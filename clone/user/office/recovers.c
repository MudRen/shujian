// recovers.c
// �ָ���ɱ���

#include <ansi.h>

string do_auto(object me, string arg)
{
        object ob;
        int *file_info;

        seteuid(ROOT_UID);
	if (file_size("/data/login/" + arg[0..0] + "/" + arg + ".ooo") < 0)
		return HIR + arg + " �ĵ�¼���ݵ�����ɾ�����޷��ָ���\n"NOR;
        if (file_size("/data/user/"+ arg[0..0] + "/" + arg + ".ooo")<0)
                return arg + " �ĵ�������û�б����ϣ�\n";

	ob = find_player(arg);
	if (ob) {
		tell_object(ob, BLINK HIR"\n\n\n\t�������ڸ����ָ������У���������Ӻ��¼��\n\n"NOR);
		"/cmds/usr/quit"->main(ob);
	}

	if (cp("/data/login/" + arg[0..0] + "/" + arg + ".ooo", "/data/login/" + arg[0..0] + "/" + arg + ".o") <=0)
		return "��½�ļ�����ʧ�ܣ�\n";

	file_info = stat("/data/user/"+ arg[0..0] + "/" + arg + ".ooo");
	if (cp("/data/user/" + arg[0..0] + "/" + arg + ".ooo","/data/user/" + arg[0..0] + "/" + arg + ".o") <=0)
		return "�����ļ�����ʧ�ܣ�\n";
	write("�����Ѿ��ָ���ϣ�����"HIW"��¼"NOR"���̣�\n");
//log to recover_suicide
	log_file("static/recover_suicide",sprintf("%s %s�ָ�(%s)[��ɱ��%s]��\n",ctime(time()),geteuid(me),arg,ctime(file_info[1])));
        write(arg + " ����ɱ���ݻָ���ϣ�\n");
        return "�ָ���� "+ arg +" �ɹ���\n";
}

string *help()
{
	return ({"recovers [id]","�����Զ��ָ���ɱ����ҡ�"});
}
