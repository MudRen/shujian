// Write By Yanyang@SJ 2001.10.2
// NPC: /d/changan/tuchang.c

inherit NPC;

void create()
{
        set_name("���", ({"tu chang", "tuchang","girl" }) );
        set("gender", "Ů��" );
        set("age", random(20)+15);
        set("long", "\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 2000);
        set("str", 20);
        set("dex", 30);
        set("con", 10);
        set("int", 10);
        set("attitude","heroism");
        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
                "���������һ�ۣ�˵�������������в��У��������Ǳ������ˣ�\n",
                "���������������ҿɲ������¥������Ƕ��\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 100);
}