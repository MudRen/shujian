// Room: /city/chaguan.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "靖边楼");
	set("long", @LONG
靖边乃取安定边疆之意，所为御敌于国门之外，忧国忧民的袁将军便
经常在此地巡查勘探敌情。
LONG
	);
	
	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	setup();
}
//是镜像
int is_mirror() { return 1; }