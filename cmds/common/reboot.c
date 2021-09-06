// shutdown.c with time loop.
// by snowman@SJ  22/02/1999
// Modify BY LInux for �����

#include <ansi.h>
#include <mudlib.h>
#include <net/daemons.h>

int counting = 0;
int min;

int help (object me)
{
	write(@HELP
ָ���ʽ: reboot < min|now >

����
	reboot       :  ��ʾĿǰ����Ϣ�����û��reboot���У���ʾ����Ϣ��
	reboot now   :  ������������Ϸ��
	reboot 3     :  �������ӣ�Ȼ����������Ϸ��
	reboot cancel:  ȡ�����𶯡�

HELP
	);
	return 1;
}

void create()
{
	seteuid(getuid());
}

private int start_shutdown()
{
	message("channel",
		HIW"\n\t"+CHINESE_MUD_NAME+HIW"���� "HIR+chinese_number(min)+HIW" ���Ӻ���������\n"
		"\tΪ�˱��ⲻ��Ҫ�ĵ���������������Ҿ��������˳���\n\n" NOR, users()
	);
	call_out("countdown", 60);
	counting = 1;
	return 1;
}

int main(object me, string arg)
{
	int time;

	if (geteuid(me) != ROOT_UID) {
	if (me != this_player(1))
		return 0;

	if (SECURITY_D->wiz_level("(arch)") > SECURITY_D->wiz_level(me))
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������"+CHINESE_MUD_NAME+"��\n");

	if (!arg || arg == "?") {
		if (!counting)
			return help(me);
		return notify_fail(CHINESE_MUD_NAME+HIW"���ڵ���ʱ�У���������������"HIR+ chinese_number(min) + HIW"���ӡ�\n"NOR);
	}

	if (arg == "cancel") {
		remove_call_out("countdown");
		remove_call_out("do_shutdown");
		counting = 0;
		LOGIN_D->set_wizlock(0);
		message("system","\n\t"+CHINESE_MUD_NAME+HIW"��������"HIR"ȡ��"HIW"��\n"NOR, users());
		return notify_fail(CHINESE_MUD_NAME+HIW"��������ȡ����\n"NOR);
	}
	}
	log_file("static/CRASHES", geteuid(me) + " ������ "+CHINESE_MUD_NAME+" �� "
		+ ctime(time()) + "\n", me);

	if (arg == "now") {
		LOGIN_D->set_wizlock(1);
		message("system","\n\t"+CHINESE_MUD_NAME+HIW"�������������Ժ��ٳ������ߡ�\n"NOR, users());
		call_out("do_shutdown", 1);
		return 1;
	}

	if (sscanf(arg, "%d", time) != 1
	|| time < 1)
		return help(me);

	if (counting)
		return notify_fail(CHINESE_MUD_NAME+HIW"���ڵ���ʱ�У���������������"HIR+ chinese_number(min) + HIW"���ӡ�\n"NOR);

	min = time;
	if (start_shutdown()) {
		LOGIN_D->set_wizlock(1);
		write("Starting shutdown...\n");
	} else
		write("��ʱReboot�����⣬���� /cmds/arch/reboot.c\n");
	return 1;
}

private void countdown()
{
	if (--min) {
		message("channel",
			HIW"\n\t"+CHINESE_MUD_NAME+HIW"���� "HIR+chinese_number(min)+HIW" ���Ӻ���������\n"
			"\tΪ�˱��ⲻ��Ҫ�ĵ���������������Ҿ��������˳���\n\n" NOR, users()
		);
		call_out("countdown", 60);
	} else {
		message("system",HIW"\n\t"+CHINESE_MUD_NAME+HIW"�������������Ժ��ٳ������ߡ�\n\n"NOR,users());
		call_out("do_shutdown", 1);
	}
}

private void do_shutdown()
{
	object *users, link_ob;
	int i;
	
	
	if (find_object(DNS_MASTER))
		DNS_MASTER->send_shutdown();

	users = filter_array(objects(), (: userp :));
	foreach (object user in users) {
		if (!environment(user))
			continue;
		reset_eval_cost();
		user->save();
		i = uptime() - user->query_temp("time");
		link_ob = user->query_temp("link_ob");
		if (objectp(link_ob)){
			//���������ӱ���			
			link_ob->set("last_on", time() + (i > 300 ? -30 : 0));
			link_ob->set("last_from", link_ob->query_temp("last_from"));
			link_ob->set_temp("db_quit", 1);
			//end
			link_ob->save();
			
		}
	}

	write_file("/log/static/LASTCRASH", CHINESE_MUD_NAME+"�� "
		+ ctime(time()) + " ��������\n", 1);

	shutdown(0);
}
