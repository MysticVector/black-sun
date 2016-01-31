#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Sign;

class GameScene : public cocos2d::LayerColor
{
public:
	cocos2d::Size _visibleSize;
	cocos2d::Point _origin;

	cocos2d::DrawNode* gameSpace;

	int _currentSign;
	Sign* _signs[3];

	bool _drawingSign;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void setCurrentSign(int index);

	void update(float dt);

	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
