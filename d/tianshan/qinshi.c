// Room: /d/tianshan/qinshi.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�侫�µ�С�ᣬһ���ű��ŵ�һ��Ũ�ҵĻ��㣬���������廨��
�棬�ƺ�����ɽͯ�ѵ����ҡ�
LONG);
	 set("exits", ([
		"north" : __DIR__"zoulang5",
        ]));       
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    
	setup();
}
