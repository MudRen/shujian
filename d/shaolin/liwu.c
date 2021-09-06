//liwu

#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", HIW"����"NOR);
	set("long",@LONG
���ݵĳ���͸��Ӽ򵥣�һ�ѷ�����һ�����棬�������һ����ɮ����
��Ŀ�붨��
LONG
    );
	set("exits",([
		"out"  :    __DIR__"houyuan",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		CLASS_D("shaolin") + "/wumingseng" : 1,
	]));
	set("valid_startroom", 1);
	setup();
}

void init()
{
	add_action("do_sangong", "sangong");
}

int do_sangong()
{
	object me = this_player();
	int i, rmd, ryb;
	
	i = me->query("max_neili");
	rmd = me->query_skill("ranmu-daofa", 1);
	ryb = me->query_skill("riyue-bian", 1);

	if (!me->query_temp("sangong")) return 0;
	
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	
	if ( ! present("wuming laoseng", environment(me)))
		return notify_fail("��ʦ����������ߣ�����ɢ����������Σ�ա�\n");

	message_vision(HIW"\n������ɮ��$Nͷ����������˼��£�����$Nͷ��ð��һ�ɰ���������������\n"NOR, me);
	
	switch (me->query_temp("sangong")){
		case "pass_xin":
			me->delete("pass_xin");
			me->set_skill("weituo-chu", rmd);
			me->delete_skill("ranmu-daofa");
			break;
		case "passdu" :
			me->delete("passdu");
			me->set_skill("weituo-chu", ryb);
			me->delete_skill("riyue-bian");
			break;
		default : return notify_fail("�棿�����⣬�뱨��wiz��\n");
	}
	me->add("max_neili", -i/2);
	me->set_skill("buddhism", 180);
	me->set("sl_wtc", 1);
	me->set("no_recover", 1);
	me->delele_temp("sangong");
	message_vision(HIR"\n$N�����죬��ɫ����ʹ�࣬�·��ھ����ܴ��ĥ�ѡ���\n\n"NOR, me);
	me->unconcious();
	return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("sangong");
	return ::valid_leave(me, dir);
}
