// shanyang.c

inherit NPC;

void create()
{
        set_name("Ұɽ��", ({"shan yang", "yang"}));
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��˳�ɰ���Ұɽ��\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
       message_vision("$N�Һ�һ���������������ˣ�\n", this_object());
       new_ob("../obj/yang-rou")->move(environment());
       destruct(this_object());
}
