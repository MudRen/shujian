// xykm_job.h

#define DEBUG_MODE 0

string xykm_job()
{
	object me = this_player();
	int max,i;
	object obj1;
	object *ob_list;
	object ob2;
//	if (!wizardp(me))	
//              return "��ʱ�ر�,������������֪ͨ!";
	if ( me->query_temp("xykm_job") )
		return "�㲻���Ѿ��ӹ���������";
	
	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);
	for (i=0;i<max;i++){
		obj1 = ob_list[i];
		if (obj1->query_temp("xykm_job") )
		return "����������Ѿ�����" + obj1->query("name")
		+"("+capitalize(obj1->query("id"))+")"+"ȥ���ˡ�";
	}
//����
	if( !wizardp(me) && !DEBUG_MODE ) {
	if ( me->query_condition("job_busy") || me->query_condition("xykm_job_busy"))
		return "���ϴ����������ˣ���������Ϣһ����˵�ɡ�";

	if (me->query("job_name") == "���������ɹŴ��")
		return "���ϴ����������ˣ���������Ϣһ����˵�ɡ�";
/*		
	if( me->query_temp("xykm_job") )
		return "����������û��ʲô������Ը��㡣";*/
//����
	}

	ob2 = new("/clone/npc/zhong-shentong");
	if( ob2 ){
		destruct(ob2);
	}
			
	command("say Ӧ�����������룬�������������ԭ�������ָ����������ŵֿ��ɹž��ӵĹ�����\n" );

	set_temp("xykm_job",1);

	// ������Ϣ
	me->set_temp("xykm_job/asked",1);
	me->apply_condition("job_busy", 30);
	command("say ���������ɹŽ��������ıؾ�֮�أ��������������ָ���ȥ�����ɹž��ӹ�����\n");
	CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIR"%s��ʼ�����ǵֿ��ɹŴ������", me->name(1)));

	if (wizardp(me)) {
		me->apply_condition("xykm_job", 6);
		me->set("neili", me->query("max_neili")*2);
	}
	else
		me->apply_condition("xykm_job", 10);

	return "�ɹž��Ӳ����������֣��������ӣ������󷨣��Բ���ȫ���м��мǡ�";
}
