// yaochang-zhu
// by augx@sj  3/4/2002

#include <ansi.h>
inherit NPC;

string ask_job();
string ask_fail();

nosave string yaocai_path = "/d/zhiye/obj/yaocai";

void add_yaocai(object yaocai)
{
	add("vendor_goods", ({
		([	"name"	: yaocai_path,
			"number": 99,
			"type"	: yaocai->query("oid"),
			"short"	: yaocai->short(),
			"value"	: yaocai->query("value"),
			"id"	: yaocai->query("id"),
			"lvl"	: yaocai->query("need_lvl")+50+random(50),
		]),
	}));
}

void create()
{
	object yaocai;

	set_name("��������",({ "zuofang zhuren","zhuren" }) );
	set("gender", "����" );
	set("age", 41);
	set("long","��λ�������ҩ���������ˣ��ڴ�����ҩ�Ķ����ˡ�\n");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
	set_skill("tilian", 60);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 1);
 	set("chat_msg", ({
 		CYN"�������˳�ü������˵���������ҩ������ɲ�����������\n"NOR,
 		CYN"��������˵����������Ҫѧ����ҩ�ĵļ����𣿡�\n"NOR,
 	}) );

	set("vendor_goods", ({ }));

	// add yaocai shengcai
	yaocai = new(yaocai_path); yaocai->set_type("bai wei");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("he ye");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("ju geng");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("mu gua");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("sang ye");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("tian qi");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("zhu ye");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("xiong huang");
	add_yaocai(yaocai); destruct(yaocai);

	yaocai = new(yaocai_path); yaocai->set_type("bai zhi");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("chai hu");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("fang feng");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("gou qi");
	add_yaocai(yaocai); destruct(yaocai);

	yaocai = new(yaocai_path); yaocai->set_type("chan tui");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("chuan bei");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("dang gui");
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("fu ling");
	add_yaocai(yaocai); destruct(yaocai);

	// add yaocai
	yaocai = new(yaocai_path); yaocai->set_type("bai wei"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("he ye"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("ju geng"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("mu gua"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("sang ye"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("tian qi"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("zhu ye"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("xiong huang"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);

	yaocai = new(yaocai_path); yaocai->set_type("bai zhi"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("chai hu"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("fang feng"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("gou qi"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);

	yaocai = new(yaocai_path); yaocai->set_type("chan tui"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("chuan bei"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("dang gui"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);
	yaocai = new(yaocai_path); yaocai->set_type("fu ling"); yaocai->change_state();
	add_yaocai(yaocai); destruct(yaocai);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/yaochui")->wield();
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say �Һ�����Թ�޳�Ϊ��Ҫ���ң�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say �Һ�����Թ�޳�Ϊ��Ҫ���ң�");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
}

int prevent_learn(object ob, string skill)
{
	if (skill == "tilian") return 0; else return 1;
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 125, level = ob->query_skill("tilian", 1);

	if (level > 9) money = 250;
	if (level > 19) money = 500;
	if (level > 29) money = 1000;
	if (level > 49) money = 2000;

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"�����ڵ�ѧ����ÿ��"+MONEY_D->money_str(money)+"�����Ǯ������\n" ); return 0;
	}
	return 1;
}

////////////////////////////////////////////////////////////////////
int query_goods_value(int value , int number , string sid)
{
	object me = this_player();
	int trade_level;
	int cur;

	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (115 - trade_level) / 100;

	cur = query_temp("vendor_goods/"+sid);
	if( cur != number )
		value += value/6 * cur/number;

	return value;
}

string is_vendor_good(string arg)
{
	mapping *goods;
	int i;

	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			if( goods[i]["id"]==arg && goods[i]["number"]!=query_temp("vendor_goods/"+goods[i]["id"]) )
				return goods[i]["name"];
	return "";
}

void reset()
{
	this_object()->delete_temp("vendor_goods");
}

int do_list(string arg)
{
	mapping *goods;
	int i;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");

	if (arrayp(goods = query("vendor_goods")))
	{
		write(query("name") + "Ŀǰ�������»��\n");
                write("��������������������������������������������������������������������������������\n");
		write("��  ��  ��                          ��  ��                          ���/���� ��\n");
		write("�ǩ�����������������������������������������������������������������������������\n");
		for (i = 0; i < sizeof(goods); i++)
			write(sprintf("��%-30s%-36s%4d/%4d ��\n", goods[i]["short"],
				MONEY_D->price_str(query_goods_value(goods[i]["value"],goods[i]["number"],goods[i]["id"])),
				goods[i]["number"]-query_temp("vendor_goods/"+goods[i]["id"]),
				goods[i]["number"])
			);
		write("��������������������������������������������������������������������������������\n");
		return 1;
	}
}

int do_buy(string arg)
{
	int i,j,improve;
	string ob_file;
	object ob;
	object me = this_player();
	mapping goods;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");
	if (!arg) return notify_fail("������ʲô��\n");
	if ((ob_file = is_vendor_good(arg)) == "")
		return notify_fail("������Ķ���������û�С�\n");

	goods = query("vendor_goods");
	for(i=0;i<sizeof(goods);i++)
		if(goods[i]["id"]==arg) break;

	ob = new(ob_file);
	ob->set_type(goods[i]["type"]);
	if( strsrch(arg,"shengcai",1) < 0 ) {
		ob->change_state();
		ob->set_level(me->query_skill("liandan",1));
	}
	else {
		ob->set_level(me->query_skill("tilian",1));
	}

	switch(MONEY_D->player_pay(me,j = query_goods_value(goods[i]["value"],goods[i]["number"],goods[i]["id"]))) {
	case 0:
		destruct(ob);
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		destruct(ob);
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		if (!ob->move(me)) {
			destruct(ob);
			return 0;
		}
		message_vision("$N��"+MONEY_D->price_str(j)+"�ļ۸��$n����������һ" + ob->query("unit") + ob->name() + "��\n", me, this_object());
		improve = 40 - me->query("pur");
		me->improve_skill("trade", improve + random(improve));
		add_temp("vendor_goods/"+goods[i]["id"],1);
	}
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}


int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 10) trade_level = 10;
	value = value * (80 + trade_level) / 100;

	return value;
}

int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, improve;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (!arg || !(ob = present(arg, me)))
		return notify_fail("��Ҫ��ʲô��\n");
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	if ( !(int)ob->query("shengcai") && !(int)ob->query("yaocai") )
		return notify_fail("��ֻ�չ�ҩ�ġ�\n");

	value = query_goods_value2(ob);
	message_vision("$N��"+MONEY_D->price_str(value)+"�ļ۸�������һ"+ob->query("unit")+ob->name() + "��$n��\n", me, this_object());
	destruct(ob);
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}
