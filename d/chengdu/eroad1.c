// Room: eroad1.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ��������ͨ���������񶼳ɶ��ˣ��򶫱��߿���
ȥ��������
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
		"west" : __DIR__"dadongmen",
		"northeast" : __DIR__"eroad2",
	]));

        set("objects", ([
                CLASS_D("gaibang/liuzz") : 1,
        ]));

	setup();
}
