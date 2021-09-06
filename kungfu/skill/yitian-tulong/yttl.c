//tulong.c 屠龙
// By Spiderii@ty
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
 
string perform_name() {return HIC"倚天屠龙诀"NOR;}

int perform(object me, object target)
{
        string weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("屠龙诀只能对战斗中的对手使用。\n");
    
        
      if((int)me->query_skill("yitian-tulong",1) < 200 )
         return notify_fail("你的倚天屠龙功还不够熟练，使不出屠龙诀！\n");
      
      if((int)me->query_skill("literate",1) < 200 )
         return notify_fail("你的读书写字等级不够，使不出屠龙诀！\n");  

      if((int)me->query_skill("sword",1) < 200 )
         return notify_fail("你的基本剑法还不够熟练！\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("你的内力不够使用屠龙诀！\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("你的精力不够使用屠龙诀！\n");

        if( me->query_temp("yttlg/tulong"))
                return notify_fail("你正在运用屠龙诀！\n");

        if( !me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("你手中无剑怎能使用屠龙诀？！\n");
              
        weapon = (me->query_temp("weapon"))->query("name");
              
       message_vision(HIY "\n$N以手中" + weapon + HIY"做笔，在空中写起字来，每一字包含数招，便有数般变化。\n" +
        "但见剑招开合，俊逸处如风飘雪舞，厚重处如虎蹲象步，当真是雄浑刚健，淋漓酣畅。\n" NOR, me, target);

skill = me->query_skill("yitian-tulong",1);

        me->set_temp("yttlg/tulong",1);
           me->add_temp("apply/attack", skill/3);
           me->add_temp("apply/damage", skill/3);
           me->add_temp("apply/parry",skill/10);        
           me->add_temp("apply/dodge", skill/10);
        
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
       me->add("neili", -(me->query_skill("force")));
       me->add("jingli", - 100);
       me->start_perform(4, "屠龙诀");
       call_out("remove_effect", 1, me, target, weapon, skill/10);
       return 1;
}

int remove_effect(object me,object target,object weapon,int count)
{
        if(!me) return 0;
        if(!me->query_temp("yttlg/tulong")) return 0;
        if( !target 
         || ! me->is_fighting(target)
         || weapon != me->query_temp("weapon")
         || me->query_skill_mapped("sword") != "yitian-tulong"
         || count < 0){
           me->add_temp("apply/attack", -me->query_skill("yitian-tulong", 1)/3);
           me->add_temp("apply/damage", -me->query_skill("yitian-tulong", 1)/3);
           me->add_temp("apply/parry", -me->query_skill("yitian-tulong", 1)/10);        
           me->add_temp("apply/dodge",- me->query_skill("yitian-tulong", 1)/10);
           me->delete_temp("yttlg/tulong");
           if(living(me))
             message_vision(HIG "\n$N以剑代笔，二十四个字一遍又一遍的翻覆演展，良久始罢！\n\n" NOR, me);
           return 0;
         }
         call_out("remove_effect", 1 ,me ,target, weapon, count -1);
}


int help(object me)
{
   write(HIG"\n「"HIW"倚天屠龙诀"HIG"」："NOR"\n");
	write(@HELP
   
   “武林至尊，宝刀屠龙。号令天下，莫敢不从。倚天不出，谁与争锋。”
  
   张三丰寿诞之日,遭逢大变,情之所至，将这二十四个字演为一套武功，后传
   于武当张翠山张武侠。
  
    指令：perform sword(parry).yttl

    要求：基本剑法200级
          读书写字200级
          倚天屠龙功200级
          当前内力3000以上，当前精力1000以上，手中持有剑类武器。
                    

    说明：倚天屠龙功乃是由拳法演变而来。要求绝高的书法造诣，
          领悟之后，不判断激发。
HELP
	);
	return 1;
}
