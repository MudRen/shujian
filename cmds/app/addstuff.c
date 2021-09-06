// adstuff.c
// by snowman@SJ 20/05/1999

#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	object ob;
	mapping obs;
	string *name;
	int num = 1;

	if (!arg) {
		obs = TASK_D->query_stuffs();
		if (sizeof(obs) < 1)
			return notify_fail("û���κ���Ʒ��\n");
		name = keys(obs);
		foreach (string item in name)
			write(sprintf("%-40s %4d\n", item+"("+obs[item]["id"]+") ", obs[item]["reward"]));
		return 1;
	}
	if (sscanf(arg, "%d %s", num, arg) != 2)
		return help(me);

	if (num <= 0) {
		if (TASK_D->delete_stuff(arg))
			return notify_fail("�㽫 "+arg+" �� task_stuffs ��ɾ��....Ok��\n");
		return notify_fail("�� "+arg+" ��TASKD.C ��ɾ��ʧ�ܡ�\n");
	}

	if (!objectp(ob = present(arg, environment(me))))
		if( !objectp(ob = present(arg, me)))
		       return notify_fail("����û�������Ʒ��\n");

	if (ob->is_character())
		return notify_fail("�����һ�㣬�ǿ�������Ŷ��\n");

	if (file_size(base_name(ob)+".c") <= 0 )
		return notify_fail("�Բ��𣬴���Ʒ��Դ�ļ��Ѿ��������ˡ�\n");

	if (TASK_D->set_stuff(ob->query("name"), ([ "id" : ob->query("id"), "reward" : num ]) ))
		return notify_fail("�㽫"+ob->name()+"("+ob->query("id")+") ��EXP = "+num+" ���뵽 task_stuffs ��....Ok��\n");

	return notify_fail("TASK_D ���Ѿ����˴˼���Ʒ����Ҫ��������ɾ��\n");
}

int help(object me)
{
write(@HELP
ָ���ʽ��

adstuff <����> <��Ʒ>

����Ϊ��ֵ֮EXP��
�������Ϊ�㣬��ɾ������Ʒ��

by snowman@SJ 20/05/1999

HELP
    );
    return 1;
}

