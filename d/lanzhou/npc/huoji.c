// huoji. ҩ�̻��

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���", ({ "huoji" }));
        set("str", 20);
        set("gender", "����");
        set("per", 18);
        set("age", 18);
        set("long", "��������Ļ�ƣ����ڵ���æ��æ�⡣\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
		(["name":MEDICINE_D("jinchuang"),"number": 25]),
	}));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

