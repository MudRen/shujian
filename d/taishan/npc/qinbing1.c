// qinbing1.c �ױ�

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ױ�", ({ "qin bing", "qinbing", "bing"}) );
        set("gender", "����");
        set("age", 40);
        set("long", "�����ǵ�������ͨ�����ױ�, �������ף���ִ�ֽ���\n");

        set("combat_exp", 300000);
        set("attitude", "heroism");
        set("unique", 6);

        set("str", 25);
        set("con", 20);
        set("int", 20);
        set("dex", 20);

        set("max_qi", 700);
        set("eff_qi", 700);
        set("qi", 700);
        set("max_jing", 300);
        set("jing", 300);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 40);

        set_temp("apply/attack",  40);
        set_temp("apply/defense", 40);

        set_skill("sword", 140);
        set_skill("unarmed", 140);
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set("chat_chance", 10);

        setup();

        carry_object(BINGQI_D("gangjian"))->wield();
        carry_object(ARMOR_D("armor"))->wear();
}
