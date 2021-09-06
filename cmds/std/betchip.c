#include <ansi.h>
#include <mudlib.h>
#include  <database.h>

#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"

string getchipflag(int valflag,int valodds_id,int valbet_result)
{
//	0����1��ʼͶע2Ͷע��ֹ3�������4�ɲʽ���10��ͣʹ��
	switch(valflag){
		case 0:
			return MAG"  ";
		case 1:
//			return HIG"  ";
			return GRN"  ";
			
		case 2:
//			return HIB"  ";
			return CYN"��";
			
		case 3:
			if( valbet_result == 0 )
				return YEL"��";
			if( valodds_id == valbet_result )
				return BWHT""HIC"Ӯ"HIR""HIC;
			else
				return YEL"��";
		case 4:
			if( valbet_result == 0 )
				return YEL"��";
			if( valodds_id == valbet_result )
				return BWHT""HIR"Ӯ"NOR""HIR;
			else
				return YEL"��";
		case 10:
			return HIR"ͣ";
		};
	return HIR"??";
}

int main(object me, string arg)
{
	string outstr,*option,querycode;
	string sql,sql2;
	int ipos;
	int opt_all;
	mixed ret;
	int i;

	sql = "select "+DB_CHIP_NAME+".code,"+DB_DOBET_NAME+".context,"+DB_CHIP_NAME+".chip_id,"+DB_CHIP_NAME+".odds_remark,"
		+DB_CHIP_NAME+".odds_id,"+DB_CHIP_NAME+".odds,"+DB_CHIP_NAME+".chip,"+DB_CHIP_NAME+".chip_time,"
		+DB_DOBET_NAME+".flag,"+DB_DOBET_NAME+".bet_result from "
		+DB_CHIP_NAME+","+DB_DOBET_NAME
		+" where "+DB_CHIP_NAME+".U_Site='"+INTERMUD_MUD_NAME+"' and "+DB_CHIP_NAME+".code="+DB_DOBET_NAME+".code";
	if( !stringp(arg) ) {
		sql += " AND "+DB_CHIP_NAME+".chip_id='"+me->query("id")+"'";
	} else {
		opt_all=0;
		option = explode(arg, " ");
		option -= ({ "" });
		i = sizeof(option);
		querycode="";
		while( i-- )
			if(option[i]=="-a") 
				opt_all=1;
			else
				querycode = option[i];
/*				
�����ô�Ҷ����Կ����˵�Ͷע
		if( (opt_all==1) && (!wizardp(me) )
			return notify_fail("ֻ����ʦ�ܲ쿴ȫ���˵�Ͷע�����\n");
*/				
		if( opt_all!=1 )
			sql +=" AND "+DB_CHIP_NAME+".chip_id='"+me->query("id")+"'";
		if( querycode!="" )
			sql +=" AND "+DB_CHIP_NAME+".code='"+querycode+"'";
	};

	sql+=" order by "+DB_DOBET_NAME+".flag,"+DB_CHIP_NAME+".chip_id,"+DB_CHIP_NAME+".odds_id,"+DB_CHIP_NAME+".code ";
	ret = DOBET_D->leasedb(sql);
	if(!ret || sizeof(ret)<1) 
		return notify_fail("û�ҵ��κ���ע��¼\n");

	outstr="������"HIW"���齣�ľ���ע��¼��"NOR"����������������������������������������������������������������\n";
	outstr += "��"HIG"   �ľ�����                     Ͷע��   ��ע����         ����      ��ע   ��עʱ��   "NOR"��\n";
	outstr+="�ǩ���������������������������������������������������������������������������������������\n";
	ipos=0;
	while(sizeof(ret)>0){
		for(i=0;i<sizeof(ret);i++)
		{
			outstr+= sprintf("��%2s %-28s %-8s %-16s %3d.%-2d %6d�� %s"NOR"��\n",
				getchipflag(ret[i][8],ret[i][4],ret[i][9]),ret[i][1],ret[i][2],ret[i][3],
				ret[i][5]/100,ret[i][5]%100,ret[i][6],DOBET_D->shorttime(ret[i][7]));
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
ָ���ʽ��betchip
	betchip <�ľִ���>
	betchip -a 
	betchip <�ľִ���> -a 
--------------------------------------------------
 betchip ���Լ���ע�����
 betchip <�ľִ���> ���Լ���ĳ���ľ��е���ע���
 betchip -a  ��ȫ�������ע�����
 betchip <�ľִ���> -a ��ȫ�������ĳ���ľ��е���ע���
--------------------------------------------------

HELP
    );
    return 1;
}
