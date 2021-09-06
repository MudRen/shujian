//  mujiang.c

inherit NPC;
inherit F_VENDOR;


void create()
{
	set_name("许老板", ({ "xu laoban", "laoban", "xu" }));
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 30);
	set("long", "许老板三十来岁，身材魁梧，手掌上厚厚的一层茧子。\n");
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
		"name": "在下姓许，本店武器全是千锤百炼的精品，这位英雄何不仔细看看?",
		"rumors": "这里连年打仗，百姓许多都出走了。幸好有郭大侠在，不然早就沦陷了。",
		"here": "这里是襄阳城，蒙古兵一般喜欢秋天来攻打。",
		"郭大侠": "就是郭靖呀，这里的人都尊称他为大侠。",
		"郭靖": "这里的人都尊称他为大侠。",
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
        message_vision("许老板对你撇了撇嘴角。\n许老板挽起袖子，手臂上赫然是一排黑漆漆的手弩。\n许老板又从兜兜里掏出一把蓝莹莹的铁蒺藜，随手掂了掂。\n许老板说道：“这位英雄，你还是不要乱开玩笑的好。”\n", ob);
}

void unconcious()
{
	say( "许老板伸手在怀里摸了一阵，摸出一粒药丸来塞在嘴里，片刻之间就又恢复了精神。\n");
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

