// by ����Ӣ��

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"���ټ����š�"NOR, ({ "art's book", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"һ����װͼ�ף��ϻ��硢�������̡�������֮���Ż�����\n"+
			"������ж���Read�����������������ټ���\n"NOR);
		set("value", 500);
		set("material", "paper");
		set("exp_required",100000);
		set("jing_cost", 18);
		set("difficulty", 28);
		set("max_skill", 30);
	}
}

void init()
{
	if( environment() == this_player() )
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me,ob;
	int i, j;

	me = this_player();
	ob = this_object(); 

	i = (int)me->query_skill("art", 1);
	j = (int)me->query_skill("literate", 1);

	if( !(arg == ob->query("id") || arg == "book") ) return 0;

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");	   

	if( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() ) 
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if( !id(arg) )
		return notify_fail("��Ҫ��ʲô��\n");

	if( j < 100 )
		return notify_fail("��Ķ���д�ֵȼ��������޷�������м��صġ������ټ�����\n"); 

	if( !random(5) )
		message("vision", me->name() + "��ר�ĵ��ж�" + this_object()->name()+"��\n", environment(me), me);

	if( (int)me->query("jing") < ob->query("jing_cost") )
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

	if( (int)me->query("combat_exp") < ob->query("exp_required"))
		return notify_fail("���ʵս���鲻�����и�����ġ������ټ�����\n");	

	if( (int)me->query("combat_exp") < i*i*i/10 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

	if( me->query_int() < ob->query("difficulty") )
		return notify_fail("���ж���һ��������ָ���������������дЩʲô��\n");

	if( i < ob->query("min_skill") )
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫���ˣ�û��ѧ���κζ�����\n");

	if( i > ob->query("max_skill") )
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

	me->receive_damage("jing", ob->query("jing_cost")); 
	me->improve_skill("art", me->query_int()/3 + 3);
	write("����ϸ�ж���"+ob->name()+"�������Լ�������֮���������档\n");
	return 1;
}
