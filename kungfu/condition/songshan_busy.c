// songshan_job.c for both player and npc.

void do_back(object me)
{
	if(!me) return;
	me->delete_temp("songshan_job");
	me->delete_temp("last_lost_to");
	me->set("chat_chance", me->query("chat_c"));
	me->delete("chat_c");
	if(!me->query_temp("location"))
		me->delete("location");
	me->delete_temp("location");
	tell_room(environment(me), me->name() + "����һ����"+RANK_D->query_self_rude(me)+"���ͷ��ˣ�\n", me);
	me->set_leader(0);
	me->reincarnate(); 
	if (!me->return_home())
		destruct(me);
}

int update_condition(object me, int duration)
{
	object player;
	
	if (duration < 2) {
		 if(!userp(me)) do_back(me);
		 return 0;
	}

	me->apply_condition("songshan_busy", duration - 1);

	if(!userp(me) && living(me)){
		if(!objectp(player = me->query_temp("songshan_job")))
		{
			do_back(me);
			return 0;
		}
		if(environment(player) == environment(me))
			return 1;
		tell_room(environment(me) , me->name() + "����һ����"+player->name()+"����ȥ�ˣ�˵��㼱��ææ���뿪�ˡ�\n");
		if (me->move(environment(player)))
			tell_room(environment(me) , me->name() + "����ææ�����˹�����\n");
		else destruct(me);
	}
	return 1;
}

string query_type(object me)
{
	return "job";
}
