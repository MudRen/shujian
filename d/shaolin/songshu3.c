//songshu3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��߸ߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��
������գ��������ڵ�˿��Ҳ�ޡ�һ���ྻ����ʯС���������С�
LONG
	);
        set("outdoor","shaolin");
	set("exits", ([
		 "north" : __DIR__ "songshu2",
                 "southwest" : __DIR__ "celang2",
                 "east" : __DIR__ "songshu4", 
          ]));
	set("coor/x",70);
  set("coor/y",290);
   set("coor/z",110);
   setup();
}



