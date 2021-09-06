// NPC: /d/plummanor/npc/shilingwei.c
// By Jpei

inherit NPC;

void create()
{
	set_name("ʩ����", ({ "shi lingwei", "shi" }));
	set("nickname", "����");

	set("gender", "����");
	set("age", 45);
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

	set("nickname", "����");
	::init();
	where = base_name(environment(this_object()));
	if (where == "/d/plummanor/entrance")
	        add_action("do_flatter", "flatter");
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
			message_vision("$Nָ��$n���̵�����$n�书������Ȼ���˿ɱȣ������Ÿ�ƨҲ������������������̣���\n", me, npc);
			message_vision("$N���ĵؿ���$n���ƺ�һ���Ӷ�û������ô�����޳ܵ��ˡ�\n", npc, me);
			me->add_temp("plummanor/shi_friend", -12);
			return 1;
		}
		if (me->query_temp("plummanor/shi_flatter")) {
			write("�㻹��ʩ����ѽ���Լ�������������\n");
			return 1;
		}
		me->set_temp("plummanor/shi_flatter", 1);
		write("�����ʩ����˵�������뵱��ʩ���ں����Ὥ�ȹ£�һ���Ͻ���Ե�ɱ��������һʮ������ͷ��Ѫ����ˮ��ͷ������ȴ������ͷ����\n");
		tell_room(environment(npc), me->name() + "����ʩ����˵��Щ���̵Ļ���\n", ({me}));
		message_vision("$N����$n��һ���������ɵ���¶ϲɫ��\n", npc, me);
		me->add_temp("plummanor/shi_friend", 10);
		call_out("decrease_friend", 1, me);
		return 1;
	}
	return 0;
}

void decrease_friend(object me)
{
	if (base_name(environment(this_object())) != "/d/plummanor/entrance") return;
	if (objectp(me)) {
		me->add_temp("plummanor/shi_friend", -1);
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
	message_vision("ʩ����ĮȻ���������ֽ�����ɱ�Ѿ������޹��ˡ���\n", ob);
}

int accept_fight(object ob)
{
	message_vision("ʩ����ҡ�׵�����������÷ׯ�����ٺ��˶����ˡ���\n", ob);
	return 0;
}

void unconcious()
{
	say("ʩ�����ȵ�����ס�֣����Ѿ����ٺ��˶����ˣ���\n");
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

