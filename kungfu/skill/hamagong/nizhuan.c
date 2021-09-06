
// nizhuan.c 逆转九阴
// by snowman@SJ

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

string exert_name()
{
        return HIW"逆转九阴"NOR;
}

int exert(object me, object target)
{
        int skill,sk;

        if( !target )
                target = me;

        if(!(int)me->query_skill("hamagong", 1) )
                return 0;
        if( me->query("oyf/hamagong") < 2 )
                return notify_fail("逆运蛤蟆功使经脉倒转？找死啊？\n");
        if((int)me->query("neili") < 300  )
                return notify_fail("你的内力不够。\n");
        if((int)me->query("jingli") < 200  )
                return notify_fail("你的精力不够。\n");
        if((int)me->query_temp("hmg_nizhuan") )
                return notify_fail("你已经逆运了九阴。\n");

       sk = me->query_skill("force",1)/2 + me->query_skill("hamagong", 1);
       sk /= 2;
       skill = me->query_skill("force",1)/4 + me->query_skill("hamagong", 1)/2;
       me->add("neili", -200);
       me->add("jingli", -20);


      message_vision(HIW "\n$N双手撑地，口中发出一连窜低喉声，一股股内劲勃发使$N双足离地，呈头下足上之势。\n" NOR, me);
      tell_object(me, HIW "你体内蛤蟆功劲力逆转，好像有股巨大的力量要崩发出来一样。\n" NOR);

   me->start_call_out( (: call_other, this_object(), "remove_effect", me :), skill);

 if (me->query_skill("hamagong", 1) > 450)
        {
                me->add_temp("apply/parry", skill/4);
                me->add_temp("apply/dodge", skill/4);
        }

if(me->query("oyf/hamagong")==3 ) me->add_temp("apply/armor",skill);

        me->add_temp("apply/strength", skill/6);
        me->add_temp("apply/dexerity", skill/6);
        me->add_temp("apply/attack", skill/5);
 
      me->set_temp("hmg_nizhuan", skill);
        
        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me)
{
        int amount;
        if(!me) return;

        if( !intp(amount = me->query_temp("hmg_nizhuan")) )
                return;

        if (me->query_skill("hamagong", 1) > 450)
        {
                me->add_temp("apply/parry", -amount/4);
                me->add_temp("apply/dodge", -amount/4);
        }
        me->add_temp("apply/strength", - amount/6);
        me->add_temp("apply/dexerity", - amount/6);
        me->add_temp("apply/attack", - amount/5);

if(me->query("oyf/hamagong")==3 ) me->add_temp("apply/armor",-amount);

        me->delete_temp("hmg_nizhuan");
  tell_object(me, HIW "你蛤蟆功逆运过久，神智渐渐不清，只好中止了逆转。\n" NOR);      
}

int help(object me)
{
write(WHT"\n蛤蟆功「逆转九阴」："NOR"\n");
write(@HELP
欧阳锋的独门绝技蛤蟆功乃是天下武学中的绝顶功夫。自从他逆练九阴成疯
而又夺得天下第一的称号后，这蛤蟆功更大逆寻常武功，更加怪异无伦。这
逆转九阴之法，便是当年他传与杨过的绝技！

      要求：内力 300 以上；
            解开蛤蟆功秘题二；
            可以施展逆转九阴；
            解开蛤蟆功秘题三；
            可以释放逆转九阴真正威力。
HELP
);
return 1;

}
