// eatroom.c ���� 
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"����"NOR);
       set("long", @LONG
���ݵĹ�������㣬��һ�߽�����ŵ��������������������������һ
�ٵ���ͷ���м�����������ææµ�ţ��м���С�������̺��š�
LONG);
	set("exits", ([		
		"east" : __DIR__"xting",
	]));             
	set("objects",([
             FOOD_D("tang") : 2,
             FOOD_D("zongzi") : 1,
             __DIR__"npc/xtong2" : 1,
	]));
        set("no_fight", 1);
        set("coor/x",-300);
  set("coor/y",210);
   set("coor/z",120);
   set("coor/x",-300);
 set("coor/y",210);
   set("coor/z",120);
   setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("eatroom"))
           me->set_temp("eatroom",1);
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
        if((dir == "east")){
          while (i--)
          if(ob[i]->id("suanmei tang") || ob[i]->id("zongzi"))
             return notify_fail(CYN"С�׺���һ�����Ա������˻�Ҫ����ѽ��\n"NOR);
        }
        return ::valid_leave(me, dir);
}
