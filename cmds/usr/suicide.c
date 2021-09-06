// suicide.c

#include <ansi.h>
#include <command.h>

int main(object me, string arg)
{
	if (wiz_level(me)) {
		return notify_fail("��ʦ�����������ɱ���������ʱ��ʲô�벻���ģ����Ƕ�ʹ�����İɡ�\n");
	}

	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");

	if( !arg || arg != "-f") {
		write("���� suicide -f ȷ����ɱ��\n");
		return 1;
	}

	if (me->is_ghost()) return notify_fail("�����ɱ��û��˵����\n");
	if (environment(me)->query("no_fight"))
		return notify_fail("�����ƺ�û����ɱ��������\n");

	if (!me->query_temp("link_ob"))
		return notify_fail("�㲻���������߽���ģ�������ɱ��\n");

	write(
		"ѡ����ɱ��ζ�������������Ͼ���Զɾ���ˣ�����ؿ��������\n"
		"ȷ���Ļ��������������룺");
	input_to("check_password", 1, me, 1);
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}

	if (forever) {
		tell_object( me, HIR "\n�����Ҫ��ɱ�ˣ���������ˡ�\n\n" NOR);
//		if (!wiz_level(me)) CHANNEL_D->do_channel(this_object(),"rumor",me->short(1) + "����Ҫ��ɱ�ˡ�");
		me->set_temp("suicide_countdown", 6);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :),
			(: call_other, this_object(), "halt_suicide" :) );
	}
}

private int slow_suicide(object me)
{
	object link_ob;
	int stage;
string name;
	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;
name = me->query("id");
	stage = me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
			tell_object(me, HIR "�㻹��" + chinese_number(stage+stage) + "�������ʱ�䣬��ֹͣ���� halt��\n" NOR);
		return 1;
	}

	log_file("static/SUICIDE",
		sprintf("%s suicide on %s\n", geteuid(me), ctime(time())) );
           rm(DATA_DIR + "career/" + name[0..0] + "/" + name + ".o");
	seteuid(getuid());
	write("�ðɣ�������:)��\n");
	if (me->query("g_title") && me->query("g_level") == 1)
		log_file( "group", sprintf("%s %s ��ɢ��%s ( %s ) ��ɱ��\n", ctime(time())[4..19],
			me->query("g_title"), me->query("name"), me->query("id")));
	if( !wiz_level(me) ) {
		int i;
		object *inv = all_inventory(me);

		for(i=0; i<sizeof(inv); i++)
			if (inv[i]->query("money_id")) destruct(inv[i]);
			else if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
		me->delete("balance");
	}
	if (wiz_level(me)) {
		link_ob->save();
		me->save();
		cp(link_ob->query_save_file() + SAVE_EXTENSION, link_ob->query_save_file() + ".ooo");
		rename(me->query_save_file() + SAVE_EXTENSION, me->query_save_file() + ".ooo");
        } else if (me->query("combat_exp") < 100000) {
		rm(link_ob->query_save_file() + SAVE_EXTENSION);
		rm(me->query_save_file() + SAVE_EXTENSION);
	} else {
		link_ob->set("last_on", time()+86400);
		link_ob->save();
		if (!environment(me)->query("no_save"))
			me->set("startroom", base_name(environment(me)));
		me->add("combat_exp", -me->query("combat_exp")/10);
		me->save();
		rm(link_ob->query_save_file() + ".ooo");
		rm(me->query_save_file() + ".ooo");
//		rename(link_ob->query_save_file() + SAVE_EXTENSION, link_ob->query_save_file() + ".ooo");
//		rename(me->query_save_file() + SAVE_EXTENSION, me->query_save_file() + ".ooo");
	}
	tell_room(environment(me), me->name() +
		"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));
//	if (!wiz_level(me)) CHANNEL_D->do_channel(this_object(),"rumor",me->short(1) + "��ɱ�ˣ��Ժ�����Ҳ������������ˡ�");
	destruct(link_ob);
	destruct(me);
	return 0;
}

int halt_suicide(object me)
{
	tell_object(me, "���������ɱ����ͷ��\n");
	if (!wiz_level(me)) {
//		CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + "���������¸ҵػ���ȥ��");
                me->start_busy(6);
	}
	notify_fail("�������˳�ʱ��ĳ�˼֮�С�\n");
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: suicide [-f]

�����Ϊĳ��ԭ���㲻����ˣ������ѡ����ɱ��

suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ��������������ȷ����ݡ�

ϵͳ��Ծ��� 20K ������֮������Ͻ����Զ����沢��ȥ 10% �ľ������Ӧ�ĵȼ��� 
ͬʱû�����вƲ���������ѡ�� :)
HELP
);
	return 1;
}
