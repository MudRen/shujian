// shuiqi.c  ��ˮ��
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"��ˮ��"NOR);
       set("long", @LONG
�����Ǻ�ˮ�졣������ʮ��������ˮ�����е��Ӹ�����ͨˮ�ԡ��򶫾�
��ͨ����ˮ��̶��ɽ��С·�ˡ�
LONG);    
	set("exits", ([
		"west" : __DIR__"cl2",
                "east" : __DIR__"didao/senlin-8",		
		"north" : __DIR__"wu4",
		"eastdown" : __DIR__"shanlu1",
	]));             
	set("objects",([
		__DIR__"npc/dizi4"  : 3,
                CLASS_D("mingjiao") + "/tang" : 1,	
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-270);
  set("coor/y",190);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",190);
   set("coor/z",120);
   setup();
}
