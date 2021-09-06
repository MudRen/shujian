// NPC: /d/plummanor/npc/dingjian.c
// By Jpei

inherit NPC;

int do_flatter(string arg);

void create()
{
	set_name("����", ({ "ding jian", "ding" }));
	set("nickname", "����");

	set("gender", "����");
	set("age", 48);
	set("long", "��Ŀ�⾼�����������أ������书���͡�\n");
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_temp("apply/damage", 40);

	set("combat_exp", 400000);
	set("attitude", "peaceful");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	string where;
	object inv, me = this_player();

	set("nickname", "����");
	::init();
	where = base_name(environment(this_object()));
	if (where == "/d/plummanor/entrance")
	        add_action("do_flatter", "flatter");
	else if (where == "/d/plummanor/hall") {
		if (me->query_temp("plummanor/flag") == 3 && me->query_temp("plummanor/ding_friend") >= 18) {
			me->set_temp("plummanor/flag", 4);
			if (objectp(inv = present("wuse lingqi", me))) destruct(inv);
			message_vision("�����$N�����������ò裬����������������ȥ������ϣ����벻����ȴ�����ԡ���\n", me);
			call_out("destruct_me", 1);
		}
	}
	else if (where == "/d/plummanor/room3") {
		set("nickname", "һ�ֵ罣");
	}
}

void destruct_me()
{
	destruct(this_object());
}

int do_flatter(string arg)
{
	object npc = this_object();
	object me = this_player();

	if (base_name(environment(npc)) != "/d/plummanor/entrance") return 0;
	if (!arg) return notify_fail("��Ҫ��˭����ƨ��\n");
	if (arg == "four-friends") {
		if (me->query_temp("plummanor/flag") != 2) {
			message_vision("$Nһ�����ĵض�����λ����˵�������������ѣ�������أ��������Ž��ޱȣ���\n", me);
			message_vision("��λ���˱��ĵؿ���$N���ƺ�һ���Ӷ�û������ô�����޳ܵ��ˡ�\n", me);
			me->add_temp("plummanor/ding_friend", -15);
			me->add_temp("plummanor/shi_friend", -15);
			return 1;
		}
		me->add_temp("plummanor/friends_flatter", 1);
		if (me->query_temp("plummanor/friends_flatter") > 2) {
			me->add_temp("plummanor/friends_flatter", -1);
			write("�㻹�Ľ������ѣ��Լ�������������\n");
			return 1;
		}
		if (me->query_temp("plummanor/friends_flatter") == 1) {
			write("�������λ����˵������������λǰ���Ǻε����ˣ���Ȼ���Ὣ���¿�������ġ���\n");
			tell_room(environment(npc), me->name() + "������λ����˵��Щ���̽������ѵĻ���\n", ({me}));
			message_vision("��λ������$N���н��������ѵ����̧�����ߣ���ɫ��ͻ�����ࡣ\n", me);
			me->add_temp("plummanor/ding_friend", 5);
			me->add_temp("plummanor/shi_friend", 5);
			call_out("decrease_friend", 1, me);
			return 1;
		}
		else if (!me->query_temp("plummanor/ding_flatter") || !me->query_temp("plummanor/shi_flatter")) {
			message_vision("$Nһ�����ĵض�����λ����˵�������������ѣ�������أ��������Ž��ޱȣ���\n", me);
			message_vision("��λ���˱��ĵؿ���$N���ƺ�һ���Ӷ�û������ô�����޳ܵ��ˡ�\n", me);
			me->add_temp("plummanor/ding_friend", -15);
			me->add_temp("plummanor/shi_friend", -15);
			call_out("decrease_friend", 1, me);
			return 1;
		}
		else {
			write("�������λ����˵������������������ϣ����뽭��������δ���Ƶ������£������ܼ�����һ�ֵ罣���͡���·�񡱶�λ�����㲻����С���\n");
			tell_room(environment(npc), me->name() + "������λ����˵��Щ̧�߽���������˳��������˵Ļ���\n", ({me}));
			message_vision("��ʩ������$N�����������ѣ��ִ��������Լ����ˣ���Ϊ���ˡ�\n", me);
			me->add_temp("plummanor/ding_friend", 12);
			me->add_temp("plummanor/shi_friend", 12);
			call_out("decrease_friend", 1, me);
			return 1;
		}
	}
	if (id(arg)) {
		if (me->query_temp("plummanor/flag") != 2) {
			message_vision("$Nָ��$n������׳ʿ����ò����������ѣ���ֱ�Ƿ���������ǰ�޹��ˣ��������ߡ��˰��˱����ᣬ����ʰ��·硣��\n", me, npc);
			message_vision("$N���ĵؿ���$n���ƺ�һ���Ӷ�û������ô�����޳ܵ��ˡ�\n", npc, me);
			me->add_temp("plummanor/ding_friend", -12);
			return 1;
		}
		if (me->query_temp("plummanor/ding_flatter")) {
			write("�㻹�Ķ���ѽ���Լ�������������\n");
			return 1;
		}
		me->set_temp("plummanor/ding_flatter", 1);
		write("����Ŷ���˵�������뵱�궡��������ɽ�������İԣ�һ����˫�ۣ��ε����磡��\n");
		tell_room(environment(npc), me->name() + "���Ŷ���˵��Щ���̵Ļ���\n", ({me}));
		message_vision("$N΢΢һЦ����$n������С��һ��������ҳݣ����¼��ŵ��㲩�úܡ���\n", npc, me);
		me->add_temp("plummanor/ding_friend", 10);
		call_out("decrease_friend", 1, me);
		return 1;
	}
	return 0;
}

void decrease_friend(object me)
{
	if (base_name(environment(this_object())) != "/d/plummanor/entrance") return;
	if (objectp(me)) {
		me->add_temp("plummanor/ding_friend", -1);
		call_out("decrease_friend", 1, me);
	}
}

void fight_ob(object ob)
{
	return;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("����ĮȻ���������ֽ�����ɱ�Ѿ������޹��ˡ���\n", ob);
}

int accept_fight(object ob)
{
	message_vision("����ҡ�׵�����������÷ׯ�����ٺ��˶����ˡ���\n", ob);
	return 0;
}

void unconcious()
{
	say("����ȵ�����ס�֣����Ѿ����ٺ��˶����ˣ���\n");
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

