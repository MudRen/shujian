//jinshe

inherit NPC;

void create()
{
        set_name("����Ѫ��", ({ "yinguan xueshe", "xueshe" }) );
        set("race", "Ұ��");
        set("age", 15);
        set("long", "һֻ��ֵ�С�ߣ�ͷ���и���ɫ��ڡ�\n");
        set("attitude", "peaceful");

        set("str", 36);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);

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
        message_vision("$Nž��һ���ϳ����أ�$N���ˡ�\n", this_object());
//        ob = new(__DIR__"obj/shedan");
//        ob->move(environment(this_object()));
        destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 60);
	return 0;
}
