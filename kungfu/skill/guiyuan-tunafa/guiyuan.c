// focus.c, 聚力 by darken@SJ
// By Spiderii@ty更新效果
#include <ansi.h>

inherit F_CLEAN_UP;
void remove_effect(object me,int count);
string exert_name(){ return HBBLU"归元聚力"NOR; }

int exert(object me)
{      
int skill;
       skill = me->query_skill("guiyuan-tunafa");
if( !me->is_fighting() && (int)me->query_skill("guiyuan-tunafa",1)<350 )
                return notify_fail("你只能在战斗中使用「归元聚力」！\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 100 )
                return notify_fail("你的归元吐纳法法修为还不够！\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够。\n");

        if(me->query_temp("tz/focus"))
                return notify_fail("你已经在使用了。\n");

        message_vision(HBBLU"$N一凝神，手上的力道似乎增强了。\n" NOR, me);
        me->start_busy(1);
       me->add_temp("apply/strength", me->query_skill("guiyuan-tunafa", 1)/15);
       me->add_temp("apply/attack", me->query_skill("guiyuan-tunafa", 1)/10);
        me->add("neili", -400);
        me->set_temp("tz/focus",skill /10);
call_out("remove_effect", 1, me, skill);
me->start_exert(1, "「归元聚力」");
        return 1;
}
void remove_effect(object me, int count)
{
if (!me) return;
if( count < 1){
me->delete_temp("tz/focus");
        
           me->add_temp("apply/strength", -me->query_skill("guiyuan-tunafa", 1)/15);
           me->add_temp("apply/attack", -me->query_skill("guiyuan-tunafa", 1)/10);
            message_vision(HIW"$N运功完毕，手上力道渐渐恢复如常。\n"NOR, me);

            return;

        }
call_out("remove_effect", 1 , me ,count -1);
}

