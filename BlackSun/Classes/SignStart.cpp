#include "SignStart.h"
#include "Circle.h"

USING_NS_CC;

SignStart* SignStart::create()
{
	SignStart* node = new SignStart();
	if (node) {
		node->init();
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool SignStart::init()
{
	_circle = Circle::create(100, Color4F(0, 1.0f, 0, 0.8f));
	CC_SAFE_RETAIN(_circle);
	addChild(_circle);

	return true;
}