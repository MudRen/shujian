/*

                   me->prepare_skill("strike");
                   me->prepare_skill("hand");




*/
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

	if( !target ) target = offensive_target(me);

    if( !me->query("/quest/xiaoyao/pass") )
		return notify_fail("你尚未有机缘遍览逍遥绝学！\n");

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
		return notify_fail("羽意剑舞只能对战斗中的对手使用。\n");



       if( me->query_skill_mapped("sword") != "tianyu-qijian" || me->query_skill_mapped("blade") != "ruyi-dao")
		return notify_fail("必须通晓并备有天羽奇剑与如意刀法才能使用羽意剑舞！\n");


      if(me->query_skill_prepared("hand") != "zhemei-shou" || me->query_skill_prepared("strike") != "liuyang-zhang" )
		return notify_fail("你必须同时备有折梅手和六阳掌！\n");
	
      if(me->query_skill("tianyu-qijian",1) <120)
		return notify_fail("你的天羽奇剑不够熟练，不能使用羽意剑舞！\n");

	if(me->query_skill("ruyi-dao",1) <120)
		return notify_fail("你的如意刀法不够熟练，不能使用羽意剑舞！\n");

	if( me->query_skill_mapped("force") != "bahuang-gong" &&
		me->query_skill_mapped("force") != "beiming-shengong"
		)
		return notify_fail("你所用的并非逍遥心法，无法施展羽意剑舞！\n");

	if( me->query_skill("bahuang-gong", 1) < 120 &&
		me->query_skill("beiming-shengong", 1) < 120
		)
		return notify_fail("你的逍遥心法火候未到，无法施展羽意剑舞！\n");
	

		
	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade" )
		return notify_fail("必须持有刀剑才能使用羽意剑舞！\n");

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
		return notify_fail("必须持有刀剑才能使用羽意剑舞！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不够使用羽意剑舞！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用羽意剑舞！\n");
	if( me->query("jing") <= 120 )
		return notify_fail("你的精不够使用羽意剑舞！\n");

	skill =  ( me->query_skill("sword",1) + me->query_skill("tianyu-qijian",1)
		+ me->query_skill("ruyi-dao",1) +me->query_skill("blade",1) 
                + me->query_skill("force",1)) / 3; 


	message_vision(HIC"$N早已遍览逍遥武技，于逍遥绝学"HIG"天羽剑"HIR"如意刀"HIC"，"HIY"六阳掌"HIM"折梅手"HIC"，无一不精，信手拈来信手使出，身形飘逸洒脱，正合适“逍遥”之意。\n" NOR, me);
     me->set_temp("xiaoyao_jianwu", 1);
target->add_busy(2);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/sword",  skill/4);
	me->add_temp("apply/blade",  skill/4);
	me->add_temp("apply/parry",  skill/4);
	me->add_temp("apply/hand",  skill/4);
	me->add_temp("apply/strike",  skill/4);
	me->add_temp("apply/strength",  skill/10);

bei_skill = me->query_skill_mapped("blade");

if (skill>=351 && !userp(target) ) target->set_temp("must_be_hit",1);
	weapon->unequip();
	weapon2->unequip();
   me->prepare_skill("hand");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);   //一掌定生死


 if(me->is_fighting(target)) {

    me->map_skill("blade", "ruyi-dao");
	weapon->wield();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  //如意刀
	
                                       }                               

 if(me->is_fighting(target)) {
       weapon->unequip();
	me->prepare_skill("strike");
       me->prepare_skill("hand","zhemei-shou");             
COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);         //折梅手
	                          }

 if(me->is_fighting(target)) {
	weapon2->wield();
    me->map_skill("sword", "tianyu-qijian");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);   //天羽剑
	weapon2->unequip();
	weapon->wield();
                                   }

//-------------------450飞------------------//
if(me->query_skill("beiming-shengong",1) >= 450){

        if(me->is_fighting(target)) {
             me->map_skill("blade", "ruyi-dao");
	      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);  
	      weapon->unequip();
	      weapon2->wield();
                                   }
      if(me->is_fighting(target)) {
             me->map_skill("sword", "tianyu-jian");
	      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	      weapon2->unequip();
                                 }
}

    me->map_skill("blade", bei_skill);
	weapon2->unequip();
	weapon->wield();

       me->prepare_skill("hand","zhemei-shou");
       me->prepare_skill("strike","liuyang-zhang");   

	me->add("jingli", -100);
	me->add("jing", -100);
	me->add("neili", -300);
//         me->start_busy(1+random(2));
  if(target){
 target->start_busy(1+random(2));  
 target->delete_temp("must_be_hit");}
	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill/3);
	me->add_temp("apply/dodge",  -skill/2);
	me->add_temp("apply/sword",  -skill/4);
	me->add_temp("apply/blade",  -skill/4);
	me->add_temp("apply/parry",  -skill/4);
	me->add_temp("apply/hand",   -skill/4);
	me->add_temp("apply/strike",  -skill/4);
	me->add_temp("apply/strength",  -skill/10);
me->delete_temp("xiaoyao_jianwu", 1);
    me->start_perform(2+random(3), "「羽意剑舞」");

//	message_vision(HIY "\n$N羽意剑舞收招！\n\n" NOR, me,weapon);

	return 1;
}
