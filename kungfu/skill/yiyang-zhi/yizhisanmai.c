// Modified by snowman@SJ 05/12/2000
// Update By lsxk@hsbbs 2007/6/14

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

void remove_effect(object me, int improve);

string perform_name() {return HIR"һָ������"NOR;}

int perform(object me, object target)
{
        int lev;
        
        if( !target ) target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) 
         || !living(target) )
                return notify_fail("��һָ��������ֻ����ս����ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á�һָ����������\n");   

        if( (int)me->query_skill("yiyang-zhi", 1) < 120 )
                return notify_fail("���һ��ָ��������죬ʹ������һָ��������������\n");

        if((int)me->query_skill("force",1) < 120 ) 
                return notify_fail("����ڹ���Ϊ��������ʹ������һָ��������������\n");

        if( me->query_temp("pf_rong"))
                return notify_fail("���������á��١��ִ󷨣�\n"); 

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 120)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������һָ����������\n");        

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ�á�һָ����������\n"); 

        if (me->query_skill_mapped("force") != "kurong-changong" )
          if(me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");                

        if( (int)me->query("max_neili") < ((int)me->query_skill("force",1)+1000) )
                return notify_fail("����������̫����ʹ������һָ����������\n");      

        if( (int)me->query("neili") < ((int)me->query_skill("force",1)+1100) )
                return notify_fail("����������̫����ʹ������һָ����������\n");

        if( (int)me->query("jingli") < ((int)me->query_skill("force",1)+ 800) )
                return notify_fail("�����ھ���̫�٣�ʹ������һָ����������\n");

        lev = (int)me->query_skill("yiyang-zhi", 1)/4;
        
        if(!userp(me)) lev = lev *2 /3 ;
         if(userp(me)) lev = lev * 2 ;
        message_vision(HIR"\n$N��ָ�滺���磬�ձ�����Ʈ�ݣ��ֱ۲������������ѵ�ˮ��һָ���������Ϯ����������������ף�\n"NOR,me,target);

        me->add_temp("apply/strength", lev /5);
        me->add_temp("apply/attack", lev);
        me->add_temp("apply/damage", lev * 2);
        me->add_temp("apply/finger", lev);


        me->set_temp("yyz/yz3m",3);
if(!userp(target)&& lev>=251) target->start_busy(2);
         COMBAT_D->do_attack(me, target, 0, 3);
        me->add_temp("yyz/yz3m",-1);
 
if( me->is_fighting(target)) {
         COMBAT_D->do_attack(me, target, 0, 3);
            me->add_temp("yyz/yz3m",-1);
        }

if( me->is_fighting(target) && (int)me->query_skill("yiyang-zhi",1) > 199 ) {
      	 COMBAT_D->do_attack(me, target, 0, 3);
	    me->add_temp("yyz/yz3m",-1);
        }

        me->start_busy(1);
        me->delete_temp("yyz/yz3m");

        me->add_temp("apply/strength", -lev /5);
        me->add_temp("apply/attack", -lev);
        me->add_temp("apply/damage", -lev * 2);
        me->add_temp("apply/finger", -lev);

        me->add("neili", -300);
        me->add("jingli", -100);
        me->start_perform(5,"��һָ��������");
        return 1;
}




int yzsm_attack(object me, int flag)
{
        object target;
        int lev;
        
        if( !target ) target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) 
         || !living(target) )
                return notify_fail("��һָ��������ֻ����ս����ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á�һָ����������\n");   

        if( (int)me->query_skill("yiyang-zhi", 1) < 120 )
                return notify_fail("���һ��ָ��������죬ʹ������һָ��������������\n");

        if((int)me->query_skill("force",1) < 120 ) 
                return notify_fail("����ڹ���Ϊ��������ʹ������һָ��������������\n");

        if( me->query_temp("pf_rong"))
                return notify_fail("���������á��١��ִ󷨣�\n"); 

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 120)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������һָ����������\n");        

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ�á�һָ����������\n"); 

        if (me->query_skill_mapped("force") != "kurong-changong" )
          if(me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");                

        if( (int)me->query("max_neili") < ((int)me->query_skill("force",1)+1000) )
                return notify_fail("����������̫����ʹ������һָ����������\n");      

        if( (int)me->query("neili") < ((int)me->query_skill("force",1)+1100) )
                return notify_fail("����������̫����ʹ������һָ����������\n");

        if( (int)me->query("jingli") < ((int)me->query_skill("force",1)+ 800) )
                return notify_fail("�����ھ���̫�٣�ʹ������һָ����������\n");

        lev = (int)me->query_skill("yiyang-zhi", 1)/4;
        
        if(userp(me))  lev = lev * flag;
            


        message_vision(HIR"\n$N��ָ�滺���磬�ձ�����Ʈ�ݣ��ֱ۲������������ѵ�ˮ��һָ���������Ϯ����������������ף�\n"NOR,me,target);

        me->add_temp("apply/strength", lev /10);
        me->add_temp("apply/attack", lev/ 2);
        me->add_temp("apply/damage", lev);
        me->add_temp("apply/finger", lev);


        me->set_temp("yyz/yz3m",3);
        
         COMBAT_D->do_attack(me, target, 0, 3);
        me->add_temp("yyz/yz3m",-1);
 
if( me->is_fighting(target)) {
         COMBAT_D->do_attack(me, target, 0, 3);
            me->add_temp("yyz/yz3m",-1);
        }

if( me->is_fighting(target) && (int)me->query_skill("yiyang-zhi",1) > 199 ) {
      	 COMBAT_D->do_attack(me, target, 0, 3);
	    me->add_temp("yyz/yz3m",-1);
        }

        me->start_busy(1);
        me->delete_temp("yyz/yz3m");

        me->add_temp("apply/strength", -lev /10);
        me->add_temp("apply/attack", -lev/ 2);
        me->add_temp("apply/damage", -lev);
        me->add_temp("apply/finger", -lev);

        me->add("neili", -300);
        me->add("jingli", -100);
        me->start_perform(5,"��һָ��������");
        return 1;
}















int help(object me)
{
   write(WHT"\nһ��ָ֮��"HIR"һָ������"WHT"����"NOR"\n\n");
   write(@HELP

     Ҫ��: ����������ڻ����ڹ�1000�����ϣ�
           ��ǰ�������ڻ����ڹ�1100�����ϣ�
           ��ǰ�������ڻ����ڹ�800�����ϣ�
           һ��ָ�ȼ� 120 ���ϣ�
           �����ڹ��ȼ� 120 ���ϣ�
           �����ڹ��ȼ� 120 ���ϣ�
           ����ָ��Ϊһ��ָ��
           ���֣���һ��ָ��

           ������ set һ��ָ��Ѩ ������������

HELP
   );
   return 1;
}
