//Cracked by Kafei
//author wzfeng@xkx 2000 6
//job_system ��һЩ���Ӻ���

static string *cleanup_filename=({"job_data","job_menpai",});

void clean_up_job_object()
{
	object master,*ob_list;
	int i,j;
	for(j=0;j<sizeof(cleanup_filename);j++)
	{
	ob_list=children(JOB_DIR+cleanup_filename[j]);
	i=sizeof(ob_list);
//	if( wizardp(this_player()) && (string)this_player()->query("env/job_system")=="open" )
	//printf("�ļ�%s��cloneһ����%d��\n",JOB_DIR+cleanup_filename[j],i);
	if(i>1)
	{
		i=i-1;
	while (i--)
			if(!environment(ob_list[i]))
 {
      reset_eval_cost();
//	if( wizardp(this_player()) && (string)this_player()->query("env/job_system")=="open" )
//printf("ɾ��%O\n",JOB_DIR+cleanup_filename[j],ob_list[i]);
      
      destruct(ob_list[i]);
    }
	}
	}
}

void job_tell_player(object player)
{
	string msg,area_name,master_place,menpai_place,master_name,menpai_c_place,master_id,master_place_full,
		master_full_name;
	string state;
	object master;
	mapping job_data_message;
	int i;
	object room_master;
	state="����";
	msg="";
	area_name=explode(file_name(environment(player)), "/")[1];
	menpai_name=player->query("family/family_name");
	if(undefinedp(family_master_place[menpai_name]))
	{
		write("����"+menpai_name+"û�ж���\n");
		return;
	}
	//�õ���Ӧ�������ڵ�Ŀ¼����
	menpai_place=explode(family_master_place[menpai_name], "/")[1];
	master_place_full=family_master_place[menpai_name];
	master_name=explode(family_master[menpai_name], "/")[0];
	menpai_c_place=explode(family_master[menpai_name], "/")[3];
	master_id=explode(family_master[menpai_name], "/")[2];
	master_full_name=explode(family_master[menpai_name], "/")[4];
	if(!(room_master=find_object(family_master_place[menpai_name])))
		room_master=load_object(family_master_place[menpai_name]);
	if(!objectp(room_master))
		return;
	if(file_name(environment(player))==master_place_full)
		{
		if(objectp(master = present(master_id,room_master)))
		{
			
			job_data_message = ([
				"job_menpai":menpai_name,
				"job_player": player->query("id"),
				"job_strategy": strategy_produce,
				"job_master": explode(family_master[menpai_name], "/")[2],
				"job_area": menpai_area_power,
				"job_master_prompt_time":time(),
				"job_command_mode":state,
				"job_master_place":family_master_place[menpai_name],
				"job_master_cname":master_name,
				"job_askjob":1,
				]);
				job_data->add_job_data(job_data_message);
				job_data->save();
			if(!master_tell_player(player))
				if( wizardp(player) && (string)player->query("env/job_system")=="open" )
				tell_object(player,"error");
			else
				if( wizardp(player) && (string)player->query("env/job_system")=="open" )
			tell_object(player,"succeed");
				return;
		}
		else
			return;
        
		}
	//if master not in that place, return.
	if(!objectp(master = present(master_id,room_master)))
		return;
	msg=HIW"\nһ��"+menpai_name+"�������˹���,��$N��ȭ������";
	
	if(area_name==menpai_place)
		msg += master_name+"�����ټ���������ȥ"+room_master->query("short")+"����\n";
	else
		msg += "���·�"+master_name+"֮���������ٻ�"+menpai_c_place+"��������\n";
	msg+=menpai_name+"����˵��:"+"��"+explode(family_master[menpai_name], "/")[1]+"��ѵ���Ѵ����������!��\n"+
		menpai_name+"�������˳�ȥ\n"NOR;
	message_vision(msg, player);

	//set_player_var(job_player,strategy_produce,master_id,family_master_place[menpai_name],state,master_name);
	
	//////////////////////////////////////////////
	//add a menber in job_player_list
	job_data_message = ([
		"job_menpai":menpai_name,
        "job_player": player->query("id"),
        "job_strategy": strategy_produce,
		"job_master": explode(family_master[menpai_name], "/")[2],
		"job_area": menpai_area_power,
		"job_master_prompt_time":time(),
		"job_command_mode":state,
		"job_master_place":family_master_place[menpai_name],
		"job_master_cname":master_name,
		"job_askjob":1,
		]);

	job_data->add_job_data(job_data_message);
	job_data->save();

}

void assign_job(object master,object player,mapping map)
{
	string job_calss;
	job_calss=map["job_strategy"];
	switch(job_calss)
	{
	case "oppose_pker":  
			oppose_pker(master,player,map);
		
		break;
		default  : 
			oppose_pker(master,player,map);
			//break;
			return;
	}

/*		switch(job_calss)
	{
	case "protect":  
			protect_job(master,player,map);
		
		break;
		default  : 
			protect_job(master,player,map);
			//break;
			return 0;
	}

*/	
	return;
}
void finish_job(object player)
{
	string job_kind;
	job_kind=get_mapping(player->query("id"),"job_player",job_data->query_job_data())["job_finish"];
	switch(job_kind)
	{
	case "oppose_pker":
		award_oppose_pker(player);
		break;
	default:
		break;
	}
//if( wizardp(player) && (string)player->query("env/job_system")=="open" )
//	tell_object(player,job_kind);
	job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	job_data->detract_job_data(player->query("id"));
	job_data->save();

	return;
}
void master_tell_player(object player)
{

	object master,place;
	string mname,pname,msg_room,msg_player;
	
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	msg_room="";
	msg_player="";
	
	if(!(place=find_object(job_map["job_master_place"])))
		place=load_object(job_map["job_master_place"]);

	if(!objectp(place))
		return;
	
	
	if(!objectp(master = present(job_map["job_master"],
						 place
						 )))
                return;
	mname=master->query("name");
	pname=player->query("name");
	
	if(job_map["job_master_prompt_time"]+900<time())
	{
		master_msg(master,player,"time_over",job_map["job_command_mode"]);
		job_data->restore();
		job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
		job_data->detract_job_data(player->query("id"),job_map);
		player->delete_temp("job_system");
		job_data->save();
		job_punish(player,"mastercall_in");

	}
	else
	{
		master_msg(master,player,"time_noover",job_map["job_command_mode"]);
		assign_job(master,player,job_map);

	}
	//printf("%s\t%s\n",job_map["job_player"],job_map["job_master"]);
	return;
}
//��������������ݵ�����
void adjust_menpai_job_data(object player,string kind)
{
	string menpai_name;
	object menpai_ob;
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	write("adjust_menpai_job_data"+player->query("family/family_name"));
	job_data->change_family_data(player->query("family/family_name"),player,kind);
	job_data->save();
//	job_data->destruct();


}

void award_job(int exp_lim,int pot_lim,int time1,int time2,int luck,
			   int neili,int jingli,int skills_lim,object player,object master,string kind)
{
	int exp,pot,max_pot,time,ver;
	//kind=1;
	exp=player->query("combat_exp");
	pot=player->query("potential");
	max_pot=player->query("max_potential");
	time=time2-time1;
	//printf("exp_lim=%d\tpot_lim=%d\tluck=%d\tkind=%s\n",exp_lim,pot_lim,luck,kind);
	if(luck>9)
		luck=9;

	switch(kind)
	{

		//award exp and pot
		case "oppose_pker":
			{
				
			exp_lim=exp_lim+(exp_lim/(10-luck));

			pot_lim=pot_lim+(pot_lim/(10-luck));
			
			if((pot_lim+pot)>max_pot)
			{
				player->set("potential",player->query("max_potential"));
				tell_object(player,"���Ǳ���������ˡ�"+pot_lim+"��\n");
			}
			else
			{
				player->add("potential",pot_lim);
				tell_object(player,"���Ǳ��������"+pot_lim+"��\n");
			}
			player->add("combat_exp",exp_lim);
			tell_object(player,"��ľ���������"+exp_lim+"��\n");
			if(random(30)==1&&time<300)
			{
				player->add("max_neili",1);
				tell_object(player,"����������������1��\n");
				neili=1;
			}
			else
				if(random(25)==1&&time<300)
					{
					player->add("eff_jingli", 1);
                    player->add("max_jingli", 1);
					tell_object(player,"��������������1��\n");
					jingli=1;
					}
			log_file( "test/jobsystem_award",
		player->query("name")+
		"("+player->query("id")+")��"+time+"�������������exp " +exp_lim+"Ǳ�� "+pot_lim+"�������"+neili+"��"+
		"�����"+jingli+
		" on " 	+ ctime(time()) + "��\n" );
			adjust_menpai_job_data(player,"oppose_pker");
			
			}

			break;
	}
	
	
	return;
}
void job_punish(object player,string job_kind)
{

	switch(job_kind)
	{
	case "oppose_pker":
		tell_object(player,HIB"�����㵢���ʱ��̫���ˣ��������ȡ���ˡ�\n"NOR);
		if(player->query("job_system_fail/oppose_pker")>2)
		{
			tell_object(player,"��ľ����½���"+OPPOSE_DROP_EXP+"�㡣\n");
			player->delete("job_system_fail/oppose_pker");
			tell_object(player,"����������ζ��½���"+OPPOSE_DROP_CON+"�㡣\n");
			player->add("combat_exp",-OPPOSE_DROP_EXP);
			adjust_menpai_job_data(player,"OPPOSE_DROP_CON");

		}
		else
		{
			player->add("job_system_fail/oppose_pker",1);
		}
		break;
	case "mastercall_in":
		
		if(player->query("job_system_fail/mastercall_in")!=1002)
		{
			tell_object(player,"��ľ����½���"+MASTER_CALL_IN_EXP+"�㡣\n");
			player->delete("job_system_fail/mastercall_in");
			tell_object(player,"����������ζ��½���"+MASTER_CALL_IN_CON+"�㡣\n");
			player->add("combat_exp",-MASTER_CALL_IN_EXP);
			adjust_menpai_job_data(player,"MASTER_CALL_IN_CON");

		}
		else
		{
			player->add("job_system_fail/mastercall_in",1);
		}
		break;
	case "finish_job":
		tell_object(player,HIB"�����㵢���ʱ��̫���ˣ��������ȡ���ˡ�\n"NOR);
		if(player->query("job_system_fail/finish_job")>2)
		{
			tell_object(player,"��ľ����½���"+FINISH_JOB_EXP+"�㡣\n");
			player->delete("job_system_fail/mastercall_in");
			tell_object(player,"����������ζ��½���"+FINISH_JOB_CON+"�㡣\n");
			player->add("combat_exp",-FINISH_JOB_EXP);
			adjust_menpai_job_data(player,"FINISH_JOB_CON");

		}
		else
		{
			player->add("job_system_fail/finish_job",1);
		}

	}
	return;
}

void del_job(object player,string kind)
{
		
		if(!job_data=find_object(JOB_DIR+"job_data"))
			job_data=new(JOB_DIR+"job_data");
		if(!objectp(job_data)) return;
		job_data->restore();
		job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
		job_data->detract_job_data(player->query("id"),job_map);
		job_data->save();
		//punish the player.
		//the OPPOSE_DROP_EXP define in default_data.h
		job_punish(player,kind);

	return;
}
