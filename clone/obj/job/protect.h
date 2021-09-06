//Cracked by Kafei
//protect.h
//author wzfeng@xkx 2000 6
//create a protect job.

//#include "job_area.h"
int	protect_job(object master,object player,mapping job)
{
	string area,room_name,region;
	object room;
	int ret;
	ret=0;
	area=job["job_area"];
	room_name=get_room(area);
	if(!room_name)
		{
//		printf("����û���ҵ�������ϵwiz.\n");
		return 0;
		}
	if(!room=find_object(room_name))
		room=load_object(room_name);
	if(!objectp(room))
		{
//		printf("����%s������������ϵwiz.\n",room_name);
		return 0;
		}
	//confirm room area by region.
    if ( strsrch(file_name(room), "/d/") != 0       
		||  undefinedp(region = region_names[explode(file_name(room), "/")[1]]))
				region = "";

	get_job_palce_msg(master,player,region+room->query("short"),"npc","protect");
	//add job message in dab_data
	/**************************************************************************/
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	/****get this player job mapping from job data.*/
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	job_map["job_protect_place"]=room_name;
	job_map["job_protect_time"]=time();
	job_map["job_protect_mode"]="npc";
	job_map["job_protect_place_chinses"]=region+room->query("short");

	map_delete(job_map,"job_askjob"); 
	map_delete(job_map,"job_command_mode"); 
	map_delete(job_map,"job_master_prompt_time"); 
	job_data->modify_job_data(job_map["job_player"],job_map);
	
	
	job_data->save();
	/****************************************************************************/
	//destruct(room);

	return 1;
}
void out_protecter(object player,object place)
{
	object protect;

	if(file_name(environment(player))==file_name(place))
	{
	
	protect=new("/clone/obj/job/job_protect_npc");
	if(!objectp(protect)) return;
	//killer->set_status(player);
	protect->move(environment(player));
	
	message("vision", HIW"һ��"+protect->name(1)+"���˹��������㱧ȭ������"+player->name(1)+"���������ˡ�\n"
		"��������а��������Ᵽ����ҵ������ͣ�������ʤ���ҡ�	��\n"NOR, environment(player), protect);
	player->set("job_system/protect",1);
	protect->set("player_name",player->query("id");


	}
	else
		tell_object(player,HIW"Խ��ԽԶ�ˣ�����Լ�������˵��......\n"NOR);

	return ;

}

//start oppose job.
int job_protect_start(object player)
{
	
	if(player->query_temp("job_system/start_prompt"))
		return 1;
	tell_object(player,HIW"��Ӧ�þ��������ˡ�����������ĥ��......\n"NOR);
	player->set_temp("job_system/start_prompt",1);
	remove_call_out("out_protecter");
	call_out( "out_protecter",10,player,environment(player)); 

	return 1;

}
int award_protect_pker(object player)
{
	object master,place;
	string mname,pname,msg_room,msg_player;
	int time1,time2;
	
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	msg_room="";
	msg_player="";
	
	if(!(place=find_object(job_map["job_master_place"])))
		place=load_object(job_map["job_master_place"]);

	if(!objectp(place))
		return 0;
	if(!objectp(master = present(job_map["job_master"],
						 place
						 )))
                return 0;
	mname=master->query("name");
	pname=player->query("name");
	master_msg(master,player,"opposepk_award","award");
	//******************award***************************
	time1=job_map["job_oppose_pker_time"];
	time2=job_map["job_oppose_pker_finish_time"];
	award_job(600,
			120,
			time1,
			time2,
			random(5),
			0,
			0,
			0,
			player,
			master);

	return 1;
}
