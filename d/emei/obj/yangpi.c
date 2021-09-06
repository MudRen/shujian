// yangpi.c
// Modified by Lane@SJ

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"ɽ��Ƥ"NOR, ({ "shanyang pi", "yangpi", "pi" }));
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ��ɽ��Ƥ������д�������ϣ��Źֵ��֡�\n");
		set("treasure", 1);
		set("value", 200000);
		set("material", "skin");
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
		set("no_steal", 1);
	}
}

void init()
{
	add_action("do_du", "read");
}

int do_du(string arg)
{
	object me = this_player();
	int level;

	if( !id(arg) ) return 0;

	if( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if( !me->query("quest/jiuyin2/emei") )
		return notify_fail("������޷����ɽ��Ƥ��ϣ��Źֵ��֣�\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");        

	if( me->query("jing") < 30 )
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

	if( me->query_int() < 32 )
		return notify_fail("����������Բ������޷���ϰɽ��Ƥ��\n");

	if( me->query("combat_exp") < 1500000 )
		return notify_fail("���ʵս���鲻�����޷����ɽ��Ƥ�ϵ����֡�\n");

	level = me->query_skill("jiuyin-baiguzhua", 1);

	if( level >= 62 )
		return notify_fail("ɽ��Ƥ�ϵ����ֶ�������Ѿ�̫ǳ�ˡ�\n");

	me->receive_damage("jing", 30);
	write("���ж���ɽ��Ƥ���ϵ����֣������ĵá�\n");
	me->improve_skill("jiuyin-baiguzhua", me->query_skill("literate", 1)+level);
	if( !random(9) ) message("vision", me->name() + "��������һ��ɽ��Ƥ��\n", environment(me), ({me}));
	return 1;
}
