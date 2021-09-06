// leitaiuser.c
// by snowman@SJ
// Modify by yuj@SJ 22/02/2000
// modify by augx@sj  10/29/2001
// Modify by yuj@SJ 19/12/2001

#include <ansi.h>
#include <user.h>

inherit CHARACTER;
inherit F_SAVE;

nosave int last_age_set;
string userid;

void quit();

varargs void create(string arg)
{
	::create();
	set_name("��̨�������", ({ arg }) );
	userid = arg;
}

int save() { return 0; }
int set_leader(object ob){ return 0; }

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	if (!stringp(userid)) return 0;
	return sprintf(DATA_DIR "user/%c/%s", userid[0], userid);
}

void die()
{
	string fam, color;
	object me, ob;

	me = this_object();
	ob = query_temp("last_damage_from");
	if (!living(me))
		revive(1);
	remove_all_killer();
	all_inventory(environment())->remove_killer(me);
	if (objectp(ob)) {
		if( !living(ob) ) ob->revive(1);
		ob->remove_all_killer();
		all_inventory(environment())->remove_killer(ob);
	}
	fam = query("family/family_name")?query("family/family_name"):"��ͨ����";
	color = query("color")?" "+query("color"):" ";
	fam = fam + color + query("name") + NOR + "(" + capitalize(query("id")) + ")";
	if (objectp(ob)) {
		environment(me)->end_fight(me, ob, fam);
		ob->quit();
	}
	quit();
}

void quit()
{
	object ob = this_object();
	object link_ob;

	link_ob = query("link_ob");
	if (query_temp("leitai"))
		message_vision("\n$N�˳�����̨��\n\n", ob);
	if (environment()->query_temp("leitai") > 0)
		environment()->add_temp("leitai", -1);

	if (objectp(link_ob)) {
		link_ob->delete_temp("apply/short");
		tell_room(environment(link_ob), link_ob->query("name")+"����̨������������\n");
		if (!query_temp("netdead")) {
			if (wizardp(ob))
				tell_object(ob, "��Ļ��ǻص��Լ������ϡ�\n");
			exec(link_ob, ob);
			link_ob->force_me("look");
		} else {
			link_ob->set_temp("netdead", query_temp("netdead"));
			"/cmds/usr/quit"->main(link_ob);
		}
	}

	seteuid(ROOT_UID);
	destruct(ob);
}

private void net_dead()
{
	object ob = query_temp("link_ob");

	set_temp("netdead", uptime());
	set_heart_beat(0);
	tell_room(environment(), query("name") + "�����ˡ�\n");
	if (ob)
		destruct(ob);
	die();
}

void reconnect()
{
	object ob = query("link_ob");

	set_heart_beat(1);
	delete_temp("netdead");
	tell_object(this_object(), "����������ϡ�\n");
	if (ob)
		ob->set_temp("link_ob", query_temp("link_ob"));
}
