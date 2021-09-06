// fight.c

#include <ansi.h>
#include <pktime.h>

int main(object me, string arg)
{
	object obj,ob;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0)
		return notify_fail("武馆内禁止打人。\n");


	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if (me->query_temp("quit"))
		return notify_fail("正在退出游戏中，切磋武艺失败。\n");
		
	if( me->is_fighting(obj) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");

	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("你不能偷袭巫师等级比你高的对手。\n");

	if (obj==me) return notify_fail("打自己？别这么想不开。\n");

	if ( userp(me) && userp(obj) && obj->query("age") < 18 )
		return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n");
		
        if ( userp(me) && userp(obj) && me->query("combat_exp")<1000000)
 	
		return notify_fail("你目前还属于大米级别。。。\n");

	if (userp(me) && userp(obj)) {
		if(me->query("no_pk")) return notify_fail("你已经金盆洗手，如何还能做此等勾当。\n");
		if(obj->query("no_pk")) return notify_fail("对方已经金盆洗手，你还是放过他吧。\n");
			if(objectp(ob = present("hu wan", me))) return notify_fail("你还是把新手护腕丢下来再说吧！\n");
	}



if (userp(obj) && userp(me) && obj->query("combat_exp")<1000000) 
                return notify_fail("对不起，请爱护小朋友。\n");
/*
if (userp(obj) && userp(me) && me->query("combat_exp")<  obj->query("combat_exp") * 2 /3 &&  !obj->query_condition("killer") ) 
                return notify_fail("人家比你强这么多，你就不怕人家报复？\n");
		
if (userp(obj) && userp(me) && me->query("combat_exp") > obj->query("combat_exp") * 3 / 2 &&  !obj->query_condition("killer")) 
                return notify_fail("你比人家强这么多，这种小虾米也值得你动手？\n");
		
*/










// Add By River@SJ 2003.6.24
	if ( pktime_limit(me, obj))
		return 0;

/* add by cool for limit hit player to die */
	if ( userp(me) && userp(obj) &&
	   ( (obj->query("qi") < obj->query("max_qi")/2 )
	 || (obj->query("eff_qi") < obj->query("max_qi")/2 )) )
		return notify_fail("对方已经很虚弱，无力再和你切磋了。\n");

	if (!living(obj))
		return notify_fail(obj->name()+"已经无法还手了！\n");

        if ( obj->query("no_ansuan") || obj->query("job_npc") || obj->query("id")=="hou junji")
		return notify_fail("要杀就杀，搞什么偷袭！\n");

	if( userp(obj) ) {
		message_vision("\n$N对着$n大喝一声："+RANK_D->query_rude(obj)+"，接我一招试试！\n\n", me, obj);
		me->set_temp("hitting", 1);
		me->add_busy(1);
		if (userp(me))
{
 me->apply_condition("no_quit",20);
			obj->set_temp("other_kill/"+me->query("id"), 1);
						
			log_file("ANSUAN", 
                        sprintf("%-18s hit    %-18s",
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                obj->name(1)+"("+capitalize(getuid(obj))+")"
                        	),
                        	this_object(),
                	);
		}
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N对着$n大喝一声："+RANK_D->query_rude(obj)+"看招！\n\n", me, obj);
		me->fight_ob(obj);
		if (obj->accept_fight(me)) obj->fight_ob(me);
		else obj->kill_ob(me);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}
/*
	if (obj && obj->query_temp("last_hit_by") == me && me->query_temp("hit_time") == time()) {
		if (me->add_temp("hit_count", 1) > 4) me->add("combat_exp", -1000);
		if (me->query("combat_exp") < 0) me->delete("combat_exp");
		log_file("punish", me->query("id") + " hit " + obj->query("id") + "中奖了！\n");
	} else {
		me->set_temp("hit_time", time());
		me->delete_temp("hit_count");
	}
	if (obj) obj->set_temp("last_hit_by", me);
*/
	if (obj) COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 1);
	return 1;
}

void do_hit(object me, object obj)
{
	if (!me) return;
	me->delete_temp("hitting");
	if (!obj) return;
	if(objectp(present(obj, environment(me)))) {
		/*
		if (me->query_temp("kill_other/"+obj->query("id"))
		|| !obj->query_temp("kill_other/"+me->query("id"))
		&& !me->query_temp("other_kill/"+obj->query("id")))
			if (userp(me) && me->query("registered") < 3 && userp(obj) && obj->query("registered") > 2)
				me->unconcious();
		*/
		
		if(meisdummy(me,obj))
		{
			message_vision("$N忽然想起自己是死大米，顿时万念俱灰。\n", me);
			me->set("qi", -1);
			return;
		}
						
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon"), 2);
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 1);
	}
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>

这个指令让你向一个人物「讨教」或者是「切磋武艺」，这种形式的战斗纯粹是
点到为止，因此只会消耗体力，不会真的受伤，但是并不是所有的 NPC 都喜欢
打架，因此有需多状况你的比武要求会被拒绝。

其他相关指令: kill

PS. 如果对方不愿意接受你的挑战，你仍然可以迳行用 kill 指令开始战斗，有
    关 hit 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
