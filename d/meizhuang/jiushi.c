// Room: /d/meizhuang/jiushi.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "酒室");
	set("long", @LONG
这里是一间酒室，门帷掀开，便是一阵扑鼻酒香。屋子里摆满了各色各样
的酒壶酒桶、各色酒具，芳香四溢。
LONG
	);

	set("exits", ([
		"east" : __DIR__"huilang4",
	]));
	set("objects", ([
		"d/meizhuang/npc/dingjiansuper" : 1,
				]) );
	setup();
}

void init()
{
        add_action("do_zuan", "zuan");
}

int do_zuan(string arg ,string dir)
{
        object ob;
        object me = this_player();
        
                if (!this_player()->query_temp("quest/xxdf/start")){
                write("你没事瞎钻什么桌子？\n");
             return 1;
        }

        if (arg != "table")
        {
                write("你想要往哪儿钻？\n");
                return 1;
        }

        if (objectp(ob = present("ding jian", this_object())) &&
            living(ob))
        {
                write("你偷偷的看了看" + ob->name() + "，不敢乱来。\n");
                return 1;
        }

        write("\n你蹑手蹑脚的绕到石桌的后面，钻进了下面的一个小洞。\n");
        if((int)me->query_skill("dodge",1) >= 30)
        {
              write("\n你费尽九牛二虎之力，发现自己到了一个很神秘的地道里。\n\n");
              me->move(__DIR__"didao1");
              return 1;
        }
        write("\n你试着钻了一下后面的一个小洞，发现钻不进去。\n");
        me->add("jing", -10);
        me->add("qi", -10);

        return 1;
}


int valid_leave(object me, string dir)
{
        object ding;

        if (dir != "north" ||
            ! objectp(ding = present("ding jian", this_object())))
                return ::valid_leave(me, dir);

        return ding->permit_pass(me, dir);
}