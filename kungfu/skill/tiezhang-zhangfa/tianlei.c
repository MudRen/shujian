// tianlei.c ����--������
// rewrite by snowman@SJ 19/12/2000

#include <ansi.h>

inherit F_SSERVER;

#include <combat_msg.h>

string perform_name(){ return HBBLU"������"NOR; }
int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || !living(target)
          || environment(target)!= environment(me))
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if( me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ����������\n");
/*
        if((int)me->query_skill("guiyuan-tunafa", 1) < 150 )
                return notify_fail("�����������δ���ɣ�����ʹ�ã�\n");
 */              
        if((int)me->query("neili", 1) < 1000 )
                return notify_fail("�������������㣬����ʹ����������\n");       

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("parry") != "tiezhang-zhangfa")
                return notify_fail("�������޷�ʹ�á�����������\n");                                                                                 
/*
        if( me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("�����ڵ��ڹ��ò��ˡ�����������\n");   
*/               
        if(me->query_temp("tzzf"))
                return notify_fail("������ʹ���Ƶ���\n");

        if((int)me->query_skill("tiezhang-zhangfa", 1) < 150 )
                return notify_fail("��������Ʒ�������죬����ʹ����������\n");

        tell_object(me, HIW"\n��������һ������������ʦ�����ش��������������۵�˫��֮�С���\n"NOR);
        me->start_perform(3, "������");
        me->start_call_out( (: call_other, __FILE__, "tianlei_hit", me, 1 :), 1+ random(4) );
        return 1;
}

int tianlei_hit(object me, int flag)
{
        object target, weapon;
        int i, damage;
        string *limbs, msg, dodge_skill;
        
        if( !me || !living(me) ) return 0;
        
        if( !me->is_fighting() ){
                write("������ֻ����ս����ʹ�á�\n");
                return 0;
        }
        i = 5;
        target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target)
        || !living(target)
        || environment(target) != environment(me) ){
                write("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                return 0;
        }
        
        if( me->query_temp("weapon")
        && !me->query_temp("tzzf") ){
                write("�������ֲ���ʹ����������\n");
                return 0;
        }
        if( (int)me->query("neili", 1) < 600 ){
                write("�������������㣬����ʹ����������\n"); 
                return 0;
        }
        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("parry") != "tiezhang-zhangfa"){
                write("�������޷�ʹ�á�����������\n");   
                return 0;
        }
        
        me->start_perform(3 + random(2), "������");
        dodge_skill = (flag == 1)?"�� ���� �� ���� ��":"�� ���� �� ���� �� ���� һ";
        
        msg = HIY "\n$N��Ȼ������һ����"HIW + dodge_skill + HIY"����һ˫����ɲ�Ǽ���ѩ�ף��ƾ�֮�£�һ�����ȵ���������ƿ�쭶������Ʋ��ɵ���\n"NOR;

        if( me->query_temp("tzzf") ) flag=3;
        if( random((int)me->query("combat_exp", 1) * (flag+1) ) < (int)target->query("combat_exp", 1)/3
        || me->query("combat_exp") < target->query("combat_exp")/2 ){
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += "\n" + SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                limbs = target->query("limbs");
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))]);
                msg += HIY"$p��Σ���бܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
                message_vision(msg, me, target);
                if( !target->is_busy() ) target->start_busy(1);
                return 1;
        }
       
        damage = me->query_skill("tiezhang-zhangfa", 1) + me->query_skill("guiyuan-tunafa", 1) + me->query("jiali") * 4;
        damage = damage / 2 + random(damage / 2);
        damage *= 2;
        
        if( target->query("neili") < 10 || target->query("qi") <= 100 ) 
                damage = target->query("qi") + 1;
        else {
                if( me->query("neili") > target->query("neili") * 2 )
                        damage *= 2;
                else if( me->query("neili") > target->query("neili") /3*2 )
                        damage += random(damage);
                else if( me->query("neili") > target->query("neili") )
                        damage += random(damage/2);             
                else if( me->query("neili") < target->query("neili") / 2 )
                        damage /= 2;    
                else if( me->query("neili") < target->query("neili") /3*2 )
                        damage -= random(damage/2);
                damage *= flag; // call by other combo pfm...add damage rate;
        }
        
        msg += "$n���޿ɱܣ���һ���Ѿ�ӡ����ǰ�أ�\n";
        if( objectp(weapon = target->query_temp("weapon")) ){
                if( random(me->query_str()) > (int)target->query_str()/3
                && damage > 1000 ) { 
                        msg += HIM"$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"+weapon->query("name")+HIM"���ֶ�����\n" NOR;
                        weapon->unequip();
                        weapon->move(environment(target));
                }
                else if( target->query_str()/2 > random(me->query_str()) ){
                        msg += "$p�ۼ����Σ������æ��"+weapon->query("name")+"����ǰһ����ֻ����������һ�������ǵ�����һЩ������\n" NOR;
                        damage -= random(damage/2);
                }
        }
        if( wizardp(me) ) tell_object(me, "Damage = "+damage+"\n");
        
        if( !me->is_busy() ) me->start_busy(1);
        if( !target->is_busy() ) target->start_busy(1);
        target->receive_damage("qi", damage, me);
        if (me->query_temp("tzzf")) target->receive_wound("qi", damage *3/4, me);
        else target->receive_wound("qi", damage /3, me);
        target->receive_wound("qi", damage *3/4, me);
        i = (int)target->query("qi")*100/(int)target->query("max_qi");
        msg += damage_msg(damage, "����")+"( $n"+eff_status_msg(i)+" )\n"; 
        message_vision(msg, me, target);
        if( flag < 2 )
                me->add("neili", -400);
        
        return 1;
}
int help(object me)
{
        write(WHT"\n�����Ʒ�������������"NOR"\n");
        write(@HELP
        ������ǧ�����ƹ���ʮ������֮һ���������������������Ǿ���ʮ����ڹ�
        ������ƣ������ƵС��ǽ�����������ɱ��֮һ��
        
        Ҫ��  ���� 600 ���ϣ�   
                �����Ʒ��ȼ� 150 ���ϣ�
                ��Ԫ���ɷ��ȼ� 140 ���ϣ�    
                �����ޱ�����
HELP
        );
        return 1;
}

