// By River@SJ

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���˳ǽ������ܣ��������䣬�������ں����������ˡ�����������������
ëƤ��ɢ�أ������������Ƥ����һ�����żҿڣ���һ�������ǹ����ˣ�����
������������ʮ������ˮ�Ӽ������ݡ�
LONG );
	set("exits", ([
		"east"      : __DIR__"yaocaidian",
                "southeast"      : __DIR__"xjqiao",
		"northwest" : __DIR__"dacaigou",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke1" : 1,
	]));

	set("outdoors", "����");
	setup();
}
