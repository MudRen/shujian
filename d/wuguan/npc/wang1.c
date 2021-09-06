//wang1.c
// Lklv modify 2001.10.03

inherit NPC;
#include <ansi.h>

string ask_food();
string ask_water();

void create()
{
	set_name("������", ({ "wang chuzi", "chuzi", "wang" }) );
	set("gender", "����" );
	set("age", 46);
	set("long", "����������ݵĳ��ӣ����ֵģ��غ���ʵ��\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	set("inquiry", ([
		"����" : "�����������տ�������һ��������������˭�����ң��ٺ٣�",
		"ʳ��" : (: ask_food :),
		"food" : (: ask_food :),
		"ˮ" : (: ask_water :),
		"water" : (: ask_water :),
	]) );

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
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

string ask_food()
{
	object ob,me,food;

	ob=this_object();
        me=this_player();

	say("������˵����˭֪���вͣ����������࣡���˷��ˡ���\n");
	if ((me->query("food")*10/me->max_water_capacity())>8)
		return "����ô�Ա��˻���Ҫ��";
	if ( present("rice", this_player()))
		return "�ȳ������Ҹ������˵�ɡ�";
	if ( present("rice",  environment(me)) )
		return "�ǲ��������ȳ�������˵��";
	food = new (FOOD_D("rice"));
	food->move(me);
	return "������׷��͸����ˣ������Ӵ��";
}

string ask_water()
{
        object ob,me,water;
	ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "����ô�ȱ��˻���Ҫ��";
        if ( present("tea", this_player()))
                return "�Ⱥ������Ҹ������˵�ɡ�";
        if ( present("tea",  environment(me)) )
                return "�ǲ��������Ⱥ�������˵��";
        water = new(FOOD_D("dawancha"));
        water->move(me);
	return "�Ɑ�����͸���ɣ��������Ӵ��";
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if ( ob->query("combat_exp") < 1000){
		command(":) "+ob->query("id"));
		command("say �����ǳ�����������ȿ�����ʲô�Եĺͺȵģ����û���������\n"+
		"Ҫʳ�� "HIY HBCYN"ask wang about ʳ��"CYN" �ͺȵ� "HIY HBCYN"ask wang about ˮ"CYN" �ɡ�"NOR);
	}
}
