#include "SignEnd.h"

USING_NS_CC;

SignEnd* SignEnd::create()
{
	SignEnd* node = new SignEnd();
	if (node) {
		node->init();
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool SignEnd::init()
{
	_circle = Circle::create(100, Color4F(0, 0, 1.0f, 0.8f));
	CC_SAFE_RETAIN(_circle);
	addChild(_circle);

	return true;
}