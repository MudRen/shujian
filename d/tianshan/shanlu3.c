// Room: /d/tianshan/shanlu3.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ͨ��ɽ�ϵ�С·����Ϊ�˵س���ຮ��·������ֻ��Щ�ͺ��Ĳ�
��ֲ�����������ް�������С�ֻ��ɽ���Х��������Ϯ�����㲻�ɵĹ�
�������ϵ��·���
LONG);
	 set("exits", ([
                "southdown" :__DIR__"shanlu2",
	        "northup" :__DIR__"shanlu4",
        ]));       
        set("objects", ([
                __DIR__"npc/zhuji" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
