//chufang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","����");
       set("long", @LONG
������ݵĳ���, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, ���ݵĹ�������㣬ʹ��һ�߽������
��������������������뱥��һ�١��м�����������æµ�š�
LONG);

        set("exits", ([         
                "east" : __DIR__"zoulang1",
        ]));             

        set("objects",([
                FOOD_D("dawancha") : 2,
                FOOD_D("rice") : 1,
                __DIR__"npc/wang1"  : 1,
        ]));

        set("no_fight", 1);

        setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if( dir == "east" ){
		while (i--)
		if(ob[i]->id("tea") || ob[i]->id("rice"))
			return notify_fail(CYN"�����Ӻ���һ�����Ա������˻�Ҫ����ѽ��\n"NOR);                
	}
	return ::valid_leave(me, dir);
}
