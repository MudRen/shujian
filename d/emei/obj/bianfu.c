// animal: bianfu
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("����", ({ "bian fu", "fu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ���𵹹���ʯ�����ϡ�\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "��", "����", "��צ", "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 400);

        setup();
}
/*
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
        message_vision("$N��~~��һ��˺�еĽ������ˡ�\n", this_object());
        destruct(this_object());
}
*/