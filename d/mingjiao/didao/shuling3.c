// /d/mingjiao/shuling3.c
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
                "east" : __DIR__"shuling1",                     
                "west" : __DIR__"shenchu1",
                "south" : __FILE__,
                "north" : __DIR__"shuling4",
       ]));             
       set("outdoors", "���̹�����");
       set("coor/x",-310);
  set("coor/y",190);
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
