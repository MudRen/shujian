// huoshan1.c ��ɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"��ɽ"NOR);
	set("long", @LONG
������һʲôҲ�������ˡ�������ֻ���л�����ĸо���
LONG
);
	set("exits",([
		"northup" : __DIR__"huoshan2",
		"eastdown" : __DIR__"hsjiao",
	]));
	set("outdoors","����");
	setup();
}

int valid_leave(object me, string dir)
{
      if (dir == "northup")
        me->set_leader(0);
      return ::valid_leave(me, dir); 
}
