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
	//创建一个npc
	//
	static Npc* createNpc(const int &id);

	void autoMove();

	Npc();
	~Npc();

private:

	//是否移动
	bool isMove;

	//故事id
	uint16_t storyId;

	//剧情列表
	vector<StoryStruct*> storyList;

	//npc的动作列表
	vector<AutoMoveStruct*> actionList;

};

#endif

