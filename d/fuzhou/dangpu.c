// Room: /d/fuzhou/dangpu.c
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������������ƽ���Ƶ����ֺŵ��̣�һ���ĳ߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)�� ��̨�����ŵ��̵��ϰ壬һ˫���������
���������´������㡣
LONG
	);
	set("no_fight",1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "��ƽ���ף�ͯ�����ۡ�\n",
	]));
	set("objects", ([
		__DIR__"npc/zhang" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	setup();
}

