// By River@SJ 2001/9  

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"大驿道"NOR);
        set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着大
车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林,还有一片草丛。
LONG
        );
        set("outdoors", "沧州");
        set("exits", ([ 
                "south" : __DIR__"nroad1",
                "northwest" : __DIR__"nroad3",
        ]));

set("油布小包", 1);

        setup();
}

void init()
{
 add_action("do_search", "search");
 
}

int do_search(string arg)
{
object me = this_player();
object ob;
mapping fam;
fam = me->query("family");

if ( me->is_busy() || me->is_fighting())
  return notify_fail("你正忙着哪！\n");
if( !arg || arg != "草丛" ) return 0;
if( arg == "草丛" ){
 if (!fam || fam["family_name"] != "星宿派") 
                return notify_fail("你拨了拨草丛，并没有什么发现，不禁有些怅然。\n");
if (me->query("quest/bingcan/fail") > 3 && me->query("registered") < 3 ) 
return notify_fail("你拨了拨草丛，并没有什么特别发现，不禁有些怅然。\n");
if ( present("youbu xiaobao", this_player()))
return notify_fail("你拨了拨草丛，并没有别的什么发现，不禁有些怅然。\n");
if (query("油布小包") <1  ) 
return notify_fail(HIR"你来晚了，油布小包已经给人取走了。\n"NOR);
ob = unew("clone/misc/xiaobao");
this_object()->add("油布小包",-1);


            message_vision(HIC"$N拨了拨周围的草丛，忽见左首草丛中有个油布小包,当即拾起。\n"NOR, me);
ob->set_temp("owner",me->query("id"));
     ob->move(me);

       
              return 1; 
        }
}


