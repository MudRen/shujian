// jianzhang.c ����������

#include <ansi.h>
  string perform_name() {return HIC"����������"NOR;}

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = ( (int)me->query_skill("huashan-jianfa", 1) + (int)me->query_skill("hunyuan-zhang", 1) ) /2;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("����������ֻ����ս���жԶ���ʹ�á�\n");

      if (!weapon || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("parry") != "huashan-jianfa")
      return notify_fail("������û�н����޷�ʹ�ý�����������\n");             
  
     if(me->query_skill_mapped("sword") != "huashan-jianfa")
     if(me->query_skill_mapped("sword") != "dugu-jiujian")
       return notify_fail("�㲻ʹ�û�ɽ�������ʹ�ý�����������\n");             


    if( (int)me->query_skill("sword",1) < 100 )
      return notify_fail("��Ļ��������ȼ�����������ʹ�ý�����������\n");  

      if( (int)me->query_skill("hunyuan-zhang", 1) < 100 )
      return notify_fail("��Ļ�Ԫ�Ʒ��ȼ�����������ʹ�ý�����������\n");

      if( (int)me->query_skill("huashan-qigong", 1) < 60 )
           if( (int)me->query_skill("zixia-gong", 1) < 60 )
      return notify_fail("��������ڹ��ȼ�����������ʹ�ý�����������\n");
    
  if( (int)me->query("max_neili") < 200 )
      return notify_fail("�������̫��������ʹ�ý�����������\n");
      
      if( (int)me->query("neili") < 100 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó�������������\n");   
                                                                                 
      if (me->query_skill_prepared("strike") != "hunyuan-zhang"
          || me->query_skill_mapped("strike") != "hunyuan-zhang")
      return notify_fail("�������޷�ʹ�ý������������й�����\n");             

      message_vision(HIG"\n$NͻȻ��ʽһ�䣬���м��ƣ����вؽ�����$n����������������,���ǻ�ɽ���ھ�ѧ��"HIR"����������"HIG"����\n"NOR, me,target);
if(me->query("quest/zixia/pass") && me->query_temp("zxg"))
{ message_vision(HBMAG"$N������ϼ�񹦣�����ɽ�������ӵ����쾡�£�ʹ����Ȼֻ����ͨ��ʽ������ȴ�޿�ƥ�У�\n"NOR, me,target);
  me->add_temp("apply/damage", lvl/3  ); 
target->add_busy(2);
target->set_temp("must_be_hit",1);
me->set_temp("zixia_up",1);}
      me->add("jingli", -200);      
      me->add_temp("apply/strength", lvl /20 );
      me->add_temp("apply/sword", lvl/4);
      me->add_temp("apply/damage", lvl /4 );
      me->add_temp("apply/attack", lvl /4);
if(!userp(target)) target->add_busy(1);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
      weapon->unequip(); 
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
  if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
      me->add_temp("apply/strength", -lvl /20 );
      me->add_temp("apply/attack", -lvl /4);
      me->add_temp("apply/sword", -lvl/4 );
      me->add_temp("apply/damage", -lvl /4  );
      weapon->wield();
if(me->query_temp("zixia_up")) {
  me->add_temp("apply/damage", -lvl/3  ); 
if(target) target->delete_temp("must_be_hit");
me->delete_temp("zixia_up");}
      me->start_perform(3 + random(2), "��������������");
      return 1;
}


int help(object me)
{
    write(WHT"\n��ɽ������"HIC"����������"WHT"����"NOR"\n");
    write(@HELP
    ��ɽ���ھ����������������������������ơ�
    ָ� perform sword.jianzhang

     Ҫ����ϼ�� 60������ 
          ��ɽ���� ��Ԫ�� ��100����
          ��Ҫ���൱��������Ϊ
          �������� ��ɽ�����������Ʒ� ��Ԫ��
HELP
);
 return 1;
}


