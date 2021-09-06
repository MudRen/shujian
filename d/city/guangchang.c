// Room: /d/city/guangchang.c

inherit ROOM;

int do_zhai(string arg);
int do_shake(string arg);
int do_strike(string arg);
int do_sling(string arg);
int do_climb(string arg);

void create()
{
	set("short", "����㳡");
	set("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ���
���������������������������������ݡ�����Կ������ߺ��ϱ��Ǽ���
��ĵ��̣�����ȫ�����ص����������������������������ر�Ӫ������������
����Ѳ�����ŵ����ڡ��㳡������һ��������(tree)���Ե�ʮ�ֵĴ�׳������
����Ҷ(leaf)�ǳ�ï�ܣ��м�ֻ��֪����С�������д�����ȥ�������Ա���һ
������������(sign)��
LONG
	);
        set("no_sleep_room", 1);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"guangchangdong",
		"south" : __DIR__"guangchangnan",
		"west" : __DIR__"guangchangxi",
		"north" : __DIR__"guangchangbei",
	]));

	set("item_desc", ([
		"tree" : "һ�ô�����֦Ҷï�ܣ�����������������֦ͷ���������ӣ��Ѿ����Ҫ�������ˡ�\n",
		"leaf" : "��Ҷ���ɵع������ϣ�����ȥ�������ժ������\n",
		"sign" : "�밮��������ľ������������ط���    --���ݸ���ʾ\n",
	]) );
	set("objects", ([
		__DIR__"npc/xunbu" : 1,
		__DIR__"npc/gongzi" : 1,
		__DIR__"npc/yiren" : 1,
		__DIR__"npc/parrot" : 1,
   //             __DIR__"npc/huangdaxian" : 1,
	]));
	set("stick_count", 5);
	set("peach_count", 30);

	set("incity",1);
	setup();
}

void init()
{
	object room;

	add_action("do_sling", "sling");
	add_action("do_sling", "tan");
	add_action("do_sling", "shoot");
	add_action("do_sling", "she");
	add_action("do_shake", "shake");
	add_action("do_shake", "wave");
	add_action("do_shake", "yao");
	add_action("do_shake", "huang");
	add_action("do_strike", "strike");
	add_action("do_strike", "press");
	add_action("do_strike", "hit");
	add_action("do_strike", "pai");
	add_action("do_strike", "ji");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_zhai", "zhai");
       add_action("do_jump", "jump");
	if (!wizardp(this_player()) && room = find_object(__DIR__"shushang"))
		tell_room(room, "͸����Ҷ�ķ�϶���㿴��" + this_player()->name() + "���������¡�\n");
}
int do_jump(string arg)
{
	object me = this_player();

	if (arg != "up")
		return notify_fail("��Ҫ���찡��\n");
       if (me->query_condition("killer"))
              return notify_fail("�㻹�����˽��꽭����Թ�ɣ�\n");
	message_vision("$N����һԽ��wo kao,��������\n", me);
	me->move("adm/daemons/huanjing2003/room_door_hj");
	return 1;
}

int do_zhai(string arg)
{
	object me = this_player();

	if (arg != "leaf" && arg != "shuye" && arg != "ye")
		return notify_fail("��Ҫժʲô��\n");

	message_vision("$N����ȥ�����ϵ�Ҷ�ӣ������ֱ���Ҫ�ٳ���ʮ�߲��У�\n", me);
	return 1;
}

int do_sling(string arg)
{
	object weapon, room, xunbu, money_ob, *ob;
	object me = this_player();
	int i, qi, level, jinglicost, topay, temp;
	string weapon_name, money_str = "";

	if (arg != "leaf" && arg != "shuye" && arg != "ye")
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	weapon = me->query_temp("weapon");
	if (!weapon) {
		message_vision("$N�������ϵ�Ҷ���������ֱ�������ͼ����ժ������ȴʼ��û��������\n", me);
		return 1;
	}
	weapon_name = weapon->query("name");
	if (weapon->query("skill_type") != "throwing") {
		message_vision("$N�����е�" + weapon_name + "ȥ�����ϵ�Ҷ�ӣ�ȴ��������\n", me);
		return 1;
	}
	weapon_name = weapon->query("base_unit") + weapon->query("name");
	xunbu = present("xunbu", this_object());
	if (xunbu && !userp(xunbu)) {
		message_vision("$N�ͳ�һ" + weapon_name + "����׼��������Ҷ��ȥ��Ѳ����Ȼ����һ�ţ���$N����һ����ͷ��\n", me);
		message_vision("Ѳ������$N�ȵ����������϶���������㰮��������ľ������λ����ٷ�����\n", me);
		me->add_temp("damage_yz_tree", 1);
		me->start_busy(1);
		topay = me->query_temp("damage_yz_tree");
		if (topay < 3) {
			message_vision("Ѳ������$N�ȵ������´α���ץ�����������ģ���\n", me);
			return 1;
		}
		else {
			message_vision("Ѳ������$N�ȵ���������" + CHINESE_D->chinese_number(topay * 5) + "��ͭǮ����\n", me);
			switch (MONEY_D->player_pay(me, topay * 5)) {
				case 0:
					message_vision("$N���������������ˣ�С������Ǯ����������Ǻã���\n", me);
					topay = 0;
					if (money_ob = present("gold_money", me)) {
						money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "���ƽ�";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("silver_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("coin_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (topay)
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬��$N���ϵ�����" + money_str + "��\nѲ������Ǯ���㬵�˵������������㣬�´���ɸ���С�ĵ㣡��\n", me);
					else
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬����$N������һ��ͭ�嶼û�е�������\nѲ�������۵�����û��Ǯ��������ѽ�㣡��������㣬�´���ɸ���С�ĵ㣡��\n", me);
					return 1;
				case 2:
					message_vision("$N�ͳ�һ����Ʊ��С��������ʵ��������ˣ�С��ֻ����Ʊ�����ϣ������ܷ�ͨ��һЩ����\n", me);
					message_vision("Ѳ��һƲ�죬���ֽ���Ʊ���˹�ȥ��������������ǰ�����������ľ͵������ҺȾƺ��ˡ���\n", me);
					money_ob = present("thousand-cash", me);
					money_ob->set_amount(money_ob->query_amount() - 1);
					return 1;
				default:
					message_vision("$N���˷��һ���Ĳ����ˡ�\n", me);
					return 1;
			}
		}
	}
	if (room = find_object(__DIR__"shushang")) {
//		room = load_object(__DIR__"shushang");
		temp = 18 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp)) {
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++) {
				if (userp(ob[i]) && !wizardp(ob[i])) {
					tell_object(ob[i], me->name() + "�ͳ�һ" + weapon_name + "���������ϵ�����ȴ���û����㣬�����һ�����ȣ�������ȥ��\n");
					tell_room(room, me->name() + "�ͳ�һ" + weapon_name + "���������ϵ�����ȴ���û���" + ob[i]->name() + "��" + ob[i]->name() + "����һ�����ȣ�������ȥ��\n", ({ob[i]}));
					write("���ͳ�һ" + weapon_name + "����׼��Ҷ��ȥ��ֻ����������һ���ҽУ�һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n");
					tell_room(this_object(), me->name() + "�ͳ�һ" + weapon_name + "����׼��Ҷ��ȥ��ֻ����������һ���ҽУ�һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n", ({me}));
					ob[i]->move(this_object());
					qi = ob[i]->query("qi");
					if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
					else if (qi >= 100) ob[i]->receive_damage("qi", 100);
					else if (qi > 0) ob[i]->receive_damage("qi", qi);
					return 1;
				}
			}
		}
	}
	level = me->query_skill("throwing", 1);
	jinglicost = level / 3 + random(level / 3);
        if (me->query("jingli") <= jinglicost) {
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30) {
		write("���ͳ�һ" + weapon_name + "����׼��Ҷ��ȥ��ȴ��Ϊָ��̫����û�е�����\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
		return 1;
	}
	me->receive_damage("jingli", jinglicost);
	if (level <= 100) {
		write("���ͳ�һ" + weapon_name + "����׼��Ҷ��ȥ��ֻ�����͡����������һƬ��ҶӦ�����䡣\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
		me->improve_skill("throwing", me->query("int"));
	}
	else {
		if (query("stick_count")) {
			message_vision("$N�ͳ�һ" + weapon_name + "����׼��Ҷ��ȥ������þ���������֦����������������������ȴû���½�չ��\n", me);
			add("stick_count", -1);
			new(__DIR__"obj/stick.c")->move(this_object());
		}
		else
			write("���ͳ�һ" + weapon_name + "����׼��Ҷ��ȥ������������ϰ̫�����ˣ������������Ѿ��޷�ȡ���½�չ��\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
	}
	return 1;
}

int do_shake(string arg)
{
	object room, peachroom, xunbu, money_ob, *ob;
	object me = this_player();
	int i, qi, level, jinglicost, topay, temp;
	string money_str = "";

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("��Ҫҡʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	xunbu = present("xunbu", this_object());
	if (xunbu && !userp(xunbu)) {
		message_vision("$N�������ɣ���׼��ҡ��Ѳ����Ȼ����һ�ţ���$N����һ����ͷ��\n", me);
		message_vision("Ѳ������$N�ȵ����������϶���������㰮��������ľ������λ����ٷ�����\n", me);
		me->add_temp("damage_yz_tree", 1);
		me->start_busy(1);
		topay = me->query_temp("damage_yz_tree");
		if (topay < 3) {
			message_vision("Ѳ������$N�ȵ������´α���ץ�����������ģ���\n", me);
			return 1;
		}
		else {
			message_vision("Ѳ������$N�ȵ���������" + CHINESE_D->chinese_number(topay * 5) + "��ͭǮ����\n", me);
			switch (MONEY_D->player_pay(me, topay * 5)) {
				case 0:
					message_vision("$N���������������ˣ�С������Ǯ����������Ǻã���\n", me);
					topay = 0;
					if (money_ob = present("gold_money", me)) {
						money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "���ƽ�";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("silver_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("coin_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (topay)
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬��$N���ϵ�����" + money_str + "��\nѲ������Ǯ���㬵�˵������������㣬�´���ɸ���С�ĵ㣡��\n", me);
					else
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬����$N������һ��ͭ�嶼û�е�������\nѲ�������۵�����û��Ǯ��������ѽ�㣡��������㣬�´���ɸ���С�ĵ㣡��\n", me);
					return 1;
				case 2:
					message_vision("$N�ͳ�һ����Ʊ��С��������ʵ��������ˣ�С��ֻ����Ʊ�����ϣ������ܷ�ͨ��һЩ����\n", me);
					message_vision("Ѳ��һƲ�죬���ֽ���Ʊ���˹�ȥ��������������ǰ�����������ľ͵������ҺȾƺ��ˡ���\n", me);
					money_ob = present("thousand-cash", me);
					money_ob->set_amount(money_ob->query_amount() - 1);
					return 1;
				default:
					message_vision("$N���˷��һ���Ĳ����ˡ�\n", me);
					return 1;
			}
		}
	}
	if (room = find_object(__DIR__"shushang")) {
//		room = load_object(__DIR__"shushang");
		temp = 15 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp)) {
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++) {
				if (userp(ob[i]) && !wizardp(ob[i])) {
					tell_object(ob[i], me->name() + "ʹ����ҡ���Ŵ����������һ�����ȣ�������ȥ��\n");
					tell_room(room, me->name() + "ʹ����ҡ���Ŵ�����" + ob[i]->name() + "����һ�����ȣ�������ȥ��\n", ({ob[i]}));
					write("��ʹ����ҡ���Ŵ�����������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n");
					tell_room(this_object(), me->name() + "ʹ����ҡ���Ŵ�����������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n", ({me}));
					ob[i]->move(this_object());
					if (!random(3)) {
						qi = ob[i]->query("qi");
						if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
						else if (qi >= 100) ob[i]->receive_damage("qi", 100);
						else if (qi > 0) ob[i]->receive_damage("qi", qi);
					}
					return 1;
				}
			}
		}
	}
	level = me->query_skill("parry", 1);
	jinglicost = level / 3 + random(level / 3);
        if (me->query("jingli") <= jinglicost) {
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30) {
		write("��ʹ����ҡ���Ŵ���������ȴ��˿�������㲻���뵽�Ǿ䡰��ݺ������ĳ�������\n");
		return 1;
	}
	if (level > 100) {
		write("��ʹ����ҡ���Ŵ����������ϵ����Ӷ�ҡ���䵽���ɿ���ȥ�ˡ�\n");
		if (!random(8) && query("peach_count")) {
			add("peach_count", -1);
			switch (random(4)) {
				case 0:
					if (!(peachroom = find_object(__DIR__"guangchangbei")))
						peachroom = load_object(__DIR__"guangchangbei");
					break;

				case 1:
					if (!(peachroom = find_object(__DIR__"guangchangxi")))
						peachroom = load_object(__DIR__"guangchangxi");
					break;

				case 2:
					if (!(peachroom = find_object(__DIR__"guangchangnan")))
						peachroom = load_object(__DIR__"guangchangnan");
					break;

				case 3:
					if (!(peachroom = find_object(__DIR__"guangchangdong")))
						peachroom = load_object(__DIR__"guangchangdong");
					break;
			}
			new(__DIR__"obj/peach")->move(peachroom);
			tell_room(peachroom, "��Ȼ�ӹ㳡�����Ǳ߷ɹ���һ�����ӣ�����ҵ��㣡\n", ({}));
		}
		return 1;
	}
	me->receive_damage("jingli", jinglicost);
	if (!random(5))
		message_vision("$Nʹ����ҡ�Ŵ����������ϵ��¼���������������$N��ͷ����$N��æ��ۼܿ���\n", me);
	else
		write("��ʹ����ҡ�Ŵ����������ϵ��¼������������������ͷ�������æ��ۼܿ���\n");
	me->improve_skill("parry", me->query("int"));
	return 1;
}

int do_strike(string arg)
{
	object room, peachroom, xunbu, money_ob, *ob;
	object me = this_player();
	int i, qi, level, jinglicost, topay, temp;
	string money_str = "";

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	xunbu = present("xunbu", this_object());
	if (xunbu && !userp(xunbu)) {
		message_vision("$N�������������Ѳ����Ȼ����һ�ţ���$N����һ����ͷ��\n", me);
		message_vision("Ѳ������$N�ȵ����������϶���������㰮��������ľ������λ����ٷ�����\n", me);
		me->add_temp("damage_yz_tree", 1);
		me->start_busy(1);
		topay = me->query_temp("damage_yz_tree");
		if (topay < 3) {
			message_vision("Ѳ������$N�ȵ������´α���ץ�����������ģ���\n", me);
			return 1;
		}
		else {
			message_vision("Ѳ������$N�ȵ���������" + CHINESE_D->chinese_number(topay * 5) + "��ͭǮ����\n", me);
			switch (MONEY_D->player_pay(me, topay * 5)) {
				case 0:
					message_vision("$N���������������ˣ�С������Ǯ����������Ǻã���\n", me);
					topay = 0;
					if (money_ob = present("gold_money", me)) {
						money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "���ƽ�";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("silver_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("coin_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (topay)
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬��$N���ϵ�����" + money_str + "��\nѲ������Ǯ���㬵�˵������������㣬�´���ɸ���С�ĵ㣡��\n", me);
					else
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬����$N������һ��ͭ�嶼û�е�������\nѲ�������۵�����û��Ǯ��������ѽ�㣡��������㣬�´���ɸ���С�ĵ㣡��\n", me);
					return 1;
				case 2:
					message_vision("$N�ͳ�һ����Ʊ��С��������ʵ��������ˣ�С��ֻ����Ʊ�����ϣ������ܷ�ͨ��һЩ����\n", me);
					message_vision("Ѳ��һƲ�죬���ֽ���Ʊ���˹�ȥ��������������ǰ�����������ľ͵������ҺȾƺ��ˡ���\n", me);
					money_ob = present("thousand-cash", me);
					money_ob->set_amount(money_ob->query_amount() - 1);
					return 1;
				default:
					message_vision("$N���˷��һ���Ĳ����ˡ�\n", me);
					return 1;
			}
		}
	}
	if (room = find_object(__DIR__"shushang")) {
//		room = load_object(__DIR__"shushang");
		temp = 16 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp)) {
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++) {
				if (userp(ob[i]) && !wizardp(ob[i])) {
					tell_object(ob[i], me->name() + "һ����������������һ�����ȣ�������ȥ��\n");
					tell_room(room, me->name() + "һ�����������" + ob[i]->name() + "����һ�����ȣ�������ȥ��\n", ({ob[i]}));
					write("��һ�����������������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n");
					tell_room(this_object(), me->name() + "һ�����������������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n", ({me}));
					ob[i]->move(this_object());
					if (!random(3)) {
						qi = ob[i]->query("qi");
						if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
						else if (qi >= 100) ob[i]->receive_damage("qi", 100);
						else if (qi > 0) ob[i]->receive_damage("qi", qi);
					}
					return 1;
				}
			}
		}
	}
	level = me->query_skill("strike", 1);
	jinglicost = level / 3 + random(level / 3);
        if (me->query("jingli") <= jinglicost) {
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30) {
		write("��һ���������������ȴ��˿��������е�ʮ�־�ɥ��\n");
		return 1;
	}
	if (level > 100) {
		write("��һ����������������ϵ����Ӷ�����䵽���ɿ���ȥ�ˡ�\n");
		if (!random(8) && query("peach_count")) {
			add("peach_count", -1);
			switch (random(4)) {
				case 0:
					if (!(peachroom = find_object(__DIR__"guangchangbei")))
						peachroom = load_object(__DIR__"guangchangbei");
					break;

				case 1:
					if (!(peachroom = find_object(__DIR__"guangchangxi")))
						peachroom = load_object(__DIR__"guangchangxi");
					break;

				case 2:
					if (!(peachroom = find_object(__DIR__"guangchangnan")))
						peachroom = load_object(__DIR__"guangchangnan");
					break;

				case 3:
					if (!(peachroom = find_object(__DIR__"guangchangdong")))
						peachroom = load_object(__DIR__"guangchangdong");
					break;
			}
			new(__DIR__"obj/peach")->move(peachroom);
			tell_room(peachroom, "��Ȼ�ӹ㳡�����Ǳ߷ɹ���һ�����ӣ�����ҵ��㣡\n", ({}));
		}
		return 1;
	}
	me->receive_damage("jingli", jinglicost);
	if (!random(5))
		message_vision("$Nһ������������������˼��Σ�$N�����Լ����Ʒ����������ˡ�\n", me);
	else
		write("��һ������������������˼��Σ�������Լ����Ʒ����������ˡ�\n");
	me->improve_skill("strike", me->query("int"));
	return 1;
}

int do_climb(string arg)
{
	object xunbu, money_ob, me = this_player();
	int topay;
	string money_str = "";

	if (arg != "tree" && arg != "shu" && arg != "dashu" && arg != "up")
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	xunbu = present("xunbu", this_object());
	if (xunbu && !userp(xunbu)) {
		message_vision("$N������������������ĭ��������������������ȥ�������˼��£�Ѳ����Ȼ���ֽ�$N��������ק��������\n", me);
		message_vision("Ѳ������$N�ȵ����������϶���������㰮��������ľ������λ����ٷ�����\n", me);
		me->add_temp("damage_yz_tree", 1);
		me->start_busy(1);
		topay = me->query_temp("damage_yz_tree");
		if (topay < 3) {
			message_vision("Ѳ������$N�ȵ������´α���ץ�����������ģ���\n", me);
			return 1;
		}
		else {
			message_vision("Ѳ������$N�ȵ���������" + CHINESE_D->chinese_number(topay * 5) + "��ͭǮ����\n", me);
			switch (MONEY_D->player_pay(me, topay * 5)) {
				case 0:
					message_vision("$N���������������ˣ�С������Ǯ����������Ǻã���\n", me);
					topay = 0;
					if (money_ob = present("gold_money", me)) {
						money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "���ƽ�";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("silver_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "������";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (money_ob = present("coin_money", me)) {
						if (topay)
							money_str = money_str + "��" + CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						else
							money_str = CHINESE_D->chinese_number(money_ob->query_amount()) + "��ͭǮ";
						money_ob->set_amount(0);
						topay = 1;
					}
					if (topay)
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬��$N���ϵ�����" + money_str + "��\nѲ������Ǯ���㬵�˵������������㣬�´���ɸ���С�ĵ㣡��\n", me);
					else
						message_vision("Ѳ����ŭ��ץס$N�����ŵ���������ʹ��ҡ�˰��죬����$N������һ��ͭ�嶼û�е�������\nѲ�������۵�����û��Ǯ��������ѽ�㣡��������㣬�´���ɸ���С�ĵ㣡��\n", me);
					return 1;
				case 2:
					message_vision("$N�ͳ�һ����Ʊ��С��������ʵ��������ˣ�С��ֻ����Ʊ�����ϣ������ܷ�ͨ��һЩ����\n", me);
					message_vision("Ѳ��һƲ�죬���ֽ���Ʊ���˹�ȥ��������������ǰ�����������ľ͵������ҺȾƺ��ˡ���\n", me);
					money_ob = present("thousand-cash", me);
					money_ob->set_amount(money_ob->query_amount() - 1);
					return 1;
				default:
					message_vision("$N���˷��һ���Ĳ����ˡ�\n", me);
					return 1;
			}
		}
	}
	message_vision("$N������������������ĭ������������˳������������ȥ��\n", me);
	me->move(__DIR__"shushang", 1);
	message("vision", me->name() + "����������������\n", __DIR__"shushang", ({me}));
	return 1;
}

int valid_leave(object me, string dir)
{
	object room;
	int valid;

	valid = ::valid_leave(me, dir);
	if (valid && !wizardp(me) && room = find_object(__DIR__"shushang"))
		tell_room(room, "͸����Ҷ�ķ�϶���㿴��" + me->name() + "�뿪�����¡�\n");
	return valid;
}
/*
void reset()
{
mixed *ob_list;
int i;

ob_list=objects();
for(i=0;i<sizeof(ob_list);i++)
ob_list[i]->delete_temp("vendor_goods");
::reset();
return;
}
*/
