// yzeroad1.c

inherit ROOM;

#include <ansi.h>
#include "/d/group/entry.h"

void create()
{
	set("short", "�����");

	set("long", "������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�\n"
		"������������������ǳ����֡���ʱ����������������߷ɳ۶���������\n"
		"һ·��������·��������������������֡�\n");

	set("exits", ([
		"east":"/d/city/eroad2",
		"west":"/d/city/dongmen",
		]));

	set("outdoors","���ݳ�");
	
	set("group",1);
	
	setup();
}
