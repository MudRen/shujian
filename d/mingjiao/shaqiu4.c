// shaqiu4.c  Сɳ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
       set("short",YEL"Сɳ��"NOR);
       set("long", @LONG
����һ��������ɳ��Сɳ����һ̤��������ʧ�˷��򡣿���Ҫ�߳����
ɳĮ�������¡�������������Լ���Լ�һ����ɳ��
LONG);
	set("exits", ([
		"east" : __DIR__"shaqiu3",
                "northwest" : __DIR__"htping",
		"south" : __DIR__"shaqiu"+(random(3)+1),
		"north" : __DIR__"shaqiu"+(random(3)+1),
	]));
        set("outdoors", "���̹�����");
	set("coor/x",-310);
  set("coor/y",80);
   set("coor/z",0);
   set("coor/x",-310);
 set("coor/y",80);
   set("coor/z",0);
   setup();
}
