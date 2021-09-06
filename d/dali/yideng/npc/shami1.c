//xiao-tong2.c С��
inherit NPC;
#include <ansi.h>
string ask_tea();
string ask_food();
void create()
{
	set_name("Сɳ��", ({ "xiao shami", "xiao","shami" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ��Сɳ�֡�\n");
	
	set("combat_exp", 30000);
	set("shen_type", 100);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("inquiry", ([
		"��" : (: ask_tea :),
		"ʳ��" : (:ask_food:),
	]));

	setup();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

void init()
{       
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say(CYN"Сɳ�ְ����ӷ������λ" + RANK_D->query_respect(ob) + "���ˣ����������Űɡ�\n"NOR);
}

string ask_tea()
{
	object ob, me = this_player();

	if ((me->query("water")*10/me->max_water_capacity())>8)
		return "����ô�ȱ��˻���Ҫ��";
	if ( present("xiang cha", this_player()))
		return "�Ⱥ������Ҹ������˵�ɡ�";
	if ( present("xiang cha",  environment(me)) )
		return "�ǲ��������Ⱥ�������˵��";
	ob=new(FOOD_D("cha"));
	ob->move(environment(this_object()));
	return "�Ɑ������ɣ������Ӵ��";
}

string ask_food()
{
	object ob, me =this_player();

	if ((me->query("food")*10/me->max_water_capacity())>8)
		return "����ô�Ա��˻���Ҫ��";
	if ( present("mi fan", this_player()))
		return "�ȳ������Ҹ������˵�ɡ�";
	if ( present("mi fan",  environment(me)) )
		return "�ǲ��������ȳ�������˵��";
	ob=new(FOOD_D("rice"));
	ob->move(environment(this_object()));
	return "�����׷�����ɣ������Ӵ��";
}
