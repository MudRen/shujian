#include <ansi.h>
#include <mudlib.h>
  
#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"
  
int main(object me, string arg)
{
	string outstr;
	string betcode;
	int oddscode;
	mixed ret;
	mixed op;
	int i;
	
	if( !stringp(arg) )
		return notify_fail("��Ҫ����ʲô?\n");

	//if ( !wizardp(me) && ( (!me->query("gamblers"))||(me->query("gamblers")!=1) ) )
	if ( !wizardp(me) )
		return notify_fail("��û�����Ȩ��?\n");

	sscanf( arg, "%s %d",betcode,oddscode);

	if( oddscode!=0 ){
		op = DOBET_D->leasedb("select odds_id,odds_remark,odds from "+DB_ODDS_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+betcode+"' AND odds_id='"+oddscode+"'");
		if(!op || sizeof(op)<1) 
			return notify_fail("û�ҵ��κη��������Ķľ�����\n");
	};
	
	ret = DOBET_D->leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+betcode+"'");

	if(!ret || sizeof(ret)<1) 
		return notify_fail("û�ҵ��κη��������Ķľ֣��޷�ɾ������\n");

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
	if( oddscode!=0 ){
		outstr+="�ǩ�������������������������������������������������������������������������������������������\n";
		outstr += "���������н�������Ϊ��                                                                      ��\n";
		outstr+= sprintf("��                     ��ע����:"HIW"%2i"NOR" ��ע���ݣ�"CYN"%-20s"NOR" ���ʣ�"HIW"%3d.%-2d"NOR"              ��\n",
			op[0][0],op[0][1],op[0][2]/100,op[0][2]%100);
		outstr += "����������������������������������������������������������������������������������������������\n";
		outstr+=HIW"���ȷ���н����ã�������y:"NOR;
	}else{
		outstr += "����������������������������������������������������������������������������������������������\n";
		outstr += HIR"��ƻ�"HIW"ȡ��"HIR"���ζľ�,���ȷ�ϣ�������y:\n"NOR;
	}
	write(outstr);
	input_to("odds_result_yes_no", 1, betcode,oddscode,me);
	return 1;
}

private void odds_result_yes_no(string yes_no,string valcode, int valodds_id,object me)
{
	string sql;
	
	if( (yes_no !="y") && (yes_no !="Y") ){
		write("������˱���ɾ��\n");
		return;
	};
	sql = "UPDATE "
	+DB_DOBET_NAME+" SET "	
	+"flag='3', "
	+"bet_result='"+valodds_id+ "'"
	+" WHERE code='"+valcode+"' AND U_Site='"+INTERMUD_MUD_NAME+"'";

	if(DOBET_D->leasedb(sql)){
		write("�н����óɹ�\n");
		log_file("betlog",sprintf("%s���öľֽ��Ϊ%i",
			me->query("id"),valodds_id));
	}else
		write("�н�����ʧ��\n");
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��betresult <�ľִ���> <�н������ʴ���>
--------------------------------------------------
 betresult ���öľֵĽ��
����� <�н������ʴ���>����Ϊ0��ʾȡ�����ζľ�
--------------------------------------------------

HELP
    );
    return 1;
}
