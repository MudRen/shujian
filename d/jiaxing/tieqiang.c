// Room: /d/jiaxing/tieqiang.c
// Lklv@SJ modify for dgb Quest at 2001.10.08

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"��ǹ��"NOR);
	set("long", @LONG
����ǹ�������������ʱ����������ǹ�����¡���Ϊ���ʧ�ޣ����
�Ǻ���ʢ���������ʩ�������������������������ں�����������Ѿ��޴�
֪��������Ⱥѻ����Ϊ������������˵��ǹ�����ѻ������񽫣���������
�ַ���������ѻ������ֳ��Խ��Խ�ࡣ
LONG
	);
	set("exits", ([
		"west" : __DIR__"jxnanmen",
		"north" : __DIR__"dbianmen",
	]));
	set("objects", ([
		__DIR__"npc/wuya": 2,
		__DIR__"npc/limochou": 1,
	]));
	setup();
}

void init()
{
	object me = this_player();

	if (me->query_temp("get_wugou") && !query("quest")) {
		add_action("do_da", ({"da", "huida"}));
		add_action("do_han", ({"han", "yell"}));
	}
}

int do_han(string arg)
{
	object me, ob, env;
	int count;

	if (localtime(TIME_TICK)[2] > 2)
		return 0;
	me = this_player();
	count = time() - me->query_temp("get_wugou");
	/*if (count < 0 || count > 11 * 60)
		return 0;*/
	env = this_object();
	count = me->query_temp("h7g_quest/han");

	if (ob = present("li mochoau", env))
		return notify_fail("��Ī��ȵ����������ҹ�����һ�����С��ʲô����\n");
	if (me->is_busy() || !arg )
		return notify_fail("��Ҫ��ʲô���ȴ������ɡ�\n");

	if (present("hong qigong", env)){
		message_vision(CYN"���߹���$N�ȵ�������ʲô��������û������\n"NOR, me);
		me->delete_temp("h7g_quest/han");
		me->start_busy(1);
		return 1;
	}
	if ( count > 3 ){
		message_vision(CYN"$N���˿�������һ�������߹�������ͽ��"+me->name()+""CYN"����þ��ˣ�������������ȥ��Զ��\n"NOR, me);
		me->start_busy(1);
		me->add_temp("h7g_quest/han",1);
		remove_call_out("happen");
		remove_call_out("happen2");
		call_out("happen2", 10, me);
		return 1;
	}
	if (arg=="�߹�" || arg=="ʦ��" || arg=="����") {
		if ( arg =="����" && count == 1){
			me->start_busy(1);
			me->add_temp("h7g_quest/han", 1);
			message_vision(CYN"$NС������һ������"+arg+"���������\n"NOR, me);
			return 1;
		}
		if ( arg =="�߹�" && count == 2){
			me->start_busy(1);
			me->add_temp("h7g_quest/han", 1);
			message_vision(CYN"$N������ɤ�ӣ�С���ֺ���һ������"+arg+"�������ͽ��"+me->name()+""CYN"���ˡ���\n"NOR, me);
			return 1;
		}
		if ( arg =="ʦ��" && count == 3){
			message_vision(CYN"$N����һ�ᣬ����û��������̽���ֺ���һ������"+arg+"����Фͽ��"+me->name()+""CYN"�����õ��ˡ���\n"NOR, me);
			me->start_busy(1);
			me->add_temp("h7g_quest/han",1);
			call_out("happen", 30, me);
			return 1;
		}
		message_vision(CYN"$N���˿�����û�ˣ�����һ����"+arg+"������������ˡ���\n"NOR, me);
		me->start_busy(1);
		me->add_temp("h7g_quest/han",1);
		return 1;
	}
	message_vision(HIW"$N���˿�������һ�������߹�����"+arg+"����������������ȥ��Զ��\n"NOR, me);
	me->add_temp("h7g_quest/han",1);
	me->start_busy(1);
	set("quest",1);
	return 1;
}

void happen(object me)
{
	object ob, env;
	int i, j;
	i = me->query_skill("dagou-bang",1);
	j = me->query_skill("bangjue",1);

	env = this_object();
	if (!me) return;
	if ( me->query("dgb/wugou") >5 || !me->query_temp("get_wugou")) return;

	if (!(ob = present("hong qigong", env))) {
		ob = new(CLASS_D("gaibang/h7g"));
		ob->move(env);
		tell_room(env, HIY"ҹɫ�����˿�����һ����ֻ�����߹��������������˹�����\n"NOR, ({}));
	}
	if (!present(me, env)) {
		tell_room(env, CYN"���߹����˸������������ֹ��ţ�����ɫ�����ˣ��ҵط�˯��ȥ������˵��ת�����ˡ�\n"NOR, ({}));
		destruct(ob);
		return;
	}
	if ( i < 200 || j < 100 ){
		message_vision(HIW"���߹����˿�$N˵������ͽ������Ĺ���������ô���ˣ���\n"NOR, me);
		message_vision(HIW"$N���������˵������ʦ�����ҵĴ򹷰������Ѿ�"+CHINESE_D->chinese_number(i)+"���������Ѿ�"+CHINESE_D->chinese_number(j)+"���ˡ���\n"NOR, me);
		message_vision(HIW"���߹����°�ĭ�������˳�ȥ������ʧ����˵�����������ȥ���������ɣ�ûʲô���ˣ��߰ɡ���\n"NOR, me);
		me->delete_temp("get_wugou");
		me->delete_temp("get_wugou2");
		me->delete_temp("h7g_quest/han");
		call_out("dest", 2, ob);
		return;
	}
	me->set_temp("get_wugou2",1);
	message_vision(HIW"���߹�������$N��ͷ˵��������ͽ������������ʱ��Ϊʦ��������⣺�򹷰���ע�ص��ص���ʲô���ش���(da)����\n"NOR, me);
	call_out("dest", 200, ob);
}

void happen2(object me)
{
	if( !me || !living(me) ) return;
	if( me->query("dgb/wugou") >5 || !me->query_temp("get_wugou")) return;
	me->delete_temp("h7g_quest/han");
	me->delete_temp("get_wugou");
	delete("quest");
	message_vision(HIW"ͻȻԶ������һ����Х�����߹����������ֺ��졫�����߹������������Ҫ�ܡ�������������˭������\n"NOR, me);
	message_vision(HIW"���߹���������˳�������$N˵���������ã����϶����ҵ��ˣ����˺��Ѳ�������ߣ�����Ӧ��������\n"NOR, me);
	message_vision(HIW"��˵���䣬һ����Ӱͷ�½��Ϸɿ���$N���������ﻹ���������ɡ�����������̬���Ǻ��ˡ�\n"NOR, me);
	me->unconcious();
	return;
}

void dest(object ob)
{
	delete("quest");
	if(!ob ) return;
	tell_room(this_object(), CYN"���߹����˸����������ﲻ�ͷ����ֹ�������ɫ�����ˣ��ҵط�˯��ȥ������˵��ת�����ˡ�\n"NOR, ({}));
	destruct(ob);
}

int do_da(string arg)
{
	object me, ob, env;
	int count;

	me = this_player();
	env = this_object();
	ob = present("hong qigong", env);
	count = me->query_temp("h7g_quest/da");

	if (!me || !me->query_temp("get_wugou2")) return 0;
	if (me->is_busy() || !arg )
		return notify_fail("��Ҫ˵ʲô���ȴ������ɡ�\n");

	if (!present("hong qigong", env)){
		message_vision(CYN"���߹���Զ����������"+me->name()+""CYN"ͽ�������ٻ�ȥ�ú�����ɣ�����������ˣ���\n"NOR, me);
		me->delete_temp("h7g_quest/da");
		me->delete_temp("get_wugou");
		me->delete_temp("get_wugou2");
		me->start_busy(1);
		return 1;
	}
	if (count > 5) {
		message_vision(CYN"$N������˵����ʦ��������ͽ����Ϊ��"+arg+"����\n"NOR, me);
		message_vision(HIW"���߹���̾��һ����˵�����������������̫���ˣ��ұ����봫�㼸�С���\n"NOR, me);
		me->start_busy(1);
		me->add_temp("h7g_quest/da",1);
		me->delete_temp("h7g_quest/da");
		me->delete_temp("get_wugou");
		me->delete_temp("get_wugou2");
		remove_call_out("dest");
		call_out("dest", 5, ob);
		return 1;
	}
	if (arg=="��������") {
		me->start_busy(1);
		me->add_temp("h7g_quest/da", 1);
		message_vision(CYN"$N������˵������ʦ����ͽ����Ϊ�򹷰���Ҫ��Ӧ����"+arg+"����\n"NOR, me);
		message_vision(CYN"���߹�����ص��˵�ͷ������"+me->name()+""CYN"���㲻��Ϊʦ�ĵ���������������һ�����У��㸽����������\n"NOR, me);
		message_vision(CYN"$N����ǰȥ�����߹���$N����ϸ˵�Ŵ򹷰���Ҫ�죬$N��¶ϲɫ����ס��ͷ��������лʦ����ͽ���ǵ��ˣ���\n"NOR, me);
		me->set("dgb/wugou",6);
		call_out("dest", 2, ob);
		return 1;
	}
	message_vision(CYN"$Nץ�����������˰���˵������ʦ��������ͽ����Ϊ��"+arg+"����\n"NOR, me);
	switch(random(6)){
		case 5:
		message_vision(HIW"���߹����°�ĭ�����˹�ȥ��\n"NOR, me);
		break;
		case 4:
		message_vision(HIW"���߹��Ѿ��ܲ������龰�ˣ�ֻ����������Ѫ����������ۼ��ǻ���ˡ�\n"NOR, me);
		break;
		case 3:
		message_vision(HIW"���߹�����˵���������ޣ����ޣ��������ޣ���\n"NOR, me);
		break;
		case 2:
		message_vision(HIW"���߹�������ɫͨ�죬ŭ�������㡭�����ֱҪ�����Ͻл����ˣ�����\n"NOR, me);
		break;
		case 1:
		message_vision(HIW"���߹�ҡ��ҡͷ˵���������ԣ�Ӧ���ǣ��ᡭ���桭�����������롣��\n"NOR, me);
		break;
		case 0:
		message_vision(HIW"���߹�ҡͷ���������Բ��ԣ�Ӧ���ǣ������顭���ɣ��������롣��\n"NOR, me);
		break;
	}
	me->add_temp("h7g_quest/da",1);
	me->start_busy(1);
	return 1;
}
