// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/dashou.c

inherit NPC;

void create()
{
        set_name("����", ({"da shou", "dashou" }) );
        set("gender", "����" );
        set("age", 27);
        set("long", "���ǳ������¥���õĴ��֣����ޱ��顣\n");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        setup();

        set("chat_chance", 2);
        set("chat_msg", ({
		"����˫��߬��һ�𣬽��ǽ���á�������ֱ�졣\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin",50);
}
