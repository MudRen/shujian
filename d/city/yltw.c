// yue lao ting wai 月老亭外

inherit ROOM;

int do_get(string);

void create()
{
        set("short", "月老亭外");
        set("long", @LONG
这里是月老亭外，北面紧挨着东大街，南面的小亭子就是天下闻名的月老
亭了。每天都有许多人来此登记婚姻，所以一些专门从事婚嫁生意的轿夫之流
整天在此招徕生意。
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"dongdajie1.c",
                "south" : __DIR__"yuelaoting.c",
	]));

        set("objects", ([
                __DIR__"npc/jftou.c" : 1,
                __DIR__"npc/jiaofu.c" : 1,
                __DIR__"npc/lgshou.c" : 1,
                __DIR__"npc/snshou.c" : 1,
                __DIR__"obj/jiaozi.c" : 1,
	]));
	set("incity",1);
	setup();
}
