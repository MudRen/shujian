int answer(string arg)
{
	object me,ob,who,obj;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/marry_object")) return 0;
	if(me->query_temp("quest/bwzh/marry_yes"))
	{
		tell_object(me,YEL"���Ѿ��ش��ˡ�\n"NOR);
		return 1;
	}
	if(query("station")!=6)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s �����������answer"NOR,me->query("name"),me->query("id")),me);
		remove_call_out("answer_check");
		command("say");
		init_over();
		return 1;
	}

	if(!arg || ( arg!="yes" && arg!="y" && arg!="Y" && arg!="Yes" && arg!="no"&& arg!="n"&& arg!="N"&& arg!="No")) 
	{
		command("? "+me->query("id"));
		command("say ��������ף��㵽��Ը�ⲻԸ�⣬���������˵�����ס�");
		return 1;
	}

	who=me->query_temp("quest/bwzh/marry_object");

	if(!who || environment(who)!=environment(ob)) 
	{
		remove_call_out("answer_check");
		command("chat* ?");	
		if(me->query("gender")=="Ů��")
			command("chat "+ob->query("bwzh/winner_player/name")+"�Ȳ�ԸȢ������ô�³����䣿������£�����ᱡ��");
		else
			command("chat "+ob->query("bwzh/host_player/name")+"�����ǲ�������Է�������˵�߾��ߣ�������£�����ᱡ��");
		command("poor "+me->query("id"));
		if(who)
		{
			who->delete_temp("quest/bwzh");
			who->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s �뿪��ʧʮ��answer",who->query("name"),who->query("id")),who);
		}
		else
		{
			if(me->query("gender")=="Ů��")
				log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s �뿪������ʧanswer"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
			else log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s �뿪������ʧanswer"NOR,ob->query("bwzh/winner_player/name"),ob->query("bwzh/winner_player/id")),ob);
		}
		init_over();
		return 1;
	}

	if(arg=="no" || arg=="n" || arg=="N" || arg=="No")
	{
		remove_call_out("answer_check");
		if(me->query("gender")=="Ů��")
		{
			message_vision(HIR"\n$N��ɫ�Ұף�����ҧ�����飬��$nһ����˵���������ɹ��Ӵ���ȻСŮ�Ӹ���ǳ�����䲻�Ϲ�����Ʒ������\n"NOR,me,who);
			command("chat* sigh "+getuid(me));
			command("chat "+ob->query("bwzh/host_player/name")+"�Ȳ�Ը�޸�����Ϊʲô�������ף�������£�����ᱡ��");
		}
		else
		{
			message_vision(HIR"\n$NƲ��Ʋ�죬˫��һ̯���ٺ�һЦ������$n��ȭ�������棬��Ҳ��Ȥ��������������ɶ�л�ˣ���\n"NOR,me,who);
			command("chat* hmm "+getuid(me));
			command("chat "+ob->query("bwzh/winner_player/name")+"�Ȳ�ԸȢ������ô�³����䣿������£�����ᱡ��");
		}
		command("? "+getuid(me));
		command("poor "+getuid(who));
		tell_object(me,"����Ϊ�ڡ��������ס��г��������������۳���ʮ��㾭�顣");
		me->add("combat_exp",-100000);
		me->delete_temp("quest/bwzh");
		if(who) who->delete_temp("quest/bwzh");
		log_file("quest/zhaoqin",sprintf("%-8s%-10s �ܾ���ʧʮ��answer",me->query("name"),me->query("id")),me);
		init_over();
		return 1;
	}

	me->set_temp("quest/bwzh/marry_yes",1);

	if(me->query("gender")=="Ů��")
	{
        message_vision(HIM"$N�ߵ�˫�����̣�ȴ�򸣴�����������������Ů���ҡ���������ҡͷ���������ǵ�ͷ��������\n"NOR, me);
		command("say ��ϲ����ϲ��");
		if(!who->query_temp("quest/bwzh/marry_yes"))
		{
			command("say "+who->query("name")+"�㻹��ʲô��������Ȼ��"+me->query("name")+"����Ӧ�ˣ�������ش�");
			return 1;
		}
	}
	else
	{
		message_vision(HIG"$N������Ц��������䶼�ȹ��ˣ�������ޣ����ֺ��󣡡�\n"NOR, me);
		command("say ��ϲ����ϲ��");

		if(!who->query_temp("quest/bwzh/marry_yes"))
		{
			command("say "+who->query("name")+"�����㻹��ʲô����������䶼���ˣ���Ը��޸�"+me->query("name")+"ô��");
			return 1;
		}
	}
	remove_call_out("answer_check");
	me->delete_temp("apply/short");  
	who->delete_temp("apply/short");  
	obj=new("/d/city/npc/yuelao");
	obj->move(environment(ob));
	message_vision(HIY"\nͻȻһ��������ɢ��һ��������⣬��ü�԰׵��������˹�����\n"NOR, me);
	command("ah "+obj->query("id"));
	message_vision(HIG"$N���Ц�ݣ�����������һ��ȭ�����������ˣ�����������Ǹ������ӣ���\n"NOR, me);
	message_vision(HIC"$N���˵�ͷ�����Ҿ�Ϊ�������ġ�����������˫�����⣬һ���뱸�������Ϊ���ǵǼǣ���\n"NOR, obj);
	message_vision(HIW"$N��ͷ����Ե�����˷���д��Щʲô��\n\n"NOR,obj);
	who->delete_temp("quest/busy");
	who->delete_temp("quest/bwzh");
	me->delete_temp("quest/busy");
	me->delete_temp("quest/bwzh");

	who->set("marry/id",me->query("id"));
	who->set("marry/name",me->query("name"));
	me->set("marry/id",who->query("id"));
	me->set("marry/name",who->query("name"));

	me->set_temp("marrying",1);
	me->set_temp("bride", ob->query("id"));
	who->set_temp("groom", ob->query("id"));

	command("say ��ϲ����ϲ��");
	message_vision("$N˵��������ϲ����ϲ����\n\n", obj);
	new("/clone/misc/marry-token")->move(me);
	new("/clone/misc/marry-token")->move(who);
	me->save();
	who->save();
	command("chat "+HIR"��ϲ����ϲ��"NOR);
	CHANNEL_D->do_channel(obj,"chat",HIR"��ϲ����ϲ��"NOR);
	CHANNEL_D->do_channel(this_object(),"chat",HIY""NOR+me->short("1")+HIY"��"NOR+who->short(1)+HIY"�������ף������Ե��"NOR);
	message_vision(HIM"\n$N��$n�����˶������\n"NOR, me, who);
	message_vision("\n$Nվ��������һ��ȭ���������������˽ᣬ�����и����ˣ���\n",obj);
	message_vision("ͻȻһ����Ļ������$N�Ѿ���ʧ�ˡ�\n\n",obj);

	destruct(obj);
	log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s %-8s%-10s���ף��ش˼�¼��"NOR,me->query("name"),me->query("id"),who->query("name"),who->query("id")),ob);
	init_over();
	return 1;
}