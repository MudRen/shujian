// Room: /d/tianshan/shizhuyan.c
// By Linux

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "ʧ����");
	set("long", @LONG
������ʧ���ң�����ɽɽ·�ؿڣ������ѩ���죬���ƶ�б�����Ǳ���ѩ
�أ�̤�㻬б����ʱ����к֮Σ�����˾���ֱ������ȡʧ��֮����
LONG);
	set("exits", ([
                "southdown" :__DIR__"duanhunya",
	        "north" :__DIR__"bzhanjian",   
        ]));    
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
