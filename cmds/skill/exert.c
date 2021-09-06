// exert.c
// Modified by snowman@SJ 08/12/2000
// �� exert_function() ��/inherit/skill/skill.c �ᵽ���
// �������Ƿ���Խ�ԼһЩ�ڴ棿 :-)
// Looklove Modified at 2001.5.20 for condition no_exert, can't exert all now.
// hehe

#include <skill.h>

inherit F_SSERVER;

int exert_function(object me, mixed skill, string arg);

int main(object me, string arg)
{
	string force;
	mixed rc;
	string pfmname;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");

	if (!me->query_skill("force"))
		return notify_fail("��û���ڹ���\n");
	if( !arg )
		return notify_fail("��Ҫ���ڹ���ʲô��\n");

	if( me->query_condition("no_exert") || me->query_condition("no_force"))
	     	return notify_fail("����Ϣ���ȣ���ʱ����ʩ���ڹ���\n");

	notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��ڹ���\n");

	rc = exert_function(me, SKILL_D("force"), arg);
	if( stringp(rc) )
		return notify_fail(rc);
	if (rc >= 0)
		return rc;
	
	pfmname = arg;
	sscanf(arg,"%s %*s",pfmname);
	notify_fail("�����õ��ڹ���û�����ֹ��ܡ�\n");
	if( stringp(force = me->query_skill_mapped("force")) ) {
		if( me->is_exert())
			return notify_fail(me->query_exert()+"���õ��У��㲻��ʩ���ڹ���\n");
		if (exert_function(me, SKILL_D(force), arg) > 0) {
			if (me->is_fighting())
				me->add("combat_exp", random(2));
			if( me && userp(me))
				BALANCE_D->add_exert(force,pfmname,1);
			return 1;
		}
	}
	return 0;
}

int exert_function(object me, mixed skill, string arg)
{
	string func, target, file;
	mixed target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) target_ob = target;
	} else {
		func = arg;
		target_ob = offensive_target(me);
		if (!target_ob) target_ob = me;
	}

	if( !stringp(file = (string)skill->exert_function_file(func))
	|| file_size(file + ".c") <= 0 )
		return -1;

	notify_fail("");
	return (int)call_other( file, "exert", me, target_ob);
}

int help (object me)
{
	write(@HELP
ָ���ʽ��exert|yun <��������> [<ʩ�ö���>]

����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>����п��ޡ�
����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����ָ����Ҫʹ��
���ڹ���

��ο� help force �ɵ�֪һЩ�󲿷��ڹ����еĹ��ܣ����������õ��ڹ�����
��û�иù��ܣ���һ�Ի�ο�����˵����֪��

ע�������ı��Լ����ڹ�����ԭ�����������������ֱ��ת����ȥ������
    �ӣ���ʼ��
HELP
	);
	return 1;
}
