// shenchu1.c  �����
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
		"north" : __DIR__"shuling2",			
		"northwest" : __DIR__"shenchu2",
	]));   
	set("objects",([
		"/d/mingjiao/npc/laohu" : 1,
	]));
        set("outer_times", 4);
        set("outdoors", "���̹�����");
        set("coor/x",-300);
  set("coor/y",160);
   set("coor/z",100);
   setup();
}

#include "/d/mingjiao/npc/attacker.h";
