// Room: /d/tianshan/shanjin4.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ʯŪ��Ҳ�Ƶ�խ����Խ��Խ�ߣ��������֣���Լ�ɼ���������
���ʵ�ʯ�ڣ�����ֻ��һ�ߣ��㲻�ɵļӿ��˲�����
LONG);
	set("exits", ([
                "east" : __DIR__"shanjin5",
				"west" : __DIR__"shanjin3",
        ]));       
	set("objects", ([
                __DIR__"npc/linyang" : 1,
        ]));    
	set("outdoors", "��ɽ");
	setup();
}
