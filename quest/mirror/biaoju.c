// Room: /city/biaoju.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "临闾楼");
	set("long", @LONG
临闾楼在东城上接东罗城北角处，明万历十二年（1584年）建。因建东罗城连接关城，
虑有不测，特置楼设军。
LONG
	);
	set("exits", ([
		"south" : __DIR__"zhengting",
		"north" : __DIR__"xidajie2",
	]));

	setup();
}
//是镜像
int is_mirror() { return 1; }