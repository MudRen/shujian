// xiaoyao.c ��ң
// modified by action@SJ 28/12/2008
// modified by zhuifeng@SJFY 2010/7/20

#include <ansi.h>
  string perform_name() {return HIC"��ң"NOR;}

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = ( (int)me->query_skill("ruyi-dao", 1) /4+ (int)me->query_skill("liuyang-zhang", 1) ) /4;
      if(!userp(me)) lvl = lvl /2 ;

      if( !target ) target = offensive_target(me);
     
  if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("��ң��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

      if (!weapon || weapon->query("skill_type") != "blade"
       || me->query_skill_mapped("blade") != "ruyi-dao"
       || me->query_skill_mapped("parry") != "ruyi-dao")
      return notify_fail("������û�е����޷�ʹ����ң��\n");  
                 
      if( (int)me->query_skill("blade",1) < 200 )
      return notify_fail("��Ļ��������ȼ�����������ʹ�á���ң����\n");  

      if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
      return notify_fail("�����ɽ�����Ƶȼ�����������ʹ�á���ң����\n");
   
   if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 250 )
	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 200 )
      return notify_fail("��ı�ڤ�񹦵ȼ�����������ʹ�á���ң����\n");
  
  

         if (me->query_skill_mapped("force") != "bahuang-gong" )       
      if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
                
      if( (int)me->query("max_neili") < 4000 )
      return notify_fail("�������̫��������ʹ�á���ң����\n");
      
      if( (int)me->query("neili") < 2000 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó�����ң����\n");   
                                                                                 
      if (me->query_skill_prepared("strike") != "liuyang-zhang"
          || me->query_skill_mapped("strike") != "liuyang-zhang")
      return notify_fail("��ʹ�������ƣ������ʹ�á���ң�����й�����\n");             

      message_vision(HIC"\n$N�ڻ��ͨ��ң����ѧ��ʹ����ң���书֮���衸��ң����ѧ����$n���赭д�Ļӳ��������ƣ�\n"NOR, me,target);
if(!userp(target)) target->add_busy(2);
me->set_temp("xiaoyao",1);
      me->add("neili", -300); 
      me->add("jingli", -200);      
      me->add_temp("apply/strength", lvl /10 );
              if (me->query("family/family_name") == "��ң��") {
      me->add_temp("apply/blade", lvl/2);
      me->add_temp("apply/damage", lvl/2);
    };
                  if (me->query("family/family_name") == "���չ�") {
      me->add_temp("apply/blade", lvl);
      me->add_temp("apply/damage", lvl);
      me->add_temp("apply/attack", lvl /2);
    };
    
    
      me->add_temp("apply/attack", lvl /2);

  if( random(lvl*3) > (int)target->query_skill("parry",1) /3 )
      target->start_busy(1 + random(1)) ;
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);  
      
if (me->is_fighting(target)){
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);  
      weapon->unequip(); }
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
  if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  
     me->add_temp("apply/strength", -lvl /10 );
      if (me->query("family/family_name") == "��ң��") {
      me->add_temp("apply/blade", -lvl/2);
      me->add_temp("apply/damage", -lvl/2);
    };
                   if (me->query("family/family_name") == "���չ�") {
      me->add_temp("apply/blade", -lvl);
      me->add_temp("apply/damage",- lvl);
      me->add_temp("apply/attack", -lvl /2);
    };
    
      me->add_temp("apply/attack", -lvl /2);
      weapon->wield();
me->delete_temp("xiaoyao");
      me->start_perform(3 + random(2), "����ң��");
      return 1;
}

int help(object me)
{
        write(HIC"\n���⵶��֮����ң����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 4000 ���ϣ�
                ���⵶���ȼ� 200 ���ϣ�
                ��ڤ�񹦵ȼ� 200 ���ϣ�
                ��ɽ�����Ƶȼ� 200 ���ϣ�
                ��������Ϊ���⵶����
                �����м�Ϊ���⵶����
                �����Ʒ�Ϊ��ɽ�����ƣ�
                ���ַ�Ϊ��ɽ�����ƣ�
                ���ֱֳ�����

HELP
        );
        return 1;
}
