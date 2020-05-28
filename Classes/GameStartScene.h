#ifndef __GAME_START_SCENE__
#define __GAME_START_SCENE__

#pragma execution_character_set("utf-8")//解决中文乱码


#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class GameStartScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameStartScene);


	string content;

	Label  *label;
	int n;

	void showFont(float dt);

	string str;

};

#endif

