
//action@sj 2008

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "石洞");
        set("long", @LONG
这是沙漠中天然形成的一个石洞，洞中光线昏暗，但却十分干燥,
墙壁上爬慢了蜘蛛。
LONG
        );

        set("exits", ([
                "out" : __DIR__"shidong",               
        ]));
        set("objects",([
        ]));
        set("no_clean_up", 0);
        set("outdoors", "兰州");
        setup();
}
void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
        object obj, me;
        int j;
        me = this_player();

        if( ! arg || (arg != "misc"))
          return notify_fail("你要找什麽？\n");
	      if( me->is_busy() )
		      return notify_fail("你上一个动作还没有完成！\n");
	     if( me->is_fighting() )
		      return notify_fail("你还是专心作战吧！\n");
        if ((int)me->query("jingli") < 500) 
           return notify_fail("你的精力不够做这件事！\n");  
      	message_vision(HIC"$N蹲在地上，四处寻找。\n"NOR, me);
        me->start_busy(1);
        if(random(6)!=1) 
        {
           me->add("jingli",-200);
           tell_room(environment(me), me->name() + "找了半天，只弄了一手泥。\n", ({ me }));
           return notify_fail("你找了半天，什么也没找到。\n");
        }
        else
        {
        obj = new("d/xiakedao/npc/obj/binghuojiu");
        message_vision(HIB"$N终于发现墙角有一只小箱子。你从箱子里得到一瓶很奇怪的酒。\n"NOR,me);
        me->add("jingli", -500);
        obj->set("owner",me->query("id"));
        obj->move(me);
        j=me->query_skill("force");
        if(random(2)) obj=new("/clone/animal/zhizhu");
        else obj=new("/clone/animal/zhizhu");
        message_vision(HIB"突然，墙壁上突然串出一只"+obj->name()+"。\n"NOR,me);
		    obj->set("combat_exp", me->query("combat_exp"));
		    obj->set("max_qi", me->query("max_qi")*4);
		    obj->set("eff_qi", me->query("max_qi")*4);
		    obj->set("qi", me->query("max_qi")*4);
		    obj->set("max_jing", me->query("max_jing"));
		    obj->set("jing", me->query("max_jing"));
		    obj->set("eff_jing", me->query("eff_jing"));
		    obj->set("eff_jingli", me->query("eff_jingli"));
		    obj->set("max_neili", me->query("max_neili"));
		    obj->set("jing", me->query("max_jing"));
		    obj->set("jingli", me->query("max_jingli"));
		    obj->set("neili", me->query("max_neili")*3/2);
		    obj->set("jiali", 200);
		    obj->set("str", me->query("str")*2);
		    obj->set("con", me->query("con"));
		    obj->set("dex", me->query("dex")*2);
		    obj->set("int", me->query("int")*2);
		    obj->set_skill("unarmed",j +random(50));
		    obj->set_skill("force",j + random(50));
		    obj->set_skill("dodge",j + random(50));
		    obj->set_skill("parry",j + random(50));
		    obj->move(environment(me));
		    obj->set_leader(me);
		    obj->kill_ob(me);
		    message_vision(RED"$N决定和$n一起行动。\n"NOR,obj,me);
        return 1;
       }
}
