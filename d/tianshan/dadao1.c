// Room: /d/tianshan/dadao1.c
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
                "north" : __DIR__"dadao2",
		"southup" : __DIR__"pmfeng",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
