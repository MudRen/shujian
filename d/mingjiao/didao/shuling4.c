// /d/mingjiao/shuling4.c
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
                "north" : __DIR__"shenchu1",                    
                "south" : __DIR__"shuling3",
                "east" : __FILE__,
                "west" : __DIR__"shuling"+(5+random(2)),
       ]));             
       set("objects",([
                BINGQI_D("xiao-shuzhi") : 1,
                CLASS_D("mingjiao") + "/xu" : 1,
       ]));
       set("outdoors", "���̹�����");
       set("coor/x",-310);
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
