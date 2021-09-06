//edit by rock
//2008.10.16
//本文件不会被克隆
//Rebuild By Hongba && Jpei 2012
//增加npc增援
#include <ansi.h>
#include <localtime.h>
#include "/quest/gmd/hongshui/sys/list.h"

#define MAX_ROOM_INDEX 20
#define OFFICE_NPC     "/quest/gmd/npc/office"
#define MIRROR_MEMORY  "/quest/gmd/hongshui/sys/memory"
#define KILLER_NPC     "/quest/gmd/hongshui/npc/killer"
#define BOSS_NPC       "/quest/gmd/hongshui/npc/zhuang"
#define MAX_KILLER_INDEX 10

//全局变量
int make_room_index;
int ob_time;

//函数声明

int mirror(object* player,object leader);
void del_npc();
void mirror_ok(object me);
varargs void make_killer(object *player,int boss);

//函数：查询现有量镜像数量
int query_room_amount() { return make_room_index; }

//初始化




//NPC调用，创造镜像世界
int mirror(object* player,object leader)
{
	object maps,memory,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX || !leader ) return 0;

	//创建内存
	if(!memory = new(MIRROR_MEMORY)) return 0;

	memory->set("leader",leader);
	//判断所有玩家是否符合要求
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
		if(!player[i] || !userp(player[i]) || !living(player[i]) || !pointerp(player[i]->query_team()))
		{
			destruct(memory);
			return 0;//continue;
		}

		//找出队长
		if(player[i]->is_team_leader())
		{
			leader = player[i];
			
		}
		memory->set(sprintf("user_id/%d",i),player[i]->query("id"));
		memory->set(sprintf("user/%d",i),player[i]);
		player[i]->set_temp("mirror/mirror_memory",memory);

		tell_object(player[i],HIY"【围攻光明顶】正在为你制造镜像，请稍候......\n"NOR);
		player[i]->disable_player("<进入镜像中>");
		player[i]->set_temp("block_msg/all",1);
	}

	//制造世界
	size = sizeof(mirror_maps);
	for(j=0;j<size;j++)
	{
		maps = new(mirror_maps[j]);
		if(maps)
		{
			//所有地图进memory
			memory->set(sprintf("maps/%d",j),maps);
sscanf(mirror_maps[j],"/quest/gmd/hongshui/%s",fileName);
			memory->set(fileName,maps);
			maps->set("memory",memory);
                 if(maps->query("short") == HIW"洪水旗"NOR);
			{
				start_room = maps;
			}
			index ++;
		}
			}
	if(index < 1 || !start_room  )
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->enable_player();
			player[i]->delete_temp("block_msg");
			tell_object(player[i],"Error: 镜像制造失败，请联系巫师。\n");
		}

		memory->delete_map();
		destruct(memory);
		time = localtime(time());
		log_file("mirror",sprintf("%d月%d日 %d:%d  虚拟空间创建失败。\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->set_temp("mirror/start_room",start_room);
			call_out("mirror_ok",20,player[i]);
		}
		memory->set("mirror_time",time()+1800); //任务结束时间
		memory->set("open_time",time());        //任务开始时间
		memory->len_exits(); //连通地图(小心)
		memory->heart(1);  //启动心跳
		call_out("make_killer",60,player);   //一分钟后开始刷怪
	}
}

void mirror_ok(object me)
{
	object start_room,memory;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("mirror/start_room");
	memory = (object)me->query_temp("mirror/mirror_memory");

	me->enable_player();
	me->delete_temp("block_msg");

	//没有开始房间
	if(!start_room)
	{
		tell_object(me,"坐标错误，你没能进入镜像。\n");
		user_id = (mapping)memory->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))
			{
				memory->set(sprintf("user_id/%d",i),0);
				memory->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else
	{
		me->move(start_room);
		tell_object(me,HIY"【围攻光明顶】请各位英雄做好准备，30秒后魔教教徒将会出现。\n"NOR); //广告
	}
}

varargs void make_killer(object *player,int boss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
object killer,memory,rand_map,leader;
	mapping maps;
	//tell_object(find_player("rock"),sprintf("debug: player = %O\n",player));
	if(!player) return;

	//平均等级
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
      if(!player[i] || !userp(player[i])) continue;
		all_level += player[i]->query("jym_level/level");
		all_exp += player[i]->query("combat_exp");
if(player[i]->is_team_leader()) leader=player[i];
}
	killer_exp = all_exp/size;
	killer_level = all_level/size;

	memory = (object)player[0]->query_temp("mirror/mirror_memory");
	if(!memory) return; //防抱错

	//放置主动攻击NPC
	if(!boss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
                if(memory->query("npc_amount",1) >= 30 ) break;
		
		if(!boss)
		{
			if(killer = new(KILLER_NPC))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图
		
				killer->set("jym_level",killer_level);
				killer->set("combat_exp",killer_exp);

				killer->move(rand_map);
			}
		}
		else
		{
			if(killer = new(BOSS_NPC))
			{
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图
		
				killer->set("jym_level",killer_level*(2+random(9)));
				killer->set("combat_exp",killer_exp);

				killer->move(rand_map);
			}
		}
	}
	//tell_object(find_player("rock"),"????\n");
if(!memory->query("send_boss"))
{ 
call_out("make_killer",120,player);    //敌人增援
if(leader && memory->query("npc_amount",1) < 30)   tell_object(leader,HBMAG"敌人最新一波增援赶到！请注意安全！\n"NOR); }
}

//收起 NPC
void del_npc()
{
	object *office;
	int i,size;

	office = children("/quest/gmd/npc/office");

	if(!office) return;

	size = sizeof(office);
	for(i=0;i<size;i++)
	{
		destruct(office[i]);
	}
}
