// Room: /d/village/shilu6.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿������������
�Ҳ��࣬���Ҵ�����ܼ���������һ�����������ʯ·�������Ǽ���ͨ����
����
LONG
        );
        set("exits", ([
		"east"  : __DIR__"eexit.c",
		"west"  : __DIR__"shilu4.c",
		"south" : __DIR__"minfang2",
	]));
        set("outdoors", "��ɽ");

	setup();
}
