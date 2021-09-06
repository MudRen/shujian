// by ����Ӣ��

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"����ս��������ı�ԡ�"NOR, ({ "gunnery's book", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"����һ��ʩ�Ž�������ĺ�ս��������ı�Աʼǣ�\n"+
			"������Լ�Ӧ����ϸ�ж���Read��һ�¡�\n"NOR);
		set("value", 1);
		set("material", "paper");
                            set("treasure", 1);
		set("jing_cost", 18);
		set("difficulty", 1);
//                 set("max_skill", 1);
                            set("treasure", 1);
set("unique", 1);


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

	i = (int)me->query_skill("gunnery", 1);
	j = (int)me->query_skill("literate", 1);

	if( !(arg == ob->query("id") || arg == "book") ) return 0;

	if( !me->query_skill("literate", 50) )
		return notify_fail("�㼸�����Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");	   

	if( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() ) 
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if( !id(arg) )
		return notify_fail("��Ҫ��ʲô��\n");

	if( !random(5) )
		message("vision", me->name() + "��ר�ĵ��ж�" + this_object()->name()+"��\n", environment(me), me);

	if( (int)me->query("jing") < ob->query("jing_cost") )
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

	if( me->query_int() < ob->query("difficulty") )
		return notify_fail("���ж���һ��������ָ���������������дЩʲô��\n");

	if( i > ob->query("max_skill") )
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

	me->receive_damage("jing", ob->query("jing_cost")); 
	me->improve_skill("gunnery", me->query_int() + 30);
	write("����ϸ�ж���"+ob->name()+"�������Լ���ս�Ե������������ࡣ\n");
	return 1;
}
