// Room: /d/tianshan/dadao3.c
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
                "southup" : __DIR__"ctbu",
                "northup" : __DIR__"jtbu",
		"west" : __DIR__"dadao10",
		"east" : __DIR__"dadao4",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
