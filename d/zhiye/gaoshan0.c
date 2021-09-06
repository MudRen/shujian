// 山脚
// gaoshan0.c
// augx@sj 2/27/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","高山脚下");
	set("long",
"这是做极高的山峰，从半山腰起就云雾缭绕，在山顶的悬崖上生长着不少
奇珍异草，还有不少罕见的动物出没。此山是有名的药材产地，常年都有无数
的采药人忙碌其间。
你抬头望去，似乎有一条羊肠山路蜿蜒其间，不知道通往何处。
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"west"		: "/d/chengdu/road1",
		"northup"	: __DIR__"gaoshan1",
		"southup"	: __DIR__"gaoshan2",
		"eastup"	: __DIR__"gaoshan3",
	]));
	
	set("outdoors", "成都郊外");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

// Added by mxzhao 2004/03/06
int valid_leave(object me, string dir)
{
	if (dir != "west")
	{
		return notify_fail("此地近有猛兽出没，禁止通行。\n\n\t\t成都知府。\n");
	}

	return ::valid_leave(me, dir);
}

void init()
{
          add_action("do_push", "climb");
}

int do_push(string arg)
{
         object me = this_player();
          if (arg != "山路")
                  return notify_fail("你要爬什么?\n");
          if (me->is_busy() || me->is_fighting())
                 return notify_fail("你正忙着呢。\n");

if(me->query("family") && me->query("family/family_name")!="逍遥派")
                  return notify_fail("你要爬什么??\n");
me->add_busy(3);
     message_vision("$N纵身一跃，消失在一条羊肠小路中不见了。\n", me);
          me->receive_damage("jing", 30);
          me->move("/d/xiaoyao/muwu2");
          return 1;
}

