#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("ѩ¶��", ({"xuelu wan", "wan", }));   
	set("no_drop",1);
	set("no_get",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�Ө��͸����ҩ�裬ǳ��ɫ����һ�����㣬��ҩ���������ش�����ɽѩ�������ݺϳɣ������������Ч�ޱȡ�\n");
		set("value", 10000);     
		set("no_drop",1);
	set("no_get",1);
		
	}

	set("tialongsi",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill_mapped("force") != "qiantian-yiyang" )
      {
       if ( me->query_skill_mapped("force") != "kurong-changong" )
	{
	/*
		if (me->add("max_jingli", -20) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -20) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N����һ��ѩ¶�裬ֻ���øγ���ϣ�ԭ�������ڹ���������������������\n" NOR, me);
		me->unconcious();
		destruct(this_object());
	*/
		write("�����ڹ���������ҩ�㻹�ǲ�Ҫ�Եĺã�\n");
		return 1;
	}
      } 

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		if (me->add("max_jingli", -1) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -1) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N����һ��ѩ¶�裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("max_jingli", 1);
		me->add("eff_jingli", 1);
		message_vision(HIY "$N����һ��ѩ¶�裬ֻ����������Ȼ��ߣ�ȫ����������ľ�����\n" NOR, me);
		me->apply_condition("bonze_drug", 25);
	}
	
	destruct(this_object());
	return 1;
}
