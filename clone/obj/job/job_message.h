//Cracked by Kafei
//job_message.h
//���������Ϣ�ĺ���
//����������������򣬲���һ��ɱ�˵�����
//#include "job_family_master.h"

void get_job_palce_msg(object master,object player,string place,string state,string command_mode)
{
	string rmsg,pmsg,job_menpai,master_msg;

	job_menpai=job_map["job_menpai"];
	

	master_msg=get_family_master_massage(command_mode,job_menpai,state);
	rmsg=replace_string(master_msg,"$N",master->query("name"));
	rmsg=replace_string(rmsg,"$n",player->query("name"));
	rmsg=replace_string(rmsg,"$P",player->query("name"));
	rmsg=replace_string(rmsg,"$ROOM",place);


	pmsg=replace_string(master_msg,"$N",master->query("name"));
	pmsg=replace_string(pmsg,"$n","��");
	pmsg=replace_string(pmsg,"$P",player->query("name"));
	pmsg=replace_string(pmsg,"$ROOM",place);

	
	tell_room(environment(master),rmsg,({master,player}));
	tell_object(player,pmsg);
}

//������´��߶�����ִ���߸��ߵ���Ϣ
//The message that job master command to job executant
//���λ�ò���masterλ�ã����ֵ���ʾ��Ϣ��
//show the message taht job executant not in master room
string get_family_master_massage(string command_mode,string menpai,string state)
{
	string talk_msg;
	talk_msg="";
	switch(menpai)
				{

				case "�䵱��" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,wudang_message);
					break;
				case "������" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,xingxiu_message);
					break;
				case "��ɽ��" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,huashan_message);
					break;
				case "�һ���" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,taohua_message);
					break;
				case "ؤ��" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,gaibang_message);
					break;
				case "������" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,emei_message);
					break;
				case "����ɽ" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,baituo_message);
					break;
				case "ȫ���" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,quanzhen_message);
					break;
				case "ѩɽ��" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,xueshan_message);
					break;
				case "����μ�" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,dali_message);
					break;
				case "������" :
					talk_msg+=(string)get_msg_map("job_tell_mode",command_mode,state,shaolin_message);
					break;
				default :
					talk_msg+="$N��$n���˵�ͷ,˵������$P�����������á���\n";
				}
	return talk_msg;
}
	

int job_class_prompt(object player)
{
	string state;
	mapping job_map;
	state="";

	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	switch(job_map["job_command_mode"])
		{
		case "����"   :  
			state+=job_map["job_master_cname"]+"�Ѵ���Ҫ�ټ��㣬�㻹�ǿ��ȥ�ɡ�\n";
			
			break;
			default  : 
				state="�������ʹ���\n";
				//break;
				return 0;
		}
	tell_object(player,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	tell_object(player,job_map["job_master_place"]);
	return 1;
}
int job_start_prompt(object player)
{
	string state;
	state="";
	job_map=get_mapping(player->query("id"),"job_player",job_data->query_job_data());
	
	switch(job_map["job_oppose_pker_mode"])
		{
		
		case "npc":  
			
			state+=job_map["job_master_cname"]+"������ȥ"+job_map["job_oppose_pker_place_chinses"]+"���������Ҫ���񣬸Ͽ�ȥִ�аɡ�\n";
			
			break;
			default  : 
				state="job_oppose_pker_mode error��\n";
				//break;
				return 0;
		}
/*		switch(job_map["job_protect_mode"])
		{
		case "npc":  
			state+=job_map["job_master_cname"]+"������ȥ"+job_map["job_oppose_pker_place_chinses"]+"����ȥ���ˣ��Ͽ�ȥ����ɡ�\n";
			
			break;
			default  : 
				state="job_oppose_pker_mode error��\n";
				//break;
				return 0;
		}
*/	
	tell_object(player,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	tell_object(player,job_map["job_oppose_pker_place"]);
	return 1;
}

//message of master tell player.I put all message in a database .now load only base on database.
int master_msg(object master,object player,string state,string command_mode)
{
	string rmsg,pmsg,job_menpai,master_msg;

	job_menpai=job_map["job_menpai"];
	master_msg=get_family_master_massage(command_mode,job_menpai,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	{
	tell_object(player,"command_mode="+command_mode+"job_menpai="+job_menpai+"state="+state+"\n");
	tell_object(player,"master_msg="+master_msg+"\n");
	}
	rmsg=replace_string(master_msg,"$N",master->query("name"));
	rmsg=replace_string(rmsg,"$n",player->query("name"));
	rmsg=replace_string(rmsg,"$P",player->query("name"));

	pmsg=replace_string(master_msg,"$N",master->query("name"));
	pmsg=replace_string(pmsg,"$n","��");
	pmsg=replace_string(pmsg,"$P",player->query("name"));
	
	tell_room(environment(master),rmsg,({master,player}));
	tell_object(player,pmsg);
	return 1;
}

int assess_msg(object master,object player,string state,string command_mode,string family,object place)
{
	string rmsg,pmsg,job_menpai,master_msg;

	job_menpai=family;
	master_msg=get_family_master_massage(command_mode,job_menpai,state);
	if( wizardp(player) && (string)player->query("env/job_system")=="open" )
	{
	tell_object(player,"command_mode="+command_mode+"job_menpai="+job_menpai+"state="+state+"\n");
	tell_object(player,"master_msg="+master_msg+"\n");
	}
	rmsg=replace_string(master_msg,"$N",master->query("name"));
	rmsg=replace_string(rmsg,"$n",player->query("name"));
	rmsg=replace_string(rmsg,"$P",player->query("name"));

	pmsg=replace_string(master_msg,"$N",master->query("name"));
	pmsg=replace_string(pmsg,"$n","��");
	pmsg=replace_string(pmsg,"$P",player->query("name"));
	tell_room(place,rmsg,({player}));
	tell_object(player,pmsg);
	return 1;
}


