// Room: /d/city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG );
	set("item_desc", ([ /* sizeof() == 1 */
		"xuegui": "
		日讲经书三起，日看纲目数页。
		通晓时务物理，参读古文诗赋。
		读书必须过笔，会课按时蚤完。
		夜读仍戒晏起，疑误定要力争。

	               知识无价。\n",
		"shujia":"一个一尘不染的书架。\n",
		"board": "
       本书院奉圣上恩旨自即日起封授学位：
\n" 
	]));
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"shuyuan2",
		"south" : __DIR__"dongdajie1",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("那是朱熹的私人寝室！！\n");
        return 1;
}

//是镜像
int is_mirror() { return 1; }