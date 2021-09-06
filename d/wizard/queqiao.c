
// Date: Zhuifeng 2010

#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",  HIC "鹊 桥" NOR);
	set("long", @LONG
 这里就是鹊桥，每年农历七月七日，牛郎和织女就会得到允许在这里相会，
鹊桥边有一个千年"HIR"相思红豆"NOR"(Xiangsi dou)树，可以采集(caiji)红豆来祝福
这对每年只能见一次的神仙眷侣，也祝福自己也会有美满的爱情。

LONG
);

	set("no_clean_up", 0);
        set("exits", ([
                 "down" : "d/wizard/guest_room",
        ]));
    set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_caiji", "caiji");
}

int do_caiji(string arg)
{
	object ob;
        object me = this_player();

        if (arg != "xiangsi dou")
                return notify_fail("你要采什么？\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

          if( me->query("xsd2010"))
                return notify_fail("一个声音自空中响起，“乱采神仙果实要收到惩罚的，难道你采了一个还不够吗？！”\n");

        if ( (int)me->query("jingli")<400)
        	{
             	write("你现在太累了，休息一下吧！\n");
		return 1;
		}
        if(random(20) == 3)
        	{
        	me->add("jingli",-random(300));
        	return notify_fail("你使出吃奶的力气往上蹦，就是无法够到相思红豆，急得满头大汗。\n"); 
         	}

        if (present("xiangsi dou", me))
               return notify_fail("你身上已经有一枚"HIR"相思红豆"NOR"了，莫要贪得无厌！\n");
               
        message_vision("$N艰难的攀缘到树上，伸手采下了一枚"HIR"相思红豆"NOR""。\n, me);
        
        ob = new("/u/jpei/zhuguo");
        ob->move(me);
        me->set("xsd2010",1);
	return 1;
}


