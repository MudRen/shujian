// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB "�﷿" NOR);
	set("long", "�������һ�����һ��С���䣬����һЩ�����ͱ�����\n");
	set("sleep_room",1);
	set("exits", ([
		"out" : __DIR__"jicui.c",
	]) );
	set("objects",([
		BINGQI_D("sword/biyuxiao") : 1,
		BINGQI_D("tiexiao") : 1,
		BINGQI_D("yuxiao") : 1,
		BINGQI_D("xiao") : 1,
		BINGQI_D("sword/ziyuxiao") : 1,
	]));
	setup();
}
