// NPC : /d/wudang/npc/monkey.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "hou zi", "hou", "monkey" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻ�ɰ�����Ƥ��С���ӡ�\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 5);

	setup();
}

