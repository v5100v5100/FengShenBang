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

	//��ɫ��id
	static uint16_t id;
	
	//��ɫ��
	string name;

	//Ѫ
	uint32_t hp;

	//ħ��
	uint32_t mp;

	//��ɫ�ȼ�
	uint16_t level;

protected:


private:

};


#endif

