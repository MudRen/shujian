//  mujiang.c

inherit NPC;
inherit F_VENDOR;


void create()
{
	set_name("���ϰ�", ({ "xu laoban", "laoban", "xu" }));
	set("shen_type", 1);

	set("gender", "����");
	set("age", 30);
	set("long", "���ϰ���ʮ���꣬��Ŀ��࣬�����Ϻ���һ����ӡ�\n");
	set_skill("unarmed", 25);
	set_skill("dodge", 22);
	set_temp("apply/damage", 20);

	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("vendor_goods", ({
            (["name": BINGQI_D("bqsnow_sword"),      "number" : 50]),
            (["name": BINGQI_D("bqwhip"),              "number" : 100]),
            (["name": BINGQI_D("bqjinhua"),            "number" : 100]),
            (["name": BINGQI_D("bqzhubang"),           "number" : 100]),
            (["name": BINGQI_D("bqyuxiao"),           "number" : 100]),
            (["name": BINGQI_D("bqdanrenbi"),          "number" : 100]),
            (["name": BINGQI_D("bqchui"),              "number" : 100]),
            (["name": BINGQI_D("bqclub"),              "number" : 100]),
            (["name": BINGQI_D("bqdafu"),              "number" : 100]),
            (["name": BINGQI_D("bqhammer"),            "number" : 100]),
            (["name": BINGQI_D("bqhongying-qiang"),    "number" : 100]),
            (["name": BINGQI_D("bqhushou-gou"),        "number" : 100]),
            (["name": BINGQI_D("bqjianxia"),           "number" : 2]),
            (["name": BINGQI_D("bqzhen1"),             "number" : 20]),
            (["name": BINGQI_D("bqxuesui"),            "number" : 20]),
            (["name": BINGQI_D("bqsm_ding"),           "number" : 100]),
            (["name": BINGQI_D("bqpanguanbi"),         "number" : 100]),
            (["name": BINGQI_D("bqyinshesword"),         "number" : 120]),
            (["name": BINGQI_D("bqstaff"),         "number" : 20]),
           (["name": BINGQI_D("bqtieling"),         "number" : 200]),
/*
            (["name": ("xinyuedao"),"number" : 100]),
            (["name": ("xinyuedao"),"number" : 100]),
            (["name": ("xinyuedao"),"number" : 100]),
            (["name": ("xinyuedao"),"number" : 100]),
            (["name": ("xinyuedao"),"number" : 100]),
            (["name": ("xinyuedao"),"number" : 100]),
*/
	}));
	set("inquiry", ([
		"name": "����������������ȫ��ǧ�������ľ�Ʒ����λӢ�ۺβ���ϸ����?",
		"rumors": "����������̣�������඼�����ˡ��Һ��й������ڣ���Ȼ��������ˡ�",
		"here": "�����������ǣ��ɹű�һ��ϲ������������",
		"������": "���ǹ���ѽ��������˶������Ϊ������",
		"����": "������˶������Ϊ������",
	]) );
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");

}


void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
        message_vision("���ϰ����Ʋ��Ʋ��ǡ�\n���ϰ��������ӣ��ֱ��Ϻ�Ȼ��һ�ź����������\n���ϰ��ִӶ������ͳ�һ����ӨӨ������޼�����ֵ��˵ࡣ\n���ϰ�˵��������λӢ�ۣ��㻹�ǲ�Ҫ�ҿ���Ц�ĺá���\n", ob);
}

void unconcious()
{
	say( "���ϰ������ڻ�������һ������һ��ҩ�����������Ƭ��֮����ָֻ��˾���\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

