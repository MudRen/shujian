// npc: /d/xingxiu/herdsman.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("����Ů", ({ "muyang nu", "nu", "muyang" }));
        set("gender", "Ů��");
        set("age", 18 + random(5));
        set("long", "һ��ά�����Ů����\n");
        set("attitude", "friendly");
        set("env/wimpy", 80);
        set("combat_exp", 500);

        set_skill("unarmed", 5);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("whip", 15);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("inquiry", ([
               "������" : "���Ƕ������޺���",
               "���޺�" : "���޺����Ǳ��߷�Բ������ĺ���������ء�\n",
        ]) );

        setup();
        carry_object(BINGQI_D("bian"))->wield();
        carry_object(ARMOR_D("wncloth"))->wear();
}

