// Room: /d/chengdu/nancejie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�ϲ��");
	set("long", @LONG
����һ����ͨ����ʯ��·���ϱ������ؾ����ϲ��ţ����߲�Զ�Ƕ���֡�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"nancejie1",
                "south" : __DIR__"nanmen",
	]));

	set("incity",1);
	setup();
}

