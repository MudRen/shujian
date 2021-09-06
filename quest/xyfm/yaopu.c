// Room: /d/city/yaopu.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "破旧药铺");
	set("long", @LONG
	这是一家药铺，虽然破败不堪，但一股浓浓的药味还是让你几欲窒息。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "guanggao" : "本店出售以下药品：
金创药：	五十两白银
其他神药与老板面议。
",
]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
"north" : __DIR__"yaopuls",
]));
	setup();
}

//是镜像
int is_mirror() { return 1; }
