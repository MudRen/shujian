// shangren.c ����

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "shang ren", "shang", "ren" }) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"��λ������Ц���������æ��������ʱ�к��Ź����Ŀ��ˡ�\n");
	set("combat_exp", 30000);
	set("attitude", "peaceful");
	set("rank_info/respect", "����");
	set("vendor_goods", ({
                (["name": __DIR__"obj/shengzi","number" : 3000]),
		(["name": MISC_D("fire"),"number" : 5]),
	}));
        setup();
	add_money("coin", 90);
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

