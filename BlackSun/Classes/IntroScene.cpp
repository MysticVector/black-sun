#include "IntroScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = IntroScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


// on "init" you need to initialize your instance
bool IntroScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B::WHITE))
	{
		return false;
	}

	_screenSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();

	_screen = 0;

	createIntroScreen();

	//create main loop
	this->schedule(CC_SCHEDULE_SELECTOR(IntroScene::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(IntroScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(IntroScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void IntroScene::createIntroScreen()
{
	_screen1 = Sprite::create("LQ\\bg1.png");
	_screen1->setAnchorPoint(Point(0, 0));

	_screen1->setOpacity(0);
	_screen1->runAction(FadeIn::create(1.0f));

	this->addChild(_screen1);

	_screen2 = Sprite::create("LQ\\bg2.png");
	_screen2->setAnchorPoint(Point(0, 0));
	_screen2->setOpacity(0);
	this->addChild(_screen2);

	_screen3 = Sprite::create("LQ\\bg3.png");
	_screen3->setAnchorPoint(Point(0, 0));
	_screen3->setOpacity(0);
	this->addChild(_screen3);
}

void IntroScene::update(float dt)
{

}

bool IntroScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* event)
{
	return true;
}

void IntroScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* event)
{

}

void IntroScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* event)
{
	if (_screen == 0)
	{
		_screen++;
		_screen2->runAction(Sequence::create(FadeIn::create(1.0f), nullptr));
	}
	else if (_screen == 1)
	{
		_screen++;
		_screen3->runAction(Sequence::create(FadeIn::create(1.0f), nullptr));
	}
	else if (_screen == 2)
	{
		//SimpleAudioEngine::sharedEngine()->playEffect("button.wav");
		Scene* newScene = TransitionCrossFade::create(0.2f, GameScene::createScene());
		Director::getInstance()->replaceScene(newScene);
	}
}
