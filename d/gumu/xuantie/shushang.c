// Room: shushang.c
// By River 98/09

inherit ROOM;

#include <ansi.h>
void create()
{
	set("short",HIG"����"NOR);
	set("long", @LONG
һ���ȳ�֮�������������̧ͷһ������ʱë���Ȼ��һ����ڴ�ϸ�ľ�
�������������ϣ��ſ���ڣ���Ҫ����������
LONG
	);
	
	set("exits",([
		"down" : __DIR__"shanlu7",
        ]));

	set("objects",([
		"/d/gumu/npc/dumang" : 1,
	]));

	set("outdoors", "����");

	setup();
}
