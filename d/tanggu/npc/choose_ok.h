void choose_ok(string arg, object me)
{
	int i,p;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh "+me->query("id"));
		command("say ֻ�������ɬ�������н�����Ů�����ѡ�Ҳ�գ��ҽ������ϵ����ֲ�ȥ��");
		message_vision(HIY"\n$N����ǰȥ������������д�����ֲ�ȥ��\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ȡ����������choose_ok",me->query("name"),me->query("id")),me);
		return;
	}
	if(arg == "R" || arg == "r" ) 
	{
	   command("nod "+me->query("id"));
	   delete("bwzh/exp");
	   delete("bwzh/per");
	   delete("bwzh/age");
	   tell_object(me,HIW"\nԭ������ȫ��������������������ã�\n\n"NOR);
	   if(!query("bwzh/exp")) tell_object(me,WHT"  1�������顿"NOR);
	   if(!query("bwzh/per")) tell_object(me,WHT"  2������ò��"NOR);
	   if(!query("bwzh/age")) tell_object(me,WHT"  3�������䡿"NOR); 
	   tell_object(me,HIW"\n\n�����ѡ�����֣���Ҳ����Q��ȡ����\n"NOR);
       input_to( (: choose_mode :), me );
	   return;
	}
	i=me->query("age")-query("bwzh/age");
	if(i<18) i=18;
	p=me->query("age")+query("bwzh/age");
	if(p>80) p=80;

	if(arg != "Y" && arg != "y" ) 
	{
		command("? "+me->query("id"));
		tell_object(me,HIW"\n��������Ŀ�еķ����Ҫ���������£�\n\n"NOR);
		tell_object(me,HIR"  1�������顿��;���"+chinese_number(query("bwzh/exp"))+"�ס�\n"NOR);
		tell_object(me,HIR"  2������ò�������ò"+chinese_number(query("bwzh/per"))+"��\n"NOR);
		tell_object(me,HIR"  3�������䡿��"+chinese_number(i)+"���"+chinese_number(p)+"��֮�䡣\n"NOR); 
		tell_object(me,HIW"\n�����ͬ�⣬����ѡ��\n"NOR);
		tell_object(me,WHT"��Y��ͬ�� ��R����ѡ ��Q��ȡ��\n"NOR);
		input_to( (: choose_ok :), me );
		return;
	}
    log_file("quest/zhaoqin",sprintf("%-8s%-10s �����������choose_ok",me->query("name"),me->query("id")),me);

	over_time=time();//�ٺ�
	start_time=time();
	set("bwzh/host_player/name",me->query("name"));//��Ů��Ϣ
	set("bwzh/host_player/id",me->query("id"));
	set("bwzh/host_player/object",me);
	set("bwzh/winner_player/name",me->query("name"));//��������Ů
	set("bwzh/winner_player/id",me->query("id"));
	set("bwzh/winner_player/object",me);
	set("station",2);//��һ��״̬
	me->set_temp("quest/bwzh/biwu_host",1);//�����ı��
	me->set_temp("quest/bwzh/hoster",1);//�����˵ı�ǣ���Ů���
	me->set_temp("quest/busy",1);//����������
	me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <���������У�������> "NOR}));	
	
	message_vision(HIR"\n$N�ڽ����Ա�ע������Ҫ�󣬰��������顿������ò���������䡿��\n"NOR,me);
	command("pat "+me->query("id"));
	command("addoil "+me->query("id"));

	command("chat* smile "+me->query("id"));
	CHANNEL_D->do_channel(this_object(),"chat",HIY+me->query("name")+"���ڱ������ף���ӭ��·���ܿ�ӻԾ������"NOR);
	command("chat* addoil");

	tell_object(me,HIW"\n�����ڿ�ʼ�ȴ���ע���һ���������㱾�ˡ����⣬�����ȡ����cancel�����ף�\nҲ����������Ȱ����η�����Ϣ��fabu xiaoxi����\n"NOR);
	remove_call_out("biwu_over");
	remove_call_out("checking");
	call_out("checking",1);
	call_out("biwu_over",NEXT_TIME);
  	return;
}
