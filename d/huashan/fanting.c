// Room: /d/huashan/fanting.c
// Date: Look 99/03/25
// By Spiderii@ty ȡ�������ͷ�
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
������ǻ�ɽ�ɵ����÷��ĵط����������Ǻܴ󣬵��������������ϰ���
һЩʳ����˴������Ρ���ʱ��һЩ��ɽ����������ȥ��������æЩʲô��
LONG
	);

	set("exits", ([
		"north" : __DIR__"yaofang",
		"east" : __DIR__"celang3",
	]));
	set("objects",([
			__DIR__"npc/puren" : 1,
        	__DIR__"obj/qingshui-hulu" : 1,
	]));
	set("indoors", "��ɽ" );
	setup();
}

int not_at_all(string arg)
{
	if (arg == "all") {
		write("����˵��������ط�������С��������㡣\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	if ( present("pu ren", environment(me))
       && (present("rice", me)
	  || present("fanqie yaoliu", me) || present("kousansi", me)
	  || present("niurou", me) || present("huasheng", me)
	  || present("tangcu liyu", me) || present("zhuachao liji", me)
	  || present("jitui", me) || present("rou pian", me)
	  || present("doufu", me) || present("douhua", me)
	  || present("liangxi cuishan", me) )
	  && ( dir == "east" || dir == "north" ) )
	{
		return notify_fail("����˵��������������ȳ԰ɣ����߸�ʲô��\n");
	}
	return ::valid_leave(me, dir);
}
