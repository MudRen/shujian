//  mafu.c

inherit NPC;

void create()
{
	set_name("�����", ({ "ma fuzi", "ma" ,"fuzi"}));
	set("title", "���ϰ�");
	set("long","����ӱ�����£���Ϊ����������Ҷ���������ӡ�\n");
	set("shen_type", 1);
	set("unique", 1);

	set("gender", "����");
	set("age", 45);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	
	setup();
}
/*
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
*/