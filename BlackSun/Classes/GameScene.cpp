#include "GameScene.h"
#include "Sign.h"

USING_NS_CC;

static const int SIGN1_LENGTH = 9;
static cocos2d::Vec2 SIGN1[SIGN1_LENGTH] = {
	cocos2d::Vec2(180, 1000),
	cocos2d::Vec2(400, 1170),
	cocos2d::Vec2(550, 1370),
	cocos2d::Vec2(700, 1170),
	cocos2d::Vec2(800, 820),
	cocos2d::Vec2(550, 820),
	cocos2d::Vec2(300, 820),
	cocos2d::Vec2(550, 1000),
	cocos2d::Vec2(900, 1000)
};

static const int SIGN2_LENGTH = 6;
static cocos2d::Vec2 SIGN2[SIGN2_LENGTH] = {
	cocos2d::Vec2(130, 1020),
	cocos2d::Vec2(500, 1070),
	cocos2d::Vec2(770, 970),
	cocos2d::Vec2(320, 970),
	cocos2d::Vec2(320, 820),
	cocos2d::Vec2(900, 820)
};

static const int SIGN3_LENGTH = 6;
static cocos2d::Vec2 SIGN3[SIGN3_LENGTH] = {
	cocos2d::Vec2(150, 1270),
	cocos2d::Vec2(500, 1070),
	cocos2d::Vec2(500, 1320),
	cocos2d::Vec2(800, 1220),
	cocos2d::Vec2(600, 720),
	cocos2d::Vec2(900, 620)
};

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_drawingSign = false;

	_signs[0] = Sign::create(SIGN1, SIGN1_LENGTH, "LQ\\sign1.png");
	_signs[1] = Sign::create(SIGN2, SIGN2_LENGTH, "LQ\\sign2.png");
	_signs[2] = Sign::create(SIGN3, SIGN3_LENGTH, "LQ\\sign3.png");
	addChild(_signs[0]);
	addChild(_signs[1]);
	addChild(_signs[2]);
	setCurrentSign(0);
	
	gameSpace = DrawNode::create();
	gameSpace->drawSolidRect(Vec2(0, 500), Vec2(1080, 1500), Color4F(1, 1, 1, 0.3f));
	addChild(gameSpace);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void GameScene::setCurrentSign(int index)
{
	_currentSign = index;
	for (int i = 0; i < 3; i++)
	{
		if (i == index)
		{
			_signs[i]->setVisible(true);
		}
		else
		{
			_signs[i]->setVisible(false);
		}
	}
}

void GameScene::update(float dt)
{
	//_currentSign->redraw();
}

bool GameScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* event)
{
	/*if (_currentSign->getStart()->getCircle()->checkCollisionWithPoint(pTouch->getLocation()))
	{
		_drawingSign = true;
	}*/
	if (_currentSign == 2)
		setCurrentSign(0);
	else
		setCurrentSign(_currentSign + 1);

	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* event)
{


}

void GameScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* event)
{
}