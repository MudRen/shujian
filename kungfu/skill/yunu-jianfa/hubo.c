// hebi.c 玉女剑与全真剑和璧左右互搏
//by sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill, skill1, skill2;
	
	object weapon,weapon2;
       object *inv;
       int i, count;
	string bei_skill;

	if( !target) target= offensive_target(me);

    if(me->query("gmhb") != "pass" && ! me->query("quest/hubo/pass") )
		return notify_fail("你尚未领悟左右互博绝技，不能双剑和璧左右互搏！\n");

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
		return notify_fail("双剑和璧左右互搏只能对战斗中的对手使用。\n");


	
	if( (int)me->query_temp("hubo") ) 
	{
		return notify_fail("你正进行双剑和璧左右互搏。\n");
	}

	if( (int)me->query_temp("hebi") ) 
	{
		return notify_fail("你正与人合壁，不能再进行双剑和璧左右互搏。\n");
	}


       if( me->query_skill_mapped("sword") != "yunu-jianfa" && me->query_skill_mapped("sword") != "quanzhen-jianfa")
		return notify_fail("必须通晓并备有玉女剑法与全真剑法才能双剑和璧左右互搏！\n");


	if(me->query_skill("quanzhen-jianfa",1) <120)
		return notify_fail("你的全真剑法不够熟练，不能双剑和璧左右互搏！\n");

	if(me->query_skill("yunu-jianfa",1) <120)
		return notify_fail("你的玉女剑法不够熟练，不能双剑和璧左右互搏！\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" &&
		me->query_skill_mapped("force") != "xiantian-gong"
		)
		return notify_fail("你所用的并非玉女心经或先天功，无法施展双剑和璧左右互搏！\n");

	if( me->query_skill("yunu-xinjing", 1) < 120 &&
		me->query_skill("xiantian-gong", 1) < 120
		)
		return notify_fail("你的玉女心经或先天功火候未到，无法施展双剑和璧左右互搏！\n");
	

	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("必须持有双剑才能和璧左右互搏！\n");

     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
           if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   break;
		   }
     }

	if( !objectp(weapon2) )
		return notify_fail("必须持有双剑才能和璧左右互搏！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不够使用双剑和璧左右互搏！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用双剑和璧左右互搏！\n");
	if( me->query("jing") <= 120 )
		return notify_fail("你的精不够使用双剑和璧左右互搏！\n");

	skill =  ( me->query_skill("sword",1) + me->query_skill("yunu-jianfa",1)
		+ me->query_skill("quanzhen-jianfa",1) +me->query_skill("yunu-xinjing",1) 
		+ me->query_skill("force")) / 10; 

if(me->query("gender")=="女性") skill = skill*3/2;

	message_vision(
	HIR "$N突然间左手抽出另一把剑，双手使出两种截然不同的剑法，正是左右互搏绝技。\n"+HBBLU+HIM"只见$N双剑一交，左右手玉女剑法与全真剑法配合得天衣无缝，攻拒击刺，宛似两大高手联手进攻一般，威力大增！\n\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/2);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/sword",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->set_temp("hubo", 1);

	bei_skill = me->query_skill_mapped("sword");
if(me->query("max_pot")<=451 )
 target->start_busy(1+random(2));
 
 if(me->is_fighting(target)) {
    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	if(weapon) weapon->unequip();
	weapon2->wield();
                                       }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "quanzhen-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		if(weapon2) weapon2->unequip();
	   if(weapon)	weapon->wield();
                                    }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	if(weapon)	weapon->unequip();
	if(weapon2) 	weapon2->wield();
                                   }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "quanzhen-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	if(weapon2)	 weapon2->unequip();
	if(weapon)	weapon->wield();
                                 }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	if(weapon)	weapon->unequip();
	if(weapon2)	 weapon2->wield();
                              }
 if(me->is_fighting(target)) {
            me->map_skill("sword", "quanzhen-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                             }

       me->map_skill("sword", bei_skill);
	if(weapon2)	 weapon2->unequip();
   if(weapon)  weapon->wield();

	me->add("jingli", -100);
	me->add("jing", -100);
	me->add("neili", -300);
	me->start_busy(1+random(2));
     if(me->is_fighting(target))  target->start_busy(1+random(2));  

	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill/2);
	me->add_temp("apply/dodge",  -skill/2);
	me->add_temp("apply/sword",  -skill/2);
	me->add_temp("apply/parry",  -skill/2);
        me->delete_temp("hubo");
	if(weapon)
	message_vision(HIY "\n$N深吸了一口气，左手将"+"$n" + HIY "插回剑鞘，从容收招！\n\n" NOR, me,weapon);
   else 
   		message_vision(HIY "\n$N深吸了一口气，从容收招！\n\n" NOR, me);
	return 1;
}
