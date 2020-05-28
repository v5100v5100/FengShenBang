#include "GameSceneManager.h"
#include "DataManager.h"

GameSceneManager *GameSceneManager::_gInstance;

bool GameSceneManager::init()
{
	bool bRet = false;
	do
	{
		//registerChangeSceneEvent();

		bRet = true;
	} while (0);
	return bRet;
}


void GameSceneManager::loadMap(uint16_t mapId)
{

}


