#include <ansi.h>
#include <mudlib.h>
  
#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"
  
int main(object me, string arg)
{
	string outstr;
	mixed ret;
	int i;
	
	if( !stringp(arg) )
		return notify_fail("��Ҫɾ��ʲô?\n");

	ret = DOBET_D->leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+arg+"'");

	if(!ret || sizeof(ret)<1) 
		return notify_fail("û�ҵ��κη��������Ķľ�\n");

	outstr="������"HIW"����Ҫɾ���Ķľ�Ϊ��"NOR"��������������������������������������������������������������������\n";
	outstr += "��"HIG"�ľִ��� �ľ�����                       ״̬     �ľֽ��        ��ע                     "NOR"��\n";
	for(i=0;i<sizeof(ret);i++)
	{
		outstr+= sprintf("��"HIW"%-8s"NOR" %-30s %8s "HIC"%-15s"NOR" %-25s��\n",ret[i][0],ret[i][1],
			DOBET_D->getflag(ret[i][3]),
			DOBET_D->getresult(ret[i][0],ret[i][3],ret[i][8]),
			DOBET_D->getmytime(ret[i][3],ret[i][4],ret[i][5],ret[i][6]));
	};
	outstr += "����������������������������������������������������������������������������������������������\n";
	outstr+="���ȷ��ɾ����������y:";
	write(outstr);
	input_to("bet_del_yes_no", 1, arg,me);
	return 1;
}

private void bet_del_yes_no(string yes_no,string valcode,object me)
{
	if( (yes_no !="y") && (yes_no !="Y") ){
		write("������˱���ɾ��\n");
		return;
	};
	if( DOBET_D->delete_bet(valcode) != 1)
		write("����ɾ��ʧ��\n");
	else{
		write("����ɾ���ɹ�\n");
		log_file("betlog",sprintf("%s %sɾ���ľ�%s",
			DOBET_D->longtime(time()),
			me->query("id"),valcode));
	};
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��betdel <�ľִ���>
--------------------------------------------------
 betdel ɾ���ľ�
 
--------------------------------------------------

HELP
    );
    return 1;
}
