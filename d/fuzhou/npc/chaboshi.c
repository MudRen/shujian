// d/fuzhou/chaboshi.c �販ʿ
// Lklv 2001.9.8

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�販ʿ", ({ "cha boshi", "boshi" }));
	set("title", "����ϰ�");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 47);
	set("long",
		"����������ɫ������ɫ�Ͱ���\n");
	set("combat_exp", 100000+random(50000));
        set("attitude", "friendly");
	set("inquiry", ([
		"�ּ�" : "���Ǽҵ��ھ����ⲻ���������ʦ�������־�����������Ȳ衣\n",
		"����" : "�������ﶼ�ã����ǲ�Ҫȥ�Ƕ�������Ļ��Ӻ��ס�\n",
		"��" : "���Ǹ����Ĳ�Ҷ�ǲ�����Ʒ�����öೢһЩ���ǡ�\n",
		"��а����" : "�����������ҿɲ�֪����\n",
		"��ƽ֮" : "�⺢��������ʢ�����򱧲�ƽ��\n",
		"������" : "������ͷ������Ǻ������ˣ�������������ʲô�¡�\n",
		"here" : "�����Ǹ��������ĳ�����¥����ǰ�����Ӿ��ǳ���������ҹվ͵��������ˡ�\n",
		"rumors" : "��˵����������˲��ٱ��������ĺ��ӣ����������ǽ����ϻ�ġ�\n",
		"rumor" : "�������Ұ�����ҥ�����������й��򰡣��ҿ�������Ъ��ɡ�\n",
		"job" : "�����Ҵ����˰ɣ���\n",
		"cha boshi" : "�販ʿ�����Ұ���\n",
		"laoban" : "������ϰ�����ҡ�\n",
		"�Ȳ�" : "����Ȳ��Ұﵹ���ǵý�Ǯ�����ˣ��׿�ˮ���ȡ�\n",
		"������ͷ" : "����������ͷ������ǿ���˵�����˲�֪���˲�����\n",
		"�ھ�" : "��������գ������ҹ����Σ��͵��ˡ�\n",
		"�ӻ���" : "����˵ԭ��������ڵ��ӻ��̰�������ˣ��ᵽ�����ӱ��ߡ�\n",
		"��¥" : "�����¥�����汲�������ģ��ھ��Ǿ������Ȳ衣\n",
		"��ɽ" : "�����ţ�һֱ�ߣ�Ȼ�������ߵĲ�·��\n",
		"��Ҷ" : "�Բ���С�겻����Ҷ����Ҫ�ȣ�����������Ȱɡ�\n",
		"����ͷ" : "ƽ֮�⺢��������ʢ�����򱧲�ƽ��\n",
		"�����ھ�" : "�ּҴ����������ھ֣��ڸ���һ����ͷһֱ����ġ�\n",
		"name" : "�����շ�������������Ҷ�ϰ�߽��Ҳ販ʿ�����Ǽҿ���������ϻ���\n",
		"..." : "���л���ʹ��˵��\n",

	]));

	set("vendor_goods", ({
		(["name":FOOD_D("peanut"),"number":10]),
		(["name":FOOD_D("tea"),"number":20]),
	}));

	setup();
	add_money("silver", 20+random(10));
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
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
        say("�販ʿЦ���е�˵��������������λ" + RANK_D->query_respect(ob) +
                        "�����ȱ��衣\n");
                break;
        case 1 :
        say("�販ʿ˵����Ӵ����λ" + RANK_D->query_respect(ob) +
                        "�����˰����þò����������ô�������Ȳ��ˣ�\n");
                break;
        }
}
