// sanwu.c ����������
// By River@SJ 02/16/2001

#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>
string perform_name(){ return HIW"����������"NOR; }
int perform3(object me,object target);
int perform2(object me,object target);

int perform(object me, object target)
{       
        string msg, dodge_skill;
        int i, damage, ap, dp;
        object weapon;
        
        if( !me->query("gmsanwu")) return notify_fail("�㻹���ᡸ���������֡����������\n");
        if( !target ) target = offensive_target(me);
 
         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target))
                return notify_fail("�����������֡�ֻ����ս����ʹ�á�\n");

        if( !living(target))
                return notify_fail("�Է��Ѿ��ι�ȥ�ˡ�\n");
                
        if( !objectp( weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "whip" )
                return notify_fail("��װ�����������ԣ��޷�ʩչ�����������֡���\n");

        if( (int)me->query_skill("yinsuo-jinling", 1) < 120 
         || (int)me->query_skill("meinu-quanfa", 1) < 120 
         || (int)me->query_dex() < 28)
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á����������֡���\n");

        if(me->query_skill("yunu-xinjing", 1) < 120)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ���������������֡���\n");        
         
        if(me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

        if (me->query_skill_prepared("cuff") != "meinu-quanfa" 
         || me->query_skill_mapped("cuff") != "meinu-quanfa"
         || me->query_skill_mapped("whip") != "yinsuo-jinling" )
                return notify_fail("�������޷�ʹ�á����������֡����й�����\n");

        if (me->query_skill_mapped("parry") != "yinsuo-jinling")
                return notify_fail("����ʹ�õ��мܲ��ԡ�\n");

        if((int)me->query("max_neili") < 1300 )
                return notify_fail("���������Ϊ̫��������ʹ�á����������֡���\n");

        if((int)me->query("neili") < 800 )
                return notify_fail("�������������\n");
            
        me->start_perform(4, "����������");

        msg = HIM"ͻȻ��ֻ����Ӱ�϶�����ǰ�����"+weapon->query("name")+HIM"��Ӱ�ӡ�$N��һ�С��޿ײ��롹��������$n����\n"+
                 "�ٺ�����������һ�У���ʵǧͷ������һ��֮�а�������ʮ�У�����ͬʱ��$nȫ�������Ѩ��\n"NOR;

        ap = (int)me->query("combat_exp") * me->query_per();
        dp = (int)target->query("combat_exp")* target->query_per();

        if( random(ap) > dp /2 ){
                damage = (int)me->query_skill("yinsuo-jinling", 1);
                damage *= 10;
             if( damage > 2000 ) damage = 2000;
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3*2, me);
                target->set_temp("sanwu/wukong", 1);
                me->add("neili", - 200);
              msg += damage_msg(damage, "����")+
                "( $n"+eff_status_msg((int)target->query("qi")*100/(int)target->query("max_qi"))+" )\n"; 
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+ damage+ WHT"���˺���\n"NOR);
                i = me->query_skill("yinsuo-jinling", 1) / 15;
                call_out("perform_bonus", 1, me, target, i);
        }
        else {
                me->add("neili", -100);
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                               
        }        
        message_vision(msg, me, target);
        if( me->query_skill("meinu-quanfa", 1) >= 140 
         && me->query_skill("yinsuo-jinling", 1) >= 140
         && me->query("neili") > 800 )
         perform2(me, target);
        return 1;
}

int perform2(object me, object target)
{
        int i,ap,dp;
        string msg,dodge_skill;
        
        if(!target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) ){
               tell_object(me, "����Ҫ�ٷ�һ�У�ȴ���ֶ����Ѿ����ô��ˡ�\n");
               return 1;
        }

        ap = (int)me->query("combat_exp") * me->query_per();
        dp = (int)target->query("combat_exp")* target->query_per();             
        i = me->query_skill("meinu-quanfa", 1);

        msg = HIC"\n$N����һ�С���������������һ�е����$n�����ƫ��Ѩ����\n"NOR;
        if( random(ap) > dp/4*3 ){
                msg += HIR"$n�����������������ƫ��Ѩ�����������У�ȫ��Ȼ�᲻��һ˿������\n"NOR;
                target->add_temp("apply/attack", -i/6);
                target->add_temp("apply/damage", -i/6);
                target->add_temp("apply/defense", -i/6);
                if( random(2))
                   target->apply_condition("no_exert", 2);
                else  
                   target->apply_condition("no_perform", 2);
                target->set_temp("sanwu/wusuo", i/6);
                call_out("check_fight", 1, me, target, i/20);
                me->add("neili", -200);
        }
        else{
                  me->add("neili", - 100);
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
         message_vision(msg, me, target);
        if( me->query_skill("meinu-quanfa", 1) >= 160
         && me->query_skill("yinsuo-jinling", 1) >=160
         && me->query("neili") > 800 )
         perform3(me, target);
        return 1;
}

int perform3(object me, object target)
{
        object weapon;
        int i;

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) ){
               tell_object(me,"����Ҫ�ٷ�һ�У�ȴ���ֶ����Ѿ����ô��ˡ�\n");
               return 1;
        }

        weapon = me->query_temp("weapon");

        i = me->query_skill("meinu-quanfa",1);
        i += me->query_skill("yinsuo-jinling", 1);
        i /= 8;
        
               if(!userp(me)) i = i / 2;


        message_vision(HIW"\n$N�ĵ����֡�������Ϊ������ʹ������һ�в��ٵ�Ѩ��ר���۾����ʺ�С�����������������\n"+
                          "����֮�������Խ�����������Ϊ�������ݶ�����\n"NOR, me);

        if( !target->query_temp("sanwu/wusuo")){
                me->add_temp("apply/attack", i);
                me->add_temp("apply/whip", i);
                me->add_temp("apply/damage", i);
                me->set_temp("sanwu/buwei", i);
        }

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
 //      weapon->unequip(); 
        if (present(target,environment(me)) && me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if (present(target,environment(me)) && me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if (present(target,environment(me)) && me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
//      weapon->wield();

        if( me->query_temp("sanwu/buwei")){
                me->add_temp("apply/attack", -i);
                me->add_temp("apply/whip", -i);
                me->add_temp("apply/damage", -i);
                me->delete_temp("sanwu/buwei");
        }
        me->add("neili", -200);
        me->add("jingli", -100);
        me->start_perform(4, "����������");
        return 1;
}

void check_fight(object me,object target,int amount)
{        
        int j;
        if( !target ) return;
        if( !me
         || !me->is_fighting(target)
         || amount < 1){
              j = target->query_temp("sanwu/wusuo");
              target->add_temp("apply/attack", j);
              target->add_temp("apply/damage", j);
              target->add_temp("apply/defense", j); 
              target->delete_temp("sanwu/wusuo");
              message_vision(HIW"\n$NѨ���ѽ⣬������Ϊ֮һ��\n"NOR, target);
              return;
        }
        call_out("check_fight", 1, me, target, amount -1);
}

void perform_bonus(object me,object target,int amount)
{
        int j;
        object weapon;
        
        if( !target ) return;
        if( me
         && me->is_fighting(target)
         && me->query_skill_mapped("whip") =="yinsuo-jinling"
         && me->query_skill_mapped("cuff") =="meinu-quanfa"
         && me->query_skill_prepared("cuff") == "meinu-quanfa"
         && environment(me) == environment(target)
         && amount > 0){
                j = me->query_skill("yinsuo-jinling", 1);
                j += me->query_skill("meinu-quanfa", 1);
                weapon = me->query_temp("weapon");
                switch(random(4)){
                        case 0:
                              message_vision(HIR"\n$Nֻ����ȫ������Ѩ�����裬����̰��ʹ��\n"NOR,target);
                              target->receive_damage("jing", j);
                              target->receive_wound("jing", j);
                              break;
                        case 1:
                              message_vision(HIR"\n$Nֻ����ȫ������Ѩ�����裬���ɾ����㱣�ֻ�����ھ��޷����ơ�\n"NOR,target);
                              target->add("neili", -j*3);
                              if(target->query("neili") < 0) target->set("neili", 0);
                              target->add("jingli", -j);
                              break;                          
                        case 2:
                              message_vision(HIR"\n$Nֻ����ȫ������Ѩ�����裬���β���һ�ͣ��ж����㡣\n"NOR,target);
                              if(!target->is_busy())
                              target->start_busy(2+random(3));
                              break;
                        case 3:
                              message_vision(HIR"\n$Nֻ����ȫ������Ѩ�����裬$N�û��������С�\n"NOR,target);
                              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                              if (weapon) weapon->unequip(); 
                              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
                              if (weapon) weapon->wield();
                              break;
                }
     //           me->start_perform(3, "����������");
                call_out("perform_bonus", 3, me, target, amount - 3);
        }
        else {
                target->delete_temp("sanwu/wukong");
                return;
        }
}
