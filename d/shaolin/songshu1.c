//songshu1.c

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
		 "east" :  __DIR__ "yaowang",
                 "northwest" :  __DIR__ "hguangz3",
                 "south" : __DIR__ "songshu2",
          ]));
	set("coor/x",70);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}



