// tuqi.c ������
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"������"NOR);
       set("long", @LONG
�����Ǻ����졣�����и��ָ����Ŀ������ߣ����е���һ������С��������
����һ��������������ڽ��������湦���������������������죬���컥��
�н�֮�ơ�
LONG);    
	set("exits", ([
                "south" : __DIR__"zl6",
		"east" : __DIR__"longwang",
                "west" : __DIR__"didao/senlin-5",
	]));
	set("objects",([
		__DIR__"npc/dizi2" : 3,
                CLASS_D("mingjiao") + "/yan" : 1,
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-250);
  set("coor/y",260);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",260);
   set("coor/z",120);
   setup();
}
