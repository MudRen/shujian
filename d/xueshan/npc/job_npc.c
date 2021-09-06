// job_npc.c by lane@ln

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Ӱ����ʿ", ({ "yingzi wushi", "wushi", "yingzi" }) );

	set("gender", "����" );
	set("age", 30);
	set("nickname", HIR"Ӱ����ʿ"NOR);
	set("long", "һ��Ӱ����ʿ���沿���������⡣\n");
	set("meitude","peaceful");

	set("combat_exp", 2000000);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("max_neili", 20000);
	set("neili", 5000);
	set("neili", 20000);

	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);

	set("no_ansuan",1);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("claw", 300);
	set_skill("leg", 300);
	set_skill("finger", 300);
	set_skill("cuff", 300);
	set_skill("hand", 300);
	set_skill("unarmed", 300);
	set_skill("sword", 300);
	set_skill("blade", 300);
	set_skill("hammer", 300);
	set_skill("stick", 300);
	set_skill("club", 300);
	set_skill("staff", 300);
	set_skill("whip", 300);
	set_skill("dagger", 300);
	set_skill("literate", 200);

	setup();
	if( random(2) ) add_money("thousand-cash", random(5) + 1 );
	else add_money("gold", random(10) + 1 );
}

void init()
{
	object ob = this_player();
	object me = this_object();

	::init();

	if( interactive(ob) && !environment(ob)->query("no_fight")
	 && me->query("kill_party") == ob->query("family/family_name") ) {
		command("grin " + ob->query("id"));
		command("knock " + ob->query("id"));
		ob->start_busy(1);
	}
}       

void do_copy(object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;

	set_name(ob->name(), ({ ob->query("id")+"'s wushi", "wushi", "yingzi" }) );
	set("title", ob->query("title") );
	set("long", ob->query("long") );

	set_temp("apply/attack",  random(30));
	set_temp("apply/armor",  random(50));

// copy skills

	if( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			set_skill(sname[i], skill_status[sname[i]]);
		}
	}

// copy skill maps

	if( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			map_skill(mname[i], map_status[mname[i]]);
		}
	}

// copy skill prepares

	if( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

// copy weapon & armor

	inv = all_inventory(ob);
	i = sizeof(inv);
	while (i--) {
		if( inv[i]->query("weapon_prop/damage") > 100
		|| inv[i]->query("unique")
		|| inv[i]->query("imbued")
		|| inv[i]->query("treasure")
		|| inv[i]->query("armor_prop/armor") > 100 ) continue;

		if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			set("weapon", base_name(inv[i]));
		}
		if( inv[i]->query("armor_prop") && inv[i]->query("armor_type") == "cloth" && inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			set("armor", base_name(inv[i]));
		}
	}

	hp_status = ob->query_entire_dbase();

	set("str", hp_status["str"]);
	set("int", hp_status["int"]);
	set("con", hp_status["con"]);
	set("dex", hp_status["dex"]);

	set("max_qi",    hp_status["max_qi"]);
	set("eff_qi",    hp_status["max_qi"]);
	set("qi",        hp_status["max_qi"]);
	set("max_jing",  hp_status["max_jing"]);
	set("eff_jing",  hp_status["max_jing"]);
	set("jing",      hp_status["max_jing"]);
	set("max_neili", hp_status["max_neili"]);
	set("neili",     hp_status["neili"]);
	set("jiali",     hp_status["jiali"]);
	set("combat_exp",hp_status["combat_exp"]);
	call_out("dest", 1000);
}

void die()
{
	object me, ob;
	int exp, pot;

	me = query_temp("last_damage_from");
	ob = this_object();

	if( !objectp(me) ) return;
	if( !ob->query("kill_party") ) return;

	if( ob->query("kill_party") == me->query("family/family_name") ) {

		if( ob->query("combat_exp") > me->query("combat_exp")*3/2 )
			exp = 1000 + random(200);
		else if( ob->query("combat_exp") > me->query("combat_exp") ) {
			exp = 300 + random(100) + (ob->query("combat_exp") - me->query("combat_exp"))/2000;
			if( exp >= 1000 ) exp = 800 + random(200);
		} else if( ob->query("combat_exp") < me->query("combat_exp")*3/4 )
			exp = 300 + random(300);
		else exp = 200 + random(200);

		pot = exp/4 + random(50);

		me->add("combat_exp", exp);
		me->add("potential", pot);
		me->add("safeguard_party", 1);
		message_vision(YEL"\n��ɱ����" + ob->name() + "��Ϊ" + me->query("family/family_name") + "����������Ķ�����\n",me);
		message_vision(YEL"����ϸ����ղź�" + ob->name() + "�Ĵ򶷾����������Լ�����ѧ�������ָ�����һ�㣡\n",me);
		message_vision(HIW"������" + CHINESE_D->chinese_number(exp) + HIW"�㾭�飬" + 
			CHINESE_D->chinese_number(pot) + HIW"��Ǳ�ܣ��㹲Ϊ" + me->query("family/family_name") + HIW
			"������" + CHINESE_D->chinese_number(me->query("safeguard_party")) + HIW"��������\n"NOR,me);
	}
	::die();
	return;
}

void dest()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	write(ob->query("name")+"���������ˬ��������Ĳ���ˣ������ˣ�\n",me); 
	write(ob->query("name")+"ʩչ��������һ�Σ�ƮȻ��ȥ��\n",me);
	destruct(this_object());
}
