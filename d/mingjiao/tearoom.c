// tearoom.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"����"NOR);
       set("long", @LONG
������һ����ң���ר���д�����ʱ���ĵط���
LONG);    
	set("exits", ([		
		"east" : __DIR__"tingtang",
	]));             
	set("objects",([
             FOOD_D("tang") : 2,
             __DIR__"npc/xtong1" : 1,
	]));
	set("no_fight", 1);
        setup();       
}

void init()
{
       	object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("tearoom"))
           me->set_temp("tearoom",1);
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if((dir == "east")) {
	    while (i--)
                if(ob[i]->id("suanmei tang"))
                   return notify_fail(CYN"�̲�С�׺���һ���������˻�Ҫ����ѽ��\n"NOR);
	}
        return ::valid_leave(me, dir);
}
