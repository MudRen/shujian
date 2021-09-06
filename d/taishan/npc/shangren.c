// yang.c ���ϰ� 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "shang ren", "ren" }));
        set("shen_type", 1);
        set("gender", "����");
        set("age", 45);
        set("long",
                "�����ĺ����أ����⸽�����˼�������⣬Ҳû׬������Ǯ��\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
		(["name": MEDICINE_D("yangjing"),"number": 10]),
		(["name": MISC_D("fire"),"number": 5]),
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
