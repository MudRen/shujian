// recovers.c
// Created by Numa 19990906
// Modified by Numa 19990926
// Modified by Numa 19991120 �޸�������������ʱ�ָ����ɹ���bug
// modify by snowman@SJ 26/02/2000 ����log file��λ��
// modify by looklove 29/07/2000 �޸Ĳ��ַ�����Ϣ
// modify by looklove 2001-7-5 ����֪ͨ�ż� & ��ֹ�ָ���ɾ��ID��s -f����

inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>

private int update_player(object me);
int help(object me);

void create()
{
	seteuid(getuid());
}

int main(object me,string arg)
{
	object ob;
	string nod, msg;
	int *file_info;

	if (!arg) return help(me);
	me = this_player(1);
	if (sscanf(arg,"%s %s", arg, nod) != 2) {
		if (file_size("/data/user/"+ arg[0..0] + "/" + arg + ".ppp")>0) //add by looklove, ����ָ���ɾ����ID ��
			return notify_fail(arg + " ��id�Ǳ�ɾ����id����� -p ������\n");
		if (file_size("/data/login/" + arg[0..0] + "/" + arg + ".ooo") < 0)
			return notify_fail(arg + " �ĵ�¼�������ݲ����ڣ��޷��ָ���\n");
		if (file_size("/data/user/"+ arg[0..0] + "/" + arg + ".ooo")<0)
			return notify_fail(arg + " �����ݵ������ݲ����ڣ��޷��ָ���\n");

		rename("/data/login/" + arg[0..0] + "/" + arg + ".ooo", "/data/login/" + arg[0..0] + "/" + arg + ".o");

		file_info = stat("/data/user/"+ arg[0..0] + "/" + arg + ".ooo");
		rename("/data/user/" + arg[0..0] + "/" + arg + ".ooo", "/data/user/" + arg[0..0] + "/" + arg + ".o");
		//log to recover_suicide
		log_file("static/recover_suicide",
			sprintf("%s�ָ�(%s)[��ɱ��%s]��\n",
				geteuid(me),arg,ctime(file_info[1])
			), me, ({ arg })
		);
		write(arg + " ����ɱ���ݻָ���ϣ�֪ͨ�ż������С���\n");

		//����֪ͨ�ż�
		msg =   ""+arg+ "�����ã�\n"+
			"    �ܸ���֪ͨ��������"+CHINESE_MUD_NAME+"����ɱID�Ѿ��ָ�����ӭ����������������Ϸ��\n"+
			"��������κ�����ͽ��飬������ڷ�վ����ʦ��ϵ���á�wizlist��ָ�����\n"+
			"�鿴���ǵ�ID��\n"+
			"\n"+
			"\n"+
			"����\n"+
			"				�齣��ʦ��\n"+
			"\n"+ctime(time());

		SMTP_D->send_mail(me,arg,"֪ͨ�ʼ�",msg);
	} else {
		if (nod != "-p") return help(me);
 if (geteuid(me) != "hongba" && geteuid(me) != "master")
return notify_fail("��֪ͨ8�ܻ���ܡ�\n");
		if (file_size("/data/login/" + arg[0..0] + "/" + arg + ".ppp") < 0)
			return notify_fail(arg + " �ĵ�¼�������ݲ����ڣ��޷��ָ���\n");
		if (file_size("/data/user/"+ arg[0..0] + "/" + arg + ".ppp")<0)
			return notify_fail(arg + " �����ݵ������ݲ����ڣ��޷��ָ���\n");

		rename("/data/login/" + arg[0..0] + "/" + arg + ".ppp","/data/login/" + arg[0..0] + "/" + arg + ".o");

		file_info = stat("/data/user/"+ arg[0..0] + "/" + arg + ".ppp");
		rename("/data/user/" + arg[0..0] + "/" + arg + ".ppp","/data/user/" + arg[0..0] + "/" + arg + ".o");
		//log to recover_purge
		log_file("static/recover_purge",
			sprintf("%s�ָ�(%s)[ɾ����%s]��\n",
				geteuid(me),arg,ctime(file_info[1])
			), me, ({ arg })
		);
		write(arg + " ��ɾ�����ݻָ���ϣ�ϵͳ���ڷ���֪ͨ�ż���\n");

		//����֪ͨ�ż�
		msg =   ""+arg+ "�����ã�\n"+
			"    ����"+CHINESE_MUD_NAME+"��ɾ����ID�Ѿ��ָ�����ӭ����������������Ϸ��\n"+
			"��������κ�����ͽ��飬������ڷ�վ����ʦ��ϵ���á�wizlist��ָ�����\n"+
			"�鿴���ǵ�ID��\n"+
			"    ���á�help rules��ָ��鿴��Ϸ���򣬲���ע�����ء�лл��\n"+
			"\n"+
			"\n"+
			"����\n"+
			"				�齣��ʦ��\n"+
			"\n"+ctime(time());

		SMTP_D->send_mail(me,arg,"֪ͨ�ʼ�",msg);
	}
	if (ob = LOGIN_D->find_body(arg))
		update_player(ob);
	return 1;
}

private int update_player(object me)
{
	object env, link_ob, obj;

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	if (!link_ob) {
		destruct(me);
		return 0;
	}
	link_ob->restore();
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Exec the player to his/her link object.
	exec(link_ob, me);
	env = environment(me);

	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	tell_object(obj, "������ݻָ���ϡ�\n");
	obj->write_prompt();
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : recovers <Ŀ��ID> [-p]

���ָ������Զ��ָ���ɱ����ҡ�
���� -p ������ purge ���лָ���

HELP
);
	return 1;
}
