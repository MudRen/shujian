// /u/beyond/hz/cuihezhai.c ���ի
#include <ansi.h>
 
inherit ROOM;
void create()
{
	set("short",HIW"���ի"NOR);
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����
̨�ϰ���һ������(sign)����̨������λ�ϰ壬һ˫�������۾��������´�
�����㡣
LONG
	);
	set("no_sleep_room",1);
        set("no_fight",1);
	set("item_desc", ([
		"sign" : "��ƽ����\n",
	]));
	set("objects", ([
		__DIR__"npc/dplaoban" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"qsddao4",
	]));

	set("coor/x",110);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}

 