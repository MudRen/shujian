// ��翽���
#include <ansi.h>
#include <combat.h> 
#include <skill.h>
string perform_name(){ return HBMAG"��翽���"NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
         string dodge_skill,msg;
         int i, j;
       object weapon;

    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) 
    	|| !me->is_fighting(target) 
    	|| !living(target)
      || environment(target)!=environment(me))
                return notify_fail("����翽�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

 
         if (me->query_skill_mapped("force") != "beiming-shengong")
         if (me->query_skill_mapped("force") != "bahuang-gong" )                
                return notify_fail("����ڹ������޷�ʹ�á���翽�������\n");

       	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 350 )
       	if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 350 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�á���翽�������\n");

    if((int)me->query_skill("force", 1) < 350 )
                return notify_fail("��Ļ����ڹ�������죬�޷�֧�֡���翽�������\n");

    if( (int)me->query_skill("tianyu-qijian", 1) < 350 ) 
                return notify_fail("��Ľ�����δ���ɣ�����ʹ�á���翽�������\n");

    if((int)me->query_skill("sword", 1) < 350 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ�á���翽�������\n");

    if((int)me->query_skill("dodge", 1) < 350 )
                return notify_fail("��Ļ����Ṧ������죬����ʹ�á���翽�������\n");

    if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "tianyu-qijian"
        || me->query_skill_mapped("parry") != "tianyu-qijian")
                return notify_fail("�������޽������ʹ�á���翽�������\n");
                
    if((int)me->query("max_neili") < 10000 )
                return notify_fail("�������������㣬����ʹ�á���翽�������\n");

    if((int)me->query("neili") < 6000 )
                return notify_fail("�������������㣬����ʹ�á���翽�������\n");

    if((int)me->query("jingli") < 3000 )
                return notify_fail("������̫���ˣ�����ʹ�á���翽�������\n");
                

       msg = HBMAG "$N��ͨ���չ���ѧ��ʹ�������չ��ľ�ѧ֮���裡\n" NOR;
           me->add("neili", -me->query("max_neili")/10);
       message_vision(msg, me, target);          
 
 
         me->set_temp("tyqj/piaomiao", 1);
         me->start_perform(4+random(2),"����翽�����");

         message_vision(MAG"\n$NǱ����ң�ķ���"+weapon->name()+MAG"��â�������������������ɱ��ӡ�\n"NOR,me,target);

         i = me->query_skill("tianyu-qijian", 1);
         j = me->query_skill("sword", 1) ;
         
if( me->query("quest/�����˲�/��ڤ��/pass") ){i = i * 2;
                                                j = j * 2;}
                                                
         me->add_temp("apply/attack", j/3);
         me->add_temp("apply/damage", j/3); 

         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),3); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),3); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),3);      

        me->add_temp("apply/attack", -j/3);
        me->add_temp("apply/damage", -j/3);
	 
    if (random(me->query("combat_exp")) > target->query("combat_exp")/2 && me->fighting(target) && living(target) ){
     message_vision(HIW"\n$N����˻�����Ψ�Ҷ��𹦣���������Ϣ�䷢��һ����������\n"NOR,me,target);
	  
           target->set_temp("must_be_hit",1);
           target->add_busy(2);
           target->apply_condition("no_fight",2);
           target->apply_condition("no_perform",2);

		}
        
        
        
         weapon->unequip();
         me->add_temp("apply/strength", i/10);
    
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);                                
         message_vision(HIM"���� ÷��"NOR, me, target); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);                                     
         message_vision(HIW"���� ѩ��"NOR, me, target); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);                                       
         message_vision(HIM"��ɢ���㡿\n"NOR, me, target); 
         me->start_busy(2);
         me->add_temp("apply/strength", -i/10);
         me->delete_temp("tyqj/piaomiao");
if(target)
	       target->delete("must_be_hit");
      
         weapon->wield();
          return 1;
 }

int help(object me)
{
    write(WHT"\n�����潣֮��"MAG"��翽���"WHT"����"NOR"\n");
         write(@HELP
   �����潣֮������翽��裬��֪��˭���ֱʣ������ǳ����졣
   �����������ơ������׵絯÷��ѩɢ���㣬���߿ﻹ��˹��

   Ҫ��
        �˻�����Ψ�Ҷ���350���������ڹ�350��
        �����潣�����������������Ṧ��350��
        �����мܽ���Ϊ �����潣
        �������10000����ǰ����6000����ǰ����3000
        ��������ľ޴󣬷������ಫ���������á�
HELP
    );
        return 1;
}
 
