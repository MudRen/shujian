// Room: /d/death/gateway.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"�ز���������"NOR);
	set("long", @LONG
����������һ����ɭ�Ĵ��ǰ�������Ĺ���Ƕ������ڴ˽�������
��㱼䣬������һ����ΰ�Ĵ��ǰ���˴����߻��ͣ�����Щ����Ǻ�֮
�����������⡣������������һ���������������ͷ���Ϲڣ��ǵز�
��������
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/pusa": 1,
                __DIR__"npc/shami": 2,
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
	     return notify_fail("һ�����ӷ�����������𡣡���ʹ�㲻����������ϥ����������\n");
	else return 1;
}
