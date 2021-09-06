// expell.c

#include <skill.h>

inherit	F_CLEAN_UP;

void create() {	seteuid(getuid()); }

int main(object	me, string arg)
{
	object ob;
	int i;

	if( !arg || !ob	= present(arg, environment(me))	)
		return notify_fail("��Ҫ��˭���ʦ�ţ�\n");

	if( !ob->is_character()	)
		return notify_fail("���𲻶�����\n");

	if( !userp(ob) )
		return notify_fail("��ֻ�ܿ�����������ݵ����\n");

	if( userp(me) )
		return notify_fail("��ʱ�رա�\n");

	if (me->query("family/privs")==-1
	&& (string)me->query("family/family_name")==(string)ob->query("family/family_name"))
	{
		message_vision("\n$N����$n˵�����ӽ���������Ҳ������"
			+ me->query("family/family_name") + "�ĵ����ˣ����߰ɣ�\n\n", me, ob
		);
		tell_object(ob, "\n�㱻" + me->query("family/title") + "�����ʦ���ˣ�\n\n");
	}
	else if (ob->is_apprentice_of(me))
	{
		message_vision("\n$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n\n", me, ob);
		tell_object(ob,	"\n�㱻ʦ�������ʦ���ˣ�\n\n");
	} else
		return notify_fail("����˲�����ĵ��ӡ�\n");

	i = ob->query("combat_exp") / 200;
	if (i > 30000) i = 30000;
	if (i < 150) i = 0;

	ob->set("expell/family_name",ob->query("family/family_name"));
	ob->set("expell/master_id", ob->query("family/master_id"));
	ob->set("expell/master_name", ob->query("family/master_name"));
	ob->delete("family");
	ob->delete("vendetta_mark");
	ob->delete("title");
        ob->add("combat_exp", -i);
	ob->skill_death_penalty();
	tell_object(ob, "�㱻�ͷ���"+chinese_number(i)+"�㾭�飬�������书�����˰뼶��\n");
	return 1;
}

int help(object	me)
{
	write(@HELP
ָ���ʽ : expell|kaichu <ĳ��>

���ָ��������㿪�����ɲŵĵ��ӣ������ڿ���һ������֮ǰ����������ǡ�
HELP
	);
	return 1;
}
