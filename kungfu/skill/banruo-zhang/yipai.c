//banruo-zhang's perform yipai(һ����ɢ)
//cool 981226

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, i;
        mapping pre;
        string *skill, a, b;
        
        if( !objectp(target) ) target = offensive_target(me);
        
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) || !living(target) 
         || environment(target)!=environment(me))
                return notify_fail("һ����ɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");      

        if((int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("��İ����ƻ���������������ʹ��һ����ɢ���жԵУ�\n");

        if((int)me->query_skill("yijin-jing", 1) < 180 )
                return notify_fail("����׽������������������ʹ��һ����ɢ���жԵУ�\n");
 
        if((int)me->query_skill("strike", 1) < 180 )
                return notify_fail("����Ʒ�������죬ʹ���������Ƶľ��У�\n");
                
        if(objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á�һ����ɢ����\n");
        
        if (me->query_skill_prepared("strike") != "banruo-zhang"
         || me->query_skill_mapped("strike") != "banruo-zhang")
                return notify_fail("������Ƚ��������������Ʒ�֮�в��С�\n");

        if(me->query_skill_mapped("parry") != "banruo-zhang")
                return notify_fail("������Ƚ��������������м�֮�в��С�\n");

        if((int)me->query("max_neili") < 3000 )
                return notify_fail("��������Ϊ���㣬ʹ���������Ƶľ��У�\n");     

        if( (int)me->query("neili") < (int)me->query("max_neili")*2/3 )
                return notify_fail("�������������㣬ʹ���������Ƶľ��У�\n");     

        if( (int)me->query("jingli") < me->query("eff_jingli")/2 )
                return notify_fail("�����ھ������㣬ʹ���������Ƶľ��У�\n");   
                
//        me->start_perform(15, "һ����ɢ");

        message_vision(HIR"\n$N��עһ������ȫ��������һ��֮���ĳ���\n" NOR, me);
 
        pre = me->query_skill_prepare();
        skill = keys(pre);     
        for (i=0; i<sizeof(skill); i++){
                if(skill[i]=="strike") continue; 
                a = skill[i];
                b = pre[skill[i]];
                me->prepare_skill(skill[i]);
        }
         
        if ( (int)me->query("combat_exp",1) < (int)target->query("combat_exp",1) )
                damage = me->query("neili")/10;
        else    damage = me->query("neili")/3;
        me->set_temp("brz_yipai", 1);
        me->set("jiali", damage);

        if(wizardp(me))  tell_object(me, "Jiali = "+damage+"��");

        if( !me->query_temp("sl/xiouliqiankun") && !me->query_temp("fumo")){
                me->add_temp("apply/attack", me->query_int());
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); // attack in normal power. snowman@SJ
                me->add_temp("apply/attack", -me->query_int());
        }
        
        me->prepare_skill(a,b);
        
        me->set("neili", 0);
        me->set("qi",10);
//        me->set("eff_qi";10);
//        me->set("jingli",0);
        me->set("jing",0);     
        me->delete("jiali");
//        me->set("jingli", me->query("eff_jingli")/2);
        
        if(!target->is_killing(me->query("id"))) 
                target->kill_ob(me); // hehehehehehe.....
        me->start_busy(5);
        if(!target->is_busy())
                target->start_busy(1); 
        return 1;
}
string perform_name(){ return HIR"һ����ɢ"NOR; }
