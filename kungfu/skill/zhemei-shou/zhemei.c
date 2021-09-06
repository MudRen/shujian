// zhemei.c
// /kungfu/skill/zhemei-shou/
// Program by ying
//modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
	string msg;
	int improve, ap, dp, skill, i;

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("����÷չ��ֻ����ս����ʹ�á�\n");
                
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���÷չ����\n");   
                
        if( (int)me->query_skill("zhemei-shou", 1) < 80 )
                return notify_fail("�����ɽ��÷�ֻ�������죬ʹ��������÷չ��������\n");     
                
        if( (int)me->query_skill("hand", 1) < 80 )
                return notify_fail("��Ļ����ַ���������죬ʹ��������÷չ��������\n");                                                      

        if (me->query_skill_mapped("force") != "bahuang-gong" )
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ʹ�õ��ڹ����ԣ�ʹ��������÷չ��������\n");  
                
        if ( me->query_skill_mapped("parry") != "zhemei-shou"
	            && me->query_skill_mapped("hand") != "zhemei-shou")
		            return notify_fail("�������޷�ʹ�á���÷չ����\n");
		            
		    if (me->query_skill_prepared("hand") != "zhemei-shou"
	             || me->query_skill_mapped("hand") != "zhemei-shou")
	              return notify_fail("�������޷�ʹ�á���÷չ����\n");

        if( (int)me->query_temp("zhemei") > 0 )
                return notify_fail(HIG"��ո��ù�����÷չ������һ����ʹ�ðɡ�NOR\n"NOR);

        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������̫��������ʹ�á���÷չ��������\n");
                
        if( me->query("jingli") < 200 )
		            return notify_fail("�����ھ�������, ����ʹ�á���÷չ������! \n");
 /*
       if( target->is_busy() )
		            return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
*/
                
        message_vision(HIM"$N�ַ�ͻȻ�ӿ죬ʹ����ɽ����÷չ��������Ѹ������ץס$nһֻ�ֱۣ��������ۡ�\n" NOR,me, target);        

	       me->set_temp("zhemei", 1);


	ap = COMBAT_D->skill_power(me, "hand", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);

	if ( target->is_busy())
		dp -= dp/3;

	skill = me->query_skill("zhemei-shou", 1) /2 + me->query_skill("bahuang-gong",1) /2;

        i = skill/3;
	if ( skill > 350 )
		i = to_int( skill/3 * skill/350.0);
 
  if(!userp(me)) i = i / 2;

	me->add_temp("apply/attack", i);
	me->add_temp("apply/hand", i);
              me->add_temp("apply/damage", i);
           me->add_temp("apply/strength", i/5);
	if(random(ap + dp) > dp /3  && !target->query_temp("zhemei")) {
		msg = HIR"���$n���ֱ۱�$N���۵��޷�������ֻ��һ������ʹ���̣������۶ϣ������޷�������\n"NOR;
		message_vision(msg, me, target);
		improve = me->query("str");
                            target->add_busy(random(2)+3);
		target->add_temp("apply/strength", -improve);
		target->set_temp("zhemei", improve);
                target->add_condition("no_fight", 2);
                target->add_condition("no_perform", 2);
                target->set_temp("must_be_hit", 1);
		
		if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		
		if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (skill>350)?3:1);
		if ( skill > 150)
			if (present(target,environment(me)) && me->is_fighting(target))
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (skill>350)?3:1);
			
			if ( skill > 220)
			if (present(target,environment(me)) && me->is_fighting(target))
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (skill>350)?3:1);	

			if ( skill > 350)
			if (present(target,environment(me)) && me->is_fighting(target))
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		
		me->add("neili", -100);
		me->add("jingli", -50);
		call_out("check_fight", 1, me, target ,improve, me->query_skill("zhemei-shou")/50);
	}
	else {
		msg = WHT"����$n�������ڳ��ˣ������쳣���������𣬷���$N����������\n"NOR;
		message_vision(msg, me, target);
		if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);
		if ( skill > 100)
			if (present(target,environment(me)) && me->is_fighting(target))
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
	}
	me->add_temp("apply/attack", -i);
	me->add_temp("apply/hand", -i);
              me->add_temp("apply/damage", -i);
           me->add_temp("apply/strength", -i/5);
	me->start_busy(1+random(1));
	me->add("neili", -100);
	me->add("jingli", -100);

	me->delete_temp("zhemei");

        me->start_perform(3, "����÷չ��");
	return 1;
}

void remove_effect(object target, int improve)
{
	if(!target) return;
	target->add_temp("apply/strength", improve);
        target->delete_temp("zhemei");
        target->delete_temp("must_be_hit");
	tell_object(target, HIR"\n������������չ�ֱۣ���һ����͸о��ֱ��Ѿ��ָ�ԭ״��\n"NOR);
}

void check_fight(object me, object target, int improve, int count)
{
	if(! target) return;
	if(! me
	|| ! me->is_fighting(target)
	|| me->query_skill_mapped("hand") != "zhemei-shou"
	|| me->query_skill_prepared("hand") != "zhemei-shou"
	|| me->query_temp("weapon")
	|| count < 0 ){
		remove_effect(target , improve);
		return;
	}
	call_out("check_fight", 1, me, target, improve, count -1);
}

string perform_name(){ return HIM"��÷չ"NOR; }

int help(object me)
{
	write(YEL"\n��ɽ��÷��֮"HIM"����÷չ����"NOR"\n");
	write(@HELP
	���չ���ɽͯ��֮������

	Ҫ��
	��ǰ���� 200 ���ϣ�
	��ǰ���� 200 ���ϣ�
        ������� 200 ���ϣ�
        ��ɽ��÷�ֵȼ� 80 ���ϣ�
        �˻�����Ψ�Ҷ��𹦵ȼ� 80 ���ϣ�
        ��ڤ�񹦵ȼ� 80 ���ϣ�
HELP
	);
	return 1;
}
