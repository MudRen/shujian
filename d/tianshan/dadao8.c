// Room: /d/tianshan/dadao8.c
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
                "northwest" : __DIR__"youtbu",
		"east" : __DIR__"dadao7",
		"south" : __DIR__"dadao9",				
        ]));       
	set("outdoors", "��ɽ");
	setup();
}
