void choose_exp(string arg, object me)
{
	int exp;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh");
		command("say ֻ�������ɬ�������н�����Ů�����ѡ�Ҳ�գ��ҽ������ϵ����ֲ�ȥ��");
		message_vision(HIY"\n$N����ǰȥ������������д�����ֲ�ȥ��\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ȡ����������choose_exp",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/exp")) 
	{
	   command("? "+me->query("id"));
	   choose_other(me,1);
	   return;
	}
	if(!sscanf(arg, "%d", exp))
	{
		command("say "HIC"������һ�����ֱ�ʾ���顣");
		command("hammer "+me->query("id"));
		input_to( (: choose_exp :), me );
		return;
	}
	if(exp<1 || exp>99)
	{
		command("say "HIC"���������ֵ������Ҫ��0<EXP<99����");
		command("hmm "+me->query("id"));
		input_to( (: choose_exp :), me );
		return;
	}
	command("nod "+me->query("id"));
	set("bwzh/exp",exp);
	choose_other(me,1);
	return;
}
void choose_per(string arg, object me)
{
	int per;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh");
		command("say ֻ�������ɬ�������н�����Ů�����ѡ�Ҳ�գ��ҽ������ϵ����ֲ�ȥ��");
		message_vision(HIY"\n$N����ǰȥ������������д�����ֲ�ȥ��\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ȡ����������choose_per",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/per")) 
	{
	   command("? "+me->query("id"));
	   choose_other(me,2);
	   return;
	}
	if(!sscanf(arg, "%d", per))
	{
		command("say ������һ�����ֱ�ʾ��ò��");
		command("kick "+me->query("id"));
		input_to( (: choose_per :), me );
		return;
	}
	if(per<1 || per>50)
	{
		command("say "HIC"���������ֵ������Ҫ��0<PER<50����");
		input_to( (: choose_per :), me );
		return;
	}
	command("nod "+me->query("id"));
	set("bwzh/per",per);
	choose_other(me,2);
	return;
}
void choose_age(string arg, object me)
{
	int age;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh");
		command("say ֻ�������ɬ�������н�����Ů�����ѡ�Ҳ�գ��ҽ������ϵ����ֲ�ȥ��");
		message_vision(HIY"\n$N����ǰȥ������������д�����ֲ�ȥ��\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ȡ����������choose_age",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/age")) 
	{
	   command("? "+me->query("id"));
	   choose_other(me,3);
	   return;
	}
	if(!sscanf(arg, "%d", age))
	{
		command("claw "+me->query("id"));
		command("say "HIC"������һ�����ֱ�ʾ����");
		input_to( (: choose_age :), me );
		return;
	}
	if(age<1 || age>me->query("age"))
	{
		command("say "HIC"���������ֵ������Ҫ��0<AGE<"+me->query("age")+"����");
		input_to( (: choose_age :), me );
		return;
	}
	command("nod "+me->query("id"));
	set("bwzh/age",age);

	choose_other(me,3);
	return;
}
void choose_other(object me,int x)
{
    int i,p;
	if(!me) return;
	i=me->query("age")-query("bwzh/age");
	if(i<18) i=18;
	p=me->query("age")+query("bwzh/age");
	if(p>80) p=80;
    
	if(x==1)
		tell_object(me,HIW"\n���Ѿ��趨����;��飺"+chinese_number(query("bwzh/exp"))+"�ס�\n"NOR);
	else if(x==2)
		tell_object(me,HIW"\n���Ѿ��趨�������ò��"+chinese_number(query("bwzh/per"))+"��\n"NOR);
	else 
		tell_object(me,HIW"\n���Ѿ��趨�����䣺"+chinese_number(i)+"��----"+chinese_number(p)+"�꡿\n"NOR);

	if(query("bwzh/exp")
		&& query("bwzh/per")
		&& query("bwzh/age")) 
	{
		command("addoil "+me->query("id"));
		tell_object(me,HIW"\n��������Ŀ�еķ����Ҫ���������£�\n\n"NOR);
		tell_object(me,HIR"  1�������顿��;���"+chinese_number(query("bwzh/exp"))+"�ס�\n"NOR);
		tell_object(me,HIR"  2������ò�������ò"+chinese_number(query("bwzh/per"))+"��\n"NOR);
		tell_object(me,HIR"  3�������䡿��"+chinese_number(i)+"���"+chinese_number(p)+"��֮�䡣\n"NOR); 
		tell_object(me,HIW"\n�����ͬ�⣬����ѡ��\n"NOR);
		tell_object(me,WHT"��Y��ͬ�� ��R����ѡ ��Q��ȡ��\n"NOR);
		input_to( (: choose_ok :), me );
		return;
	}
	tell_object(me,HIW"\n�����ѡ����������Ҫ��\n\n"NOR);
	if(!query("bwzh/exp")) tell_object(me,WHT"  1�������顿"NOR);
	if(!query("bwzh/per")) tell_object(me,WHT"  2������ò��"NOR);
	if(!query("bwzh/age")) tell_object(me,WHT"  3�������䡿"NOR); 
	tell_object(me,HIW"\n\n�����ѡ�����֣���Ҳ����Q��ȡ����\n"NOR);
	input_to( (: choose_mode :), me );
	return;
}