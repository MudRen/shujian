
//ʹ�����ݿ���Զ������ļ� by Ciwei@SJ 2004 4 27
//���ļ�ֻ���ֶ�����

#include <ansi.h>
#include <mudlib.h>

#define JIAMI_C "/cmds/common/jiami.c"
#define EV_DATA 1000
/*ÿ���ϴ����ص�����ַ�*/
#define FILE_DB_NAME "discuz"
/*Web�������д���ļ����ݱ�����ݿ�����*/
#define TICK_TIME 60
/*��ʱ����ʱ��*/
#define DB_DATA "mfile_data"
#define DB_FLAG "mfile_flag"

string* for_bid = ({
	"��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��",
	"��","��","��","��","��","��","��","��","��","��",
	"��","��","��",});
///////////////////////////
int stas = 0;
string name="";
string file_data;
string reascon="";
string id="";
int u_part=0;

//"LN","CQ",
string* sites = ({"SJ","SJCB",});
/*����վ*/
int now_site = 0;

string *allow = ({
	"action",
//	"ciwei",
//	"mxzhao",
});

void create()
{
	seteuid(getuid());
	// �������縺����ֻ��Ҫ����վ�����������ݿ� & ����վ�Ż����ظ��µ��ļ�
	if (member_array(INTERMUD_MUD_NAME, sites ) != -1)
		call_out("down_file",TICK_TIME);
	if (member_array(INTERMUD_MUD_NAME, sites ) == -1)
		call_out("delete_file",TICK_TIME/2);
}

string query(string arg)
{
	if (arg == "channel_id")
        	return "���;���";
}

void debug(string arg)
{
	object ob = find_player("ciwei");
	arg = HIW+arg+NOR;	
	if(ob) tell_object(ob,arg);
}

int main(object me, string filename)
{
	//int w;
	me = this_player(1);
		
	if (member_array(geteuid(me), allow) == -1)
		return notify_fail("������å "+implode(allow, " ")+" ר�����\n");
	
	if(getuid(me)!="action")
		return notify_fail("����ʹ��newucp �鿴help newucp��\n");
	
	if (!filename || sscanf(filename,"%s %s",filename,reascon)!=2 )
		return notify_fail("��ʽ���ԣ���鿴������ \n");
	//����<30
	
	if(sizeof(reascon)>30 || sizeof(reascon)<10)
		return notify_fail("���ԭ�������10-30����֮�䣬����������п����ṩ��Ҳ�ѯ��\n");
	seteuid(geteuid(me));
	
	if (member_array(INTERMUD_MUD_NAME, sites ) != -1)
		return notify_fail("��ָ��ֻ���ڿ���վʹ�á�\n");
	
	if(stas!=0) return notify_fail("�Բ��𣬸�ָ�û��ʹ����ϣ����ԵȺ�\n");
	
	filename = resolve_path(me->query("cwd"), filename);

	if ( file_size(filename) < 1)
		return notify_fail("û�� "+filename+" ����ļ������߽�ֹ�������ļ�����������һ��Ŀ¼��\n");

	if( !SECURITY_D->valid_write(filename, me, "write_file")
	|| !SECURITY_D->valid_read(filename, me, "read_file") )
		return notify_fail("Sorry����û�ж�д "+filename+" ����ļ���Ȩ����\n");
	
	name = filename;
	
	//����Ӧ���Ƚ��м��ܴ���
	//���ߴ��͵����Ժ��ټ���Ҳ�� :D		
	//����	
	/*
	w =  strsrch(name,"/",-1);
	filename = name[0..w]+"temp_"+ name[w+1..<1];
	if(!cp(name,filename)) return notify_fail("�ݴ��ļ�����ʧ�ܡ�\n");
	
	
	JIAMI_C->main(this_object(),filename);
	
	file_data = read_file(filename);
	
	if(!rm(filename)) write("�ļ�"+filename+"ɾ��ʧ�ܡ�\n");
	
	*/
	file_data = read_file(filename);
	
	if(!file_data)
	{
		return notify_fail("�ļ�̫�󣬻��������쳣�����ֶ����¡�\n");
	}	
					
	notify_fail("�����ַ����ƣ����ļ�ֻ���ֶ����͡�\n");	
	if(strsrch(file_data,"")!=-1) return 0;
	if(strsrch(file_data,"")!=-1) return 0;
	if(strsrch(file_data,"")!=-1) return 0;
	if(strsrch(file_data,"")!=-1) return 0;
	if(strsrch(file_data,"��")!=-1) return 0;
	if(strsrch(file_data,"��")!=-1) return 0;
	if(strsrch(file_data,"��")!=-1) return 0;
	if(strsrch(file_data,"��")!=-1) return 0;
	if(strsrch(file_data,"��")!=-1) return 0;
	
	file_data = replace_string(file_data, "
", "");
	file_data = replace_string(file_data, "\\", "");
	file_data = replace_string(file_data, "\"", "");
	file_data = replace_string(file_data, "'", "");
	file_data = replace_string(file_data, ";", "��");
	file_data = replace_string(file_data, ",", "��");
	file_data = replace_string(file_data, "&", "��");
	file_data = replace_string(file_data, "+", "��");
	file_data = replace_string(file_data, "*", "��");
	stas = 1;
	u_part=0;
	id = getuid(me);
	CHANNEL_D->do_channel(this_object(),"sys","��ʼ����"+name+"��������վ�����ڴ�������Ժ��ڸ���վ�����¡�");
	call_out("update_file",0);
	return 1;
}

void update_file()
{
	string data;
	string sql;
		
	if(file_data==""){
		stas = 3;
		sql = "UPDATE "+DB_DATA+" SET "
			"U_Time='"+time()+"',"
			"Wizard='"+id+"',"
			"Code='"+reascon+"' "
			"WHERE U_Name='" + name+"'";
	}
	else {
		if(sizeof(file_data)>EV_DATA)
		{
			data = file_data[0..EV_DATA-1];
			file_data = file_data[EV_DATA..<1];
		}
		else
		{
			data = file_data;
			file_data = "";	
		}		
		sql = "REPLACE "+DB_DATA+" SET "
			"U_Name='" + name + "',"
			"U_Part='" + u_part + "',"
			"U_Data='"+data+"'";
		u_part++;		
	}
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,sql,this_object(),"readback");
	call_out("failed",300);
}

void readback(mixed ret)
{
	remove_call_out("failed");
	remove_call_out("update_file");
	remove_call_out("update_flag");
	if(stas == 3)
	{
		now_site = 0;
		call_out("update_flag",0);
		return;
	}
	call_out("update_file",0);
}

void update_flag()
{
	string sql;
	
	if(now_site>=sizeof(sites))
	{		
		CHANNEL_D->do_channel(this_object(),"sys","����"+name+"�ɹ����뵽����վ�ȴ������¡�");
		stas=0;
		return;
	}
	sql = "REPLACE "+DB_FLAG+" SET "
		"U_Name='" + name + "',"
		"U_Site='" + sites[now_site] + "'";		
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,sql,this_object(),"readback2");
	now_site++;
	call_out("failed",300);			
}

void readback2(mixed ret)
{
	remove_call_out("failed");
	remove_call_out("update_file");
	remove_call_out("update_flag");	
	call_out("update_flag",0);
}

void failed()
{
	CHANNEL_D->do_channel(this_object(),"sys","����"+name+"ʧ�ܣ����������Ƿ���á�");
	//log
	stas = 0;
	name="";
	file_data="";
	remove_call_out("update_file");	
}
/////////////////////////////////////////�ϴ����ֽ���///////////////////////////////////////
int d_stas = 0;
string d_file="";
string d_data;
int d_part;

void down_file()
{
	if(d_stas!=0){
		//call_out("down_file",TICK_TIME);
		return;
	}
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,"SELECT U_Name,U_Data FROM "+DB_FLAG+" WHERE U_Site='"+INTERMUD_MUD_NAME+"'",this_object(),"readback3");
}

void readback3(mixed ret)
{
	if(ret && sizeof(ret) )
	{
		int i;
		for(i=0;i<sizeof(ret);i++)		
			if(ret[i][1]=="0") break;		
		if(i==sizeof(ret))
		{
			call_out("down_file",TICK_TIME);
			return;	
		}
		d_stas = 1;
		d_file = ret[i][0];
		d_part = 0;
		CHANNEL_D->do_channel(this_object(),"sys","��׼��������������"+d_file+"��");		
		call_out("down_the_file",0);
	}
	else call_out("down_file",TICK_TIME);
}

void down_the_file()
{
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,"SELECT U_Data,Wizard,Code FROM "+DB_DATA+" WHERE U_Name='"+d_file+"' AND U_Part='"+d_part+"'",this_object(),"readback4");
	call_out("d_failed",300);
}

void readback4(mixed ret)
{	
	remove_call_out("d_failed");
	if(!ret)
	{
		d_stas=0;
		call_out("down_file",TICK_TIME);
		error("���ݿ���󣡣�");
		return;
	}	
	if(!sizeof(ret))
	{		
		d_data = replace_string(read_file(d_file), "
", "\n");
		//d_data = replace_string(d_data, "\n\n", "\n");
		d_data = replace_string(d_data, "", "
");
		d_data = replace_string(d_data, "", "\\");
		d_data = replace_string(d_data, "", "\"");
		d_data = replace_string(d_data, "", "'");
						
		d_data = replace_string(d_data, "��",";");
		d_data = replace_string(d_data, "��",",");
		d_data = replace_string(d_data, "��","&");
		d_data = replace_string(d_data, "��","+");
		d_data = replace_string(d_data, "��","*");
				
		write_file(d_file,d_data,1);
		
		//�����������
		JIAMI_C->main(this_object(),d_file);
		CHANNEL_D->do_channel(this_object(),"sys","����"+d_file+"��ɣ������߹�����Ա�������Ӧ�ó���");
		BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,"REPLACE "+DB_FLAG+" SET U_Name='" + d_file + "',U_Site='" + INTERMUD_MUD_NAME + "',U_Data='1'",this_object(),"over_back");	
		call_out("d_failed",300);
		return;
	}
	
	if(sizeof(ret)>1)
	{
		d_stas=0;
		call_out("down_file",TICK_TIME);
		error("���ݿ���󣡣�");
		return;
	}
			
	if(sizeof(ret)==1)
	{
		string wizard = ret[0][1];
		string be = ret[0][2];
		d_data = ret[0][0];
				
		//add log here	
		if(!d_part) log_file("static/super_ftp",sprintf("����%-30s,%-8s����%s",be,wizard,d_file),this_object());
		//add test
		if(!write_file(d_file,d_data,!d_part?1:0))
		{
			CHANNEL_D->do_channel(this_object(),"sys","����"+d_file+"ʧ�ܣ������߹�����Ա��ȫ�ļ���");
			//change db
			d_stas=0;
			call_out("down_file",TICK_TIME);
			return;
		}
		d_part++;
		call_out("down_the_file",0);
	}
}

void over_back(mixed ret)
{
	d_stas=0;
	remove_call_out("d_failed");
	call_out("down_file",1);
	return;
}

void d_failed()
{
	d_stas=0;
	call_out("down_file",TICK_TIME);
	CHANNEL_D->do_channel(this_object(),"sys","����"+d_file+"ʧ�ܣ����������Ƿ���á�");
	return;
}
/////////////////////////////////////���ز��ֽ���///////////////////////////////////////////

int delete_busy = 0;
mixed hash;
int delete_num = 0;
string to_delete;

void delete_file()
{
	if(delete_busy!=0)
	{
		//call_out("delete_file",TICK_TIME);
		return;
	}
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,"SELECT U_Name,U_Data FROM "+DB_FLAG,this_object(),"delete_back");
}

void check_hash()
{
	mixed tt;
	if(delete_num >= sizeof(hash))
	{
		delete_busy = 0;
		call_out("delete_file",1);
		return;
	}
	tt = hash[delete_num];
	for(int i=0;i<sizeof(tt);i++)	
		if(tt[i][1]!="1")
		{
			delete_num++;
			call_out("check_hash",1);
			return;
		}
	to_delete = copy(tt[0][0]);
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,"DELETE FROM "+DB_FLAG+" WHERE U_Name='"+to_delete+"'",this_object(),"delete1");
	call_out("delete_failed",300);
}

void delete1(mixed ret)
{	
	remove_call_out("delete_failed");
	BBS_D->add_Bbs_Up_Map(FILE_DB_NAME,"DELETE FROM "+DB_DATA+" WHERE U_Name='"+to_delete+"'",this_object(),"delete2");
	call_out("delete_failed",300);
}

void delete2(mixed ret)
{	
	remove_call_out("delete_failed");
	delete_num++;
	call_out("check_hash",0);	
}

void delete_failed()
{
	remove_call_out("delete_file");
	remove_call_out("check_hash");
	remove_call_out("delete_back");
	delete_busy = 0;
	call_out("delete_file",TICK_TIME);		
}

void delete_back(mixed ret)
{		
	if(!ret || !sizeof(ret))
	{
		call_out("delete_file",TICK_TIME);
		return;
	}
	hash = unique_array(ret,(:$1[0]:));
	delete_num = 0;
	delete_busy = 1;
	call_out("check_hash",0);
}
//////////////////////�����ֽ���//////////////////////////////////////////

void remove(string id)
{
	if( id!="ciwei" && (delete_busy!=0 || stas!=0 || d_stas!=0) )
	{
		log_file("static/super_ftp","�ļ��쳣���棺�����ϴ��������ػ��߼����µĹ����г�������������漰�����ļ���"+name+" and "+d_file,this_object());
		error("��Ƥ��������");
	}
}

int help(object me)
{
	write("
�ӿ���վ�����ļ�������վ
ָ���ʽ: ucp <�ļ���> <ԭ��>

ע�⣺������å "+implode(allow, " ")+" ר�ã�
ucp �Ժ��� update ����վ��Ӧ���򣬲����߹۲�����һСʱ��
������Լ����������ļ�û���㹻�İ��գ�����ʹ�ñ��������
���û���㹻��ʱ��۲죬����ʹ�ñ��������
����������⣬�������������˳Է���

�򵥵�˵���¸���ԭ��
"
	);
	return 1;
}