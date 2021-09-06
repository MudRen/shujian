// wolfdog.c

inherit NPC;

void create()
{
set_name("Ұ��", ({ "lang gou", "gou" }) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ��ɫ���ǣ���ֻ�۾������̹⡣\n");
        set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"Ұ�Ǿ����ע�������ܣ�\n",
		 
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (living(this_object()) && interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
	object ob;
	message_vision("\n$N�Һ�һ�������ˣ�\n", this_object());
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
