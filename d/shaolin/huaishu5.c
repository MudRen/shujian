//huaishu5.c

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
		"west" : __DIR__ "lshuyuan",
                "northeast" : __DIR__ "hguangz1",
                "south" : __DIR__ "huaishu4",
       ]));
	set("coor/x",30);
  set("coor/y",320);
   set("coor/z",120);
   set("coor/x",30);
 set("coor/y",320);
   set("coor/z",120);
   setup();
}



