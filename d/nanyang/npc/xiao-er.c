// nanyang/npc/xiao-er.c
// Lklv Modify 2001.10.10

inherit WAITER;
void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "xiaoer", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "����Ц�����æ������ʱ�������ϵ�ë�������\n");
	set("combat_exp", 200);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
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

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch(random(2)) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 500){
		message_vision("С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n",who);
		who->set_temp("rent_paid",1);
		return 1;
	}
	return 0;
}
