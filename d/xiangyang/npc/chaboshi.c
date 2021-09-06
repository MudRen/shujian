// d/fuzhou/chaboshi.c �販ʿ
// Lklv 2001.9.25

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
        set("env/wimpy", 50);
        set("chat_chance", 5);
        set("chat_msg", ({
                "�販ʿ������˵�ͷ��΢΢��Ц��Ц��\n",
        }) );
	set("inquiry", ([
		"����" : "�����������������Ҳ�¥��󣬵ش���ͨҪ�����������ǲ���\n",
		"����" : "����ǰ�����ͻ�Ů����������Ȳ衣��\n",
		"��" : "��������Ĳ�Ҷ�ǴӸ��������ģ�ȫ���ǲ��м�Ʒ�����öೢһЩ��\n",
		"������" : "���С�ӣ���ǰ���컹�ڶĳ�����������\n",
		"���ɩ" : "�����ǣ������ʱ�������������С���ӡ�\n",
		"�ٱ�" : "�ꡭ����Ҫ˵�����С�����㵱�ɹż��ץ��ȥ��\n",
		"here" : "���������������ĳǱ���¥����ǰ�Ǳ��֣������ҹ�������и���̨��\n",
		"rumors" : "��˵����������˲��ٱ��������ĺ��ӣ����������ǽ����ϻ�ġ�\n",
		"rumor" : "�������Ұ�����ҥ�����������й��򰡣��ҿ�������Ъ��ɡ�\n",
		"job" : "�����Ҵ����˰ɣ���\n",
		"cha boshi" : "�販ʿ�����Ұ���\n",
		"laoban" : "������ϰ�����ҡ�\n",
		"�Ȳ�" : "����Ȳ��Ұﵹ���ǵý�Ǯ�����ˣ��׿�ˮ���ȡ�\n",
		"��Ҷ" : "�١�������Ҫ���Ҷ����Ҫ��裿���ǵĲ�Ҷ�����\n",
		"tea" : "����Ϊ˵�����ҾͲ������������ǲ�������������ӣ�\n",
		"��¥" : "�����¥�����汲�������ģ��ھ��Ǿ������Ȳ衣\n",
		"�䵱" : "�����ţ�һֱ�ߣ�Ȼ�������ߵĲ�·������ˮ����\n",
		"����" : "�����ţ�һֱ�ߣ�Ȼ���߶�������������Ȼ�󡭡�\n",
		"��ɽ" : "˵��ɽ��ȥ�����ڻ�ɽ������һλ����������Ǯ������ͯ�����ۡ���\n",
		"name" : "�����հ�������������Ҷ�ϰ�߽��Ҳ販ʿ��\n",
		"����" : "�������Ұ������л���˵��㲻˵����ô֪���ء�\n",
	]));

	set("vendor_goods", ({
		(["name":FOOD_D("peanut"),"number":10]),
		(["name":FOOD_D("tea"),"number":20]),
	}));

	setup();
	add_money("silver", 20+random(10));
        carry_object(ARMOR_D("changshan2"))->wear();
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
                        "�����˰�������룡����룡\n");
                break;
        }
}
