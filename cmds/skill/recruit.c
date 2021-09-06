// recruit.c
// Modify by Lklv 2002.7.17 �������岻���

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;

	if (!arg)
		return notify_fail("ָ���ʽ��recruit|shou [cancel]|<����>\n");

	if (arg=="cancel") {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("�����ڲ�û����¼�κ���Ϊ���ӵ���˼��\n");
		write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
		if (present(old_rec, environment(me))) {
		tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		}
		me->delete_temp("pending/recruit");
		return 1;
	}

	if (!(ob = present(arg, environment(me))))
		return notify_fail("������˭�����ӣ�\n");

	if (ob==me)
		return notify_fail("���Լ�Ϊ���ӣ�������....����û���á�\n");

	if (!userp(ob))
		return notify_fail("��ֻ�������Ϊ���ӡ�\n");

	if (ob->is_apprentice_of(me)) {
		message_vision("$N����$n��ͷ��˵��������ͽ������\n", me, ob);
		return 1;
	}

	if (!me->query("family"))
		return notify_fail("�㲢�������κ����ɣ�������ȼ���һ�����ɣ����Լ���һ��������ͽ��\n");

	// If the target is willing to apprentice us already, we do it.
	if (!userp(me) || (object)ob->query_temp("pending/apprentice") == me) {
		if (!living(ob)) {
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"����������$n��Ȼû�а취�а�ʦ֮��\n\n",
				me, ob);
			return 1;
		}
		if((ob->query("family")) && ( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) )
		{
			message_vision(
				"$N��������ʦ�ţ���Ͷ��$n���£���\n\n"
				"$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",
				ob, me);
			if (ob->query("class") != "eunuch"){
				ob->delete("class");
				ob->delete("tls");
				ob->delete("gb/bags");
			}
			if (ob->query("combat_exp") > 10000) {
				int count = ob->add("betrayer", 1);

				log_file("static/BETRAY",
					ob->query("name")+"("+ob->query("id")+")��"+count+"�δ�"
					+ob->query("family/family_name")+"����"+me->query("family/family_name")+"\n",
					ob
				);
				if (count <= 1)
					count = 10;
				else if (count == 2)
					count = 4;
				else
					count = 2;

				ob->add("combat_exp", - ob->query("combat_exp") / count);
				ob->setup();
			}
		}
		else
		{
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"$n����������$N���������ؿ����ĸ���ͷ���е�����ʦ������\n",
				me, ob
			);
		}

		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");
		ob->delete("expell");

		tell_object(me, "��ϲ��������һ�����ӣ�\n");
		family = ob->query("family");
		tell_object(ob, sprintf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", family["family_name"],
			chinese_number(family["generation"]) )
		);
	} else {
		old_rec = me->query_temp("pending/recruit");
		if (ob==old_rec)
			return notify_fail("������" + ob->name() + "Ϊ���ӣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_rec) ) {
			write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
			tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		}

		me->set_temp("pending/recruit", ob);
		message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", me, ob);
		tell_object(ob, YEL "�����Ը���" + me->name() + "Ϊʦ������ apprentice ָ�\n" NOR);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : recruit|shou [cancel]|<����>

���ָ����������ĳ��Ϊ����, ����Է�Ҳ��ӦҪ����Ϊʦ�Ļ�.

See Also:	apprentice
HELP
	);
	return 1;
}
