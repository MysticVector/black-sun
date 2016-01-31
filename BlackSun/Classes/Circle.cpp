#include "Circle.h"

USING_NS_CC;

Circle* Circle::create(float radius, cocos2d::Color4F solidColor)
{
	Circle* node = new Circle();
	if (node) {
		node->init(radius, solidColor);
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool Circle::init(float radius, Color4F solidColor)
{
	_radius = radius;
	_solidColor = solidColor;

	_circleNode = DrawNode::create();
	//_circleNode->setAnchorPoint(Vec2(1.f, 1.f));
	addChild(_circleNode);

	redraw();

	return true;
}

void Circle::update(float dt)
{

}

void Circle::redraw()
{
	_circleNode->clear();
	_circleNode->drawDot(getPosition(), _radius, _solidColor);
}

bool Circle::checkCollisionWithPoint(Point p)
{
	if (abs(p.x - getPosition().x) < _radius && abs(p.y - getPosition().y) < _radius)
		return true;
	else
		return false;
}