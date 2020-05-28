#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MapLayer.h"

#include "DataManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;


Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	DataManager::getInstance();

	auto size = getContentSize();

	TMXTiledMap *map = TMXTiledMap::create("map/map_001.tmx");
	map->setAnchorPoint(ccp(0.5f, 0.5f));
	map->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(map);

	auto *dispatcher = Director::getInstance()->getEventDispatcher();
	auto* keyListener = EventListenerKeyboard::create();
	//����һ���¼����������������¼�
	keyListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	//���̱�����ʱ��Ӧ
	keyListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	//���̰���������ʱ��Ӧ
	dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}


void GameScene::onKeyPressed(EventKeyboard::KeyCode keycode, Event *event) {
	if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		CCLOG("�����ˣ��Ϸ����");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		CCLOG("�����ˣ������");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		CCLOG("�����ˣ��ҷ����");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		CCLOG("�����ˣ��·����");
	}
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event) {
	if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		CCLOG("�ɿ��ˣ��Ϸ����");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		CCLOG("�ɿ��ˣ������");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		CCLOG("�ɿ��ˣ��ҷ����");
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		CCLOG("�ɿ��ˣ��·����");
	}
}


void GameScene::loadMap(uint16_t mapId)
{
	MapStruct mapData = DataManager::getInstance()->readMapData(mapId);
	vector<MapBoxStruct*> boxList = DataManager::getInstance()->readMapBoxList(mapId);

}