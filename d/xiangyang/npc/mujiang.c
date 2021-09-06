//  mujiang.c

inherit NPC;
inherit F_VENDOR;

int do_order(string arg);
int my_sell(string arg);
int ask_price();

void create()
{
	set_name("ľ��", ({ "mu jiang", "mujiang", "mu", "jiang" }));
	set("shen_type", 1);

	set("gender", "����");
	set("age", 30);
	set("long", "��λľ��������ͷ��������Ϊ��������ע����������̧��ͷ��΢Ц��һ�¡�\n");
	set_skill("unarmed", 25);
	set_skill("dodge", 22);
	set_temp("apply/damage", 20);

	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("vendor_goods", ({
            (["name": BINGQI_D("mujian"),"number" : 500]),
            (["name": ("clone/gift/muchui"),"number" : 100]),
(["name": ("clone/armor/xinshouhuwan"),"number" : 200]),
	}));
	set("inquiry", ([
		"name": "�������ţ������Դ���˵�����Ƿ�Բ������������õ�ľ���ˡ�",
		"rumors": "����������̣�������඼�����ˡ��Һ��й������ڣ���Ȼ��������ˡ�",
		"here": "�����������ǣ��ɹű�һ��ϲ������������",
		"ľ��": "��ô����Ҳ�붩��(order)ľ��������Ҫ���˶࣬��Ǯ���ǲ���ѽ��",
		"������": "���ǹ���ѽ��������˶������Ϊ������",
		"����": "������˶������Ϊ������",
		"��Ǯ": (: ask_price :),
		"�۸�": (: ask_price :),
		"price": (: ask_price :),
	]) );
	setup();
        set("chat_chance", 5);
        set("chat_msg", ({
		"ľ������˵�����ɱ�С���˱��꣬�������ֵ�ʦ���Ƕ�Ҫ�����ﶩ��ľ���أ�\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_order", "order");
	add_action("do_order", "ding");
	add_action("my_sell", "sell");
}

int ask_price()
{
	object ob = this_player();
	int value, temp;

	if ((temp = ob->query_temp("muren_num")) >= 8) {
		command("say ���У�С��ɲ��Ǹ���һ���˿��ģ�");
		return 1;
	}
	value = (ob->query("combat_exp") / 100000 + 1) * 30;
	value = value + temp * value / 2;
	command("say ����ǿ͹��������Ļ�������" + chinese_number(value) + "�����Ӻ��ˡ�");
	return 1;
}

void muren_done(object ob)
{
	object muren;

	delete_temp("busy");
	if (objectp(ob)) {
		if (present(ob, environment())) {
			muren = new(__DIR__"muren");
			muren->set("owner", ob);
			muren->set("gender", ob->query("gender"));
			muren->set("name", ob->query("name") + "������ľ��");
			if (muren->move(ob)) {
				message_vision("ľ�������õ�ľ�˽�����$N��\n", ob);
			}
			else {
				muren->move(environment());
				message_vision("ľ�������õĸ�$N��ľ�˷ŵ��˵��ϡ�\n", ob);
			}
			ob->add_temp("muren_num", 1);
		}
		else {
			tell_object(ob, "��Ϊľ���Ҳ������ˣ����Զ�����ȡ���ˡ�\n");
		}
	}
}

int my_sell(string arg)
{
	object ob;
	object me = this_player();
    int value, improve;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (!arg || !(ob = present(arg, me)))
		return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");

	if (ob->query("no_drop"))
		return notify_fail("����������������\n");

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if (ob->query("material") != "wood")
                return notify_fail("Ӵ����Ǹ���������ֻ�չ��Ͼ�ľͷ�����Լ�������ľ�ˡ�\n");

	if (arg != "mutou" && !ob->id("mu ren"))
                return notify_fail("Ӵ����Ǹ���������ֻ�չ��Ͼ�ľͷ�����Լ�������ľ�ˡ�\n");

	if (ob->id("mu ren")) {
		if (ob->query("owner") != me)
                	return notify_fail("�ף������������������ﶩ����ľ��ѽ����\n");
		else {
			value = (me->query("combat_exp") / 100000 + 1) * 2000;
			me->add_temp("muren_num", -1);
		}
	}

	if (arg == "mutou") value = 1000;
	message_vision("$N������һ" + ob->query("unit") +
		ob->query("name") + "��$n��\n", me, this_object());
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	destruct(ob);
	return 1;
}

int do_order(string arg)
{
	object ob = this_player();
	int value, temp;

	if (arg == "muren" || arg == "ľ��") {
		message_vision("$N���ľ������һ��ľ�ˡ�\n", ob);
		if (query_temp("busy")) {
			message_vision("ľ����æ˵����Ӵ����Ǹ�����������æ���ء��������Ժ򡣡�\n", ob);
			return 1;
		}
		if ((temp = ob->query_temp("muren_num")) >= 8) {
			command("say ���У�С��ɲ��Ǹ���һ���˿��ģ�");
			return 1;
		}
		value = (ob->query("combat_exp") / 100000 + 1) * 3000;
		value = value + temp * value / 2;
		switch (MONEY_D->player_pay(ob, value)) {
			case 0:
				return notify_fail("����ľ��Ҫ" + chinese_number(value / 100) + "��������\n");
			case 2:
				return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
			default:
		        	set_temp("busy", 1);
				message_vision("ľ�����ͷ��˵������Ϳ�ʼ������Ȼ��Ϳ�ʼ��ͷ��ľ�ˡ�\n", ob);
			        remove_call_out("muren_done");
			        call_out("muren_done", 10 + random(10), ob);
		}
		return 1;
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��Ҫ���ȥ��ľ����һ�һû�뵽ľ��̧��ͷ������һ�ۣ�$Nֻ�þ�ɥ�����˻�����\n", ob);
}

void unconcious()
{
	say( "ľ�������ڻ�������һ������һ��ҩ�����������Ƭ��֮����ָֻ��˾���\n");
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

