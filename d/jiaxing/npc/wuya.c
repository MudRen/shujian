// Jay 5/23/96

inherit NPC;

void create()
{
        set_name("��ѻ", ({ "wu ya", "wuya",  "craw" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ��ɫ����ѻ����ª���ˡ�\n");
        set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        setup();

	set("race", "����");
	set("chat_chance", 2);
        set("chat_msg", ({
		"��ѻ���¸¡����˼�����\n",
		"��ѻ�е������¸¡���\n",
                "��ѻ����ǰ���Ϸ��¡�\n",
        }) );
}
