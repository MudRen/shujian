// yuanzi.c СԺ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","СԺ��");
       set("long", @LONG
����һ��СԺ�ӡ���һ�����������ŵ�һ��ǿ�ҵĻ��㣬ֻ��Ժ����ֲ��
���������Ļ��ݡ���������һ���᷿��
LONG);    
	set("exits", ([
		"southeast" : __DIR__"longwang",				
		"west" : __DIR__"wxiang",
	]));             
        set("objects",([
		__DIR__"npc/yahuan" : 1,
                __DIR__"npc/xtong" : 1,
	]));   
        set("outdoors", "���̹�����");
        set("coor/x",-250);
  set("coor/y",270);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",270);
   set("coor/z",120);
   setup();
}
