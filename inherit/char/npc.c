// npc.c
// modified by snowman@SJ
// modified by campsun@SJ

#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

object carry_object(string file)
{
	object ob;

	file = resolve_path(0, file);
	ob = unew(file);
	if (ob) ob->move(this_object());
	return ob;
}

object add_money(string type, int amount)
{
	object ob;

	if (!clonep()) return 0;
	ob = carry_object("/clone/money/" + type);
	if (!ob) return 0;
	ob->set_amount(amount);
	return ob;
}

int accept_fight(object who)
{
	string att;

	att = query("attitude");

	if (is_killing(who->query("id"))) {
		command("say �ߣ�" + RANK_D->query_rude(who)+"�㾡�ܷ�������ɣ�");
		return 1;
	}
	if (is_fighting())
		switch(att) {
			case "heroism":
				command("say �ߣ�" + RANK_D->query_rude(who)+"�㾡�ܽ��аɣ�");
				return 1;
			default:
				command("say " + RANK_D->query_respect(who)+"���ж�Ϊʤ���ⲻ������̫����");
				return 0;
		}

	switch(att) {
		case "friendly":
			command("say " + RANK_D->query_self(this_object())
				+ "��ô������" + RANK_D->query_respect(who)
				+ "�Ķ��֣����ͱ���Ц�ˣ�");
			break;
		case "aggressive":
		case "killer":
			command("say �ߣ�" + RANK_D->query_rude(who)+"�㾡�ܷ�������ɣ�");
			return 1;
		default:
			if (query("jing") * 100 / query("max_jing") >= 90
			&& query("qi") * 100 / query("max_qi") >= 90
			&& query("jingli") * 100 / query("eff_jingli") >= 80
			&& query("neili") * 100 / query("max_neili") >= 80 ) {
				command("say ��Ȼ" + RANK_D->query_respect(who)
					+ "�ͽ̣�" + RANK_D->query_self(this_object())
					+ "ֻ�÷��㣬���ǵ㵽Ϊֹ��");
				return 1;
			}
	}
	return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
	if (home && !query("startroom")) return 0;
	if (!home && stringp(query("startroom")))
		if(!objectp(home = load_object(query("startroom")) ))
			return 0;

	// Are we at home already?
	if( !environment()
	|| environment()==home )
		return 1;

	// Are we able to leave?
	if( !living(this_object())
	|| is_fighting()
	|| is_busy() ) return 0;

	// Are we beast?
	if( query("master") && find_player((string)query("master")) )
		return 0;

	// Leave for home now.
	message("vision", name() + "����ææ���뿪�ˡ�\n",
		environment(), this_object());
	if (move(home)) {
		message("vision", name() + "����ææ�����˹�����\n",
			environment(), this_object());
		delete_temp("random_move");
		return 1;
	}
	return 0;
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.

int chat()
{
	string *msg;
	int chance, rnd;

	if( !environment() || !living(this_object()) ) return 0;

	if (query("neili")>100 && query("max_neili") > 200
	&& query("race") == "����" && !is_busy()) {
		if (!is_fighting()) {
			if (query("eff_jing")
			&& query("jing")*100/query("eff_jing") <= 80)
				command("exert regenerate");

			if (query("eff_qi") && query("qi") >= 0
			&& query("qi")*100/query("eff_qi") <= 80)
				command("exert recover");

			if (query("eff_jingli")
			&& query("jingli")*100/query("eff_jingli") <= 80)
				command("exert refresh");
		} else {
			if (query("eff_qi") && query("qi") >= 0
			&& query("qi")*100/query("eff_qi") <= 40)
				command("exert recover");

			if (query("eff_jingli")
			&& query("jingli")*100/query("eff_jingli") <= 40)
				command("exert refresh");
		}

		if (!is_fighting() && query_temp("embed") && random(10) < 3)
			command("remove "+query_temp("embed"));

		if (query("eff_qi") && query("qi") >= 0
		&& query("max_qi") && !is_fighting() && !query("mute")
		&& query_skill_mapped("force")
		&& query_skill("force") > 50
		&& query("eff_qi") < query("max_qi")
		&& query("eff_qi") >= query("max_qi")/3
		&& !query("no_heal"))                                  //set no_heal tag by campsun 2004.2.4
			command("exert heal");
	}

	if( !chance = query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg")) && !is_busy()) {
		//return while msg is null add by campsun 2004.2.4
		if (!sizeof(msg)) return 0;                                                    
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
	mapping exits;
	string *dirs;
	object me = this_object();

	if( !environment()
	|| !mapp(exits = environment()->query("exits"))
	|| me->is_fighting() || me->is_busy()
	|| me->query("jingli") < me->query("eff_jingli") / 2 ) return 0;

	dirs = keys(exits);
	if (sizeof(dirs) < 1) return 0;
	add_temp("random_move", 1);
	command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	if (!living(this_object()) || is_busy() || is_exert()) return 0;
	"/cmds/skill/exert"->main(this_object(), func);
}

int perform_action(string func)
{
	if (!living(this_object()) || is_busy() || is_perform()) return 0;
	"/cmds/skill/perform"->main(this_object(), func);
}

