int do_lingwu(string arg)
{
	object me=this_player();
	object who=this_object();
	int i = me->query_skill("douzhuan-xingyi", 1);
        int lv = me->query("max_pot")-100;
	if( !living(who))
		return notify_fail("Ľ�ݸ����ڵ�״���������޷��ش����κ����⡣\n");

	if ( me->query("family/family_name") != "����Ľ��")
		return notify_fail("�����Ľ�ݵ��ӣ������ֽ�ʲô����\n");

	if (!arg || arg !="douzhuan-xingyi" ){
		message_vision("$N��$n�ֽ�һЩ������ѧ�ϵ����ʡ�\n", me, who);
		command("dunno "+me->query("id"));
		return 1;
	}
	if (me->is_busy() || me->is_fighting()){
		command("say ����æ�Ÿɱ�������أ�æ������˵�ɡ�");
		return 1;
	}
	if( me->query("jing") < 10)
		return notify_fail("��̫���ˣ�������Ϣһ��ɡ�\n");
	if((int)me->query("potential", 1) < 1 )
		return notify_fail("��Ǳ�ܲ�����\n");
	if ( i <= 50 ){
		command("say ��Ķ�ת���Ƶȼ������������ܴ�������ѧ��ʲô��");
		return 1;
	}
	write("����Ľ�ݸ��ֽ̹��ڡ�" + to_chinese(arg) + "�������ʡ�\n");
	write(HIC"������Ľ�ݸ���ָ�㣬���򵽶�ת���Ƶľ������ڡ�\n");
	write(HIR"���[��ת����]��ߵ�����Ŀǰʵս�������Ƶ���߼���\n");
      me->set_skill("douzhuan-xingyi", lv);

       if (i >= lv -1)
         {
		command("say ���ʵս���鲻�����޷�����ʲô��");
		return 1;
	}
        
	return 1;
}