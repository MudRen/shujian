// duke.c

inherit NPC;

void create()
{
        set_name("����Ŀ�", ({"dali duke", "duke" }) );
        set("gender", "����" );
        set("age", 35);
        set("long", "���Ǹ��������õĴ���Ŀ͡�\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 1000);
	set("shen_type", 0);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
		"�Ŀ������Ϳڴ�����������ͭ������\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
}

