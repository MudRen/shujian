// Room: /d/chengdu/xidajie1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ�������֡�����ͨ�������ţ������ǳ����ġ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"west" : __DIR__"xidajie2",
		"east" : __DIR__"center",
	]));

	set("incity",1);
	setup();
}

