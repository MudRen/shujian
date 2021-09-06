// 弹梅.落雪.散花香  action@SJ 2008/12/28

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int lv;

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("【弹梅.落雪.散花香】只能在战斗中使用。\n");
                
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用【弹梅.落雪.散花香】！\n");   
                
        if( (int)me->query_skill("zhemei-shou", 1) < 100 )
                return notify_fail("你的天山折梅手还不够娴熟，无法使出【弹梅.落雪.散花香】绝技。\n");     
                
        if( (int)me->query_skill("hand", 1) < 100 )
                return notify_fail("你的基本手法还不够娴熟，无法使出【弹梅.落雪.散花香】绝技。\n");   
                
        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("你的内功修为不足，无法使出【弹梅.落雪.散花香】绝技。\n");                                                         

        if (me->query_skill_mapped("force") != "bahuang-gong" )
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你所使用的内功不对，无法使出【弹梅.落雪.散花香】。\n");  
                
        if ( me->query_skill_mapped("parry") != "zhemei-shou"
	            && me->query_skill_mapped("hand") != "zhemei-shou")
		            return notify_fail("你现在无法使用【弹梅.落雪.散花香】。\n");
		            
		    if (me->query_skill_prepared("hand") != "zhemei-shou"
	             || me->query_skill_mapped("hand") != "zhemei-shou")
	              return notify_fail("你现在无法使用【弹梅.落雪.散花香】。\n");

        if( (int)me->query_temp("tanmei") > 0 )
                return notify_fail(HIG"你刚刚用过【弹梅.落雪.散花香】，等一会再使用吧。NOR\n"NOR);
                
        if( (int)me->query("max_neili", 1) < 1000 )
                return notify_fail("你现在内力修为不足，无法使出【弹梅.落雪.散花香】。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，无法使出【弹梅.落雪.散花香】。\n");
                
        if( me->query("jingli") < 300 )
		            return notify_fail("你现在精力不够, 无法使出【弹梅.落雪.散花香】! \n");
        lv = me->query_skill("zhemei-shou",1)/2+ me->query_skill("liuyang-zhang",1)/2;
        lv = lv *2 /3;
  if(!userp(me)) lv = lv / 6;

        if (me->query("family/family_name") != "逍遥派"&& me->query("family/family_name") != "灵鹫宫")
                 lv  =  lv / 6;

        me->add_temp("apply/attack", lv);
        me->add_temp("apply/damage", lv /2 );
        me->add_temp("apply/strength", lv /10 );
        me->add_temp("apply/hand", lv /2 );
        me->add_temp("apply/parry", lv /2 );
if( me->query_skill("zhemei-shou",1)>350 && !userp(target)) target->add_busy(1+random(2)); 

        me->set_temp("tanmei");
message_vision(MAG "$N微微一笑，使出"HIG"【弹梅.落雪.散花香】"MAG"左手向$n轻轻弹出，好像是要弹去梅花上面的露珠！       
\n"HIW"【弹 梅】\n"NOR, me,target);

		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 

message_vision(HIG "$n突然闻到一股若有若无的香味，心猿意马之中$N的双手已向$p胸口拍来！                        
\n"HIW"【落 雪】\n"NOR, me,target);

		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
message_vision(HIC "$N双手急挥，左右摇摆，幻出漫天"HIW"梅花"HIC"，飞雪似的向$n落来！                                    
\n"HIM"【散花香】\n"NOR, me,target); 


		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 

		    me->delete_temp("tanmei");

        me->add_temp("apply/attack", -lv);
        me->add_temp("apply/damage",- lv /2 );
        me->add_temp("apply/strength", -lv /10 );
        me->add_temp("apply/hand", -lv /2 );
        me->add_temp("apply/parry", -lv /2 );


		    me->start_perform(3 + random(2), "【弹梅.落雪.散花香】");
        return 1;
}

string perform_name(){ return HIG"弹梅.落雪.散花香"NOR; }

int help(object me)
{
	write(YEL"\n天山折梅手之"HIG"【弹梅.落雪.散花香】："NOR"\n");
	write(@HELP
	
	要求：
	当前内力 500 以上；
	最大内力 1000 以上：
	当前精力 300以上；
	天山折梅手等级 100 以上；
	八荒六合唯我独尊功等级 100 以上；
	北冥神功等级 100 以上；
	内功有效等级 100 以上：
HELP
	);
	return 1;
}
