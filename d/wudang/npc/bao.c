// NPC : /d/wudang/npc/bao.c ����

inherit NPC;
void create()
{
        set_name("����", ({ "bao zi","bao" }) );
        set("race", "Ұ��");
        set("age", 6);
        set("con", 100);
        set("str", 100);
        set("long", "һֻ�ײеĽ�Ǯ����\n");
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 250000);
	 set_temp("apply/attack", 120);
	 set_temp("apply/defense",150);
        set_temp("apply/damage", 120);
        set_temp("apply/armor", 100);
        setup();
}

