//Cracked by Kafei
//wzfeng@xkx 2000 7
//ask somethig about master
//ask master about "���׶�"

#define JOB_DIR "/clone/obj/job/"
//#include JOB_DIR+"lpc_math.h"
//#include JOB_DIR+"job_family_master.h"
#include "/clone/obj/job/lpc_math.h"
#include "/clone/obj/job/job_family_master.h"

void tell_player_family_job_contribute(object player,object master)
{
	object job_data,menpai_ob;
	string family_name,master_name,master_call,msg;
	mapping family_map;
	int point;
	family_name=player->query("family/family_name");
	if(!family_name||
		family_name!=master->query("family/family_name"))
	{
		message_vision(CYN "$n��$N˵������λ"+RANK_D->query_respect(player)+"�ʴ����˰ɣ�"
		+RANK_D->query_self(master)+"��ô֪�����������ء�\n" NOR, player, master);
		return;
		
	}
	master_name=explode(family_master[family_name], "/")[2];
	master_call=explode(family_master[family_name], "/")[0];
	if(master->query("id")!=master_name)
	{
		message_vision(CYN "$n��$N˵������ȥ��"+master_call+"�ɡ�\n" NOR, player, master);
		return;
	}

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_map=job_data->query_family_job_data(family_name);
	if(!mapp(family_map)
		||family_map["job_contribute"]<=0)
	{
		message_vision(CYN "$n��$Nҡҡͷ˵����"+family_name+"���Ӳ���������ûΪ"+family_name+"�����κι����ء�\n" NOR, player, master);
		return;
	}
	message_vision(CYN "$n��$N˵����Ŀǰ��"+family_name+"�Ĺ��׶�Ϊ"+chinese_number(family_map["job_contribute"])+"�㡣\n"NOR, player, master);
	if(!family_map[player->query("id")])
		point=0;
	else
		point=family_map[player->query("id")];
	if(point<0)
		msg="��̫��"+family_name+"ʧ���ˣ��մ���ȥ�������´�"+family_name+"����ϱ����ط���";
	else
		msg="��Ҫ����Ŭ������ȡ���´�"+family_name+"����ϵõ����������";
	message_vision(CYN "$n��$N˵������Ϊ"+family_name+"�����Ĺ���Ϊ"+chinese_number(point)+"�㡣"+msg+"\n"NOR, player, master);
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	//write("here");
	if(!objectp(menpai_ob)) return 0;
	menpai_ob->restore();
	
	family_map=menpai_ob->query_assess_basenum(family_name);
	if(!undefinedp(family_map["family_assess_num"]))
	{
		point=family_map["family_assess_num"];
		message_vision(CYN "$n˵������"+family_name+"���׶ȴﵽ"
		+chinese_number(point)+"ʱ�����ٿ��´ε�"+family_name+"��ᡣ\n"NOR, player, master);
	}
	if(objectp(menpai_ob))
		destruct(menpai_ob);
	if(objectp(job_data))
		destruct(job_data);



}

