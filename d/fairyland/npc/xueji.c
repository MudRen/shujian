// xueji.c

inherit NPC;

void create()
{
        set_name("ѩ��", ({"xue ji","ji"}));
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ�ʷʰװ׵�ѩ����\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);

	set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
       message_vision("$N�Һ�һ���������������ˣ�\n", this_object());
       new_ob("../obj/xueji-rou")->move(environment());
       destruct(this_object());
}
