// Room: /d/tianshan/dsqiao.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
�����Ƕ�ˮ�ţ����ǹ���ͤ�ͺ�԰��ɽ��һ����ˮ�ߡ�
LONG);
	 set("exits", ([
                "east" : __DIR__"jiashan",
	        "south" : __DIR__"gyting",
		"west" : __DIR__"huayuan",
        ]));       
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
