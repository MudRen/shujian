// Room: /d/tianshan/shanlu2.c
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
                "southdown" :__DIR__"shanlu1",
	        "northup" :__DIR__"shanlu3",
        ]));          

	set("outdoors", "��ɽ");
	setup();
}
