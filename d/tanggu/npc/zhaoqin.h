void zhaoqin(object me,object who)
{
	object ob=this_object();
	remove_call_out("zhaoqin");
	if(!me || !me->query_temp("quest/bwzh/over"))
	{
		if(!me) log_file("quest/zhaoqin",sprintf("%-8s%-10s ��Ů��Ϣ��ʧzhaoqin",ob->query("name"),ob->query("id")),ob);
		else log_file("quest/zhaoqin",sprintf("%-8s%-10s ��Ů��Ƕ�ʧzhaoqin",ob->query("name"),ob->query("id")),ob);
		init_over();
		return;	
	}
	if(!who || !who->query_temp("quest/bwzh/over")) 
	{
		if(!who) log_file("quest/zhaoqin",sprintf("%-8s%-10s ������Ϣ��ʧzhaoqin",ob->query("name"),ob->query("id")),ob);
		else log_file("quest/zhaoqin",sprintf("%-8s%-10s ������Ƕ�ʧzhaoqin",ob->query("name"),ob->query("id")),ob);
		init_over();
		return;	
	}

	if(environment(me)!=environment(ob))
	{
		command("chat* angry "+me->query("id"));	
        command("chat "+HIY+me->query("name")+"�����ǲ�������Է�������˵�߾��ߣ�������£�����ᱡ��"NOR);
		if(environment(who)==environment(ob))
			command("shrug "+getuid(who));	
		tell_object(who,"��Ϊ"+me->query("name")+"�����뿪�����ױ�����ֹ��\n");
		tell_object(me,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣\n");
		me->add("combat_exp",-100000);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʧʮ����zhaoqin",me->query("name"),me->query("id")),me);
		init_over();
		return;
	}
	if(environment(who)!=environment(ob))
	{
        command("chat "+HIY+who->query("name")+"�Ȳ�ԸȢ������ô�³����䣿������£�����ᱡ��"NOR);
		command("chat* heng");
		command("chat* poor "+me->query("id"));	
		tell_object(who,"��Ϊ"+who->query("name")+"�����뿪�����ױ�����ֹ��\n");

		tell_object(who,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣");
		who->add("combat_exp",-100000);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʧʮ����zhaoqin",who->query("name"),who->query("id")),who);
		init_over();
		return;
	}
	command("smile "+getuid(ob));	
	command("smile "+me->query("id"));
	command("say ������Ӣ�ۣ���λ�ɲ�Ůò������֮�ϣ�"+me->query("name")+"�����㻹��ʲô����������䶼���ˣ���Ը��޸�"+who->query("name")+"ô��");
	tell_object(who,HIY"����Իش� answer y ���� answer n ��ʾ��ͬ����߾ܾ����Ż��£�\n"NOR);
	who->set_temp("quest/bwzh/marry_object",me);
	tell_object(me,HIY"����Իش� answer y ���� answer n ��ʾ��ͬ����߾ܾ����Ż��£�\n"NOR);
	me->set_temp("quest/bwzh/marry_object",who);
	remove_call_out("answer_check");
	call_out("answer_check",10,me,who,0);
	return;
}
void answer_check(object me,object who,int i)
{
	object ob=this_object();
	int p;
	remove_call_out("answer_check");
	if(!me || !me->query_temp("quest/bwzh/over") || environment(me)!=environment(ob))
	{
        command("chat* hmm");
        command("chat "+HIY+"��δ�ҶԴ���������ḡ�������ǲ�������Է�������˵�߾��ߣ�"NOR);
		if(me)
		{
			tell_object(me,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣\n");
			me->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʧʮ����answer_check",me->query("name"),me->query("id")),me);
		}
		init_over();
		return;	
	}
	if(!who || !who->query_temp("quest/bwzh/over") || environment(who)!=environment(ob))
	{
        command("chat* hmm");
        command("chat "+HIY+"��δ�ҶԴ���������ḡ�������ǲ�������Է�������˵�߾��ߣ�"NOR);
		if(who)
		{
			tell_object(who,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣\n");
			who->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʧʮ����answer_check",who->query("name"),who->query("id")),who);
		}
		init_over();
		return;	
	}
	if(i>=9)
	{
		if(!who->query_temp("quest/bwzh/marry_yes"))
		{
			tell_object(who,HIY"��ô��ʱ�仹û�о�������ȡ���㡣\n"NOR);
			tell_object(who,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣\n");
			who->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʧʮ����answer_check",who->query("name"),who->query("id")),who);
		}
		if(!me->query_temp("quest/bwzh/marry_yes"))
		{
			tell_object(me,HIY"��ô��ʱ�仹û�о�������ȡ���㡣\n"NOR);
			tell_object(me,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣\n");
			me->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʧʮ����answer_check",me->query("name"),me->query("id")),me);
		}
        command("chat* hmm "+who->query("id"));
        command("chat* hmm "+me->query("id"));
        command("chat "+HIY+"��δ�ҶԴ���������ḡ����ȴ��£���Ȼ�ٳٲ�����Ӧ��"NOR);
		init_over();
		return;	
	}
	i=i+1;
	p=100-i*10;
	command("smile "+getuid(ob));	
	command("smile "+me->query("id"));
	tell_object(me,HIC"�㻹��"+chinese_number(p)+"�������\n"NOR);
	tell_object(who,HIC"�㻹��"+chinese_number(p)+"�������\n"NOR);
	call_out("answer_check",10,me,who,i);
	return;
}