// maoniu.c ��ţ

inherit NPC;

void create()
{
        set_name("��ţ", ({ "mao niu", "niu" ,"yak"}) );
	set("race", "Ұ��");
	set("age", 5);
        set("long", "һֻ��ǿ��׳����ţ��ȫ���ų�ë���ƺ�����ʳ��\n");
	set("attitude", "peaceful");
        set("str",60);
        set("max_qi",1000);
        set("qi",1000);
        set("max_jing",1000);
        set("jing",1000);
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "kick", "hoof" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 120);
        set_temp("apply/armor", 100);

	setup();
}

