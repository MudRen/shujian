// Room: /d/tianshan/room.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��ʱ����");
	set("long", @LONG
��ɽ������ʱ���䡣
LONG);
	 set("exits", ([
             //   "east" : __DIR__"",
        ]));       
        set("objects", ([
             //   __DIR__"npc/" : 1,
        ]));    
	set("outdoors", "��ɽ");
	setup();
}
