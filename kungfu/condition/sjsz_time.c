// sjsz_time.c  试剑山庄寻宝有效时间计时
// Create By lsxk@hsbbs 2008/6/20

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
       int i;

       if (duration < 1){
           tell_object(me,BLINK + HIC"突然从边上窜出两个彪形大汉，一把抗起你，丢到了城隍庙。你顿时郁闷了半天。\n"NOR);
           me->move("/d/city/chmiao");
           return 0;
       }
       me->apply_condition("sjsz_time", duration - 1);
       //增加随机奖励。by lsxk@hsbbs
     if ( strsrch(file_name(environment(me)), "/cmds/leitai/bwdh") >= 0){
       switch(random(5)){
       case 0:
           me->add("combat_exp",(i=71+random(80)));
           tell_object(me,HIM"你正在试剑山庄中探险，额外获得了"+HIW+chinese_number(i)+HIM+"点经验值奖励!\n"NOR);
           break;
       case 1:
           me->add("max_neili",(i=1+random(3)));
           tell_object(me,HIG"你正在试剑山庄中探险，额外获得了"+HIW+chinese_number(i)+HIG+"点最大内力奖励!\n"NOR);
           break;
       default:
           me->add("potential",(i=21+random(30)));
           tell_object(me,HIC"你正在试剑山庄中探险，额外获得了"+HIW+chinese_number(i)+HIC+"点潜能奖励!\n"NOR);
           break;
       }
     }

	return 1;
}

string query_type(object me)
{
       return "quest";
}
