// setSkill.c
//Modified By bbb

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,j,level,oldlvl;
	mapping skill_status;
	object ob;
	string skill,obj,reason;
	string *skills;

	if( !arg )  return notify_fail("setskill <ĳ��> <����>/all <������> because <ԭ��>��\n");

	if( sscanf(arg, "%s %s %d because %s", obj, skill, level, reason)!=4 
	&& sscanf(arg, "%s %s %d", obj, skill,level) != 3)
		return notify_fail("setskill <ĳ��> <����>/all <������> because <ԭ��>��\n");

	if ( obj == "me") ob = me;
	else ob = find_player(obj);

	if( !ob )  ob = find_living(obj);
	if( !ob )  ob = present(obj, environment(me));
	if( !ob ) return notify_fail("�Ҳ���������\n");

	if ( !wizardp(ob) && sscanf(arg, "%s %s %d because %s", obj, skill, level, reason)!=4 )
		return notify_fail("setskill <ĳ��> <����>/all <������> because <ԭ��>��\n");

	if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");

/*	if( userp(ob))
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
*/
	if( skill != "all" &&!find_object(SKILL_D(skill))&&file_size(SKILL_D(skill)+".c") < 0 )
		return notify_fail("û�д����书��"HIM+skill+NOR"  ���� !\n");

	if( level == 0 && wizardp(ob) && (wiz_level(me) < wiz_level("(admin)")) )
		return notify_fail("�����ô������ʦ�Ĺ���ɾ����\n");

	/*if( (wiz_level(me) < wiz_level("(arch)")) && me!=ob )
		return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");*/

	write("begin setting skills for " + ob->short(1) + "��\n");

	if( skill == "all" ) {
		if ( !(skill_status = ob->query_skills()) || !sizeof(skill_status) )
			return notify_fail("�����û��ѧ���κμ��ܣ������� all ���������\n");
		skills  = keys(skill_status);
		j = sizeof(skill_status);
		for(i=0; i<j; i++) {
			if( level ==0 ) {
				ob->delete_skill(skills[i]);
				write("deleting->" + to_chinese(skills[i]) +
					"(" + skills[i] + ")\n");
			}
			else {
				ob->set_skill(skills[i], level);
				printf("setting-> %-36s%d\n", to_chinese(skills[i]) +
					"(" + skills[i] + ")", level);
			}
		}
	}
	else {
		oldlvl = ob->query_skill(skill, 1);
		if( level ==0 ) {
			write("deleting->" + to_chinese(skill) + "(" + skill + ")\n");
			ob->delete_skill(skill);
		}
		else    {
			ob->set_skill(skill, level);
			printf("setting-> %-36s%d\n", to_chinese(skill) +
				"(" + skill + ")", level);
		}
	}
	if( userp(ob) && ob!=me )
		log_file("static/SETSKILL",
			sprintf("%s(%s) set %s(%s) %s from %d to %d because %s\n", me->name(1),
				me->query("id"), ob->name(1), ob->query("id"), skill, oldlvl, level, reason
			), me, ob
		);
	write("Done.\n");
	return 1;
}

int help()
{
	write(@LONG
ָ���ʽ��setskill  <ĳ��> <����>/all <������>��

�����趨ĳ�˵�ĳ�ּ��ܵļ�����, ����ڶ����� all �������е�
���ܸ�Ϊ�趨�ļ����������ѡ���˼�����Ϊ 0 ��ɾ�����˴���ܡ�

���棺�����ô����
LONG    );
	return 1;
}

