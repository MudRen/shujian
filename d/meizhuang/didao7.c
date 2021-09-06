// didao7.c
inherit ROOM;
#include <wanted.h>

void create()
{
        set("short", "梅庄密道");
        set("long", @LONG
这是一条昏暗潮湿的地道，地道很长，两边点着两根不太明亮的
火把，地道两旁的墙壁上画着很多不知道出自何人之手的壁画，而且
画得相当难看。北面有一扇铁门，看样子已经被上了锁了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"didao6",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

void init()
{
        add_action("do_kai", "kai");
        if (present("ling tuisi", environment(this_player())))
                delete("exits/north");
}
int do_kai(string arg)
{
        object ob;
        if (query("exits/north"))
                return notify_fail("这扇门已经是打开的。\n");
                
        if (!arg || (arg != "men" && arg != "north"))
                return notify_fail("你要打开什么？\n");
        if (!(ob = present("hongyu yaoshi", this_player())))
                return notify_fail("你用不知道东西在门里转了几下,无奈怎么也打不开。\n");
        set("exits/north", __DIR__"jianyu");        
        message_vision("$N把红玉钥匙插入了一个匙孔，转了几转，向内推动。\n只听得轧轧声响，一扇石门缓缓开了。\n", this_player());
        message_vision("只听见“吧嗒”一声，好像是红玉钥匙断掉了。\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
        return ::valid_leave(me, dir);
}