//Modified by zhuifeng@SJFY
//Update by Jpei 2010

#include <ansi.h>
inherit F_SSERVER;

string perform_name(){ return HIC"��"HIG"��"HIY"��"HIB"��"NOR; }

int perform(object me, object target)
{
        int skill,lvl,i,hits;
        object weapon;

    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) 
    	|| !me->is_fighting(target) 
    	|| !living(target)
      || environment(target)!=environment(me))
                return notify_fail("��������졹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("force") != "beiming-shengong")
        if (me->query_skill_mapped("force") != "bahuang-gong" )                
                return notify_fail("����ڹ������޷�ʹ�á�������졹��\n");

       	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 100 )
       	if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 100 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�á�������졹��\n");

    if((int)me->query_skill("force", 1) < 100 )
                return notify_fail("��Ļ����ڹ�������죬�޷�֧�֡�������졹��\n");

    if( (int)me->query_skill("tianyu-qijian", 1) < 100 ) 
                return notify_fail("��Ľ�����δ���ɣ�����ʹ�á�������졹��\n");

    if((int)me->query_skill("sword", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ�á�������졹��\n");

    if((int)me->query_skill("dodge", 1) < 100 )
                return notify_fail("��Ļ����Ṧ������죬����ʹ�á�������졹��\n");

    if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "tianyu-qijian"
        || me->query_skill_mapped("parry") != "tianyu-qijian")
                return notify_fail("�������޽������ʹ�á�������졹��\n");
                
    if((int)me->query("max_neili") < 1000 )
                return notify_fail("�������������㣬����ʹ�á�������졹��\n");

    if((int)me->query("neili") < 800 )
                return notify_fail("�������������㣬����ʹ�á�������졹��\n");

    if((int)me->query("jingli") < 500 )
                return notify_fail("������̫���ˣ�����ʹ�á�������졹��\n");

        me->add("neili",-350);
  
      lvl = me->query_skill("tianyu-qijian",1);
      
      hits = lvl /100;
     if(hits>5) hits=5; 
     
      skill = me->query_skill("tianyu-qijian",1)/2 + me->query_skill("bahuang-gong", 1) /2 ;
      skill = skill /4;


      me->add_temp("apply/attack", skill);	
      me->add_temp("apply/damage", skill);
      me->add_temp("apply/sword",  skill/2);


    message_vision(HIW"\n$N�����ת���飬���е�"+weapon->name()+""HIW"�����������Ľ��⣬��������Ʈ�ݣ����������潣֮��"HIC"��"HIG"��"HIY"��"HIB"��"HIW"����\n" NOR,me,target);       




   for( i = 0; i < hits; i ++ ) {

     if (target && me->is_fighting(target) )    
 { 
               
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
 
  }
     else break;
 }



//���ø�С�ɰ� 
if(me->is_fighting(target) && lvl >= 450 && living(target) ) 
 { 
        me->add_temp("apply/damage", lvl);
        target->set_temp("must_be_hit",1);
        message_vision(HIW" �����һ��Яǰ������֮�������������������ǵ��޿ɵ���\n" NOR,me,target);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        target->delete_temp("must_be_hit",1) ;
       me->add_temp("apply/damage", -lvl);
      message_vision(WHT"$N����ʹ�ϣ�"+weapon->name()+""WHT"������һ�գ���������һƬ����������һ�ӡ�\n" NOR,me,target);

if(me->is_fighting(target))
        if (random(me->query("combat_exp")/10000)> target->query("combat_exp")/20000 )
             {                
        message_vision(HIC "$nֻ�����˿�һ�䣬ԭ���Ѿ���������Ϣ�б�������һ����������\n" NOR,me,target);
       target->apply_condition("shengsi_poison",2);
              }
        else   
      message_vision(HIC "$nֻ���ö���һ�䣬��æ���ã�ԭ��ȴ��$N������Ϣ�з�����һ�������������ɵþ�����һ���亹��\n" NOR,me,target);

 }


	      me->add_temp("apply/attack", -skill);
              me->add_temp("apply/sword",  -skill/2);
              me->add_temp("apply/damage", -skill);
        me->start_busy(1);
        me->start_perform(3+random(2),"��������졹");
        return 1;
}

int help(object me)
{
    write(WHT"\n�����潣֮��"MAG"�������"WHT"����"NOR"\n");
         write(@HELP
   �����潣֮����������죬�������飬�������У�
   ���е�����֮�������������߽����������ҡ�
   ���ҿ������мд������������˷���ʤ����
      
    Ҫ�� �˻�����Ψ�Ҷ���100��
        �����潣�����������������Ṧ��100��
        �����мܽ���Ϊ �����潣
        �������1000����ǰ����800����ǰ����500
HELP
    );
        return 1;
}
