// wushuai.c ������˥
// Rewrite By lsxk@hsbbs 2007/5/16

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIY"������˥"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i,j,lev,jiali;
    
    if( !target ) target = offensive_target(me);
     
    if( !userp(me) && userp(target) )
                return notify_fail("��������˥��ֻ�������ʹ�á�\n");

    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("��������˥��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query_skill_mapped("force") != "longxiang-boruo")
                return notify_fail("����ڹ����������������޷�ʹ�á�������˥����\n");

    if( (int)me->query_skill("longxiang-boruo", 1) < 150 )
                return notify_fail("������������ȼ��������޷�ʹ�á�������˥����\n");

    if( (int)me->query_skill("xiangfu-lun", 1) < 160 ) 
                return notify_fail("��Ľ�ս����ֻ�δ���ɣ��޷�ʹ�á�������˥����\n");

    if((int)me->query_skill("hammer", 1) < 160 )
                return notify_fail("��Ļ�������������죬����ʹ�á�������˥����\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "hammer"
        || me->query_skill_mapped("hammer") != "xiangfu-lun")
                return notify_fail("�����ʹ�ô���������ʹ����������˥��!\n");
                
   if((int)me->query_str() < 40)
           return notify_fail("�������������ǿ����ʹ������������˥��������\n");

   if(me->query_skill_mapped("parry") != "xiangfu-lun")
           return notify_fail("��������˥����Ҫʹ�ý����ַ��м�һ�ез�������\n"); 

   if((int)me->query("max_neili") < 3000 )
           return notify_fail("��������Ϊ��ǳ��ʹ������������˥����\n");  

   if( (int)me->query("neili") < 600 )
           return notify_fail("����������̫����ʹ������������˥����\n");

        message_vision(HIY"\nֻ������-��-��֮��������$N�����з�����ת������ʹ����������˥������������������\n"NOR, me,target);

    lev = (int)me->query_skill("xiangfu-lun",1)/4;

    if( me->query_temp("xs/longxiang") ) {
           message_vision(MAG"$N���������ھ����ڱ���֮�ϣ�"+weapon->query("name")+MAG"ͨ����������������ɫ��â��\n\n"NOR, me,target);
           lev *= 2;
           if(!userp(target)) target->start_busy(2);
       }

    me->start_perform(5,"��������˥��");
    me->add("neili", -300);
    me->set_temp("xfl/wushuai", 1);
        jiali = ((int)me->query("str",1)/2 + (int)me->query("con",1))/2 + random((int)me->query("jiali")/20 );
        me->add_temp("apply/damage",  lev);
me->add_temp("apply/attack", lev);
        me->add_temp("apply/strength", jiali);
        for (i=0;i<5;i++){
          j = i;
          if (i<1) j = 1;
          if (i>1) j = 3;
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"),j);
          me->add("neili", -200);
          }

        me->add_temp("apply/damage",  -lev);
        me->add_temp("apply/strength", -jiali);
me->add_temp("apply/attack", -lev);

    me->delete_temp("xfl/wushuai");
    target->add_busy(1);
    return 1;
}


