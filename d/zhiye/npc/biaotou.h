// biaotou.h
// by augx@sj  10/17/2001

string ask_guard()
{	
	object me = this_player();
	int lvl,i,j,k;
	
	if( me->query_user_type() == "worker" ) {
		lvl = me->query_temp("worker_skill_highest");
		i = lvl/2; j = lvl*2/3; k = lvl;
		if(i<50) i = 50;
		if(j<50) j = 50;
		me->delete_temp("worker_skill_limit");
		me->delete_temp("worker_skill_highest");		

		return  "���ھ��ṩ�����ڷ���ÿ�η����ʱ��Ϊһ���ӣ�Ŀǰ��Ϊ���ṩ���ӵ��εı��ڣ�\n"+
			sprintf("%-32s%-14s%-6s%-30s\n","��ͨ����(guard1) ������ �书�ȼ���",CHINESE_D->chinese_number(i),"Ӷ��",MONEY_D->price_str( (i>300)?(i*1500):(i*1000) ))+
			sprintf("%-32s%-14s%-6s%-30s\n","�߼�����(guard2) ������ �书�ȼ���",CHINESE_D->chinese_number(j),"Ӷ��",MONEY_D->price_str( (j>300)?(j*1500):(j*1000) ))+
			sprintf("%-32s%-14s%-6s%-30s\n","��������(guard3) ������ �书�ȼ���",CHINESE_D->chinese_number(k),"Ӷ��",MONEY_D->price_str( (k>300)?(k*1500):(k*1000) )) ;
	}
	else
		return "˵Ц�ˣ���������������ָ��ֻ���Ҫ�˱�����";
}

string do_fire(int type)
{
	object me = this_player() , guard;
	int lvl;
	
	if( !wizardp(me) && (int)me->query_temp("fire_guard") && me->query_temp("fire_guard")>time() )
		return "�㲻���Ѿ�Ƹ�뱣������";
	if( me->query_user_type() != "worker" )
		return "˵Ц�ˣ���������������ָ��ֻ���Ҫ�˱�����";
		
	lvl = me->query_temp("worker_skill_highest");
	lvl = lvl * type / 6;
	if(lvl<50) lvl = 50;
	me->delete_temp("worker_skill_limit");
	me->delete_temp("worker_skill_highest");
	
	if( is_wanted(me) )
		return "���ǲ�����ͨ������";
			
	switch( MONEY_D->player_pay(me, (lvl>300)?(lvl*1500):(lvl*1000)) ) {
		case 0:
		case 2:	return "��û���㹻��Ǯ֧��Ӷ��";
		default: break;
	}
	message_vision("$N����$n"+MONEY_D->price_str((lvl>300)?(lvl*1500):(lvl*1000))+"����Ӷ���ڡ�\n",me,this_object());
	
	guard = new(__DIR__"wguard");
	if(!guard) return "error! please tell wizard!";
	guard->do_copy(me,lvl);
	
	guard->move(environment(me));
	message_vision("$N���������˳�����\n",guard);
	guard->set_leader(me);
	
	me->set_temp("fire_guard",time()+15*60);
	return "�����ģ�����һ�����ڣ����ǻᱣ֤���İ�ȫ��";
}

string ask_guard1()
{
	return do_fire(3);
}

string ask_guard2()
{
	return do_fire(4);
}

string ask_guard3()
{
	return do_fire(6);
}
