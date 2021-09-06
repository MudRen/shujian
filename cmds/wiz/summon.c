// summon command..
// Modify by snowman@SJ 17/02/2000
// check if ob is a leitaiuser.

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int s = 0;

	if (!str) return notify_fail("<Syntax>: summon <player id>\n");
	if (sscanf(str, "-s %s", str)) s = 1;
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("��... ���������\n");
	if( wiz_level(ob) > wiz_level(me) )
		return notify_fail("���޴�Ȩ��\n");
	if (ob->query("env/invisibility") > 10000)
	return notify_fail("��... ���������\n");
	if (environment(ob) == environment(me))
		return notify_fail(ob->name() + "��������ߡ�\n");
	if (environment(ob)) {
	if (environment(ob)->query("no_summon_out"))
		return notify_fail(ob->name() + "���������⣬������Summonץ������\n");
	if (environment(me)->query("no_summon_in"))
		return notify_fail("��Ŀǰ�������⣬������Summon���\n");
	}

	if (base_name(ob) == "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name() + "�����Ǳ�����̨Clone�����ģ�����ץ����\n");
	// moving
	if (!s) {
		tell_room(environment(ob),"��������һֻ���ְ�"+
		ob->name()+"ץ��������Ȼ�󲻼��ˡ�\n", ob);
		tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ��ڡ���\n");
	}
	ob->move(environment(me), s);
	tell_object(me, "���"+ob->name()+"ץ�������ǰ��\n");
	if (!s) {
		tell_object(ob,"��������ʱ������"+ me->name() + "����Ū�����ġ�\n");
		tell_room(environment(ob), me->name()+ "���ְ�" + ob->name()+"ץ�˹�����\n",({me,ob}));
	}
	if (!wizardp(ob) && geteuid(me) != "yuj")
		log_file("static/SUMMON",
			sprintf("%s(%s) summoned %s(%s) to %s\n", me->name(1),
				me->query("id"), ob->name(1), ob->query("id"), environment(me)->query("short")
		), me, ({ ob })
	);
	// ok ..
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ�������(��)��ĳ��ץ������ǰ��
HELP
	);
	return 1;
}
