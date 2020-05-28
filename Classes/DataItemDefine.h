//
// 道具，武器等等等等各种数值结构体的定义
//
//
#ifndef __DATA_ITEM_DEFINE_H__
#define __DATA_ITEM_DEFINE_H__


#include "cocos2d.h"

using namespace std;
USING_NS_CC;

//==========================直接映射数据文件的结构===========================================
//
//角色自动移动
//
struct AutoMoveStruct
{
	uint16_t map_id;
	uint16_t hero_pos_x;
	uint16_t hero_pos_y;
	uint8_t hero_dir;
	uint16_t npc_id;
	uint16_t npc_start_pos_x;
	uint16_t npc_start_pos_y;
	uint16_t npc_end_pos_x;
	uint16_t npc_end_pos_y;
	uint16_t story_id;
	uint8_t npc_dir;
	uint16_t auto_move_id;
	uint8_t type;
	uint8_t switch_on;
	uint8_t switch_off;
	uint8_t delay;
};

//
//战斗相关的数值
//
struct BattleStruct
{
	uint16_t id;
	string monser_01;
	string monser_02;
	string monser_03;
	string monser_04;
	string monser_05;
	string monser_06;
	uint8_t is_escape;
	uint8_t switch_on;
	uint8_t switch_off;
	uint16_t map_id;
	uint8_t type;
	string note;
	string bg;
	uint16_t next_story_id;
	uint16_t auto_move_id;
	uint16_t mibao_id;
};

//
// 连击
//
struct LianJiStruct
{
	uint16_t id;
	float pro_01;
	float pro_02;
	float pro_03;
	float pro_04;
};

//
// 地图
//
struct MapStruct
{
	uint16_t id;
	string res;
	string description;
	string name;
	uint16_t hero_pos_x;
	uint16_t hero_pos_y;
	uint16_t sound_id;
	uint16_t jump_map_id;
	uint16_t jump_pos_x;
	uint16_t jump_pos_y;
	uint8_t type;
	uint16_t zero_pos_x;
	uint16_t zero_pos_y;
	uint16_t bgm;
};

//
// 
//
struct MapBoxStruct
{
	uint16_t id;
	uint16_t map_id;
	uint16_t pos_x;
	uint16_t pos_y;
	uint16_t obj_id;
	uint16_t obj_num;
	uint8_t is_box;
};

struct  MapBuyStruct
{
	uint16_t id;
	uint16_t map_id;
	uint16_t npc_id;
	uint16_t obj_id;
};

struct MapMaskStruct
{
	uint16_t id;
	uint16_t map_id;
	uint16_t pos_x;
	uint16_t pos_y;
	uint16_t width;
	uint16_t height;
	string res;
};


//
//
//
struct MapMonsterStruct
{
	uint16_t id;
	string monster_01;
	string monster_02;
	string monster_03;
	string monster_04;
	string monster_05;
	string monster_06;
	string note;
};

//
//
//
struct MapNpcStruct
{
	uint16_t id;
	uint16_t map_id;
	uint16_t width;
	uint16_t height;
	uint8_t dir;
	uint8_t is_move;
	uint16_t zero_pos_x;
	uint16_t zero_pos_y;
	uint16_t min_pos_x;
	uint16_t max_pos_y;
	uint16_t story_id;
	uint8_t switch_on;
	uint8_t switch_off;
	uint16_t zero_id;
	string res;
	string note;
	uint8_t type;
	uint8_t check_pos;
	uint16_t cost_money;
};

//
//
//
struct MapObjectStruct
{
	uint16_t id;
	uint16_t map_id;
	uint16_t pos_x;
	uint16_t pos_y;
	uint16_t width;
	uint16_t height;
	string res;
	uint8_t res_type;
	uint8_t switch_on;
	uint8_t switch_off;
	string note;
	uint8_t type;
	uint16_t connect_id;
};

//
//
//
struct MapWarpPointStruct
{
	uint16_t id;
	uint16_t cur_map_id;
	uint16_t point_x;
	uint16_t point_y;
	uint16_t tar_map_id;
	uint16_t tar_hero_pos_x;
	uint16_t tar_hero_pos_y;
	uint8_t tar_hero_dir;
	string note;
	uint8_t switch_on;
	uint8_t switch_off;
	uint8_t type;
};

struct MonsterStruct
{
	uint16_t id;
	string name;
	string res;
	uint32_t exp;
	uint32_t money;
	uint16_t skill_id;
	uint32_t skill_hurt_num;
	uint32_t atk;
	uint32_t def;
	uint32_t agi;
	uint32_t hp;
	uint32_t object;
	string note;
	uint8_t type;
	uint8_t buff_type;
	float buff_pro;
	float object_pro;
};

//
//道具
//
struct ObjectStruct
{
	uint16_t id;
	string name;
	string description;
	uint8_t type;
	uint32_t number_1;
	string res;
	uint32_t buy_price;
	uint32_t sell_price;
	uint8_t mini_type;
	uint8_t is_two_hand;
	uint8_t role_01;
	uint8_t role_02;
	uint8_t role_03;
	uint8_t role_04;
	uint8_t is_disappear;
	uint16_t sell_story_id;
};

//
//
//
struct RoleLvStruct
{
	uint16_t id;
	uint16_t role_id;
	uint16_t role_lv;
	uint32_t hp;
	uint32_t mp;
	uint32_t li_liang;
	uint32_t min_jie;
	uint32_t ti_neng;
	uint32_t jin_shen;
	uint32_t attack;
	uint32_t df;
	uint32_t exp;
	uint32_t reward_exp;
	uint32_t reward_gold;
};

//
//
//
struct SkillStruct
{
	uint16_t id;
	string name;
	uint32_t cost_mp;
	uint16_t role_id;
	uint16_t role_lv;
	uint8_t target_type;
	uint8_t is_battle_use;
	string sk_effect;
	string desc;
	string note;
};

//
//
//
struct StoreStruct
{
	uint16_t id;
	string name;
	string icon;
	uint32_t price;
	string desc;
	uint8_t type;
	string note;
	uint16_t connect_id;
};

//
//
//
struct StoryStruct
{
	uint16_t id;
	uint16_t speaker_id;
	uint16_t type;
	string speak_words;
	uint16_t next_story_id;
	uint16_t get_item_id;
	uint16_t get_item_num;
	uint16_t next_scene_id;
	uint16_t scene_param;
	uint16_t tar_x;
	uint16_t tar_y;
	uint8_t dir;
	string note;
	uint16_t auto_move_id;
};

//
//鹰翼
//
struct YingYiStruct
{
	uint16_t id;
	uint16_t map_id;
	uint16_t pos_x;
	uint16_t pos_y;
	string name;
	uint16_t unlock_map_id;
};


//==========================通用的数据结构===========================================



class DataItemDefine
{
public:
	DataItemDefine();
	~DataItemDefine();
};

#endif // __DATA_ITEM_DEFINE_H__


