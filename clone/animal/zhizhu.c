// zhizhu.c ֩��

inherit NPC;

void create()
{
	
        set_name("����֩��", ({ "zhi zhu", "zhizhu" }) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ������צ�ľ���֩�롣\n");
	
	set("max_qi", 4000);
	set("eff_qi", 4000);
	set("qi", 4000);
	set("str", 100);
	set("con", 30);
	set("dex", 100);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 800000);
	
		
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
	set_temp("apply/armor", 800);

	setup();
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
		ob->start_busy(3);
	}
}

