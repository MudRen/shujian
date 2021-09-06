#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"玩家登记室"NOR);
	set("long", @LONG
============================================================
    这里是新玩家等待账号激活的地方，玩家必须激活后才能正式
    开始游戏。
    
    请加入QQ群88397272或者联系QQ  10388172 来获取激活。
    
    为了更快的获得审核通过，请务必表述清楚你的id和注册email
    
    为了更好地管理书剑，对给大家带来的不便敬请原谅。
================================================================
LONG);
	set("no_death", 1);
//         set("no_summon_out", 1);
	set("no_save", 1);
	set("no_update", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);
	set("indoors", "书剑");
	setup();
}

void init()
{
        add_action("do_quit","suicide");      
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","chat");
        add_action("do_quit2","respirate");
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
        add_action("do_quit2","chat*");
        add_action("do_quit2","fight");
        add_action("do_quit2","kill");
        add_action("do_quit2","hit");
}

int do_quit(string arg)
{
        if(arg=="roar") {
        write(this_player()->query("name")+"，请加入QQ群88397272或者联系QQ  10388172 来获取激活！\n");
        return 1;
        }

        if(arg=="all") {
        write(this_player()->query("name")+"，请加入QQ群88397272或者联系QQ  10388172 来获取激活！\n");
        return 1;
        }
        if(arg=="corpse") {
        write(this_player()->query("name")+"，请加入QQ群88397272或者联系QQ  10388172 来获取激活！\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"，请加入QQ群88397272或者联系QQ  10388172 来获取激活！\n");
        return 1;
}

