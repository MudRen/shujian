// hudie.c

inherit NPC;

void create()
{
        set_name("����", ({ "hudie"}) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ������ɫ�ĺ�����ʮ�ֿɰ����Ǻ�������Ʒ��\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);
    
	set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 10);

        setup();
}
