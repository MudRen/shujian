// /d/mingjiao/zhoulang6.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"����"NOR);
       set("long", @LONG
����һ�����ȡ�һ������שǽ�ڣ���һ���ǹ�ľ��ɵ�Χ��������ͨ������
ȴҲ�����������һ����ƶ��ϡ��ϱ������䳡������ͨ�������졣
LONG);    
	set("exits", ([		
                "north" : __DIR__"tuqi",
		"south" : __DIR__"wu2",
	]));
        set("objects",([
                CLASS_D("mingjiao") + "/shuo" : 1,
	])); 
        set("outdoors", "���̹�����");         
        set("coor/x",-250);
  set("coor/y",250);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",250);
   set("coor/z",120);
   setup();
}
