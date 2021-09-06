#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"师门密信"NOR, ({ "shimen mixin","mixin","letter" }) );
        set("long",HIY"这是一份师门通过秘密渠道传来的紧急调查(diaocha)情报。\n"NOR);
        set("unit", "份");
        set("weight", 90);
        set("no_sell",1);
        set("value", 0);
}

void init()
{
	add_action("do_diaocha","diaocha");
        add_action("do_jiaoxun","jiaoxun");
}

int do_diaocha(string arg)
{
	object me=this_player() , ob,npc ;

	if (!arg) return notify_fail("你要调查谁？\n");

	ob = present(arg, environment(me));

	if (!ob || !living(ob)) return notify_fail("你要调查谁？\n");
	
	
	if ( userp(ob) || ob->query_temp("party_job_target")!= me->query("id") )
		return notify_fail("这个人好象不是要调查那个吧！\n");
        if (me->query_temp("party_job_start"))
                return notify_fail("你已经调查出真相了，进行下一步吧！\n");
       if (me->query_temp("party_job_over"))
                return notify_fail("你已经调查出真相了，进行下一步吧！\n");

	message_vision(HIY"$N"HIY"远远向$n望去，只见$n神色闪烁不定。\n"NOR,me, ob);
	message_vision(HIR"\n只见$N面有赧色，吞吞吐吐说道：“其实我是受了....”\n"NOR, ob);
	message_vision(HIR"\n话音未落，暗地里窜出个人影，不由分说向$N攻去。\n"NOR, me,ob);
me->set_temp("party_job_start",1);
npc = new("/quest/party/guard");
npc->do_copy(me,0);
npc->move(environment(me));
npc->set("策反",ob);
npc->set_temp("target", me->query("id"));
me->kill_ob(npc);
npc->kill_ob(me);
	return 1;
}


int do_jiaoxun(string arg)
{
	object me=this_player() , ob,target ;
        int gx;  
	if(!arg ) return notify_fail("你要干什么？\n");

	
   
        if(me->is_busy() || me->is_fighting()) 
                 return notify_fail("你正忙着呢。\n"); 

if(me->query_temp("party_job_start"))
         return notify_fail("你先赶紧处理掉恶贼再说吧。\n");

if(!me->query_temp("party_job_over"))
         return notify_fail("不分青红皂白就想教训人，你够狠的。\n");

 
 if (present(arg, environment(me))->query_temp("party_job_target") != me->query("id") )
return notify_fail("这个人好象不是要调查那个吧！\n");

 if(objectp(ob) && ob==present("jianxi", environment(me)))
       if(ob->query("策反") == me->query_temp("party_job_npc") )
        return notify_fail("奸细还没除去，你抽的出空么。\n");
		
message_vision(HIR"\n$N上前语重心长地教训了$n"HIR"一番，$n羞愧万分无地自容。\n\n"NOR, me, present(arg, environment(me)));

  
//	me->set_temp("diaochaover",1); 
	me->start_busy(1);


TASKREWARD_D->get_reward(me,"师门贡献",1,0,0,random(2)+1,0,0,0,this_object());
gx = 1+random(2);
message_vision(HIY"$N从这任务中得到了"+CHINESE_D->chinese_number(gx)+"点师门贡献。\n"NOR, me);

me->delete_temp("party_job");
me->delete_temp("party_job_target");
me->delete_temp("party_job_over");
me->apply_condition("job_busy",2);
me->add("party_cont",gx);
me->set("job_name","师门贡献");

destruct(this_object());

	return 1;
}


	



