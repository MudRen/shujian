// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�°���", ({ "chen apo", "chen", "apo" }));
	set("title", "�ӻ����ϰ���");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "Ů��");
	set("age", 55);
	set("long",
		"�°��žþӸ��ݳǣ���˵������ʱ���м��ַ��ϣ������ھ�\n"
		"��ʱ������ͷ�����ϻ�׷�������\n");
	set("combat_exp", 280000);
	set("attitude", "friendly");
	set("inquiry", ([
                "������" : "���������ǿ����ǻ���һ�����������ţ�����\n",
                "name" : "�����ҷ���ճ¡����ְ�����\n",
                "here" : "�����Ǹ��ۿڣ����д����˺ܶࡣ\n",
	]));

	set("vendor_goods", ({
		(["name": "/d/fuzhou/npc/obj/xiuhua","number":5]),
		(["name": "/d/city/obj/flower_shoe","number":5]),
		(["name": "/d/city/obj/pink_cloth","number":5]),
		(["name":  "/d/city/obj/goldring","number":5]),
		(["name":   "/d/city/obj/necklace","number":5])
	}));

	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
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
		say("�°���Ц���е�˵�����˿�������\n");
		break;
	case 1 :
		say("�°���˵��������ģ���Ҫ��ʲ��\n");
		break;
	}
}
