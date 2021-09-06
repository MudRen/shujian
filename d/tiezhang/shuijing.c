// Room: /u/zqb/tiezhang/shuijing.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIM"蝴蝶泉"NOR);
	set("long", @LONG
在向前行，一路上嫣红姹紫，遍山遍野都是鲜花。春光烂漫已极。转过一
树花丛，眼前出现一眼泉水，泉水清澈见底，散发出一种沁人心脾的清凉。泉
水的旁边，飞舞一群群的蝴蝶，或花或白，或黑或紫，翩翩起舞。蝴蝶并不畏
人，飞近时便在人们的身上停留。
LONG
	);

        set("outdoors", "tiezhang");
	set("exits", ([ 
"northwest" : __DIR__"guajia",
]));

	// set("no_clean_up", 0);
	set("resource", ([ 
"water" : 1,
]));

	
set("世系表", 1);
   setup();
}


void init()
{
        add_action("do_tan", "mo");
}

int do_tan(string arg)
{
        object room, me,ob;
        mapping fam;
 
        me = this_player();
        fam = me->query("family");

        if(!living(me) ) return 0;

        if ( me->is_busy() || me->is_fighting())
              return notify_fail("你正忙着哪！\n");

        if( !arg || arg != "水底" ) return 0;

        if( arg == "水底" ){
            if ((!fam || fam["family_name"] != "姑苏慕容") )
                return notify_fail("你伸手探了探水底，只觉泉水清凉爽快。\n");
if ( present("shixi biao", this_player()))
return notify_fail("你伸手探了探水底，只觉泉水清凉爽快无比。\n");

if (query("世系表") <1  ) 
return notify_fail(HIR"你来晚了，世系表已经给人取走了。\n"NOR);
ob = unew("d/tiezhang/obj/yuxi");
this_object()->add("世系表",-1);
            message_vision(HIC"$N将身趴低，伸手向水底探去，却不经意间摸到一件东西。\n"NOR, me);

ob->set("owner",me->query("id"));
    ob->move(me);

              return 1; 
        }
}




