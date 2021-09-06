// name.c
// last modify by Look@SJ

// Modified by mxzhao 2004/02/18

inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>

int main(object me, string arg)
{
	string tmp;
	object ob = me;
	mixed ret;
//	mixed mysql;

	if( !arg )
		return notify_fail("��Ҫ��˭ȡʲô���֣�\n");

	if (sscanf(arg, "%s %s", tmp, arg) == 2) {
		if (arg == "noname")
			arg = "���ִ���";
		ob = LOGIN_D->find_body(tmp);
	}

	if (!ob)
		return notify_fail("û�������ҡ�\n");

	if (wiz_level(me) < wiz_level(ob))
		return notify_fail("�㲻�ܰ���ʦ�ȼ�����ߵ���ʦ������\n");

	if (strlen(arg) < 4)
		return notify_fail("�������̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	if (strlen(arg) > 8)
		return notify_fail("�������̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	ret = dbquery("select U_Name from Users where U_Name='" + arg + "'");

	if (!ret)
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 0;
	}

	if (sizeof(ret) > 0 && arg !="���ִ���")
	{
		write("���������ѱ�������ʹ�á�\n");
		return 1;
	}

	if (!dbquery("update Users set "
		"U_Name='" + strip(arg) + "' "
		"where U_Username='" + ob->query("id") + "'"))
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 1;
	}

	if (me != ob) 
	{
		write(HIY"�㽫"HIW+ob->name(1)+HIY"�����ָ�Ϊ"HIW+arg+HIY"��\n"NOR);
		tell_object(ob, HIY+me->name()+"��������ָ�Ϊ"HIW+arg+HIY"��\n" NOR);
	}
	else
	{
		write(HIY"�㽫�Լ������ָ�Ϊ"HIW+arg+HIY"��\n"NOR);
	}

	ob->set("name", arg);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: name [���] ����

�޸���һ��Լ������֣��������д���п۳����ٶ��ƽ�������ѡ�

HELP );
	return 1;
}
