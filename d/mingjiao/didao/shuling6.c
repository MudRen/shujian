// /d/mingjiao/shuling6.c
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
		"east" : __DIR__"shuling5",		
		"west" : __DIR__"shenchu4",
                "south" : __FILE__,
                "north" : __DIR__"shuling4",
	]));             
	set("objects",([
                CLASS_D("mingjiao") + "/chang" : 1,
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-300);
  set("coor/y",180);
   set("coor/z",100);
   setup();
}

void init()
{
      string a,b,c,d;
      a =query("exits/west");
      b =query("exits/north");
      c =query("exits/south");
      d =query("exits/east");

       set("exits/north", a);
       set("exits/south", b);
       set("exits/west", c);
       set("exits/east", d);
}
