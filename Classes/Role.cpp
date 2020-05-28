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

		// ��һ���� ����һ��NodeLoaderLibrary
		auto loaderLib = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();

		// �ڶ���: ����CCBReader
		auto ccbReader = new CCBReader(loaderLib);

		// �������� ����CCBReader��readNodeGraphFromFile�ķ���������ccbi����
		auto node = ccbReader->readNodeGraphFromFile("ccbFiles/Role/Role_Down.ccbi", this);
		ccbReader->release();

		// ������ϣ�����ʹ��Node�ˡ�
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
