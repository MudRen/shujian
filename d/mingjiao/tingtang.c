// tingtang.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"����"NOR);
       set("long", @LONG
����һ���ܴ����ã������̽Ӵ���������֮�ء����õ���Χ���ż��Ź�ľ
����ļҾߣ���ǰ������һ�Ŵ�ʦ�Σ��ǽ����Ӵ����͵���λ������վ�ż���
СѾ����רΪ�����Ͳ�ˮ��
LONG);    
	set("exits", ([
       		"east" : __DIR__"xiangfang",
		"west" : __DIR__"tearoom",	
                "north" : __DIR__"muqi",
                "south" : __DIR__"qianting",			
	]));             
	set("objects",([
		__DIR__"npc/yahuan" : 1,
                __DIR__"npc/xtong" : 1,
	]));
        set("coor/x",-290);
  set("coor/y",150);
   set("coor/z",100);
   set("coor/x",-290);
 set("coor/y",150);
   set("coor/z",100);
   setup();
}
