// hero 英雄三招
// 19991002001
#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIR"英雄三招"NOR;}

int calc_damage(int,int,object,object);

int perform(object me, object target)
{
        object weapon;
        string msg,result;
        int i,total,def,abs,gifts1,gifts2; 
        
        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("「英雄三招」只能在战斗时使用！\n");

        if(me->query("family/master_id")!="hong antong")
                return notify_fail("「英雄三招」只有拜了教主后才能用！\n");

        if( objectp(weapon=me->query_temp("weapon")) ) {
                string *ids = weapon->parse_command_id_list();
                if (member_array("bishou", ids) == -1)                          
                        return notify_fail("你必须拿着匕首才能用「英雄三招」！\n");
        }
        else {
                return notify_fail("你必须拿着匕首才能用「英雄三招」！\n");
        }
        
        if( (int)me->query_skill("huagu-mianzhang", 1) < 250 )
                return notify_fail("你的化骨绵掌还不够熟练，不能使用「英雄三招」！\n");

        if (me->query_skill_mapped("strike") != "huagu-mianzhang")
                return notify_fail("只有使用化骨绵掌时才能使用「英雄三招」！\n");

        if( (int)me->query_skill("shenlong-tuifa", 1) < 250 )
                return notify_fail("你的神龙腿法还不够熟练，不能使用「英雄三招」！\n");

        if (me->query_skill_mapped("leg") != "shenlong-tuifa")
                return notify_fail("只有使用神龙腿法时才能使用「英雄三招」！\n");

        if( (int)me->query_skill("canglang-goufa", 1) < 250 )
                return notify_fail("你的沧浪钩法还不够熟练，不能使用「英雄三招」！\n");

        if (me->query_skill_mapped("hook") != "canglang-goufa")
                return notify_fail("只有使用沧浪钩法时才能使用「英雄三招」！\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 250 )
                return notify_fail("你的毒龙大法功力不足，不能用「英雄三招」。\n");

        if( (int)me->query_skill("tenglong-bifa", 1) < 250 )
                return notify_fail("你的腾龙匕法还不够熟练，不能使用「英雄三招」！\n");

        if (me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("只有使用腾龙匕法时才能使用「英雄三招」！\n");

        if( (int)me->query_skill("dagger", 1) < 250 )
                return notify_fail("你的基本匕法还不够熟练，不能使用「英雄三招」！\n");

        if((int)me->query("max_neili", 1) < 4000) 
                return notify_fail("你现在内力修为尚低，不能使用「英雄三招」！\n"); 

        if((int)me->query("eff_jingli", 1) < 2500) 
                return notify_fail("你现在精力修为尚低，不能使用「英雄三招」！\n"); 

        if((int)me->query("jingli", 1) < 800)
                return notify_fail("你现在精力不足，不能使用「英雄三招」！\n");       

        if((int)me->query("neili", 1) < 1500) 
                return notify_fail("你现在内力不足，不能使用「英雄三招」！\n");      

        if(me->query("gender")!= "男性") 
                return notify_fail("只有男人才能使用「英雄三招」！\n");      

        if( me->query_skill_mapped("force") != "dulong-dafa")
                return notify_fail("你现在所使用的内功同毒龙大法向抵触，不能使用「英雄三招」。\n");

        me->add("jingli",-100);
        me->add("neili",-200);

        msg = HIR"$N乘$n稍稍走神之机，拼尽全力使出洪教主不传之绝技－－「英雄三招」\n"NOR;
def = target->query_temp("apply/armor",1);
gifts1 = me->query("str") +  me->query("dex") +  me->query("con") +  me->query("int") ;
gifts2 = target->query("str") +  target->query("dex") +  target->query("con") +  target->query("int") ;

        if((random((int)me->query_skill("canglang-goufa",1)) > (int)target->query_skill("parry",1)/3
          ||random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3
          ||random((int)me->query_str()) > (int)target->query_dex()/3)
          && (gifts1+ 3 )>= gifts2
          ||!userp(target) ){
                me->start_busy(1);
                me->add("neili",- random(400)-400 );
                me->add("jingli",-random(200)- 200);
                total = 0;
                msg += HIR "\n$N使出一招「"HIY"子胥举鼎"HIR"」，一手轻搔$n腋底极泉穴，乘其慌张之际，另一手同\n"+
                           "时拿向$n肘后小海穴，将其摔向地上。\n"NOR;
                i = calc_damage((int)me->query_skill("huagu-mianzhang",1),(int)me->query_skill("canglang-goufa",1),me,target);
abs = i * def/(1000+ def);
                total += i;
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                
                
      if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"RED+ i+ WHT"点攻击伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR);    
      if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"RED+ i+ WHT"点伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR); 
                target->receive_damage("qi", i, me );
                target->receive_wound("qi", i/3 , me);
                result = COMBAT_D->damage_msg(i,"瘀伤");
                result = replace_string( result, "$l", "小海穴" );
                msg += result;
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0);     

                msg =HIR "\n$N使出一招「"HIW"鲁达拔柳"HIR"」，缩腿假装向$n叩头，突然一个斛斗，似欲向$n胯下\n"+
                         "钻过，但只一作势，左手抓向$n右脚足踝，右手兵器虚点向$n小腹，一用力，把$n头下\n"+
                         "脚上，倒提起来。\n"NOR;

                i = calc_damage((int)me->query_skill("tenglong-bifa",1),(int)me->query_skill("canglang-goufa",1),me,target);
abs = i * def/(1000+ def);
                total += i;
                
                
      if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"RED+ i+ WHT"点攻击伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR);    
      if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"RED+ i+ WHT"点伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR); 
      
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                target->receive_damage("qi", i, me );
                target->receive_wound("qi", i/3 , me);
                result = COMBAT_D->damage_msg(i,"刺伤");
                result = replace_string( result, "$l", "小腹" );
                result = replace_string( result, "$w", weapon->query("name") );
                msg += result;
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0);     

                msg =HIR "\n$N使出一招「"HIC"狄青降龙"HIR"」，背脊后撞，十指向$n胸口虚抓，乘其避让之际，\n"+
                         "突然一个倒翻斛斗，身子跃起，双腿一分，跨坐在$n肩头，同时双手拇指压住$n\n"+
                         "太阳穴，食指按眉，中指按眼。\n"NOR;

                i = calc_damage((int)me->query_skill("shenlong-tuifa",1),(int)me->query_skill("canglang-goufa",1),me,target);
abs = i * def/(1000+ def);
                total += i;
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                

                
                target->receive_damage("qi", i, me );
                target->receive_wound("qi", i/3 , me);
                result = COMBAT_D->damage_msg(i,"内伤");
                result = replace_string( result, "$l", "头部" );
                msg += result;
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0);
      if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"RED+ i+ WHT"点攻击伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR);  
      if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"RED+ i+ WHT"点伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR);            
            abs = total * def /(1000+ def);   
      if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"总共造成了"RED+ total+ WHT"点攻击伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR);    
      if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你总共造成了"RED+ total+ WHT"点伤害(其中"RED+ abs+ WHT"被吸收)。\n"NOR);  
                if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));
                me->start_perform(5,"「英雄三招」");
        }
        else {
                msg += HIR "\n$N使出一招「"HIY"子胥举鼎"HIR"」，一手轻搔$n腋底极泉穴，乘其慌张之际，另一手同\n时拿向$n肘后小海穴，将其摔向地上。\n"NOR;
                msg += "但是$n看破了$N的企图，没有上当，急急忙忙向旁边一闪，躲了过去。\n";
                msg +=HIR "\n$N使出一招「"HIW"鲁达拔柳"HIR"」，缩腿假装向$n叩头，突然一个斛斗，似欲向$n胯下\n"+
                          "钻过，但只一作势，左手抓向$n右脚足踝，右手兵器虚点向$n小腹，一用力，把$n头下\n"+
                          "脚上，倒提起来。\n"NOR;
                msg += "$n吃了一惊，但随即冷静下来，在空中猛一蹬腿踢向$N面门，$N只得松开了手。\n";
                msg += HIR "\n$N使出一招「"HIC"狄青降龙"HIR"」，背脊后撞，十指向$n胸口虚抓，乘其避让之际，\n"+
                           "突然一个倒翻斛斗，身子跃起，双腿一分，跨坐在$n肩头，同时双手拇指压住$n\n"+
                           "太阳穴，食指按眉，中指按眼。\n"NOR;
                msg += "$n被$N制住，但临危不乱，以内力护住要害，同时高高跃起，翻身以头撞地，把$N撞了出去！\n";

                message_vision(msg,me,target);

                me->start_busy(1+random(3));
                me->start_perform(3,"「英雄三招」");
        }

        return 1;
}

int calc_damage(int skill,int skill2,object me,object target)
{
        int i,lvl;

            i = ( (skill+skill2)*2 - (int)target->query_skill("parry",1) )*10;
            lvl = skill + skill2 - target->query_skill("parry",1)* 2;

            if (i<0) i = -i;
            i += random(i*2/5);
         if( i < (skill2*5)) i = (int)target->query("qi",1)/4;   

if(userp(target)){
if (lvl>50) i = i * 3 /2;
if(lvl + 50 < 0)  i = i /2;
}
if(me->query("gender")=="男性")  i = i * me->query("str") /50;
else i = i * me->query("dex") /50;
if(!userp(target)) i = i*2;
        return i;
}

int help(object me)
{
   write(WHT"\n沧浪钩法「"HIR"英雄三招"WHT"」："NOR"\n");
   write(@HELP

    要求：最大内力 4000 以上；
          最大精力 2500 以上；
          当前内力 1500 以上；
          当前精力 800 以上；
          化骨绵掌等级 250 以上；
          神龙腿法等级 250 以上；
          沧浪钩法等级 250 以上；
          毒龙大法等级 250 以上；
          腾龙匕法等级 250 以上；
          基本匕法等级 250 以上；
          性别需求 男性。
HELP
   );
   return 1;
}
