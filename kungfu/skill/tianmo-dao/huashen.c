// chuanliu.c
//xjqx@sj 2008/12/30
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int skill;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);
	
	if( !objectp(target)
	 || !me->is_fighting(target) )
		return notify_fail("��ֻ����ս����ʹ�û�����ǧ��\n");

	if (!objectp(weapon) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("����ʹ�õ������ڹ����ԡ�\n"); 

        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 150)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������������ǧ����\n");  

	if ((int)me->query_skill("blade", 1) < 150 )
		return notify_fail("��Ļ���������������죬����ʹ�û�����ǧ��\n");

	if ( me->query_skill_mapped("blade") != "tianmo-dao"
	 || me->query_skill_mapped("parry") != "tianmo-dao" )
		return notify_fail("�������޷�ʹ�û�����ǧ��\n");

	if ((int)me->query("neili") < 1000 )
		return notify_fail("����������̫��������ʹ�û�����ǧ��\n");

	if ((int)me->query("max_neili") < 2000 )
		return notify_fail("����������̫��������ʹ�û�����ǧ��\n");

	if (me->query_temp("tmd/huashen") ) 
		return notify_fail("���Ѿ���ʹ�û�����ǧ�ˣ�\n");

	message_vision(HIG"\n$N���������Ǵ󷨣�������" + weapon->name() +HIG"��������Ӱ�����������������Ʋ��ɵ���\n"NOR, me);
        skill = me->query_skill("tianmo-dao",1);
	skill += random(skill);
	if ( skill > 100) skill = 100 + random(skill-100)/10;
	me->add_temp("apply/damage", skill/2);
	me->set_temp("tmd/huashen", skill);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	if ( me->query_skill("tianmo-dao", 1) > 200)
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	me->start_perform(3, "������ǧ");
	me->add("neili", -300);
	me->start_busy(random(2));
	call_out("remove_effect", 1, me, target, weapon, skill);
	return 1;
}

void remove_effect(object me, object target,object weapon, int skill)
{
	if( !me) return;
	if(!me->is_fighting(target)
	|| ! weapon
	|| me->query_temp("weapon") != weapon
	|| me->query_skill_mapped("blade") != "tianmo-dao"
	|| me->query_skill_mapped("parry") != "tianmo-dao"){
		if( weapon)
			message_vision(HIG"$N�����ջص�Ӱ��������ʱɢ����\n"NOR, me);
		me->add_temp("apply/damage", -skill/2);
		me->delete_temp("tmd/huashen");
		return;
	}
	call_out("remove_effect", 1, me, target, weapon, skill);
}

string perform_name(){ return HIG"������ǧ"NOR; }

int help(object me)
{
        write(HIY"\n��ħ��֮��������ǧ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ��ħ���ȼ� 150 ���ϣ�
                ���Ǵ󷨵ȼ� 150 ���ϣ�
                ���������ȼ� 150 ���ϣ�
                ��������Ϊ��ħ����
                �����м�Ϊ��ħ����
                �����ڹ�Ϊ���Ǵ󷨣�
                ���ֱֳ�����

HELP
        );
        return 1;
}
