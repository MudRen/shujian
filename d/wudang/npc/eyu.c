// animal: eyu.c

inherit NPC;

void create()
{
        set_name("����", ({"eyu","e yu"}));
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һ���ſ�Ѫ���ڵ����㡣\n");
        set("attitude", "aggressive");

        set("str", 35);
        set("con", 35);

        set("limbs", ({ "ͷ��", "����", "�Ų�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 500000);

        set_temp("apply/attack", 550);
        set_temp("apply/damage", 550);
        set_temp("apply/armor", 700);


        setup();
}

void die()
{
        object ob;
        message_vision("$N�鴤�˼��£���������һ�����ˡ�\n", this_object());
        ob = new("/d/wudang/obj/luohan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
