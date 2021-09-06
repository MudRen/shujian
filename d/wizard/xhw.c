#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","小黑屋");
        set("long",
"这里是小黑屋，专门让犯规的玩家闭门思过的。
墙上似乎有模糊的字迹，你细看之下，上面似乎写着许多潦草的字迹。细细看去，居然是《九阴真经》！
另外一面墙上刻画了许多小人，手持长剑，招式甚是玄奥，依稀便是独孤九剑的招式！
");
        set("no_update", 1);
        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("sleep_room", 1);
        set("valid_startroom", 1);
        set("no_get",1);
        set("no_dazuo",1);
        setup();
}
void init()
{
        add_action("do_quit","suicide");      
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","chat");
        add_action("do_quit2","respirate");
        add_action("do_quit2","suicide"); 
        add_action("do_quit2","suicide -f"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}

int do_quit(string arg)
{
        if(arg=="roar") {
        write(this_player()->query("name")+"，安心的反省过错吧！\n");
        return 1;
        }

        if(arg=="all") {
        write(this_player()->query("name")+"，安心的反省过错吧！\n");
        return 1;
        }
        if(arg=="corpse") {
        write(this_player()->query("name")+"，安心的反省过错吧！\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"，安心的反省过错吧！\n");
        return 1;
}
