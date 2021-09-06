// hu.c ����

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "hu gui", "hu" ,"hugui","gui"}));
        set("title", "�վƺ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
        set("long", "��������¥���ϰ壬��Ϊ������պã�������������ºš�\n");
        set("combat_exp", 2000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set("unique", 1);

	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set("vendor_goods", ({
([ "name":FOOD_D("shaojiu"),"number":20]),
([ "name":FOOD_D("roubing"),"number":40])
        }));

	setup();
        add_money("silver", 50);
        carry_object(ARMOR_D("pipao"))->wear();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
