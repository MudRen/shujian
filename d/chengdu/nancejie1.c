// Room: /d/chengdu/nancejie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�ϲ��");
	set("long", @LONG
����һ����ͨ����ʯ��·���ϱ�ͨ���ϲ��ţ����߾��Ƕ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
                "north" : __DIR__"ddajie3",
		"south" : __DIR__"nancejie2",
	]));

	set("incity",1);
	setup();
}

