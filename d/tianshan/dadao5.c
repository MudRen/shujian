// Room: /d/tianshan/dadao5.c
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
                "south" : __DIR__"dadao4",
		"westup" : __DIR__"jtbu",
		"eastup" : __DIR__"htbu",
		"north" : __DIR__"dadao6",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
