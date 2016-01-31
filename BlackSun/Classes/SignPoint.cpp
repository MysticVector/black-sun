#include "SignPoint.h"

USING_NS_CC;

SignPoint* SignPoint::create()
{
	SignPoint * node = new SignPoint();
	if (node) {
		node->init();
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool SignPoint::init()
{
	_circle = Circle::create(80, Color4F(1.0f, 0.98f, 0.49f, 0.8f));
	CC_SAFE_RETAIN(_circle);
	addChild(_circle);

	return true;
}