// Room: /d/shaolin/talin9.c
// Date: hunthu

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
��������������ɮ�µ�Ĺ�أ��ϰ���Ĺ��ʽ�����࣬���͸��졣������
���У�ֻ�����ۻ����ң���֪�����ĸ������ߣ����ƺ���·�ˡ�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"talin"+(random(10)+1),
		"southeast" : __DIR__"talin"+(random(10)+1),
		"northwest" : __DIR__"talin10",
		"southwest" : __DIR__"talin"+(random(10)+1),
		"south"     : __DIR__"talin"+(random(10)+1), 
                "west"      : __DIR__"talin"+(random(10)+1),
                "north"     : __DIR__"talin8",
                "east"      : __DIR__"talin"+(random(10)+1),
	]));

	set("outdoors", "shaolin");

	set("coor/x",30);
  set("coor/y",300);
   set("coor/z",120);
   setup();

}

