#ifndef __SIGN_H__
#define __SIGN_H__

#include "cocos2d.h"
#include "SignStart.h"
#include "SignEnd.h"
#include "SignPoint.h"

class Sign : public cocos2d::Node {

public:
	static Sign* create(cocos2d::Vec2* points, int nbrPoints, std::string spriteFile);
	bool init(cocos2d::Vec2* points, int nbrPoints, std::string spriteFile);

	void update(float dt);
	void redraw();

	SignStart* getStart() { return _start; }
	SignEnd* getEnd() { return _end; }
	std::vector<SignPoint*> getPoints() { return _points; }

	void doSignDemo();
protected:
	SignStart* _start;
	SignEnd* _end;
	std::vector<SignPoint*> _points;
	std::vector<bool> _lineVisible;

	cocos2d::Sprite* _signSprite;
	cocos2d::DrawNode* lines;
};

#endif // __SIGN_H__