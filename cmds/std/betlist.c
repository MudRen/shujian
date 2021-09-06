#include <ansi.h>
#include <mudlib.h>
#include  <database.h>
  
#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"


int main(object me, string arg)
{
	string outstr;
	string sql,sql2;
	mixed ret;
	int ioddsflag=0;
	int i,ipos;
	
	sql="select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark,max_bet from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"'";
	if( !stringp(arg) ||(arg == "-l") ) {
		if(arg == "-l")
			ioddsflag=1;
//		ret = DOBET_D->leasedb(sql+" AND flag!='10' AND flag!='4'");
		sql+=" AND flag!='10' AND flag!='4'";
	} else {
//		if( arg == "-a" ){
//			ret = DOBET_D->leasedb(sql+");
//		}else{
//			ret = DOBET_D->leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark,max_bet from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+arg+"'");
//			ioddsflag=1;
//		};
		if( arg != "-a" ){
			sql+=" AND code='"+arg+"'";
			ioddsflag=1;
		};
	};

	ret = DOBET_D->leasedb(sql);
	if(!ret || sizeof(ret)<1) 
		return notify_fail("û�ҵ��κη��������Ķľ�\n");

	outstr="������"HIW"���齣����ľ��嵥��"NOR"����������������������������������������������������������������\n";
	outstr += "��"HIG"�ľִ��� �ľ�����                       ״̬     �ľֽ��        ��ע                 "NOR"��\n";
	ipos=0;
	while(sizeof(ret)>0){
		for(i=0;i<sizeof(ret);i++)
		{
			if(ioddsflag == 1)
				outstr+="�ǩ���������������������������������������������������������������������������������������\n";
			outstr+= sprintf("��"HIW"%-8s"NOR" %-30s %8s "HIC"%-15s"NOR" %-21s��\n",
				ret[i][0],
//				ret[i][1]+sprintf("(%d)",ret[i][10]),
				ret[i][1],
				DOBET_D->getflag(ret[i][3]),
				DOBET_D->getresult(ret[i][0],ret[i][3],ret[i][8]),
				DOBET_D->getmytime(ret[i][3],ret[i][4],ret[i][5],ret[i][6]));
			if(ioddsflag == 1)
				outstr+=DOBET_D->getoddsstr(ret[i][0],"��                           ","    ��\n");
		};
		ipos+=sizeof(ret);
		sql2 = sql+sprintf(" LIMIT %d,%d",ipos,ROW_LIMIT);
		ret = DOBET_D->leasedb(sql2);
	};
	outstr += "������������������������������������������������������������������������������������������\n";

//	write(outstr);
	me->start_more(outstr);
	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��betlist
	betlist <�ľִ���>
	betlist -a
	betlist -l
--------------------------------------------------
 betlist ����ǰ���е�ȫ���ľ����
	betlist <�ľִ���> �鿴�öľֻ����������������
	betlist -a �鿴ȫ���ľ֣����ѽ����Ķľ�
	betlist -l �鿴��ǰȫ���ľֻ����������������

--------------------------------------------------

HELP
    );
    return 1;
}
