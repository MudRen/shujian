// perform.c
// Modified by snowman@SJ 08/12/2000
// �� perform_action() ��/inherit/skill/skill.c �ᵽ���
// �������Ƿ���Խ�ԼһЩ�ڴ棿 :-)
// Modified by emnil@sj 02/14/2001
// ����Դ�perform�Ľӿ�

inherit F_SSERVER;

int perform_action(object me, mixed skill, string arg);
int diy_pfm(object me, string arg);

int main(object me, string arg)
{
	object weapon;
	string martial, skill;
	mapping prepare;
	string pfmname;
	
	seteuid(getuid());

	if ( !arg ) return notify_fail("��Ҫ���⹦��ʲô��\n");
	if ( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
	if ( me->is_perform()) 
		return notify_fail(me->query_perform()+"������ʱ�仹û����Ŀǰ����ʩ���⹦��\n");
	
	if ( me->query_condition("no_perform") )
		return notify_fail("( ����Ϣ���ȣ���ʱ����ʩ���⹦��)\n");

	if ( me->query_temp("combat_yield") )
		return notify_fail("( �����򲻻����أ�ʩ���⹦���)\n");
			
	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
		if( weapon = me->query_temp("weapon") )
			martial = weapon->query("skill_type");
		else {
			prepare = me->query_skill_prepare();
			if (sizeof(prepare)) martial = keys(prepare)[0];
			else
			martial = "unarmed";
		}
	}
	
	notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
	
	pfmname = arg;
	sscanf(arg,"%s %*s",pfmname);
	
	if( stringp(skill = me->query_skill_mapped(martial)) ){
		if( perform_action(me, SKILL_D(skill), arg) ) {
			if( me && random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			if( me && userp(me))
				BALANCE_D->add_perform(skill,pfmname,1);
			return 1;
		}
		if( weapon )
			if (diy_pfm(me, arg))
			{
				if( me && userp(me))
				BALANCE_D->add_perform(skill,pfmname,1);
				return 1;
			}
			else return 0;
	}
	if ( sizeof(prepare) > 1) {
		martial = keys(prepare)[1];
		if( stringp(skill = me->query_skill_mapped(martial))
		&& perform_action(me,SKILL_D(skill), arg) ) {
			if( me && random(120) < (int)me->query_skill(skill, 1) )
				me->improve_skill(skill, 1, 1);
			if( me && userp(me))
				BALANCE_D->add_perform(skill,pfmname,1);			
			return 1;
		}
	}
	if( stringp(skill = me->query_skill_mapped("parry"))
	&& perform_action(me,SKILL_D(skill), arg) ) {
		if(me && random(120) < (int)me->query_skill(skill, 1) )
			me->improve_skill(skill, 1, 1);
		if( me && userp(me))
				BALANCE_D->add_perform(skill,pfmname,1);
		return 1;
	}
	if( stringp(skill = me->query_skill_mapped("dodge"))
	&& perform_action(me,SKILL_D(skill), arg) ) {
		if( me && random(120) < (int)me->query_skill(skill, 1) )
			me->improve_skill(skill, 1, 1);
		if( me && userp(me))
				BALANCE_D->add_perform(skill,pfmname,1);
		return 1;
	}

	//return diy_pfm(me, arg);
	if (diy_pfm(me, arg))
	{
		if( me && userp(me))
			BALANCE_D->add_perform(skill,pfmname,1);
		return 1;
	}
	return 0;
}

int perform_action(object me, object skill, string arg)
{
	string action, target, file;
	mixed target_ob;
	object d_target, d_source;

	if( sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) target_ob = target;
//			return notify_fail("����û�� " + target + "��\n");
	}
	
	else{
		action = arg;
		target_ob = offensive_target(me);
	}

	if( !stringp(file = (string)skill->perform_action_file(action))
	||      file_size(file + ".c") <= 0 )
		return 0;
	
	if ( !objectp(target_ob) ) 
//		return notify_fail("����û�п�ʹ�õĶ���\n");
		return (int)call_other( file, "perform", me, target_ob);
	if ( !present(target_ob, environment(me)) )
		return notify_fail("����û�п�ʹ�õĶ���\n");
		
	if ( target_ob != me 
	&& (d_target = target_ob->query_temp("douzhuan_target"))
	&& (d_source = target_ob->query_temp("douzhuan_source"))){
		if(!objectp(d_target)
		|| !objectp(d_source)
		|| d_source != me
		|| environment(d_target) != environment(me)
		|| environment(d_target) != environment(target_ob) )
			return (int)call_other( file, "perform", me, target_ob);
			
		else {
			d_target->fight_ob(me);
			me->fight_ob(d_target);
			target_ob = d_target;
		}
	}
	return (int)call_other( file, "perform", me, target_ob);
}

int diy_pfm(object me, string arg)
{
	string skill, file, action, target;
	mixed target_ob;
	
	return 0;
	skill = SKILL_D(me->query_skill_mapped("force"));
	if( !stringp(skill) || (skill=="/kungfu/skill/0") )
		return 0;
	if( !stringp(file = (string)skill->exert_function_file("diypfm"))
	   || file_size(file + ".c") <= 0 )
		return 0;

	if( sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) //target_ob = target;
			return notify_fail("����û�� " + target + "��\n");
	}
	else{
		action = arg;
		target_ob = offensive_target(me);
	}

	return (int)call_other( file, "perform", me, target_ob, action);
}

int help (object me)
{
	write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺

perform parry.yi

or

perform chan

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
	);
	return 1;
}
