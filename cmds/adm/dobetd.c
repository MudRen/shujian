/**********************************************************************************
//
//      dobetd.c
//      Created by mychat 12/05/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/adm/deamons��
// 		����ľֵĽ���

-- �ľ����ÿ�
if(select count(*) from sysobjects where name = 'dobet_main') > 0
  drop table dobet_main
go
�����Ǽ����Ͷע������Ͷע�ûʲô����ɣ����鷳
create table dobet_main
(
	U_Site  char(10)		not null,	--վ��
	code	char(10)		not null,	--�ľִ���
	context	char(80)		not null,	--�ľ����ݣ���˭��˭
	setup_id		char(8)			not null , -- �ľ�������
	flag			int			not null , -- ״̬0����1��ʼͶע2Ͷע��ֹ3�������4�ɲʽ���10��ͣʹ��
	begin_time		int			not null , -- ��ʼʱ��
	stop_time		int			not null , -- ��ֹʱ��
	end_time		int		not null , -- �ɲ�ʱ��,Ҳ�Ǳ��ľֵĽ���ʱ��
	deposit 		int		not null , -- ���Ѻ����wiz�����Ϊ0��
	bet_result		int		not null , -- �ľֽ������Ӧdobet_odds�е�odds_id,����0��ʾȡ��,-1��ʾ���޽��
	remark			varchar(100), -- �ľֱ䶯��¼	--�Ժ�����
)
go
-- �ľ����ʿ�
if(select count(*) from sysobjects where name = 'dobet_odds') > 0
  drop table dobet_odds
go
create table dobet_odds
(
	U_Site  char(10)		not null,	--վ��
	code	char(10)		not null,	--�ľִ���
	odds_id	int		not null,	--���ʴ���:��������Ϊ0����Ϊ���ý��ʱ0��ʾ����û���л�ľ�ȡ��,
	odds_remark	char(20)		not null,	--����˵����򵥵ľ���1��Ӯ2ƽ3��Ӯ
	odds		int			not null , -- ���ʣ��������������0.8���ص�ʱ�����1.8,�洢Ϊ����*100
)
go
-- �ľ���ע��
if(select count(*) from sysobjects where name = 'dobet_chip') > 0
  drop table dobet_chip
go
create table dobet_chip
(
	U_Site  char(10)		not null,	--վ��
	code	char(10)		not null,	--�ľִ���
	context	char(80)		not null,	--�ľ����ݣ���˭��˭;�����ֶΣ������������
	chip_id	char(8)		not null,	--Ͷע��id
	odds_remark	char(20)		not null,	--����˵����򵥵ľ���1��Ӯ2ƽ3��Ӯ;�����ֶΣ������������
	odds_id	int			not null , -- ���ʴ���
	odds	int			not null , -- ��ע���ʣ���Ϊ�ľֵ����ʿ����ڱ䣬���Լ�¼��עʱ������,�洢Ϊ����*100
	chip	int			not null , -- Ͷע��
	chip_time	int			not null , -- ��עʱ��
)
go
http://shaer.mymud.com/bbs/showthread.php?threadid=24238
��ע��
ֻҪ�ľ�û�н������������κ�ʱ�̶�����������ʱ��flag�Զ���Ϊ3
***********************************************************************************/
#include <ansi.h>
#include <mudlib.h>

void init_dobet();
void do_dobet();
void check_dobet();

int delete_odds(string valcode, int valodds_id);
int delete_chip(string valcode);

mixed leasedb(string sql);
void pay_all(string valcode,string valcontext, int bet_result);
string money_str(int amount);
int givemoney(string valuserid,int money,string valreason);
string Ctime(string ts);

int ilaststatistic;
int iifstop;

int iifpublicrepay=1;

#define DB_DOBET_NAME "dobet_main"
#define DB_ODDS_NAME "dobet_odds"
#define DB_CHIP_NAME "dobet_chip"


#define MSG_CMDS "/cmds/std/msg"
//#define MYLOG_TIME 600
#define MYLOG_TIME 30


string longtime(int t)
{
	string ts = ctime(t);
	ts = " "+ts[19..23]+"��"+ts[4..6]+ts[8..9]+ts[10..15];
	return Ctime(ts);
}

string shorttime(int t)
{
	string ts = ctime(t);
	ts = ts[4..6]+ts[8..9]+ts[10..15];
	return Ctime(ts);
}

string Ctime(string ts)
{

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

int set_bet(string valcode,string valcontext, string valsetup_id,
		int valbegin_time, int valstop_time, int valend_time, int valdeposit)
{
	string sql;
	mixed ret = leasedb("select code from "+DB_DOBET_NAME+" WHERE code='"+valcode+"' AND U_Site='"+INTERMUD_MUD_NAME+"'");
	if(!ret) return 0;
	if(sizeof(ret)>1)
	{
		error("db error!");
		return 0;
	}
	//���������ľ֣����޸���,���򴴽�
	if(sizeof(ret)>0)
	sql = "UPDATE "
	+DB_DOBET_NAME+" SET "	
	+"context='"+valcontext+ "',"
	+"begin_time='"+valbegin_time+ "',"
	+"stop_time='"+valstop_time+ "',"
	+"end_time='"+valend_time+ "'"
	+" WHERE code='"+valcode+"' AND U_Site='"+INTERMUD_MUD_NAME+"'";
	else sql = "REPLACE "+DB_DOBET_NAME+" SET "
	+"U_Site='" + INTERMUD_MUD_NAME + "',"
	+"flag='0',"
	+"code='"+valcode+ "',"
	+"context='"+valcontext+ "',"
	+"setup_id='"+valsetup_id+ "',"
	+"begin_time='"+valbegin_time+ "',"
	+"stop_time='"+valstop_time+ "',"
	+"end_time='"+valend_time+ "',"
	+"bet_result='-1',"
	+"deposit='"+valdeposit+ "'";

	if(leasedb(sql)) return 1;
	return 0;
}

int delete_bet(string valcode)
{
	//string* room;
	//object r;
	//����ľ�û�н����Ͳ���ɾ��
	mixed ret = leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"'");

	if(!ret || sizeof(ret)<1) 
		return 0;

	if(sizeof(ret)>1)
	{
		error("db error!");
		return 0;
	}
	if( ret[0][3] != 4 ){
		write("�ľ�û����ǰ����ɾ��!\n�����޸Ķľֽ���ʱ�䣬Ȼ��ȴ���־������ɾ,�Ա���Ͷע�ߵ�Ǯ\n");
		return 0;
	};
//��ɾ��Ͷע��¼
	delete_chip(valcode);
//Ȼ��ɾ��Ͷעѡ��
	delete_odds(valcode,-1);
//Ȼ��ɾ���ľ�
	if(!leasedb("DELETE FROM "+DB_DOBET_NAME+" WHERE code='"+valcode+"' AND U_Site='"+INTERMUD_MUD_NAME+"'"))
		return 0;
	write("ɾ���ľֳɹ���\n");
	return 1;
}

int set_odds(string valcode, int valodds_id, string valodds_remark, int valodds)
{
	string sql;
	mixed ret = leasedb("select code,odds_id  from "+DB_ODDS_NAME+" WHERE code='"+valcode+"' AND odds_id='"+valodds_id+"' AND U_Site='"+INTERMUD_MUD_NAME+"'");
	if(!ret) return 0;
	if(sizeof(ret)>1)
	{
		error("db error!");
		return 0;
	}
	if( (valodds_id == -1)||(valodds_id == 0) ){
		write("�ľ�ѡ����벻��Ϊ0��-1,�����ڲ�רҵ����\n");
		return 0;
	};
	//��������Ͷעѡ����޸���,���򴴽�
	if(sizeof(ret)>0)
	sql = "UPDATE "+DB_ODDS_NAME+" SET "	
	+"odds_remark='"+valodds_remark+ "',"
	+"odds='"+valodds+ "'"
	+" WHERE code='"+valcode+"' AND odds_id='"+valodds_id+"' AND U_Site='"+INTERMUD_MUD_NAME+"'";
	else sql = "REPLACE "+DB_ODDS_NAME+" SET "
	+"U_Site='" + INTERMUD_MUD_NAME + "',"
	+"code='"+valcode+ "',"
	+"odds_id='"+valodds_id+ "',"
	+"odds_remark='"+valodds_remark+ "',"
	+"odds='"+valodds+ "'";
	if(leasedb(sql)) return 1;
	return 0;
}

//���valodds_id=-1��ʾ�öľֵ�ȫ��ѡ�ɾ��
int delete_odds(string valcode, int valodds_id)
{
	if( valodds_id == -1 ){
		if(!leasedb("DELETE FROM "+DB_ODDS_NAME+" WHERE code='"+valcode+"' AND U_Site='"+INTERMUD_MUD_NAME+"'"))
			return 0;
	}else{
		if(!leasedb("DELETE FROM "+DB_ODDS_NAME+" WHERE code='"+valcode+"' AND odds_id='"+valodds_id+"' AND U_Site='"+INTERMUD_MUD_NAME+"'"))
			return 0;
	};
	write("ɾ��Ͷעѡ��ɹ���\n");
	return 1;
}

//��ע�¾Ͳ����޸�
int set_chip(string valcode, string valcontext, string valchip_id, int valodds_id, string valodds_remark, int valodds, int valchip)
{
	string sql;
	sql = "REPLACE "+DB_CHIP_NAME+" SET code='" + valcode + "',"
	+"context='" + valcontext + "',"
	+"U_Site='" + INTERMUD_MUD_NAME + "',"
	+"chip_id='"+valchip_id+ "',"
	+"odds_id='"+valodds_id+ "',"
	+"odds_remark='"+valodds_remark+ "',"
	+"odds='"+valodds+ "',"
	+"chip='"+valchip+ "',"
	+"chip_time='"+time()+"'";
	if(leasedb(sql)) return 1;
	return 0;
}

//ɾ��Ͷע��¼ֻ���������ľֱ�ɾ��ʱ���ã����ԾͲ��жϱ����
int delete_chip(string valcode)
{
	if(!leasedb("DELETE FROM "+DB_CHIP_NAME+" WHERE code='"+valcode+"' AND U_Site='"+INTERMUD_MUD_NAME+"'"))
		return 0;
	write("ɾ��Ͷע��¼�ɹ���\n");
	return 1;
}

//���ֲ�
//��ľ�
//��Ͷע�˲�

//���ý��
//����Ͷע

int start_dobet()
{
	if(!iifstop) return 0;
	call_out("do_dobet", 2);
	iifstop=0;
	return 1;
}

void create()
{
	seteuid(getuid());

	init_dobet();
	iifstop=0;
}

void remove()
{
}

void init_dobet()
{
	call_out("do_dobet", MYLOG_TIME);
}

void do_dobet()
{
	//���ľ�����
	check_dobet();

	remove_call_out("do_dobet");
	if(!iifstop)
		call_out("do_dobet", MYLOG_TIME);
}

void stop_dobet()
{
	iifstop=1;
	remove_call_out("do_dobet");
}

void check_dobet()
{
	int i,ichangflag,inewval;
	string csoutstr;
	int inowtime = time();
	mixed op;		
	mixed ret = leasedb("select code,context,setup_id,flag,begin_time,stop_time,end_time,deposit,bet_result,remark from "+DB_DOBET_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND flag!='10' AND flag!='4'");
	if(!ret || !sizeof(ret)) return;
	
	if(iifstop==1) return;
	
	for(i=0;i<sizeof(ret);i++)
	{
		ichangflag=0;
		op = ret[i];
		//flag==0 and begin_time<inowtime
		if( (op[3] == 0) && (op[4]<inowtime) ){
			//��״̬��Ϊ��ʼͶע
			inewval=1;
			ichangflag=1;
		};

		//flag<2 and stop_time<inowtime
		if( op[3] < 2 && op[5]<inowtime){
			//��״̬��ΪֹͣͶע
			inewval=2;
			ichangflag=1;
		};
		
		//ֻ�н���Ѿ������ˣ����ܽ��ɲ�flag==3 and end_time<inowtime
		if( op[3] == 3 && op[8] != -1 && op[6]<inowtime){
			//��״̬��ΪֹͣͶע
			inewval=4;
			pay_all(op[0],op[1],op[8]);
			ichangflag=1;
		};
		
		if( ichangflag==1 ){
			if(!leasedb("UPDATE "+DB_DOBET_NAME+" SET "
				+"flag='"+inewval+ "'"
				+" WHERE code='" + op[0] + "' AND U_Site='" + INTERMUD_MUD_NAME + "'"))
				log_file("dobetlog","check_dobet�ϲ����ݿ����ʧ�ܡ�");
			if(inewval==1)
				csoutstr=HIY"��"
					+op[1]
					+"�����Կ�ʼ��ע�ˣ����λӻԾ����\n"NOR;
			else if(inewval==2)
				csoutstr=HIY"��"
					+op[1]
					+"������ֹͣ��ע�����λ�ȴ��������\n"NOR;
			else if(inewval==4)
				csoutstr=HIY"��"
					+op[1]
					+"�����ڿ�ʼ�ɲ��ˣ����Ͷע��ע����Ϣ\n"NOR;
			else 
				csoutstr=HIY"��"
					+op[1]
					+"�������ˣ�"
					+inewval
					+"��wizע����Ϣ\n"NOR;
			message("channel:chat", 
				HIW"\n���ľ���Ϣ��"HIY
				+csoutstr,
				users());
		};
	}
	return;
}

//����ҷ��ɲɽ�,bet_result==0��ʱ�����˻�ԭ���ĳ���
void pay_all(string valcode,string valcontext, int bet_result)
{
	//int i,ichangflag;
	int i,itotalwin,itotallost;
	//int inowtime = time();
	string result_context;
	string logstr;
	mixed op;
	mixed ret = leasedb("select chip_id,odds_id,odds_remark,odds,chip from "+DB_CHIP_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"'");
	
	if(!ret || !sizeof(ret)) return;
	
	if(iifstop==1) return;
	
	if( bet_result!=0 ){
		op = leasedb("select odds_remark from "+DB_ODDS_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"' AND odds_id='"+bet_result+"'");
		if(!op || sizeof(op)<1){
			log_file("dobetlog","�����ˣ�"+valcode+"�ɲ�ʱ�Ҳ���"+bet_result+"��");
			return;
		};
		result_context=op[0][0];
	};
	for(i=0;i<sizeof(ret);i++)
	{
		if( bet_result==0 ){
			itotallost+=ret[0][4]*10000;
			givemoney(ret[0][0],ret[0][4]*10000,
				HIY"��"+valcontext+"���Ķľ��Ѿ���ȡ���ˣ���ԭ���µ�Ͷע"
				+money_str(ret[0][4])
				+"���˻���Ĵ������\n"NOR);
		}else{
			if( ret[0][1] == bet_result ){
				itotalwin+=ret[0][4]*10000+(ret[0][4]*ret[0][3]*100);
				givemoney(ret[0][0],ret[0][4]*10000+(ret[0][4]*ret[0][3]*100),
					HIY"��"+valcontext+"���ĶľֵĽ����"
					+result_context
					+"��ϲ���н��ˣ�����ԭͶע��"
					+money_str(ret[0][4]*10000+(ret[0][4]*ret[0][3]*100))
					+"�ѹ��͵����Ǯׯ�������\n"NOR);
			}else{
				itotallost+=ret[0][4]*10000;
				givemoney(ret[0][0],0,
					HIY"��"+valcontext+"���ĶľֵĽ����"
					+result_context
					+"����ϧ��û�в���\n"NOR);
			};
		};
	};
	if( bet_result!=0 )
		logstr=sprintf("����ʽ�%s,û�н�����ʧ��ע��Ϊ:%s",money_str(itotalwin),money_str(itotallost));
	else
		logstr=sprintf("���˻زʽ�%s",money_str(itotallost));

	log_file("betlog",sprintf("%s �ľ��ɲʣ�%s",
			longtime(time()),
			logstr));
}

mixed leasedb(string sql)
{
	mixed ret = dbquery(sql);	
	if(!ret){
		error("roomlease db error!"+sql);
		return 0;
	}
	return ret;	
}

string money_str(int amount)
{
	// returns a chinese string of `amount` of money
	string output;
		
	if(amount==0)
		return "��������";

	if (amount / 10000) {
		output = chinese_number(amount / 10000) + "���ƽ�";
		amount %= 10000;
	}
	else
		output = "";
	if (amount / 100) {
		output = output + chinese_number(amount / 100) + "������";
		amount %= 100;
	}
	if (amount)
		return output + chinese_number(amount) + "��ͭǮ";
	return output;
}

int givemoney(string valuserid,int money,string valreason)
{
	object body,ob;

	if(objectp(body = LOGIN_D->find_body(valuserid))) {
		body->add("balance",money);
		if( money!=0 )
			valreason += sprintf(HIY"���ڵĴ�����Ϊ%s\n"NOR,
				money_str(body->query("balance")));
		tell_object(body, valreason);
//		destruct(body);
	}else{
		ob = new(LOGIN_OB);
		ob->set("id", valuserid);
		
		if( !ob->restore() ) {destruct(ob); return 1;}
		body = LOGIN_D->make_body(ob);
		if( body->restore() ) {
			body->add("balance",money);
			if( money!=0 )
				valreason += sprintf(HIY"���ڵĴ�����Ϊ%s\n"NOR,
					money_str(body->query("balance")));
			//if( !body->query("leasemsg") )
			//	body->set("leasemsg","");
			valreason = sprintf(HIW"�������ڼ���Ϣ��"HIY"�������ߺ���%sϵͳ֪ͨ��\n",
				 longtime(time()))+valreason;
			//body->set( "leasemsg",
			//	((!body->query("leasemsg"))?valreason:body->query("leasemsg")+valreason) );
			MSG_CMDS->system_send(this_object(),({valuserid}),"�ľ���Ϣ",valreason);
			//add
			body->set_temp("db_quit",1);
			body->save();
		}
		destruct(ob);
		destruct(body);
	}
	return 1;
}


string getflag(int valflag)
{
//	string outstr;
//	mixed ret;
//	int i;

	//״̬0����1��ʼͶע2Ͷע��ֹ3�������4�ɲʽ���10��ͣʹ��
	if( valflag==0 )
		return CYN"��ҪͶע"NOR;
	if( valflag==1 )
		return HIG"����Ͷע"NOR;
	if( valflag==2 )
		return HIB"Ͷע��ֹ"NOR;
	if( valflag==4 )
		return HIR"�ɲʽ���"NOR;
	if( valflag==10 )
		return HIR"��ͣͶע"NOR;
	if( valflag!=3 )
		return HIR"״̬����"NOR;
	if( valflag==3 )
		return HIY"�ȴ��ɲ�"NOR;
/*
	if( valresult!=0){
		ret = leasedb("select odds_id,odds_remark,odds from "+DB_ODDS_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"' AND odds_id='"+valresult+"'");
		if(!ret || sizeof(ret)!=1) 
			return "�������������⣬�뱨��wiz\n";
		return ret[0][1];
	}else
*/
		return HIR"�ѱ�ȡ��"NOR;
}

string getresult(string valcode, int valflag,int valresult)
{
	//string outstr;
	mixed ret;
	//int i;

	//״̬0����1��ʼͶע2Ͷע��ֹ3�������4�ɲʽ���10��ͣʹ��
	switch(valflag){
		case 0:
		case 1:
		case 2:
			return "";
		};

	if( valresult!=0){
		ret = leasedb("select odds_id,odds_remark,odds from "+DB_ODDS_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"' AND odds_id='"+valresult+"'");
		if(!ret || sizeof(ret)!=1) 
			return "�������������⣬�뱨��wiz\n";
		return ret[0][1];
	}else
		return "�ѱ�ȡ��";
}

string getmytime(int valflag, int valbegin_time, int valstop_time, int valend_time)
{
	if( valflag==0 )
		return sprintf("����ʱ��Ϊ:%s",DOBET_D->shorttime(valbegin_time));
	if( valflag==1 )
		return sprintf("��ֹʱ��Ϊ:%s",DOBET_D->shorttime(valstop_time));
	if( valflag==2 )
		return sprintf("�ɲ�ʱ��Ϊ:%s",DOBET_D->shorttime(valend_time));
	if( valflag==3 )
		return sprintf("�ɲ�ʱ��Ϊ:%s",DOBET_D->shorttime(valend_time));
	if( valflag==4 )
		return "�ɲʽ���";
	if( valflag==10 )
		return "��ͣͶע";
	return "����";
}

string getoddsstr(string valcode,string valpre,string valsuffix)
{
	string outstr;
	mixed ret;
	int i;

	ret = DOBET_D->leasedb("select odds_id,odds_remark,odds from "+DB_ODDS_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND code='"+valcode+"'");
	if(!ret || sizeof(ret)<1) 
		return valpre+HIR"��δ�����κ�����                                       "NOR+valsuffix;
	outstr="";
	
	for(i=0;i<sizeof(ret);i++)
		outstr+= valpre+sprintf("��ע����:"HIW"%2i"NOR" ��ע���ݣ�"CYN"%-20s"NOR" ���ʣ�"HIW"%3d.%-2d"NOR,
			ret[i][0],ret[i][1],ret[i][2]/100,ret[i][2]%100)+valsuffix;
	return outstr;
}
