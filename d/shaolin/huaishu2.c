//huaishu2.c

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
		"west" : __DIR__ "huaishu1",
                 "north" : __DIR__"huaishu4",
                 "southeast" : __DIR__ "celang1",
          ]));
	set("coor/x",30);
  set("coor/y",300);
   set("coor/z",120);
   set("coor/x",30);
 set("coor/y",300);
   set("coor/z",120);
   setup();
}



