// ����˫��
// by snowman@SJ
// Modify by Lklv for npc can't add gift
// Modify by Lane@SJ 2005.08.03 
// Update by lsxk@hsbbs 2007/7/3

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define KANGLONG "/kungfu/skill/xianglong-zhang/kanglong"

string perform_name(){ return WHT"����˫��"NOR; }

int perform(object me, object target)
{
	int i, j, ap, dp, jiali;

	i = me->query_skill("xianglong-zhang", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target) != environment(me) )
		return notify_fail("������˫�ơ�ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á�����˫�ơ���\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 150 )
		return notify_fail("��Ľ���ʮ���ƻ�������죬ʹ����������˫�ơ�������\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 150 )
		return notify_fail("��Ļ��������ȼ���������ʹ����������˫�ơ�������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("����ʹ���ڹ����ԣ�ʹ����������˫�ơ�������\n");

	if( (int)me->query_skill("force") < 200 )
		return notify_fail("����ڹ��ȼ�����������ʹ�á�����˫�ơ���\n");

	if( (int)me->query_str(1) < 36 )
		return notify_fail("�������������ǿ����ʹ����������˫�ơ�����\n");

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("parry") != "xianglong-zhang")
		return notify_fail("�������޷�ʹ�á�����˫�ơ���\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("����������̫����ʹ����������˫�ơ���\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("����������̫����ʹ����������˫�ơ���\n");

	if( (int)me->query("jingli") < 800 )
		return notify_fail("��ľ�������������ʹ��������˫�ơ���\n");

        if( (int)me->query_temp("xlz/xiao") && userp(me) && i<551 )
		return notify_fail("������ʹ�á�����Х����\n");

	if( me->query_temp("xlz/py") )
		return notify_fail("������ʹ�á�����˫�ơ���\n");

if(!userp(me)) i =  i  /3 ;

	j = i / 3;

	if( i > 350 )
		j = to_int( i / 2.5 * i/ 350.0);
	else if( i > 250 )
		j = to_int( i / 3.0 * i/ 250.0);


message_vision(HIW"\n$Nһ���Ϻȣ�˫�������Ю�������ɳ��ʹ����������ĵ��⹦������˫�ơ���\n"NOR,me);
	me->add_temp("apply/damage", i/5);
	me->add_temp("apply/attack", j);
	me->add_temp("apply/strike", j);
	me->add_temp("apply/strength", i/15);
if (i>=400)         
	me->set_temp("xlz/py", 1);

   if( userp(me) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	else
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	if( me->is_fighting(target) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);



        ap = COMBAT_D->skill_power(me,"strike",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"parry",SKILL_USAGE_DEFENSE);

	if( target->is_busy() ) dp /= 2;

	if( ap < 1 ) ap = 1;
	if( dp < 1 ) dp = 1;

 jiali = me->query("jiali");

	if( random(ap + dp ) > dp / 2 && i >= 451  && userp(me) ) {
		me->set_temp("xlz/py_add", 1);
		if( random(me->query_str(1)) > target->query_con(1)/2 ) {
			target->set_temp("must_be_hit", 1);
			me->set("have_master", 1);
			if( wizardp(me) ) tell_object(me, HIG"����ʮ���Ƹ�Ч�������У���"NOR);
		}
		if( wizardp(me) ) tell_object(me, HIG"����ʮ���Ƹ�Ч����׷����������"NOR);
         	if( wizardp(me) ) tell_object(me, HIG"�����ʶԱ� "+ap+" : "+dp+"\n"NOR);
	message_vision(HIC"\n$Nһ�Ƽȳ������������������������⣬������ǰ�ƣ�˫����������һ����ɽ�������ӿ����\n"NOR,me,target);
	me->set("jiali", jiali +(i-400));

	me->add_temp("apply/damage", i/10);
	me->add_temp("apply/attack", j*2);
	me->add_temp("apply/strike", j*2);
	me->add_temp("apply/strength", i/10);
	me->set_temp("xlz/py_power", 1);

COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->add_temp("apply/damage", -i/10);
	me->add_temp("apply/attack", -j*2);
	me->add_temp("apply/strike", -j*2);
	me->add_temp("apply/strength", -i/10);

	me->set("jiali", jiali);
	me->delete_temp("xlz/py_power");
	me->delete_temp("xlz/py_add");
	target->delete_temp("must_be_hit");
	me->delete("have_master");
	me->start_busy(random(2));
	me->add("neili", -400);

}

	me->add_temp("apply/damage", -i/5);
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/strike", -j);
	me->add_temp("apply/strength", -i/15);

	me->add("jingli", -100);
	me->delete_temp("xlz/py");
	me->start_busy(random(2));
	me->start_perform(3,"������˫�ơ�");

 if( i >= 350  && userp(me)){
        	
        tell_object(me, HIC"\n�㻺����˫���ᵽ��ǰ����Ϣ������������ת��Խ��Խ�죬������ȴ�������κζ���...\n\n"NOR);

         	me->start_call_out( (: call_other, __DIR__"kanglong", "kanglong_attack", me, 2 :), 1 );
        }

	
	me->start_perform(3,"������˫�ơ�");

	return 1;
}



int help(object me)
{
	write(WHT"\n�����ơ�����˫�ơ���"NOR"\n");
	write(@HELP
	����˫��Ϊ��������������֮һ����Ϊ���ơ��������֣���ɲ�ͬ��
	Ҫ��	������� 2000 ���ϣ�
		��ǰ���� 1500 ���ϣ�
		��ǰ���� 800 ���ϣ�
		�����Ƶȼ� 150 ���ϣ�
		���������ȼ� 150 ���ϣ�
		�ڹ���Ч�ȼ� 230 ���ϣ�
		���� 36 ���ϣ�
		�����м�Ϊ�����ơ�
HELP
	);
	return 1;
}
