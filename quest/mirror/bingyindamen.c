// Room: /city/bingyindamen.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "兵营大门");
	set("long", @LONG
	你正站在兵营的门口，面对着一排简陋的营房，可以看到穿着制服的官兵
正在操练，不时地传来呐喊声。老百姓是不允许在此观看的，你最好赶快走开。
LONG
	);
	set("exits", ([
		"south" : __DIR__"bingyin",
		"north" : __DIR__"xidajie1",
	]));

	setup();
}

//是镜像
int is_mirror() { return 1; }