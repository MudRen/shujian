int ask_biwu()
{
	object me=this_player();
	if(me->query("gender")=="Ů��")
	{
		if(!me->query_temp("quest/bwzh/can_marry"))
		{
			if(time()-ask_time<ASKTIME)
			{
				command("pat "+me->query("id"));
				command("say �ȵȣ��Ҹմ���һ�������Ϣ����ûæ�����ء�");	
				return 1;
			}
			ask_time=time();
			command("say ����Ů�ӿ����ڴ˵������з���������⽫�Լ������и���һλ����Ӣ�ۣ�");
			command("whisper "+me->query("id")+" �ǲ������Ҹ������ɾ���");
			command("say ������ڴ������飨Write�����Լ������֣������ʹ�� help quest bwzq ����ⷽ��İ�����");
			me->delete_temp("quest/bwzh");
			me->set_temp("quest/bwzh/can_marry",1);
		}
		command("addoil "+me->query("id"));
	}
	else if(me->query("gender")=="����")
	{
		if(!me->query_temp("quest/bwzh/can_yingzhao"))
		{
			if(time()-ask_time<ASKTIME)
			{
				command("pat "+me->query("id"));
				command("say �ȵȣ��Ҹմ���һ�������Ϣ����ûæ�����ء�");	
				return 1;
			}
			command("say ����������Ů�ӿ����ڴ˵������з��Խ��Լ������и���һλ����Ӣ�ۣ�");
			command("whisper "+me->query("id")+" �ǲ���������Ҹ�������Ů��");
			if(query("bwzh/fail_player") && query("bwzh/fail_player/id")==me->query("id"))
			{
				command("hmm");
				command("say �ȵȣ����Ѿ���ȥ���˰ɣ����ұ�ʹ�⣿��.......");
				command("laugh");
			}
			else
			{
				ask_time=time();
				command("say ������ڴ˵زμӱ���Ӧ�У�Yingzhao����");
				command("say �����ʹ�� help quest bwzq ����ⷽ��İ�����Ҳ���ԣ�Look qi�����������Ϣ��");
				me->delete_temp("quest/bwzh");
				me->set_temp("quest/bwzh/can_yingzhao",1);
			}
		}
		command("addoil "+me->query("id"));
	}
	else
	{
		if(time()-ask_time<ASKTIME)
		{
			command("pat "+me->query("id"));
			command("say �ȵȣ��Ҹմ���һ�������Ϣ����ûæ�����ء�");	
			return 1;
		}
		command("say ����������Ů�ӿ����ڴ˵������з��Խ��Լ������и���һλ����Ӣ�ۣ�");
		command("say Ҳ�и��ص����ֿ��ܿ����ڴ˵زμӱ���Ӧ�У�Yingzhao����");
		command("whisper "+me->query("id")+" ֻ���������Ҹ������ɾ��أ������绨��Ů��");
		command("tsk "+me->query("id"));
		command("addoil");
	}
	return 1;
}