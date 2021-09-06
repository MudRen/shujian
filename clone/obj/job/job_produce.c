//Cracked by Kafei
//wzfeng@xkx 2000 6
// job produce system.
//���������
#include <ansi.h>
inherit F_SAVE;
inherit ITEM;
/************************************************************************************/
//job_proudce�еı��������ݡ�

nosave string menpai_name;//������������� 
nosave string strategy_produce;//ѡ�����ɲ����Ĳ������ơ�
nosave string menpai_area_power;//ѡ�����ɲ������������
//ִ���������������
//object job_player;
nosave object job_data;
nosave mapping job_map;

/********************************************************************************/


#include "lpc_math.h"
#include "job_include.h"
#include "default_data.h"
#include "job_family_master.h"
#include "job_message.h"
#include "job_area.h"
#include "oppose_pker.h"
//#include "protect.h"
#include "job_produce.h"
#include "job_assess.h"

//�����ߵ��û���ѡ�������ִ����
object choose_user(string menpai_name)
{
	object *choose_user;
	int i;
	choose_user=filter_array(users(), "do_check_user", this_object(),menpai_name);
	if(!sizeof(choose_user))
	{
		//printf("user list=0\n");
		return 0;
	}
	//write(choose_user[random(i)]->query("name")+"��ѡ��\n");
	return choose_user[random(sizeof(choose_user))];
}
//�ж��û��Ƿ������������Ӻ���
int do_check_user(object ob,string menpai_name)
{
	string* havejob_player,room_name;
//	object room;

	 if(
		 !userp(ob)
		 ||!interactive(ob)
		 ||!living(ob)
		 //||ob->is_busy()
		 //||ob->set_temp("pending/exercise")
 		 //||ob->set_temp("pending/respirate")
	 	 //||ob->is_fighting()
		 ||wizardp(ob)
		 ||ob->query("combat_exp")<100000
		 //||query_idle(ob)
		 ||ob->query("family/family_name")!=menpai_name
		 
		 )
	 {
		 
		 //printf("����ѡ����%s\tplayer\t%s��������%s\n",menpai_name,ob->query("name"),ob->query("family/family_name"));
		 return 0;
	 }
	 	/////////////////////////////////////////////////////
	//had the player in job_list
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	if(is_attr_mapping(ob->query("id"),"job_player",job_data->query_job_data()))return 0;
	/////////////////////////////////////////////////////
	//does the player in no job room
	room_name=file_name(environment(ob));
		if (strsrch(room_name, "/d/shaolin/dmyuan2")==0||
			strsrch(room_name, "/d/wizard/")==0 ||
			strsrch(room_name, "/d/taohua/")==0 ||
			strsrch(room_name, "/d/qilian/dilao")==0 ||
			strsrch(room_name, "/d/shaolin/jianyu")==0 ||
			strsrch(room_name, "/d/wizard/guest_room")==0 ||
			strsrch(room_name, "/d/city/wumiao")==0 ||
			strsrch(room_name, "/d/qilian/dilao")==0 ||
			strsrch(room_name, "/d/city/kedian")==0 ||
			strsrch(room_name, "/clone/ship/seaboat1")==0 ||
			strsrch(room_name, "/d/zhongnan/liangong1")==0 ||
			strsrch(room_name, "/d/huashan/liangong1")==0 ||
			strsrch(room_name, "/d/wudang/liangongfang")==0 ||
			strsrch(room_name, "/d/baituo/base1")==0 ||
			strsrch(room_name, "/d/bwdh")==0
			) 
		{
			write("player�ڷǷ��ص�\n");
		return 0;
		}
	/////////////////////////////////////////////////////

	 return 1;
}
//�жϵ�ǰ�û��Ƿ����������ִ���ߵ��Ӻ���
int do_check_job_player(object ob,string *list)
{
	int i;
	for(i=0;i<sizeof(list);i++)
	{
//		printf("%s\n",ob->query("name"));
			if( userp(ob)
				&&ob->query("race") == "����"
				&&interactive(ob))
				if(ob->query("id")==list[i])
					return 1;
	}
	 return 0;
}


int choose_job(object player)
{
	string job_strategy;
	return 1;
}
//assess check.
void check_assess_award()
{
	string family;
	string player_name;
	object player,place,master;
	mapping *family_assess,family_map;
	
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();

	//check very family number.
	
	family=job_data->is_familyassess_full();
	
	//write(family);
	family_assess=job_data->query_family_assess_data();
	if(!family)
		return;
	

	family_map=get_mapping(family,"family",family_assess);
	//If family meeting . return.
	if(sizeof(family_map))
		return;

	player_name=get_award_player(family);
	if(!player_name)
		return;
	
	//send all menpai player award messgae.
	if(!(place=find_object(family_master_place[family])))
		place=load_object(family_master_place[family]);
	if(!objectp(place))
		return;
	
		
	if(!master=find_object(family_master_basefile[family]))
		master=new(family_master_basefile[family]);
	
	if(!objectp(master)) return;
	//write("send message");
	send_assess_msg(master,family);

	return;
}
//check when assess start.
void check_start_assess()
{
	int i,step;
	string family_msg;
	mapping *family_assess;
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_assess=job_data->query_family_assess_data();
	if(!pointerp(family_assess))
		return;
	for(i=0;i<sizeof(family_assess);i++)
	{
//		write(p_map(family_assess[i]));

		if(!family_assess[i]["family"])
			continue;
		if(family_assess[i]["time"]+ASSESS_DELAY>time())

		{
			printf("ʱ��û��������%d��",family_assess[i]["time"]+ASSESS_DELAY-time());
			prompt_assess_player(family_assess[i]["family"],family_assess[i]["time"],family_assess[i]["place"]);
			continue;
		}
		step=family_assess[i]["assess_start"];
		if(family_assess[i]["time"]+ASSESS_DELAY<time()&&step==0)
			job_data->set_start_assess(family_assess[i]["family"],1);

		//write("here");
		switch(step)
		{
		case 1:
			write("setp1");
			do_assess_1(family_assess[i]);
			break;
		case 2:
			write("setp2");
			do_assess_2(family_assess[i]);
			break;
		case 3:
			write("setp3");
			do_assess_3(family_assess[i]);
			break;
		case 4:
			write("setp4");
			do_assess_4(family_assess[i]);
			break;
		case 5:
			write("setp5");
			do_assess_5(family_assess[i]);
			break;


		}
	}
}
void check_assess_player_place()
{
	string state,*player_list;
	int player_num,i;
	object *ob_player,room_master,master;
	mapping assess_player,player_map;
	state="";
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	assess_player=job_data->query_assess_playermap();
	if(!sizeof(assess_player))
		return;

	//write(p_map(assess_player));
	player_list=keys(assess_player);
	ob_player=filter_array(users(), "do_check_job_player", this_object(),player_list);
	if(!sizeof(ob_player))
		return;
	
	for(i=0;i<sizeof(ob_player);i++)
	{
		//write(ob_player[i]->query("name"));
		player_map=make_assess_playermap(ob_player[i],assess_player[ob_player[i]->query("id")]);
		//write(p_map(player_map));
		if(file_name(environment(ob_player[i]))==player_map["master_place"])
		{
			//write("here");

			if(!(room_master=find_object(player_map["master_place"])))
				room_master=load_object(player_map["master_place"]);
			if(!objectp(room_master))
				continue;
			if(!objectp(master = present(player_map["master_name"],room_master)))
				continue;
				if(player_map["mode"]=="good")
					family_assess_award(ob_player[i],master,player_map["family_name"]);
				if(player_map["mode"]=="bad")
					family_assess_punish(ob_player[i],master,player_map["family_name"]);
		}
	}

	return;
}


void check_finishjob_place()
{
	string state,*player_list;
	int player_num,i;
	object *ob_player;
	state="";
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();
	
	/*****get job player list from job data.*******/
	player_list=job_data->query_list("finish_job");
	//write("get player_list\n");
	if(!sizeof(player_list))
	{
	//	write("no player_list");
		return;
	}
//	write("�����Ѿ�����������:\n");
/*	for(i=0;i<sizeof(player_list);i++)
		{
		write(player_list[i]+"\n");
	}
*/	
	/***************filtrate online user ,only choose the player that on job_player_list.*/
	write("ok here now");
	ob_player=filter_array(users(), "do_check_job_player", this_object(),player_list);
	//write("ok filter_array");
	if(!sizeof(ob_player))
	{
		//write("no_player\n");

		return;
	}
	
	
	
	for(i=0;i<sizeof(ob_player);i++)
	{

		job_map=get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data());
		if(file_name(environment(ob_player[i]))!=
			get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data())["job_master_place"]
			)
		{
			if(job_map["job_oppose_pker_finish_time"]+1200<time())
			{
				if( wizardp(ob_player[i]) && (string)ob_player[i]->query("env/job_system")=="open" )
					tell_object(ob_player[i],"finish time over\n");
				del_job(ob_player[i],"finish_job");
				return;
			}

			if(ob_player[i]->query_temp("job_system/prompt_time")>6)
			{
				//job_finish_prompt(ob_player[i]);
				tell_object(ob_player[i],"�����Ѿ���ɣ��Ͽ��ȥ�����ɡ�\n");
				ob_player[i]->delete_temp("job_system/prompt_time");
			}
			else ob_player[i]->add_temp("job_system/prompt_time",1);
		}
		else
		{
			
			finish_job(ob_player[i]);
		if( wizardp(ob_player[i]) && (string)ob_player[i]->query("env/job_system")=="open" )
			tell_object(ob_player[i],"finish_job");

		}
		
	}
	return;
}

//���ִ���ߵ����ڵأ��Ƿ�Ϊmaster place
void check_askjob_place()
{
	string state,*player_list;
	int player_num,i;
	object *ob_player;
	state="";
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;

	job_data->restore();
	/*****get job player list from job data.*******/
	player_list=job_data->query_list("ask_job");
	if(!sizeof(player_list))
		return;
	//write("�����Ѿ��쵽�������:\n");
	/*for(i=0;i<sizeof(player_list);i++)
	{
		write(player_list[i]+"\n");
	}
	*/
	/***************filtrate online user ,only choose the player that on job_player_list.*/
	ob_player=filter_array(users(), "do_check_job_player", this_object(),player_list);
		if(!sizeof(ob_player))
		return;

	for(i=0;i<sizeof(ob_player);i++)
	{
		job_map=get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data());
		if(file_name(environment(ob_player[i]))!=
			get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data())["job_master_place"]
			)
		{
			if( wizardp(ob_player[i]) && (string)ob_player[i]->query("env/job_system")=="open" )
			//write(get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data())["job_master_place"]+"\n");
//////////////////////////////////////////////////////////////////////////////////////////////////
			if(job_map["job_master_prompt_time"]+900<time())
			{
				if( wizardp(ob_player[i]) && (string)ob_player[i]->query("env/job_system")=="open" )
					tell_object(ob_player[i],"finish time over\n");
				del_job(ob_player[i],"oppose_pker");
				return;
			}
			if(ob_player[i]->query_temp("job_system/prompt_time")>6)
			{
				job_class_prompt(ob_player[i]);
				ob_player[i]->delete_temp("job_system/prompt_time");
			}
			else ob_player[i]->add_temp("job_system/prompt_time",1);
		}
		else
		{
			master_tell_player(ob_player[i]);
		}
		
	}
	return;
}
//���ִ���ߵ����ڵأ��Ƿ�Ϊoppose_pker place

void check_oppose_pker_place()
{
	string state,*player_list;
	int player_num,i;
	object *ob_player;
	state="";
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;

	job_data->restore();
	//get job player list from job data.
	player_list=job_data->query_list("oppose_pker");
	if(!sizeof(player_list))
		return;
	/*write("��������ִ���������:\n");
	for(i=0;i<sizeof(player_list);i++)
	{
		write(player_list[i]+"\n");
	}
*/

	//filtrate online user ,only choose the player that on job_player_list.
	ob_player=filter_array(users(), "do_check_job_player", this_object(),player_list);
		if(!sizeof(ob_player))
		return;

	
	for(i=0;i<sizeof(ob_player);i++)
	{
		job_map=get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data());
		//Is the place same as where the player kill killer?
		if(file_name(environment(ob_player[i]))!=
			get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data())["job_oppose_pker_place"]
			)
		{
			//over the job time limit . delete job.
			if(job_map["job_oppose_pker_time"]+1200<time())
			{
				del_job(ob_player[i],"oppose_pker");
				return;
			}
			//no a kill killer place. then delete player killer prompt fag.
			ob_player[i]->delete_temp("job_system/start_prompt");
			//dose the player have ready to be prompt ?
			if(ob_player[i]->query_temp("job_system/prompt_time")>6)
		{

			job_start_prompt(ob_player[i]);
			ob_player[i]->delete_temp("job_system/prompt_time");
		}
		else ob_player[i]->add_temp("job_system/prompt_time",1);

		}
		else
		{
			//dose the player killing the killer.
			if(!ob_player[i]->query_temp("job_system/kill_killer"))
			{
				if( wizardp(ob_player[i]) && (string)ob_player[i]->query("env/job_system")=="open" )
				tell_object(ob_player[i], "λ�õ���.\n");
				//no,do job_oppsse_pker_start.
				job_oppsse_pker_start(ob_player[i]);
			}
		}
	}
	return;
}
///////////////////////////////////////////////////////////////////////////////////////
//���ִ���ߵ����ڵأ��Ƿ�Ϊoppose_pker place

/*int check_protect_place()
{
	string state,*player_list;
	int player_num,i;
	object *ob_player;
	state="";
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
		if(!objectp(job_data)) return;

	job_data->restore();
	//get job player list from job data.
	player_list=job_data->query_list("protect");
	if(!sizeof(player_list))
		return 1;
	write("�������ڱ���ִ���������:\n");
	for(i=0;i<sizeof(player_list);i++)
	{
		write(player_list[i]+"\n");
	}


	//filtrate online user ,only choose the player that on job_player_list.
	ob_player=filter_array(users(), "do_check_job_player", this_object(),player_list);
		if(!sizeof(ob_player))
		return 1;

	
	for(i=0;i<sizeof(ob_player);i++)
	{
		job_map=get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data());
		
		if(file_name(environment(ob_player[i]))!=
			get_mapping(ob_player[i]->query("id"),"job_player",job_data->query_job_data())["job_protect_place"]
			)
		{
			//over the job time limit . delete job.
			if(job_map["job_protect_time"]+1800<time())
			{
				del_job(ob_player[i],"protect");
				return 1;
			}
			//no a kill killer place. then delete player killer prompt fag.
			ob_player[i]->delete_temp("job_system/start_prompt");
			//dose the player have ready to be prompt ?
			if(ob_player[i]->query_temp("job_system/prompt_time")>6)
		{
			job_start_prompt(ob_player[i]);
			ob_player[i]->delete_temp("job_system/prompt_time");
		}
		else ob_player[i]->add_temp("job_system/prompt_time",1);

		}
		else
		{
			//dose the player killing the killer.
			if(!ob_player[i]->query("job_system/protect"))
			{
				if( wizardp(ob_player[i]) && (string)ob_player[i]->query("env/job_system")=="open" )
				tell_object(ob_player[i], "λ�õ���.\n");
				//no,do job_oppsse_pker_start.
				job_protect_start(ob_player[i]);
			}
		}
	}
	return 1;
}
*/
///////////////////////////////////////////////////////////////////////////////

//һ������ȫ��jobִ����ĺ���
//��ʱ������е�xkx online player��������Ӧ�Ĵ���
//���ܣ����ִ���ߵ����ڵأ�ֱ������master placeΪֹ��
//���ܣ����ִ���ߵ����ڵأ�ֱ������oppose_pker_placeΪֹ��
void check_player_place()
{
	//clear some job system temp data.
	clean_up_job_object();
/////////////////////////////////////////////
	check_assess_award();
	check_start_assess();
	check_askjob_place();
	check_oppose_pker_place();
	//check_protect_place();
	check_finishjob_place();
	check_assess_player_place();

	
	

	return ;
}

//��������󣬸���ִ���������������Ϣ



void create()
{
	 set_name("���������",  ({"job_produce"}));
	seteuid(getuid());
}

//��������
string query_save_file()
{
        return DATA_DIR + "job_system/produce"; 
}
//���������������
void produce_job(string p_name)
{
	
	int job_succeed,ret;
	object obj_temp,job_player;
	string produce_report,job_player_name;
	//restore();
	if(!objectp(obj_temp=new(JOB_DIR+"job_menpai")))
	return;
	obj_temp->restore();
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return;
	job_data->restore();


	produce_report=HIW"����ϵͳ����:\n"NOR;
	produce_report += HIC"����ѡ��:\t"NOR;
	while ( ret < 10 && !objectp(job_player)) {
   	ret++;
    
	if(!choose_menpai())
		produce_report += HIR"����\n"NOR;
	else
		produce_report += HIW+menpai_name+"\n"NOR;
	
	produce_report += HIC"���ɲ���ѡ��:\t"NOR;

	if(!choose_strategy(menpai_name))
		produce_report += HIR"����\n"NOR;
	else
		produce_report += HIW+strategy_produce+"\n"NOR;

	produce_report += HIC"����ѡ��:\t"NOR;

	if(!choose_area_power(menpai_name))
		produce_report += HIR"����\n"NOR;
	else
		produce_report += HIW+menpai_area_power+"\n"NOR;
	produce_report += HIC+"ִ����Ϊ"+"\t"+NOR;
	
	job_player=choose_user(menpai_name);

	//*****************************************************
	if(p_name)
		{
		job_player=find_player(p_name);
		
/*		if(!do_check_user(job_player,job_player->query("family/family_name")))
			return;
*/		
		if(is_attr_mapping(job_player->query("id"),"job_player",job_data->query_job_data()))
			return;
	}
	//*****************************************************
    }
	if(!objectp(job_player))
	{
		produce_report += HIR"�������û���ҵ�\n"NOR;
		job_player_name="";
		job_succeed=0;
	}

/*	if(job_player==this_object())
	{
		produce_report += HIR"�������û���ҵ�\n"NOR;
		job_player_name="";
		job_succeed=0;
	}
	*/
	else
	{

	produce_report += HIW+job_player->query("name")+"("+job_player->query("id")+")"+"\n"NOR;
	job_player_name=job_player->query("name")+"("+job_player->query("id")+")";
	job_succeed=1;
	}
	//printf("%s",produce_report);

	if(job_succeed)
	{
		job_tell_player(job_player);
		save();

	}
	//temp();
	if(obj_temp)
	destruct(obj_temp);

	write ("�������\n");

	return;

}

//ѡ������
int choose_menpai()
{
	object obj_temp;
	string menpai;

	if(!objectp(obj_temp=new(JOB_DIR+"job_menpai")))
	return 0;
	obj_temp->restore();
	menpai=obj_temp->get_random_menpai();
	

	while(menpai_name==menpai)
	menpai=obj_temp->get_random_menpai();
	if(!(obj_temp->have_menpai(obj_temp->con_name(menpai,1))))
		return 0;

	//����ѡ�е�����
	menpai_name=menpai;
	save();
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}
//ѡ�������´�����Ĳ���
int choose_strategy(string menpai)
{
	object obj_temp;
	//string strategy;

	if(!objectp(obj_temp=new(JOB_DIR+"job_menpai")))
	return 0;
	obj_temp->restore();
	strategy_produce=obj_temp->random_get_menpai_strategy(menpai);

	
	//write("����ѡ����:\t"+strategy_produce+"\n");
	
	if(!obj_temp->have_strategy(obj_temp->con_name(menpai,1),strategy_produce,0))
		return 0;
	save();
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}
//ѡ��ִ�����������
int choose_area_power(string menpai)
{
	object obj_temp;
	//string strategy;
	if(!objectp(obj_temp=new(JOB_DIR+"job_menpai")))
	return 0;
	obj_temp->restore();
	menpai_area_power=obj_temp->random_get_menpai_areapower(menpai);
	//write("����ѡ����"+menpai_area_power+"\t");
	if(!obj_temp->have_power(obj_temp->con_name(menpai,1),menpai_area_power,0))
		return 0;
	//printf("��ǰ���������ֵ=%d\n",obj_temp->have_power(obj_temp->con_name(menpai,1),menpai_area_power,0));
	save();
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}

