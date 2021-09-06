// jianjue.c 全真剑法 同归剑诀
// modified by xjqx@SJ 2009/01/01
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill,improve;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("「同归剑诀」只能对战斗中的对手使用。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何能够使出「同归剑诀」？！\n");

        if( (int)me->query_skill("quanzhen-jianfa", 1) < 150 )
                return notify_fail("你的全真剑法不够娴熟，无法使出「同归剑诀」。\n");
                
        if( me->query_temp("qzjf/jianjue"))
                return notify_fail("你正在使用「同归剑诀」！\n");

        if( (int)me->query_skill("xiantian-gong", 1) < 150 )
         return notify_fail("你的特殊内功火候不够，无法使出「同归剑诀」！\n");

        if( me->query_skill_mapped("force") != "xiantian-gong")
        return notify_fail("你的现在使用的内功不对，无法使出「同归剑诀」！\n");    

        if (me->query_skill_mapped("sword") != "quanzhen-jianfa"
         || me->query_skill_mapped("parry") != "quanzhen-jianfa")
                return notify_fail("你现在无法使用「同归剑诀」进行攻击。\n");

        if( me->query("max_neili") <= 2500 )
                return notify_fail("你的内力修为不足，劲力不足以施展「同归剑诀」！\n");

        if( me->query("neili") <= 1500 )
                return notify_fail("你的内力不够，劲力不足以施展「同归剑诀」！\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("你的精力有限，不足以施展「同归剑诀」！\n");

        message_vision(HIC+me->name()+HIC"左手捏一个剑诀，右手握起" + weapon->name() + ""HIC"，拼着最后的力气，一式「"HIR"同归剑诀"NOR"」"HIC"，\n"HIC"驭剑猛烈绝伦地冲向"+target->name()+HIC",意图与"+target->name()+HIR"同归一尽"NOR+HIC"！\n"NOR, me);
 if(userp(me)){
           me->add("neili", -300);
           me->add("jingli", -50);
        }
        skill = me->query_skill("sword",1);
        improve = skill/10 + random(skill/10);
      	if ( improve > 100 ) improve = 100 + random(improve-100) / 5;

        me->set_temp("qzjf/jianjue", improve);
        me->add_temp("apply/damage", improve);//
        me->add_temp("apply/sword", improve);//
        me->add_temp("apply/strength", improve);//
        call_out("remove_effect", 1,  me, weapon, skill);
        me->start_perform(5, "「同归剑诀」");
        return 1;
}

void remove_effect(object me,object weapon,int count)
{
        int i;
        if(!me) return;
        if(! me->is_fighting()
         || !weapon
         || me->query_skill_mapped("sword") != "quanzhen-jianfa"
         || me->query_skill_mapped("parry") != "quanzhen-jianfa"
         || count < 1 ){
          i = me->query_temp("qzjf/jianjue");
          me->add_temp("apply/sword", -i);
          me->add_temp("apply/damage", -i);
          me->add_temp("apply/strength", -i);
          me->delete_temp("qzjf/jianjue");
	if (weapon)
                message_vision(HIW"$N使完"NOR"「"HIR"同归剑诀"NOR+HIW"」，"NOR+weapon->name()+HIW"的全真剑气逐渐消失，威力大减。\n"NOR, me);
          return;
        }
        else {
          me->start_perform(1,"「同归剑诀」");
          call_out("remove_effect", 1, me, weapon, count -1);
        }
}               
string perform_name(){ return HIC"同归剑诀"NOR; }
