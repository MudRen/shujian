
#include <ansi.h>
#define SYNTAX  "ָ���ʽ��changemail <ĳ��> <������>\n"
inherit F_CLEAN_UP;


int main(object me, string str)
{
	string name, mail,oldmail;
	mixed ret;
 	       
	if(!str || sscanf(str, "%s %s", name, mail)!=2 )
		  return notify_fail(SYNTAX);
        
	ret = dbquery("SELECT U_Email FROM Users WHERE U_Username=\"" + name + "\"");

	if (!ret)
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 1;
	}

	if (sizeof(ret) < 1) {
		write(HIY "û�������ҡ�\n"NOR);
		return 1;
	}
	else
	{
	        oldmail = ret[0][0];
	        
		ret = dbquery ("UPDATE Users set U_Email = \"" + mail + "\" where U_Username = \"" + name+ "\"");
		if (!ret)
		{
			write("����������ݿ�ʧ�ܡ�\n");
			return 1;
		}
		else
		{
			write("��� " + name + " �������Ѿ��� " + oldmail + " ����Ϊ " + mail + " ��\n");
			log_file("static/CHANGEEMAIL",
			sprintf("%s  �� %s(%s) �޸������� %s ��� %s ��\n",
				name, (string)me->query("name"),me->query("id"), oldmail,mail
			), ({ me }) );
		}
	}

	return 1;
}



int help(object me)
{
	write(@HELP
ָ���ʽ��changemail <ĳ��> <������>
����������ָ�����һ����䡣
HELP
	);
	return 1;
}
