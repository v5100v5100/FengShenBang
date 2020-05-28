#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#pragma execution_character_set("utf-8")//�����������

#include "DataItemDefine.h"
#include "cocos2d.h"
USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

	//�����ļ���
	virtual void onKeyPressed(EventKeyboard::KeyCode keycode, Event *event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);

private:

	//��ǰ��ͼ��id
	uint16_t currentMapId;

	//��ǰ��ͼ
	MapStruct map;

	//��ǰ�����µĹ����б�
	vector<MonsterStruct> monsterList;

	//��ǰ�����µ�npc�б�
	vector<MapNpcStruct> npcList;

	//��ǰ�����µ������б�
	vector<MapBoxStruct> mapBoxList;

	//��ǰ�������̵��б�
	vector<MapBuyStruct> mapBuyList;

	//
	vector<MapMaskStruct> mapMaskList;

	//��ǰ��ͼ����Ҫ��Ʒ�б�
	vector<MapObjectStruct> mapObjectList;

	//
	vector<MapWarpPointStruct> mapWarpPointList;

private:
	//
	//���ص�ͼ	mapId:��ͼid
	//
	void loadMap(uint16_t mapId);
};

#endif // __GAME_SCENE_H__
