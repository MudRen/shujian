// dclaoban.c �ĳ��ϰ�

inherit NPC;

void create()
{
        set_name("�ĳ��ϰ�", ({ "lao ban", "laoban" }));
        set("shen_type", 0);
        set("gender", "����");
        set("age", 42);
        set("long", "����������һ����Ʊ�����ڷ����š�\n");
        set("no_get_from", 1);
        set("no_get", 1);
        set("no_bark", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 200000);
        set("attitude", "friendly");

        setup();
        carry_object(ARMOR_D("changshan3"))->wear();
        carry_object(ARMOR_D("ryyaodai"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

