// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "lao hu", "hu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ��쵴󻢣��ش����ٶ�\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 400);

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
        message_vision("$N����һ���غ����ˡ�\n", this_object());
        ob = new(__DIR__"obj/hupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}
