// animal: hudie.c

inherit NPC;

void create()
{
        set_name("����", ({ "hu die", "hu" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�����ĺ��������������㲻����Щ���ˡ�\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ǰצ","��","��צ","���" }));
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        setup();
}

void die()
{
        message_vision("$N�����Ʈ���ڵ��棡$N������Ϣ�����ˡ�\n", this_object());
        destruct(this_object());
}
