// yunu-jianfa ��Ů����
// by dubei
// Modify By River 99.5.26
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string perform_name(){ return HIM"��Ů����"NOR; }
int perform(object me, string arg)
{
      object weapon, target;
      int dex,armor,skill;       
      dex = me->query_dex()*2;
      armor = me->query_int()*3;
      skill = me->query_skill("yunu-xinjing",1)/5 + me->query_skill("yunu-jianfa",1)/5;
      if (me->query("gender") == "Ů��") skill *= 5/4;
      weapon = me->query_temp("weapon");

      if( !target ) target = offensive_target(me);

      if( !target || !me->is_fighting(target) )
               return notify_fail("����Ů���ġ�ֻ����ս���жԶ���ʹ�á�\n");

      if ( !weapon
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunu-jianfa" 
        || me->query_skill_mapped("parry") != "yunu-jianfa")
               return notify_fail("��û����Ů���Ľ���ôʹ������Ů���ġ��أ��������ˣ�\n");

      if((int)me->query_skill("yunu-jianfa", 1) < 120 )
               return notify_fail("�����Ů������Ϊ���� ��\n");

      if((int)me->query_skill("sword", 1) < 120 )
               return notify_fail("��Ļ�������������죬ʹ��������Ů���ġ�������\n");

      if((int)me->query_dex() < 30)
               return notify_fail("�����������Ѹ�ݣ�ʹ��������Ů���ġ�������\n");

      if((int)me->query_skill("yunu-xinjing", 1) < 110 )   
               return notify_fail("�����Ů�ľ���Ϊ�������޷�ʹ�á���Ů���ġ�������\n");  
        if( me->query_skill_mapped("force") != "yunu-xinjing" && userp(me))
                return notify_fail("�������޷�ʹ�á���Ů���ġ���\n");
      if((int)me->query_temp("gumu_suxin")) 
               return notify_fail("����������ʹ�á���Ů���ġ�������\n"); 

        if( me->query_temp("wujian") )
                return notify_fail("������ʹ�á��޽�ʤ�н����أ�\n");

      if((int)me->query_temp("hebi"))
               return notify_fail("������ʩչ˫���ϱڣ��޷�ʹ�á���Ů��?ġ�������\n"); 

      if((int)me->query("max_neili") < 1000)
               return notify_fail("���������Ϊ������\n");

      if((int)me->query("neili") < 700)
               return notify_fail("�������������\n");

      if((int)me->query("jingli") < 600)
               return notify_fail("��ľ���������\n");

       me->add("neili", -300);
       me->add("jingli", -150);
       me->add_temp("apply/armor", armor);
       me->add_temp("apply/dexerity",dex);
       me->set_temp("gumu_suxin", 1); 
       message_vision(HIW"\n$N����һ����������������֮�����"+weapon->name()+HIW"�û���������â����$n�糸��ȥ��\n"NOR,me,target);
       me->add_temp("apply/damage", skill);

target->add_temp("lost_attack", 1+random(3));
if(random(2))   target->apply_condition("no_perform", 1+ random(2));
if(random(2) || !userp(target))   target->add_busy(2+random(2));

       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

       me->add_temp("apply/damage", -skill);

    if(me->query_skill("yunu-jianfa",1)<=550) 
       me->start_perform(1,"����Ů���ġ�");

       call_out("check_fight", 1, me, dex, armor, skill);
       return 1;
}

void remove_effect(object me, int dex, int armor, object weapon)
{      
       me->add_temp("apply/armor", -armor);
       me->add_temp("apply/dexerity",-dex);
       me->delete_temp("gumu_suxin");
       tell_object(me, HIW"�㡸��Ů���ġ�ʩչ��ϣ���������һ������\n" NOR); 
}

void check_fight(object me, int dex, int armor, int skill)
{
       object weapon;
       if (!me) return;
       if(!objectp(weapon = me->query_temp("weapon"))
         || me->query_skill_mapped("sword") != "yunu-jianfa"
         || me->query_skill_mapped("parry") != "yunu-jianfa"
         || me->query_skill_mapped("force") != "yunu-xinjing"
         || weapon->query("skill_type") != "sword"){
           remove_effect(me, dex, armor, weapon);
           return;
       }
       if( skill < 1 || !me->is_fighting()) {
           remove_effect(me, dex, armor, weapon);
           return;
       }
       call_out("check_fight", 1, me, dex, armor, skill-1);
}
