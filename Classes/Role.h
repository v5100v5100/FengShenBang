#ifndef __ROLE__
#define __ROLE__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
USING_NS_CC_EXT;
using namespace cocosbuilder;


class Role : public Node
{
public:
	virtual ~Role();

	static Role *createRole();

	virtual bool init(const int &rId);

	//角色的id
	static uint16_t id;
	
	//角色名
	string name;

	//血
	uint32_t hp;

	//魔法
	uint32_t mp;

	//角色等级
	uint16_t level;

protected:


private:

};


#endif

