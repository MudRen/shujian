// NPC: /d/huashan/npc/monkey.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
        set_name("����", ({ "hou zi" , "monkey", "hou" }));
	set("long","һ�������С���ӡ�\n");

	set("race", "Ұ��");
	set("age", 3);
	set("attitude", "friendly");

	set("max_ging", 80);
	set("max_qi", 80);

	set("str", 10);
	set("cor", 50);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	set("combat_exp", 1000);
	setup();
}
