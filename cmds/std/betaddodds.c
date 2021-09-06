#include <ansi.h>
#include <mudlib.h>
  
#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"
  
int main(object me, string arg)
{
	string outstr;
	string betcode,oddsremark;
	int oddscode,odds1,odds2;
	mixed ret;
	int i;
	
	if( !stringp(arg) )
		return notify_fail("��Ҫ����ʲô?\n");

	if ( !wizardp(me) && ( (!me->query("gamblers"))||(me->query("gamblers")!=1) ) )
		return notify_fail("��û�����Ȩ��?\n");

	sscanf( arg, "%s %d %s %d.%d",betcode,oddscode,oddsremark,odds1,odds2);

	if( !stringp(oddsremark) )
		return notify_fail("����˵������Ϊ��?\n");
	
	ret = DOBET_D->leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+betcode+"'");

	if(!ret || sizeof(ret)<1) 
		return notify_fail("û�ҵ��κη��������Ķľ֣��޷��������\n");
	
	while(odds2>=100)
		odds2=odds2/10;
/*	outstr = "��Ҫ������ʵĶľ�����Ϊ��\n";
	for(i=0;i<sizeof(ret);i++)
	{
		outstr+= sprintf("%10s %20s %10s %20s\n",ret[i][0],ret[i][1],DOBET_D->getflag(ret[i][0],ret[i][3],ret[i][8]),
			DOBET_D->getmytime(ret[i][3],ret[i][3],ret[i][4],ret[i][5]));
	};
	outstr += "ԭ�����ʵ�����Ϊ��\n";
	outstr += DOBET_D->getoddsstr(betcode);
	outstr += "��Ҫ�������Ϊ��\n";
*/
	outstr="������"HIW"����Ҫ�����Ķľ�Ϊ��"NOR"��������������������������������������������������������������������\n";
	outstr += "��"HIG"�ľִ��� �ľ�����                       ״̬     �ľֽ��        ��ע                     "NOR"��\n";
	for(i=0;i<sizeof(ret);i++)
	{
		outstr+= sprintf("��"HIW"%-8s"NOR" %-30s %8s "HIC"%-15s"NOR" %-25s��\n",ret[i][0],ret[i][1],
			DOBET_D->getflag(ret[i][3]),
			DOBET_D->getresult(ret[i][0],ret[i][3],ret[i][8]),
			DOBET_D->getmytime(ret[i][3],ret[i][4],ret[i][5],ret[i][6]));
	};
	outstr+="�ǩ�������������������������������������������������������������������������������������������\n";
	outstr += "��ԭ�����ʵ�����Ϊ��                                                                        ��\n";
	outstr+=DOBET_D->getoddsstr(ret[0][0],"��                           ","        ��\n");
	outstr+="�ǩ�������������������������������������������������������������������������������������������\n";
	outstr += "����ƻ���ӵ�����Ϊ��                                                                      ��\n";

	outstr+= sprintf("��                     ��ע����:"HIW"%2i"NOR" ��ע���ݣ�"CYN"%-20s"NOR" ���ʣ�"HIW"%3d.%-2d"NOR"              ��\n",
			oddscode,oddsremark,odds1,odds2);

	outstr += "����������������������������������������������������������������������������������������������\n";
//	outstr += "���棺һ���ľֵ��������ò��ܳ���10��������Ϳ��ܴ�������\n";
	outstr+="���ȷ�����ã�������y:";
	write(outstr);
	input_to("odds_add_yes_no", 1, betcode,oddscode,oddsremark,odds1*100+odds2,me);
	return 1;
}

private void odds_add_yes_no(string yes_no,string valcode, int valodds_id, string valodds_remark, int valodds,object me)
{
	if( (yes_no !="y") && (yes_no !="Y") ){
		write("������˱�����������\n");
		return;
	};
	if( DOBET_D->set_odds(valcode, valodds_id, valodds_remark, valodds) != 1)
		write("������������ʧ��\n");
	else{
		write("�����������óɹ�\n");
		log_file("betlog",sprintf("%s %s����޸Ķľ�%s������%i����Ϊ%s����Ϊ",
			DOBET_D->longtime(time()),
			me->query("id"),valcode,valodds_id,valodds_remark, valodds));
	};
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��betaddodds <�ľִ���> <���ʴ���> <����˵��> <����>
--------------------------------------------------
 betaddodds �ľֵ���������
	�ľִ���
	���ʴ���:��������Ϊ0����Ϊ���ý��ʱ0��ʾ����û���л�ľ�ȡ��,
	����˵����򵥵ľ���1��Ӯ2ƽ3��Ӯ
	���ʣ������������1.8���ص�ʱ�����1.8,�洢Ϊ����*100
���棺һ���ľֵ��������ò��ܳ���10��������Ϳ��ܴ������� 
--------------------------------------------------

HELP
    );
    return 1;
}
