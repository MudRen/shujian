// jinsq.c ��˿ȸ

inherit NPC;
void create()
{
        set_name("��˿ȸ", ({ "jinsi que", "bird" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�����Ľ�˿ȸ��ߴߴ�����Ľ��ţ������ö�������\n");
        set("attitude", "friendly");
        set("max_qi", 100);
        set("max_jing", 100);
        set("eff_jingli", 100);
        set("limbs", ({ "��", "���", "צ��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);
        set("chat_chance", 3);
        set("chat_msg", ({ (: random_move :),}) );
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5);
        set("senlin", 1);
        setup();
}

