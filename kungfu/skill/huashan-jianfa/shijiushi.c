// shijiushi.c 玉女十九式

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
#define MAX_HITS   9
 
string perform_name() {return HIC"玉女十九式"NOR;}

int perform(object me, object target)
{
        string weapon;
        int i,hits,lvl;

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("玉女十九式只能对战斗中的对手使用。\n");
    
        if (me->query_skill_mapped("force") != "zixia-gong"
          &&me->query_skill_mapped("force") != "huashan-qigong")
                return notify_fail("你的内功有误，无法使用「玉女十九式」。\n");

        if( me->query_dex() < 60 )
                return notify_fail("你在身法上先天禀赋不足，不能使用玉女十九式！\n");
        
        if( me->query_skill("zixia-gong", 1) < 300
         && me->query_skill("huashan-qigong", 1) < 300)
                return notify_fail("你的特殊内功火候未到，无法施展玉女十九式！\n");

        if( (int)me->query_skill("huashan-jianfa",1) < 300 )
                return notify_fail("你的华山剑法火候不足，无法使用精妙绝伦的玉女十九式！\n");

        if( me->query_skill("dodge") < 300 )
                return notify_fail("玉女十九式需要超绝的轻功配合，方能有效施展！\n");

        if( me->query_skill("sword") < 300 )
                return notify_fail("你剑法未到炉火纯青之境，还不会使用玉女十九式！\n");

        if( me->query("neili") <= 5000 )
                return notify_fail("你的内力不够使用玉女十九式！\n");

        if( me->query("jingli") <= 3000 )
                return notify_fail("你的精力不够使用玉女十九式！\n");

        if( me->query_temp("hsj_19"))
                return notify_fail("你正在运用玉女十九式！\n");

      if(!me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("你手中无剑怎能使用玉女十九式？！\n");


      if(me->query_skill_mapped("sword") != "huashan-jianfa")
        if(me->query_skill_mapped("sword") != "dugu-jiujian")
                return notify_fail("你不用华山剑法剑怎么去施展玉女十九式？！\n");

        weapon = (me->query_temp("weapon"))->query("name");
        lvl = me->query_skill("huashan-jianfa",1);
        message_vision(HIC "\n$N运剑如风，精妙非常的“玉女剑十九式”一式式施展开来。" + weapon + HIC"如银龙出海,幻起道道电光！\n" +
        "顷刻之间，$N将“玉女十九剑”中那十九式的数百招一气呵成的使了出来，这数百招便如一招，剑法之快，直是匪夷所思。\n" NOR, me, target);
        me->set_temp("hsj_19",1);
     
   if(me->query("quest/huashan")=="气宗" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/damage",lvl/5);
    
   if(me->query("quest/huashan")=="剑宗" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/attack",lvl/5);
       
      me->add_temp("apply/damage", lvl/4);
      me->add_temp("apply/attack", lvl/4);
      
      hits =random(MAX_HITS);
   if(hits<4) hits = 4;

 if (me->query("quest/huashan") == "剑宗") {
    if(hits<6) hits = 4+random(3);
                 if(random(2)|| !userp(target)){
                 message_vision(HBGRN"$N此刻将华山派剑宗的精妙招数发挥到极致，$n只觉得"+weapon+HBGRN+"如影随行，挡无可挡！\n"NOR,me,target);
                                target->apply_condition("no_fight",1);
                            }
                            
               
if(me->query("quest/zixia/pass") && me->query_temp("zxg")) 
             {   message_vision(HIM"$N更将华山派气宗的镇派绝技紫霞内劲运到极致，手中"+weapon+HIM+"上紫霞剑气锐利无匹，$n哪敢招架，只得暂避锋芒，连连后退，！\n"NOR,me,target);
                              target->add_busy(hits);
             }


                me->add("jingli", -300);
                                                      }
                                                      
                                                      
                                                      
                                                      

   else  if (me->query("quest/huashan") == "气宗" || me->query("quest/zixia/pass")) {            
                 if(random(2)){
                 message_vision(HIM"$N更将华山派气宗的镇派绝技紫霞内劲运到极致，"+weapon+HIM+"紫芒大作，剑气锐利无匹！\n"NOR,me,target);
                                target->apply_condition("no_fight",1);
                              }
                if(random(2)|| !userp(target)){
                message_vision(HIM"$N手中"+weapon+HIM+"上紫霞剑气锐利无匹，$n哪敢招架，只得暂避锋芒，连连后退，！\n"NOR,me,target);
                      target->add_busy(2);
                              }
                me->add("neili", -500);
                                                    }
   for( i = 0; i < hits; i ++ ) {

    if (target && me->is_fighting(target) )    
{
              
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 }
    else break;
 }
  
  
   if(me->query("quest/huashan")=="气宗" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/damage",-lvl/5);
    
   if(me->query("quest/huashan")=="剑宗" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/attack",-lvl/5);
       
      me->add_temp("apply/damage", -lvl/4);
      me->add_temp("apply/attack", -lvl/4);
        
        me->add("jingli", -100);
        me->add("neili", -500);
        me->delete_temp("hsj_19");
        me->start_perform(3+random(3),"玉女十九式");
        me->start_busy(1);
        return 1;
}

int help(object me)
{
   write(WHT"\n华山剑法「"HIC"玉女十九式"WHT"」："NOR"\n");
   write(@HELP
    这招「玉女十九式」乃穷华山先辈心血而创，华山剑宗，气宗对其理
    解却各有所不同，剑宗讲究剑招轻盈灵巧，攻敌破绽，而气宗却讲究
    以深厚内力驭剑。因此，气宗使用威力远强于剑宗， 而剑宗则以招数
    精妙为主，命中率远高于气宗。
    均有几率让敌人忙乱。
    如解密华山镇派绝学独孤九剑及紫霞神功，则威力可发挥至极致。
    指令：perform shijiushi

    要求：华山气功 或者 紫霞神功 300级
          后天身法大于60，
          华山剑法300级，
          基本剑法300级，
          基本轻功300级，
          当前内力5000以上，
          当前精力3000以上。
HELP
   );
  return 1;
}
