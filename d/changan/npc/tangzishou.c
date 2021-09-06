// Write By Yanyang@SJ 2001.9.28
// NPC: /d/changan/tangzishou.c

inherit NPC;

void create()
{
        set_name("������", ({"tangzi shou", "shou" }) );
        set("gender", "����" );
        set("age", 24);
        set("long", "�����ھ���������֡�\n");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 5000);
        set("str", 30);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude","heroism");
        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver", 10);
}
