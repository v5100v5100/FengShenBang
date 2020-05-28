#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#pragma execution_character_set("utf-8")//解决中文乱码

#include "PublicDefine.h"
#include "sqlite3.h"
#include "DataItemDefine.h"

class DataManager : public Node
{
public:

	CREATE_INSTANCE_FUNC(DataManager);

	DESTROY_INSTANCE_FUNC();


	//
	//加载地图数据
	//
	MapStruct readMapData(uint16_t mapId);

	//
	//读取地图上的箱子列表
	//
	vector<MapBoxStruct*> readMapBoxList(uint16_t mapId);

	vector<MapBuyStruct*> readMapBuyList(uint16_t mapId);

	vector<MapMaskStruct*> readMapMaskList(uint16_t mapId);

	//
	//读取地图上的npc列表
	//
	vector<MapNpcStruct*> readMapNpcList(uint16_t mapId);

	//
	//读取怪物列表
	//
	vector<MonsterStruct*> readMonsterList(uint16_t mapId);

	//
	//读取地图上对象列表
	//
	vector<MapObjectStruct*> readObjectList(uint16_t mapId);

	//
	//保存进度
	//
	void saveRecord();

	//
	//加载进度
	//
	void loadRecord();

	//
	//获取进度列表
	//
	void recordList();

protected:

	virtual bool init();

private:

	DataManager(){}

	virtual ~DataManager(){}

	DataManager(const DataManager &) = delete;

	DataManager &operator=(const DataManager &) = delete;

	//
	//打开数据库
	static sqlite3* openDatabase();

	//
	//关闭数据库
	static void closeDatabase(sqlite3 *pSqlite);

	static int  excuteSQL(string sql);


	static vector<map<string, string>> getDataSet(string sql);


	static int GetSingleData(string sql);

};
#endif // __DATA_MANAGER_H__
