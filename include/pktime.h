
#include <ansi.h>
#define REFRESH_TIME 120
/* �����Զ������ʱ�� ��λ �� */
string* query_same_ip(object me,mapping all,string ip);

int meisdummy(object me,object target)
{
	if(me->query("registered") > 2) return 0;//vip have no this limit	
	if (userp(target) && userp(me)
	&& (!living(target) && me->query("mud_age") < (time() - me->query("birthday"))/24
	|| me->query("mud_age") / 6 > me->query("combat_exp"))) return 1;
	return 0;
}

int pktime_limit(object me,object target)
{
	string ts = ctime(time())[0..2];
	mapping be_killed_ip;
	string* ids;

					
	if ( !userp(me) || !userp(target)) return 0;
		
	if (strsrch(file_name(environment(me)),"/cmds/leitai/") >= 0
	 && strsrch(file_name(environment(target)),"/cmds/leitai/") >= 0) return 0;
	 
	if( target->query_temp("be_killed_ip") && !mapp(target->query_temp("be_killed_ip")))
		target->delete_temp("be_killed_ip");
	be_killed_ip = target->query_temp("be_killed_ip");
	if(!be_killed_ip) be_killed_ip = ([]);
	ids = keys(be_killed_ip);	
	if( me!=target &&  interactive(me) && (!sizeof(ids) || member_array(getuid(me),ids) == -1 ) )//���ڹ��������б��ڲŲ�ȡ��ʩ �ټ��ϱ��������ߵ����
	{
		string* ips = values(be_killed_ip);
		string* check_idip = query_same_ip(target,be_killed_ip,query_ip_number(me));
		if(ips && sizeof(ips) && member_array( query_ip_number(me),ips)!=-1 && check_idip && sizeof(check_idip)>0 ) //�ó�ML PK�Ľ���
		{
			log_file("nosave/MLPK",
				sprintf("%-8s ���ܸ� %s MLPK %-8s ����%s",getuid(me), implode(check_idip,","),getuid(target), query_ip_number(me)  ),
				this_object() );
			tell_object(me,sprintf(HIG"\n����Ϸ��ֹMulti-Login TK���Ѿ���%s������IP��ͬ�����(%s)��Ŀ����ս���ˡ�\n"NOR,
				chinese_number(sizeof(check_idip)),implode(check_idip,",")) );			
			tell_object(me,BLINK HIR"��ķ�����Ϊ�Ѿ���ϵͳ��¼��\n\n"NOR NOR);
		}
		if(check_idip && sizeof(check_idip)>2)
		{
			return 1;//������ɱ��
		}
		be_killed_ip[getuid(me)]=query_ip_number(me);
		call_out("delete_ip_flag",REFRESH_TIME,target,getuid(me));
		target->set_temp("be_killed_ip",be_killed_ip);		
		//target->start_call_out( (:call_other, this_object(), "delete_ip_flag", getuid(me) :),5);
	}
	
	if ( target->query_condition("killer") && target->query_condition("pk") ) return 0;
	
	if (strsrch(file_name(environment(me)), "/d/group") >=0 
	 && strsrch(file_name(environment(me)), "/d/group/entry") !=0 ) return 0;
	
	ts = replace_string(ts, "Sun", "������");
	ts = replace_string(ts, "Mon", "����һ");
	ts = replace_string(ts, "Tue", "���ڶ�");
	ts = replace_string(ts, "Wed", "������");
	ts = replace_string(ts, "Thu", "������");
	ts = replace_string(ts, "Fri", "������");
	ts = replace_string(ts, "Sat", "������");
	
	
	
	return 0;

	if ( ts == "������" || ts == "������") return 0;

	notify_fail("������"+ts+"����ֻ���ڹ涨�����ڽ�������������Ϊ��\n");
	return 1;
}

string* query_same_ip(object me,mapping all,string ip)
{
	string* ret = ({});
	string* k;
	object targetob;
	if(!all) return 0;
	if(!k = keys(all) || !sizeof(k)) return 0;
	if(!ip) return 0;
	for(int i=0;i<sizeof(k);i++)
	{
		if(all[k[i]]==ip)
		{
			targetob = find_player(k[i]);
			if(!targetob) continue;
			if(me->is_fighting(targetob)) ret += ({k[i]});
		}
	}
	return ret;
}

void delete_ip_flag(object me,string id)
{
	mapping bekilledip;
	//message("wizard:ciwei",sprintf(HIR"��ʱ�����Ϣ��%O id:%s\n"NOR,me,id),users());	
	if(!me) return;
	bekilledip = me->query_temp("be_killed_ip");
	if(!bekilledip || !mapp(bekilledip)) return;
	map_delete(bekilledip,id);
}
