// snowman.
// yuj.

#include <ansi.h>
inherit F_CLEAN_UP;

void do_recover(object ob, int j)
{
	int i;
	mapping skills, learned;
	string *sk;

	if (j < 1 || j > 5) return;
	while(j--) {
		skills = ob->query_skills();
		if (mapp(skills)) {
			sk = keys(skills);
			ob->improve_skill(sk[0], 1, 1);
			learned = ob->query_learned();
			learned[sk[0]]--;
			foreach (string skill in sk) {
				i = (skills[skill]+1)*(skills[skill]+1);
				if ((learned[skill]+=i/2) > i) {
					skills[skill]++;
					learned[skill] -= i;
				}
			}
		}
		i = ob->query("death_lost_exp");
		ob->add("combat_exp", i);
		ob->add("shen", ob->query("shen")/9);
		i = ob->query("potential");
		i += i/3;
		if (i > ob->query("max_pot")) i = ob->query("max_pot");
		ob->set("potential", i);
		i = ob->query("death_count") - 1;
		if (i < 0) i = 0;
		ob->set("death_count", i);
		if (i < ob->query("death_times")) ob->set("death_times", i);
	}
	ob->reincarnate();
}

int main(object me, string arg)
{
	int i, j = 1;
	string obj, reason;
	object ob;
	mapping note;

	if( !arg )
		return notify_fail("recover <某人> [次数] because [原因]。\n");

	if( sscanf(arg, "%s %d because %s", obj, i, reason)==3 ) j = i;
	else obj = arg;

	if( !reason )
		return notify_fail("recover <某人> [次数] because [原因]。\n");

	ob = find_player(obj);
	if( !ob )  ob = find_living(obj);
	if( !ob )  ob = present(obj, environment(me));
	if( !ob ) return notify_fail("找不到这个生物。\n");

	if( !userp(ob) )
		return notify_fail("对方只是个NPC，不用这么小题大作吧？\n");

	if( (wiz_level(me) < wiz_level("(wizard)")) && me!=ob )
		return notify_fail("你没有恢复" + ob->name() + "死亡损失的权利。\n");

	message_vision(HIR "\n$N祭起"+chinese_number(j)+"道"BLU"鬼火"HIR"，将$n笼罩在其中，把$p又送入轮回！！\n\n"NOR,me,ob);

	tell_object(ob, HIW"你感到神情恍忽，宛若又遍历六道之界，恢复了不少损失！\n"NOR);
	
	note = (["title":"【死亡恢复】恢复玩家"+ob->name(1) + "("+ capitalize(ob->query("id"))+")死亡损失的公告",
			"author":me->query("name") + "(" + getuid(me) + ")",
			"time":0,
			"msg":0,
			]);	
			
	"/clone/board/wizto_b"->done_post(me,note,"【死亡恢复】" + ob->name(1) + "(" + capitalize(ob->query("id"))
		+ ")因为「"+reason+"」恢复"+chinese_number(j)+"次死亡损失。\n");
		
	if( ob!=me && !wizardp(ob) )
		log_file("static/RECOVER",
			sprintf("%s(%s) recovered %s(%s) %d times because %s\n", me->name(1),
				me->query("id"), ob->name(1), ob->query("id"), j, reason
			), me, ({ ob->query("id") })
		);
	do_recover(ob, j);
	ob->set("last_death", "已由巫师恢复");
	ob->delete("last_killer_id");
	ob->delete("last_death_time");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : recover <某人> [次数]

此命令将可恢复死亡损失，谨用！

HELP
    );
    return 1;
}
