// shutdown.c

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");

	message( "system", "��Ϸ�������������Ժ�һ������ login ��\n", users() );

    user = filter_array(objects(), (: userp :));
	for(i=0; i<sizeof(user); i++) {
		reset_eval_cost();
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	log_file("static/CRASHES", geteuid(me) + " shutdown " + MUD_NAME + " on: "
		+ ctime(time()) + "\n");
	write_file("/log/static/LASTCRASH", geteuid(me) + " shutdown " + MUD_NAME + " on: "
		+ ctime(time()) + "\n", 1);

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(-1);
	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: shutdown
 
������������Ϸ��
HELP
);
        return 1;
}
 
