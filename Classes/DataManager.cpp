#include "DataManager.h"

DataManager *DataManager::_gInstance;

//抽取数据回调函数
int loadRecord(void * para, int n_column, char ** column_value, char ** column_name);
//取得 条数的回调函数
int loadRecordCount(void * para, int n_column, char ** column_value, char ** column_name);

bool DataManager::init()
{
	bool bRet = false;
	do
	{
		bRet = true;
		//==
		//==
	} while (0);
	return bRet;
}



MapStruct DataManager::readMapData(uint16_t mapId)
{
	MapStruct result;
	char *sql = nullptr;
	sprintf(sql,"select * from map where id = %d",mapId);
	log("要执行的SQL %s",sql);
	vector<map<string, string>> dataSet = getDataSet(sql);
	map<string, string> record0 = dataSet[0];

	result.res = record0["res"];
	result.name = record0["name"];
	result.hero_pos_x = atoi(record0["heroPosX"].c_str());
	result.hero_pos_y = atoi(record0["heroPosY"].c_str());
	result.sound_id = atoi(record0["soundId"].c_str());
	result.jump_map_id = atoi(record0["jump_map_id"].c_str());
	result.jump_pos_x = atoi(record0["jump_pos_x"].c_str());
	result.jump_pos_y = atoi(record0["jump_pos_y"].c_str());
	result.type = atoi(record0["type"].c_str());
	result.zero_pos_x = atoi(record0["zeroPosX"].c_str());
	result.zero_pos_y = atoi(record0["zeroPosY"].c_str());
	result.bgm = atoi(record0["bgm"].c_str());

	return result;
}



//======================================================================================
//
//打开数据库
sqlite3* DataManager::openDatabase()
{
	//创建sqlite数据库
	sqlite3* pSqlite;

	//打开sqlite数据库
	string str = FileUtils::sharedFileUtils()->fullPathForFilename("res/MainData");
	log("路径%s", str);
	int ret = sqlite3_open("res/MainData", &pSqlite);

	//当sqllite数据库打开失败时
	if (ret != SQLITE_OK)
	{
		//获得sqltite数据库打开错误的信息
		const char* errmsg = sqlite3_errmsg(pSqlite);
		//打印数据库打开失败的信息
		cocos2d::log("database open error: %s", errmsg);
		return nullptr;
	}
	return pSqlite;
}

//
//关闭数据库
//
void DataManager::closeDatabase(sqlite3 *pSqlite)
{
	if (pSqlite)
	{
		sqlite3_close(pSqlite);
	}
}

int DataManager::excuteSQL(string sql)
{
	sqlite3 *pSqlite = openDatabase();
	char *errMsg = nullptr;
	int result = sqlite3_exec(pSqlite, sql.c_str(), NULL, NULL, &errMsg);
	if (result != SQLITE_OK)
		CCLog("失败，错误码:%d ，错误原因:%s\n", result, errMsg);
	closeDatabase(pSqlite);
	return result;
}

vector<map<string, string>> DataManager::getDataSet(string sql)
{
	sqlite3 *pSqlite = openDatabase();
	char *errMsg = nullptr;
	//创建一个victor用于存储所有数据，每行从数据库抽出来的数据都放在一个map<string,string>里
	//第一个string是key,存列名，第二个string是值，存数据库取出的相应数据
	vector<map<string, string>> vect;
	//执行sqlite api接口函数，把vect的指针飞进回调函数loadRecord里去
	int result = sqlite3_exec(pSqlite, sql.c_str(), loadRecord, &vect, &errMsg);
	if (result != SQLITE_OK){
		CCLog("失败，错误码:%d ，错误原因:%s\n", result, errMsg);
	}
	closeDatabase(pSqlite);
	//恩，经过回调的处理，这个vector已经装满了，我们想要滴数据
	return vect;
}

int loadRecord(void *para, int n_column, char ** column_value, char ** column_name)
{
	map<string, string> hmap;
	for (int i = 0; i<n_column; i++)
	{
		//把数据 以 key-value的方式把数据库里的数据 存进map
		hmap.insert(make_pair<string, string>((string)column_name[i], (string)column_value[i]));
	}
	vector<map<string, string>>* vect = (vector<map<string, string>>*)para;
	//添加进vector
	vect->push_back(hmap);
	return 0;
}

int DataManager::GetSingleData(string sql)
{
	sqlite3 *pSqlite = DataManager::openDatabase();
	int count = 0;
	char *errMsg = nullptr;
	sqlite3_exec(pSqlite, sql.c_str(), loadRecordCount, &count, &errMsg);
	closeDatabase(pSqlite);
	return count;
}

int loadRecordCount(void * para, int n_column, char ** column_value, char ** column_name)
{
	int *count = (int*)para;
	*count = (int)atof(column_value[0]);
	return 0;
}