
inherit NPC;

void create()
{
	set_name("����", ({ "mian yang", "yang" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һͷѩ�׿ɰ����ַ���׳������\n");
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "kick", "bite" }) );

	set("combat_exp", 200);
	set_temp("apply/attack", 1);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 3);
	set_temp("apply/armor", 2);
	setup();
}

void die()
{
	object ob;
	message_vision("$N��঵ĺ��˼��������ڵ������ˡ�\n", this_object());
        ob = new(__DIR__"yangpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}