int write_qi(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/can_marry")) return 0;
    message_vision(HIY"\n$N��üһ��������˫����׼����ǰȥ�ڽ����������Լ������֡�\n"NOR,me);
	if(query("station")>0)
	{
		command("smile "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say �Ѿ��������ڱ������ף�����ԣ�Look qi����������Ϣ��");	
		return 1;
	}
    if(check_player(me,0)) return 1;

	if(time()-over_time<WAIT_TIME)
	{
		command("pat "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say �ղ����˲ű������׽��������Ժ������ɡ�");	
		return 1;
	}
	if(arg!="myself" && arg!=me->query("id"))
	{
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("smile "+me->query("id"));	
		command("say Ϊ���˱���������ʱû�п�ͨ��");	
		return 1;
	}
	message_vision(HIR"��˵�ǽ�����Ů��������̬֮�������ߵ���˫��糺졣\n"NOR,me);
	command("smile "+me->query("id"));
	command("addoil "+me->query("id"));
	delete("bwzh");
	set("bwzh/host_player/id",me->query("id"));
	set("bwzh/host_player/name",me->query("name"));
	set("bwzh/host_player/object",me);//�����Ů
	set("station",1);//busy 

	log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʼ��������write_qi",me->query("name"),me->query("id")),me);
    tell_object(me,HIW"\n��������Ա�ע������Ŀ�еķ���Ĳ���Ҫ��\n\n"NOR);
    if(!query("bwzh/exp")) tell_object(me,WHT"  1�������顿"NOR);
	if(!query("bwzh/per")) tell_object(me,WHT"  2������ò��"NOR);
    if(!query("bwzh/age")) tell_object(me,WHT"  3�������䡿"NOR);
    tell_object(me,HIW"\n\n�����ѡ�����֣���Ҳ����Q��ȡ����\n"NOR);
	input_to( (: choose_mode :), me );
	return 1;
}