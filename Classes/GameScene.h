#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#pragma execution_character_set("utf-8")//解决中文乱码

#include "DataItemDefine.h"
#include "cocos2d.h"
USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

	//按键的监听
	virtual void onKeyPressed(EventKeyboard::KeyCode keycode, Event *event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);

private:

	//当前地图的id
	uint16_t currentMapId;

	//当前地图
	MapStruct map;

	//当前场景下的怪物列表
	vector<MonsterStruct> monsterList;

	//当前场景下的npc列表
	vector<MapNpcStruct> npcList;

	//当前场景下的箱子列表
	vector<MapBoxStruct> mapBoxList;

	//当前场景下商店列表
	vector<MapBuyStruct> mapBuyList;

	//
	vector<MapMaskStruct> mapMaskList;

	//当前地图上重要物品列表
	vector<MapObjectStruct> mapObjectList;

	//
	vector<MapWarpPointStruct> mapWarpPointList;

private:
	//
	//加载地图	mapId:地图id
	//
	void loadMap(uint16_t mapId);
};

#endif // __GAME_SCENE_H__
