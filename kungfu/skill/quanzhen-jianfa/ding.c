// ding. ������
// Modified by action@SJ
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

string perform_name() {return HIB"������"NOR;}

int perform(object me, object target)
{        
        object weapon;
        int damage,p,force;
        string msg, *limbs;
        weapon = me->query_temp("weapon");

        if( !target) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("�������롹ֻ����ս���жԶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");    

        if( (int)me->query_skill("xiantian-gong",1) < 100 )
                return notify_fail("������칦�ȼ�����������ʩչ�������롹��\n");

        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʩչ�������롹��\n");
                
        if ((int)me->query_skill("quanzhen-jianfa", 1) < 100)
                return notify_fail("���ȫ�潣��������죬����ʹ�á������롹��\n");
                
        if (me->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("��û�м���ȫ�潣��������ʹ�á������롹��\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("����������㣬����ʩչ�������롹��\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("����������㣬����ʩչ�������롹��\n");

        if( (int)me->query("jingli") < 300 )
                return notify_fail("��ľ������㣬����ʩչ�������롹��\n");

        if( target->is_busy()) 
                 return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʩչ�������롹��\n");

        me->start_perform(2, "�������롹");

        force = me->query_skill("force") + me->query_skill("xiantian-gong", 1)/10;
        tell_object(me,HIW"���������Ž���������̤��һ�С�"HIR"������"HIW"������б�̣�"+weapon->name()+""HIW"��ȻԾ����ٿ�Ļ��������ǹ⣬����"+target->name()+"��\n"NOR);
        if(random(force) > target->query_skill("force")/3){
           damage = force;
           damage += random(damage);
           if(target->query_skill("force") - 50 > force)
             damage = damage/2;
           if(target->query_skill("force") > (force)*2)
              damage = random(10);
           if((force) > target->query_skill("force")*2)
              damage = damage+random(damage);
             if (damage > 1500) damage = 1500;
           if(damage > 300)
              tell_object(target, HIB"\nͻȻ֮�䣬���ؿ�һʹ���ƺ���һö��ϸ�ļ������һ�¡���һ�´�ʹ\n"+
                                     "ͻ�������������Σ�ʵ���ʣ�һ�ɽ���ͻ����Ļ����񹦣�ֱ�����ķΣ�\n"NOR);            
           target->receive_damage("qi", damage, me);
           target->receive_wound("qi", damage/3, me);
           me->receive_damage("neili", damage/3);
           limbs = target->query("limbs");
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"����ȫ���������һ����һ��һ����飡\n" NOR, ({ target }));  
           msg = damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR); ;
           me->start_busy(1);
           me->add("jingli", -20);
           target->start_busy(2+random(4));
           return 1;
        }        
        else {
           me->add("neili", -50);
           me->add("jingli", -5);
           tell_object(me, HIY"����"+target->name()+"�����������ͼ��бԾ�ܿ��˹�����\n"NOR);
           me->start_busy(2);         
        }
        return 1;
}

