// waiter.c

inherit WAITER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ��������\n");
        set("max_qi", 200);
        set("qi", 200);
        set("max_jing", 200);
        set("eff_jingli", 200);
        set("jingli", 200);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
        
    
	setup();
    carry_object("/clone/misc/cloth")->wear();
      
}

void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void kill_ob(object ob)
{
        command("chat ��λ�͹پ�������"+ob->name(1)+"��"+ RANK_D->query_rude(ob) +"����ɱ���ң�����");
        command("recruit " + ob->query("id"));
}


void greeting(object ob)
{
	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
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
	
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
		who->set_temp("rent_paid",1);
		return 1;
	}
	return 0;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
