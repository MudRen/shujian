// Modify By River 98/12 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ʒ����������������Ƿ����ﲢ�����ң������ڵ�������ʰ�ľ�
���е������ӽǷ��ż��ѳ�����
LONG
	);

        set("exits", ([
		"west" : __DIR__"lang6",
	]));

	set("objects", ([
		"/clone/weapon/changjian" : 2,
	]) );
        set("coor/x",-260);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}

