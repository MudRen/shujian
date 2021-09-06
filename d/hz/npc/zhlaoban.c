// yang.c ���ϰ� 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("���ϰ�", ({ "li laoban", "li" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long", "���ϰ������������ĺ����ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		(["name": BINGQI_D("changjian"), "number":10]),
		(["name": BINGQI_D("gangdao") , "number":15]),
		(["name": MISC_D("mabudai"), "number":15]),
		(["name": ARMOR_D("beixin"), "number":20]),
		(["name": MISC_D("fire"), "number":15]),
		(["name": BINGQI_D("zhubang"), "number":25])
        }));
        setup();
        carry_object(ARMOR_D("jinduan"))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
