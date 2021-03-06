// yujianshi.c 驭剑式  By lsxk@hsbbs 2007/7/24
// 作用为：增加命中和set_temp("double_attack")。  By lsxk@hsbbs

#include <ansi.h>

inherit F_SSERVER;

string exert_name() {return HIG"驭剑式"NOR;}

private int remove_effect(object me, int amount);
int exert(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("「驭剑式」只能在战斗中使用。\n");

        if((int)me->query_skill("huashan-qigong", 1) < 250 )
                return notify_fail("你的华山气功等级不够，不能使用「驭剑式」。\n");
    
        if ((int)me->query_skill("huashan-jianfa", 1) < 250 )
                return notify_fail("你的华山剑法不够娴熟，不能真正发挥「驭剑式」的威力。\n");
    
        if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("你的基本内功等级不够，不能使用「驭剑式」。\n");

        if (!weapon 
         || weapon->query("skill_type") != "sword"
         ||( me->query_skill_mapped("parry") != "huashan-jianfa" &&  me->query_skill_mapped("parry") != "dugu-jiujian")
         ||( me->query_skill_mapped("sword") != "huashan-jianfa" &&  me->query_skill_mapped("sword") != "dugu-jiujian") )
                return notify_fail("你现在无法使用「驭剑式」！\n");
    
        if ((int)me->query("max_neili") < 3500 )
                return notify_fail("你的内力修为太低，不能使用「驭剑式」。\n");

        if ((int)me->query("neili") < 1500 )
                return notify_fail("你现在内力太弱，不能使用「驭剑式」。\n");

        if ((int)me->query("jingli") < 800 )
                return notify_fail("你现在精力太少，不能使用「驭剑式」。\n");

        if(me->query_temp("hsqg/yjs"))
                return notify_fail("你现正在使用「驭剑式」。\n");

        if(me->query_temp("hsqg/juli"))
                return notify_fail("你现正在使用「真气聚力」。\n");
/*
        if ((int)me->query_temp("hsj_junzi"))
                return notify_fail("你正在使用「君子剑法」绝技。\n"); 

        if ((int)me->query_temp("hsj_shunv"))
                return notify_fail("你正在使用「淑女剑法」绝技。\n"); 
    
        if ( (int)me->query_temp("hsj_xiyi") ) 
                return notify_fail("你正在使用「淑女剑法」。\n");

        if ( me->query_temp("zxg/jianyi") ) 
                return notify_fail("你正在使用「紫霞剑意」。\n");
*/
        if (me->query_skill_mapped("force") != "huashan-qigong")
                return notify_fail("你的内功有误，无法使用「驭剑式」。\n");

    message_vision(HIM"$N正遇劲敌，当下便使出华山剑宗绝学之「"HIR"驭剑式"HIM"」，只见$N手中"+weapon->query("name")+HIM"急速舞动，犹如飞沙走石一般，剑招接连而至!\n"NOR, me);
        me->start_exert(1+random(2),"「驭剑式」");
        me->add("neili", -500);
        me->add("jingli", -300);
if(me->query_skill("huashan-qigong")<=300 )
        me->start_busy(1);
    
        skill = me->query_skill("huashan-jianfa", 1);
        me->add_temp("apply/attack",  skill/2);
        if(me->query("quest/huashan")=="剑宗")
        me->set_temp("double_attack",1);
        me->set_temp("hsqg/yjs", skill);

        call_out("check_fight", 1, me, weapon);
        return 1;
}

void check_fight(object me, object weapon)
{  
        object wep;
        int i;

        if (!me) return;
        wep = me->query_temp("weapon");  
        if( !me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || me->query_skill_mapped("force") != "huashan-qigong"
         ||(me->query_skill_mapped("sword") != "huashan-jianfa" &&
            me->query_skill_mapped("sword") != "dugu-jiujian")
         ||(me->query_skill_mapped("parry") != "huashan-jianfa" &&
            me->query_skill_mapped("parry") != "dugu-jiujian")
         || !wep
         || weapon != wep ){
       i = me->query_temp("hsqg/yjs");
           me->add_temp("apply/attack", -i/2);
           if(me->query("quest/huashan")=="剑宗")
               me->delete_temp("double_attack");
           me->delete_temp("hsqg/yjs");
           if(living(me) && !me->is_ghost())
              message_vision(HIG"$N一套「驭剑式」使完，微微一笑?袷掌n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
   write(YEL"\n华山气功「"HIG"驭剑式"YEL"」："NOR"\n");
   write(@HELP
   华山气功乃华山一派基础内功，虽不及本门紫霞神功精妙，但若练到
   深处，也绝非同小可！此「驭剑式」绝技乃是剑宗不传绝学，临敌对
   阵时，大幅度提高自己的命中。华山剑宗弟子越练到高深处，越觉得
   心应手，出招之快乃过敌人两倍有余。
   指令：exert yujianshi

   要求：华山气功250级，
         华山剑法250级，
         基本内功250级，
         最大内力 3500 以上，
         当前内力 1500 以上，
         当前精力 800 以上，
         激发华山剑法为招架。
HELP
   );
   return 1;
}
