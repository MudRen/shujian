inherit F_DBASE;
#include <ansi.h>
#include <mudlib.h>

nosave mapping valid_login = ([
	// ��վ��ʦ
           "master":    ({ "222", "124.", "58.","116" }),                 
           "hongba":    ({ "222", "124.", "218.","116" }),                 
 
       	]);

void add_site(string id, string addr)
{
	if (!stringp(id) || !stringp(addr)) return;
	if (arrayp(valid_login[id])) valid_login[id] += ({ addr });
	else valid_login[id] = ({ addr });
}

void del_site(string id, string addr)
{
	if (!stringp(id) || !stringp(addr)) return;
	if (arrayp(valid_login[id])) valid_login[id] -= ({ addr });
}

string *query_site(string id)
{
	if (stringp(id)) return valid_login[id];
	return 0;
}

int is_valid(string id, string ip)
{
	int i;
	int ip1, ip2;

	if (sscanf(ip, "%d.%d.%*d.%*d", ip1, ip2) != 4) return 0;

	// �ڲ�����ַ YUJ@SJ 2002-01-30
	if (ip1 == 10) return 1;
	if (ip1 == 172 && ip2 & 240 == 16) return 1;
	if (ip1 == 192 && ip2 == 168) return 1;

	if (undefinedp(valid_login[id+"@"+INTERMUD_MUD_NAME])) {
		if (undefinedp(valid_login[id])) {
			if (!wiz_level(id)) return 1;
			write("��ʦ�����е�ַ���ƣ����� guest ��¼֪ͨ����\n");
			destruct(this_object());
			return 0;
		}
	} else id += "@"+INTERMUD_MUD_NAME;
	i = sizeof(valid_login[id]);
	while (i--) if (sscanf(ip, valid_login[id][i] + "%*s")) return 1;
	destruct(this_object());	// �Զ��ݻ��Լ�������YUJIP�ı�ˢ��
	return 0;
}

mapping valid_multi = ([
	"":		0,
]);

int is_multi(string id, string ip, string port)
{
	object *usr;
	string *site = keys(valid_multi);
	int i, login_cnt = 0;
	string ipname = IP_D->ip2name(ip);

	if (query(ip) && query(ip) != port) {
		write("���ĵ�ַ�����˵�¼����Ȼ����ԡ�\n");
		return 1;
	}
	set(ip, port);
	call_out("delete", 10, ip);
	usr = filter_array(users(), (: environment :));
	i = sizeof(usr);
	while (i--) {
		if (query_ip_number(usr[i]) != ip) continue;
		if (usr[i]->query("id") != id) {
/*
			if (wiz_level(id)) {
				write("�Բ������ĵ�ַ�Ѿ���������ߣ���ֹ��¼��\n");
				return 1;
			}
			if (wiz_level(usr[i])) {
				write("�Բ������ĵ�ַ�Ѿ�����ʦ���ߣ���ֹ��¼��\n");
				return 1;
			}
*/
			login_cnt++;
		}
	}
	write(CSI "20D���� IP �ǣ�" HIW + ip + ":" + port + "(" + ipname + ")" NOR
		"���˵�ַ����" + chinese_number(login_cnt)+"λ������ߡ�\n");
	if (ipname == "δ֪"){
		message("wizard:spiderii", id + " " + ip + "\n", usr);
		message("wizard:server", id + " " + ip + "\n", usr);
	}
//	if (!login_cnt) return 0;
// By Spiderii ����IP����
       if (login_cnt > 8)
	{
		write("�Բ�����Ŀǰ�ĵ�ַ�ѵ����������ƣ����˳�����ID�Ա��½��\n");
           return 1;
      }

	i = sizeof(valid_multi);
	while (i--) if (sscanf(ip, site[i] + "%*s")) break;
	if (i < 0) {
		write("�Բ�����Ŀǰ�ĵ�ַ��ֹ���ص�¼��������ʦ��ϵ��\n");
		return 1;
	}
	if (!(i = valid_multi[site[i]])) return 0;
	if (login_cnt < i) return 0;
	write("�Բ�����Ŀǰ�ĵ�ַ�ѵ����������ƣ�������ʦ��ϵ��\n");
	return 1;
}
