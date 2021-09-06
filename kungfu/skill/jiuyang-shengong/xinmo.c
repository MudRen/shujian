// xinmo.c ʥ���--��ħ
// By River@SJ 
// Update By lsxk@hsbbs change perform to exert 2007/6/11

#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;
void remove_effect(object me,object weapon,int count);
int exert(object me, object target)
{
        int skill, j ;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target) )
		return notify_fail("��ֻ����ս��������ʥ�������ħ������\n");

	if((int)me->query("neili") < 1000 ) 
		return notify_fail("�������������\n");

	if((int)me->query("jingli") < 800 ) 
		return notify_fail("��ľ���������\n");

	if((int)me->query_temp("ling")) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = (int)me->query_skill("shenghuo-lingfa", 1);
 j = skill;
	if(skill < 120)
		return notify_fail("���ʥ����ȼ���������\n");

   if((int)me->query_skill("qiankun-danuoyi", 1) < 120)
		return notify_fail("���Ǭ����Ų�Ƶȼ���������\n");
/*
   if((int)me->query_skill("jiuyang-shengong", 1) < 120)
           return notify_fail("������̾������ȼ���������\n");
*/
	if( !(weapon=me->query_temp("weapon"))
	|| weapon->query("skill_type") != "dagger" )
		return notify_fail("�㲻�ñ�����ô������ʥ�������ħ������\n");

	if ( me->query_skill_mapped("dagger") != "shenghuo-lingfa"
	 || me->query_skill_mapped("parry") != "qiankun-danuoyi"
	 || me->query_skill_mapped("cuff") != "shenghuo-lingfa"
	 || me->query_skill_prepared("cuff") != "shenghuo-lingfa"
	 && userp(me))
		return notify_fail("������Ƚ�ʥ�������Ǭ����Ų���໥��ϡ�\n");

	if(userp(me) && me->query("shen") < - 20000 && !me->query_skill("jiuyang-shengong", 1))
		return notify_fail("������̫���ˣ����ʥ���̫��Σ�ա�\n");

	if(userp(me)){
		me->add("jingli", -80);
		me->add("neili", -300);
	}

	message_vision(HIR"\n$N�˿�է�꾢�У���ʥ����еľ�΢���������ӳ��������齥�ܸ�Ӧ��ͻȻ�������������Ц��\n"+
			"�����о�������а���թ֮�⡣\n\n" NOR, me);
	
	skill += me->query_skill("jiuyang-shengong", 1)/2;
	skill = skill/2 + random(skill);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/strength", skill/5);
	me->set_temp("ling", skill);

    if(j < 450) me->start_busy(random(2));
   me->start_exert(1, "��ħ");
	call_out("remove_effect", 1, me, weapon, skill/3);
	return 1;
}

void remove_effect(object me,object weapon, int count)
{
	if ( !me ) return;
	if (objectp(me) && me->query_temp("ling")) {
		if (count-- > 0 
		&& me->is_fighting()
		&& me->query_skill_mapped("cuff") == "shenghuo-lingfa"
		&& me->query_skill_prepared("cuff") == "shenghuo-lingfa"
		&& me->query_temp("weapon")
		&& weapon == me->query_temp("weapon")) {
			call_out("remove_effect", 1, me, weapon, count);
			return;
		}
		me->add_temp("apply/attack", - me->query_temp("ling")/3);
		me->add_temp("apply/damage", - me->query_temp("ling")/3);
		me->add_temp("apply/strength", - me->query_temp("ling")/5);
		me->delete_temp("ling");
		tell_object(me, HIW"\n����ħ�������ˣ�ʥ�����ʱ�������ᣬ���������\n"NOR);
		tell_room(environment(me), HIW+ me->name() + "��ħ�������ˣ�ʥ�����ʱ�������ᣬ���������\n"NOR, ({ me }));
	}
}

string exert_name(){ return HIR"��ħ"NOR; }

int help(object me)
{
   write(WHT"\n����ʥ���֮��"HIR"��ħ"WHT"����"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 1000 ���ϣ�
		��ǰ���� 800 ���ϣ�
		ʥ����ȼ� 120 ���ϣ�
		Ǭ����Ų�Ƶȼ� 120 ���ϣ�
		�����Ϊʥ�����
		����ȭ��Ϊʥ�����
		�����м�ΪǬ����Ų�ƣ�
		��ȭ��Ϊʥ�����
		���ֱֳ�����

HELP
        );
        return 1;
}
