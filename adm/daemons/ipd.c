// ipd.c 
// Created by mxzhao 2004/05/15
// 

// �ļ���ʽ��
// 4.11.0.0|4.11.255.255|����|������
// 
// ˵��: һ��Ϊһ��IP��Ԫ�����ٵ�ָ��ǰ�������ʼIP�ͽ���IP
//       

#include <ansi.h>

#define IP_MIN		0
#define IP_MAX		255

void create()
{
	seteuid(getuid());
}

private string fullip(string ip)
{
	string *ips = explode(ip, ".");

	if (sizeof(ips) != 4 
		|| atoi(ips[0]) < IP_MIN || atoi(ips[0]) > IP_MAX
		|| atoi(ips[1]) < IP_MIN || atoi(ips[1]) > IP_MAX
		|| atoi(ips[2]) < IP_MIN || atoi(ips[2]) > IP_MAX
		|| atoi(ips[3]) < IP_MIN || atoi(ips[3]) > IP_MAX)
	{
		return 0;
	}

	return sprintf("%03s.%03s.%03s.%03s", ips[0], ips[1], ips[2], ips[3]);
}

private varargs int update_ip_list(string arg, int start, int count)
{
	string str;
	int i;
	int end;

	if ( !arg )
	{
		return 0;
	}

	if (file_size(arg) < 0)
	{
		write("�ļ�" + arg + "�����ڡ�\n");
		return 0;
	}

	if (start < 0)
	{
		start = 0;
	}

	if (count < 0)
	{
		count = 0;
	}

	i = start>0?start:1;
	end = i + count;

	for ( ; stringp(str = read_file(arg, i, 1)); i++)
	{
		string *sline = explode(replace_string(
			replace_string(str, "\n", ""), "||", "|"), "|");
		
		string sname = "";
		int nline = sizeof(sline);

		if (count > 0 && i>=end)
		{
			break;
		}

		if (nline < 2)
		{
			write(sprintf("%s��%d�д��������: %s\n", arg, i, str));
			continue;
		}

		if (!stringp(sline[0] = fullip(sline[0]))
			|| !stringp(sline[1] = fullip(sline[1])))
		{
			write(sprintf("%s��%d�д��������: %s\n", arg, i, str));
		}

		for (int j=2; j<nline; j++)
		{
			sname += sline[j];
		}

		dbquery("REPLACE ipdata SET startip =" + save_variable(sline[0])
			+ ", endip =" + save_variable(sline[1]) 
			+ ", ipname =" + save_variable(sname));
	}

	write(arg + "�ļ�������ϡ�\n");

	return 1;
}

varargs int update_ip(object me, string arg, int start, int count)
{
	if ( !arg )
	{
		return 0;
	}

	if (SECURITY_D->get_status(me) != "(admin)" )
	{
		return 0;
	}

	arg = resolve_path(me->query("cwd"), arg);
	
	if (file_size(arg) == -2)
	{
		mixed *files;
		
		if (start < 1)
		{
			start = 1;
		}
		
		if (count <= 0)
		{
			count = 10;
		}
		
		arg += "/";
		files = get_dir(arg);
		
		for (int i=start-1; i<(start+count-1) && i<sizeof(files); i++)
		{
			update_ip_list(arg + files[i]);
		}
	}
	else if (file_size(arg) == -1)
	{
		write("����ļ������ڡ�\n");
		return 0;
	}
	else
	{
		update_ip_list(arg, start, count);
	}

	write("IP��Ϣ������ϡ�\n");

	return 1;
}

string ip2name(string addr)
{
	string sip = fullip(addr);

	if (stringp(sip))
	{
		mixed ret = dbquery("SELECT ipname FROM ipdata WHERE " 
			+ save_variable(sip) + " BETWEEN startip AND endip ");

		if (sizeof(ret) == 1)
		{
			return ret[0][0];
		}
	}
	else 
	{
		return "����";
	}

	return addr;
}

