// shaqiu1.c  Сɳ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"Сɳ��"NOR);
       set("long", @LONG
����һ��������ɳ��Сɳ����һ̤��������ʧ�˷��򡣿���Ҫ�߳����
ɳĮ�������¡�
LONG);    
	set("exits", ([
		"east" : "/d/group/entry/mjshamo1",
		"west" : __DIR__"shaqiu2",
		"south" : __DIR__"shaqiu"+(random(3)+1),
		"north" : __DIR__"shaqiu"+(random(3)+1),
	]));             
        set("outdoors", "���̹�����");
        set("mj_xl", "yinwufu");
	setup();
}

void init()
{
	object me;
	string arg;
	arg = this_object()->query("mj_xl");
	if(interactive(me = this_player())
	 && me->query_temp("mj/xunluo") 
	 && !me->query_temp(arg)
	 && me->query_temp("mj/xunluo") == 8)
		me->add_temp(arg,1);
}
