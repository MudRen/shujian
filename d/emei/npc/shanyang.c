// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("ɽ��", ({ "shan yang", "yang" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ�ɰ���Сɽ��\n");
        set("attitude", "peaceful");
	set("no_quest", 1);

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 10000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 400);

        setup();
}

/*void die()
{
        object ob;
        message_vision("$N���㡱һ�����ˡ�\n", this_object());
ob = new(__DIR__"pi");
        ob->move(environment(this_object()));
        destruct(this_object());
}*/

