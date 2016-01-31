#ifndef __SIGN_START_H__
#define __SIGN_START_H__

#include "cocos2d.h"

class Circle;

class SignStart : public cocos2d::Node {

public:
	static SignStart* create();
	bool init();

	Circle* getCircle() { return _circle;  }
private:
	Circle* _circle;
};

#endif // __SIGN_START_H__