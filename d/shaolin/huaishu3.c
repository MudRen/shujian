//huaishu3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ǰһ�����߽�һƬ�����֣�֦ͷ����������������絴������һ����
������֮���ڡ�����һ ��С����������ǰ����
LONG
	);
        set("outdoor","shaolin");
	set("exits", ([
		"south" : __DIR__ "huaishu2",
                "west" : __DIR__ "huaishu4",
                "north" : __DIR__ "huaishu5",
                "east"  : __DIR__ "stoneroad",
       ]));
	setup();
}



