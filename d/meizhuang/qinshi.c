// Room: /d/meizhuang/qinshi.c
// By Lklv 2001.9.11

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG

����һ�����ң����䲻�Ǻܴ󣬵��Ǻܱ��£��������Σ�һ�Ų輸����ǽ
��λ�������񴲣���ͷ�ļ��Ϸ���һ�����٣��Ա߱��Ϲ���һ��������������
������һ��̴���ζ����
LONG
	);
	set("exits", ([
		"south" : __DIR__"huilang19",
		"north" : __DIR__"neishi",
	]));

        set("objects", ([
                __DIR__"npc/huang" : 1,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("huangzhong gong", environment(me))) && dir == "north")
		return notify_fail("���ӹ�������ü����û���벻Ҫ�Ҵ���\n");

	return ::valid_leave(me, dir);
}
