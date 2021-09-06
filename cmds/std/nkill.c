// kill.c

#include <ansi.h>
#include <pktime.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string callname, msg;
	int gfight;

	if (!arg)
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( environment(me)->query("no_fight") && !obj->query_condition("killer"))
		return notify_fail("这里不准战斗。\n");

	if (userp(obj))
		return notify_fail("如果你确认要杀死该玩家，请使用kill指令！\n");

	if (strsrch(file_name(environment(me)),"/d/wuguan/") >= 0 )
		return notify_fail("武馆内禁止杀人。\n");

	if (!obj->is_character() || obj->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");
		

	if (obj == me) return notify_fail("用 suicide -f 指令会比较快些。\n");

	if ( obj->query("job_npc") && me->query("registered") < 3 )
		return notify_fail("你不能对"+obj->name(1)+"下手。\n");

	if (userp(obj) && userp(me)
	&& (!living(obj) && me->query("mud_age") < (time() - me->query("birthday"))/24
	|| me->query("mud_age") < (time() - me->query("birthday"))/48))
		return notify_fail("死大米，一边凉快去。\n");

	if (me->is_killing(obj->query("id")) && me->is_fighting(obj))
		return notify_fail("加油！加油！\n");

	if (me->query_temp("combat_yield"))
		return notify_fail("你正打不还手呢，怎么杀？\n");

	if ( obj->query("job_npc") && (me->query("kill_job_npc/time") + 86400) > time())
		return notify_fail("你刚杀过"+me->query("kill_job_npc/target")+"，还是得饶人处且饶人吧。\n");

	callname = RANK_D->query_rude(obj);

	if(me->query("race")=="人类"){
		if(me->query("mute"))
			msg = "\n$N突然冲向$n，双眼通红，看来是要至$p于死地！！\n\n";

		else if(stringp(me->query("env/kill_msg")) && strlen( strip(me->query("env/kill_msg")) ) < 50 )
			msg = "\n$N对着$n大喝一声：「"+callname+"！"+me->query("env/kill_msg")+"！」\n\n";

		else if(me->query("combat_exp") > obj->query("combat_exp")*2){
			if(me->query("shen") < -10000)
				msg = "\n$N对着$n啐了一口：「"+callname+"！怪你生不逢时，"+RANK_D->query_self_rude(me)+"今天看你极不顺眼，认命吧！！」\n\n";
			else msg = "\n$N对着$n吼道：「"+callname+"！你记好"+RANK_D->query_self_rude(me)+"的名字，死后到阴司去告我一状吧！！」\n\n";
		}

		else if(obj->query("combat_exp") > me->query("combat_exp")*2){
			if(me->query("shen") < -10000)
				msg = "\n$N对着$n一声奸笑：「"+callname+"！别看你平时耀武扬威，今天"+RANK_D->query_self_rude(me)+"就要取你性命！！」\n\n";
			else msg = "\n$N对着$n嘿嘿一笑："+callname+"，我虽技不如你，但今天就是拼了命也要将你碎尸万断！！\n\n";
		}

		else {
			if(me->query("shen") < -10000)
				msg = "\n$N对着$n猛吼一声：「"+callname+"！明年的今天就是你的祭日，让"+RANK_D->query_self_rude(me)+"送你上路吧！！」\n\n";
			else    msg = "\n$N对着$n喝道：「" + callname + "！你死期已到，今天就让"+RANK_D->query_self_rude(me)+"送你上西天吧！」\n\n";
		}

	}
	else msg = "\n$N大吼一声，猛然扑向$n，看来是要将$p杀死！！\n\n";

	message_vision(msg, me, obj);

	me->delete_temp("guarding");
	obj->set_temp("guarding", 1);
	me->kill_ob(obj);

	if (userp(me) && userp(obj))
		log_file("ATTEMP_KILL",
			sprintf("%s(%s)(%s) 试图杀死 %s(%s)\n",
				me->name(1),me->query("id"),query_ip_number(me),obj->name(1),obj->query("id")
			), me, ({ obj }),"1"
		);

	if (!userp(obj))
		obj->kill_ob(me);
	else if (!me->is_killing(obj->query("id"))) {
		if (userp(me))
			tell_object(obj,
				HIR  + me->name()+ "("
				+capitalize(me->parse_command_id_list()[0])+")想和你性命相搏，可他还是忍下了这个冲动。\n"NOR
			);
	} else {
		obj->fight_ob(me);
		if (userp(me)) {
			tell_object(obj,
				HIR "如果你要和" + me->name()+ "("
				+capitalize(me->parse_command_id_list()[0])+")性命相搏，请你也对这个人下一次 kill 指令。\n"NOR
			);
			if ( (!obj->query_condition("killer") || !obj->query_condition("pk"))
			&& (me->query_temp("kill_other/"+obj->query("id"))
			|| !obj->query_temp("kill_other/"+me->query("id"))
			&& !me->query_temp("other_kill/"+obj->query("id")))) {
				if ( strsrch(file_name(environment(me)), "/cmds/leitai/bwdh") >= 0 )
					return 1;
				gfight = GROUP_D->is_group_fight(me,obj);
				if( gfight != 1 ) {
					if( gfight < 0 ) me->add_busy(15); else me->add_busy(2);
					message_vision("$N无法马上向$n发动攻击。\n", me, obj);
				}
			}
		}
	}
		
        if(meisdummy(me,obj) && !strsrch(file_name(environment(me)), "/cmds/leitai/dzd") >= 0 )
	{
		message_vision("$N忽然想起自己是死大米，顿时万念俱灰。\n", me);
		me->set("qi", -1);		
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : nkill <NPC>

这个指令让你主动开始攻击一个NPC，并且试图杀死对方，nkill 和 kill 最大的
不同在于你只能对NPC使用这个指令。NPC对你使用 kill。

其他相关指令: kill fight

HELP
    );
    return 1;
}
