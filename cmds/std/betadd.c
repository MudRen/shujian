#include <ansi.h>
#include <mudlib.h>
  
#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"

void end_input_bet(string valcode,string valcontext, string valsetup_id, int valbetmax, 
		int valbegin_time, int valstop_time, int valend_time, int valdeposit, object ob);

int check_legal_code(string valcode)
{
	int i;

	i = strlen(valcode);

	if( i < 1 || i > 6 ) {
		write("�Բ��𣬶ľִ�������� 1 �� 6 ��Ӣ����ĸ�����֡�\n");
		return 0;
	}

	while(i--)
		if( (valcode[i] < 'a' || valcode[i] > 'z') && (valcode[i] < '0' || valcode[i] > '9') ) {
			write("�Բ��𣬶ľִ���ֻ����Ӣ����ĸ�����֡�\n");
			return 0;
		}

	return 1;
}

int getsettime(string valstr)
{
	int iday,ihour,imin,isec;
	int inowtime = time();
	string ts;
	int ioldhour,ioldmin,ioldsec;
	
	ts = ctime(inowtime);
	ts = ts[10..15];
	sscanf( ts, "%d:%d:%d",ioldhour,ioldmin,ioldsec);

	sscanf( valstr, "%d %d:%d:%d",iday,ihour,imin,isec);
	if( iday <0 ) iday=0;
//	if( iday >30 ) iday=30;
	inowtime += iday*3600*24;

	if( ihour<0 ) ihour=0;
	if( ihour>23 ) ihour=23;
	inowtime += (ihour-ioldhour)*3600;

	if( imin<0 ) imin=0;
	if( imin>59 ) imin=59;
	inowtime += (imin-ioldmin)*60;

	if( isec<0 ) isec=0;
	if( isec>59 ) isec=59;
	inowtime += isec-ioldsec;
	return inowtime;
}
  
int main(object me, string arg)
{
	if ( !wizardp(me) && ( (!me->query("gamblers"))||(me->query("gamblers")!=1) ) )
		return notify_fail("��û�����Ȩ��?\n");

	write("����������Ϊ���ζľ����õĴ��룬ע�������ϵͳ���ִ���ظ������Ḳ��ԭ����\n����Ϊ��");
	input_to("get_code", 1, me);
	return 1;
}

private void get_code(string valcode, object ob)
{
	mixed ret;
	
	ret = DOBET_D->leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark,max_bet from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"'");
	if(check_legal_code(valcode)==0){
		write("�ľִ���Ϊ��");
		input_to("get_code", 1, ob);
	};
	
	if(!ret || sizeof(ret)<1){
		write("������ľֵ����ݣ��س���ʾ������");
		input_to("get_context1", 1,valcode, ob );
	}else{
		write("����Ϊ:"HIW+valcode+NOR"�Ѿ����ڡ�\nԭ�趨�Ķľֵ����ݣ�"HIW+ret[0][1]+NOR"\n");
		write("ԭ�ľֵ�״̬Ϊ��"+DOBET_D->getflag(ret[0][3])+"\n");
		write("������ľֵ������ݣ��س���ʾ���޸ģ�");
		input_to("get_context2", 1,valcode,ret[0][1],ret[0][10],
			ret[0][4],ret[0][5],ret[0][6], ob );
	}
}

private void get_context1(string valcontext, string valcode, object ob)
{
	if( !stringp(valcontext)||(valcontext=="") ){
		write("�����������\n");
	}else{
		write("������ľֵ�����һ��id���Ͷע���Զ��ƽ�Ϊ��λ\n");
		write("�س���ʾ������");
		input_to("get_betmax1", 1,valcode, valcontext,ob );
	}
}

private void get_context2(string valcontext,string valcode, string oldvalcontext, int valbetmax, 
	int valbegin_time, int valstop_time, int valend_time, object ob)
{
	if( !stringp(valcontext)||(valcontext=="") )
		valcontext=oldvalcontext;

	write(sprintf("ԭ�ľֵ����Ͷע����ǣ�"HIW"%d���ƽ�\n"NOR,valbetmax));
	write("������ľֵ�����һ��id���Ͷע���Զ��ƽ�Ϊ��λ\n");
	write("�س���ʾ���޸ģ�");
	input_to("get_betmax2", 1,valcode,valcontext,valbetmax,
			valbegin_time, valstop_time, valend_time , ob );
}

private void get_betmax1(string valbetmax, string valcode, string valcontext,object ob)
{
	int ibetmax;
	
	if( !stringp(valbetmax)||(valbetmax=="") ){
		write("�����������\n");
	}else{
		sscanf( valbetmax, "%d",ibetmax);
		if(ibetmax<=0){
			write("���Ͷע����С����\n");
			write("������ľֵ�����һ��id���Ͷע���Զ��ƽ�Ϊ��λ\n");
			write("�س���ʾ������");
			input_to("get_betmax1", 1,valcode, valcontext,ob );
		};
		write(sprintf("����������Ͷע���Ϊ��"HIW"%d���ƽ�\n"NOR,ibetmax));
		write("������ľֵ�����ʼͶעʱ�䣬����ʾ��Ϊ 4 12:00:00,��ʾ����������12����\n");
		write("�س���ʾ������");
		input_to("get_begintime1", 1,valcode, valcontext,ibetmax,ob );
	}
}

private void get_betmax2(string valbetmax, string valcode, string valcontext, int valoldbetmax, 
	int valbegin_time, int valstop_time, int valend_time, object ob)
{
	int ibetmax;
	
	if( !stringp(valbetmax)||(valbetmax=="") )
		ibetmax=valoldbetmax;
	else{
		sscanf( valbetmax, "%d",ibetmax);
		if(ibetmax<=0){
			write("���Ͷע����С����\n");
			write("������ľֵ�����һ��id���Ͷע���Զ��ƽ�Ϊ��λ\n");
			write("�س���ʾ������");
			input_to("get_betmax2", 1,valcode,valcontext,
					valbegin_time, valstop_time, valend_time , ob );
		};
	};
	write(sprintf("����������Ͷע���Ϊ��"HIW"%d���ƽ�\n"NOR,ibetmax));
	write("ԭ�ľֵĿ�ʼͶעʱ���ǣ�"HIW+DOBET_D->longtime(valbegin_time)+NOR"\n");
	write("������ľֵ�����ʼͶעʱ�䣬����ʾ��Ϊ 4 12:00:00,��ʾ����������12����\n");
	write("�س���ʾ���޸ģ�");
	input_to("get_begintime2", 1,valcode,valcontext,ibetmax,
			valbegin_time, valstop_time, valend_time , ob );
}

private void get_begintime1(string valbegin_time,string valcode, string valcontext, int valbetmax, object ob)
{
	int ibegin_time;
	
	if( !stringp(valbegin_time) ){
		write("�����������\n");
	}else{
		ibegin_time=getsettime(valbegin_time);
		write("�����õĿ�ʼͶעʱ���ǣ�"HIW+DOBET_D->longtime(ibegin_time)+NOR"\n");
		write("������ľֵ�Ͷע��ֹʱ�䣬����ʾ��Ϊ 4 12:00:00,��ʾ����������12����\n");
		write("�س���ʾ������");
		input_to("get_stoptime1", 1,valcode,valcontext,valbetmax,ibegin_time, ob );
	}
}

private void get_begintime2(string valbegin_time,string valcode, string valcontext, int valbetmax, 
	int oldvalbegin_time, int valstop_time, int valend_time, object ob)
{
	int ibegin_time;
	
	if( !stringp(valbegin_time)||(valbegin_time=="") )
		ibegin_time=oldvalbegin_time;
	else
		ibegin_time=getsettime(valbegin_time);

	write("�����õĿ�ʼͶעʱ���ǣ�"HIW+DOBET_D->longtime(ibegin_time)+NOR"\n");
	write("ԭ�ľֵ�Ͷע��ֹʱ���ǣ�"HIW+DOBET_D->longtime(valstop_time)+NOR"\n");
	write("������ľֵ�Ͷע��ֹʱ�䣬����ʾ��Ϊ 4 12:00:00,��ʾ����������12����\n");
	write("�س���ʾ���޸ģ�");
	input_to("get_stoptime2", 1,valcode,valcontext,valbetmax,
			ibegin_time, valstop_time, valend_time, ob );
}

private void get_stoptime1(string valstop_time,string valcode, string valcontext,  int valbetmax, 
		int ibegin_time, object ob)
{
	int istop_time;

	if( !stringp(valstop_time)||(valstop_time=="") ){
		write("�����������\n");
	}else{
		istop_time=getsettime(valstop_time);
		write("�����õ�Ͷע��ֹʱ���ǣ�"HIW+DOBET_D->longtime(istop_time)+NOR"\n");
		write("������ľֵ��ɲ�ʱ�䣬����ʾ��Ϊ 4 12:00:00,��ʾ����������12����\n");
		write("�س���ʾ������");
		input_to("get_endtime1", 1,valcode,valcontext,valbetmax,ibegin_time,istop_time, ob );
	}
}

private void get_stoptime2(string valstop_time,string valcode, string valcontext,  int valbetmax, 
	int valbegin_time, int oldvalstop_time, int valend_time,object ob)
{
	int istop_time;
	
	if( !stringp(valstop_time)||(valstop_time=="") )
		istop_time=oldvalstop_time;
	else
		istop_time=getsettime(valstop_time);
	
	write("�����õ�Ͷע��ֹʱ���ǣ�"HIW+DOBET_D->longtime(istop_time)+NOR"\n");
	write("ԭ�ľֵ��ɲ�ʱ���ǣ�"HIW+DOBET_D->longtime(valend_time)+NOR"\n");
	write("������ľֵ��ɲ�ʱ�䣬����ʾ��Ϊ 4 12:00:00,��ʾ����������12����\n");
	write("�س���ʾ���޸ģ�");
	input_to("get_endtime2", 1,valcode,valcontext,valbetmax,
			valbegin_time, istop_time, valend_time, ob );
}

private void get_endtime1(string valend_time,string valcode, string valcontext,  int valbetmax, 
		int ibegin_time, int istop_time, object ob)
{
	int iend_time;
	
	if( !stringp(valend_time)||(valend_time=="") ){
		write("�����������\n");
	}else{
		iend_time=getsettime(valend_time);
		write("�����õ��ɲ�ʱ���ǣ�"HIW+DOBET_D->longtime(iend_time)+NOR"\n");

		if( wizardp(ob)||( (ob->query("gamblers"))&&(ob->query("gamblers")==1) ) ){
			end_input_bet(valcode,valcontext, ob->query("id"),valbetmax,
				ibegin_time, istop_time, iend_time, 0,ob);
		}else{
			write("��������Ϊ��֯��ζľּƻ�֧����Ѻ���Զ��ƽ�Ϊ��λ���س���ʾ������");
			input_to("get_deposit", 1,valcode,valcontext,valbetmax,ibegin_time,istop_time,iend_time, ob );
		};
	}
}

private void get_endtime2(string valend_time, string valcode,string valcontext, int valbetmax, 
	int valbegin_time, int valstop_time, int oldvalend_time,object ob)
{
	int iend_time;
	
	if( !stringp(valend_time)||(valend_time=="") )
		iend_time=oldvalend_time;
	else
		iend_time=getsettime(valend_time);

	write("�����õ��ɲ�ʱ���ǣ�"HIW+DOBET_D->longtime(iend_time)+NOR"\n");

	end_input_bet(valcode,valcontext, "*",valbetmax,
		valbegin_time, valstop_time, iend_time, 0,ob);
}

private void get_deposit(string valgold,string valcode, string valcontext,  int valbetmax, 
		int ibegin_time, int istop_time, int iend_time, object ob)
{
	int igold;
	
	if( !stringp(valgold)||(valgold=="") ){
		write("�����������\n");
	}else{
		sscanf( valgold, "%d",igold);
		if(igold<100){
			write("�����õ�Ҫ֧����Ѻ�����100���ƽ����������룬�س���ʾ������");
			input_to("get_deposit", 1,valcode,valcontext,valbetmax,ibegin_time,istop_time,iend_time, ob );
		};
		write(sprintf("�����õ�Ҫ֧����Ѻ���ǣ�%d���ƽ�\n",igold));

		end_input_bet(valcode,valcontext, ob->query("id"),valbetmax,
				ibegin_time, istop_time, iend_time, igold,ob);
	}
}

void end_input_bet(string valcode,string valcontext, string valsetup_id, int valbetmax, 
		int valbegin_time, int valstop_time, int valend_time, int valdeposit, object ob)
{
	if( valsetup_id!="*" ){
		write("�㱾�ζľֵ���������\n");
		write(sprintf("���룺"HIW"%s"NOR"\n",valcode));
		write(sprintf("���ݣ�"HIW"%s"NOR"\n",valcontext));
		write(sprintf("���Ͷע��"HIW"%d���ƽ�"NOR"\n",valbetmax));
		write(sprintf("��ʼͶעʱ�䣺"HIW"%s"NOR"\n",DOBET_D->longtime(valbegin_time)));
		write(sprintf("Ͷע��ֹʱ�䣺"HIW"%s"NOR"\n",DOBET_D->longtime(valstop_time)));
		write(sprintf("�ɲ�ʱ�䣺"HIW"%s"NOR"\n",DOBET_D->longtime(valend_time)));
		write(sprintf("Ѻ��"HIW"%d���ƽ�"NOR"\n",valdeposit));
		write("ȷ��������y������ȡ���������ã�");
	}else{
		write("��Ա��ζľ��������޸�\n");
		write(sprintf("���ݣ�"HIW"%s"NOR"\n",valcontext));
		write(sprintf("���Ͷע��"HIW"%d���ƽ�"NOR"\n",valbetmax));
		write(sprintf("��ʼͶעʱ�䣺"HIW"%s"NOR"\n",DOBET_D->longtime(valbegin_time)));
		write(sprintf("Ͷע��ֹʱ�䣺"HIW"%s"NOR"\n",DOBET_D->longtime(valstop_time)));
		write(sprintf("�ɲ�ʱ�䣺"HIW"%s"NOR"\n",DOBET_D->longtime(valend_time)));
		write("ȷ��������y������ȡ���������ã�");
	};
	input_to("bet_set_yes_no", 1,valcode,valcontext, valsetup_id,valbetmax,
		valbegin_time, valstop_time, valend_time, valdeposit,ob);
}

private void bet_set_yes_no(string yes_no,string valcode,string valcontext, string valsetup_id, int valbetmax, 
		int valbegin_time, int valstop_time, int valend_time, int valdeposit,object me)
{
	if( (yes_no !="y") && (yes_no !="Y") ){
		write("�����������\n");
		return;
	};
	if( DOBET_D->set_bet(valcode,valcontext, valsetup_id,valbetmax,
		valbegin_time, valstop_time, valend_time, valdeposit) != 1)
		write("��������ʧ��\n");
	else{
		write("�������óɹ�\n");
		write("��ʹ��"HIW"betaddodds "+valcode+" <��ע����> <����˵��> <����> "NOR"����ӻ��޸ı��ζľֵ�����\n");
		log_file("betlog",sprintf("%s%s�ľ�%s����%s ���Ͷע%d %s %s %s Ѻ��%i ",
			me->query("id"),
			((valsetup_id=="*")?"�޸�":"����"),
			valcode,valcontext,valbetmax,
			DOBET_D->longtime(valbegin_time),
			DOBET_D->longtime(valstop_time),
			DOBET_D->longtime(valend_time),
			valdeposit));
	};
}
int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��betadd
--------------------------------------------------
 betadd ���öľֻ��޸�
 �޸���ǰ�Ķľ֣�ֻ���޸�
�ľ����ݣ���˭��˭
��ʼʱ��
��ֹʱ��
�ɲ�ʱ��,Ҳ�Ǳ��ľֵĽ���ʱ��
--------------------------------------------------

HELP
    );
    return 1;
}
