// buoqi.c �һ���
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
           set("short",HIR"�һ���"NOR);
       set("long", @LONG
��һ��������ŵ�һ�ɹ�ǿ�ҵ������ζ����������һ��졣���������
���ָ��������ǹ��ʮ������µ�������С������������ɵ������Ǹ�������
�ǰ������ң������ǻ������ҡ��ɴ˿��Կ��������Ƕ�ô��ǿ�󡣱���������
����������һ�����ȣ������߾��Ǳ������ˡ�
LONG);    
	set("exits", ([
		"east" : __DIR__"cl1",	
                "west" : __DIR__"didao/senlin-7",			
		"north" : __DIR__"wu2",
                "south" : __DIR__"bingqi",
	]));             
	set("objects",([
		__DIR__"npc/dizi3" : 3,
                CLASS_D("mingjiao") + "/xin" : 1,
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-250);
  set("coor/y",230);
   set("coor/z",120);
   setup();
}
