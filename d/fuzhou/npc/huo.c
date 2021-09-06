// huo.c ��ʦ��.����
// by snowman 12.feb.98
// Modify by Looklove 2000/10/07

#include <ansi.h>
inherit NPC;
string ask_me();
void check_skills(object ob);
void waiting(object dest);
void checking(object dest);
void do_back();
void do_kill(object dest);
void do_weapon();
void change_huo();

void create()
{
	if (clonep()) tell_room(environment(),
		HIY +"����ת��ǽ�Ǻ�Ȼ�����ˣ������߳���һ������ޱȵ���ؤ��\n\n" NOR);
	set_name("��ʦ��", ({"he shiwo", "he", "shiwo"}));
	set("gender", "����");
	set("title", "ؤ���ʮ�Ŵ�����");
	set("age", 35);
	set("unique", 1);
	set("per", 13);
	delete("huodu");
	set("location", 1);
	set("long", "ֻ��������һ��������õĺ��£��ֳ�һ���Ʊ��ڴ�ϸ�����ȣ���ͷ\n"+
			"�ҷ���һ��������ӷ�װ���͹͹�����ǰ̺ۣ����ϸ�����ֻ������ԭ\n"+
			"����һ��������ӡ�\n");

	set("attitude", "friendly");
	create_family("ؤ��", 19, "����");
	set("str", 23);
	set("int", 24);
	set("con", 22);
	set("dex", 27);
	set("per", 12);
	set("chat_chance", 35);
	set("chat_msg", ({ (: random_move :), }));
	set("max_qi", 700);
	set("max_jing", 700);
	set("eff_jingli", 500);
	set("combat_exp", 150000);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("staff", 60);
	set_skill("huntian-qigong", 60);
	set_skill("tianshan-zhang", 60);
	set_skill("xiaoyaoyou", 50);
	set_skill("suohou-shou", 50);
	set_skill("hand", 50);
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("hand", "suohou-shou");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("hand", "suohou-shou");
	set("inquiry", ([
		"����"  : (: ask_me :),
		"ؤ��" : "����ؤ�������µ�һ��",
		"���ַ���" : "����˵ʲô����",
		"�����" : "����˵ʲô����",
		"������" : "����˵ʲô����",
		"��Ħ��" : "����˵ʲô����",
	]));
	setup();
	if (clonep())
	{
		reincarnate();
		do_weapon();
	}
	remove_call_out("change_huo");
	if(clonep()) call_out("change_huo", 900);
}

void do_weapon()
{
	object armor, weapon, *ob, me = this_object();

	ob = all_inventory(me);

	foreach (object item in ob) destruct(item);
	if (query("huodu"))
	{
		armor = new(ARMOR_D("pao2"));
		weapon = new(__DIR__"obj/txs");
	}
	else
	{
		armor = new(ARMOR_D("cloth"));
		weapon = new(BINGQI_D("gangzhang"));
	}
	armor->move(me);
	armor->wear();
	weapon->move(me);
	weapon->wield();
	add_money("silver", 50);
}

nosave int init_flag = 0;

void init()
{
	object ob;

	::init();
	if (init_flag) return;
	if (living(this_object()) && interactive(ob = this_player()) && visible(ob))
	{
		init_flag = 1;
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	init_flag = 0;
	if (ob && present(ob, environment()))
	{
		if (query("huodu") && ob->query("combat_exp") > 100000) check_skills(ob);
		else if (present("yuzhu bang", ob))
		{
			object me = this_object();

			message_vision(BLU"$NͻȻ����$n��ǰ���۾�ֱ����$n������������\n"NOR,me,ob);
			change_huo();
			ob->add_busy(2);
			do_kill(ob);
		}
	}
}

string get_user_place()
{
	object *obs = users(), ob, room;
	string room_name;

	ob = obs[random(sizeof(obs))];
	if (room = environment(ob)) room_name = file_name(room);

	if (
	!room ||
	wiz_level(ob) ||
	ob->is_ghost() ||
	strsrch(room_name,"/d/") < 0 ||
	!strsrch(room_name, "/d/wizard/") ||
	!strsrch(room_name, "/d/death/") ||
	!strsrch(room_name, "/d/wuguan/")
	)
		return 0;

	return room_name;
}

void do_back()
{
	string room;

	remove_call_out("do_back");
	if (!stringp(room = get_user_place())) move("/d/city/kedian");
	else move(room);

	tell_room(environment(), query("name")+"�첽���˹�����\n");
	set_leader(0);
}

string ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("combat_exp") < 100000) return "С���ӣ����Լ�������֪����ôд�𣿱��ʶ������ġ�";
	else
	{
		if (query("huodu"))
		{
			check_skills(ob);
			return "�ٺ٣��������Ǳ����ӣ���ˣ���׺�Ϸ���ҿ����ɣ�";
		}
		else
		{
			switch(random(4))
			{
				case 0 : return "��֪����"; break;
				case 1 : return "�ҿɲ���ʶ����ˡ�"; break;
				case 2 : return "˭�ǻ�������"; break;
				case 3 : change_huo();
					do_kill(ob);
					return "�ٺ٣��������Ǳ����ӣ���ˣ���׺�Ϸ���ҿ����ɣ�\n";
				break;
			}
		}
	}
}

void change_huo()
{
	object *ob;

	remove_call_out("change_huo");

	tell_room(environment(), HIY +"ͻȻ��ʦ������һЦ�����ֳ�ȥ���ϵİ��಼�£���������һĨ����Ȼ\n"+
		"ת�۾ͱ����һλ���Ž��ۡ������������깫�ӡ�\n\n" NOR);
	set("title", "�ɹ�����");
	set("long", "ֻ�������ױ���ɫ���ۣ�����ߡ�ȣ������Ӵ�磬����һ�ɰ���֮ɫ��\n");
	set_name("����", ({"huo du", "huo", "du"}));
	set("shen", -12000);
	set("per", 25);
	set("huodu", 1);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("songshan-qigong", 120);
	set_skill("songshan-jian", 120);
	set_skill("xiaoyaoyou", 120);
	set_skill("suohou-shou", 120);
	set_skill("hand", 100);
	map_skill("force", "songshan-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("hand", "suohou-shou");
	map_skill("sword", "songshan-jian");
	prepare_skill("hand", "suohou-shou");
	set("combat_exp", 300000);
	set("max_qi", 1500);
	set("max_jing", 1300);
	set("eff_jingli", 1400);
	set("jiali", 50);
	reincarnate();
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({ (: perform_action, "sword.feiwu" :) }));
	do_weapon();
	if (!environment()->query("no_fight") && !environment()->query("sleep_room"))
	{
		ob = all_inventory(environment());
		foreach (object item in ob) {
			if (!userp(item)) continue;
			if (!visible(item)) continue;
			if (item->query_temp("block_msg/all")) continue;
			if (item->query("combat_exp") < 100000) continue;
			if (item->query_temp("user_type") == "worker") continue;
			COMBAT_D->do_attack(this_object(), item, query_temp("weapon"), 1);
		}
	}
	remove_call_out("create");
	if (clonep()) call_out("create", 300+random(200));
}

void kill_ob(object ob)
{
	if (!query("huodu")) change_huo();
	::kill_ob(ob);
}

void reset()
{
	if (clonep()) do_back();
}

#include "killer.h";
