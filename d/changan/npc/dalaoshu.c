// Write By Yanyang@SJ 2001.10.2
// Animal : /d/changan/npc/dalaoshu.c

inherit NPC;

void create()
{
        set_name("������", ({ "da laoshu", "laoshu", "mouse" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("unique", 2);
        set("long", "һֻ�ַ��ִ�����󣬿�����͵���˲�����ʳ��\n");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 1000);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 30);

        setup();

}

