// /d/mingjiao/shuling2.c
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
���㣬�øϿ��뿪��
LONG);    
	set("exits", ([
		"south" : __DIR__"shenchu5",			
		"north" : __DIR__"shuling6",
                "west" : "/d/mingjiao/muqi",
                "east" : __DIR__"shuling"+(5+random(2)),
	]));             
	set("objects",([
          BINGQI_D("da-shugan") : 1,
	]));
        set("outer_times", 10);
        set("outdoors", "���̹�����");
        set("coor/x",-300);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}

#include "/d/mingjiao/npc/attacker.h";
