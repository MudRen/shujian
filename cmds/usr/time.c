// time.c
// yuj@sj �������緶Χ��ʱ�䣬������ʱ�䣬������
// ����vip��ʾ LinuX@SJ

#include <ansi.h>
#include <mudlib.h>


string Ctime(int t)
{
	string ts = ctime(t);

	ts = " "+ts[0..2]+ts[19..23]+"-"+ts[4..6]+"-"+ts[8..9]+ts[10..18];
	ts = replace_string(ts, "Sun", "������");
	ts = replace_string(ts, "Mon", "����һ");
	ts = replace_string(ts, "Tue", "���ڶ�");
	ts = replace_string(ts, "Wed", "������");
	ts = replace_string(ts, "Thu", "������");
	ts = replace_string(ts, "Fri", "������");
	ts = replace_string(ts, "Sat", "������");
	ts = replace_string(ts, "Jan", "һ��");
	ts = replace_string(ts, "Feb", "����");
	ts = replace_string(ts, "Mar", "����");
	ts = replace_string(ts, "Apr", "����");
	ts = replace_string(ts, "May", "����");
	ts = replace_string(ts, "Jun", "����");
	ts = replace_string(ts, "Jul", "����");
	ts = replace_string(ts, "Aug", "����");
	ts = replace_string(ts, "Sep", "����");
	ts = replace_string(ts, "Oct", "ʮ��");
	ts = replace_string(ts, "Nov", "ʮһ��");
	ts = replace_string(ts, "Dec", "ʮ����");
	return ts;
}

string SYDtime(int t)
{
	mixed *lt = localtime(t);

	if ( (lt[4] > 9 || lt[4] < 2)
	  || (lt[4] == 9 && lt[3] - 24 > lt[6])	// Last Sunday
	  || (lt[4] == 2 && lt[3] - 25 < lt[6])	// Last Sunday
	) return Ctime(t+3600)+" (����ʱ��)";
	else return Ctime(t);
}

string NZtime(int t)
{
	mixed *lt = localtime(t);

	if ( (lt[4] > 9 || lt[4] < 2)
	  || (lt[4] == 9 && lt[3] > lt[6])	// First Sunday
	  || (lt[4] == 2 && lt[3] - 5 < lt[6])	// First Sunday on or after 5
	) return Ctime(t+3600)+" (����ʱ��)";
	else return Ctime(t);
}

string NAtime(int t)
{
	mixed *lt = localtime(t);

	if ( (lt[4] > 3 && lt[4] < 9)
	  || (lt[4] == 3 && lt[3] > lt[6])	// First Sunday
	  || (lt[4] == 9 && lt[3] - 25 < lt[6])	// Last Sunday
	) return Ctime(t+3600)+" (����ʱ��)";
	else return Ctime(t);
}

string EUtime(int t)
{
	mixed *lt = localtime(t);

	if ( (lt[4] > 2 && lt[4] < 9)
	  || (lt[4] == 2 && lt[3] - 24 > lt[6])	// Last Sunday
	  || (lt[4] == 9 && lt[3] - 25 < lt[6])	// Last Sunday
	) return Ctime(t+3600)+" (����ʱ��)";
	else return Ctime(t);
}
void do_vip(object me)
{
	int t,t1;
	int this_week = time()/86400/7;
	int end_time = 1106452800; //January 23, 2005, 12:00 pm
	string site;
	
	site = lower_case(INTERMUD_MUD_NAME);

	if((me->query("vip/vip_time") > 1104508800) && end_time - time() > 0 && !me->query("vip/redeem") && site=="ln") //1104508800 January 1, 2005, 12:00 am
	{
		t1 = me->query("vip/vip_time") - time();
		write(sprintf(HIY"�����ϴι��%s��Ϊ�˲�������վǰ��ʱ��ĵ�����ʧ������������15�졣\n"NOR,
		(t1>0)?("ʣ��ʱ�䣺"+CHINESE_D->chinese_time(t1)):"�Ѿ�����"));	
		
		if (t1>0)
			me->add("vip/vip_time",15*24*3600);
		else
			me->set("vip/vip_time",time()+15*24*3600);
		me->set("vip/redeem",1);//���
		log_file("static/REDEEM",
				sprintf("%s ��ù��������\n",me->query("id")));
	}
		
	t = me->query("vip/vip_time") - time();
	if ( t > 0 && t < 86400)
			write (HIY+"���ʣ��ʱ�䣺" +BLINK+HIR+CHINESE_D->chinese_time(t) + "���뼰ʱ���ѡ�\n"+NOR);
	else if (t > 0)
			write (HIY"���ʣ��ʱ�䣺" +NOR+CHINESE_D->chinese_time(t) + "��\n");
	else if ((int)me->query("vip/vip_start_time") != 0)
			write(HIY"���ϵͳ��ʾ��"NOR"���Ĺ����Ч���Ѿ����ڣ��뼰ʱ���ѡ�\n");
	else
			write (HIY"���ϵͳ��ʾ��"NOR"��Ŀǰ���ǹ������γ�Ϊ����뿴( help vip )��\n");
	if ( t > 0 && (me->query("registered") < 3 )) {
		me->set("registered",3);
		write (HBRED+HIY"���Ĺ���Ѿ����\n"NOR);
	}
	if ( t < 0 && (me->query("registered") > 2 )) {
                	me->set("registered",2);
                	write( HBRED+HIY"���Ĺ���Ѿ����ڣ�ϵͳ�Ѿ��Զ�ȡ�����Ĺ����\n"NOR);
       	 }
	if ((int)me->query("vip/vip_start_time") != 0)
		write (HIY"�����Чʱ�䣺"+ NOR+CHINESE_D->chinese_date(me->query("vip/vip_start_time"),1) +"��\n");	
	else
		write (HIY"�����Чʱ�䣺"NOR"��û�й����Чʱ���¼��\n");
		
	//For all Bug By Ciwei@SJ
	while(me->query("ggs/left_time")>10*3600)
		me->add("ggs/left_time",-10*3600);
	
        if (me->query("registered") >= 3 && me->query("ggs/started") && me->query("ggs/start_time")){
		t = time()-(int)me->query("ggs/start_time");
		//me->set("ggs/left_time",me->query("ggs/left_time") - t);
		if (me->query("ggs/left_time") < 0 ) //��ֹbug
			me->set("ggs/left_time",0);
		
		write (HIY"�������״̬��"NOR+"�Ѿ�ʹ��"+CHINESE_D->chinese_time(t) +",���ܻ�����ʹ��"+CHINESE_D->chinese_time(me->query("ggs/left_time") -t) +"��\n");	
	}
        else if(me->query("registered") < 3)
		write (HIY"�������״̬��"NOR+"�㲻�ǹ��������ʹ�ù����������γ�Ϊ����뿴( help vip )��\n");	
	else if(this_week > me->query("ggs/last_week")) 
		write (HIY"�������״̬��"NOR+"��ǰ��û�н��й�����������ܻ�����ʹ��ʮ��Сʱ��\n");		
	else
		write (HIY"�������״̬��"NOR+"��ǰ��û�н��й�����������ܻ�����ʹ��"+CHINESE_D->chinese_time(me->query("ggs/left_time")) + "��\n");	
	
}

int modify = 0;

int main(object me, string arg)
{
	int t;
	if (!wizardp(me) || !arg) {
		int GMT = time() + localtime(0)[8] + modify;

		write("�������齣"+ NATURE_D->game_time() + "��\n");
		write("��������Ϸ����������ʱ����" + Ctime(GMT+28800) + "\n");
		write("                Ϥ��ʱ����" + SYDtime(GMT+36000) + "\n");
		write("      �¿����������ʱ����" + NZtime(GMT+43200) + "\n");
		write("      �¸绪����ɼ�ʱ����" + NAtime(GMT-28800) + "\n");
		write("        ���׶ࡢŦԼʱ����" + NAtime(GMT-18000) + "\n");
		write("    ���֡���������ʱ����" + EUtime(GMT+3600) + "\n");
		
		t = me->query_temp("online_time");
		if (t > 0) write("���Ѿ���������"+CHINESE_D->chinese_time(t)+"��\n");
		t = me->query("online_total");
		if (t > 0) write("���������"+CHINESE_D->chinese_time(t)+"��\n");
	
		do_vip(me);
	} else if (arg != "-cond") {
		int i;

		if (sscanf(arg, "%d", i) == 1) {
			modify += i;
			//save();
			write(ctime(time() + localtime(0)[8] + 28800 + modify) + "\n");
			return 1;
		}
		me = LOGIN_D->find_body(arg);
		if (!me) return notify_fail("û�������ҡ�\n");
	}


	return 1;
}

int help(object me)
{
 	write(@HELP
ָ���ʽ: time

���ָ������(��)֪�����ڵ�ʱ����������Ϸ���������ϴι����Чʱ���¼��

HELP
    );
    return 1;
}
