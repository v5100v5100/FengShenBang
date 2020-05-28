#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#pragma execution_character_set("utf-8")//�����������

#include "PublicDefine.h"
#include "sqlite3.h"
#include "DataItemDefine.h"

class DataManager : public Node
{
public:

	CREATE_INSTANCE_FUNC(DataManager);

	DESTROY_INSTANCE_FUNC();


	//
	//���ص�ͼ����
	//
	MapStruct readMapData(uint16_t mapId);

	//
	//��ȡ��ͼ�ϵ������б�
	//
	vector<MapBoxStruct*> readMapBoxList(uint16_t mapId);

	vector<MapBuyStruct*> readMapBuyList(uint16_t mapId);

	vector<MapMaskStruct*> readMapMaskList(uint16_t mapId);

	//
	//��ȡ��ͼ�ϵ�npc�б�
	//
	vector<MapNpcStruct*> readMapNpcList(uint16_t mapId);

	//
	//��ȡ�����б�
	//
	vector<MonsterStruct*> readMonsterList(uint16_t mapId);

	//
	//��ȡ��ͼ�϶����б�
	//
	vector<MapObjectStruct*> readObjectList(uint16_t mapId);

	//
	//�������
	//
	void saveRecord();

	//
	//���ؽ���
	//
	void loadRecord();

	//
	//��ȡ�����б�
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
	//�����ݿ�
	static sqlite3* openDatabase();

	//
	//�ر����ݿ�
	static void closeDatabase(sqlite3 *pSqlite);

	static int  excuteSQL(string sql);


	static vector<map<string, string>> getDataSet(string sql);


	static int GetSingleData(string sql);

};
#endif // __DATA_MANAGER_H__
