// shenchu3.c  �����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",GRN"�����"NOR);
       set("long", @LONG
���������������ʮ�ɸߵ���ľ����һ�飬��ʵ��֦Ҷ��һ�����ɡ��
������գ��������ڵ�˿��Ҳ�ޡ���һ�߽������������ɭ�ֵģ���ĸо���
���㣬�øϿ��뿪�������������ˡ�
LONG);    
	set("exits", ([
		"east" : __DIR__"shenchu4",
                "south" : __DIR__"shenchu5",			
		"southwest" : __DIR__"shenchu2",
                "northwest" : __DIR__"shenchu1",
	]));   
	set("objects",([
		"/clone/misc/corpse" : 1,
                "/d/xingxiu/npc/snake" : random(3),
	]));
        set("outer_times", 4);
        set("outdoors", "���̹�����");
        set("coor/x",-310);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}

#include "/d/mingjiao/npc/attacker.h";
