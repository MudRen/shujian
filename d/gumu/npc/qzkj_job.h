// qzkj_job.h

#define DEBUG_MODE 0

string qzkj_job()
{
	object me = this_player();
	int max,i;
	object obj1;
	object *ob_list;
	object ob2;
//	if (!wizardp(me))	
              return "Ŀǰս�±Ƚ�ƽ����û��˵���н���������㻹������ذ�!";
	if ( me->query_temp("qzkj_job") )
		return "�㲻���Ѿ��ӹ���������";
	
	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);
	for (i=0;i<max;i++){
		obj1 = ob_list[i];
		if (obj1->query_temp("qzkj_job") )
		return "����������Ѿ�����" + obj1->query("name")
		+"("+capitalize(obj1->query("id"))+")"+"ȥ���ˡ�";
	}
//����
	if( !wizardp(me) && !DEBUG_MODE ) {
	if ( me->query_condition("job_busy") || me->query_condition("qzkj_job_busy"))
		return "���ϴ����������ˣ���������Ϣһ����˵�ɡ�";

	if (me->query("job_name") == "ȫ��̿������")
		return "���ϴ����������ˣ���������Ϣһ����˵�ɡ�";
/*		
	if( me->query_temp("qzkj_job") )
		return "����������û��ʲô������Ը��㡣";
*/		
//����
	}

	ob2 = new("/clone/npc/zhong-shentong");
	if( ob2 ){
		destruct(ob2);
	}
		
	//GIFT_D->check_count(me,this_object(),"��Ħ��");
			
	command("say �ҸղŽӵ��ҽ̵�����־ƽ���棬���պ�����ǲ����������������ȫ��̡�\n" );

	set_temp("qzkj_job",1);

	// ������Ϣ
	me->set_temp("qzkj_job/asked",1);
	me->apply_condition("job_busy", 30);
	command("say �������ǽ��������ȫ��̵ıؾ�֮�أ����ٴ�������������������ɱ��\n");
	CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIR"%s��ʼȫ��̿����������", me->name(1)));

	if (wizardp(me)) {
		me->apply_condition("qzkj_job", 6);
		me->set("neili", me->query("max_neili")*2);
	}
	else
		me->apply_condition("qzkj_job", 10);

	return "������ʿ�в������֣��������ӣ������󷨣��Բ���ȫ���м��мǡ�";
}
