// /d/mr/migong3.c

inherit ROOM;

void create()
{
	set("short","�Թ�");
	set("long",@LONG
�����ǹ���Ľ�ݵĵ����Թ�����Ȼ��ͨ��һ����Ҫ�ĵط������ܵ�ǽ����
����¶ˮ�������κ������ǣ���һ�߽�������ʧ�˷���
LONG);

	set("exits",([
		"east" : __DIR__"migong2",
		"west" : __DIR__"migong4",
		"north" : __DIR__"migong3",
		"south" : __DIR__"migong1",
	]));

	setup();
}

#include "migong.h"
