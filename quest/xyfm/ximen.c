// Room: /city/ximen.c
// YZC 1995/12/04 
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "西门");
	set("long", @LONG
	这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上
方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告示(gaoshi)。
这里是罪犯逃往西域的必经之地。
LONG
	);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"xidajie2",
         "south" : __DIR__"work1",
	]));
	setup();
}


//是镜像
int is_mirror() { return 1; }