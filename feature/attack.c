// attack.c
// Modified by augx@sj 3/15/2002

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>
#include <pktime.h>

#define MAX_OPPONENT 4

nosave object *enemy = ({});
nosave string *killer = ({});

// prototypes

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if (query_temp("combat_yield"))
		return 0;
	enemy -= ({ 0 });
	if (!objectp(ob))
		return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	object me = this_object();

	if (!ob || ob==me)
		return;

	if (wizardp(me) && query("env/no_fight"))
		return;

	if ( userp(me) 
	 && userp(ob) 
	 && !ob->query_condition("killer")
	 && !me->query_condition("killer")
      	 && (me->query("no_pk") || ob->query("no_pk"))
      	 && (me->query("combat_exp")<2000000 || ob->query("combat_exp")<2000000)
        && (!me->query_temp("xyjob") || !ob->query_temp("xyjob"))
	 && (!me->query("env/fight_player") || !ob->query("env/fight_player"))) {
		message_vision("$N�Ѿ�����ϴ�֣��˳��������������������ˡ�\n", (me->query("no_pk")?me:ob) );
		return;
	}

	if ( !me->query_condition("pk") && pktime_limit(me, ob)) {
		tell_object(me, "�������ֻ���ڹ涨�����ڽ���ս����Ϊ��\n");
		return;
	}//killer -> pk by Ciwei@SJ

	set_heart_beat(1);

	if (!living(me) || !present(ob, environment()))
		return;

	if ((!userp(me) || !userp(ob))
	&& (environment(me)->query("no_fight") || environment(me)->query("sleep_room")))
		return;

	if( member_array(ob, enemy)==-1 )
		enemy += ({ ob });

	//added by snowman
	if (query_temp("last_lost_to"))
		delete_temp("last_lost_to");
}

// added by snowman@SJ 15/10/2000
// ������һ����ɱͬһ�������Ρ�
int can_kill_ob(object me, object ob)
{
	int i;

	if (!userp(me))
		return 1;
	if (ob->query_condition("pk"))//killer -> pk by Ciwei@SJ
		return 1;
	i = ob->query("last_death_time/"+ me->query("id"));
	if (i + 86400 > time())
		return 0;
	return 1;
}
int can_kill_user(object ob) // By Spiderii@ty
{
	if (userp(ob)

        && (query_temp("living") || ob->query_temp("living")))
        	return 0;
        return 1;
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	object *inv, me = this_object();
	string uid, mid;
	int i;

	if (!objectp(ob))
		return 0;

	if (!living(me) || !present(ob, environment()))
		return;

	if (wizardp(me) && query("env/no_fight"))
		return;

	mid = query("id");
	uid = ob->query("id");
       //��������
       if (userp(me)
	&& userp(ob)
   && (!me->query_temp("special_die") || !ob->query_temp("special_die")))
	{

	//if (userp(me) && userp(ob)) {
		if (ob->query_temp("kill_other/"+mid)) {
			ob->delete_temp("other_kill/"+mid);
			set_temp("other_kill/"+uid, 1);
			delete_temp("kill_other/"+uid);
		}
		if (!query_temp("other_kill/"+uid)) {
			set_temp("kill_other/"+uid, 1);
			ob->set_temp("other_kill/"+mid, 1);
			ob->delete_temp("kill_other/"+mid);
		} else ob->set_temp("kill_other/"+mid, 1);

		if( !can_kill_ob(me,ob) && !GROUP_D->is_group_fight(me,ob)
		&& strsrch(file_name(environment(me)),"/cmds/leitai") != 0 ){//ȥ�� /bwdh �ٺ�
			message_vision("$N�����룬��ɱ$n���ã����ǷŹ�$p�ɡ�\n", me, ob);
			enemy -= ({ ob });
			ob->remove_enemy(me);
			return;
		}

		if (stringp(uid = ob->query("family/family_name"))
		&& !query("vendetta/" + uid)) {
			inv = all_inventory(environment(me));
			for(i=0; i<sizeof(inv); i++) {
				if( wizardp(inv[i]) || inv[i]==me || !inv[i]->is_character()
				|| inv[i] == ob || !living(inv[i]) )
					continue;
				if( uid == inv[i]->query("family/family_name") ) {
					add("vendetta/" + uid, 1);
					delete_temp("last_channel_msg");
					CHANNEL_D->do_channel(inv[i], "party",
						"���ע������"+me->name()+"��"+ob->name()+"�����ˣ�");
					break;
				}

			}
		}
	} else
		if (environment(me)->query("no_fight") || environment(me)->query("sleep_room"))
			return;

	uid = ob->query("id");
	if (member_array(uid, killer) == -1)
		killer += ({ uid });
	tell_object(ob, HIR "������" + me->name() + "��ɱ���㣡\n" NOR);
if(userp(me) && userp(ob)) { me->apply_condition("no_quit",20);
                              ob->apply_condition("no_quit",20);}
	fight_ob(ob);
	ob->fight_ob(me);
}

void clean_up_enemy()
{
	if (sizeof(enemy)) {
		for(int i=0; i<sizeof(enemy); i++) {
			if (!objectp(enemy[i])
			|| !environment(enemy[i])
			|| environment(enemy[i]) != environment()
			|| (!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if (!sizeof(enemy)) return 0;
	
	if(stringp(this_object()->query("env/target")))
	for(which=0;which<sizeof(enemy);which++)
		if(enemy[which]->id(this_object()->query("env/target"))) return enemy[which];
		//if(enemy[which]->parse_command_id_list()[0]==this_object()->query("env/target")) return enemy[which];
	
	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if (!objectp(ob))
		return 0;
	if (!query_temp("combat_yield") && is_killing(ob->query("id")))
		return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	string uid;

	if (!objectp(ob))
		return 0;
	uid = ob->query("id");
	if (is_killing(uid))
		killer -= ({ uid });

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	object ob = this_object();

	delete_temp("combat_time");//combat_time ���ս��ʱ�� ����ĳЩ�书����ԽսԽǿ
	delete_temp("combat_been_wound");
	delete_temp("combat_been_damage");//been hit �˺�
	if (sizeof(enemy))
		foreach (object item in enemy) {
			// We ask our enemy to stop fight, but not nessessary to confirm
			// if the fight is succeffully stopped, bcz the fight will start
			// again if our enemy keeping call COMBAT_D->fight() on us.
			if (objectp(item))
				item->remove_enemy(ob);
		}
	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	object ob = this_object();

	killer = ({});
	enemy -= ({ 0 });

	for (int i = 0; i < sizeof(enemy); i++)
		if (enemy[i]->remove_killer(ob))
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object ob, target, me;
	mapping prepare;
	string type, skill;

	me = this_object();
	target=me->query_temp("bishen_target");

	if (objectp(target) && me->is_fighting(target)
	&& !target->query_temp("bishen_target") ) {
		prepare = target->query_skill_prepare();
		if( ob = query_temp("weapon") ) type = ob->query("skill_type");
		else if ( sizeof(prepare) == 0) type = "unarmed";
		else if ( sizeof(prepare) == 1) type = (keys(prepare))[0];
		else if ( sizeof(prepare) == 2) type = (keys(prepare))[target->query_temp("action_flag")];

		skill = target->query_skill_mapped(type);
		if (!stringp(skill) || target->query_skill(skill,1) < 1) {
			if (ob && set("actions", ob->query("actions",1)));
			else set("actions", (: call_other, target->query_temp("default_actions"), "query_action" :));
		} else {
			if ( ob ) set("actions", (: call_other, SKILL_D(skill), "query_action", target, ob :) );
			else set("actions", (: call_other, SKILL_D(skill), "query_action", target :) );
		}
		return;
	}

	prepare = query_skill_prepare();

	if( ob = query_temp("weapon") ) type = ob->query("skill_type");
	else if ( sizeof(prepare) == 0) type = "unarmed";
	else if ( sizeof(prepare) == 1) type = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)
		type = (keys(prepare))[query_temp("action_flag")];

	skill = query_skill_mapped(type);
	if( !stringp(skill) || !query_skill(skill) ) {
		if( ob ) set("actions", ob->query("actions",1));
		else set("actions", (: call_other, query_temp("default_actions"), "query_action" :));
	} else {
		// If using a mapped skill, call the skill daemon.
		if ( ob ) set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
		else set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	}
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	
	if (objectp(opponent)) {
		set_temp("last_opponent", opponent);
		add_temp("combat_time",1);//added by Ciwei@SJ
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	}
	return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	object me = this_object();
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if (is_fighting()
	|| !living(me)
	|| !(ob = this_player())
	|| environment(ob)!=environment()
	|| !living(ob)
	|| ob->query_temp("netdead") )
		return;

	// Now start check the auto fight cases.
	if (userp(ob)) {
		if (!userp(me)) set_heart_beat(1);
		if( is_killing(ob->query("id")) ) {
			COMBAT_D->auto_fight(me, ob, "hatred");
			return;
		} else if( stringp(vendetta_mark = query("vendetta_mark"))
		&& ob->query("vendetta/" + vendetta_mark) ) {
			COMBAT_D->auto_fight(this_object(), ob, "vendetta");
			return;
		} else if((string)query("attitude")=="aggressive" ) {
			COMBAT_D->auto_fight(this_object(), ob, "aggressive");
			return;
		}
	}
}
