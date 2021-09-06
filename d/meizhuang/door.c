// Room: /d/meizhuang/entrance.c ׯԺ����
// By Jpei, recode by Lklv
// Modify and open Quest by Lklv 2001.9.11

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"ׯԺ����"NOR);
	set("long",
"��ǰ�Ǹ߸ߵİ�ʯǽ��ʯǽΧ���ŵ���һ�����ɵ�ׯԺ�������ϸ߸߹���\n"
"��"CYN"�Ҷbian��"NOR"������д��"HIY"��÷ׯ��"NOR"�����̽���֣���д�ñ����Ծ�������֮\n"
"��͸�Ų���Ӣ����ǰ�����������ɫ�Ĵ��ţ�gate�������ϵĴ�ͭ�����þ���\n"
"ѩ����\n"
	);
	set("outdoors","����");
	set("flag", 0);
	set("item_desc", ([
		"gate" : "���Ž����ţ������и����þ���ѩ���Ĵ�ͭ������������(qiao)���õġ�\n",
		"door" : "���Ž����ţ������и����þ���ѩ���Ĵ�ͭ������������(qiao)���õġ�\n",
		"bian" : "����д�š�÷ׯ���������֣��Ա߻������ĸ�С�֣����������⡱��\n",
	]) );
	set("exits", ([
		"north" : __DIR__"road3",
	]));
	setup();
}

void init()
{
	object me = this_player();

	add_action("do_knock", ({"qiao"}));
	if (!me->query_temp("mz_quest")){
		add_action("do_answer", ({"answer", "huida", "da"}));
		add_action("do_show", ({"show", "zhanshi", "chushi", "shi"}));
	}
}

int do_knock(string arg)
{
	object me, env;
	string times, gate;
	int count, knock;

	me = this_player();
	env = this_object();
	knock = me->query_temp("mz_quest/knock");

	if (!arg) return notify_fail("��Ҫ��ʲô��\n");
	if (knock == 4 && !me->query_temp("mz_quest/flag"))
		return notify_fail("�����и��������������ȵȣ�������ˣ���\n");
	if (me->is_busy()&& !wizardp(me))
		return notify_fail("���㣬����һ��������û����ɡ�\n");
	if (sscanf(arg, "%s %d %s", gate, count, times) != 3 || gate != "gate" || times != "times")
		return notify_fail("��Ҫ�ü���( ? times)��\n");
	if ( count > 10 ) return notify_fail("�꣬��㣡\n");
	if (present("ding jian", env) && present("shi lingwei", env))
		return notify_fail("�������˺ȵ������˶������ˣ�����ʲô������\n");
	if (present("ding jian", env) && !present("shi lingwei", env)){
		new(__DIR__"npc/shilingwei")->move(env);
		return notify_fail("һ�������߳���,���˼���,������˵�������ﲻ�������𣬻���ʲô������\n");
	}
	if (present("shi lingwei", env) && !present("ding jian", env)) {
		new(__DIR__"npc/dingjian")->move(env);
		return notify_fail("һ�������߳���,���˼���,������˵�������ﲻ�������𣬻���ʲô������\n");
	}

	message_vision(HIW"$Nץס���ϵĴ�ͭ��������" + CHINESE_D->chinese_number(count) + "�¡�\n"NOR, me);
	me->start_busy(1);

	if ((knock == 0 && count == 4) || (knock == 1 && count == 2) ||	(knock == 2 && count == 5))
		me->add_temp("mz_quest/knock", 1);
	else {
		if (knock == 3 && count == 3){
			me->set_temp("mz_quest/knock", 4);
			call_out("servant_out", 30, me);
			}
		else{
			remove_call_out("servant_out");
			me->delete_temp("mz_quest/knock");
		}
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
	tell_room(env, CYN"���˰��Σ����Ż����򿪣������߳���������װ�������ߡ�\n"NOR, ({}));
	if (!present(me, env)) {
		tell_room(env, CYN"���˿��˰��죬û�ҵ�����֮�ˣ����Ǿ�ת�����˻�ȥ���Ѵ��Ź����ˡ�\n"NOR, ({}));
		destruct(shi);
		destruct(ding);
		return;
	}
	message_vision(CYN"���׵����˶���$N����˵��������λ" + RANK_D->query_respect(me) + "���ٱ�ׯ����֪�кι�ɣ���\n"NOR, me);
	me->set_temp("mz_quest/flag", 1);
	call_out("close_door", 180, me);
}

void close_door(object me)
{
	object shi, ding, env = this_object();

	if (shi = present("shi lingwei", env)) destruct(shi);
	if (ding = present("ding jian", env))  destruct(ding);
	if (query("flag")!=1){
		tell_room(env, CYN"�������˵��˰��죬û�еõ���ȷ�Ļش�(answer)�����Ǿ�ת�����˻�ȥ���Ѵ��Ź����ˡ�\n"NOR, ({}));
	}
	else {
		tell_room(env, CYN"���Ÿ�֨һ���죬����������ˡ�\n"NOR, ({}));
	}
	if (objectp(me)) me->delete_temp("mz_quest");
	delete("exits/south");
	return;
}

int do_answer(string arg)
{
	object me = this_player();
	object env = this_object();

	if (!me->query_temp("mz_quest") || me->query_temp("mz_quest/flag") != 1) return 0;
	if (!arg) return notify_fail("��Ҫ�ش�ʲô��\n");

	if (!present("shi lingwei", env))
		new(__DIR__"npc/shilingwei")->move(env);
	if (!present("ding jian", env))
		new(__DIR__"npc/dingjian")->move(env);
	if (arg[0..11] == "�����������" || arg[0..11] == "�ݼ���������"
	 ||arg[0..15] == "���������������" || arg[0..15] == "���°ݼ���������") {
		message_vision(CYN"$N���ֵ���������$P�����������������λǰ�����ͷ���λ��������\n"NOR,me);
		message_vision(CYN"���׵ļ��˶�$N�������Ҽ������򲻼��͡���˵�ű������š�\n"NOR, me);
		me->set_temp("mz_quest/flag", 2);
		return 1;
	}
	else{
		message_vision(CYN"$N���ֵ���������·���˵أ������һ�ޣ��ͷ���λ�и����㡣��\n"NOR,me);
		message_vision(CYN"���׵ļ��˶�$N��������ׯһ������ͣ����������Ҽ����˵����ѡ���˵�ž�Ҫ���š�\n"NOR, me);
	}
	return 1;
}

int do_show(string arg)
{
	object me, env, *inv, shi, ding;
	string str;
	int i, flag;

	me = this_player();
	env = this_object();
//	ob = present("wuyue lingqi", me);

	if (!me->query_temp("mz_quest/flag") || !me->query_temp("mz_quest") )
	return 0;
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
	if (!me->query_temp("mz_quest/flag"))
		return notify_fail("���ͳ�һ" + inv[i]->query("unit") + inv[i]->query("name") + "�������ҿ�������û�����㡣\n");
	flag = 0;
	str = "$N�ͳ�һ" + inv[i]->query("unit") + inv[i]->query("name") + "��";
	if (inv[i]->id("wuyue lingqi")) {
		flag = 1;
		str += "չ�˿�����ֻ��������ҫ���������������鱦ʯ��\n";
	}
	else str += "�����������˻������Ρ��������Ǻ�������$N����˼��\n";
	message_vision(str, me);
	if (flag) {
		if (me->query_temp("mz_quest/flag") == 1) {
			message_vision(CYN"�������˶�$N�ȵ�������ô�����������������������Ż����ǣ��Ȼش�(answer)����ʲô����˵��\n"NOR, me);
			return 1;
		}
		else {
			message_vision(HIW"��������������������ɽ�������������죿��\n$N���������ǡ���\n"NOR, me);
			message_vision(HIW"���׵ļ��˵�������ʹ����ɽ�������׵����Ҽ�����Ҳδ��...��\n"NOR, me);
			message_vision(HIW"���׵ļ��˶�$N������������Ȼ�������ڣ����ҽ�ȥ������������\n"NOR, me);
			message_vision(CYN"�����������ԣ���$Nһ���ֵ���������롣��\n"NOR, me);
			set("exits/south", __DIR__"tianjing");
			me->force_me("go south");
			ding->force_me("go south");
			shi->force_me("go south");
			me->set_temp("mz_quest/flag", 3);
			remove_call_out("close_door");
			call_out("close_door", 60, me);
//			destruct(inv[i]);
		}
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	if (dir == "north" && me->query_temp("mz_quest/flag")==3
	&& (objectp(present("ding jian", environment(me)))
	|| objectp(present("shi lingwei", environment(me))) )){
		return notify_fail(CYN"�����������������ǰ������" + RANK_D->query_respect(me) + "�����������Ҷ��˽�ׯ�ա���\n"NOR);
	}
	if (me->query_temp("mz_quest/flag")==3)
		me->set_temp("mz_quest/go",1);
	if (dir == "south" && me->query_temp("mz_quest/flag")!=3)
		return notify_fail(CYN"�����������������ǰ������" + RANK_D->query_respect(me) + "���Ҽ�ׯ��������͡���\n"NOR);
        return ::valid_leave(me, dir);
}