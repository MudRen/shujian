// Room: /u/bobo/tiezhang/dashishi.c

inherit ROOM;
#include <ansi.h>
#define QUESTDIR "quest/tzautopfm/"


void create()
{
	set("short", "大石室");
	set("long", @LONG
四周石壁上火把在燃烧着，墙角四周放满了大铁箱，打开一看，都是珠宝
黄金。中间架子上供着二件宝兵器，其一宛如一条金龙盘旋着，其二宛如一片
火红的云朵飘浮在空中。墙壁上密密麻麻的刻着一些图形和小字，似乎是什么
武功诀要。
LONG
	);

	set("exits", ([ 
"out" : __DIR__"taijie-2",
]));
        set("objects", ([
        __DIR__"obj/jia2" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
}


void init()
 {
     object me = this_player();


        add_action("do_study", "yandu");


     if(me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<100000)
       { 
      message_vision( HIW "$N看到兵器架上的武器，忽然若有所思。\n"NOR,me);
      message_vision( HIW "$N想了半天，没想起什么来，不由得摇了摇头。\n"NOR,me);

        }
     
else
      { if ( me->query("quest/tzauto/pass",1) 
            && me->query("combat_exp")>= 2000000 
            && me->query_skill("yingou-bifa",1) > 220
            && me->query_skill("lietian-fu",1) > 220
            && me->query_skill("liuye-daofa",1) > 220
            && me->query_skill("tiezhang-zhangfa",1) >220 
            && !me->query("quest/tzauto/over")  
            && random(me->query("kar")) >26 ) 
           
                {  
       message_vision( HIW "$N看到兵器架上的武器，忽然想起当日慈恩所使用的掌法。\n"NOR,me);
       message_vision( HIR "$N心下思忖道：所谓招式，无非是发力之技巧，或以快打慢，或以长搏短，\n", me);
       message_vision( "              兵器与否，无非是掌力不能及远，肉掌不若神兵之利耳。\n",me);
       message_vision( "$N不由得陷入了沉思中。。 \n"NOR, me);
       me->set(QUESTDIR+"time",time());
       me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
       me->start_busy(3);               
       remove_call_out("thinking");
		 call_out("thinking",5, me );
       
                }
       }            
 }



int thinking(object me)
{
  int i;
  if(!me) return 0;
	
  if(me->query_temp("try_auto")<(3+random(3)))
    { me->add_temp("try_auto",1);
          if(random(2)) tell_object(me,HIG"\n你用手掌比划着柳叶刀和裂天斧的招式,只觉得头脑发昏...\n"NOR);
             else tell_object(me,HIY"\n突然间，你似乎抓到了什么...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"似乎在思索着什么，手里胡乱比划着。\n"NOR, ({}));
	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);
	}
  else
   {
      me->delete_temp("try_auto");
      i=random(6);
     
     if(i = 5 && random(me->query("kar"))>20)
     {
       tell_object(me,HIG"\n你一掌挥出，去势轻灵，宛若天成！却是一招柳叶刀法！\n"NOR);
       tell_object(me,HIW"\n你一掌挥出，中途忽然骈指如笔，写了个大大的“武“字！却是一招银钩笔法！\n"NOR);

       message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
       tell_object(me,HIR"你成功的把铁掌武技融入了铁掌掌法中！\n"NOR);
       me->set("quest/tzauto/over",1);
       log_file("quest/tzautopfm", sprintf("%s(%s) 失败%d次成功融合了铁掌武技。富源：%d；经验：%d。",        me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
     }
    else
    {
       tell_object(me,HIG"\n你沉思许久，不得要领。\n"NOR);
       message_vision(HIC"\n$N摇了摇头，深深地叹了口气。\n"NOR,me); 
       me->add(QUESTDIR+"fail",1);
       log_file("quest/tzautopfm", sprintf("%s(%s) 融合铁掌武技失败：%d次。富源：%d；经验：%d。",        me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }

}




int do_study(string arg)
{
	int cost, my_skill;
 	object me=this_player();

	if (!arg) return 0;
	if( me->query("family/family_name") != "铁掌帮")
		return 0;
	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if((int)me->query("potential") < 1 )
		return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");

	if((int)me->query("combat_exp") < 150000 )
		return notify_fail("你的实战经验不足，再怎么读也没用。\n");

	if( me->query_int() < 30 )
		return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");

	cost = 10 * ( 1 + ( 35 - (int)me->query("int"))/20 );

	if (cost < 10) cost = 10;
	if( me->query("jing") < cost * 2 )
		return notify_fail("你现在太累了。还是先休息一下吧。\n");

	switch (arg) {
		case "lietian-fu":
			my_skill = me->query_skill("lietian-fu", 1);
			if( my_skill >= 221)
				return notify_fail("你觉得这洞壁上所刻已经太浅了，不能学到什么东西。\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("也许是缺乏实战经验，你对洞壁上所刻总是无法领会。\n");
			else
				write("你研读着有关裂天斧的技巧，似乎有些心得。\n");
			me->improve_skill("lietian-fu", ((int)me->query_skill("literate", 1)/3 + 1));
			me->receive_damage("jing", cost );
		              me->add("potential", - random(2));
		break;      
                case "axe":
			my_skill = me->query_skill("axe", 1);
			if( my_skill >= 221)
				return notify_fail("你觉得洞壁所刻已经尽藏胸中，没有什么可学的了。\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("也许是缺乏实战经验，你对洞壁上所刻总是无法领会。\n");
			else
				write("你研读着有基本斧法的技巧，似乎有些心得。。\n");
			me->improve_skill("axe", ((int)me->query_skill("literate", 1)/3 + 1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;             
		case "brush":
			my_skill = me->query_skill("brush", 1);
			if( my_skill >= 221)
				return notify_fail("你觉得这洞壁上所刻已经太浅了，不能学到什么东西。\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("也许是缺乏实战经验，你对洞壁上所刻总是无法领会。\n");
			else
				write("你研读着有关基本笔法的技巧，似乎有些心得。\n");
			me->improve_skill("brush", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;
                case "yingou-bifa":
			my_skill = me->query_skill("yingou-bifa", 1);
			if( my_skill >= 221)
				return notify_fail("你觉得这洞壁上所刻已经太浅了，不能学到什么东西。\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("也许是缺乏实战经验，你对洞壁上所刻总是无法领会。\n");
			else
				write("你研读着有关银钩笔法的技巧，似乎有些心得。\n");
			me->improve_skill("yingou-bifa", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;
		case "blade":
			my_skill = me->query_skill("blade", 1);
			if( my_skill >= 221)
				return notify_fail("你觉得这洞壁上所刻已经太浅了，不能学到什么东西。\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("也许是缺乏实战经验，你对洞壁上所刻总是无法领会。\n");
			else
				write("你研读着有关基本刀法的技巧，似乎有些心得。\n");
			me->improve_skill("blade", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;

		case "liuye-daofa":
			my_skill = me->query_skill("liuye-daofa", 1);
			if( my_skill >= 221)
				return notify_fail("你觉得这洞壁上所刻已经太浅了，不能学到什么东西。\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("也许是缺乏实战经验，你对洞壁上所刻总是无法领会。\n");
			else
				write("你研读着有关柳叶刀法的技巧，似乎有些心得。\n");
			me->improve_skill("liuye-daofa", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;
	}
	return 1;
}


