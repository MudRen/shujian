//huaishu1.c

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
		 "west" : __DIR__ "putiyuan",
                 "east" : __DIR__ "huaishu2",
          ]));
	set("coor/x",20);
  set("coor/y",300);
   set("coor/z",120);
   setup();
}



