// Room: /d/tianshan/houyuan.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
������վ�����չ��ĺ�԰�԰�е�һЩ��֪����С���ں����ѩ�³���
����������ɢ������������㣬���Ե���ʯ����Ʈ��һЩ��Ҷ��
LONG);
	 set("exits", ([
                "north" : __DIR__"gyting",
	        "south" : __DIR__"zoulang6",
        ]));       
        set("objects", ([
             //   __DIR__"obj/****" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
