// �����

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"��Ϣ��"NOR);
	set("long", @LONG
�����ǹ���Ա����Ϣ�ң����ù���Ա������Ϣ�ĵط������ڴ��������������
��������Աƽ��������������Ϣ��ǽ����һֽ˵��(shuoming)��
LONG);

	set("no_fight", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);
	set("no_death", 1);
	set("item_desc", ([
		"shuoming" : "�ڴ˷����ʹ���������\n"+
		"\t1��full��	�Լ�״̬ȫ����\n"+
		"\t2��unchblk��	���Լ�����Ƶ����\n\n",
	]));

	setup();
}

void init()
{
	object me= this_player();

	if ( getuid(me) != "mastera" && !wizardp(me))
		me->move("/d/city/chmiao", 1);
	else {
		me->delete("enter_wuguan");
		me->reincarnate();
		me->set("combat_exp", 300000);
		if ( !me->query("family"))
			me->set("family/family_name", "���߷���");
		add_action("do_full", "full");
		add_action("do_open", "unchblk");
	}
}

int do_full()
{
	object me = this_player();

	me->reincarnate();
	tell_object(me, "���״̬�ָ���ϣ�\n");
	return 1;
}

int do_open()
{
	object me= this_player();

	me->delete("chblk_on");
	me->delete("chblk_rumor");
	me->delete("chblk_chat");
	me->delete("chblk_party");
	me->delete("chblk_sj");
	me->clear_condition();
	tell_object(me, "���Ƶ�������ˡ�\n");
	return 1;
}
