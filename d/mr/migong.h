int valid_leave(object me, string dir)
{
	if (dir == "west")
		me->add_temp("mark/lvl",1);
	if (dir == "south")
		me->add_temp("mark/lvls",1);
	if (dir == "east")
		me->add_temp("mark/lvl",-1); 
	if (dir == "north")
		me->add_temp("mark/lvls",-1);

	if (me->query_temp("mark/lvl") == -6 
	 && me->query_temp("mark/lvls") == -7
	 && random(me->query("int"))>20) {
		me->move(__DIR__"kongfang");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("���������ţ�Ī��������߽���һ���շ��䡣\n");
	}
	if (me->query_temp("mark/lvls") == -6
	 && me->query_temp("mark/lvl") == 5) {
 		me->move(__DIR__"zhengtang");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("�������ţ�ͻȻ����ǰ����һ���ƹ�, ����ŵƹ����˹�ȥ��\n");
	}
	if (me->query_temp("mark/lvls") > 20 
	|| me->query_temp("mark/lvls") < -20) {  
		me->move(__DIR__"didao2");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("��׷��˰��쾢, ���߻���ԭ�ء�\n");
	}
	if (me->query_temp("mark/lvl") > 20
	 || me->query_temp("mark/lvl") < -20) {  
		me->move(__DIR__"didao2");
		me->delete_temp("mark/lvls");
		me->delete_temp("mark/lvl");
		return notify_fail("��׷��˰��쾢, ���߻���ԭ�ء�\n");
	}
	return ::valid_leave(me, dir);
}
