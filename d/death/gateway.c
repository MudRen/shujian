// Room: /d/death/gateway.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"���޴��"NOR);
	set("long", @LONG
����������һ����ɭ�Ĵ��ǰ�������Ĺ���Ƕ������ڴ˽�������
�����У�Ϊ�Լ���ǰ��������Ϊ���ŨŨ��������������ܣ�����
��Զ������ɢȥ�Ƶġ����ϵ��м�յ��ƣ���Լ���ռ�ʮ��ڤ������Ӱ��
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/yanluo": 1,
                __DIR__"npc/bgargoyle": 1,
                __DIR__"npc/wgargoyle": 1,
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
	     return notify_fail("һ���ն�����������������𡣡���û�л�ͷ·�ˣ�\n");
	else return 1;
}
