void checking()//�����Ů�������Ƿ��ڳ�
{ 
	object me,ob,winner_player,challenge_player,room;
	object *ob_list;
	int i;

	ob= this_object();
	remove_call_out("checking");
	if(query("station")<2)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s �������д���checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/host_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ��ʧ��Ů����checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/winner_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ��ʧ��������checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if (!(room = find_object(query("leitai"))))
		room = load_object(query("leitai"));
	if(!room)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ȱ�ٸ����ļ�checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(query("station")>=6)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ������������checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}

	me=ob->query("bwzh/host_player/object");//��Ů

	if(!me ||!me->query_temp("quest/bwzh/hoster"))//ȱ����Ů
	{
		command("bite");
		command("say "+ob->query("bwzh/host_player/name")+"�����뿪�ˡ���������ֻ����ֹ�ˡ�");
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"��Ϊ"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�뿪�ֳ����������ױ���ȡ����"NOR);
		command("chat* shrug");
		if(!me) log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s ��Ů��������checking"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		else log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s ��Ů�뿪�ֳ�checking"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
        
		ob_list = filter_array(children(BIWU_USER), (: clonep :));
		for(i=0; i<sizeof(ob_list); i++) 
		{
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ����������ֹchecking"NOR,ob_list[i]->query("name"),ob_list[i]->query("id")),ob_list[i]);
			ob_list[i]->quit(ob_list[i]);
		}

		if(winner_player=ob->query("bwzh/winner_player/object"))
		{
			tell_object(winner_player,HIR""+ob->query("bwzh/host_player/name")+"��Ȼ�뿪�ֳ���������ֹ��\n"NOR);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s �˳���������checking",winner_player->query("name"),winner_player->query("id")),winner_player);
		}

		if(challenge_player=ob->query("bwzh/challenge_player/object"))
		{
			tell_object(challenge_player,HIR""+ob->query("bwzh/host_player/name")+"��Ȼ�뿪�ֳ���������ֹ��\n"NOR);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s �˳���������checking",challenge_player->query("name"),challenge_player->query("id")),challenge_player);
		}

		if(me)
		{
			tell_object(me,HIR"����Ϊ�ڡ��������ס����޹��뿪�ֳ��������۳���ʮ��㾭�飡\n"NOR);
			log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s ��ʧʮ����checking"NOR,me->query("name"),me->query("id")),me);
			me->add("combat_exp",-100000);
		}
		init_over();
		return;
	}

	winner_player=ob->query("bwzh/winner_player/object");

	if(!winner_player || !winner_player->query_temp("quest/bwzh/biwu_host"))
	{
		command("smash");
		command("say "+ob->query("bwzh/winner_player/name")+"��ô�뿪�����ˣ�����������Ҫ�����ˡ�");
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"��Ϊ"+ob->query("bwzh/winner_player/name")+"("+capitalize(ob->query("bwzh/winner_player/id"))+")��ȱϯ�������ʸ�ȡ����"+me->query("name")+"���µ���������"NOR);
		command("chat* addoil "+me->query("id"));
		if(!winner_player) log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ������������checking"NOR,ob->query("bwzh/winner_player/name"),ob->query("bwzh/winner_player/id")),ob);
		else log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ������������checking"NOR,ob->query("bwzh/winner_player/name"),ob->query("bwzh/winner_player/id")),ob);
		
		ob_list = filter_array(children(BIWU_USER), (: clonep :));
		for(i=0; i<sizeof(ob_list); i++) 
		{
			tell_object(ob_list[i],HIR"�������ڱ仯�С�������������������ʱ��ֹ��\n"NOR);
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ����������ֹchecking"NOR,ob_list[i]->query("name"),ob_list[i]->query("id")),ob_list[i]);
			ob_list[i]->quit(ob_list[i]);
		}
        
		if(challenge_player=ob->query("bwzh/challenge_player/object"))
		{
			challenge_player->delete_temp("quest/bwzh");
			challenge_player->delete_temp("quest/busy");
			challenge_player->delete_temp("apply/short");  
			tell_object(challenge_player,HIR"֪ͨ��"+ob->query("bwzh/winner_player/name")+"���ٵ���������"+me->query("name")+"���µ�������������������\n"NOR);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ֪ͨ��������checking",challenge_player->query("name"),challenge_player->query("id")),challenge_player);
		}
		
		tell_object(me,HIR"֪ͨ��"+ob->query("bwzh/winner_player/name")+"���ٵ��������������µ�������������������\n"NOR);

		if(winner_player)
		{
			winner_player->delete_temp("quest/bwzh");
			winner_player->delete_temp("quest/busy");
			winner_player->delete_temp("apply/short");  
			tell_object(winner_player,HIR"����Ϊ�ڡ��������ס����޹��뿪�������۳���ʮ��㾭�飡\n"NOR);
			log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s ��ʧʮ����checking"NOR,winner_player->query("name"),winner_player->query("id")),winner_player);
			winner_player->add("combat_exp",-100000);
		}

		ob->set("bwzh/winner_player/name",me->query("name"));//��������
		ob->set("bwzh/winner_player/id",me->query("id"));
		ob->set("bwzh/winner_player/object",me);

		me->set_temp("quest/bwzh/biwu_host",1);//������־
		me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <���������У�������> "NOR}));
		ob->set("station",3);
		log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s ���±������checking"NOR,me->query("name"),me->query("id")),me);
	}
    call_out("checking",1);
}