// 一剑落九雁 by hongba
#include <ansi.h>
inherit F_SSERVER;
    
   string perform_name(){ return HIM"一剑落九雁"NOR; }
    
   int perform(object me,object target)
 {
       object weapon;
      int i;
      
       if( !target ) target = offensive_target(me);
       
       if( !objectp (target) || !me->is_fighting(target) || !living(target)
          || environment(target)!=environment(me))
                   return notify_fail("一剑落九雁只能对战斗中的对手使用。\n");
  
      
       if( (int)me->query_skill("hengshan-jianfa", 1) < 250 ) 
                   return notify_fail("你的衡山剑法还未练成，不能使用一剑落九雁！\n");

                 
       if((int)me->query_skill("sword", 1) < 250 )
                   return notify_fail("你的基本剑法不够娴熟，不能在使用一剑落九雁。\n");
      
   if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
           || me->query_skill_mapped("sword") != "hengshan-jianfa"
           || me->query_skill_mapped("parry") != "hengshan-jianfa")
                   return notify_fail("你现在使得了一剑落九雁么？\n");
                   
       if((int)me->query("max_neili") < 4500 )
                  return notify_fail("你的内力修为不够，不能使用一剑落九雁！\n");
       if((int)me->query("neili") < 2000 )
                 return notify_fail("你现在真气不足，不能使用一剑落九雁！\n");
  
          message_vision(HIW"\n$N身形一变如分光掠影一般使出平生绝学。\n",me);
           message_vision(HIM"这正是衡山剑法的绝招「一剑落九雁」,据说此招练到绝顶便可一剑刺落九只大雁。\n",me);
          
   me->start_perform(2,"「一剑落九雁」");
       i = (int)me->query_skill("hengshan-jianfa",1);
      me->add("neili", -300);
          me->add_temp("apply/attack",  i);
         me->add_temp("apply/damage",  i/4);

         me->add_temp("apply/damage",  i/4);
      me->add_temp("hsjf_ly",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
     me->add_temp("hsjf_ly",1);
      if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
      me->add_temp("hsjf_ly",1);
      if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
      me->add_temp("hsjf_ly",1);
         me->add_temp("apply/attack",  -i);
           me->add_temp("apply/damage",  -i/4);
  
      if(me->query("hsjf_ly")){
   message_vision(HBYEL"$N已得「一剑落九雁」之精要，出招行云流水，刹那间$n已不知如何抵挡。"NOR,me,target);
 target->start_busy(3);
          me->add_temp("apply/attack",  i);
  me->add_temp("apply/damage",  i);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
          me->add_temp("hsjf_ly",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
         me->add_temp("hsjf_ly",1);

         me->add_temp("hsjf_ly",1);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
          me->add_temp("apply/attack",  -i);
   me->add_temp("apply/damage",  -i);
       }
if (random(me->query("kar")) > 10 && random(me->query("pur")) > 10 && me->query("hsjf_ly")){
                   if (wizardp(me))
                   
   message_vision(HIM"\n$N剑招一顿，突然使出一招「"HBRED"百变千幻云雾十三式"NOR""HIM"」。
这“百变千幻云雾十三式”乃是衡山派一位前辈所创，
本是由江湖杂耍演化而来，此刻$N使出，却是威力无比。\n"NOR, me, target);
 message_vision(CYN"\n$n一见之下，竟然无法躲过，胸前对穿一个拳大的血洞，眼见已无生地。\n"NOR, me, target);
          target->die();   // 貌似很流氓，条件很宽啊，嘿嘿，弄着玩呗。
            }
      me->delete_temp("hsjf_ly");
      me->start_busy(1);
     return 1;
 }

