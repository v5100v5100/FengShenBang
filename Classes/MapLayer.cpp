#include "MapLayer.h"


bool MapLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		loadSource();
		bRet = true;
	} while (0);

	return bRet;
}

void MapLayer::loadSource()
{
	//auto pSceneManager = SceneManager::getInstance();

	//auto pageLevelStr = StringUtils::format(GAMESCENEMAP, pSceneManager->getCurPageIndex() + 1, pSceneManager->getCurLevelIndex() + 1) + "BGPath.tmx";
	_pTiledMap = TMXTiledMap::create("map/map_001.tmx");
	addChild(_pTiledMap);

	//MapUtil::getInstance()->setCurrentLevelTiledMap(_pTiledMap);

	//auto pBg = Sprite::createWithSpriteFrameName("BG1.png");
	//pBg->setPosition(VisibleRect::center());
	//addChild(pBg);

	//auto pMapImage = Sprite::createWithSpriteFrameName("Path.png");
	//pMapImage->setPosition(VisibleRect::center());
	//addChild(pMapImage);
}



