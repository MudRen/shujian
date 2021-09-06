// jianpu.c ��а����
#include <ansi.h>
inherit ITEM;

void init()
{
	if (environment() == this_player())
		add_action("do_du", "read");
}

void create()
{
	set_name(MAG"�Ͻ�����"NOR, ({ "zijin jiasha", "jiasha", "book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������ò��������ġ�����ϸһ������������������д��Щ���֡�\n");
		set("value", 1);
		set("unique", 1);
		set("treasure", 1);
		set("material", "silk");
		set("no_give", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
	}
}

int do_du(string arg)
{
	object me = this_player();

	int pxlevel; 
	int neili_lost;

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy()) 
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() ) 
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if (me->query("gender") == "Ů��" )
		return notify_fail("��ϧ����Ů�����޷���������ֵ���˼��\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ܶ��飡\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���Ҳ��ܶ��飬��Ӱ�������Ϣ��\n");

	if ( query("reader") != me->query("id"))
		return notify_fail("�㷢�������������һ��Ҳ�����塣\n");
/*
	if ((string)me->query("gender") == "����" ) {
		if( (int)me->query_temp("pxj_jiasha") ){
			write("��տ���һС�����֣���Ȼ��������ǡ�ȫ�����ȣ�ͷ��һ��ѣ�Ρ�\n");
			me->unconcious();
			me->add("max_neili", -10);
			return 1;
		}
		else {
			write("�㷢����һ������д�ţ������񹦣������Թ���\n");
			me->set_temp("pxj_jiasha", 1);
			return 1;
		}
	}
*/
	if(!me->query_skill("literate", 1))
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");    

	if (!random(8))
		message("vision", me->name() + "͵͵��������һ�����ڶ���\n", environment(me), me);          

	if( me->query("jing") < 25 )
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

	if ( me->query_skill("pixie-jian", 1) > 120) neili_lost = 20;
	else if ( me->query_skill("pixie-jian", 1) > 80) neili_lost = 15;
	else neili_lost = 10;

	if( me->query("combat_exp") < 100000)
		return notify_fail("���ʵս���鲻��������ô������书��\n");

	if( me->query_skill("literate", 1) < 100 || me->query_int(1) < 30)
		return notify_fail("�㿴������������д�����֡�\n");

	if( me->query("neili") < neili_lost)
		return notify_fail("�������������޷�������ô������书��\n");
	pxlevel = me->query_skill("pixie-jian", 1);
	if( me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
/*
	if( me->query_skill("pixie-jian", 1) > 29)
	if ((!objectp(ob = present("needle", me)) ) || (!ob->query("equipped") ))
		return notify_fail("��û���廨�룬�е��޷�����������������书��\n");
*/
	if(me->query_skill("pixie-jian", 1) > 150)
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

	me->receive_damage("jing", 15);
	me->add("neili", - neili_lost);
	me->improve_skill("pixie-jian", me->query_skill("literate", 1)/3+1);
	write("����ϸ�ж��������ϵ����֡�\n");
	return 1;
}
