// Room: /d/tianshan/shanlu1.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
����һ��ͨ��ɽ�ϵ�С·����Ϊ�˵س���ຮ��·������ֻ��Щ�ͺ��Ĳ�
��ֲ�����������ް�������С�ֻ��ɽ���Х��������Ϯ�����㲻�ɵĹ�
�������ϵ��·���
LONG);
	 set("exits", ([
                "east" :__DIR__"kongchang",
	        "northup" :__DIR__"shanlu2",
        ]));       
        set("objects", ([
                __DIR__"npc/zhuji" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
