// shenchu2.c  �����
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
		"west" : __DIR__"shenchu1",			
		"northeast" : __DIR__"shenchu3",
                "southeast" : __DIR__"shenchu4",
                "north" : __DIR__"shenchu5",
	]));   
	set("objects",([
		MEDICINE_D("yaocao") : 1,
                BINGQI_D("da-shugan") : 1,
	]));
        set("outer_times", 4);
        set("outdoors", "���̹�����");
        set("coor/x",-310);
  set("coor/y",150);
   set("coor/z",100);
   setup();
}

#include "/d/mingjiao/npc/attacker.h";
