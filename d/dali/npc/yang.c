// yang.c ���ϰ� 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("���ϰ�", ({ "zhao laoban", "zhao", "laoban"}));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"���ϰ������������Ĵ����ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
        set("unique", 1);
	set("combat_exp", 40000);
	set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":ARMOR_D("beixin"),"number":15]),
         }));
	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
