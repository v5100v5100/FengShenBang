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


	content = "Hello,World \n �����������ˣ���ƾ�籩���С������㰮�ĳ�ŵ���ֵ�һ�������壬�ֵܸ�ʮ��ǧ���ֵ������ƺ���ֵ�����һ���裡�ֵ���꣬����ƣ��ֵܰ���\n                 �����䣡";
	this->n = 3;// 0~3�����һ�������ַ�
	int contentLength = content.length();
	label = Label::create();
	label->setString("");
	label->setSystemFontSize(40);
	label->setPosition(visibleSize.width / 5, visibleSize.height / 2);
	label->setAnchorPoint(Vec2(0, 1));//����ê�㣬�������Ҵ�ӡ
	label->setDimensions(800, 400);
	this->addChild(label);
	this->schedule(schedule_selector(GameStartScene::showFont), 0.1f);


	Role *role = Role::createRole();
	role->setPosition(visibleSize.width / 5, visibleSize.height / 2);
	this->addChild(role);

	return true;
}


void GameStartScene::showFont(float dt) {
	log("��������%d",n);
	str = content.substr(0, n);
	//log("%s",str);
	this->label->setString(content.substr(0, n));
	n = n + 3;
	if (n > content.length()) {
		this->unschedule(schedule_selector(GameStartScene::showFont));
	}
}