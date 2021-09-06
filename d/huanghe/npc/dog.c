// dog.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�����������Ұ����\n");
        set("attitude", "peaceful");
	set("str", 32);
	set("dex", 36);
	set("max_qi",150);
	set("qi", 150);
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp",150);
	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"Ұ���ñ�����������Ľš�\n",
		"Ұ������Ľű߰��������ģ����ֶ����ԡ�\n",
		"Ұ��������ҡ��ҡβ�͡�\n",
		"Ұ���ú���ץ��ץ�Լ��Ķ��䡣\n" }) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "���˵���������������\n", environment());
		return 1;
	}
}

void die()
{
	object ob;
	message_vision("$N�ҽ���һ�������ڵ������ˣ�������¶��һ������ͷ����\n", this_object());
	ob = new("/clone/food/jitui");
	ob->set("decay", 1);
	ob->finish_eat();
	ob->set("value", 0);
	ob->move(environment(this_object()));
	destruct(this_object());
	
}

