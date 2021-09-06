void biwu_over()
{
    biwu_stop(0);
	log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ����ʱ�䵽biwu_over"NOR,this_object()->query("name"),this_object()->query("id")),this_object());
	return;
}
int cancel(string arg)
{
	object me;
	me = this_player();
	if(!me->query_temp("quest/bwzh/can_marry")) return 0;
	if(!me->query_temp("quest/bwzh/hoster")) return 0;
	if(arg)	return 0;
	if(query("station")<2 ||query("station")>=6) return 0;
	log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ����ȡ������biwu_over"NOR,me->query("name"),me->query("id")),me);
    biwu_stop(1);
	return 1;
}
void biwu_stop(int i)
//0 biwu_over 1 cancel
{
	object me,ob,winner_player,challenge_player,room;
	object *ob_list;
	int p;

	ob= this_object();
	remove_call_out("biwu_over");
	remove_call_out("checking");
	if(query("station")<2 && i==0)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s �������д���biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(query("station")>=6 && i==0)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ������������biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/host_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ��ʧ��Ů����biwu_over"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/winner_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ��ʧ��������biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if (!(room = find_object(query("leitai"))))
		room = load_object(query("leitai"));
	if(!room)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ȱ�ٸ����ļ�biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
    
	room->remove_call_out("start_biwu");//��ֹ����
	ob_list = filter_array(children(BIWU_USER), (: clonep :));
	for(p=0; p<sizeof(ob_list); p++) 
	{
		log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ����������ֹbiwu_stop"NOR,ob_list[p]->query("name"),ob_list[p]->query("id")),ob_list[p]);
		ob_list[p]->quit(ob_list[p]);
	}
	me=ob->query("bwzh/host_player/object");//��Ů
	if(me) 
	{
		me->delete_temp("apply/short");  
 		if(i) tell_object(me,HIR"���׻���䱻ǿ����ֹ��\n"NOR);
		else tell_object(me,HIR"ʱ�䵽�����׻���䲿����ֹ��\n"NOR);		
	}
	winner_player=ob->query("bwzh/winner_player/object");
	if(winner_player)
	{
 		if(i) tell_object(winner_player,HIR"���׻���䱻ǿ����ֹ��\n"NOR);
		else tell_object(winner_player,HIR"ʱ�䵽�����׻���䲿����ֹ��\n"NOR);
	}
	challenge_player=ob->query("bwzh/challenge_player/object");
	if(challenge_player)
	{
		if(i) tell_object(challenge_player,HIR"���׻���䱻ǿ����ֹ��\n"NOR);
		else tell_object(challenge_player,HIR"ʱ�䵽�����׻���䲿����ֹ��\n"NOR);
		challenge_player->delete_temp("quest/bwzh");
		challenge_player->delete_temp("quest/quest");
		challenge_player->delete_temp("apply/short");
	}
	
	over_time=time();
	set("station",0);

	if(!me || !me->query_temp("quest/bwzh/hoster"))
	{
		command("bite");
		command("say "+ob->query("bwzh/host_player/name")+"�����뿪�ˡ���������ֻ����ֹ�ˡ�");
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"��Ϊ"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�뿪�ֳ����������ױ���ȡ����"NOR);
		command("chat* shrug");
		if(!me)
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ��Ů��������biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		else 
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ��Ů�뿪�ֳ�biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		init_over();
		return;
	}

	if(!winner_player || !winner_player->query_temp("quest/bwzh/biwu_host"))
	{
		command("chat* hmm");
		if(i)
			CHANNEL_D->do_channel(this_object(),"chat",HIY+""+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�ı������׻��ǿ����ֹ��"NOR);
		else
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"��Ϊʱ���ϵ��"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�������׻��ֹ��"NOR);
		if(winner_player)
		{
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"���ձ���ʤ���ߣ�"+winner_player->query("name")+RANK_D->query_respect(winner_player)+"��"NOR);
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"���ǣ�"+winner_player->query("name")+RANK_D->query_respect(winner_player)+"Ŀǰ�����ֳ�������ȡ����"NOR);
		}
		if(winner_player) log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ���������ֳ�biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		else log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ȱ��������Ϣbiwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		init_over();  
		command("say ʱ�䵽������������Ϸ�����˶��������ˡ�");
		command("poor "+me->query("id"));
		return;
	}

	if(winner_player==me|| me->query_temp("quest/bwzh/biwu_host"))
	{
		if(!ob->query("bwzh/bwzh/fail_player") && !ob->query("bwzh/challenge_player"))
		{
			if(i) command("say ����������Ϸ�����˶��������ˡ�"); 
			else command("say ʱ�䵽������������Ϸ�����˶��������ˡ�");
			command("poor "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ����ս��ʧ��biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		else if(!ob->query("bwzh/bwzh/fail_player") && ob->query("bwzh/challenge_player"))
		{
			if(i) command("say ֻ��ϧ��ս���˳ٳ�δ����̨��"); 
			else command("say ʱ�䵽��ֻ��ϧ��ս���˳ٳ�δ����̨��");
			command("shrug "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ս��ų����biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		else if(ob->query("bwzh/bwzh/fail_player") && !ob->query("bwzh/challenge_player"))
		{
			if(i) command("say ����Ѱ��һ���书��ǿ�������ɻ��Ǻ��ѵġ�"); 
			else command("say ʱ�䵽������Ѱ��һ���书��ǿ�������ɻ��Ǻ��ѵġ�");
			command("addoil "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ̫������ʧ��biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		else
		{
			if(i) command("say ����Ѱ��һ���书��ǿ�������ɻ��Ǻ��ѵġ�"); 
			else command("say ʱ�䵽������Ѱ��һ���书��ǿ�������ɻ��Ǻ��ѵġ�");
			command("addoil "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ������������biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		if(i)
			CHANNEL_D->do_channel(this_object(),"chat",HIY+""+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�ı������׻��ǿ����ֹ��"NOR);
		else
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"��Ϊʱ���ϵ��"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�������׻��ֹ��"NOR);
		command("chat* shrug");
		init_over();  
		return;
	}
	
	winner_player->delete_temp("apply/short");  
	message_vision(HIY"\n$n���Ž����¶���$N���˸�Ҿ��\n"NOR,me,winner_player);
	message_vision(CYN"$n˵����������±ç���ã��Թ�����Ľ֮�����棬��������ǿ���ѣ���������Ҫ���⡹\n\n"NOR,me,winner_player);
	command("pat "+me->query("id"));	
	command("pat "+getuid(winner_player));	
	command("say ʱ�䵽��ĿǰӦ����������ĵ���"+winner_player->query("name")+RANK_D->query_respect(winner_player)+"��");
	if(i)
		CHANNEL_D->do_channel(this_object(),"chat",HIY+""+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�ı������׻��ǿ����ֹ��"NOR);
	else
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"��Ϊʱ���ϵ��"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")�������׻��ֹ��"NOR);
	CHANNEL_D->do_channel(this_object(),"chat",HIY+"���ձ���ʤ���ߣ�"+winner_player->query("name")+RANK_D->query_respect(winner_player)+"��"NOR);
	command("chat* addoil "+winner_player->query("id"));
	
	winner_player->set_temp("apply/short", ({winner_player->name()+"("+winner_player->query("id")+")"YEL" <������> "NOR}));
	me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <������> "NOR}));
	
	me->set_temp("quest/bwzh/over",1);
	winner_player->set_temp("quest/bwzh/over",1);
	
	remove_call_out("zhaoqin");
	call_out("zhaoqin",6,me,winner_player);
	set("station",6);
	over_time=time();
	return;    
}