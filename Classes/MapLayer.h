//
//  MapLayer.h
//  
//
//  Created by vliu on 19-5-13.
//
//

#ifndef __MapLayer__
#define __MapLayer__

#include "cocos2d.h"
#include "Monster.h"
#include "Npc.h"

USING_NS_CC;
using namespace std;

/**
*  MapLayer use to load tmx map and bg
*/

class MapLayer : public Layer
{
public:

	CREATE_FUNC(MapLayer);

	/*
	*���ص�ͼ
	* mapId  ��ͼ��id
	*/
	void loadMap(string mapId);

	/*
	* ��������
	*/
	void loadHero(uint16_t x, uint16_t y);

	/*
	* ����NPC
	*/
	void loadNpc();

protected:

	virtual bool init();

	virtual void loadSource();

private:
	TMXTiledMap *_pTiledMap = nullptr;

	//��ǰ��ͼ�ϵĹ����б�
	vector<Monster*> monsterList;

	//��ǰ��ͼ��NPC�б�
	vector<Npc*> npcList;
};

#endif
