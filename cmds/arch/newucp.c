
//�ܵÿ� v 1.0 by Ciwei@SJ 2004 5 1

#include <ansi.h>
#include <mudlib.h>
#include <database.h>

#define FILED "/adm/daemons/filed"

string* sites = ({"CQ","LN",});

string *allow = ({
	  "linux",
  	"yeju",
	//"mxzhao",
	//"yuj",
	//"mychat",//linux add
	//"tangfeng",//linux add
});

public string query_version(object ob)
{
	if(ob==find_object(BBS_D)) return "1.0";
}

string query(string arg)
{
	if (arg == "channel_id")
        	return "���;���";
}

int main(object me, string filename)
{
	//int w;
	string reascon;
	int visi = 0;
	
	me = this_player(1);
	if (member_array(geteuid(me), allow) == -1)
		return notify_fail("������å "+implode(allow, " ")+" ר�����\n");
	
	if (!filename || sscanf(filename,"%s %s",filename,reascon)!=2 )
		return notify_fail("��ʽ���ԣ���鿴������ \n");	
	
	sscanf(reascon,"%s %d",reascon,visi);
					
	if(sizeof(reascon)<8)
		return notify_fail("���ԭ�������10-30����֮�䣬����������п����ṩ��Ҳ�ѯ��\n");
	seteuid(geteuid(me));
	
	if (member_array(INTERMUD_MUD_NAME, sites ) != -1)
		return notify_fail("��ָ��ֻ���ڿ���վʹ�á�\n");
		
	filename = resolve_path(me->query("cwd"), filename);

	if ( file_size(filename) < 1)
		return notify_fail("û�� "+filename+" ����ļ������߽�ֹ�������ļ�����������һ��Ŀ¼��\n");

	if( !SECURITY_D->valid_write(filename, me, "write_file")
	|| !SECURITY_D->valid_read(filename, me, "read_file") )
		return notify_fail("Sorry����û�ж�д "+filename+" ����ļ���Ȩ����\n");
	
	if(!read_file(filename))
	{
		return notify_fail("�ļ�̫�󣬻��������쳣�����ֶ����¡�\n");
	}
	FILED->add_file(filename,getuid(me),reascon);	
	//�ļ��� ����ԭ�� ʱ�� ������
		
        if( visi ) write("�����¼�¼��\n");
	else
	{
		CHANNEL_D->do_channel(this_object(),"sys","��ʼ����"+filename+"��������վ�����ڴ�������Ժ��ڸ���վ�����¡�");
		if(!BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,"INSERT INTO updatelog( id , filename , reason , username , dateline ) VALUES ('','"+filename+"','"+reascon+"','"+getuid(me)+"',"+time()+")" ,0,0))
		tell_object(me,"������̳�ļ����ͼ�¼ʧ�ܣ���������������̳����Ա��ϵ��\n");
	}
	return 1;
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
