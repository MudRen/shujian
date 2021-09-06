// animal: snake.c

inherit NPC;

void create()
{
	set_name("����", ({ "snake", "she" }) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ�����������Դ����ߣ�β��ɳɳ���졣\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("con", 30);

	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 2000);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob = this_player();

	::init();
	if (interactive(ob) && random(ob->query_kar() + ob->query_per()) < 20) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

void die()
{
	object me = this_object();;

	message_vision("$Nž��һ���ϳ����أ�$N���ˡ�\n", me);
	new("/clone/medicine/shedan")->move(environment(me));
	destruct(me);
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",	victim->query_condition("snake_poison") + 6);
	return 0;
}
