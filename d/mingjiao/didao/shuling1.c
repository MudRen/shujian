// /d/mingjiao/shuling1.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",GRN"����"NOR);
       set("long", @LONG
����һƬ�����֡���ʮ�ɸߵ���ľ����һ�飬��ʵ��֦Ҷ��һ�����ɡ��
������գ��������ڵ�˿��Ҳ�ޡ���һ�߽������������ɭ�ֵģ���ĸо���
���㣬Ҫ�Ͽ��뿪�����������̵ľ�ľ�졣
LONG);    
	set("exits", ([
		"east" : "/d/mingjiao/muqi",			
		"south" : __DIR__"shuling3",
		"west" : __DIR__"shuling4",
                "north" : __DIR__"shuling"+(3+random(2)),
	]));    
	set("objects", ([
             BINGQI_D("shitou") : 1,
	     BINGQI_D("da-shitou") : 1,
	]));
        set("outer_times", 10);
        set("outdoors", "���̹�����");
        set("coor/x",-300);
  set("coor/y",190);
   set("coor/z",100);
   setup();
}

#include "/d/mingjiao/npc/attacker.h";

