// NPC zhangqian.c ��ǧ

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��ǧ", ({ "zhang qian", "zhang","qian" }));
	set("title", "��ζ���ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long","��λ�ϰ���æ����ͷ�󺹡�\n");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/damage", 25);
        set("unique", 1);

	set("combat_exp", 8000);
	set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":__DIR__"obj/baozi1","number":20]),
        (["name":__DIR__"obj/yang","number":20]),
        (["name":__DIR__"obj/chaoshou","number":20]),
        (["name":__DIR__"obj/mo","number":15]),
        }));
	
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
