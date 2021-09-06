// Room: /city/dongmen.c
// YZC 1995/12/04 
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "东门");
	set("long", @LONG
	这是东城门，一条笔直的青石板大道向东西两边延伸。东边是郊外，
隐约可见一片一望无际的树林，神秘莫测。西边是城里。北面有一片茂盛的青竹林。
LONG
	);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
                "south" : __DIR__"work",
		"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie2",
	]));
	setup();
}

//是镜像
int is_mirror() { return 1; }
