// /d/mingjiao/jingqi.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIY"�����"NOR);
       set("long", @LONG
��������������ڵأ����̵Ļ��������������������֮�֡����µ��Ӳ�
���书׿Խ������һ��һ�İ������֣����ڶ�������������ߣ�������һֻ��
���¯�������ѵ������������Եκ��Ӵ�����������һ�����ȡ�
LONG);    
	set("exits", ([
                "south" : __DIR__"zl7",
                "southeast" : __DIR__"rukou",
		"west" : __DIR__"shiwang",
		"east" : __DIR__"didao/senlin-6",
	]));             
	set("objects",([
		__DIR__"npc/dizi5"  :        3,
                CLASS_D("mingjiao") + "/zhuang" : 1,
	]));
        set("coor/x",-270);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}
