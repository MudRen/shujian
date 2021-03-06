//风雷 fenglei.c 

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return BLU"风雷四击"NOR;}

int perform(object me, object target)
{
        object weapon;
        int i,a;

        weapon = me->query_temp("weapon");
       
        if( !target ) target = offensive_target(me);
         if( !objectp(target)) return notify_fail("你要对谁攻击？\n");

        if( !me->is_fighting() )
                return notify_fail("「风雷四击」只能在战斗中使用。\n");
 
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "duanjia-jianfa")
                return notify_fail("手中无剑,你怎么使得出「风雷四击」！\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力不够！\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query("jingli") < 300 )
                return notify_fail("你的精力不够！\n");

        if( (int)me->query_str() < 24 )
                return notify_fail("你的臂力不够！\n");

        if( (int)me->query_dex() < 24 )
                return notify_fail("你的身法不够！\n");

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 100)
                return notify_fail("以你现在的内功修为还使不出「阳关三叠」。\n");        
         
        if (me->query_skill_mapped("force") != "kurong-changong" )
          if(me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("你所使用的内功不对。\n");

        if( (int)me->query_skill("duanjia-jianfa",1) < 100 )
                return notify_fail("你的段家剑法还不到家，无法使用「风雷四击」绝技！\n");

        if( (int)me->query_skill("sword",1) < 100 )
                return notify_fail("你的剑法造诣不够，无法使用如此高深的「风雷四击」绝技！\n");

        if( (int)me->query_skill("qingyan-zhang",1) < 100 ||
            me->query_skill_mapped("strike") != "qingyan-zhang")
                return notify_fail("你的五罗清烟掌还不到家，无法使用「风雷四击」绝技！\n");

        if( (int)me->query_skill("strike",1) < 100 )
                return notify_fail("你的掌法造诣不够，无法使用如此高深的「风雷四击」绝技！\n");

        if (me->query_skill_prepared("strike") != "qingyan-zhang"
          || me->query_skill_mapped("parry") != "qingyan-zhang")
                return notify_fail("你现在无法使用「风雷四击」进行攻击。\n");

        if( (int)me->query_skill("tianlong-xiang",1) < 100 )
                return notify_fail("你的天龙降还不到家，无法使用「风雷四击」绝技！\n");

        i = ((int)me->query_skill("duanjia-jianfa",1)+(int)me->query_skill("qingyan-zhang",1))/3;

if (i < 200) target->start_busy(1+random(2));

        message_vision(HIG"\n$N蹂身而上，左手"HIM"五罗清烟掌"HIG"，右手"HIW"段家剑"HIG"，施展一绝招「"HIR"风雷四击"HIG"」！\n"NOR, me,target);
        me->add("neili",-(50+random(50))); 
        if (i > 200) i=200;
        me->add("jingli",-50); 
		me->set_temp("fenglei",4);
        for(a=0;a<4;a++)
        {
		     if(random(2)) me->set_temp("fl_sword",1);

		     if (me->query_temp("fl_sword"))
		   {
                         me->add_temp("apply/attack", i *2/2 );
                         me->add_temp("apply/strength", i /2 );
                         me->add_temp("apply/damage", i   );
                         me->add_temp("apply/sword", i /2  );
                         me->add_temp("apply/strike", i /2  );
		         if(me->is_fighting(target))
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3); 
                 me->add_temp("apply/sword", -i /2);
                 me->add_temp("apply/strike", -i /2);
                 me->add_temp("apply/strength", -i /2);
                 me->add_temp("apply/damage", -i );
                 me->add_temp("apply/attack", -i *2/2);
                } else {
		        weapon->unequip();
                         me->add_temp("apply/attack", i /2 );
                         me->add_temp("apply/strike", i /2 );
                         me->add_temp("apply/strength", i /2 );
                         me->add_temp("apply/damage", i  );
                 if(me->is_fighting(target))
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?1:3); 
                         me->add_temp("apply/damage", - i  );
                         me->add_temp("apply/strength", - i /2 );
                         me->add_temp("apply/strike", - i /2 );
                         me->add_temp("apply/attack", - i /2 );
                weapon->wield();
           }
     me->delete_temp("fl_sword");
        }
		me->delete_temp("fenglei");
		me->delete_temp("fl_sword");
        me->start_perform( 3 + random(2), "「风雷四击」");
if(target) target->start_busy(1);
        me->start_busy(2);
        return 1;
}
