// boshi.c �販ʿ
// by pishou

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("�販ʿ", ({ "cha boshi", "boshi" }));
    set("title", "����ϰ�");
    set("nickname", "��״Ԫ");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 45);
	set("long",
	"���Ǵ�����������Ĳ販ʿ, �ʳƲ�״Ԫ��\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
        "С��" : "��ȥ�����ˡ��ó�ʱ��û�м�������, �������ġ�\n",
        "ΤС��" : "������𣬾�������ǰ�����Ľ��ҡ�\n",
        "��" : "���г�״Ԫ������Ҳ�Ǹ�״Ԫ, �������ǹ�������״Ԫ��\n",
	]));
	
	set("vendor_goods", ({
        (["name":__DIR__"obj/peanut","number":30]),
        (["name":__DIR__"obj/tofu","number":30]),
	}));

	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting() && !wizardp(ob)) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
        say("�販ʿЦ���е�˵������λ" + RANK_D->query_respect(ob) +
			"����������ȱ��Ȳ衣\n");
		break;
	case 1 :
        say("�販ʿ˵����Ӵ����λ" + RANK_D->query_respect(ob) +
			"�����˰��������и�ը�õ����㻨�����ۡ�\n");
		break;
	}
}
