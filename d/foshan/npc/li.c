//li.c ���ϰ� 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("���ϰ�", ({ "li", "laoban" }));
	set("long",
		"���ϰ������ڵ��������������������ˡ�\n");
	set("title", "�ӻ����ϰ�");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen", 2000);

	set("str", 18);
        set("int", 25);
        set("con", 18);
        set("dex", 21);

	set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);

        set("jingli",400);
        set("eff_jingli",400);
        set("jiali", 1);   
	set("combat_exp", 2000);

        set("vendor_goods", ({
            (["name": "/d/foshan/obj/xiwan","number" : 10]),
            (["name": "/d/foshan/obj/xihu","number" : 10]),
            (["name": "/d/foshan/obj/xipen","number" : 10]),
            (["name": "/d/foshan/obj/tidao","number" : 10]),
            (["name": MISC_D("fire"),"number" : 10]),
        }));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
