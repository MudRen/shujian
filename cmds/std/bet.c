#include <ansi.h>
#include <mudlib.h>
  
#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"
  
int main(object me, string arg)
{
	string outstr;
	string betcode;
	int oddscode,chip,imaxchip;
	mixed ret;
	mixed op;
	string querystr;
	int i;
	
	if( !stringp(arg) )
		return notify_fail("��ҪͶעʲô?\n");

	sscanf( arg, "%s %d %d",betcode,oddscode,chip);

	if( (chip<0)||(chip==0) )
		return notify_fail("��ע�����������\n");
	if( chip*10000>me->query("balance") )
		return notify_fail("��Ǯׯ��û����ô��Ǯ\n");
		
	ret = DOBET_D->leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark,max_bet from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+betcode+"'");

	if(!ret || sizeof(ret)<1) 
		return notify_fail("û�ҵ��κη��������Ķľ֣��޷���ע\n");
	
	if( ret[0][3]!=1 )
		return notify_fail("��Ҫ����Ķľ����ڲ�������ע���޷���ע\n");
	
	op = DOBET_D->leasedb("select odds_id,odds_remark,odds from "+DB_ODDS_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+betcode+"' AND odds_id='"+oddscode+"'");
	
	if(!op || sizeof(op)<1) 
		return notify_fail("û�ҵ��κη��������Ķľ����ʣ��޷���ע\n");

	querystr=sprintf("bet/%s/%d",betcode,oddscode);
	if( !me->query(querystr) )
		imaxchip=chip;
	else
		imaxchip=me->query(querystr)+chip;

	if( imaxchip>ret[0][10] )
		return notify_fail(sprintf("���ڸ������µ�ע�ۼƲ��ܳ�������%i���ƽ�\n",ret[0][10]));

	outstr="������"HIW"����Ҫ�μӵĶľ�Ϊ��"NOR"��������������������������������������������������������������������\n";
	outstr += "��"HIG"�ľִ��� �ľ�����                       ״̬     �ľֽ��          ��ע                   "NOR"��\n";
	for(i=0;i<sizeof(ret);i++)
	{
		outstr+= sprintf("��"HIW"%-8s"NOR" %-30s %8s "HIC"%-15s"NOR" %-25s��\n",ret[i][0],ret[i][1],
			DOBET_D->getflag(ret[i][3]),
			DOBET_D->getresult(ret[i][0],ret[i][3],ret[i][8]),
			DOBET_D->getmytime(ret[i][3],ret[i][4],ret[i][5],ret[i][6]));
	};
	outstr += "�����ʵ�����Ϊ��                                                                            ��\n";
	outstr+=DOBET_D->getoddsstr(ret[0][0],"��                           ","        ��\n");
	outstr += "����������������������������������������������������������������������������������������������\n";
	outstr += "��Ҫ�µ�עΪ��\n";
	outstr += sprintf("Ͷע����:"HIW"%2i"NOR" ��ע���ݣ�"HIW"%-20s"NOR" ���ʣ�"HIW"%3d.%-2d"NOR" ��ƻ���ע��"HIW"%d���ƽ�"NOR"\n",
			oddscode,op[0][1],op[0][2]/100,op[0][2]%100,chip);

	outstr+=sprintf("���ѹ�У�ׯ�ҽ�������������:%s\n",DOBET_D->money_str(chip*op[0][2]*100));
	outstr+="���ȷ����ע��������y:";
	write(outstr);
	input_to("bet_chip_yes_no", 1, betcode,ret[0][1],oddscode,op[0][1],op[0][2],me->query("id"),chip,me);
	return 1;
}

private void bet_chip_yes_no(string yes_no,string valcode, string valcontext, int valodds_id, string valodds_remark, int valodds,string valchip_id,int valchip, object me)
{
	string querystr;
	int imaxchip;

	if( (yes_no !="y") && (yes_no !="Y") ){
		write("������˱�����ע\n");
		return;
	};

	if( DOBET_D->set_chip(valcode, valchip_id, valodds_id, valodds_remark, valodds, valchip) != 1)
		write("������עʧ��\n");
	else{
		write("������ע�ɹ�,Ͷע���Ѵ����Ǯׯ����п۳�\n");
		me->add("balance",0-valchip*10000);
		querystr=sprintf("bet/%s/%i",valcode,valodds_id);
		if( !me->query(querystr) )
			imaxchip=valchip;
		else
			imaxchip=me->query(querystr)+valchip;
		me->set(querystr,imaxchip);
		log_file("betchiplog",sprintf("%s��[%s]�ľ���ѹע[%s]��ע%d����%d.%d",
			me->query("id"),
			valcontext,
			valodds_remark,
			valchip,
			valodds/100,
			valodds%100));
	};
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��bet <�ľִ���> <���ʴ���> <��ע���>
--------------------------------------------------
 bet ��ע
 ��ע����Զ��ƽ�Ϊ��λ
--------------------------------------------------

HELP
    );
    return 1;
}
