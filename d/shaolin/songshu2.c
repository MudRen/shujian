//songshu2.c

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
		 "north" : __DIR__ "songshu1",
                 "west"  : __DIR__ "stoneroad1",
                 "south" : __DIR__ "songshu3",
          ]));
	set("coor/x",70);
  set("coor/y",300);
   set("coor/z",110);
   setup();
}



