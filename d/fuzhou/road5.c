// Room: /d/fuzhou/road5.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����ڶ��ϵ�һɽ������ɽ�ϡ�����Ӷ��洵�������ż��ֺ��⡣�ϱ߾�
�������ĺ��۸����ˡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"road4",
                "south" : __DIR__"beimen",
	]));

        set("objects", ([
		__DIR__"npc/baipao-jianxia" : 1,
		"/d/wudang/npc/yetu" : 2,
	]));

	set("outdoors", "����");
	setup();
}
