/**********************************************************************************
//
//      roomleased.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/adm/deamons��
// 		������ⷿ��Ľ���
//      change it to db by Ciwei@SJ
***********************************************************************************/

inherit F_SAVE;

#include <ansi.h>
//#include <roomlease.h>
#include <mudlib.h>

#define MSG_CMDS "/cmds/std/msg"
#define DB_NAME "lease"
//��һ��Ͷ�꿪ʼ��ʱ����
#define NEXT_BID		300
//ˢ��ʱ��
#define MYLOG_TIME		60
/*��Ϊ���������ⲹ����� �ٺ� �������Ϊ100000 ������Ϊ0 */
#define PAY_FOR_CRASH           100000

int strtoint(string arg);
int givemoney(string valuserid,int money,string valreason);
int sum_by_discount(int ival,int idiscount);
string get_myregions(string str);

string longtime(int t);
string shorttime(int t);
string Ctime(string ts);
string chinese_time(int total);
string money_str(int amount);

void init_statistic();
void do_statistic();
void check_lease();
void check_bid();
void write_log();
void change_dp(string valbidname);
void pay_for_crash();
void set_all_name(int type);

nosave int ilaststatistic;
int iifstop;
int livetime;
int iifpublicrepay=0;

string query(string arg)
{
	if (arg == "channel_id")
		return "Τ���̻�";
}

int start_lease()
{
	if(!iifstop) return 0;
	livetime = time();
	//if(!dbquery("REPLACE mud_var SET name='leasetime',value='"+time()+"'")) return 0;
	call_out("do_statistic", 2);
	iifstop=0;
	set_all_name(iifstop);
	return 1;
}

void create()
{
	seteuid(getuid());

	iifstop=0;
	restore();
	iifpublicrepay=0;
	init_statistic();
	set_all_name(iifstop);
}

string query_save_file()
{
	return DATA_DIR+"lease";
}

void remove()
{
	save();
	set_all_name(1);
}

void pay_for_crash()
{
	int t;
	
	if(iifstop==1) return;
		
	t = time() - livetime;
	//ϵͳ������������û��Ӧ
	if(t>MYLOG_TIME*2)
	{
		mixed ret;
		dbquery("update "+DB_NAME+" set endtime=endtime+'"+t+"',bidendtime=bidendtime+'"+t+"' where leaser!='*' AND U_Site='"+INTERMUD_MUD_NAME+"'");
		log_file("leaselog",sprintf("ϵͳ���ܵ��������Զ�����ÿ�������̵���Ч��%d��",t));
		ret = dbquery("select leaser,originshortname,roomwhere,endtime from "+DB_NAME+" where leaser!='*' AND U_Site='"+INTERMUD_MUD_NAME+"'");
		if(!ret || sizeof(ret)<1) return;
		for(int i=0;i<sizeof(ret);i++)
			givemoney(ret[i][0],PAY_FOR_CRASH,HIY"�������ԡ�"+get_myregions(ret[i][2])+ret[i][1]+"���������п����ܵ�ϵͳ������Ӱ�죬\n"
				+"��Ч���Ѿ��Զ��ӳ���"
				+longtime(ret[i][3])
				+"��\n����Ϊ�˱�ʾǸ�⣬ϵͳ�Ѿ��Զ�������Ǯׯ�����������"
				+money_str(PAY_FOR_CRASH)
				+"�������\n"NOR);
	}
}

void init_statistic()
{
	ilaststatistic=time();
	pay_for_crash();//����Ƿ񵱹���
	call_out("do_statistic", MYLOG_TIME);
}

void do_statistic()
{
	write_log();
	//��������Ƿ���
	check_lease();
	//���Ͷ���Ƿ��������תΪ������
	check_bid();
	//dbquery("REPLACE mud_var SET name='leasetime',value='"+time()+"'");
	livetime = time();
	remove_call_out("do_statistic");
	if(!iifstop)
		call_out("do_statistic", MYLOG_TIME);
}

void stop_lease()
{
	iifstop=1;
	set_all_name(iifstop);
	remove_call_out("do_statistic");
}

mixed leasedb(string sql)
{
	mixed ret = dbquery(sql);	
	if(!ret){
		error("roomlease db error!");
		return 0;
	}
	return ret;	
}

int query_ifhavebidname(string valindex)
{
	mixed ret = leasedb("select U_id from "+DB_NAME+" where U_id='"+valindex+"'");
	if(!ret) return 0;
	if(sizeof(ret)<=0) return 0;
	if(sizeof(ret)>1){
		error("db error!");
		return 0;
	}
	return 1;
	//return 	( !undefinedp(roomwhere[valindex]) );
}

string *query_keys()
{
	string* r;
	mixed ret = leasedb("select U_id from "+DB_NAME);
	for(int i=0;i<sizeof(ret);i++)
	{
		if(!r) r = ({ret[i][0]});
		else r += ({ret[i][0]});
	}
	return r;
}

mapping query_amap(string valindex)
{
	mapping amap;
	mixed ret = leasedb("select * from "+DB_NAME+" where U_id='"+valindex+"'");
	if(sizeof(ret)<=0) return 0;
	if(sizeof(ret)>1){
		error("db error!");
		return 0;
	}
	amap = ([]);
	amap["files"] = explode(ret[0][2],",");//�շѵص�
	//amap["roomwhere"] = explode(ret[0][2],",");
	//����Ҫ���ص㡣��
	//amap["room_bidname"] = room_bidname[valindex];
	amap["bidtype"] = ret[0][3];
	amap["minirent"] = ret[0][4];
	amap["minirentadd"] = ret[0][5];
	amap["originshortname"] = ret[0][6];
	amap["leasetime"] = ret[0][7];
	amap["minskill"] = ret[0][8];
	amap["maxskill"] = ret[0][9];
	amap["discount"] = ret[0][10];

	amap["leaser"] = ret[0][11];
	amap["leasername"] = ret[0][12];
	amap["leaser_bidmoney"] = ret[0][13];
	amap["repayamount"] = ret[0][14];
	amap["payamount"] = ret[0][15];
	amap["begintime"] = ret[0][16];
	amap["endtime"] = ret[0][17];
	amap["leasertype"] = ret[0][18];

	amap["bider"] = ret[0][19];
	amap["bidername"] = ret[0][20];
	amap["bidamount"] = ret[0][21];
	amap["bidtime"] = ret[0][22];
	amap["bidendtime"] = ret[0][23];
	amap["bidertype"] = ret[0][24];
	amap["roomwhere"] = ret[0][25];//������
	amap["varmoney"] = ret[0][26];//Ч��
	amap["settime"] = ret[0][27];//��ʼ���õ�ʱ��
	amap["paytime"] = ret[0][28];//���һ�ν���ʱ��
	return amap;
}

int set_room(string* filename, string valbidname, int valbidtype, int valminirent, int valminirentadd, string valoriginshortname, int valleasetime,int valminskill, int valmaxskill, int valdiscount,string roomwhere)
{
	string sql;
	mixed ret = leasedb("select leaser,bider from "+DB_NAME+" where U_id='"+valbidname+"'");
	if(!ret) return 0;
	if(sizeof(ret)>1)
	{
		error("db error!");
		return 0;
	}
	/*
	if(sizeof(ret)==1)
	{
		if(ret[0][0]!="*")
		return notify_fail("������仹����������\n");
		if(ret[0][1]!="*")
		return notify_fail("������仹������Ͷ����\n");
	}
	*/
	if(sizeof(ret)>0)
	sql = "UPDATE "+DB_NAME+" SET "	
	+"U_filename='"+implode(filename,",")+ "',"
	+"bidtype='"+valbidtype+ "',"
	+"minirent='"+valminirent+ "',"
	+"minirentadd='"+valminirentadd+ "',"
	+"originshortname='"+valoriginshortname+ "',"
	+"leasetime='"+valleasetime+ "',"
	+"minskill='"+valminskill+ "',"
	+"maxskill='"+valmaxskill+ "',"
	+"roomwhere='"+roomwhere+ "',"
	+"settime='"+time()+ "',"
	+"discount='"+valdiscount+ "'"
	+" WHERE U_id='"+valbidname+"' AND U_Site='"+INTERMUD_MUD_NAME+"'";
	else sql = "REPLACE "+DB_NAME+" SET U_id='" + valbidname + "',"
	+"U_Site='" + INTERMUD_MUD_NAME + "',"
	+"U_filename='"+implode(filename,",")+ "',"
	+"bidtype='"+valbidtype+ "',"
	+"minirent='"+valminirent+ "',"
	+"minirentadd='"+valminirentadd+ "',"
	+"originshortname='"+valoriginshortname+ "',"
	+"leasetime='"+valleasetime+ "',"
	+"minskill='"+valminskill+ "',"
	+"maxskill='"+valmaxskill+ "',"
	+"roomwhere='"+roomwhere+ "',"
	+"settime='"+time()+ "',"
	+"discount='"+valdiscount+ "'";
	if(!sizeof(ret)) sql += ",bidendtime='"+(time()+300)+"'";
	if(leasedb(sql)) return 1;
	return 0;
}

int delete_room(string valbidname)
{
	string* room;
	object r;
	mixed ret = leasedb("select U_filename,leaser,bider from "+DB_NAME+" where U_id='"+valbidname+"' AND U_Site='"+INTERMUD_MUD_NAME+"'");
	if(!ret || sizeof(ret)<1) return 0;
	if(sizeof(ret)>1)
	{
		error("db error!");
		return 0;
	}
	//////���￴���Ƿ������б��� ����������Ӫ��
	if(sizeof(ret)==1)
	{
		if(ret[0][1]!="*")
		return notify_fail("������仹����������\n");
		if(ret[0][2]!="*")
		return notify_fail("������仹������Ͷ����\n");
		room = explode(ret[0][0],",");		
	}
	if(!leasedb("DELETE FROM "+DB_NAME+" WHERE U_id='"+valbidname+"' AND U_Site='"+INTERMUD_MUD_NAME+"'"))
		return 0;
	if(room && sizeof(room)) for(int i=0;i<sizeof(room);i++)
	{
		r = find_object(room[i]);
		if(!r) continue;
		r->back_rsname();
	}
	write("ɾ���ɹ���\n");
	return 1;
}

void set_all_name(int type)
{
	object r;
	mixed ret = leasedb("select roomwhere from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"'");
	//leaser!='*' AND 
	if(!ret || !sizeof(ret)) return;
	for(int i=0;i<sizeof(ret);i++)
	{
		r = find_object(ret[i][0]);
		if(!r) continue;
		if(type) r->back_rsname();
		else r->change_rsname();
	}
}

int new_bid(object me, string valbidname,int valbidamount, int valbidertype)
{
	string valroomname;
	int valbidtype;
	mixed ret;
	
	if(iifstop==1) return 0;
	ret = leasedb("select U_filename,originshortname,bidtype,bider,bidamount,leasetime,bidendtime,roomwhere from "+DB_NAME+" where U_id='"+valbidname+"' AND U_Site='"+INTERMUD_MUD_NAME+"'");
	if(!ret) return 0;
	if(sizeof(ret)>1)
	{
		error("db error!");
		return 0;
	}
	valroomname=get_myregions(ret[0][7])+ret[0][1];
		
	me->add("balance",-valbidamount);
	valbidtype=(ret[0][2]==1)?valbidertype:2;
	if( ret[0][3]!="*" )
		givemoney(ret[0][3],ret[0][4],
			HIY"���ڡ�"+valroomname+"����"
			+((valbidtype==2)?"һλ������ʿ":me->query("name"))
			+"����"
			+money_str(valbidamount)
			+"����ߣ���Ԥ���Ķ������˻���Ĵ������\n"NOR);
		
	if(!leasedb("UPDATE "+DB_NAME+" SET "
	+"bider='"+me->query("id")+ "',"
	+"bidername='"+me->query("name")+ "',"
	+"bidamount='"+valbidamount+ "',"
	+"bidtime='"+time()+ "',"
	+"bidertype='"+valbidtype+ "'"
	+" WHERE U_id='" + valbidname + "' AND U_Site='" + INTERMUD_MUD_NAME + "'")) return 0;

	write(HIY"��"+((valbidtype==2)?"����":"ʵ��")
		+"Ͷ��ɹ���Ͷ��Ѻ���Ѿ���������д���п۳�\n"
		+"���ڵĴ�����Ϊ"
		+money_str(me->query("balance"))
		+"\n"NOR);
	
	CHANNEL_D->do_channel(this_object(),"trade",((valbidtype==2)?"һλ������ʿ":me->query("name"))
		+"����"
		+money_str(valbidamount)
		+HIY"Ͷ�꡾"
		+valroomname
		+"��"
		+chinese_time(ret[0][5])
		+"������Ȩ��Ŀǰ����߼ۣ�Ͷ�꽫��"
		+chinese_time(ret[0][6]-time())
		+"�����"NOR);
	/*
	message("channel:chat", 
		HIW"\n��������Ϣ��"HIY
		+((valbidtype==2)?"һλ������ʿ":me->query("name"))
		+"����"
		+money_str(valbidamount)
		+HIY"Ͷ�꡾"
		+valroomname
		+"��"
		+chinese_time(ret[0][5])
		+"������Ȩ��Ŀǰ����߼ۣ�Ͷ�꽫��"
		+chinese_time(ret[0][6]-time())
		+"�����\n"NOR,
		users());
	*/
	return 1;
}

void check_lease()
{
	int i;	
	string valreason,valroomname,valmsg;
	int irepayamount;
	int ipayoff;	
	mixed op;		
	mixed ret = leasedb("select U_id,repayamount,discount,leaser_bidmoney,roomwhere,originshortname,begintime,endtime,payamount,leaser,leasertype,leasername from "+DB_NAME+" where leaser!='*' AND U_Site='"+INTERMUD_MUD_NAME+"'AND endtime<'"+time()+"'");
	if(!ret || !sizeof(ret)) return;
	
	if(iifstop==1) return;
	
	for(i=0;i<sizeof(ret);i++)
	{
		op = ret[i];
		irepayamount=sum_by_discount(op[1],op[2]);		
		ipayoff=(op[3]>irepayamount)?
			op[3]-irepayamount
			:irepayamount-op[3];		
		valroomname=get_myregions(op[4])+op[5];
		
		valreason=HIY"���"
			+longtime(op[6])
			+"����ġ�"
			+valroomname
			+"���Ѿ���"
			+longtime(op[7])
			+"���ڽ���\n�ܼ�����Ϊ"
			+money_str(irepayamount)
			+"���㵱��Ͷ�껨��Ϊ"
			+money_str(op[3])
			+"��"
			+( (op[3]>irepayamount)?"����":"ӯ��" )
			+money_str(ipayoff)+"\n";
		if(op[8]) valreason +=
			"���ڼ����Ѿ����"
			+money_str(op[8])+"��";
		if(irepayamount-op[8]) valreason +=
			"���"
			+money_str(irepayamount-op[8])
			+"�Ѿ�����������д�";
		valreason +="�����\n"NOR;
				
		givemoney(op[9],irepayamount-op[8],valreason);
		valmsg = ((op[10]==2)?"һλ������ʿ":op[11])
			+"��ġ�"
			+valroomname;
					
		if( iifpublicrepay==1 )
			valmsg += "���Ѿ����ڽ�����������Ϊ"
				+money_str(irepayamount)
				+"��"
				+( (op[3]>irepayamount)?"����":"ӯ��" )
				+money_str(ipayoff)+NOR;
				//+"\n"NOR;
		else
			valmsg += "���Ѿ����ڽ�����\n"NOR;
		
		CHANNEL_D->do_channel(this_object(),"trade",valmsg );

		//message("channel:chat", valmsg, users());
		
		log_file("leaselog","��"+valroomname+"��"
			+op[11]
			+((op[10]==2)?"����":"ʵ��")
			+"��ġ�"
			+valroomname
			+"���Ѿ����ڽ�����������Ϊ"
			+money_str(irepayamount)
			+"��"
			+( (op[3]>irepayamount)?"����":"ӯ��" )
			+money_str(ipayoff)
			+"\n");
		
		if(!leasedb("UPDATE "+DB_NAME+" SET "
		+"leaser='*',"
		+"leasername='*',"
		+"leaser_bidmoney='"+0+ "',"
		+"repayamount='"+0+ "',"
		+"payamount='"+0+ "',"
		+"begintime='"+0+ "',"
		+"endtime='"+0+ "',"
		+"leasertype='"+1+ "'"
		+" WHERE U_id='" + op[0] + "' AND U_Site='" + INTERMUD_MUD_NAME + "'"))
			log_file("leaselog","�ϲ����ݿ����ʧ�ܡ�");
		change_dp(op[0]);
	}
}

void check_bid()
{
	int i;
	mixed op;
	//int inowtime;
	string valreason,valroomname;
	mixed ret;
	
	if(iifstop==1) return;
	ret = leasedb("SELECT U_id,bider,bidendtime,leasetime,roomwhere,originshortname,leaser,bidamount,bidertype,minirent,bidername  from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND bidendtime<'"+time()+"'");
	for(i=0;i<sizeof(ret);i++){
		op = ret[i];
		//bider,bidendtime,leasetime,roomwhere,originshortname,leaser,bidamount,bidertype,minirent,bidername
		//[valindex[i]]
		if( op[1]=="*" ){
			//��������˻�û��Ͷ���ߣ��ͽ�ʱ���ӳ�			
			//op[2] = time()+op[3]+60;			
			valroomname=get_myregions(op[4])+op[5];
			
			CHANNEL_D->do_channel(this_object(),"trade","���ڡ�"
				+valroomname
				+"��������Ͷ�꣬���ر�ʱ���ӳ���"
				+shorttime(op[2])
				+"�����ҿ����̱��˻�ѽ"NOR );
			/*
			message("channel:chat",   
				HIW"\n��������Ϣ��"HIY
				+"���ڡ�"
				+valroomname
				+"��������Ͷ�꣬���ر�ʱ���ӳ���"
				+shorttime(op[2])
				+"�����ҿ����̱��˻�ѽ\n"NOR,
				users()); */
		   	log_file("leaselog","���ڡ�"+valroomname+"��������Ͷ�꣬���ر�ʱ���ӳ���"+longtime(op[2])+"\n");
		   	if(!leasedb("UPDATE "+DB_NAME+" SET "
			+"bidendtime='"+(time()+op[3]+60)+ "'"
			+" WHERE U_id='" + op[0] + "' AND U_Site='" + INTERMUD_MUD_NAME + "'"))			
			log_file("leaselog","�ϲ����ݿ����ʧ�ܡ�");
			continue;
		};
		//�����ǰ���仹�б������ã�Ҳ����ȥ��
		if( op[6]!="*" )
			continue;
			
		valroomname=get_myregions(op[4])+op[5];
		valreason=HIY"��"
			+valroomname
			+"����Ͷ���У����Ѿ��б꣬�б��Ϊ��"
			+money_str( op[7])
			+"����"
			+longtime(time() )
			+"���⣬��"
			+longtime(time()+op[3] )
			+"����\n"NOR;
			
	   	log_file("leaselog","��"+valroomname+"��"
   			+op[10]
			+((op[8]==2)?"����":"ʵ��")
   			+"�б꣬�б��Ϊ��"
			+money_str(op[7])
			+"����"
			+longtime(time())
			+"���⣬��"
			+longtime(time()+op[3] )
			+"����\n");
		
		//���ˣ���Ͷ���Ϊ��
		
		if(!leasedb("UPDATE "+DB_NAME+" SET "
		+"leaser='"+op[1]+ "',"
		+"leasername='"+op[10]+ "',"
		+"leaser_bidmoney='"+op[7]+ "',"
		+"repayamount='"+0+ "',"
		+"payamount='"+0+ "',"
		+"begintime='"+time()+ "',"
		+"endtime='"+(time()+op[3])+ "',"
		+"leasertype='"+op[8]+ "',"
		+"bider='*',"
		+"bidername='*',"	
		+"bidamount='"+0+ "',"
		+"bidtime='"+(time()+NEXT_BID)+ "',"
		+"bidendtime='"+(time()+op[3]+MYLOG_TIME )+ "',"
		+"bidertype='"+1+ "'"
		+" WHERE U_id='" + op[0] + "' AND U_Site='" + INTERMUD_MUD_NAME + "'"))
			log_file("leaselog","�ϲ����ݿ����ʧ�ܡ�");
		//�´ο�ʼͶ��ʱ��Ӧ����������ڽ�����
		//Ͷ�����ʱ��ȷ������ڵ���ʱ���һ��ʱ��		
		givemoney(op[6],0,valreason);
		
		CHANNEL_D->do_channel(this_object(),"trade","�ڡ�"
			+valroomname
			+"����Ͷ���У�"
			+((op[8]==2)?"һλ������ʿ":op[10])
			+"�б꣬�б��Ϊ��"
			+money_str(op[7])
			+HIY"����"
			+shorttime(time())
			+"���⣬��"
			+shorttime(time()+op[3])
			+"����");
	/*
		message("channel:chat",   
			HIW"\n��������Ϣ��"HIY
			+"�ڡ�"
			+valroomname
			+"����Ͷ���У�"
			+((op[8]==2)?"һλ������ʿ":op[10])
			+"�б꣬�б��Ϊ��"
			+money_str(op[7])
			+HIY"����"
			+shorttime(time())
			+"���⣬��"
			+shorttime(time()+op[3])
			+"����\n"NOR,
			users());
		*/
		CHANNEL_D->do_channel(this_object(),"trade","��"
			+valroomname
			+"������һ��Ͷ�꽫��"
			+shorttime(time()+NEXT_BID)
			+"��ʼ���׼�Ϊ��"
			+money_str(op[9])
			+"������ӻԾͶ��\n"NOR );
		/*
		message("channel:chat",   
			HIW"\n��������Ϣ��"HIY
			+"��"
			+valroomname
			+"������һ��Ͷ�꽫��"
			+shorttime(time()+NEXT_BID)
			+"��ʼ���׼�Ϊ��"
			+money_str(op[9])
			+"������ӻԾͶ��\n"NOR,
			users());
		*/
		change_dp(op[0]);
	}
}

void write_log()
{
	int i;
	int inowtime;
	string valreason,valroomname;
	string valfilename;
	int irepayamount;
	int ipayoff;
	mixed op;
	mixed ret;
				
	inowtime=time();
	if( inowtime<(ilaststatistic+MYLOG_TIME) )
		return;
	ilaststatistic=inowtime;
	ret = leasedb("SELECT U_id,repayamount,discount,leaser_bidmoney,roomwhere,originshortname,leaser,begintime,endtime,payamount from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"'");
	if(!ret || sizeof(ret)<1) return;
	for(i=0;i<sizeof(ret);i++){
		op= ret[i];
		valfilename = "lease/"+op[0];
		
		irepayamount=sum_by_discount(op[1],op[2]);
		ipayoff=(op[3]>irepayamount)?
			op[3]-irepayamount
			:irepayamount-op[3];
		valroomname=get_myregions(op[4])+op[5];

		valreason=op[6]
			+"��"
			+shorttime(op[7])
			+"����ġ�"
			+valroomname
			+"��������"
			+shorttime(op[8])
			+"\n    �ܼ�����Ϊ"
			+money_str(irepayamount)
			+"������Ͷ�껨��Ϊ"
			+money_str(op[3])
			+"��"
			+( (op[3]>irepayamount)?"����":"ӯ��" )
			+money_str(ipayoff)
			+"\n�ڼ��Ѿ����"
			+money_str(op[9])
			+"�����"
			+money_str(irepayamount-op[9])
			+"����ǰʱ��Ϊ:"
			+shorttime(time())
			+"\n";
	   	log_file(valfilename,valreason);
	}
}

int tikuan(object me, string valbidname,int amount)
{
	int commision;
	string valroomname;
	mixed ret;	
		
	if(iifstop==1){
		write("�г��Ѿ�ֹͣ��ҵ��\n");
		return 1;
	}
	commision=amount/10;	
	if(!leasedb("UPDATE "+DB_NAME+" SET "
		+"payamount=payamount+'"+(amount+commision)+ "'"		
		+" WHERE U_id='" + valbidname + "' AND U_Site='" + INTERMUD_MUD_NAME + "'"))
	{
		write("����ʧ�ܣ������̵��Ѿ����գ�����ϵwiz��\n");
		return 1;
	}
	
	me->add("balance",amount);
	ret = leasedb("SELECT roomwhere,originshortname,payamount from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND U_id='"+valbidname+"'");
	if(!ret || sizeof(ret)!=1) return 0;	
	//payamount[valbidname]+=amount+commision;		
	valroomname=get_myregions(ret[0][0])+ret[0][1];
	write(HIY"\n��ӡ�"
			+valroomname
			+"����������Ԥ֧"
			+money_str(amount)
			+"��������д��,����������"
			+money_str(commision)
			+"���ڼ����ۼ�Ԥ֧����������Ϊ"
			+money_str(ret[0][2])
			+"\n"NOR);
	return 1;
}

string getroomshort(string valroomfilename)
{
	string perstr;
	mixed ret;
	
	if(iifstop==1) return 0;
	ret = leasedb("SELECT leaser,originshortname,leasertype,leasername from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND roomwhere='"+valroomfilename+"'");
	//message("wizard:ciwei",sprintf("%O\n",ret),users());
	if(!ret || sizeof(ret)<1 )
		return "*";
	perstr = "";
	if( ret[0][0] == "*" )
		return "�����"+ret[0][1];
	if( ret[0][2] == 2 )
		return "�����"+ret[0][1];
	return ret[0][3]+"��"+ret[0][1];
}

void add_money(string valroomfilename,int valmoneyamount)
{
	mixed ret = leasedb("SELECT U_id from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND U_filename LIKE '%"+valroomfilename+"%'");
	if(!ret || sizeof(ret)<1 ) return;
	//if( undefinedp(room_bidname[valroomfilename]) )
	//	return;
	if(!leasedb("UPDATE "+DB_NAME+" SET "
		+"paytime='"+time()+ "',"
		+"repayamount=repayamount+'"+(valmoneyamount)+ "'"
		+" WHERE U_id='" + ret[0][0] + "' AND U_Site='" + INTERMUD_MUD_NAME + "'"))
		log_file("leaselog","����ʧ�ܡ�");
	//repayamount[room_bidname[valroomfilename]] += valmoneyamount;
}

void change_dp(string valbidname)
{
	object obj;
	mixed ret = leasedb("SELECT roomwhere  from "+DB_NAME+" where U_Site='"+INTERMUD_MUD_NAME+"' AND U_id='"+valbidname+"'");
	if(sizeof(ret)<1) return;
	if(sizeof(ret)>1) error("db error!");
	obj = new("/clone/npc/spguanjia");
	obj->set("target", ret[0][0]);
//	obj->set("workflag", valflag);
	obj->move(ret[0][0]);
}

int sum_by_discount(int ival,int idiscount)
{
	return (ival*idiscount)/10000;
}

string get_myregions(string str)
{
	string regions;
		
	regions = TASK_D->get_regions(str);
    if( regions == "" )
    	regions = "��ԭ";
    return regions;
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

string chinese_time(int total)
{
	int d, h, m, s;
	string tmp = "";

	if (!total)
		return "����";
	d = total / 86400;
	if (d) tmp += CHINESE_D->chinese_number(d) + "��";
	h = (total % 86400) / 3600;
	if (h) tmp += CHINESE_D->chinese_number(h) + "Сʱ";
	m = (total % 3600) / 60;
	if (m) tmp += CHINESE_D->chinese_number(m) + "��";
	s = total % 60;
	if (s) tmp += CHINESE_D->chinese_number(s) + "��";
		else if (m) tmp += "��";
	return tmp;
}

string Cday(string ts)
{
	int d;
	sscanf(ts," %d",d);
	sscanf(ts,"%d",d);
	if(!d) return 0;
	return chinese_number(d)+"��";
}

string longtime(int t)
{
	string ts = ctime(t);
	ts = " "+ts[19..23]+"��"+ts[4..6]+Cday(ts[8..9])+ts[10..15];
	return Ctime(ts);
}

string shorttime(int t)
{
	string ts = ctime(t);
	ts = ts[4..6]+Cday(ts[8..9])+ts[10..15];
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

int strtoint(string arg)
{
	int t;
	if(!arg) return 0;
	if(sscanf(arg,"%d",t)==1) return t;
	return 0;
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
			MSG_CMDS->system_send(this_object(),({valuserid}),"���̾�Ӫ����",valreason);
			//add
			body->set_temp("db_quit",1);
			body->save();
		}
		destruct(ob);
		destruct(body);
	};
	return 1;
}

string get_money_str(int coin)
{
	string output;
	
	if(!coin) return HIW"��"NOR;	
	output = MONEY_D->money_str(coin);
	while(strlen(strip(output))>10)
	{
		if(strsrch(output,"ͭǮ")!=-1 && strsrch(output,"����")!=-1)
		{
			output = output[0..strsrch(output,"����")+3];
			continue;
		}
		
		if(strsrch(output,"ͭǮ")!=-1 && strsrch(output,"�ƽ�")!=-1)
		{
			output = output[0..strsrch(output,"�ƽ�")+3];
			continue;
		}
		
		if(strsrch(output,"����")!=-1 && strsrch(output,"�ƽ�")!=-1)
		{
			output = output[0..strsrch(output,"�ƽ�")+3];
			continue;
		}
		
		break;
	}
	return output;
}

string query_list(string id)
{
	mapping leasemap;
	string *indexval, outstr,roomset,leasestr,bidstr;
	string valroomname;
	int i;
	
	indexval= query_keys();
	if(!sizeof(indexval)) return 0;
	
	roomset="";
	leasestr="";
	bidstr="";
	for(i=0;i<sizeof(indexval);i++)
	{
		leasemap=query_amap(indexval[i]);
		valroomname=get_myregions(leasemap["roomwhere"])+leasemap["originshortname"];
		//message("wizard:ciwei",sprintf("id:%s,map:%O\n",indexval[i],leasemap),users());
		roomset+=sprintf("��%-30s%|10s%|20s%|20s%|16s%|16s��\n",
			valroomname+NOR"("+indexval[i]+")",
			( (leasemap["bidtype"]==0)?RED"ֹͣͶ��"NOR:((leasemap["bidtype"]==1)?BLU"ʵ��Ͷ��"NOR:CYN"����Ͷ��"NOR) ),
			get_money_str(leasemap["minirent"]),
			//sprintf("%d��"HIY+"�ƽ�"NOR,leasemap["minirent"]/10000),
			get_money_str(leasemap["minirentadd"]),			
			//sprintf("%d��"HIY+"�ƽ�"NOR,leasemap["minirentadd"]/10000),
			chinese_time(leasemap["leasetime"]),
			"���֮"+CHINESE_D->chinese_number(leasemap["discount"])
			);
		if((leasemap["bidtype"]!=0 || leasemap["leasername"]!="*")&&(!id||leasemap["leaser"]==id))//�����Ѿ�ֹͣͶ�� ���ҵ�ǰ�޳�����
		{		
		if(leasemap["leaser"]==id)
		leasestr+=sprintf("��%-30s%|4s%|20s%|18s%|20s%|20s��\n",
			valroomname+"("+indexval[i]+")",
			((leasemap["leasertype"]==2)?RED"����"NOR:HIG"ʵ��"NOR),
			get_money_str(leasemap["leaser_bidmoney"]),
			//sprintf("%d��"HIY+"�ƽ�"NOR,leasemap["leaser_bidmoney"]/10000),
			(leasemap["endtime"]==0)?"��":shorttime(leasemap["endtime"]),
			get_money_str(sum_by_discount(leasemap["repayamount"],leasemap["discount"])),
			//sprintf("%d��"HIY+"�ƽ�"NOR,sum_by_discount(leasemap["repayamount"],leasemap["discount"])/10000),
			get_money_str(leasemap["payamount"]),
			//sprintf("%d��"HIY+"�ƽ�"NOR,leasemap["payamount"]/10000),
		);
		else 
		leasestr+=sprintf("��%-30s%|10s%|20s%|52s��\n",
			valroomname+NOR"("+indexval[i]+")",
			( (leasemap["leasername"]=="*")?"����":((leasemap["leasertype"]==2)?"������ʿ":leasemap["leasername"]) ),
			get_money_str(leasemap["leaser_bidmoney"]),
			//sprintf("%d��"HIY+"�ƽ�"NOR,leasemap["leaser_bidmoney"]/10000),
			sprintf("%+25s%2s%-25s",(leasemap["begintime"]==0)?"��":shorttime(leasemap["begintime"]),
						HIC"��"NOR,
						(leasemap["endtime"]==0)?"��":shorttime(leasemap["endtime"])
			),
			);
		}		
		//Ͷ�����
		if((leasemap["bidtype"]!=0||leasemap["bidername"]!="*")&&(!id||leasemap["bider"]==id))//�����Ѿ�ֹͣͶ�� ���ҵ�ǰ��Ͷ����
		bidstr+=sprintf("��%-30s%|10s%|20s%|20s%|20s%|12s��\n",
			valroomname+NOR"("+indexval[i]+")",
			(leasemap["bidername"]=="*")?"����":((leasemap["bidertype"]==2)?"������ʿ":leasemap["bidername"]),
			//sprintf("%d��"HIW+"����"NOR,leasemap["bidamount"]/100),
			get_money_str(leasemap["bidamount"]),
			//sprintf("%d��"HIY+"�ƽ�"NOR,leasemap["bidamount"]/10000),
			(leasemap["bidtime"]==0)?"��":shorttime(leasemap["bidtime"]),
			(leasemap["bidendtime"]==0)?"��":shorttime(leasemap["bidendtime"]),
			leasemap["bidtype"]==0?RED"ֹͣͶ��"NOR:( time()<leasemap["bidtime"]?HIY"׼��Ͷ��"NOR:((leasemap["bidendtime"]>time())?HIG"����Ͷ��"NOR:HIY"Ͷ���ֹ"NOR))
			);
	};
	outstr="";
	outstr+=sprintf("������������ǰ����ĵ�����%4d��������������������������������������������������������������������������������������\n",sizeof(indexval));
	outstr+="��   ����                        Ͷ������      ���Ͷ���           ��ͼӼ�            ����          ��ɱ���    ��\n";
	outstr+=roomset;
	if(leasestr!="")
	{
	outstr += "�������������������������������������������������������������������������������������������������������������������\n";
	if(id)
		outstr+="��   ����                       ����       �б��            ���ڽ�ֹ             ����                Ԥ֧        ��\n";
	else    outstr+="��   ����                         ������         �б��                           ��        ��                    ��\n";
	outstr+=leasestr;
	}
	if(bidstr!="")
	{
	outstr += "����������Ͷ�������������������������������������������������������������������������������������������������������\n";	
	outstr+="��   ����                       ��߳�����       Ͷ���             Ͷ��ʱ��            ����ʱ��        Ͷ��״̬  ��\n";
	outstr+=bidstr;
	}
	outstr += "��������������������������������������������������������������������������������������������������������������������\n";
	
	return outstr;	
}
