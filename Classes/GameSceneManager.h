#ifndef __GAME_SCENE_MANAGER__
#define __GAME_SCENE_MANAGER__

#pragma execution_character_set("utf-8")//�����������

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
	//���ص�ͼ	mapId:��ͼid
	//
	void loadMap(uint16_t mapId);

protected:

	virtual bool init();


private:

	//��ǰ��ͼ��id
	uint16_t currentMapId;

	//��ǰ��ͼ
	MapStruct map;

	//��ǰ�����µĹ����б�
	vector<MonsterStruct*> monsterList;

	//��ǰ�����µ�npc�б�
	vector<MapNpcStruct*> npcList;

	//��ǰ�����µ������б�
	vector<MapBoxStruct*> mapBoxList;

	//��ǰ�������̵��б�
	vector<MapBuyStruct*> mapBuyList;

	//
	vector<MapMaskStruct*> mapMaskList;

	//��ǰ��ͼ����Ҫ��Ʒ�б�
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

