int yingzhao(string arg)
{
	object me,ob,winner_player,host_player,room;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/can_yingzhao")) return 0;
	if(arg)	return 0;
	if(query("station")!=5 && query("station")!=2 )
	{
		message_vision(HIY"\n$N������˸����ͣ�����һЦ��������Ⱥ���ȵ���������Ӧ�С�������Ծ������̨��\n\n"NOR,me);
		command("? "+me->query("id"));
		message_vision(HIY"$n��$N��������������ؿ����㣺�������Ǹ�ʲô��������\n"NOR,me,ob);
		if(!query("station"))
			command("whisper "+me->query("id")+" "+HIR"Ŀǰû�����ڱ������ס�����ԣ�Look qi����������Ϣ��"NOR);	
		else if(query("station")==1)
			command("whisper "+me->query("id")+" "+HIR""+query("bwzh/host_player/name")+"������������Ҫ�����Ժ���Ӧ�С�"NOR);	
		else if(query("station")==6)
			command("whisper "+me->query("id")+" "+HIR"�����Ѿ�������");
		else command("whisper "+me->query("id")+" "+HIR"�Ѿ��������ڱ���Ӧ�У�����΢��Ӧ�С�"NOR);
		return 1;
	}
	message_vision(HIY"\n$N���´��������׵�Ů�����ۣ�΢΢һЦ��������Ⱥ���ȵ���������Ӧ�С�������Ծ������̨��\n\n"NOR,me);
    if(check_player(me,1)) return 1;

	winner_player=ob->query("bwzh/winner_player/object");  
	host_player=ob->query("bwzh/host_player/object");   

	if(!winner_player||!host_player || environment(winner_player)!=environment(ob)||environment(host_player)!=environment(ob))
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("whisper "+me->query("id")+" "+HIR"Ŀǰ���仹δ��ʼ�����Ժ�����Ӧ�С�"NOR);	
		command("shrug "+me->query("id"));	
		if(!winner_player||!host_player) 
			log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ȱ��������Ϣyingzhao"NOR,me->query("name"),me->query("id")),me);
		else log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ������Ů����yingzhao"NOR,me->query("name"),me->query("id")),me);
		return 1;
	}
	if((ob->query("bwzh/per")>me->query("per"))
		||(ob->query("bwzh/exp")>me->query("combat_exp"))
		||((host_player->query("age")-ob->query("bwzh/age"))>me->query("age"))
		||((host_player->query("age")+ob->query("bwzh/age"))<me->query("age")))
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		if(ob->query("bwzh/per")>me->query("per"))
			command("whisper "+me->query("id")+" "+HIR"����òƽƽ��������Ҫ��"NOR);	
		else if(ob->query("bwzh/exp")>me->query("combat_exp"))
			command("whisper "+me->query("id")+" "+HIR"�㾭��̫�ͣ�������Ҫ��"NOR);
		else if((host_player->query("age")-ob->query("bwzh/age"))>me->query("age"))
			command("whisper "+me->query("id")+" "+HIR"������̫�ͣ�������Ҫ��"NOR);
		else command("whisper "+me->query("id")+" "+HIR"������̫�󣬲�����Ҫ��"NOR);
		command("shrug "+me->query("id"));	
		return 1;
	}
	if(winner_player==me)
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$nһ�ѽ�$N����������������ҡҡ��ͷ��\n"NOR,me,ob);
		command("whisper "+me->query("id")+" "+HIR"������������Ŷ��"NOR);	
		command("shrug "+me->query("id"));	
		return 1;
	}

	command("addoil "+me->query("id"));
	ob->set("bwzh/challenge_player/id",me->query("id"));
	ob->set("bwzh/challenge_player/name",me->query("name"));
	ob->set("bwzh/challenge_player/object",me);

	me->set_temp("quest/bwzh/biwu_challenge",1);//��ս�ߵı��
	me->set_temp("quest/busy",1);//����������

	log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ʼ����Ӧ��yingzhao",me->query("name"),me->query("id")),me);

	if (!(room = find_object(query("leitai"))))
		room = load_object(query("leitai"));
    
	if( !room ) 
	{
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ȱ����̨�ļ�yingzhao",me->query("name"),me->query("id")),me);
		init_over();
        return notify_fail("������̨û��׼���ã���֪ͨ��ʦ��\n");  
	}
	if(ob->query("bwzh/winner_player/id")==ob->query("bwzh/host_player/id"))
		set("station",3);
	else set("station",4);

	winner_player->set_temp("quest/bwzh/leitai",1);
	me->set_temp("quest/bwzh/leitai",1);
	
	host_player->set_temp("apply/short", ({host_player->name()+"("+host_player->query("id")+")"YEL" <����������> "NOR}));
	winner_player->set_temp("apply/short", ({winner_player->name()+"("+winner_player->query("id")+")"YEL" <���������У�������> "NOR}));
	me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <���������У���ս�ߣ�> "NOR}));
    
	room->load_user(winner_player);//��������
	room->load_user(me);//��ս�߽���
	
	remove_call_out("checking");
	call_out("checking",1);
	return 1;
}