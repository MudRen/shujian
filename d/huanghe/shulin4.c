//by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ
��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ��
������ԥ��ǰ���ĽŲ���
LONG );
	set("exits", ([
		"northwest"  : "/d/group/entry/hhshulin5",
		"east"       : __DIR__"shulin3",
		"south"      : __DIR__"shulin2",
	]));
	set("objects", ([
                __DIR__"npc/fox" : 1,
	]));

	set("outdoors", "�ƺ�");
	setup();
}
