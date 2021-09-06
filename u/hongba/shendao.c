// shendao.c  Ѫ���� [��]
// changed by emnil@sj  2/5/2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, weaname;
        int lvl,damage;
    
        if( !me->is_fighting() )
                return notify_fail("���񵶴��ġ�ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if((int)me->query_dex() < 28)
                return notify_fail("���������, Ŀǰ������ʹ���������! \n");

        if((int)me->query_skill("dodge") < 110)
                return notify_fail("����Ṧ��Ϊ����, ����ʹ�á��񵶴��ġ���\n");
 
        if((int)me->query_skill("xuedao-jing",1) < 100)
                return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ�á��񵶴��ġ�! \n");

        if((int)me->query_skill("longxiang-boruo",1) < 100)
                return notify_fail("��������������Ϊ������ Ŀǰ����ʹ�á��񵶴��ġ�! \n");

        if( me->query_skill_mapped("blade") != "xuedao-jing")
                return notify_fail("�����ʹ��Ѫ����������ʹ�á��񵶴��ġ��ľ�����\n");

        if( me->query_skill_mapped("force") != "longxiang-boruo" && me->query_skill_mapped("force") != "shenzhao-jing"  )
                return notify_fail("��������ʹ�õ��ڹ��ȷ������ַ����չ�������ʹ�����񵶴��ġ��ľ�����\n");

        if( (int)me->query("max_neili") < 1300 )
                return notify_fail("���������Ϊ������\n");
        if((int)me->query("neili")<600)
                return notify_fail("�������������\n"); 
        if((int)me->query("jingli")<200)
                return notify_fail("��ľ���������\n"); 

        ob = me->select_opponent();
        lvl = me->query_skill("xuedao-jing",1);
        weapon = me->query_temp("weapon");
        weaname = weapon->query("name");
        msg = HIR "\n$N��Х���У������񵶴��ġ��ؾ���ɲʱ����磬"NOR+weaname+HIR"һ��Ϊ�ģ�������ȥ��\n"NOR;
        message_vision(msg, me);
        
        if(me->query_temp("xs/longxiang")) {
                damage = me->query_skill("longxiang-boruo",1)/2;
                if(damage > lvl/3) damage = lvl/3;
                me->add_temp("apply/damage", damage);
                message_vision(MAG"$N���������ھ����ڱ���֮�ϣ�"+weaname+MAG"ͨ����������������ɫ��â��\n"NOR, me,target);
        }

 if(me->query_temp("sjz_power")) {
                damage = me->query_skill("shenzhao-jing",1)/2;
                if(damage > lvl/3) damage = lvl/3;
                me->add_temp("apply/damage", damage);
                message_vision(WHT"$N������������˳�Ƽ���������һ�䣬��Ȼ����ƽ����ȴ���н���$n��\n"NOR, me,target);
        }




if (me->query("quest/ѩɽ/shendao/jidao")) {
if (!userp(target)) target->set_temp("must_be_hit",1);
me->add_temp("apply/attack", lvl);
me->add_temp("apply/party", lvl);
me->add_temp("apply/dodge", lvl);
msg = RED"$N������ʱ����ľ��跢�ӳ�����˫Ŀ��죬�˵���һ��ֱȡ$n���࣬���ϡ��񵶴��ġ�֮�⡣\n"NOR;
 if (present(ob,environment(me)) && me->is_fighting(ob))
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

target->receive_damage("qi", damage*2, me);
target->receive_wound("qi", damage*3, me);

msg += COMBAT_D->damage_msg(damage,"����",me,target);
 message_vision(msg,me,target);


}
        me->add_temp("apply/blade", lvl/4);
 me->add_temp("apply/damage", lvl/2);


        if (present(ob,environment(me)) && me->is_fighting(ob))
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        if (present(ob,environment(me)) && me->is_fighting(ob))
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        if(lvl >150)
                if (present(ob,environment(me)) && me->is_fighting(ob))
                        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        if(lvl >180)
                if (present(ob,environment(me)) && me->is_fighting(ob))
                        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -200-random(300));
        if(me->query("neili")<0) me->set("neili",0);
        me->add("jingli", -80);
        me->start_busy(random(2)+ 2);
        me->start_perform(3,"�񵶴���");
        me->add_temp("apply/blade", -lvl/4);
        me->add_temp("apply/damage", -lvl/2);

        
        if(me->query_temp("xs/longxiang")) {
            me->add_temp("apply/damage", -damage);
        }
 if(me->query_temp("sjz_power")) {
            me->add_temp("apply/damage", -damage);
        }

if (me->query("quest/ѩɽ/shendao/jidao")) {

 me->add_temp("apply/attack", -lvl);
me->add_temp("apply/party", -lvl);
me->add_temp("apply/dodge", -lvl);
target->delete_temp("must_be_hit",1);
}
        return 1;
}

