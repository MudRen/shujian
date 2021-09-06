// By River 98/12
inherit NPC;

void create()
{
	set_name("����С��", ({ "yizu xiaohuo", "yizu", "xiaohuo" }) );
	set("gender", "����" );
	set("age", 22);
	set("long","��λ����С����Ц����ؿ����㡣\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
        set("inquiry",([
            "��Ǯ" : "�뿴�軨԰�����͸����������ɡ�",
            "price" : "�뿴�軨԰�����͸����������ɡ�",
        ]));
	setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();	
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{        
	if (!ob || !present(ob)) return;
       say ("����С��Ц����ӭ��������˵������λ" + RANK_D->query_respect(ob)+ "����������\n");
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "����С��һ������˵������л���ϣ������Բι�һ�²軨԰�ˡ�\n");
		who->set_temp("flower_paid",1);
		return 1;
	}
	return 0;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
