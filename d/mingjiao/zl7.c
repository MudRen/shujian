// /d/mingjiao/zhoulang7.c
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
ȴҲ�����������һ����ƶ��ϡ��ϱ������䳡������ͨ������죬���ϱ���
���ڼ�����ڡ�
LONG);    
	set("exits", ([		
		"south" : __DIR__"wu4",				
		"north" : __DIR__"jinqi",
		"northeast" : __DIR__"rukou",
	]));             
	set("objects",([
                CLASS_D("mingjiao") + "/peng" : 1,
	]));    
        set("outdoors", "���̹�����");     
        set("coor/x",-270);
  set("coor/y",210);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",210);
   set("coor/z",120);
   setup();
}
