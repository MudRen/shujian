//huaishu4.c

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
		"east" : __DIR__ "stoneroad1",
                "west" : __DIR__ "slyuan",
                "north" : __DIR__ "huaishu5",
                "south" : __DIR__ "huaishu2", 
          ]));
	set("coor/x",30);
  set("coor/y",310);
   set("coor/z",120);
   set("coor/x",30);
 set("coor/y",310);
   set("coor/z",120);
   setup();
}



