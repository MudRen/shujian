//wolf2.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "ye zhu" ,"zhu", "pig"}) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻ�����׳����ͷ�����Ұ��\n");
	set("attitude", "aggressive");

	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "ͷ��", "����", "�Ȳ�", "β��",}) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 6000);

        set("chat_chance",50);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );


	setup();
}
void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼���, �ڵ��ϴ��˼��������������ˡ�\n", this_object());
	ob = new(__DIR__"obj/zhurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

