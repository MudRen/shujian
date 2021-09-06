// sa.c ���ϰ�

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ϰ�", ({ "sa laoban", "sa", "laoban" }) );
        set("gender", "����" );
        set("age", 24);
        set("long",
                "���ϰ���Ц����ؿ����㡣\n");
        set("combat_exp", 25800+random(5800));
        set("no_get",1);
        set("attitude", "friendly");
        set("rank_info/respect", "���");
        set("vendor_goods", ({
		(["name":FOOD_D("jiudai"),"number":10]),
		(["name":FOOD_D("hdjiudai"),"number":10]),
		(["name":FOOD_D("jitui"),"number":10]),
		(["name":__DIR__"obj/yadan","number":10]),
		(["name":__DIR__"obj/zongzi","number":10]),
	}));
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
