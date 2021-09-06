// jiang.c ������

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("������", ({ "jiang laifu", "jiang" ,"jianglaifu","laifu"}));
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
        set("long", "���������־�֪���������������ӻ����ϰ壬���ø��Ӳ��ߣ�������Ʋ���롣\n");
        set("combat_exp", 1500);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set("unique", 1);

	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set("vendor_goods", ({
		(["name":ARMOR_D("baopi"),"number":2]),
		(["name":ARMOR_D("qilinsuo"),"number":2]),
		(["name":ARMOR_D("liyududou"),"number":10]),
		(["name":ARMOR_D("yanling"),"number":10]),
		(["name":MISC_D("fire"),"number":10]),
		(["name":MISC_D("maotan"),"number":10]),
		(["name":FOOD_D("youcha"),"number":10])
        }));
	setup();
        carry_object(ARMOR_D("pipao"))->wear();
	add_money("silver", 10);
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
