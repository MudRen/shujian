// Room: /d/meizhuang/neishi.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ң�����һ��һ��������򵥣����Ϲ���ɴ�ʣ����ǳ¾ɣ���
�ʻ�ɫ�����Ϸ���һ�Ŷ��٣�ͨ����ڣ��������ơ�
LONG
	);
	set("exits", ([
		"south" : __DIR__"qinshi",
	]));

	setup();
}