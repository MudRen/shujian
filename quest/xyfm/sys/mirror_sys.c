//edit by rock
//2008.10.16
//本文件不会被克隆

#include <ansi.h>
#include <localtime.h>
#include "/quest/xyfm/sys/list.h"

#define MAX_ROOM_INDEX 20
#define OFFICE_NPC     "/quest/xyfm/npc/office"
#define MIRROR_MEMORY  "/quest/xyfm/sys/memory"
#define KILLER_NPC     "/quest/xyfm/npc/jiangshi"
#define BOSS_NPC       "/quest/xyfm/npc/boss"
#define MAX_KILLER_INDEX 200

//全局变量
int make_room_index;
int ob_time;

//函数声明
void check_time();
int mirror(object player);
void del_npc();
void mirror_ok(object me);
varargs void make_killer(object *player,int boss);

//函数：查询现有量镜像数量
int query_room_amount() { return make_room_index; }
/*
//初始化
void create() { check_time(); }

//检查时间
void check_time()
{
	object npc;

	if(!ob_time)
	{
		//2小时一次
		ob_time = time()+2*3600;
	}
//tell_object(find_player("rock"),"\n时间.......\n");
	if(ob_time <= time())
	{
		//活动通告
		//克隆NPC
		npc = new(OFFICE_NPC);
		if(npc)
		{
			CHANNEL_D->do_channel( npc, "chat", "降妖伏魔镜像已经打开，望各位英雄前来一探究竟。\n");
			//放到 /d/city/wumiao
			npc->move("/d/city/wumiao");
			//副本最大数量清零
			make_room_index = 0;
			//激活收起NPC(10分钟)
			call_out("del_npc",600);
			//重设时间
			ob_time = time()+2*3600;
		}
	}
	//时间没到就继续循环
	if((time() + 1800) >= ob_time)
	{
		call_out("check_time",600);
	}
	else if((time() + 600) >= ob_time)
	{
		call_out("check_time",60);
	}
	else call_out("check_time",1800);
}
*/
//NPC调用，创造镜像世界
int mirror(object player)
{


object maps,memory,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player /*|| make_room_index >= MAX_ROOM_INDEX*/ ) return 0;

	//创建内存
	if(!memory = new(MIRROR_MEMORY)) return 0;

	memory->set(sprintf("user_id/%d",i),player->query("id"));
		memory->set(sprintf("user/%d",i),player);
		player->set_temp("mirror/mirror_memory",memory);
tell_object(player,WHT"战祸四起，浮尸遍野，民不聊生，而时逢乱世之秋,\n"+
             "有四方妖人假托僵尸怨孽作乱作祟，企图夺得天下，\n"+
             "道教高人章道灵仙师探得妖人行踪，欲寻义士相助，\n"+             
             "能否揭穿妖人真相，还清白朗朗于乾坤，就看你的了！\n\n"NOR);

             tell_object(player,HIG"【提示】遇到僵尸不必害怕，只管上前降伏，方能探明真相。\n"NOR);
             tell_object(player,HIG"【提示】副本届时会自动关闭，玩家自行传送回城，不必担心。\n\n"NOR);

	tell_object(player,HIR"【降妖伏魔】正在为你制造降妖伏魔副本，请稍候......\n"NOR);
	player->disable_player("<进入镜像中>");
	player->set_temp("block_msg/all",1);

	//制造世界
	size = sizeof(mirror_maps);
	for(j=0;j<size;j++)
	{
		maps = new(mirror_maps[j]);
if(maps)
		{
			//所有地图进memory
			memory->set(sprintf("maps/%d",j),maps);
			sscanf(mirror_maps[j],"/quest/xyfm/%s",fileName);
			memory->set(fileName,maps);
			maps->set("memory",memory);
			if(maps->query("short") == "野外平地")
			{
				start_room = maps;
			}
			index ++;
		}
	}

if(index < 1 || !start_room)
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player->enable_player();
			player->delete_temp("block_msg");
			tell_object(player,"Error: 镜像制造失败，请联系巫师。\n");
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

		
			player->set_temp("mirror/start_room",start_room);
			call_out("mirror_ok",20,player);
		
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
		tell_object(me,HIR"【降妖伏魔】请做好准备，30秒后大量怨孽出现。\n"NOR); //广告
	}
}

varargs void make_killer(object player,int boss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
	object killer,memory,rand_map;
	mapping maps;

	if(!player) return;

	memory = (object)player->query_temp("mirror/mirror_memory");
	if(!memory) return; //防抱错
	//放置主动攻击NPC
	if(!boss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(memory->query("npc_amount",1) >= 201 ) break;	
if(!boss)
		{
			if(killer = new(KILLER_NPC))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

				killer->move(rand_map);
			}
		}
		else
		{
if(killer = new(BOSS_NPC))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

				killer->move(rand_map);
			}
		}
	}
}
//收起 NPC
void del_npc()
{
	object *office;
	int i,size;

	office = children("/quest/xyfm/npc/office");

	if(!office) return;

	size = sizeof(office);
	for(i=0;i<size;i++)
	{
		destruct(office[i]);
	}
}
