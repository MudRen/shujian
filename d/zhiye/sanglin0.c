// ɣ����
// sanglin0.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ɣ����");
	set("long",
"����һƬ��Χ�����ɣ���֣��кܶ����ڴ˴����ϣ��������֡���Ϊ����
��Χ���󣬲���Ϥ�˴����˺�������ʧ���򣬺��ڹٸ��Ѿ����ֱ�·��������
ָʾ����ָ������ͬʱ����Ѳ��Ѳ��ɽ·����ֹ��ɱ�¼���
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"south"		: "/d/changan/northroad4",
		"northwest"	: __DIR__"sanglin1",
		"southeast"	: __DIR__"sanglin2",
		"southwest"	: __DIR__"sanglin3",
	]));
	
	set("outdoors", "��������");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

int valid_leave(object me, string dir)
{
	if( dir == "south" )
		me->delete_temp("sanglin1");
	else
		me->set_temp("sanglin1",random(4));

	if ( me->query("no_quest") && dir != "south")
		return notify_fail("");

	return ::valid_leave(me , dir);
}
