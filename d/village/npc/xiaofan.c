// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("С��", ({ "xiao fan" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
        	 (["name": __DIR__"obj/stick" ,"number":25]),
        	 (["name": __DIR__"obj/shoes" ,"number":15]),
        	 (["name": __DIR__"obj/bottle" ,"number":15]),
        	 (["name": __DIR__"obj/egg" ,"number":20]),
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 100);
}

void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
