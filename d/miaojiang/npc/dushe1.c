//jinshe

inherit NPC;

void create()
{
        set_name("��ɫ����", ({ "heise dushe", "dushe" }) );
        set("race", "Ұ��");
        set("age", 15);
        set("long", "һֻ������ڵĶ��ߣ���ֻ�۾�����Ŀ������ܡ�\n");
        set("attitude", "peaceful");

        set("str", 36);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 220000);

        set_temp("apply/attack", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/armor", 150);

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
// object ob;
        message_vision("$Nž��һ���ϳ����أ�$N���ˡ�\n", this_object());
//        ob = new(__DIR__"obj/shedan");
//        ob->move(environment(this_object()));
        destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 40);
	return 0;
}
