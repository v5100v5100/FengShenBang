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
	*加载地图
	* mapId  地图的id
	*/
	void loadMap(string mapId);

	/*
	* 加载主角
	*/
	void loadHero(uint16_t x, uint16_t y);

	/*
	* 加载NPC
	*/
	void loadNpc();

protected:

	virtual bool init();

	virtual void loadSource();

private:
	TMXTiledMap *_pTiledMap = nullptr;

	//当前地图上的怪物列表
	vector<Monster*> monsterList;

	//当前地图的NPC列表
	vector<Npc*> npcList;
};

#endif
