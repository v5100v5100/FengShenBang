#ifndef __GAME_SCENE_MANAGER__
#define __GAME_SCENE_MANAGER__

#pragma execution_character_set("utf-8")//解决中文乱码

#include "PublicDefine.h"
#include "cocos2d.h"
#include "DataItemDefine.h"
USING_NS_CC;
using namespace std;

class GameSceneManager : public Ref
{
public:

	CREATE_INSTANCE_FUNC(GameSceneManager);

	DESTROY_INSTANCE_FUNC();

	//
	//加载地图	mapId:地图id
	//
	void loadMap(uint16_t mapId);

protected:

	virtual bool init();


private:

	//当前地图的id
	uint16_t currentMapId;

	//当前地图
	MapStruct map;

	//当前场景下的怪物列表
	vector<MonsterStruct*> monsterList;

	//当前场景下的npc列表
	vector<MapNpcStruct*> npcList;

	//当前场景下的箱子列表
	vector<MapBoxStruct*> mapBoxList;

	//当前场景下商店列表
	vector<MapBuyStruct*> mapBuyList;

	//
	vector<MapMaskStruct*> mapMaskList;

	//当前地图上重要物品列表
	vector<MapObjectStruct*> mapObjectList;

	//
	vector<MapWarpPointStruct*> mapWarpPointList;

private:

	GameSceneManager(){}

	virtual ~GameSceneManager(){}

	GameSceneManager(const GameSceneManager &) = delete;

	GameSceneManager &operator=(const GameSceneManager &) = delete;
};

#endif

