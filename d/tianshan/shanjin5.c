// Room: /d/tianshan/shanjin1.c
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
                "northup" : __DIR__"shanjin6",
		"west" : __DIR__"shanjin4",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
