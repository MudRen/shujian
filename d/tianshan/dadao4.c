// Room: /d/tianshan/dadao4.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ����ʯ���̳ɵĴ����ÿ����ʯ���ǳ�Լ�˳ߣ���Լ���ߣ�������
�룬Ҫ�̳������Ĵ�������̺ƴ�֮������֪�Ǻ���δ��������졣�������
������Щʯ�ˣ�����Ŀ�������ֳָ�ɫ����������֮�ľ���
LONG);
	 set("exits", ([
                "southeast" : __DIR__"ytbu",
		"west" : __DIR__"dadao3",
		"north" : __DIR__"dadao5",
        ]));       
	set("outdoors", "��ɽ");
	setup();
}
