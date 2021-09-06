// combatd.c
// optimize by Yu Jue, 1998/3/14
// fixed some small bugs by snowman, 01/12/1998
// added in winner_reward(), by snowman 15/03/1999
// Inflict the damage before call_out ob_hit, by snowman 26/10/1999
// moved messages to combat_msg.h   by snowman 28/10/1999
// added end_fight().  by snowman@SJ 26/11/1999
// Modify...   by snowman@SJ 05/12/1999
// modify bcs mr pfm bishen by tiantian@sj 5/22/2000
// modified by snowman@SJ 24/06/2000.  added GKS & BKS in killer_reward()
// Modified by snowman@SJ 02/08/2000.  force_hit() ���������˺����ơ�
// Modified by snowman@SH 04/08/2000.  skill_power ��ʽ�ı䡣
// Modified by snowman@SJ 20/08/2000.  fixed a small bug in ob_hit.
// Modified by YUJ@SJ 2001/05/14. lost_attack ap = 1
// Improved by YUJ@SJ 2002/06/07. ͬıͨ��
// Modified By Ciwei@SJ  add GPKS & BPKS 
// Update By lsxk@hsbbs    add ����Ч�� for ���ҵ���perform luandao   2007/5/12 
// By Spiderii ���������ǣ�hdjob�õġ�
// by lsxk@hsbbs  �޸ģ���������super��������ҵ��˺���
// by lsxk@hsbbs �޸ģ����Ϳ��ֶԱ������໥�ͷ�Ч��������busyʱ�����мܵļӳ�
// By Spiderii@ty ���ӱ���hubo
// By Jpei ���ϲ�����츳ϵͳ,�����˺���ֵ����ʵ��2011
//            skill_power ��ʽ�ı䡣
// ����ע������
#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <combat_msg.h>

public int last_damage(object me,object victim,int damage);

varargs void report_status(object ob, int effective)
{
	int qi = ob->query("qi");
	int eff_qi = ob->query("eff_qi") + ob->query_temp("apply/qi");
	int max_qi = ob->query("max_qi") + ob->query_temp("apply/qi");

	if (!max_qi) max_qi = 1;
	if (eff_qi > 0 && qi * max_qi < eff_qi * eff_qi)
		message_vision( "( $N" + status_msg(qi * 100 / max_qi) + " )\n", ob);
	else message_vision( "( $N" + eff_status_msg(eff_qi * 100 / max_qi) + " )\n", ob);
}


void announce(object ob, string event)
{
    string msg;
	object env = environment(ob);

	switch(event) {
		case "dead":
		      msg = "��ž����һ�����ڵ��ϣ������ų鶯�˼��¾����ˡ�\n\n";
                      if(userp(ob)) tell_object(ob,"\n�㡸ž����һ�����ڵ��ϣ������ų鶯�˼��¾����ˡ�\n\n");
			break;
		case "unconcious":
			if (ob->query("race") != "����")
		      msg = "�����˼��£�һ�������ε���ȥ��\n\n";
			else
             msg = "��־�Ժ�������һ�����ȣ����ڵ��ϻ��˹�ȥ��\n\n";
			break;
		case "revive":
			if (ob->query("blind") || ob->query("race") != "����")
		      msg = "����һ����Ť���˼��£������˹�����\n\n";
			else if(ob->query("mute"))
		      msg = "���������˹����������۾�վ����ҡ��ҡͷ��\n\n";
			else 
             msg = "���Ӷ��˶������������˼��������ѹ�����\n\n";
	}
	tell_room(env,"\n\n" + ob->name() + msg, ({ob}) );
}

// Modified by snowman@SJ 28/11/2000
void winner_reward(object killer, object victim)
{
	victim->set_temp("defeated_by", killer);
	killer->set_temp("defeat_obj", victim->query("id"));
	killer->defeated_enemy(victim);
}

// added by snowman@SJ 26/11/1999
void end_fight(object me, object victim)
{
	string debug = sprintf("%O", me);

	if( me->query("master_user/user") && !userp(me) )
		return;
	me->remove_enemy(victim);
	victim->set_temp("last_lost_to", me);
	victim->remove_enemy(me);
	if (!me) CHANNEL_D->do_channel(this_object(), "debug", debug);
	if (victim && me)
	if (me->query("race") == "����") {
		if (!me->query("mute") && victim->query("mute"))
			message_vision( winner_msg[random(sizeof(winner_msg)/2)], me, victim);
		if (me->query("mute") && !victim->query("mute"))
			message_vision(winner_msg[sizeof(winner_msg)/2 + random(sizeof(winner_msg)/2)], me, victim);
		if (!me->query("mute") && !victim->query("mute"))
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
	}
	else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, victim);
}

string query(string arg)
{
	if (arg == "channel_id")
		return "ս������";
}

void create()
{
	seteuid(getuid());
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int level, power;

	if (!living(ob)) return 0;

	level = ob->query_skill(skill);

	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack")/4;
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");
			if (ob->is_fighting())
				level += level * ob->query_temp("fight/"+skill) / 100;
	}

	if( level < 1 )
                power = ob->query("combat_exp") / 3600;
	else
                power = (to_int(sqrt(level)*level*level) + ob->query("combat_exp")/2) / 900;

	if (usage == SKILL_USAGE_ATTACK) return power * ob->query_str();
	return power * (skill == "dodge"?ob->query_dex():ob->query_int());
}

string adj_msg(string result, string limb, object weapon, mapping action, string attack_skill)
{
	string wname = "";

	if (objectp(weapon)) {
		if (weapon->query_amount() && weapon->query("skill_type") != "throwing")
			sscanf(weapon->short(), "%s(%*s", wname);
		else wname = weapon->name();
		result = replace_string(result, "$w", wname);
	}
	else if (stringp(action["weapon"]))     result = replace_string( result, "$w", action["weapon"] );
	else if (attack_skill == "finger")      result = replace_string( result, "$w", "��ָ" );
	else if (attack_skill == "cuff")	result = replace_string( result, "$w", "ȭͷ" );
	else if (attack_skill == "strike")      result = replace_string( result, "$w", "����" );
	else if (attack_skill == "claw")	result = replace_string( result, "$w", "��צ" );
	else result = replace_string( result, "$w", "" );

	if (stringp(action["limb"])) result = replace_string( result, "$l", action["limb"] );
	else result = replace_string( result, "$l", limb );
	return result;
}

mixed force_hit(object me, object victim, int damage_bonus, int factor, int em)
{
	int damage, my_neili, v_neili;
	object* env = environment(me)?filter_array(all_inventory(environment(me)),(:
		$1->query("env/combat")=="verbose"		
		:)):0;
	
	my_neili = me->query("neili") + factor;
	if (my_neili > me->query("max_neili"))
		my_neili = me->query("max_neili");
	v_neili = victim->query("neili");
	if (v_neili > victim->query("max_neili"))
		v_neili = victim->query("max_neili");
		
if (!me->query_temp("weapon")) 	damage = my_neili/20 + factor + factor*factor/200 - v_neili/30;
	     //���ӿ��ֵ������ӳɡ�
else 	damage = my_neili/25 + factor + factor*factor/400 - v_neili/30;

	damage /= 2;

	message("wizard", sprintf("����=%d ����=%d �Է�=%d �˺�=%d\n", my_neili, factor, v_neili, damage), env );

	if (damage < 0) {
		if (!me->query_temp("weapon")
		&& !me->query_temp("hit_ob_hit")
		&& !me->query("env/invisibility")
		&& !me->query_temp("fanzhen")
		&& random(victim->query_skill("force")) > me->query_skill("force")/2
		&& living(victim))
		{
			damage = - damage;
			me->receive_damage( "qi", damage, victim);
			me->receive_wound( "qi", damage/3, victim);
			if (damage < 50)
				return "$N�ܵ�$n�����������ƺ�һ����\n";
			if (damage < 100)
				return "$N��$n���������𣬡��١���һ������������\n";
			if (damage < 220)
				return "$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
			return "$N��$n������һ����ǰһ�ڣ��������ɳ�������\n";
		}
	}

	// ����Ч���� added by snowman@SJ 06/02/2000
	damage += em/2+random(em/2);

	damage -= victim->query_temp("apply/armor_vs_force");

	//message("wizard", sprintf("�����˺�=%d �˺�=%d, ", em, damage), env);	
	message("wizard", sprintf("�����˺�=%d �˺�=%d, ", em, damage), env );

	if (damage < 0) damage = 0;
	else {
		my_neili = me->query_skill("force") - damage;
		if (my_neili > damage)
			my_neili = damage;
		damage = damage / 2 + random(my_neili);
	}
		     
	message("wizard", sprintf("�����˺�=%d\n", damage), env );

	return damage;
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs void do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result;
	string attack_skill, v_attack_skill, martial_skill, force_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp, em, damage, damage_bonus, brief,total,def,abs;
	int wounded = 0;
	int flag = 0;
	int skill = (me->query_skill("jingmai-xue", 1) + me->query_skill("medicine", 1)) * 3/4;
	object vweapon;
	object* env;

	if (!me || !victim || environment(me) != environment(victim))
		return;   // ��ֹ��ɽ��ţ Yuj@SJ 19990725

	if (!living(me) || me->is_busy() && !victim->is_busy() || me->query_temp("combat_yield"))
		return; // YUJ@SJ 20010523

	// ��ֹ�Ѿ�ʧȥս���������˳��� YUJ@SJ 2001-11-15
	if (me->query("qi") < 0 || me->query("jing") < 0 || me->query("jingli") < 0)
		return;

	if (me->query("eff_qi")+me->query_temp("apply/qi") < 0
	|| me->query("eff_jing")+me->query_temp("apply/jing") < 0)
		return;

	// ��Ҫ�������˷����Ѿ�Ҫ���Ի������������� YUJ@SJ 2001-11-16
	if (living(victim) && (victim->query("qi") < 0 || victim->query("jing") < 0 || victim->query("jingli") < 0))
		return;

	if (victim->query("eff_qi")+victim->query_temp("apply/qi") < 0
	|| victim->query("eff_jing")+victim->query_temp("apply/jing") < 0)
		return;
		
	env = environment(me)?filter_array(all_inventory(environment(me)),(:
		$1->query("env/combat")=="verbose"
		:)):0;
	if (!userp(me) && userp(victim) && victim->add_temp("do_attack_count", 1) > 75) {
		if (uptime() - victim->query_temp("last_attack_time") < 30) {
			tell_object(victim, BLINK "ϵͳ��⵽���ս���ٶ��쳣����ע�⣡\n" NOR);
			if (victim->add("combat_exp", -50) < 1)
				victim->delete("combat_exp");
			log_file("attack_speed",
				sprintf("%s %s\n", victim->query("id"),
					me->query("id")
				), victim
			);
		}
		victim->set_temp("last_attack_time", uptime());
		victim->delete_temp("do_attack_count");
	}
	if (userp(me) && me->query("age") > 16) {
		// jingli cost, added by snowman
		em = sizeof(me->query_enemy())+1;
		me->receive_damage("jingli", (2+random(2))*em);
			if (me->query("jingli")*100 / (me->query("eff_jingli")+me->query_temp("apply/jingli")) < 10)
				 tell_object(me, HIR "\n����������������ˣ�\n" NOR);
	}
	if (userp(victim) && living(victim)
	&& victim->query("age") > 16
	&& 3*me->query("combat_exp") >= 2*victim->query("combat_exp")) {
		victim->receive_damage("jingli", 2+random(2));
		if (victim->query("jingli")*100 / (victim->query("eff_jingli")+victim->query_temp("apply/jingli")) < 10)
			tell_object(victim, HIR "\n����������������ˣ�\n" NOR);
	}
//
	v_attack_skill = victim->query_attack_skill();
	if (me->query_temp("dzxy/bishen"))
	{
		if (attack_skill == v_attack_skill
		&& me->query_skill(attack_skill, 1) >= 300
		&& me->query_skill("douzhuan-xingyi", 1) >= 300)
			result = "\n" + victim->query("actions")["action"] + "��\n";
	}
	vweapon = victim->query_temp("weapon");
	if (me->query_skill_mapped("parry") == "douzhuan-xingyi"
	&& (!weapon && !vweapon
	|| weapon && vweapon && weapon->query("skill_type") == vweapon->query("skill_type")
	|| objectp(me->query_temp("bishen_target"))
	))
		flag = 1;

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	if (userp(me) && userp(victim))
		brief=me->query("env/brief") && victim->query("env/brief");
	else
		brief=me->query("env/brief") || victim->query("env/brief");
//
// (0) Choose skills.
//
	if (flag) {
		foo = me;
		me = victim;
	}
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);

	if ( sizeof(prepare) == 0) attack_skill = "unarmed";
	if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
	if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
	if ( weapon ) attack_skill = weapon->query("skill_type");
	if (flag && !me->query_skill_mapped(attack_skill)) {
		me = foo;
		flag = 0;
		prepare = me->query_skill_prepare();
		if (!prepare) prepare = ([]);
		if ( sizeof(prepare) == 0) attack_skill = "unarmed";
		if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
		if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
		if ( weapon ) attack_skill = weapon->query("skill_type");
	}

	//
	// (1) Find out what action the offenser will take.
	//
	me->reset_action();
	action = me->query("actions");
//      if( !mapp(action) ) {
//	    me->reset_action();
//	    action = me->query("action");
		if( !mapp(action) ) {
			CHANNEL_D->do_channel( this_object(), "err",
				sprintf("%O(%s): bad action = %O",
				me, me->query("id"), me->query("actions", 1)));
			action = me->query("default_actions");
			if (!mapp(action)) return 0;
			weapon = 0;
			attack_skill = "unarmed";
		}
//      }
	if (flag) me = foo;

	if (!me->query_temp("action_flag"))
		result = "\n" + action["action"] + "��\n";
	else
		result = "\n������"+action["action"] + "��\n";

	if( !arrayp(limbs = victim->query("limbs")) )
		limbs = ({ "����", "����", "����" });
	limb = limbs[random(sizeof(limbs))];

	message_vision(adj_msg(result, limb, weapon, action, attack_skill), me, victim);

	// added by snowman@SJ 30/12/1999
	if (me->query_temp("lost_attack") > 0) {
		me->add_temp("lost_attack", -1);
		ap = 1;
	}
	else if (me->is_lost()) ap = 1;
	else {
		// Check AP.  add acntion's attack by Ciwei@SJ
		if (flag)
			me->add_temp("apply/attack", me->query_skill("douzhuan-xingyi")/5);
		if(intp(action["attack"]))
			me->add_temp("apply/attack",action["attack"]);
		ap = skill_power(me, flag?"parry":attack_skill, SKILL_USAGE_ATTACK);
		if(intp(action["attack"]))
			me->add_temp("apply/attack",-action["attack"]);
		if (flag)
			me->add_temp("apply/attack", -me->query_skill("douzhuan-xingyi")/5);
	}

	if (ap < 1) ap = 1;
	// add by snowman@SJ 28/02/2000
	if(victim->query_temp("must_be_hit"))
		dp = 1;
	else {
		// Check DP.
		string* hand_skills = ({"dodge","parry","claw","cuff","finger","hand","strike","leg","unarmed"});
		if(userp(me))
			foreach(string add_skill in hand_skills)
			{
				if(intp(action[add_skill]))
					me->set_temp("fight/"+add_skill,action[add_skill]);
			}
/*
		if (userp(me) && intp(action["dodge"]))
			me->set_temp("fight/dodge", action["dodge"]);
		if (userp(me) && intp(action["parry"]))
			me->set_temp("fight/parry", action["parry"]);
*/
		dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);

		// �ñ����Ķ������� yuj 2001-11-15
		if (vweapon)
                  dp -= dp / 3; 

		if (victim->is_busy())
			dp = 1;

		if (dp < 1) dp = 1;
	}

	// Dodge, modified by snowman.
	if (random(ap + dp) < dp && living(victim)) {
		dodge_skill = victim->query_skill_mapped("dodge");
		if (!dodge_skill) dodge_skill = "dodge";
		if (!brief) {
			result = SKILL_D(dodge_skill)->query_dodge_msg(victim, attack_type);
			if (stringp(result))
				message_vision(adj_msg(result, limb, weapon, action, attack_skill), me, victim);
		}
		if (dp < ap && your["combat_exp"] < my["combat_exp"]*2
		//&& !userp(victim) && userp(me)
		&& userp(victim) != userp(me)
		&& random(your["jingli"]*100/(your["eff_jingli"]+1) + your["int"]) > 69 ) {
			// let npc get more exp from fight for group by augx@sj 3/25/2002
			if( !userp(victim) ) {
				if( mapp(victim->query("group")) ) GROUP_D->add_npc_exp(victim,me);
			}
			else {
				if (!random(10)) your["combat_exp"]++;
				for (foo = 15; foo <= 50; foo+=5)
					if (dp*foo < ap*10)
						victim->improve_skill("dodge", random(2));
					else break;
			}
		}
/*
		// This is for NPC only. NPC have chance to get exp when fail to hit.
		if (!userp(me) && ap < dp)
			my["combat_exp"] += my["combat_exp"]/50;
*/
		damage = RESULT_DODGE;
	} else {
		if (victim->query_temp("must_be_hit"))
			pp = 1;
		else {
			// Check PP.
			if (vweapon) {
				pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
				// ���ֶԱ������ñ������м���� yuj 2001-11-15
				if (!weapon && !victim->is_busy())
                                  pp += pp / 3; 
			} else {
				prepare = victim->query_skill_prepare();
				if (!prepare) prepare = ([]);
				if (sizeof(prepare) == 0)
					foo = "unarmed";
				if (sizeof(prepare) == 1)
					foo = (keys(prepare))[0];
				if (sizeof(prepare) == 2)
					foo = (keys(prepare))[victim->query_temp("action_flag")];
				pp = skill_power(victim, foo, SKILL_USAGE_DEFENSE);
				// �����Կ��ֵģ������мܽ��� yuj 2001-11-15
				if (weapon && !victim->is_busy())
                                  pp -= pp / 3;
			}

			// ���busyʱ���м� augx@sj 10/16/2001
			if (victim->is_busy()) {
/*
				if (weapon && !vweapon)
					pp = pp / 2 + random(pp / 2);
				else
					pp = pp * 2 / 3 + random(pp / 3);
*/
                          pp = pp / 3 + random(pp / 3);  // busyʱ�����ֱ����Ϳ��� ���ͼӳ� by lsxk@hsbbs
			}

                  
			if (pp < 1) pp = 1;
		}

		// Parry. modified by snowman
		if (random(ap + pp) < pp && living(victim)) {
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";

			if( !brief ){
				result = SKILL_D(parry_skill)->query_parry_msg(vweapon, me, attack_type);
				if (!stringp(result))
					result = SKILL_D("parry")->query_parry_msg(vweapon);
				message_vision(adj_msg(result, limb, weapon, action, attack_skill), me, victim);
			}

			if( pp < ap && your["combat_exp"] < my["combat_exp"] * 2
			//&& userp(victim) && !userp(me)
			&& userp(victim) != userp(me)
			&& random(your["jingli"]*100/(your["eff_jingli"]+1) + your["int"]) > 69 ) {
				// let npc get more exp from fight for group by augx@sj 3/25/2002
				if( !userp(victim) ) {
					if( mapp(victim->query("group")) ) GROUP_D->add_npc_exp(victim,me);
				}
				else {
					if (!random(10)) your["combat_exp"]++;
					
					for (foo = 15; foo <= 50; foo+=5)
						if (pp*foo < ap*10)
							victim->improve_skill("parry", random(2));
						else break;
				}
			}
			damage = RESULT_PARRY;
			// check weapon_cut in WEAPON_D. snowman
			if( weapon ) WEAPON_D->weapon_cut(me, victim, weapon, vweapon, damage);
		}

		// Hit! modified by snowman
		else {
			damage = me->query_temp("apply/damage");
			if (weapon)
				damage += weapon->query_weight()/2500;

                        if (damage > 2000) damage = 2000;
			damage = (damage*2/3 + random(damage/3)) / 2;
			if (action["damage"])
				damage += action["damage"] * damage / 100;
			damage += me->query_skill(flag?"parry":attack_skill) * damage / 100;
			damage_bonus = me->query_str(1);

			// different skill, different effect. snowman
			switch(attack_skill){

				case "dagger":
				case "brush":
				case "sword":   em = -damage_bonus/4; break;
				case "whip":
				case "blade":   em = -damage_bonus/5; break;
				case "staff":
				case "club":
				case "spear":
				case "claw":    em = damage_bonus/4; break;
				case "throwing":
				case "axe":
				case "hammer":
				case "hand":
           	                case "strike":
                                case "cuff":
                                case "leg":
			        case "finger":  em = damage_bonus/3; break;
				default: em = 0;
			}
			damage_bonus += em;

			// Let force skill take effect.
			if( my["jiali"] > 0 && (my["neili"] >= my["jiali"]) ) {
				my["neili"] -= my["jiali"];
				// Modify by snowman@SJ 05/12/1999
				if (!living(victim))
					damage_bonus += my["jiali"];
				else if (force_skill = me->query_skill_mapped("force"))  {
					foo = force_hit(me, victim, damage_bonus, my["jiali"], -em);
					if( stringp(foo) )
						message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
					else if( intp(foo) ) {
						if (!living(victim) && foo < 0) foo = 0;
//						if (weapon && !me->query_temp("weapon_effect_jiali"))
//							foo /= 2;
						damage_bonus += foo;
					}
				}
			}

			if( action["force"] ) {
				if (weapon) damage_bonus += action["force"] * damage_bonus / 1500;
				else damage_bonus += action["force"] * damage_bonus / 500;
			}

			if (weapon)
				damage_bonus += me->query_skill("force") * damage_bonus / 100;
			else
				damage_bonus += (me->query_skill(flag?"parry":attack_skill) + me->query_skill("force")) * damage_bonus / 100;

			// add by snowman@SJ 29/02/2000
			if( !me->query_temp("hit_skill_hit_ob")
			&& !victim->query_temp("no_skill_hit_ob")){
				if( martial_skill = me->query_skill_mapped(flag?"parry":attack_skill) ) {
					foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
					if( stringp(foo) )
						message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
					else if(intp(foo) )
						damage_bonus += foo;
				}
				// add force skill hit_ob
				if( force_skill ) {
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus);
					if( stringp(foo) )
						message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
					else if( intp(foo) )  damage_bonus += foo;
				}
			}

			// Let weapon or monster have their special damage.
			if( weapon ) {
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) )
					message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
				else if(intp(foo) ) damage += foo;
				// check weapon_cut in WEAPON_D
				WEAPON_D->weapon_cut(me, victim, weapon, vweapon, damage_bonus);
			}
			else {
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) )
					message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
				else if(intp(foo) ) damage += foo;
			}

			/*
			i moved this here, so ob_hit returns final damage after all effects. snowman 22/10/99

			6) Inflict the damage.
			*/
			if (!victim)	// damn wd job npc, YUJ@SJ 2001-12-21
				return;
			
			message("wizard",sprintf( GRN "STR,CON ����Ӱ�����ǰ��Damage=%d,",damage_bonus),env );
			
			damage_bonus = damage_bonus * ( my["str"]+me->query_str() ) / ( my["str"]+me->query_str() + your["con"] + victim->query_con() ) ;
			
			message("wizard",sprintf( GRN "������Damage=%d��\n",damage_bonus),env );
						
			if( damage_bonus > 0 ) damage += (damage_bonus + random(damage_bonus))/2;
			if( damage_bonus < 0 ) damage += (damage_bonus - random(-damage_bonus))/2;			
			if( damage < 0 ) damage = 0;

			if (living(victim)) {
				int defense_factor = dp + pp;

				while (defense_factor > ap / 3) {
					damage -= damage / 5;
					defense_factor /= 2;
				}
			}

			if (attack_type == TYPE_BUSY) damage /= 2;
			if (attack_type == TYPE_QUICK) damage = damage/2 + random(damage/2);
             
     //update by lsxk@hsbbs �з�����ң�����Ƚ���super����.  2007/10/29
                  if (attack_type == TYPE_SUPER){
                      if(!userp(me) || !userp(victim)) damage *= 2;
                      else damage *= 1;
                  }
                  if(userp(me) && userp(victim)) damage = damage*2/3; //�ٴ��������PVPʱ�Ĺ����� by lsxk@hsbbs 2007/10/29
			if (!living(victim)) damage *= 6; // hehehehehehe....
			
			 if (!weapon && vweapon)
			 	   damage = to_int(damage * (me->query_str(1) / 5.0 + 16) / (victim->query_con(1) / 4.0 + 15));
			else damage = to_int(damage * (me->query_str(1) / 5.0 + 16) / (victim->query_dex(1) / 4.0 + 15));
              
			// by snowman, added living check to victim for dodge, parry and force.
			// by augx@sj, when busy let force and parry still have ob_hit
			if(living(victim)
			&& !me->query_temp("hit_ob_hit")
			&& !victim->query_temp("no_hit_ob_hit")
			&& damage > 0){
				em = 0;
			  	if(!victim->is_busy()) {
					if( martial_skill = victim->query_skill_mapped("dodge") ) {
						foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage);
						if( stringp(foo) )
							message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
						else if (foo) damage += foo;
						else em = 1;
					}
				}
				else em = 1;

				if( (martial_skill = victim->query_skill_mapped("parry")) && em == 1) {
					foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage);
					if( stringp(foo) )
						message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
					else if (foo) damage += foo;
					else em = 2;
				}

				if( (martial_skill = victim->query_skill_mapped("force")) ) {
					foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage);
					if( stringp(foo) )
						message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
					else if(intp(foo) ) damage += foo;
				}
			}

			// add by augx@sj , let armor and cloth have ob_hit effect
			if ( foo = victim->query_temp("armor/armor") ) {
				foo = foo->ob_hit(me, victim, damage);
				if( stringp(foo) )
					message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
				else if(intp(foo) ) damage += foo;
			}
			if ( foo = victim->query_temp("armor/coat") ) {
				foo = foo->ob_hit(me, victim, damage);
				if( stringp(foo) )
					message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
				else if(intp(foo) ) damage += foo;
			}
			if ( foo = victim->query_temp("armor/cloth") ) {
				foo = foo->ob_hit(me, victim, damage);
				if( stringp(foo) )
					message_vision(adj_msg(foo, limb, weapon, action, attack_skill), me, victim);
				else if(intp(foo) ) damage += foo;
			}

			// add by augx@sj , let armor will be broken and let it have poison effect
			CLOTH_D->armor_cut(me , victim , weapon , damage);

									
			//Damage �����ƻ�
			damage = last_damage(me,victim,damage);
if( userp(me)
 &&random(me->query("con")) > random(victim->query("dex"))
 &&random(me->query("pur")) > random(victim->query("kar"))
 &&( random(me->query("int")) > random(victim->query_per()) ||  random(me->query_per()) >random(victim->query("int")) ) 
 && !random(6))
{
         damage *= 5+random(5);
if((int)me->query("eff_qi") < me->query("max_qi")/2 )  
  damage *= 2;
  message_vision(HIY"$N����������ͨ����ս�⼤�����������أ��̲�ס������Ц��һ�мȳ����������ǵ��޿ɵ���\n"NOR, me,victim);
}
						
			if (damage <= 0) damage = 0;
			else victim->receive_damage("qi", damage, me );

			if (
				damage > victim->query_temp("apply/armor") * 2
				&& (
					(
						me->is_killing(your["id"])
						&& (
							(!weapon && !random(4))
							|| (weapon && !random(2))
						)
					)
					|| (
						(!weapon && !random(8))
						|| (weapon && !random(4))
					)
				)
			) {

				victim->receive_wound("qi", damage - victim->query_temp("apply/armor") * 2 , me);

								
				// ��ֹ���������Ϣ YUJ@SJ 2001-11-18
				if (victim->query("qi") >= 0 || victim->query("eff_qi")+victim->query_temp("apply/qi") < 0)
					wounded = 1;
			}

			result = damage_msg(damage, action["damage_type"]);
			message_vision(adj_msg(result, limb, weapon, action, attack_skill), me, victim);

			if( userp(me) != userp(victim) ) {
				if (living(me))
				if( (ap < dp || ap < pp)
				&& (random(my["jingli"]*100/(my["eff_jingli"]+1) + my["int"]) > 69) ) {
					if( !userp(me) ) {
						if( mapp(me->query("group")) ) GROUP_D->add_npc_exp(me,victim);
					}
					else {
						if (!random(10)) my["combat_exp"]++;
						if( my["potential"] < my["max_pot"] ) my["potential"]++;
//                                                if (userp(me)) me->improve_skill(flag?"parry":attack_skill, 1);
					}
				}
				if (living(victim))
				if( (ap > dp || ap > pp )
				&& (random(your["jingli"]*100/(your["eff_jingli"]+1) + your["int"]) > 69) ) {
					if (!random(10)) your["combat_exp"]++;
					if( your["potential"] < your["max_pot"] ) your["potential"]++;
				}
			}
		}
	}

	if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
		if( damage > 0 )
			tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR, ap/100, dp/100, pp/100, damage) );
		else    tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d\n" NOR, ap/100, dp/100, pp/100));
	}

	if( wizardp(victim) && (string)victim->query("env/combat")=="verbose" ) {
		if( damage > 0 )
			tell_object(victim, sprintf( GRN "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR, ap/100, dp/100, pp/100, damage));
		else    tell_object(victim, sprintf( GRN "AP��%d��DP��%d��PP��%d\n" NOR, ap/100, dp/100, pp/100));
	}


	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);

	if( damage > 0 ) {
		report_status(victim, wounded);
		if( victim->is_busy() ) {
			   if((int)victim->query("relife/gifts/total") > 0 && random(240)<(int)victim->query("relife/gifts/total",1) )
			  { message_vision(HIW"$N�ж�΢�����ƣ���æĬ���������ƿ�������ҪѨ��\n"NOR,victim);
              if(!random(4)) victim->start_busy(-1);
              	else victim->add_busy(-1);
             }
			victim->interrupt_me(me);
		    }	


  if( victim->query_condition("no_exert") ){
             
                                 if((int)victim->query("relife/gifts/total") > 0 && random(240)<(int)victim->query("relife/gifts/total",1)  || (victim->query_skill("jiuyang-shengong",1) >=450 && random(2))  )
                                  {
                    if( victim->query_skill("jiuyang-shengong",1) >=450 )   
                    	              message_vision(HIY"$N�������񹦾����������ε���񣬾���������һ��ת���漴ƽ����\n"NOR,victim);
                                   message_vision(HIY"$NĬ��������ѹ���˷��ڲ��ѵ���Ѫ��\n"NOR,victim);
                                   victim->clear_condition("no_exert");                                       }
           }


 if( victim->query_condition("no_force") ){
              if((int)victim->query("relife/gifts/total") > 0 && random(240)<(int)victim->query("relife/gifts/total",1) ||  (victim->query_skill("jiuyang-shengong",1) >=450 && random(2))  ){
	 if( victim->query_skill("jiuyang-shengong",1) >=450 )     message_vision(HIY"$N�������񹦾����������ε���񣬾���������һ��ת���漴ƽ����\n"NOR,victim);
		               message_vision(HIC"$N�����Լ���Ϣ���ȣ���æĬ��������������Ϣ��\n"NOR,victim);
                               victim->clear_condition("no_force");}
           }
           
if( victim->query_condition("no_perform") ){
              if((int)victim->query("relife/gifts/total") > 0 && random(320)<(int)victim->query("relife/gifts/total",1) )
			{
               message_vision(HIC"$N�����Լ���ʽ���ͣ���æ���У���ʽ��ʱ����������\n"NOR,victim);
               victim->clear_condition("no_perform");
           }
}






            def = victim->query_temp("apply/armor");
      total = damage;
            abs = total * def /(1000+def);
      damage = damage * 1000/(1000+ def);
      
      if(userp(me) && me->query("env/damage"))      tell_object(me,WHT"���"+ victim->query("name") +"�����"RED+ damage+ WHT"�㹥���˺�(�ܼ�"RED+ total +WHT"������"RED + abs + WHT")��\n"NOR);    
      if(userp(victim)&& victim->query("env/damage"))      tell_object(victim,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺�(�ܼ�"RED+ total +WHT"������"RED + abs + WHT")��\n"NOR);    //-------------------------------------------------------------
		    
		    
		    
		if( !me->is_killing(your["id"])
		&& !victim->is_killing(my["id"])
		&& victim->query("qi")*2 <= victim->query("max_qi"))
			end_fight(me, victim);


          if((int)me->query("relife/gifts/total") > 0
             &&living(victim)
             && !me->is_busying()
             && random(240)<(int)me->query("relife/gifts/total",1) && random(10) > 6 ){
                  message_vision(HIR"$N���Լ����򵽵���ѧ��΢֮�����ӳ��������Ƹ���������\n"NOR,me,victim);
                  do_attack(me, victim, weapon, 3);
          }
/*
          else if(me->query_temp("hjdf/ldj/attack_chance")
             &&living(victim)
             && !me->is_busying()
             && random(20)==1 ){
                  message_vision(HIW"$N��׼��ʱ����$n����֮ʱ�����������������������ϣ�һ�󼲹���ֱ���$n��æ���ң�\n"NOR,me,victim);
                  me->delete_temp("hjdf/ldj/attack_chance");
                  me->set_temp("hjdf/ldj/color","color");
                  do_attack(me, victim, weapon, 3);
                  for (;random(4);)
                    do_attack(me, victim, weapon, 3);
                  me->delete_temp("hjdf/ldj/color");
          }
   */
          if(me->query_temp("hjdf/ldj/attack_chance")) me->delete_temp("hjdf/ldj/attack_chance");
	}

	// See if the victim can make a riposte.
	if( attack_type == TYPE_REGULAR
	&& damage < 1 && victim->query_temp("guarding") ) {
		victim->delete_temp("guarding");
		if( random(my["int"]) < 5 ) {//dex -> int 
			message_vision("$Nһ�����У���ʧɫ������¶����������\n", me);
			do_attack(victim, me, vweapon, TYPE_QUICK);
		} else {
			message_vision("$Nһ��$n����ʧ�󣬶�ʱ�û�����������\n", victim, me);
			do_attack(victim, me, vweapon, TYPE_RIPOSTE);
		}
	}

}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
	object weapon = me->query_temp("weapon");
	string d_skill;
	int double_attack = 0;

	if (!living(me) || me->query_temp("combat_yield")) return;
	if (me->query_temp("no_fight")) return;

	if (!me->is_killing(victim->query("id"))
	&& member_array(me, victim->query_enemy()) > 4) return;

	//
	// int double_attack(object me) in skill file for double_attack.
	// by snowman@SJ 16/03/99
	//

	if (weapon)
		d_skill = me->query_skill_mapped(weapon->query("skill_type"));

	else if (sizeof(me->query_skill_prepare()) == 1)
		d_skill = me->query_skill_mapped(keys(me->query_skill_prepare())[0]);

	if( stringp( d_skill ) )
		double_attack = SKILL_D(d_skill)->double_attack(me);

// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() || !living(victim) ) {
		me->delete_temp("guarding");
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, weapon, TYPE_BUSY);

		if (me->is_fighting(victim) && victim->is_fighting(me))
//			if((!weapon && sizeof(me->query_skill_prepare()) > 1)
			if(            sizeof(me->query_skill_prepare()) > 1
			|| double_attack
//			|| (me->query("double_attack") && !me->query_temp("weapon"))
			||  me->query("double_attack") 
			|| me->query_temp("double_attack")) {
				if (me->query("double_attack") && sizeof(me->query_skill_prepare()) < 2)
                                        message_vision(HIR"\n$N˫�ַ�ʹ������쳣�����������������Ƶģ�\n"NOR,me);
				me->set_temp("action_flag",1);
				do_attack(me, victim, weapon, TYPE_QUICK);
				me->delete_temp("action_flag");
			}
	} else if (me->query_temp("guarding")
	|| me->query_dex() > random(victim->query_dex()*3/2)) {
		me->delete_temp("guarding");
		if (!victim->is_fighting(me)) victim->fight_ob(me);
		if (!victim->is_fighting() && !victim->query_temp("must_be_hit")
		&& me->query("startroom") != base_name(environment(me))) {
			victim->set_temp("must_be_hit",1);
			do_attack(me, victim, weapon, TYPE_SUPER);
			victim->delete_temp("must_be_hit");
		} else do_attack(me, victim, weapon, TYPE_REGULAR);

		if( me->is_fighting(victim) && victim->is_fighting(me))
//			if( (!weapon && sizeof(me->query_skill_prepare()) > 1)
			if(             sizeof(me->query_skill_prepare()) > 1
			|| double_attack
//			|| (me->query("double_attack") && !me->query_temp("weapon"))
			||  me->query("double_attack")
			|| me->query_temp("double_attack")) {
				if (me->query("double_attack") && sizeof(me->query_skill_prepare()) < 2)
                                        message_vision(HIR"\n$N˫�ַ�ʹ������쳣�����������������Ƶģ�\n"NOR,me);
				me->set_temp("action_flag",1);
				do_attack(me, victim, weapon, TYPE_REGULAR);
				me->delete_temp("action_flag");
			}

		// Else, we just start guarding.
	} else {
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
	}
}

//      auto_fight()

void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "hunting", 1, me, obj, type);
}
void special_kill(object me, object obj)
{			
	if (me->query_temp("living") && obj->query_temp("living"))
	{
		if (me->query_temp("xyjob/xy_defend") && obj->query_temp("xyjob/mg_attack"))
		{
			me->kill_ob(obj);
			return;
		}
		if (me->query_temp("xyjob/mg_attack") && obj->query_temp("xyjob/xy_defend"))
		{
			me->kill_ob(obj);
			return;
		}
		if (!me->query_temp("gmdjob/biwu") && !obj->query_temp("gmdjob/biwu"))
		{
			if (me->query_temp("gmdjob/mj_defend") && obj->query_temp("gmdjob/wg_attack"))
			{
				me->kill_ob(obj);
				return;
			}
			if (me->query_temp("gmdjob/wg_attack") && obj->query_temp("gmdjob/mj_defend"))
			{
				me->kill_ob(obj);
				return;
			}
		}
	}
}

void start_hatred(object me, object obj)
{
	if ( !me || !obj ) return;

	if (  environment(me) == environment(obj))  return;

	tell_object(me, HIW "�����Զ��"+obj->name()+"�ı�Ӱ�е����´α����ҿ����㣡\n" NOR);
	tell_room(environment(me), HIW+me->name()+"����Զ��"+obj->name()+"�ı�Ӱ�е����´α����ҿ����㣡\n" NOR, ({me}));
	tell_object(obj, HIW+me->name()+"��Զ������е����´α����ҿ����㣡\n" NOR);
	tell_room(environment(obj), HIW+me->name()+"��Զ����"+obj->name()+"�е����´α����ҿ����㣡\n" NOR, ({obj}));
}

void hunting(object me, object obj, string type)
{
	int shen;
	string str;
	object env;

	if( !me || !obj ) return;

	me->delete_temp("looking_for_trouble");

	env = environment(me);
	if ((me->is_killing(obj->query("id")) && me->is_fighting(obj))
	|| !living(me)
	|| env->query("sleep_room")
	|| env->query("no_fight") )
		return;

	if (env != environment(obj)) {
		if ( type == "hatred" && me->query("race") == "����" && random(4) == 2)
			me->start_call_out( (: call_other, __FILE__, "start_hatred", me, obj :), 1);
		return;
	}

	switch(type){
		case "aggressive":
			me->kill_ob(obj);
			break;
		case "vendetta":
			if (me->query("combat_exp") < obj->query("combat_exp") / 2
			|| me->query("eff_qi") < me->query("max_qi")/2) return;
			message_vision(HIW "$N��$n�ȵ���"+RANK_D->query_rude(obj)+"�����ҶԱ��ŵ����¶��֣������ɣ�\n" NOR, me, obj);
			me->kill_ob(obj);
			break;
		case "hatred":
			switch(me->query("race")) {
				case "����":
				case "Ұ��":
					message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
					break;
				case "����":
					message_vision( catch_hunt_bird_msg[random(sizeof(catch_hunt_bird_msg))], me, obj);
					break;
				default:
					message_vision( catch_hunt_human_msg[random(sizeof(catch_hunt_human_msg))], me, obj);
			}
			me->kill_ob(obj);
			break;
		case "berserk":
			if (me->query("no_pk") || obj->query("no_pk")) return;
			shen = -me->query("shen");
			message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

			if (wiz_level(me) || !userp(me) || wiz_level(obj)
			|| me->query("neili") > (random(shen) + shen)/20 ) return;

			me->set_temp("other_kill/"+obj->query("id"), 1);
			if (shen/2 > random(me->query("combat_exp"))
			&& !wizardp(obj) ) {
				str = RANK_D->query_self_rude(me)+ "����ʵ�ںܲ�˳�ۣ�ȥ����";
				if(stringp(me->query("env/shen_kill")) && strlen(me->query("env/shen_kill")) < 30 )
					str = me->query("env/shen_kill");
				message_vision(CYN"$N����$n�ȵ���"+str+"��\n"NOR, me, obj);
				me->kill_ob(obj);
			} else {
				message_vision(CYN"$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)+ "��"
				+ RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n"NOR,me, obj);
				me->fight_ob(obj);
			}
	}
}


void killer_reward(mixed killer, object victim)
{
	string vmark, str;
	int times, exp, gfight=0;
	int wanted_time = 0;
	int oldpks = 0;
	object env;
	
	if(objectp(killer)) oldpks = killer->query("PKS",1);
					
	// Call the mudlib killer apply.
	if (objectp(killer)) killer->killed_enemy(victim);

	if (objectp(killer) && userp(killer) && victim->query("race") == "����") {
		if (victim->query("combat_exp") < killer->query("combat_exp"))
			killer->add("reputation", (victim->query("combat_exp") - killer->query("combat_exp")) / 100);
		else killer->add("reputation", (victim->query("combat_exp") - killer->query("combat_exp")) / 10);
		if ( (!victim->query_temp("faint_by") || victim->query_temp("faint_by") == killer)
		&& killer->query("combat_exp") < victim->query("combat_exp")
		&& killer->query("combat_exp") > victim->query("combat_exp")/4)
			killer->add("shen", -(int)victim->query("shen") / 10);
	}

	if (userp(victim)) {
		mixed muderer = victim->query_temp("faint_by");
		int multi = objectp(muderer) && userp(muderer)
	// ͬı�������������Ǹ��𣬲����Ǳ��Է��������Ƕ�����ͬı
        // ����ֱ�Ӹĳ��ж��ǲ��Ƕ��˹������ˡ����ܸ��𲻸���ֻҪ�Ǳ�������������������ML
        // 		&& !muderer->query("revenge/"+victim->query("id"))
			&& !victim->query_temp("kill_other/"+muderer->query("id"))
			&& !muderer->query_temp("other_kill/"+victim->query("id"))
			&& muderer != killer;

if(!objectp(muderer)) muderer = killer;
		gfight = GROUP_D->is_group_fight(victim);
		env = environment(victim);

		victim->add("death_count", 1);
		if (victim->query("combat_exp") >= 10000 * victim->query("death_times"))
			if( gfight != 1 ) victim->add("death_times", 1);
		victim->delete("vendetta");
		victim->set("thief", victim->query("thief") / 2);

		// give winner group reward
		if( gfight == 1 ) {
			exp = victim->query("combat_exp");
			if( exp > 10000000 ) exp = 10000000 + (exp-10000000)/2;
			if( exp >  7000000 ) exp =  7000000 + (exp- 7000000)/2;
			if( exp >  3500000 ) exp =  3500000 + (exp- 3500000)/2;
			GROUP_D->add_war_score( GROUP_D->query_enemy(GROUP_D->query_league(victim->query("group/id"))), exp/125000 );
		}

		// Give the death penalty to the dying user.
		if (victim->query_condition("pk")) wanted_time = victim->query_condition("killer");
		times = (wanted_time - 61) / 30;
		if (times < 0) times = 0;
		do {
			//��ͨ��ҵ���1%
			if (victim->query("registered") < 3) {
				exp = victim->query("combat_exp") / 100;
				}
      //�¿���ҵ���0.9%
			if (victim->query("registered") == 3) {
				exp = victim->query("combat_exp")* 90 / 10000;
			}
      //�꿨��ҵ���0.8%  
      if (victim->query("y-card-vip")) {
				exp = victim->query("combat_exp")* 80 / 10000;
			}
			//����vip����0.75%,����Ϊ200k
			if (victim->query("buyvip") || victim->query("rmb_used")>=500 ) {
				exp = victim->query("combat_exp")* 75 / 10000;
				if ( exp > 200000 ) exp = 200000;
			}
		
		else {
				exp = victim->query("combat_exp") * 75/ 10000;
				if ( exp > 200000 ) exp = 200000;
			}



			if (exp < 150) exp = 0;
			if (gfight == 1) exp /= 3;
			victim->add("shen", -victim->query("shen") / 10);
			victim->add("combat_exp", -exp);
			victim->set("death_lost_exp", exp);
			victim->add("potential", -victim->query("potential") / 4);
			
                         if(!victim->query("buyvip") && !victim->query("y-card-vip") )   victim->skill_death_penalty((gfight==1)?4:2); 
		} while (times--);

		if (multi) {
			muderer->add("PKS", 1);	// ͬı��
			muderer->set("last_pk_time", muderer->query("pk_time"));
			muderer->set("pk_time", time());
		}
if (objectp(killer)) {
			killer->add("PKS", 1);
			killer->set("last_pk_time", killer->query("pk_time"));
			killer->set("pk_time", time());

			if (killer->query("combat_exp") < victim->query("combat_exp"))
				victim->add("reputation", (killer->query("combat_exp") - victim->query("combat_exp")) / 20);

			victim->delete("last_kzf");
//����
if (wanted_time && userp(killer) && (killer->query_temp("kill_other/"+victim->query("id"))
			|| !victim->query_temp("kill_other/"+killer->query("id"))
			&& !killer->query_temp("other_kill/"+victim->query("id"))))
                        {
				if (multi) {
					str = sprintf("��%s��%s�͵������ˡ�", muderer->name(), killer->name());
					muderer->add("PKS", -1);	// ��æ�������� PK
					muderer->set("pk_time", muderer->query("last_pk_time"));
				} else str = sprintf("��%s�͵������ˡ�",  killer->name());
				victim->set("last_kzf", killer->query("id"));
			} 

else {
				if (!stringp(vmark = killer->query("kill_mark")))
					vmark = "ɱ";
				if (userp(killer)) {
					gfight = GROUP_D->is_group_fight(killer);
					if (gfight == 1) {
						if (multi) {
							muderer->add("PKS", -1);
							muderer->set("pk_time", muderer->query("last_pk_time"));
						            }
						killer->add("PKS", -1);	
						killer->set("pk_time", killer->query("last_pk_time"));
					                  }
//����ɱ���߾��޸����ǵ��������ɱ��
        if (killer->query_temp("kill_other/"+victim->query("id"))
	 && !killer->query("revenge/"+victim->query("id")) && !muderer->query("revenge/"+victim->query("id")) ) 
                        {
						if (multi)
			 				str = sprintf("��%s��%s%s���ˡ�", muderer->name(), killer->name(), vmark);
						   else str = sprintf("��%s%s���ˡ�", killer->name(), vmark);

						if (gfight != 1 && objectp(env) && strsrch(file_name(env), "/cmds/leitai/bwdh") != 0 ) {
							if (multi){
								muderer->add_condition("killer", 90);
								muderer->apply_condition("pk", 1);
							           }
							killer->add_condition("killer", 90);
							killer->apply_condition("pk", 1);
			                                            }

						if (multi) {
							victim->set("last_death_time/"+muderer->query("id"),
								time() + (victim->query("combat_exp") < 20000 ? 86400 : 0));
							victim->set("revenge/"+muderer->query("id"), 1);
						            }
						victim->set("last_death_time/"+killer->query("id"),
							time() + (victim->query("combat_exp") < 20000 ? 86400 : 0));
						victim->set("revenge/"+killer->query("id"), 1);

						if (multi && muderer->query("prepare_retire"))
							"/cmds/std/retire"->abandon(muderer);
						if (killer->query("prepare_retire"))
							"/cmds/std/retire"->abandon(killer);
			}
//��������
       else if (victim->query_temp("kill_other/"+killer->query("id"))
	    || killer->query_temp("other_kill/"+victim->query("id"))) {
						str = sprintf("��%s��������%s���ˡ�",  killer->name(), vmark);
						if (gfight != 1) {	// ���������
							if (multi) {
								muderer->add("PKS", -1);
								muderer->set("pk_time", muderer->query("last_pk_time"));
							}
							killer->add("PKS", -1);	
							killer->set("pk_time", killer->query("last_pk_time"));
						}
                                                killer->add("FKS", 1);
                                                victim->delete_temp("kill_other");
                                                killer->delete_temp("other_kill/"+victim->query("id"));
                                                victim->delete_temp("other_kill");
						victim->set("last_kzf", killer->query("id"));
					} 

//ɱ�˻��ߴ������һһ�������и�����
else if(  killer->query("revenge/"+victim->query("id"))  || muderer->query("revenge/"+victim->query("id")) ) {
	if(multi) {
		if(!muderer->query("revenge/"+victim->query("id")) ) //mudererô�и��������ܳͷ�
			 {				muderer->set("pk_time", muderer->query("last_pk_time"));
			 						muderer->add_condition("killer", 90);
					              muderer->apply_condition("pk", 1);
					             victim->set("revenge/"+muderer->query("id"), 1);
					            }

	       if(!killer->query("revenge/"+victim->query("id")) ) //killerô�и��������ܳͷ� 
		 {				
                             killer->set("pk_time",killer->query("last_pk_time"));
			        killer->add_condition("killer", 90);
			     killer->apply_condition("pk", 1);
			     victim->set("revenge/"+killer->query("id"), 1);
					            }

	 if(muderer->query("revenge/"+victim->query("id")))  muderer->add("PKS", -1);	
	 if(killer->query("revenge/"+victim->query("id")))             killer->add("PKS", -1);	
						  str = sprintf("��%s��%s�İ�æ�¸���%s���ˡ�", killer->name(),muderer->name(),vmark);

	
		}			  
							  
				
                    else {
                    	   killer->add("PKS", -1);	
                    	str = sprintf("��%s����%s���ˡ�", killer->name(), vmark);
    			            }
    						victim->set("last_kzf", killer->query("id"));
                                            
					} 



else {
						if (multi)
							str = sprintf("��%s��%sʧ��%s���ˡ�", muderer->name(), killer->name(), vmark);
						else str = sprintf("��%sʧ��%s���ˡ�", killer->name(), vmark);
						if (gfight!=1 && objectp(env) && strsrch(file_name(env), "/cmds/leitai/bwdh") != 0 ) {
							if (multi){
								muderer->add_condition("killer", 90);
								muderer->apply_condition("pk", 1);
							}
							killer->add_condition("killer", 90);
							killer->apply_condition("pk", 1);
						}

						if (multi) {
							victim->set("last_death_time/"+muderer->query("id"),
								time() + (victim->query("combat_exp") < 20000 ? 86400 : 0));
							victim->set("revenge/"+muderer->query("id"), 1);
						}
						victim->set("last_death_time/"+killer->query("id"),
							time() + (victim->query("combat_exp") < 20000 ? 86400 : 0));
						victim->set("revenge/"+killer->query("id"), 1);

						if (multi && muderer->query("prepare_retire"))
							"/cmds/std/retire"->abandon(muderer);
						if (killer->query("prepare_retire"))
							"/cmds/std/retire"->abandon(killer);
					}
				} else {	// �� NPC ɱ��
					if(!stringp(vmark = killer->query("kill_mark")) )
						switch(killer->query("race")) {
							case "����": vmark = "��"; break;
							case "Ұ��": vmark = "ҧ"; break;
							case "����": vmark = "��"; break;
							case "����": vmark = "��"; break;
							default: vmark = "ɱ";
						}
					str = "";
					if (!wanted_time && multi) {	// ͨ��������
                                  if (muderer->query_temp("kill_other/"+victim->query("id"))) vmark = "����";
						else vmark = "����";

						if (gfight != 1 && objectp(env) && strsrch(file_name(env), "/cmds/leitai/bwdh") != 0 ){
							muderer->add_condition("killer", 90);
							muderer->apply_condition("pk", 1);							
						}
						victim->set("last_death_time/"+muderer->query("id"),
							time() + (victim->query("combat_exp") < 20000 ? 86400 : 0));
						victim->set("revenge/"+muderer->query("id"), 1);

						if (muderer->query("prepare_retire"))
							"/cmds/std/retire"->abandon(muderer);

						str += sprintf("�⵽%s%s��", muderer->name(), vmark);
					}
					str += sprintf("��%s%s���ˡ�", killer->name(), vmark);
				}
			}
			if (multi)
                                CHANNEL_D->do_channel(this_object(), "rumor", "�����ǣ�"+muderer->short(1)+"��"+killer->short(1));
                        else CHANNEL_D->do_channel(this_object(), "rumor", "�����ǣ�"+killer->short(1));
		} else {
			str = "";
			if (!wanted_time && multi) {	// ͨ��������
				gfight = GROUP_D->is_group_fight(muderer);
				if (gfight == 1) {
					muderer->add("PKS", -1);
					muderer->set("pk_time", muderer->query("last_pk_time"));
				}

				if (muderer->query_temp("kill_other/"+victim->query("id"))) vmark = "";
				else vmark = "ʧ��";

				if (gfight != 1 && objectp(env) && strsrch(file_name(env), "/cmds/leitai/bwdh") != 0 ){
					muderer->apply_condition("pk", 1);
					muderer->add_condition("killer", 90);
				}

				victim->set("last_death_time/"+muderer->query("id"),
					time() + (victim->query("combat_exp") < 20000 ? 86400 : 0));
				victim->set("revenge/"+muderer->query("id"), 1);

				if (muderer->query("prepare_retire"))
					"/cmds/std/retire"->abandon(muderer);

				str += sprintf("��%s%s��裬", muderer->name(), vmark);
                                CHANNEL_D->do_channel(this_object(), "sys", "�����ǣ�"+muderer->short(1));
			}
			if (killer[<2..<1] != "��") str += sprintf("%s���ˡ�", killer);
			else str += killer;
		}
		victim->delete_temp("kill_other");
		victim->delete_temp("other_kill");
		if (multi) {
			muderer->delete_temp("kill_other/"+victim->query("id"));
			muderer->delete_temp("other_kill/"+victim->query("id"));
		   muderer->delete("revenge/"+victim->query("id"));
		}
		if (objectp(killer)) {
			killer->delete_temp("kill_other/"+victim->query("id"));
			killer->delete_temp("other_kill/"+victim->query("id"));
			killer->delete("revenge/"+victim->query("id"));
		}

		if (gfight == 1)
			CHANNEL_D->do_channel(this_object(), "rumor", "�ڰ��������У�"+victim->query("name")+str);
		else
			CHANNEL_D->do_channel(this_object(), "rumor", victim->query("name")+str);
		victim->set("last_death", str);
		if (wanted_time)
			CHANNEL_D->do_channel(this_object(), "rumor",
				"��ʱ��ͨ��ȡ������"+chinese_number((wanted_time+5)/6)+"��ʱ����");
		if (objectp(killer)) {
			str = killer->name();
			if (str == killer->query("name"))
				str += "("+capitalize(killer->query("id"))+")";
			victim->set("last_killer", str);
		} else victim->set("last_killer", "����");
		log_file("PLAYER_DIE",
			sprintf("%s(%s)%s[%d]{%s}\n",
				victim->query("name"),
				capitalize(victim->query("id")),
				victim->query("last_death"),
				victim->query("combat_exp"),
				objectp(killer)?killer->query("id"):"����"
			),
			victim, multi ? ({ muderer, killer }) : ({ killer })
		);
		
		// add GPKS & BPKS
		if(objectp(killer) && killer->query("PKS",1) > oldpks )
		{
			if (victim->query("shen") >= 0) killer->add("GPKS", 1); // killed a good guy.
			else killer->add("BPKS", 1); // killed a bad one.
		}
	} else if (objectp(killer) && victim->query("race") == "����") {
		killer->add("MKS", 1);
		if (victim->query("shen") >= 0) killer->add("GKS", 1); // killed a good guy.
		else killer->add("BKS", 1); // killed a bad one.				
	}
	
	if (stringp(vmark = victim->query("vendetta_mark")))
		if (objectp(killer)) killer->add("vendetta/" + vmark, 1);
}


int last_damage(object me,object victim,int damage)
{
	if (!me || !victim) return 0;
	
	if(!userp(me) && userp(victim)){
		//npc attack player 
		//�˺������80�� linux 050722
		damage = damage /5 ;
		damage = damage *4 ;
		
		if(victim->query_condition("job_busy"))
		{
		damage = damage /5 ;
		damage = damage *4 ;
			if(victim->query("combat_exp")<25000000)
			{
		damage = damage /5 ;
		damage = damage *4 ;
			}
			if(victim->query("combat_exp")<15000000)
			{
		damage = damage /5 ;
		damage = damage *4 ;
			}
			if(victim->query("combat_exp")< 5000000)
			{
		damage = damage /5 ;
		damage = damage *4 ;
			}
		}
	}
	
	//��������һ�����PVP��ս���˺���һ�����˲��Ǻ����顣
	
	if(userp(me))
	{
//pvp
		if(userp(victim))                                      
		{       if(me->query("combat_exp") < 5000000)  
                           damage = damage / 3; 
		        else damage = damage * 2 / 5;
                     }
//��Ҷ�NPC 
		else damage = damage * 4 / 5;
			                                
		}

	return damage;
}
