// Room: /d/shaolin/talin10.c
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
		"southeast" : __DIR__"talin9",
		"northwest" : __DIR__"talin"+(random(10)+1),
		"southwest" : __DIR__"talin11",
		"south"     : __DIR__"talin"+(random(10)+1), 
                "west"      : __DIR__"talin"+(random(10)+1),
                "north"     : __DIR__"talin"+(random(10)+1),
                "east"      : __DIR__"talin"+(random(10)+1),
	]));

	set("outdoors", "shaolin");

	set("coor/x",20);
  set("coor/y",310);
   set("coor/z",120);
   setup();

}

