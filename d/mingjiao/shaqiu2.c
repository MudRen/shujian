// shaqiu2.c  Сɳ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
       set("short",YEL"Сɳ��"NOR);
       set("long", @LONG
����һ��������ɳ��Сɳ����һ̤��������ʧ�˷��򡣿���Ҫ�߳����
ɳĮ�������¡�
LONG);
	set("exits", ([
		"east" : __DIR__"shaqiu1",
		"west" : __DIR__"shaqiu3",
		"south" : __DIR__"shaqiu"+(random(3)+1),
		"north" : __DIR__"shaqiu"+(random(3)+1),
	]));
        set("outdoors", "���̹�����");
	set("coor/x",-300);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-300);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}
