void init()
{
	if (environment() == this_player())
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me,ob;
	int i, j;
	me = this_player();
	ob = this_object(); 
	i = (int)me->query_skill("medicine", 1);
	j = (int)me->query_skill("literate", 1);

	if(!(arg==ob->query("id")||arg=="medicine book")) return 0;
      
	if(!me->query_skill("literate", 1))
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");	   
	if (me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(i <= 100 && i > j+10)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о�������ı�������\n"); 
	if(i > 100 && i <= 150 && i > j+15)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о�������ı�������\n");
	if(i > 150 && i > j+20)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о�������ı�������\n");
	if (!random(20))
		message("vision", me->name()+"��ר�ĵ��ж�"+this_object()->name()+"��\n", environment(me), me);       
	if( me->query("jing") < ob->query("jing_cost"))
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
	if( me->query("combat_exp") < ob->query("exp_required"))
		return notify_fail("���ʵս���鲻�����и�����ı�������\n");	
	if( me->query("combat_exp") < i*i*i/10 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");	
	if( me->query_int() < ob->query("difficulty"))
		return notify_fail("���ж���һ��������ָ���������������дЩʲô��\n");
	if(i < ob->query("min_skill"))
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫���ˣ�û��ѧ���κζ�����\n");
	if(i > ob->query("max_skill"))
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

	me->receive_damage("jing", ob->query("jing_cost")); 
	me->improve_skill("medicine", me->query_int()/2);
	write("����ϸ�ж���"+ob->name()+"��\n");
	return 1;
}
