//Cracked by Kafei
//����˵���ļ�
�ļ�����:
�ļ�����:
	job_family_master.h  //����master��������Ϣ.
����:
	static mapping family_master 			//	ÿ������master�ĳƺ�
	static mapping family_master_place		//    ÿ������ master�ĵص�
	static mapping *wudang_message
	static mapping *xingxiu_message
	static mapping *huashan_message        //��ÿ������master˵�Ļ�
	static mapping *taohua_message
	static mapping *gaibang_message
	static mapping *emei_message
	static mapping *baituo_message
	static mapping *quanzhen_message
	static mapping *xueshan_message
	static mapping *dali_message
	static mapping *shaolin_message

�ļ�����:
	job_area.h			//�������ļ�
����:
	string *zhongyuan	//ÿ�������������ĵ���
	string *jiangnan
	string *nanjiang
	string *xiyu
	string *dongbei

	string *cant_go_room //���ܽ���ķ����б�
����:
	string *get_arearoom(string area)//��ȡָ������ķ����ļ����б�
	int judge_room(string room_name)//������ѡȡ�ķ����Ƿ�Ϻ�����(�����Ƿ���nofight room...)
	string get_room(string area)//��һ�������л��������ķ���

	
�ļ�����:
	oppose_pker.h				//����oppose_pker����������ļ�
����:
	int	oppose_pker(object master,object player,mapping job)//����oppose_pker��������
	void out_killer(object player,object place)//killer���ֵĺ���
	int job_oppsse_pker_start(object player)//����ص��ʼ׼������killer
	int award_oppose_pker(object player)//oppose_pker�Ľ�������

�ļ�����:
	job_produce.h   //����������Ļ������������ļ�

����:
	
	int assign_job(object master,object player,mapping map) //����mapָ������
	int finish_job(object player)//������ɵĺ���
	int master_tell_player(object player)//master��player�´�����ĺ���
	int award_job(int exp_lim,int pot_lim,int time1,int time2,int luck,
		int neili,int jingli,int skills_lim,object player,object master)
	//��������
	void job_punish(object player,string job_kind)//�ͷ�����
	int del_job(object player)//ɾ������

�ļ�����:
	produce.c //���������������
����:
	string menpai_name;//������������� 
	string strategy_produce;//ѡ�����ɲ����Ĳ������ơ�
	string menpai_area_power;//ѡ�����ɲ������������
	static object job_data;	//����������������ļ�
	static mapping job_map;		

	

����:
	object choose_user(string menpai_name)//�����ߵ��û���ѡ�������ִ����
	int do_check_user(object ob,string menpai_name)//�ж��û��Ƿ������������Ӻ���
	int do_check_job_player(object ob,string *list)//�жϵ�ǰ�û��Ƿ����������ִ���ߵ��Ӻ���
	int choose_job(object player)//ѡ������
	int check_finishjob_place()//�ж����������Ƿ�ص�master palce.
	int check_askjob_place()//�жϽӵ��´���������Ƿ񵽴� master place
	int check_oppose_pker_place()//���ִ���ߵ����ڵأ��Ƿ�Ϊoppose_pker place
	int check_player_place()//һ������ȫ��jobִ����ĺ���//��ʱ������е�xkx online player��������Ӧ�Ĵ���
	int job_tell_player(object player)//��������󣬸���ִ���������������Ϣ
	void create()
	string query_save_file()
	int produce_job(string p_name)//���������������
	int choose_menpai()//ѡ������
	int choose_strategy(string menpai)//ѡ�������´�����Ĳ���
	int choose_area_power(string menpai)//ѡ��ִ�����������


	message.h
	int job_oppsse_pker_prompt(object player)//��ʾִ����ȥ���oppsse_pker����.
	int master_msg(object master,object player,string state,string command_mode)
	//�����ݿ��л��massage�����������滻






























