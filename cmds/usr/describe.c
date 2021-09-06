// describe.c
#include <database.h>
#include <ansi.h>


int main(object me, string arg)
{
	int i;
	string *txt;

	if( !arg ) return notify_fail("ָ���ʽ��describe <����>\n");
	if (arg == "none") {
		me->delete("long");
		write("\n���������Ѿ�ɾ���ˡ�\n");
		return 1;
	}

	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	txt = explode(arg, "\n");
	if ((i = sizeof(txt)) > 8)
		return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");
	while (i--)
		if (strlen(strip(txt[i])) > 80)
			return notify_fail("�뽫�����Լ�������������ÿ����ʮ���������ڡ�\n");

	arg = implode(txt, "\n") + NOR "\n";
	
	me->set("long", arg);
	arg = replace_string(arg,"\n","<br>");
	BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "
	INSERT INTO mud_nick (utime, content, name, userid, type, site) 
	values (
	'" + time() +"',
	'" + arg + "',
	'" + me->query("color") + me->query("name") +"',
	'" + me->query("id") + "',
	'describe',
	'"+ lower_case(INTERMUD_MUD_NAME) + "')");
	write("\n�����Լ���������������ˡ�\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��describe <����>|none

���ָ�������趨�������� look ָ���ʱ�������������ͨ������
����������һ��ʱ������ to describe �ķ�ʽ�����롣
TEXT
	);
	return 1;
}
