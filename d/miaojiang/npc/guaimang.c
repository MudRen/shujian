// /u/dubei/miaojiang/npc/guaimang
//  ����

inherit NPC;

void create()
{
	set_name("����", ({ "guai mang", "mang" }));
	set("race", "Ұ��");
	set("age", 200);
	set("long", "һ��������ڣ����������Ĺ����� ����������ǿ�ҵ��ȳ�ζ��\n");
	set("attitude", "firendly");
	set("str", 70);
	set("con", 50);
	set("max_qi", 4000);
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 350000);

	set_temp("apply/attack", 370);
	set_temp("apply/armor", 350);

        setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) 
	&& random(ob->query_kar() + ob->query_per()) < 30
	&& file_name(environment(this_object())) == this_object()->query("startroom")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
        }
}

void die()
{
	message_vision("\n$N�鴤�˼��£���������һ�����ˡ�\n", this_object());
	destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
	victim->add_condition("snake_poison", 35);
	return 0;
}
