// ������ӿ
// By River
// Modify By River@SJ 2000.2.22
//by spiderii@ty �����˺�
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *xue_name = ({
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
});

int perform(object me, object target)
{
	string msg,dodge_skill;
	int i, j, busy, exp, texp, skill, tskill, p, ap, dp;
	object weapon;

        i = me->query_skill("xuantie-jianfa", 1) /4 ;
        j = me->query_skill("sword", 1)/ 4;

	if ( me->query_skill("xuantie-jianfa", 1) > 250 ) {
                i = to_int(me->query_skill("xuantie-jianfa", 1)/3.0 * me->query_skill("xuantie-jianfa", 1)/250.0);
                j = to_int(me->query_skill("sword", 1)/3.0 * me->query_skill("sword", 1)/250.0);
	}

	if ( me->query("gender") != "����") {
		j = j / 5 *4;
		i = i / 5 *4;
	}

	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target))
		return notify_fail("���������ġ�������ӿ��ֻ����ս���жԶ���ʹ�á�\n");

	if( !weapon || weapon->query("skill_type") != "sword")
		return notify_fail("�����ʹ����������ʹ�á�������ӿ����\n");

	if((int)me->query_skill("xuantie-jianfa", 1) < 130 )
		return notify_fail("�������������������죬ʹ������������ӿ��������\n");

	if (me->query_skill("xuantie-jianfa", 1) < 151 && me->query("env/��������") == "����")
		return notify_fail("�������������������죬ʹ������������ӿ��������\n");

	if((int)me->query_skill("yunu-xinjing", 1) < 130 )
		return notify_fail("�����Ů�ľ��ȼ���������ʹ������������ӿ��������\n");

	if((int)me->query_skill("force") < 180 )
		return notify_fail("����ڹ��ȼ�����������ʹ�á�������ӿ����\n");

	if((int)me->query_str(1) < 33 )
		return notify_fail("�������������ǿ����ʹ������������ӿ������\n");

	if( target->query_temp("xtjf/haichao") && me->query("env/��������") != "��ӿ" )
		return notify_fail(target->name()+"���Թ˲�Ͼ������Է��ĵؽ�����\n");
	//���ε� set �������� ��ӿ ����� ��ʵ���Ǳ����ǿ��haichao hehe
	if( me->query_skill_mapped("sword") != "xuantie-jianfa" && userp(me))
		return notify_fail("�������޷�ʹ�á�������ӿ����\n");

	if( me->query_skill_mapped("parry") != "xuantie-jianfa" && userp(me))
		return notify_fail("�������޷�ʹ�á�������ӿ����\n");

	if((int)me->query("max_neili") < 1500 )
		return notify_fail("����������������ʹ������������ӿ����\n");

	if((int)me->query("neili") < 1200 )
		return notify_fail("����������̫����ʹ������������ӿ����\n");

	if((int)me->query("jingli") < 800 )
		return notify_fail("�����ھ���̫����ʹ������������ӿ����\n");

	if( me->query("env/��������") != "����" ) {
		message_vision(HIB"\n$N΢Ц��������е�"+weapon->query("name")+HIB"������죬������ᣬ����Ȼ�����������֮������$nϯ���ȥ��\n"NOR,me,target);

  if(!userp(me))  i = i / 2;
  if(!userp(me))  j = j / 2;

                         me->add_temp("apply/attack", j);
                         me->add_temp("apply/dodge", i/3);
                         me->add_temp("apply/sword", i);
                         me->add_temp("apply/damage", j);
                
if ( me->query("gender")=="����")
                me->add_temp("apply/damage", j/2);
else                       me->add_temp("apply/attack", j/2);
 
                me->set_temp("xtjf_pfm", 1);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
if (me->is_fighting(target))
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
if (me->is_fighting(target))
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 if ( me->query("gender")=="����")
               me->add_temp("apply/damage", -j /2);
else                       me->add_temp("apply/attack", -j/2);
               me->add_temp("apply/damage", -j);
                         me->add_temp("apply/dodge", -i/3);
               me->add_temp("apply/sword", -i);
               me->add_temp("apply/attack", -j);
		me->add("neili", -350);
		me->add("jingli", -150);
		me->start_busy(random(2));
		me->delete_temp("xtjf_pfm");
                me->start_perform(3+ random(2),"��������ӿ��");
	}

	ap = me->query("combat_exp", 1)/1000 * me->query_str(1);
	dp = target->query("combat_exp", 1)/1000 * target->query_con(1);

	if((int)me->query_skill("xuantie-jianfa", 1) >= 150
	 && (int)me->query("neili", 1) > (me->query_skill("force")+ j)
	 && objectp(target)
	 && present(target,environment(me))
	 && me->is_fighting(target)
	 && me->query("env/��������") != "��ӿ" ) {
		if( me->query("env/��������") == "����")
			message_vision(HIB"\n$N��"+weapon->query("name")+HIB"Ю���˳�ӿ֮�ƣ������γ�һ����ת�����У���$n���ֹ�ȥ��\n"NOR,me,target);
		else
			message_vision(HIB"\n������$N��"+weapon->query("name")+HIB"Ю���˳�ӿ֮�ƣ������γ�һ����ת�����У���$n���ֹ�ȥ��\n"NOR,me,target);
		if( random(ap + dp) > dp || !living(target)) {
			message_vision(HIR"���$nȫ���������γɵ������������ţ�ֻ�����������ݺ��ξ��ˣ�����ײײ��\n"NOR,me,target);
			skill = me->query_skill("xuantie-jianfa", 1);
			tskill = target->query_skill("dodge", 1);
			exp = me->query("combat_exp", 1);
			texp = target->query("combat_exp", 1);
			busy= 4 + random(skill)/30;
			if( busy > 8) busy= 8;
			if( exp > texp) {
				p = texp/100* tskill;
				if( p < 1 ) p = 1;
				busy = busy * exp/100 * skill/p;
			}
			if( busy > 15) busy = 15;
			if( me->query("env/��������") == "����")
				target->add_busy(busy);
			else
				target->add_busy(4 + random(2));
			target->set_temp("xtjf/haichao", 1);
			me->add("neili", -400);
			if (present(target,environment(me)) && me->is_fighting(target))
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                me->start_perform(3+ random(2),"��������ӿ��");
			call_out("remove_effect", 1, me, target);
		}
		else {
			me->start_busy(random(2));
                me->start_perform(3+ random(2),"��������ӿ��");
			me->add("neili", -100);
			dodge_skill = target->query_skill_mapped("dodge");
			if( !dodge_skill ) dodge_skill = "dodge";
			msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
   if(msg && me && target)    message_vision(msg, me, target);
		}
	}
	return 1;
}

void remove_effect(object me, object target)
{
	if( !me || !target) return;
	if( objectp(target) && !me->is_fighting(target)) {
		target->delete_temp("xtjf");
		return;
	}
	if( objectp(target)
	 && me->is_fighting(target)
	 && !target->is_busy()
	 && random(2) == 1
	 && me->query_temp("weapon")
	 && me->query_skill("xuantie-jianfa", 1) > 180
	 && me->query("env/��������") != "��ӿ" ) {
		target->delete_temp("xtjf");
		call_out("perform2", 1, me, target);
		return;
	}
	call_out("remove_effect", 1 ,me ,target);
}

int perform2(object me,object target)
{
	string msg, dodge_skill,name;
	object weapon; 
	int p;

	if ( !me) return 0;
	weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("���Ѿ����ü���ʹ�á�������ӿ���ˡ�\n");

	if( !weapon || weapon->query("skill_type") != "sword")
		return notify_fail("�����ʹ���������ܼ���ʹ�á�������ӿ����\n");

	if( me->query_skill_mapped("sword") != "xuantie-jianfa" && userp(me))
		return notify_fail("���޷�����ʹ�á�������ӿ����\n");

	if( me->query_skill_mapped("parry") != "xuantie-jianfa" && userp(me))
		return notify_fail("���޷�����ʹ�á�������ӿ����\n");

	if((int)me->query("neili") < 1000)
		return notify_fail("������̫�����޷�����ʹ����������ӿ����\n");

	if((int)me->query("jingli") < 500 )
		return notify_fail("�㾫��̫�����޷�����ʹ����������ӿ����\n");

	if( me->query("gender")=="����" )
		p = me->query_skill("force") / 6;
	else
		p = me->query_skill("force") / 7;

	name = xue_name[random(sizeof(xue_name))];
	msg =HIB"\n$n�ò����׻���������$N����Ʈ����ת�˼�ת���Ʋ�����������һ������$n��"RED+name+HIB"��\n"NOR;
	if( me->query_kar()/2 > random(target->query_kar())){
		msg += CYN"$n�پ���ǰһ���Ի�һʱ���������ϵ�"RED+name+CYN"�ѱ�"+weapon->name()+CYN"���С�\n"NOR;
		message_vision(msg, me, target);
		target->add_temp("apply/attack", -p);
		target->add_temp("apply/dodge", -p);
		target->add_temp("apply/parry", -p);
		target->set_temp("xtjf/haichao", 1);
		if( random(5) == 1) {
			target->add_condition("no_exert", 1+ random(2));
			target->set_temp("xtjf/exert", 1);
			tell_object(me,MAG"����"RED+name+MAG"�����У�"+target->name()+"��ʱ�޷�ʩ���ڹ���\n"NOR);
		}
		else {
			target->add_condition("no_perform", 1+random(2));
			target->set_temp("xtjf/perform", 1);
			tell_object(me,YEL"����"RED+name+YEL"�����У�"+target->name()+"��ʱ�޷�ʩ���⹦��\n"NOR);
		}
		me->add("neili", - p * 3);
		me->add("jingli", - p );
		call_out("check_fight", 1, me, target, weapon, p, p/2);
	}
	else {
		me->add("neili", -100);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		message_vision(msg, me, target);
	}
                me->start_perform(3+ random(2),"��������ӿ��");
	return 1;
}

void check_fight(object me,object target,object weapon, int p, int count)
{
	if( !target) return;
	if( ! me
	 || ! me->is_fighting("target")
	 || ! me->query_temp("weapon")
	 || weapon->query("skill_type") != "sword"
	 || ! present(target,environment(me))
	 || me->query_skill_mapped("sword") != "xuantie-jianfa"
	 || count < 1){
		target->add_temp("apply/attack", p);
		target->add_temp("apply/dodge", p);
		target->add_temp("apply/parry",p);
		if( target->query_temp("xtjf/perform"))
			target->add_condition("no_perform", -1);
		if( target->query_temp("xtjf/exert"))
			target->add_condition("no_exert", -1);
		target->delete_temp("xtjf");
		message_vision(HIW"\n$N���������˾��������λָ���ԭ�ȵĽýݡ�\n"NOR, target);
		return ;
	}
	else {
		call_out("check_fight", 1, me, target, weapon, p, count -1);
		target->add("neili", - random(me->query_skill("sword")));
		if(target->query("neili") < 0 ) target->set("neili", 0);
	}
}

string perform_name(){ return HIB"������ӿ"NOR; }

int help(object me)
{
        write(HIB"\n����������������ӿ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1200 ���ϣ�
                ������� 1500 ���ϣ�
                ��ǰ���� 800 ���ϣ�
                ���������ȼ� 130 ���ϣ�
                ��Ů�ľ��ȼ� 130 ���ϣ�
                ��Ч�ڹ��ȼ� 180 ���ϣ�
                ��������Ϊ����������
                �����м�Ϊ����������

        �������ò�ͬ�Ļ�������������ͬ��Ч����

                1��set �������� ��ӿ��
                2��set �������� ������
                    �����������ȼ� 150 ���ϣ�

        ������Ϊ��unset ����������

HELP
        );
        return 1;
}
