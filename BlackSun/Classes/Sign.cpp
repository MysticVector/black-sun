#include "Sign.h"

USING_NS_CC;

Sign* Sign::create(cocos2d::Vec2* points, int nbrPoints, std::string spriteFile)
{
	Sign * node = new Sign();
	if (node) {
		node->init(points, nbrPoints, spriteFile);
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool Sign::init(cocos2d::Vec2* points, int nbrPoints, std::string spriteFile)
{
	_signSprite = Sprite::create(spriteFile);
	CC_SAFE_RETAIN(_signSprite);
	_signSprite->setAnchorPoint(Point(0, 0));
	addChild(_signSprite);
	
	// Start of sign
	_start = SignStart::create();
	CC_SAFE_RETAIN(_start);
	addChild(_start);
	_start->setPosition(points[0]);

	/*************/
	// Point list
	SignPoint* p = nullptr;
	for (int i = 1; i < nbrPoints - 1; i++)
	{
		p = SignPoint::create();
		CC_SAFE_RETAIN(p);
		addChild(p);
		p->setPosition(points[i]);
		_points.push_back(p);
	}

	// End of sign
	_end = SignEnd::create();
	CC_SAFE_RETAIN(_end);
	addChild(_end);
	_end->setPosition(points[nbrPoints - 1]);

	// Adding booleans that control if the lines are visible
	// They should have the length of the points array + 1
	for (int i = 0; i < _points.size(); i++)
	{
		_lineVisible.push_back(true);
	}
	_lineVisible.push_back(true);

	lines = DrawNode::create();
	this->addChild(lines);

	redraw();

	return true;
}

void Sign::update(float dt)
{

}

void Sign::redraw()
{
	_start->getCircle()->redraw();
	_end->getCircle()->redraw();

	for (int i = 0; i < _points.size(); i++)
	{
		_points[i]->getCircle()->redraw();
	}

	// redraw the lines connecting the circles
	lines->clear();
	if (_lineVisible[0])
	{
		lines->drawLine(_start->getPosition(), _points[0]->getPosition(), Color4F(0, 1.0f, 0, 0.8f));
	}

	for (int i = 0; i < _lineVisible.size() - 2; i++)
	{
		if (_lineVisible[i])
		{
			lines->drawLine(_points[i]->getPosition(), _points[i + 1]->getPosition(), Color4F(0, 1.0f, 0, 0.8f));
		}
	}

	if (_lineVisible[_lineVisible.size() - 1])
	{
		lines->drawLine(_points[_points.size() - 1]->getPosition(), _end->getPosition(), Color4F(0, 1.0f, 0, 0.8f));
	}
}