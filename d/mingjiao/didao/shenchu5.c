// shenchu5.c  �����
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
		"south" : __DIR__"shenchu2",
                "north" : __DIR__"shenchu3",
	]));   
	set("objects",([
                "/d/xingxiu/npc/snake"  : random(3)+1,
	]));
        set("mj_xl", "wen");
        set("mj_xl2",7);
        set("outdoors", "���̹�����");
        set("coor/x",-310);
  set("coor/y",160);
   set("coor/z",100);
   setup();
}

#include "mj_xunluo.h";
