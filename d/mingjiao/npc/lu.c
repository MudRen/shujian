// lu.c
inherit NPC;
void create()
{
        set_name("÷��¹", ({ "meihua lu", "lu" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��˳�ɰ���÷��¹��\n");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 1000);
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10);
        setup();
}
