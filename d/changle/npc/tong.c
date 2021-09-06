// tong.c С��
inherit NPC;
#include <ansi.h>
string ask_tea();
string ask_food();
void create()
{
	set_name("С��",({"xiao tong", "xiao", "tong"}));
	set("long","������ר���̲��С�ס�������ü��Ŀ�㡣\n");
	set("gender", "Ů��");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);	

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 1);
	set("combat_exp", 1000);
	set("score", 50000);

	set_skill("unarmed",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	set_skill("force", 20);
	set_skill("sword", 20);

	set("inquiry", ([
		"��" : (: ask_tea :),
		"ʳ��" : (:ask_food:),
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
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
	say(CYN"С��Ц������˵������λ" + RANK_D->query_respect(ob) + "���ˣ�" + "����͸����ݲ衣\n"NOR);
}

string ask_tea()
{
	object ob;
	object me;
	ob=this_object();
	me=this_player();
	if ((me->query("water")*10/me->max_water_capacity())>8)
		return "����ô�ȱ��˻���Ҫ��";
	if ( present("xiang cha", this_player()))
		return "�Ⱥ������Ҹ������˵�ɡ�";
	if ( present("xiang cha",  environment(me)) )
		return "�ǲ��������Ⱥ�������˵��";
	ob=new(FOOD_D("cha"));
	ob->move(environment(this_object()));
	return "�Ɑ�������ȵ�������ɣ��������Ӵ��";
}

string ask_food()
{
	object ob;
	object me;
	ob=this_object();
	me=this_player();
	if ((me->query("food")*10/me->max_water_capacity())>8)
		return "����ô�Ա��˻���Ҫ��";
	if ( present("rice", this_player()))
		return "�ȳ������Ҹ������˵�ɡ�";
	if ( present("rice",  environment(me)) )
		return "�ǲ��������ȳ�������˵��";
	ob=new(FOOD_D("rice"));
	ob->move(environment(this_object()));
	return "�������׷�����ɣ��������Ӵ��";
}
