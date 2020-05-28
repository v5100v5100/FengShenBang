#ifndef __NPC__
#define __NPC__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
#include "PublicDefine.h"
#include "DataItemDefine.h"

USING_NS_CC;
using namespace std;
USING_NS_CC_EXT;
using namespace cocosbuilder;

class Npc : public Node
{

public:

	//
	//����һ��npc
	//
	static Npc* createNpc(const int &id);

	void autoMove();

	Npc();
	~Npc();

private:

	//�Ƿ��ƶ�
	bool isMove;

	//����id
	uint16_t storyId;

	//�����б�
	vector<StoryStruct*> storyList;

	//npc�Ķ����б�
	vector<AutoMoveStruct*> actionList;

};

#endif

