// xiong.c
inherit NPC;
void create()
{
        set_name("�����", ({ "xiong" }) );
        set("race", "Ұ��");
        set("age", 6);
        set("con", 100);
        set("str", 100);
        set("long", "һֻë����ޣ�״�����ţ�Ĵ���ܡ�\n");
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 250000);
      	set("chat_chance", 6);
      	set("chat_msg", ({
              (: random_move :),
      	}) );
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        setup();
}
void die()
{
       message_vision("\n$N�Һ�һ���������������ˣ�\n", this_object());
       new(FOOD_D("xzhang"))->move(environment(this_object()));
       new(ARMOR_D("xiongpi"))->move(environment(this_object()));
       destruct(this_object());
}
