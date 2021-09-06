// guangming.c  ʥ�����
// By River@SJ

#include <ansi.h>
inherit F_SSERVER;

string perform_name(){ return HIC"ʥ�����"NOR; }

string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
}); 

string *limb=({
"����","����","����","ͷ��","С��","�ؿ�","����","�ɲ�","�Ҽ�","�ұ�","�ҽ�",
});

int perform(object me, object target)
{
	object weapon;
	int damage, p, ap, dp;
	string msg,name,dodge_skill,limbs;

	if(!target) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("��ʥ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 ||(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
                
	if((int)me->query_skill("lieyan-dao", 1) < 100 )
		return notify_fail("������浶��������죬����ʹ�á�ʥ���������\n");

	if ( !me->query_skill("jiuyang-shengong", 1))
	if ( me->query_skill("shenghuo-shengong", 1) < 100 )
		return notify_fail("���ʥ���񹦲����ߣ�����ʹ�á�ʥ���������\n");
                        
	if((int)me->query_skill("piaoyi-shenfa", 1) < 100 )
		return notify_fail("���Ʈ���������ߣ�����ʹ�á�ʥ���������\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if( me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if((int)me->query("jingli", 1) < 300 )
		return notify_fail("��ľ�����Ϊ����������ʹ�á�ʥ���������\n");

	if( me->query_skill_mapped("blade") != "lieyan-dao")
		return notify_fail("�����ڵ�״̬�޷�ʹ�á�ʥ���������\n");

	if ((int)me->query("neili",1) < 800)
		return notify_fail("��������������޷�ʹ�á�ʥ���������\n");

	msg = HIC"\n$N���һ����"HIR"Ϊ�Ƴ���Ω�����ʣ�ϲ�ֱ���Թ鳾��"HIC"��"+weapon->query("name")+HIC"���˺϶�Ϊһ����������ɱ������$n��\n"NOR;

	ap = me->query("combat_exp", 1) / 1000 * me->query_skill("blade");
	dp = target->query("combat_exp", 1) / 1000 * target->query_skill("parry");

	if( random(ap + dp) > dp || !living(target)) {
		limbs= limb[random(sizeof(limb))];
		msg +=CYN"$nֻ����������·��������˵�ɱ�����֣����޿ɱܣ����ɴ�ʧɫ����ʱ��ǰһ����"+weapon->name()+CYN"�Ѵ���"+limbs+"����������\n"NOR;
		damage = me->query_skill("blade");
		damage += me->query_skill("dodge");
		damage *= 3;
		damage += random(damage/2);
		if(damage > 3500) damage = 3500 + (damage-3500)/3;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		me->add("neili", - 250);
		me->add("jingli", - 70);
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		msg = replace_string( msg, "$w", weapon->name());
		msg = replace_string( msg, "$l", limbs);
		if( me->query_skill("yingzhua-shou",1 ) > 100
	 	 && me->query_skill_mapped("hand") == "yingzhua-shou"
		 && me->query_skill_prepared("hand") == "yingzhua-shou"
		 && ! target->is_busy()){
			name = xue_name[random(sizeof(xue_name))];
			msg += HIC"\n$N��������ǰһ�����˶Է�����֮�ʣ����ֱ���Ϊӥצ֮�ƣ���������ץ��$n��"+name+"��\n"NOR;

			ap = me->query("combat_exp", 1)/ 1000 * me->query_skill("hand");
			dp = target->query("combat_exp", 1) / 1000 * target->query_skill("dodge");

			if( random(ap + dp) > dp || !living(target)) {
				me->add("neili", -100);
				target->add_busy( random(me->query_skill("yingzhua-shou", 1)/50) + 2);
				msg += CYN"���$n��"+name+"��ץ�����ţ�ȫ����������һ������ʱ���ɶ�����\n"NOR;
			}
			else {
				dodge_skill = target->query_skill_mapped("dodge");
				if( !dodge_skill ) dodge_skill = "dodge";
				msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
				me->add("neili", -50);
			}
			message_vision(msg, me, target);
			me->start_perform(3,"��ʥ�������");
			me->start_busy(random(2));
			return 1;
		}
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		me->add("neili", -100);
		me->start_busy(1);
	}
	message_vision(msg, me, target);
	me->start_perform(2,"��ʥ�������");
	return 1;
}

int help(object me)
{
        write(HIC"\n���浶����ʥ���������"NOR"\n");
        write(@HELP
        Ҫ��  ��ǰ���� 800 ���ϣ�
                ��ǰ���� 300 ���ϣ�
                ���浶���ȼ� 100 ���ϣ�
                Ʈ�����ȼ� 100 ���ϣ�
                ʥ���񹦵ȼ� 100 ���ϣ�
                ��������Ϊ���浶����

        ���⣺
                ӥצ�����ֵȼ� 100 ���ϣ�
                �����ַ�Ϊӥצ�����֣�
                ��ӥצ�����֣�
                �и������á�

HELP
        );
        return 1;
}
