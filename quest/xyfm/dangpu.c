// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "破旧当铺");
	set("long", @LONG
	这是一家以买卖公平著称的当铺，老板伙计都死绝了。
LONG
	);

	set("item_desc", ([
		"paizi": @TEXT
    本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。客倌可以在这里
看货(list)、购买(buy)、估价(value)、典当(pawn)、赎回(redeem)、卖
断(sell)各种货物。
TEXT
	]) );

	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	setup();

}
//是镜像
int is_mirror() { return 1; }