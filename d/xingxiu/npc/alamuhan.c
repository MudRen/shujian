// npc: /d/xingxiu/npc/alamuhan.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����ľ��", ({ "alamuhan", "ala", "muhan" }));
	set("long", "����β���Ҳ���ݡ�����üë�����£������۾��ܶ��顣\n");
	set("title", "�������");
	set("gender", "Ů��");
	set("age", 17);

	set_skill("unarmed", 20);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("whip", 30);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("vendor_goods", ({
		(["name":"/d/xingxiu/obj/yangrou","number":20]),
		(["name":"/d/xingxiu/obj/nang","number":20]),
		(["name":"/d/xingxiu/obj/hamigua","number":20]),
	}));

        set("combat_exp", 5000);
        set("attitude","friendly");

        setup();
        carry_object(BINGQI_D("changbian"))->wield();
        carry_object(ARMOR_D("wcloth"))->wear();
}

void init()
{
	object ob;
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "����ľ��Ц������˵����ɫ��ķ����ա�\n");
			break;
		case 1:
			say( "����ľ��ǳ��һ��˵���������ɫ��ķ��\n");
			break;
	}
}
