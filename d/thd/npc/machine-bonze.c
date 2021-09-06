// machine-bonze.c ��е����

inherit NPC;

void create()
{
	set_name("��е����", ({ "jixie heshang", "jixie", "heshang", "machine bonze", "machine", "bonze" }) );
	set("gender", "����" );
	set("age", 30);
	set("mute", 1);
	set("long", "һ�������õĻ�е���У�����һЩľ�����Ƥ�������ģ�������Ҳ����������У�ר����һ����Ƥ��ס��ͷ��������д�š������С������֡��ڻ�е���еı�����һ��СС�Ŀ���(trigger)��\n");
	set("attitude", "friendly");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
        
}

void init()
{
	add_action("do_turn", "turn");
	add_action("do_turn", "ban");
}

void unconcious()
{
	say("��е���к�Ȼ������������һ�����죬�ʹ��ɵ������ˡ�\n");
	set("damaged", 1);
	remove_all_enemy();
	reincarnate();
	set("disable_type", " <����>");
	set("qi", 0);
	set("jing", 0);
	set("jingli", 0);
}

void die()
{
	unconcious();
}

int accept_fight(object ob)
{
	return notify_fail("������㣬��ֻ�Ǹ���е���ж��ѣ�\n");
}

int do_turn(string arg)
{
	object me = this_object();
	object ob = this_player();
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	if (ob->is_busy()) return notify_fail("����æ���أ�\n");
	if (arg != "trigger" && arg != "kaiguan") return notify_fail("��Ҫ�⶯ʲô��\n");

//	if (ob->is_fighting()) return notify_fail("����æ�Ŵ���أ�\n");
	if (is_fighting()) return notify_fail("��е���������Զ���ս�����޷��������أ�\n");

	if (random(query("fight_times")) >= 8) {
		set("damaged", 1);
		me->disable_player(" <����>");
	}

	message_vision("$N����ذ⶯�˻�е���б���Ŀ��ء�\n", ob);	
	if (query("damaged")) return notify_fail("���������е�����Ѿ������ˣ���Ҫ��������\n");

	add("fight_times", 1);

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

	set("str", hp_status["str"]);
	set("int", hp_status["int"]);
	set("con", hp_status["con"]);
	set("dex", hp_status["dex"]);

	set("max_qi",    hp_status["max_qi"]);
	set("eff_qi",    hp_status["eff_qi"]);
	set("qi",        hp_status["qi"]);
	set("max_jing",  hp_status["max_jing"]);
	set("eff_jing",  hp_status["eff_jing"]);
	set("jing",      hp_status["jing"]);
	set("max_neili", hp_status["max_neili"]);
	set("neili",     hp_status["neili"]);
	set("jiali",     hp_status["jiali"]);
	set("combat_exp",hp_status["combat_exp"]);

	message_vision("��е���к�ȻһԾ���𣬶�$N���������ҵĽ�����\n", ob);	
	me->fight_ob(ob);
	ob->fight_ob(me);
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	write("������㣬��ֻ�Ǹ���е���ж��ѣ�\n");
}
