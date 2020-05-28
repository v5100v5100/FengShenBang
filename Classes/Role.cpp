#include "Role.h"

Role *Role::createRole()
{
	Role *pRet = new Role();
	if (pRet && pRet->init(0))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Role::init(const int &rId)
{
	bool bRet = false;
	do
	{


		using cocosbuilder::NodeLoaderLibrary;
		using cocosbuilder::CCBReader;

		// 第一步： 创建一个NodeLoaderLibrary
		auto loaderLib = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();

		// 第二步: 创建CCBReader
		auto ccbReader = new CCBReader(loaderLib);

		// 第三步： 调用CCBReader的readNodeGraphFromFile的方法，传入ccbi名字
		auto node = ccbReader->readNodeGraphFromFile("ccbFiles/Role/Role_Down.ccbi", this);
		ccbReader->release();

		// 解析完毕，可以使用Node了。
		if (node)
		{
			addChild(node);
		}

		bRet = true;
	} while (0);

	return bRet;
}

Role::~Role()
{

}
