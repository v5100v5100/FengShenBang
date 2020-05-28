#include "GameStartScene.h"
#include "Role.h"


Scene* GameStartScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = GameStartScene::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameStartScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getWinSize();


	content = "Hello,World \n 这世界我来了，任凭风暴漩涡。这是你爱的承诺，兄弟一二三四五，兄弟个十百千万，兄弟情深似海深，兄弟来生一个妈！兄弟相逢，三碗酒，兄弟安民。\n                 万世夸！";
	this->n = 3;// 0~3来获得一个中文字符
	int contentLength = content.length();
	label = Label::create();
	label->setString("");
	label->setSystemFontSize(40);
	label->setPosition(visibleSize.width / 5, visibleSize.height / 2);
	label->setAnchorPoint(Vec2(0, 1));//设置锚点，从左向右打印
	label->setDimensions(800, 400);
	this->addChild(label);
	this->schedule(schedule_selector(GameStartScene::showFont), 0.1f);


	Role *role = Role::createRole();
	role->setPosition(visibleSize.width / 5, visibleSize.height / 2);
	this->addChild(role);

	return true;
}


void GameStartScene::showFont(float dt) {
	log("哈哈哈哈%d",n);
	str = content.substr(0, n);
	//log("%s",str);
	this->label->setString(content.substr(0, n));
	n = n + 3;
	if (n > content.length()) {
		this->unschedule(schedule_selector(GameStartScene::showFont));
	}
}