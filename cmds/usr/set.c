// set.c
//������kill_msg���Լ�����ɫ LINUX@SJ 2003.0908

#include <ansi.h>
#include <database.h>

#define MAX_ENV_VARS 20

int help();

string *wiz_only = ({"invisibility", "immortal", "no_fight", "msg_min", "msg_mout", "msg_clone", "msg_dest"});
string *color_setting = ({"kill_msg","protect_msg"});

int main(object me, string arg)
{
	string term, *terms;
	mixed data;
	mapping env;


	env = me->query("env");

	if (!arg) {
		if (!sizeof(env))
			write("��û���趨�κλ���������\n");
		else {
			write("��Ŀǰ�趨�Ļ��������У�\n");
			terms = sort_array(keys(env), 1);
			foreach (string item in terms)
				write(sprintf("%-20s %O\n", item, env[item]));
		}
		return 1;
	}

	if (sscanf(arg, "%s %s", term, data) != 2) {
		term = arg;
		data = "YES";
	}

	term = replace_string(term, "/", "");
	if (term != "") {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
		if (strlen(term) > 20)
			return notify_fail("����Ļ�������̫���ˡ�\n");
		if (!wiz_level(me) && member_array(term, wiz_only) != -1)
			return notify_fail("ֻ����ʦ��������趨��\n");
		if(member_array(term, wiz_only) != -1  && data || member_array(term, color_setting) != -1) {
			data = replace_string(data, "$RED$", RED);
			data = replace_string(data, "$GRN$", GRN);
			data = replace_string(data, "$YEL$", YEL);
			data = replace_string(data, "$BLU$", BLU);
			data = replace_string(data, "$MAG$", MAG);
			data = replace_string(data, "$CYN$", CYN);
			data = replace_string(data, "$WHT$", WHT);
			data = replace_string(data, "$HIR$", HIR);
			data = replace_string(data, "$HIG$", HIG);
			data = replace_string(data, "$HIY$", HIY);
			data = replace_string(data, "$HIB$", HIB);
			data = replace_string(data, "$HIM$", HIM);
			data = replace_string(data, "$HIC$", HIC);
			data = replace_string(data, "$HIW$", HIW);
			data = replace_string(data, "$NOR$", NOR);
			data = data + NOR;
		}
		sscanf(data, "%d", data);
		if(strlen(data) > 80)
			return notify_fail("�Բ������趨�ı���ֵ̫���ˣ����һ�㡣\n");
		/*if (term == "kill_msg")
			BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "
			INSERT INTO mud_nick (utime, content, name, userid, type, site) 
			values (
			'" + time() +"',
			'" + data + "',
			'" + me->query("color") + me->query("name") +"',
			'" + me->query("id") + "',
			'kill_msg',
			'"+ lower_case(INTERMUD_MUD_NAME) + "')");*/			
		if (data)
			me->set("env/" + term, data);
		else
			me->delete("env/" + term);
		write(sprintf("�趨����������%s = %O\n", term, data));
		return 1;
	}
	return help();
}

int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]

���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��

ȡ�������趨���� unset ָ�

�������Щ�������������趨����� help settings��
TEXT
);
	return 1;
}
