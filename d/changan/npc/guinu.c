// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/guinu.c

inherit NPC;

void create()
{
        set_name("��ū", ({"gui nu", "guinu" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "���ǳ������¥��Ĺ�ū���������ܾ����ܸɡ�\n");

        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("combat_exp", 5000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
		"��ū�е�����¥��¥�µĹ����ǣ�������ӿ�������\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",50);
}
