// sanhua-zhang perform 四季散花(春夏秋冬)
// by beyond
// rewrite by snowman@SJ 05/12/1999

#include <ansi.h>

inherit F_SSERVER;
#include <combat_msg.h>

int hehe(object me, object target, int i)
{
	string dodge_skill, msg;
	int damage = (random(me->query("int")/6)+1) * me->query_skill("sanhua-zhang",1 );
        if (damage>2000) damage=2000+random((damage-2000)/100);
        if(!target || ! me->is_fighting(target)) return 1;
	if (i >= 400 ) msg = HIW"\n突然$N大吼一声，顿时把$n瞎了一个激灵，之间$N在眉宇之间布满了一层薄霜，双目冷冷的瞪着$n，接着僧袍一卷，一朵朵绽开的"MAG"「寒梅」"HIW"向$n满面扑来！\n"NOR;          
	else if( i >= 300) msg = HIY"\n突然$N双手莫念经文，$n忽然觉得眼前人影如山，忽而排山倒海，忽而忽而高山流水，觉得一切都在离$n远去，跟着一股醉人的"GRN"「秋菊」"HIY"清香扑鼻而来。。。\n"NOR;           
       	else if( i >= 200) msg = MAG"\n只听$N“哎呀”一声，身行象前跌去，突然一道蓝光闪现，破空之声中几朵"WHT"「清兰」"MAG"向$n的胸前飞去！\n"NOR;             
      	else msg = GRN"\n$N突然面带微笑，手掌微张，掌中涌出一股劲风，恍忽是一片片嫩绿的"CYN"「芳草」"GRN"，直向$n的面颊飞去！\n"NOR;
        
         
    	if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                me->add("neili", -damage/3);
                me->add("jingli", -50);
                i = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤") + "( $n"+eff_status_msg(i)+" )\n";
		message_vision(msg, me, target);
		if( !me->is_killing(target->query("id"))
		&& !target->is_killing(me->query("id"))
		&& !me->query("have_master")   // added by snowman
		&& target->query("qi")*2 <= target->query("max_qi"))
			COMBAT_D->end_fight(me, target);
		return 1;
        } 
        else {       
                me->start_busy(2);
                me->add("neili", -100); 
                me->add("jingli", -25);
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                message_vision(msg, me, target);
                return 0;
        }    
}

int perform(object me, object target)
{
      	if( !target ) target = offensive_target(me);
     
      	if( !target || !me->is_fighting(target) )
      		return notify_fail("「四季散花」只能在战斗中对对手使用。\n");
             
      	if(me->query_temp("weapon"))
      		return notify_fail("你必须空手使用「四季散花」！\n");
      
      	if( (int)me->query_skill("sanhua-zhang",1) < 100 )
      		return notify_fail("你的散花掌不够娴熟，不能使用「四季散花」！\n");
      
      	if( (int)me->query_skill("yijin-jing",1) < 100 )
      		return notify_fail("你的易筋经内功等级不够，不能使用「四季散花」！\n");  
      
      	if( (int)me->query_str() < 30 )
      		return notify_fail("你的臂力不够强，不能使用「四季散花」！\n");
      
      	if( (int)me->query("max_neili") < 800 )
      		return notify_fail("你的内力太弱，不能使用「四季散花」！\n");
      
      	if( (int)me->query("neili") < 300 )
      		return notify_fail("你的内力太少了，无法使用出「四季散花」！\n");   
                                                                                 
        if( me->query_temp("fumo"))
                return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
     
      	if (me->query_skill_prepared("strike") != "sanhua-zhang"
          || me->query_skill_mapped("strike") != "sanhua-zhang")
      		return notify_fail("你现在无法使用「四季散花」进行攻击。\n");     
     
     	if (me->query_skill_mapped("force") != "yijin-jing")
      		return notify_fail("你目前的内功无法使用「四季散花」进行攻击。\n");  
      		  
        me->start_perform(6, "「四季散花」");
          
    	if (!hehe(me, target, me->query_skill("sanhua-zhang", 1))){
        	if (random(me->query_int()) > target->query_int()/2) 
        		hehe(me, target, random(me->query_skill("sanhua-zhang", 1)*2));
        	else return 1;
        }
                
        else if (random(me->query_int()) > target->query_int()/2) 
        	hehe(me, target, random(me->query_skill("sanhua-zhang", 1)*2));
        return 1;
       
}
string perform_name(){ return HIW"四季散花"NOR; }