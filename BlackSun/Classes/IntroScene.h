#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class IntroScene : public cocos2d::LayerColor {
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void update(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(IntroScene);

	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* event);

private:
	cocos2d::Size _screenSize;
	cocos2d::Vec2 _origin;

	Sprite * _screen1;
	Sprite * _screen2;
	Sprite * _screen3;

	int _screen;

	void createIntroScreen();
};


#endif // __INTRO_SCENE_H__
