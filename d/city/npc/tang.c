// tang.c ���ϰ� 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("�����ϰ�", ({ "lao ban", "laoban" }));
	set("shen_type", 0);
        set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"�����ϰ����ڶ����㿴����ȥ��\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}
