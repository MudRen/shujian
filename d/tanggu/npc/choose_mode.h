void choose_mode(string arg, object me)
{
	int i,p;
	if( arg == "Q" || arg == "q" )    
	{
		command("shrug");
		command("say ֻ�������ɬ�������н�����Ů�����ѡ�Ҳ�գ��ҽ������ϵ����ֲ�ȥ��");
		message_vision(HIY"\n$N����ǰȥ������������д�����ֲ�ȥ��\n"NOR,this_object());
		command("nod "+me->query("id"));
		me->delete_temp("quest/bwzh");
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ȡ����������choose_mode",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/exp")
		&& query("bwzh/per")
		&& query("bwzh/age")) 
	{
		i=me->query("age")-query("bwzh/age");
		if(i<18) i=18;
		p=me->query("age")+query("bwzh/age");
		if(p>80) p=80;
		command("addoil "+me->query("id"));
	   tell_object(me,HIW"��������Ŀ�еķ����Ҫ���������£�\n\n"NOR);
	   tell_object(me,HIR"  1�������顿��;���"+chinese_number(query("bwzh/exp"))+"�ס�\n"NOR);
	   tell_object(me,HIR"  2������ò�������ò"+chinese_number(query("bwzh/per"))+"��\n"NOR);
	   tell_object(me,HIR"  3�������䡿��"+chinese_number(i)+"���"+chinese_number(p)+"��֮�䡣\n"NOR); 
	   tell_object(me,HIW"\n�����ͬ�⣬����ѡ��\n"NOR);
	   tell_object(me,WHT"��Y��ͬ�� ��R����ѡ ��Q��ȡ��\n"NOR);
	   input_to( (: choose_ok :), me );
	   return;
	}
	if(arg != "1"  && arg != "2" && arg != "3") 
	{
	   command("? "+me->query("id"));
	   tell_object(me,HIW"��������Ա�ע������Ŀ�еķ���Ĳ���Ҫ��\n\n"NOR);
	   if(!query("bwzh/exp")) tell_object(me,WHT"  1�������顿"NOR);
	   if(!query("bwzh/per")) tell_object(me,WHT"  2������ò��"NOR);
	   if(!query("bwzh/age")) tell_object(me,WHT"  3�������䡿"NOR); 
	   tell_object(me,HIW"\n\n�����ѡ�����֣���Ҳ����Q��ȡ����\n"NOR);
	   input_to( (: choose_mode :), me );
	   return;
	}  
	if((arg == "1" && query("bwzh/exp"))
		|| (arg == "2" && query("bwzh/per"))
		|| (arg == "3" && query("bwzh/age"))) 
	{
	   command("say ��һ����Ѿ����ý������㻹��Ҫ�����������");
	   tell_object(me,"\n");
	   if(!query("bwzh/exp")) tell_object(me,WHT"  1�������顿"NOR);
	   if(!query("bwzh/per")) tell_object(me,HIW"  2������ò��"NOR);
	   if(!query("bwzh/age")) tell_object(me,HIW"  3�������䡿"NOR); 
	   tell_object(me,HIW"\n\n�����ѡ�����֣���Ҳ����Q��ȡ����\n"NOR);
	   input_to( (: choose_mode :), me );
	   return;
	}  
 	if(arg=="1")
	{
		if(me->query("combat_exp")>=1000000 )
			command("say "HIC"���Լ��ľ������ڴ�Լ"+chinese_number(me->query("combat_exp")/1000000)+"�ס�");
		else command("say "HIC"���Լ��ľ������ڻ�����һ�ס�");
		command("say "HIC"�㽫�������ֵ������Ҫ����ķ������С����ֵ��");
		command("say "HIC"ע�ⵥλ��M��1M=1000000������Ҳ����Q��ȡ����"NOR);
		input_to( (: choose_exp :), me );
	}
	else if(arg=="2")
	{
		command("say "HIC"�㽫�������ֵ������Ҫ����ķ������С��òֵ��");
		command("say һ����˵��ò��ʮ�ģ������ٷ磬�������Σ����ƾ������У�");
		command("say ��ò��ʮ���ң�������ٶ�������òƽƽ��");
		command("say ��ʮ�����ң����е�ţ��¿������Ŀ������");
		if(me->query("per")>=10)
			command("say ���Լ�����òӦ����"+chinese_number((me->query("per")/10)*10)+"���ϡ�");
		else command("say ���Լ�����òȷʵһ��Ŷ���ٺ١�");
		command("say "HIC"���Լ�����ѡ����Ҳ����Q��ȡ����"NOR);
		input_to( (: choose_per :), me );
	}
	else
	{
		command("say "HIC"�㽫�������ֵ������Ҫ����ķ�����������������");
		command("say "HIC"������������ֵΪ��ʮ�������Ѿ�"+chinese_number(me->query("age"))+"�ꡣ"NOR);
		command("say "HIC"ͬʱע�⣬����Ҫ��������Ͳ���ʮ���꣬��߲��ð�ʮ�ꡣ"NOR);
		i=me->query("age")-20;
		if(i<18) i=18;
		p=me->query("age")+20;
		if(p>80) p=80;
		command("say "HIC"���ԣ���ʵ��Ҫ����������Σ�"+chinese_number(i)+"�굽"+chinese_number(p)+"�ꡣ"NOR);
		command("hehe");
		input_to( (: choose_age :), me );
	}
	return;
}
