#ifndef __SIGN_POINT_H__
#define __SIGN_POINT_H__

#include "cocos2d.h"
#include "Circle.h"

class SignPoint : public cocos2d::Node {

public:
	static SignPoint * create();
	bool init();

	Circle* getCircle() { return _circle; }
private:
	Circle* _circle;

};

#endif // __SIGN_START_H__