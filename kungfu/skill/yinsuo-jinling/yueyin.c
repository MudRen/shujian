// yufeng.c ��������--������������
// By River
// Modified by darken@SJ

#include <ansi.h>
string perform_name(){ return HIW"��������"NOR; }
inherit F_SSERVER;
void check_fight(object me,object target,int count);
int perform(object me, object target)
{
        string msg ;
        object weapon,weapon1; 
        int i,ap,dp,busy;
      
        weapon = me->query_temp("weapon");

        if( !target )
             target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target))
             return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !weapon 
         || me->query_skill_mapped("whip") != "yinsuo-jinling"
         || me->query_skill_mapped("parry") != "yinsuo-jinling"
         || weapon->query("skill_type") != "whip") 
             return notify_fail("�������޷�ʹ�á����������������Է���\n");

        if((int)me->query_skill("yunu-xinjing", 1)  < 140 )
             return notify_fail("�����Ů�ľ��ȼ���������ʹ������������������\n");

        if((int)me->query_skill("yinsuo-jinling",1) < 150 ) 
             return notify_fail("����������廹������죬����ʹ�á�������������\n");

        if((int)me->query_skill("yunu-jianfa",1) < 150 ) 
             return notify_fail("�����Ů���Ľ���������죬���������������ġ�������������\n");

        if((string)me->query_skill_mapped("sword") !="yunu-jianfa")
             return notify_fail("����뽫��Ů���Ľ���Ϊ��Ľ���ʹ�á�\n");

        if((int)me->query("neili") < 1500)
             return notify_fail("�����������������������������\n");

        if((int)me->query("jingli") < 500)
             return notify_fail("��ľ�������������������������\n");

        if(me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

        if( target->query_temp("yueyin"))
             return notify_fail(target->name()+"������������Ի�����Էŵ�������\n");

        if( userp(me) && (string)me->query("family/family_name") != "��Ĺ��")
             return notify_fail("�㲻�ǹ�Ĺ�ɵĴ��ˣ���ô��ʹ�á�������������\n"); 

        msg = HIW"\n$N����"+weapon->name()+HIW"Ʈ�����ó�һƬ�����ַ����������죬����������������죬����������һ�㡣\n"NOR;
        msg +=HIW"��������ѭ������������Ȼ���Ķ���ɣ��ǹ���������֮�ö�����������֮�ķ���\n"NOR;

        me->add("neili", -500);
        me->add("jingli", -200);

        i = ((int)me->query_skill("yinsuo-jinling", 1)+(int)me->query_skill("yunu-jianfa", 1)+ (int)me->query_skill("yunu-xinjing", 1))/3;

        if(me->query("gender") !="Ů��")
         i /=2;
        weapon1 = target->query_temp("weapon");
        ap = me->query("combat_exp") * me->query_per();
        dp = target->query("combat_exp") * target->query_kar();
        if( weapon1 )//�Է�����������Ļ������±��˱�����do_attack����
							      //����л����Ļ��������Լ�������do_attack����
	{
        	if( random(ap) > dp /2
		|| !living(target))
		{
           		msg += HIR"\n$N����"+weapon->name()+HIR"�����߰��������ߣ�ֻ�Ŷ���֮����$n����������һ�������ȷ��������е�"+weapon1->name()+HIR"��\n"NOR;
                           msg += HIR"$N˳�ƶ��$n��"+weapon1->name()+HIR"���ڵ��ϣ���$n�鼱�Ǳ�֮�ʣ�������ס"+weapon->name()+HIR"�ٹ����С�\n"NOR;
           		message_vision(msg, me, target);
    
      weapon1->unequip();
      weapon1->move(environment(target));
                    target->add_busy(1);

           		me->add("neili", -200);
           		me->set_temp("juan", 1);
                           me->add_temp("apply/damage", i/3);
                           me->add_temp("apply/attack", i/2);
                           me->add_temp("apply/dexerity", i/6);
                           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (me->query("gender")=="Ů��")?3:1);
           		if(present(target,environment(me))
			&& me->is_fighting(target))
                           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (me->query("gender")=="Ů��")?3:1);
		        if(present(target,environment(me))
			&& me->is_fighting(target))
			{
                           if(me->query("gender")=="Ů��")
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
				else
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
			}

           		if(me->query("double_attack")
			&& me->is_fighting(target))
			{
	           		msg = HIY"\n�����ţ�$N����"+weapon->name()+HIY"�������һ�Ű׻�������ǰ�弲��$n���С�\n"NOR;
        	     	 	message_vision(msg, me, target);
             		 	if (present(target,environment(me)) && me->is_fighting(target))
                                   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        	     		if (present(target,environment(me)) && me->is_fighting(target))
                                   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        	     	 	if (present(target,environment(me)) && me->is_fighting(target))
				{
             				if(random(me->query("combat_exp"))>target->query("combat_exp")/2)
						COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
					else
						COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
				}
           		}
                           me->add_temp("apply/damage", -i/3);
           		me->add_temp("apply/attack", -i/2);
           		me->add_temp("apply/dexerity", -i/6);
           		me->delete_temp("juan");
           		me->start_perform(5,"������������");
         	}
         	else
		{
         		msg +=CYN"\n$n��æ���һ��������һ����������ɢ��������ʱ����������������������죬��߻�͡�\n"NOR;
           		message_vision(msg, me, target);
           		me->start_busy(1);
           		target->add("jingli", -60);
           		me->start_perform(3,"������������");
         	}
         	return 1;
        }
	// ������ֲ����õı����Ļ�
        if((random(ap) > dp/2 || random(target->query("pur")) >= 20)
         && me->is_fighting(target)){
           msg +=YEL"\n$nֻ�����������࣬�������������˼��£�����Ҫ˳���������֡�\n"NOR;
           message_vision(msg, me, target);
           me->add("neili", -200);
           target->set_temp("yueyin", i);
           target->add_temp("apply/parry", -i);

           target->add_temp("apply/dodge", -i);

	   busy = random(i/3)+1;
	   if(busy>10) 	busy = 10+random(busy-10)/5;
           target->start_busy(busy);
           target->apply_condition("no_perform", 1+random(2));
           me->start_perform(5,"������������");
           call_out("check_fight", 1, me, target, busy);
        }
        else{
           msg +=CYN"\n$n��æ���һ��������һ����������ɢ��������ʱ����������������������죬��߻�͡�\n"NOR;
           me->start_busy(1+random(2));
           message_vision(msg, me, target);
           target->add("jingli", -60);
           me->start_perform(3,"������������");
        }
        return 1;
}

void check_fight(object me,object target,int count)
{
        int j ;
        if(!target) return;
        j = target->query_temp("yueyin");
        if( !me
         || !me->is_fighting(target)
         || me->query_skill_mapped("whip") != "yinsuo-jinling"
         || !me->query_temp("weapon")
         || count -- < 1 ){
           target->add_temp("apply/parry", j );
           target->add_temp("apply/dodge", j );
           target->clear_condition("no_perform");
           if( target->is_busy()) target->start_busy(1);
           target->delete_temp("yueyin");
           message_vision(HIW"\n$N�����˲Ϣ֮��������䣬���ڻָ������ǡ�\n\n"NOR, target);
           return ;
        }
        call_out("check_fight", 1, me, target, count);
}
