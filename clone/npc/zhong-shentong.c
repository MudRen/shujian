#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "zhong-shentong"

#include <ansi.h>
inherit NPC;
inherit F_SAVE;

void do_copy(object);
void do_clone(object);

string query_save_file()
{
	return MENGZHU;
}

void create()
{
	object tmp;
	seteuid(getuid());
	set_temp("pob", previous_object(-1));
	if (!restore()) {
		set_name("������", ({ "zhong shentong", "zhong", "shentong" }) );
		create_family("����", 0, "����");
		set("title", "����ͨ" );
		set("gender", "����" );
		set("age", 60);
		set("long","�������ڵ�һ�λ�ɽ�۽��м�ѹȺ�۵��������ˡ�\n");
		set("attitude", "heroism");
		set("no_quest", 1);
		set("winner","");
		set("str", 25);
		set("con", 25);
		set("int", 25);
		set("dex", 25);
		set("max_qi", 2500);
		set("eff_qi", 2500);
		set("qi", 3000);
		set("max_jing", 2500);
		set("jing", 2500);
		set("jiali", 100);
		set("combat_exp", 800000);
		set_skill("unarmed", 180);
		set_skill("force", 180);
		set_skill("dodge", 180);
		set_skill("parry", 180);
		set("weapon", BINGQI_D("changjian"));
		set("armor", ARMOR_D("armor"));
		setup();
		carry_object(ARMOR_D("armor"))->wear();
	}
	else {
		set_name(query("name"), ({ "zhong shentong", "zhong", "shentong" }));
		set("no_quest", 1);
		setup();
		if( query("weapon") ) {
			tmp = carry_object(query("weapon"));
			tmp->wield();
			tmp->set("no_get", 1);
		}
		if( query("armor") ) {
			tmp = carry_object(query("armor"));
			tmp->wear();
			tmp->set("no_get", 1);
		}
	}
}

void heart_beat()
{
	if (!living(this_object()) || is_fighting() || is_busy()) ::heart_beat();
}

void init()
{
	::init();
	add_action("do_recover", ({"recover","huifu"}));
	add_action("do_recopy", "recopy");
}

void kill_ob(object me)
{
	object ob;
	int i;

	command("say ����ı�������������ǳ������ı��ӵ��ˣ���");
	reincarnate();
	me->set("neili", 0);
	me->set("jingli", 10);
	me->remove_killer(this_object());
	remove_killer(me);
	for (i=1; i<=2; i++)
		if (objectp(ob = present("wei shi " + i)) && living(ob))
			 ob->kill_ob(me);
		else {
			command("say �ɱ����������������㣡");
			break;
		}
}

int accept_fight(object ob)
{
	if (query("winner") == ob->query("id"))
		return notify_fail("������Լ���ʲô�ܣ���\n");

	if (userp(ob) && NATURE_D->query_daytime() != "event_noon")
		return notify_fail("����ʱ�ֲ�����ս������\n");

	if (ob->query_temp("no_zhong"))
		return notify_fail("�����ڲ���������֮λ��\n");

	if (wizardp(ob))
		return notify_fail("��ʦ����������֮λ��\n");

	if (ob->query_condition("killer"))
		return notify_fail("ͨ��������������֮λ��\n");
		
//        if (ob->query("no_pk"))
//            return notify_fail("�㶼�Ѿ�����ϴ���ˣ����ں������٣�\n");

	if (mapp(ob->query_conditions_by_type("poison")) || mapp(ob->query_conditions_by_type("hurt")))
		return notify_fail("�����о޶����޷�������������������\n");

	if (is_fighting()) return notify_fail("�Ѿ�����������ս����������\n");

	if (is_busy()) return notify_fail("�����ոո��£���һ��ʱ�����԰ɣ�\n");

	restore();
	setup();
	clear_condition(0);
	start_busy(-1);
	interrupt_me(0, 0);
	reincarnate();
	command("enable all");
	reincarnate();
	remove_call_out("checking");
	call_out("checking", 1, ob);
	return 1;
}

void checking(object ob)
{
	int my_max_qi, his_max_qi;

	if (!ob) return;
	my_max_qi = query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (is_fighting(ob)) {
		call_out("checking", 1, ob);
		return;
	}

	if (!present(ob)) return;

	if (query("qi")*100 / my_max_qi <= 50) {
		command("say ��������Ȼ��������ϲ���Ϊ��һ���ġ�����ͨ����\n");
		command("chat "+HIY+ob->query("name")+"����һ���á�����ͨ���ĳƺţ���������ķ��ڷ���"NOR);
		add("generation", 1);
		do_copy(ob);
		do_clone(ob);
		start_busy(200);
		return;
	}
	if (ob->query("qi")*100 / his_max_qi <= 50)
		command("say ����" + RANK_D->query_respect(ob) + "���ö����ϰ�������ڵ��������г���ͷ�أ�\n");
}

void do_copy(object ob)
{
	object obj;
	seteuid(getuid());

	set("name", ob->name(1));
	set("title", "��" + chinese_number(query("generation")) + "��������ͨ��");
	set("short", query("title") + query("name") + "(" + capitalize(ob->query("id")) + ")");
	set("long", ob->long(1));

	//remove last winner's apply/short.
	if (objectp(obj = LOGIN_D->find_body(query("winner"))))
		obj->delete_temp("apply/short");

	ob->set_temp("apply/short", ({query("short")}));
	ob->delete("no_recover");
	set("short", query("title") + query("name") + "(Zhong shentong)");
	set("no_get",1);
	delete("title");
}

int do_recopy()
{
	object ob = this_player();

	if (query("winner") != ob->query("id"))
		return notify_fail("�㲻�����Ρ�����ͨ����\n");

	do_copy(ob);
	write("�ƺŻָ���ϣ�\n");
	return 1;
}

void do_clone(object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;

	seteuid(getuid());
	set("winner", ob->query("id"));

/* delete and copy skills */

	if (mapp(skill_status = query_skills())) {
		sname = keys(skill_status);

		i = sizeof(sname);
		while (i--) delete_skill(sname[i]);
	}

	if (mapp(skill_status = ob->query_skills()) ) {
		sname = keys(skill_status);

		i = sizeof(sname);
		while (i--) set_skill(sname[i], skill_status[sname[i]]);
	}

/* delete and copy skill maps */

	if ( mapp(map_status = query_skill_map()) ) {
		mname = keys(map_status);

		i = sizeof(mname);
		while (i--) map_skill(mname[i]);
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname = keys(map_status);

		i = sizeof(mname);
		while (i--) map_skill(mname[i], map_status[mname[i]]);
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = query_skill_prepare()) ) {
		pname = keys(prepare_status);

		i = sizeof(pname);
		while (i--) prepare_skill(pname[i]);
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname = keys(prepare_status);

		i = sizeof(pname);
		while (i--) prepare_skill(pname[i], prepare_status[pname[i]]);
	}

/* unwield and remove weapon & armor */

	inv = all_inventory();
	i = sizeof(inv);
	while (i--) destruct(inv[i]);
	delete("weapon");
	delete("armor");
	delete("recovered");
/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	i = sizeof(inv);
	while (i--) {
		if( inv[i]->query("weapon_prop/damage") > 100
		|| inv[i]->query("unique")
		|| inv[i]->query("imbued")
		|| inv[i]->query("treasure")
		|| mapp(inv[i]->query("weapon_mp"))
		|| mapp(inv[i]->query("armor_mp"))
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

/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

	set("str", hp_status["str"]+5);
	set("int", hp_status["int"]+5);
	set("con", hp_status["con"]+5);
	set("dex", hp_status["dex"]+5);
	set("age", hp_status["age"]);
	set("per", hp_status["per"]);

	set("max_qi", hp_status["max_qi"]/4*5);
	set("max_jing", hp_status["max_jing"]);
	set("max_neili", hp_status["max_neili"]/2*3);
	set("eff_jingli", hp_status["eff_jingli"]);
	set("gender", hp_status["gender"]);
	// let the copy have 1.5 times exp.
	set("combat_exp", hp_status["combat_exp"]/2*3);
	set("death_count", hp_status["death_count"]);
	set("death_times", hp_status["death_times"]);
	set("PKS", hp_status["PKS"]);
	set("family/family_name", ob->query("family/family_name"));
	set("no_get", query("name")+"������˵̫���ˡ�\n");
	clear_condition(0);
	revive(1);
	reincarnate();
	save();
	destruct(load_object(__FILE__));
	tell_object(ob, "״̬������ϡ�\n");
}

int do_recover()
{
	object ob = this_player();
	mapping skill_status, map_status, prepare_status;
	string *sname, *mname, *pname, dead;
	int i;

	if (is_busy() || is_fighting())
		return notify_fail("����ͨ��æ���ء�\n");

	if (NATURE_D->query_daytime() != "event_midnight")
		return notify_fail("��ҹʱ�ֲ��ָܻ���\n");
	restore();
	if (query("winner") != ob->query("id")) return notify_fail("�㲻�����Ρ�����ͨ����\n");
	if ( ob->query("family/family_name") != query("family/family_name") )
		return notify_fail("���Ѿ��ı������ɣ����ָܻ��ˡ�\n");
	if ( ob->query("no_recover"))
		return notify_fail("��������б仯�����ܱ��ָ���\n");
	if (ob->query("death_count") <= query("death_count"))
		return notify_fail("���úúõģ��ָ�ʲô��\n");
	if( ob->query("combat_exp") / 2 > query("combat_exp") / 3 )
		return notify_fail("����Խ�ָ�Խ�٣����˰ɡ�\n");
	if( ob->query("combat_exp") / 33 < query("combat_exp") / 50)
		return notify_fail("��ľ��鶼����ȥ�ˣ�\n");
	if (ob->query("PKS") > query("PKS"))
		return notify_fail("ɱ����ұ������˰ɣ������ɡ�\n");
	if (query("recovered"))
		return notify_fail("���Ѿ��ָ���һ�Σ������ٻָ��ˡ�\n");

//	2005.5.12 fixed by Lane@SJ
	dead = ob->query("last_death");
	if (dead[<16..<1] == "��������ɱ���ˡ�" )
		return notify_fail("����������ɱ���˰ɣ���ã�\n");

	ob->set("death_count", query("death_count"));
	ob->set("death_times", query("death_times"));

/* delete and copy skills */

	if ( mapp(skill_status = ob->query_skills()) ) {
		sname = keys(skill_status);

		i = sizeof(sname);
		while (i--) ob->delete_skill(sname[i]);
	}

	if ( mapp(skill_status = query_skills()) ) {
		sname = keys(skill_status);

		i = sizeof(sname);
		while (i--) ob->set_skill(sname[i], skill_status[sname[i]]);
	}

/* delete and copy skill maps */

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname = keys(map_status);

		i = sizeof(mname);
		while (i--) ob->map_skill(mname[i]);
	}

	if ( mapp(map_status = query_skill_map()) ) {
		mname = keys(map_status);

		i = sizeof(mname);
		while (i--) ob->map_skill(mname[i], map_status[mname[i]]);
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname = keys(prepare_status);

		i = sizeof(pname);
		while (i--) ob->prepare_skill(pname[i]);
	}

	if ( mapp(prepare_status = query_skill_prepare()) ) {
		pname = keys(prepare_status);

		i = sizeof(pname);
		while (i--) ob->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

/* copy combat exp values */
	// the copy's exp was 1.5 times of this player
	ob->set("combat_exp", query("combat_exp")/3*2);
	set("recovered", 1);
	clear_condition(0);
	reincarnate();
	save();
	write("���״̬�ָ���ϡ�\n");
	return 1;
}
