// htping.c  ����ƺ
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"����ƺ"NOR);
       set("long", @LONG
����һƬ�ϴ�Ļ���ƺ����Χֻ�м����ѸɿݵĹ����ͻ�ɳ�����Կ�����
����ǰ�������ޣ�������һ����Сɳ��
LONG);    
	set("exits", ([
		"southeast" : __DIR__"shaqiu4",
		"east" : __DIR__"shaqiu"+(random(3)+1),
		"west" : __DIR__"dashaqiu",
                "south" : __DIR__"shaqiu"+(random(3)+1),
	]));             
	set("objects",([
                CLASS_D("mingjiao") + "/wufu" : 1,
                __DIR__"npc/m-dizi" : 1,
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-320);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-320);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}
