// MarryMessage.c Look@SJ 19990916

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int invi;
int help(object me);

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object obj;

	if (!stringp(me->query("marry/id")))
	{
		return help(me);
	}
	
	obj = LOGIN_D->find_body(me->query("marry/id"));

	if (!obj)
	{
		return notify_fail("��İ������ڲ��ڡ�\n");
	}
	if (!interactive(obj))
	{
		return notify_fail("��İ������ڶ����ˡ�\n");
	}
	
	if (!arg)
	{
		if((string)me->query("gender") == "Ů��")
		{
			write(MAG"���ô˼����" + me->query("marry/name") + "��......\n"NOR);
	 		tell_object(obj, sprintf(MAG"��İ���" + obj->query("marry/name") + "��˼����......\n" NOR));
		}
        else
		{
			write(MAG"���ô˼���" + me->query("marry/name") + "�����������˽��ںη���......\n"NOR);
	 		tell_object(obj, sprintf(MAG"��ķ��" + obj->query("marry/name") + "��˼����......\n" NOR));
		}
	}
	else
	{
		switch (arg)
		{
		case "kiss":
			if (objectp(present(me->query("marry/id"), environment(me))))
			{
				message_vision(MAG "$Nӵ����$n�����һ��......\n"NOR, me, obj);
			}
			else
			{
				write(MAG "�����ӵ�����" + me->query("marry/name") + "�����һ��......\n" NOR);
				tell_object(obj, sprintf( MAG "���%s����ӵ���㣬���������һ��......\n" NOR,
					obj->query("marry/name")));
			}
			break;	
		case "bye":
			if (objectp(present(me->query("marry/id"), environment(me))))
			{
				message_vision(MAG "$N����������$n�����ʵ�: ��Ҫ�뿪�ˣ�"
					"��ʱ���ܳ���۲�����ѽ......\n"NOR, me, obj);
			}
			else
			{
				if (me->query("gender")=="Ů��")
				{
					write(MAG "������ٿ���ķ��" + me->query("marry/name") + "һ�ۣ�"
						"����֪������������һֱ�������...\n"NOR);
					tell_object(obj, MAG "��İ���" + obj->query("marry/name") 
						+ "�����ٶ࿴��һ�ۣ�ɽңˮ��������һֱ�ǹ���ģ���Ҫ�Լ����ذ�......\n" NOR);
				}
				else
				{
					write(MAG "������ٿ���İ���" + me->query("marry/name") + "һ�ۣ�"
						"����֪������������һֱ�������...\n");
					tell_object(obj, MAG"��ķ��" + obj->query("marry/name") 
						+ "�����ٶ࿴��һ�ۣ�ɽңˮ��������һֱ�ǹ���ģ���Ҫ�Լ����ذ�......\n"NOR);
				}
			}
			break;
		default:
			write(MAG "�����ĸ������" + me->query("marry/name") + "��" HIM + arg + "\n" NOR);
			message("channel", sprintf(MAG "���%s���ĸ����㣺" HIM "%s\n" NOR,obj->query("marry/name"), arg), obj);
			break;
		}
	}

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��mm [ѶϢ]

	����������ָ�����İ���˵���Ļ���
HELP);
	return 1;
}
