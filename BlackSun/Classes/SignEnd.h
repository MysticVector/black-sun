#ifndef __SIGN_END_H__
#define __SIGN_END_H__

#include "cocos2d.h"
#include "Circle.h"

class SignEnd : public cocos2d::Node {

public:
	static SignEnd * create();
	bool init();

	Circle* getCircle() { return _circle; }
private:
	Circle* _circle;

};

#endif // __SIGN_START_H__