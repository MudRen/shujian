// /u/jpei/thd/npc/ya-mujiang.c

#include <ansi.h>

inherit NPC;

object me;

void create()
{
	set_name("��ľ��", ({"ya mujiang", "ya", "mujiang", "jiang"}));
	set("long", "����һλ������е�ľ������֪Ϊʲô��ͷ����ȥ�ˡ�\n");
	set("mute", 1);

	set("gender", "����");
	set("attitude", "friendly");

	set("age", 40);
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 100000);
	set("family/family_name", "�һ���");

	set_skill("force", 50);
	set_skill("dodge", 100);
	set_skill("strike", 50);
	set_skill("parry", 60);

	setup();

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob = this_player();

	::init();
	if (!query("in_repairing") && ob->id("machine bonze") && ob->query("damaged"))
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 3, ob, environment());
		set("in_repairing", 1);
	}
}

int repairing_1(object ob, object env)
{
	if (env != environment()) return 1; 
	if (!present(ob, env)) return 1; 

	command("follow none");
	remove_call_out("no_find");
	if (present(me, environment()) ) command("nod " + me->query("id"));
	tell_room(env, "��ľ�������ƱȻ���˵��Ҫ��ʼ�����ˡ�\n", ({}));
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2 + random(3), ob, env);

	return 1;
}

int repairing_2(object ob, object env)
{
	if (env != environment()) {
		destruct(this_object());
		return 1; 
	}
	if (!present(ob, env)) {
		tell_room(env, GRN "\n��ľ����Ȼ���ֻ�е���в����ˣ���ֵ�������ͷ��\n" NOR, ({}));
		tell_room(env, GRN "\n��ľ�����˳�ȥ��\n" NOR, ({}));
		destruct(this_object());
		return 1; 
	}

	if( ob->query("damaged") )
	{
		tell_room(env, GRN "\n��ľ�����Ż�е��������һ�ᣬ�����Ű⶯��е���е���֫���Դ���Ȼ�������Դ���������ʲô��\n\n" NOR, ({}));
		remove_call_out("repairing_3");
		call_out("repairing_3", 2 + random(2), ob, env);
	}
	else
	{
		if (present(me, environment())) {
			command("? " + me->query("id"));
			command("angry " + me->query("id"));
		}

		tell_room(env, GRN "\n��ľ�����Ĺĵ����ˡ�\n" NOR, ({}));
		destruct(this_object());
	}

	return 1;
}
	
int repairing_3(object ob, object env)
{
	if (env != environment()) {
		destruct(this_object());
		return 1; 
	}
	if (!present(ob, env)) {
		tell_room(env, GRN "\n��ľ����Ȼ���ֻ�е���в����ˣ���ֵ�������ͷ��\n" NOR, ({}));
		tell_room(env, GRN "\n��ľ�����˳�ȥ��\n" NOR, ({}));
		destruct(this_object());
		return 1; 
	}

	command("nod");
	tell_room(env, GRN "\n���Ŵӻ����ͳ�һ��ѹ��������򿪻�е���е����壬��Ū�˼��¡�\n\n" NOR, ({}));

	remove_call_out("repairing_4");
	call_out("repairing_4", 3 + random(3), ob, env);

	return 1;
}

int repairing_4(object ob, object env)
{
	if (env != environment()) {
		destruct(this_object());
		return 1; 
	}
	if (!present(ob, env)) {
		tell_room(env, GRN "\n��ľ����Ȼ���ֻ�е���в����ˣ���ֵ�������ͷ��\n" NOR, ({}));
		tell_room(env, GRN "\n��ľ�����˳�ȥ��\n" NOR, ({}));
		destruct(this_object());
		return 1; 
	}

	if (random(3)) 
	{		
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		ob->enable_player();
		tell_room(env, GRN "\n��е���е�����֨֨��Ť���˼��£������Ѿ��ָ������ˡ�\n\n" NOR, ({}));
		command(":)");
		command("wave");
		tell_room(env, GRN "\n��ľ�����˳�ȥ��\n" NOR, ({}));
		destruct(this_object());
	}
	else {
		command("angry");
		tell_room(env, GRN "\n��ľ����ŭ֮�£��ø��ӽ���е�������˸�ϡ�á�\n" NOR, ({}));
		destruct(ob);
		tell_room(env, GRN "\n��ľ��ƽ��������������úܹ��ⲻȥ�������Ʊ�ʾ˵��ȥ�����µ�����\n" NOR, ({}));
		tell_room(env, GRN "\n��ľ�����˳�ȥ��\n" NOR, ({}));
		this_object()->move_to_ob("../mujiangfang");

		remove_call_out("do_back");
		call_out("do_back", 120 + random(60), env);
	}
	return 1;
}

int do_back(object env)
{
	this_object()->move(env);
	if (!present("machine bonze 4", env)) {
		tell_room(env, GRN "\n��ľ������һ���µĻ�е�������˹�����\n" NOR, ({}));
		tell_room(env, GRN "\n��ľ���ѻ�е���зŵ����¡�\n" NOR, ({}));
		new(__DIR__"machine-bonze.c")->move(environment());
	}
	else {
		tell_room(env, GRN "\n��ľ������˫�ֻ����ˡ�\n" NOR, ({}));
		tell_room(env, GRN "\n��ľ�������Ʊ�ʾû�������ɹ���\n" NOR, ({}));
		command("shrug");
	}
	command("wave");
	tell_room(env, GRN "\n��ľ�����˳�ȥ��\n" NOR, ({}));
	destruct(this_object());
	return 1;
}

int no_find()
{
	message_vision(GRN "��ľ���е��ܲ��ͷ��ˣ������Ƴ�$N�Ȼ��˼��¾����ˡ�\n" NOR, me);
	destruct(this_object());
}

void do_follow(object ob)
{
	command("nod");
	if (present(ob, environment(this_object()))) {
		command("follow " + ob->query("id"));
		set("busy", 1);
		me = ob;
		remove_call_out("no_find");
		call_out("no_find", 180);
	}
	else {
		tell_room(environment(this_object()), GRN "��ľ���Ĵ���������û�п���" + ob->name() +"���ɻ�����ˡ�\n" NOR, ({}));
		destruct(this_object());
	}
}
