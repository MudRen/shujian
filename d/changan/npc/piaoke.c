// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/piaoke.c

inherit NPC;

void create()
{
        set_name("�ο�", ({"piao ke", "ke" }) );
        set("gender", "����" );
        set("age", 35+random(15));
        set("long", "���Ǹ��ڳ������¥��Ѱ���������ο͡�\n");

	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set("combat_exp", 122000+random(50000));
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude","heroism");
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
		"�οʹ����µ��������������Ĺ����������ү���е���Ǯ����\n",
	}) );
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 50);
}
