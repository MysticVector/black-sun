#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "cocos2d.h"

class Circle : public cocos2d::Node {

public:
	static Circle* create(float radius, cocos2d::Color4F solidColor);
	bool init(float radius, cocos2d::Color4F solidColor);

	void update(float dt);
	void redraw();

	bool checkCollisionWithPoint(cocos2d::Point p);

	CC_SYNTHESIZE(float, _radius, Radius);
	CC_SYNTHESIZE(cocos2d::Color4F, _solidColor, SolidColor);

private:
	cocos2d::DrawNode* _circleNode;
};

#endif // __CIRCLE_H__