int check_player(object me,int i)
//���Ů��(0)������(1)
{
	mapping mp;
	object ob=this_object();
    object *obj;
    int p;

	if(!me) return 1;
	if(me->query("gender")!="Ů��" && me->query("gender")!="����" )
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say Ŀǰ�����˻�����ʱδ���š�");	
		command("hoho "+me->query("id"));	
		return 1;
	}
	switch (me->query("class")) {
		case "bonze":
		case "huanxi":
		case "lama":
		case "taoist":
			command("look "+me->query("id"));
			message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
			command("say "+me->query("name")+"�ǻ����Ժ�����̸���ۼްɡ�");	
			return 1;
	}
	if(me->query("gender")!="Ů��" && i==0)
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say "+me->query("name")+"�ǲ��Ǻȶ��ˣ����Լ��Ա�Ҳ�����ˣ�����ү��Ҳ���������ף�");	
		command("laugh "+me->query("id"));	
		return 1;
	}
	if(me->query("gender")!="����" && i)
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say Ŀǰ�齣�ݲ�����ͬ�������ܡ�");	
		command("shrug "+me->query("id"));	
		return 1;
	}
	if(me->query("age") < 18)
	{
		command("shrug "+me->query("id"));	
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say "+me->query("name")+"��ôС��ô�У��ȳ���һ��������˵��°ɡ�");	
		command("pat "+me->query("id"));	
		return 1;
	}
	if(me->query("age") > 80)
	{
		command("shrug "+me->query("id"));	
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		if(i) command("say ������ô˵��......"+me->query("name")+"������");	
		else command("say ������ô˵��......"+me->query("name")+"���ţ�");	
		command("pat "+me->query("id"));	
		return 1;
	}
	if (me->query("marry"))
	{
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("? "+me->query("id"));	
		if(random(2)) command("say ������"+me->query("marry/name")+"("+capitalize(me->query("marry/id"))+")֪����" );	
		else command("say "+me->query("name")+"����ӳ�ǽô���ѵ������Լ��Ѿ�����ż������" );	
		command("sneer "+me->query("id"));	
		return 1;
	}
	if (me->query_temp("marry"))
	{
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("? "+me->query("id"));	
		command("say "+me->query("name")+"����ӳ�ǽô���ѵ��������Լ��Ѿ������˰���" );	
		command("sneer "+me->query("id"));	
		return 1;
	}

	if(me->query_condition("killer"))
	{
		command("look "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("shake "+me->query("id"));
		command("say С�Ĺٸ�ͨ����");
		return 1;
	}
	if(me->query_condition("job_busy"))
	{
		command("look "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say ������"+me->query("job_name")+"���񣬻�����΢��Ϣһ�°ɣ�");
		return 1;
	}
	if( mapp(mp = me->query_conditions_by_type("poison")) && sizeof(mp)>0 )
	{
		command("poor "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say "+me->query("name")+"�������κ��Լ��Ĳ������������װɣ�");
		return 1;
	}  
	if( mapp(mp = me->query_conditions_by_type("killer")) && sizeof(mp)>0 )
	{
		command("hmm "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say "+me->query("name")+"�����Ƚ�����Լ��ĸ��˶�Թ�����������װɣ�");
		return 1;
	} 
	if( mapp(mp = me->query_conditions_by_type("hurt")) && sizeof(mp)>0 )
	{
		command("sigh "+me->query("id"));
		message_vision(HIY"\n$n����ؽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say "+me->query("name")+"����������һ�����������������װɣ�");
		return 1;
	}  
	if(wizardp(me) && !me->query("env/marry_test")) 
	{
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("say "+me->query("name")+"���Ͼͱ����ˣ�ר�ĸ㿪��ȥ�ɣ�");
		return 1;
	}
	obj = deep_inventory(me);
	p = sizeof(obj);
	while (p--)
	{
		if (obj[p]->is_character() )
		{
			message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
			command("say "+me->query("name")+"�������"+obj[p]->query("name")+"��ʲô����Ŷ��");
			return 1;
		}
		if(obj[p]->query("unique"))
		{
			message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
			command("say "+me->query("name")+"�������"+obj[p]->query("name")+"���Ǳ��ﰡ����������ʲô��ʧ�Ͳ����ˣ�");
			return 1;
		}
	}
	return 0;
}
