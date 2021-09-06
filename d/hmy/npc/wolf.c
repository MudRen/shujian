// wolf.c

inherit NPC;

void create()
{
        set_name("Ұ��", ({ "ye lang", "lang", "wolf"}) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����ͦ�أ����ų���ͷ��Ұ�ǡ�\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 10000);
	set("shen_type", -1);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"Ұ�Ǵ�����ร�ร�ร�ร�ร�ร�\n",
		"Ұ��ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
        set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
void die()
{
	object ob;
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
       ob = new(__DIR__"obj/goupi");
 	ob->move(environment(this_object()));
	destruct(this_object());
}
