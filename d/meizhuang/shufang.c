// Room: /d/meizhuang/shufang.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������һ���鷿�����÷�������������ȥ��ֻ��ǽ���ϵ�������һ������
�ܣ���ɫ���㣬��ʽ���¡�����Ȼ���Ǻܶ࣬���Ƕ��ܹžɡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"huilang7",
	]));

        set("objects", ([
                __DIR__"npc/tubiweng" : 1,
        ]));

	setup();
}