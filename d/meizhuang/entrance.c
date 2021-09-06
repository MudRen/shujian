// Room: /d/meizhuang/entrance.c ׯԺ����
// By Jpei
// modify by Lklv 2001.9.11

inherit ROOM;

int do_knock(string arg);
int do_answer(string arg);
int do_show(string arg);

void create()
{
	set("short", "ׯԺ����");
	set("long", @LONG
�е�������ֻ��ׯԺ����(gate)��д�š�÷ׯ���������֣��Ա����š���
�����⡱���֡��⼸��������֮��͸�Ų��������������ǳ��������ƽ�Ĵ�
��֮�֡�
LONG
	);
	set("outdoors","����");

	set("item_desc", ([
		"gate" : "���Ž����ţ������и����þ���ѩ���Ĵ�ͭ������������(qiao)���õġ�\n",
	]) );
	set("exits", ([
		"north" : __DIR__"road3",
	]));
	setup();
}

void init()
{
	object me = this_player();

	me->delete_temp("plummanor");
	add_action("do_knock", ({"qiao"}));
	add_action("do_answer", ({"answer", "huida", "da"}));
	add_action("do_show", ({"show", "zhanshi", "chushi", "shi"}));
}

int do_knock(string arg)
{
	object me = this_player();
	object env = this_object();
	string times, gate;
	int count, knockgate;

	if (me->is_busy()&& !wizardp(me)) return notify_fail("���㣬����һ��������û����ɡ�\n");
	if (!arg) return notify_fail("��Ҫ��ʲô��\n");
	if (sscanf(arg, "%s %d %s", gate, count, times) != 3 || gate != "gate" || times != "times")
		return notify_fail("��Ҫ�ü���( ? times)��\n");
	if (present("ding jian", env) && present("shi lingwei", env))
		return notify_fail("�������˺ȵ������˶������ˣ�����ʲô������\n");
	else if (present("ding jian", env)) {
		new(__DIR__"npc/shilingwei")->move(env);
		return notify_fail("һ�������߳���,���˼���,������˵�������ﲻ�������𣬻���ʲô������\n");
	}
	else if (present("shi lingwei", env)) {
		new(__DIR__"npc/dingjian")->move(env);
		return notify_fail("һ�������߳���,���˼���,������˵�������ﲻ�������𣬻���ʲô������\n");
	}
	message_vision("$Nץס���ϵĴ�ͭ��������" + CHINESE_D->chinese_number(count) + "�¡�\n", me);
	me->start_busy(1);
	knockgate = me->query_temp("plummanor/knock_gate");
	if ((knockgate == 0 && count == 4) || (knockgate == 1 && count == 2) ||	(knockgate == 2 && count == 5))
		me->add_temp("plummanor/knock_gate", 1);
	else {
		if (knockgate == 3 && count == 3)
			call_out("servant_out", 30, me);
		else
			remove_call_out("servant_out");
		me->delete_temp("plummanor/knock_gate");
	}
	return 1;
}

void servant_out(object me)
{
	object shi, ding, env = this_object();

	if (!objectp(me)) return;
	if (!(shi = present("shi lingwei", env))) {
		shi = new(__DIR__"npc/shilingwei");
		shi->move(env);
	}
	if (!(ding = present("ding jian", env))) {
		ding = new(__DIR__"npc/dingjian");
		ding->move(env);
	}
	tell_room(env, "���˰��Σ����Ż����򿪣������߳���������װ�������ߡ�\n", ({}));
	if (!present(me, env)) {
		tell_room(env, "���˿��˰��죬û�ҵ�����֮�ˣ����Ǿ�ת�����˻�ȥ���Ѵ��Ź����ˡ�\n", ({}));
		destruct(shi);
		destruct(ding);
		return;
	}
	message_vision("���׵����˶���$N����˵��������λ" + RANK_D->query_respect(me) + "���ٱ�ׯ����֪�кι�ɣ���\n", me);
	me->set_temp("plummanor/flag", 1);
	call_out("close_door", 180, me);

}

void close_door(object me)
{
	object shi, ding, env = this_object();

	if (shi = present("shi lingwei", env)) destruct(shi);
	if (ding = present("ding jian", env))  destruct(ding);
	tell_room(env, "�������˵��˰��죬û�еõ���ȷ�Ļش�(answer)�����Ǿ�ת�����˻�ȥ���Ѵ��Ź����ˡ�\n", ({}));
	if (objectp(me)) me->delete_temp("plummanor");
	return;
}

int do_answer(string arg)
{
	object me = this_player();
	object env = this_object();

	if (!arg) return notify_fail("��Ҫ�ش�ʲô��\n");
	if (me->query_temp("plummanor/flag") != 1)
		return notify_fail("��û�����㣬����Ϲ����ʲô����\n");
	if (arg[0..3] == "���"|| arg[0..11] == "�����������" || arg[0..11] == "�ݼ���������" ||
		arg[0..15] == "���������������" || arg[0..15] == "���°ݼ���������") {
		if (!present("shi lingwei", env))
			new(__DIR__"npc/shilingwei")->move(env);
		if (!present("ding jian", env))
			new(__DIR__"npc/dingjian")->move(env);
		message_vision("$N���ֵ���������$P�����������������λǰ�����ͷ���λ��������\n",me);
		message_vision("���׵ļ��˶�$N�������Ҽ������򲻼��͡���˵�ű������š�\n", me);
		me->set_temp("plummanor/flag", 2);
		return 1;
	}
	else
	message_vision("$N���ֵ���������·���˵أ������һ�ޣ��ͷ���λ�и����㡣��\n",me);
	message_vision("���׵ļ��˶�$N��������ׯһ������ͣ����������Ҽ����˵����ѡ���˵�ž�Ҫ���š�\n", me);
	return 1;
}

int do_show(string arg)
{
	object me, env, *inv, shi, ding, dest;
	string str;
	int i, flag;

	me = this_player();
	env = this_object();

	if (!arg) return notify_fail("��Ҫչʾʲô��\n");
	inv = all_inventory(me);
	for (i = 0; i < sizeof(inv); i++)
		if (inv[i]->id(arg)) break;
	if (i == sizeof(inv)) return notify_fail("��Ҫչʾʲô��\n");
	if (!(shi = present("shi lingwei", env))) {
		shi = new(__DIR__"npc/shilingwei");
		shi->move(env);
	}
	if (!(ding = present("ding jian", env))) {
		ding = new(__DIR__"npc/dingjian");
		ding->move(env);
	}
	if (!me->query_temp("plummanor/flag"))
		return notify_fail("���ͳ�һ" + inv[i]->query("unit") + inv[i]->query("name") + "�������ҿ�������û�����㡣\n");
	flag = 0;
	str = "$N�ͳ�һ" + inv[i]->query("unit") + inv[i]->query("name") + "��";
	if (inv[i]->id("wuse lingqi")) {
		flag = 1;
		str += "չ�˿�����ֻ��������ҫ���������������鱦ʯ��\n";
	}
	else str += "�����������˻������Ρ��������Ǻ�������$N����˼��\n";
	message_vision(str, me);
	if (flag) {
		if (me->query_temp("plummanor/flag") == 1) {
			message_vision("�������˶�$N�ȵ�������ô�����������������������Ż����ǣ��Ȼش�(answer)����ʲô����˵��\n", me);
		}
		else {
			message_vision("��������������������ɽ�������������죿��\n$N���������ǡ���\n", me);
			message_vision("���׵ļ��˵�������ʹ����ɽ�������׵����Ҽ�����Ҳδ��...��\n", me);
			message_vision("���׵ļ��˶�$N������������Ȼ�������ڣ����ҽ�ȥ������������\n", me);
			message_vision("$N���˵�ͷ�����������˽��˴��š�\n", me);
			if (!(dest = find_object(__DIR__"hall")))
				dest = load_object(__DIR__"hall");
			if (!present("shi lingwei", dest))
				shi->move(dest);
			else
				destruct(shi);
			if (!present("ding jian", dest))
				ding->move(dest);
			else
				destruct(ding);
			me->set_temp("plummanor/flag", 3);
//			destruct(inv[i]);
			me->move(dest);
		}
	}
	return 1;
}
