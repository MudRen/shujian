// yuenu-jian.c

inherit SKILL;
#include <ansi.h>
#include <combat.h>

string *dodge_msg = ({
HIR"$n长袖轻挥，身形随风而起，翩如惊鸿，婉若游龙，避开了$N的凌厉攻势。\n"NOR,
HIC"$n飘身而进，左手捏个剑诀，剑光如电，直指$N的破绽所在，$N不得不撤招回守。\n"NOR,
HIG"$n衣袂飘飘，仿佛轻云之蔽月，飘飖如流风飞雪，闪在$N意料不到之处！\n"NOR,
HIM"$n长发飘飞，紫裙如云，犹如林间精灵般飞舞穿行，丝毫不受$N的影响！\n"NOR,
HIW"$n嫣然微笑，长裙飞舞，腾挪间如行云流水，剑光挥洒，$N竟是找不到丝毫破绽！\n"NOR,
});

string *msg = ({
HIW"$N挺剑直刺，倏往倏来，$w"+HIW"化成一道长虹，招招不离$n的$l，穿梭如飞，奔行如电！"NOR,
HIC"$N随手一剑刺向$n，出招平平无奇，去势却是绝快，直如流光破空，星丸跳跃！"NOR,
HIM"$N跃身半空，回剑下击，$w"+HIM"幻出无数个剑花，银光闪烁，宛如天河飞泻，空谷山崩！"NOR,
HIB"$N手中$w"+HIB"连连刺出，剑光有如浮光掠影,惊鸿翩逝,又似星丸跳跃,稍纵即逝！"NOR,
HIY"$N手捏剑诀，$w"+HIY"如青龙跃舞，铿然长吟,一道匹练般的剑芒迅疾迸射，疾刺$n的$l！ "NOR,
HIG"$N剑尖轻点，$w"+HIG"急射而出，幻出万千道剑影，将$n圈在其中，缭绕如虹，寒气大作！ "NOR,
HIR"$N抱剑旋身，人剑合一，$w"+HIR"剑芒爆涨，纵横飞舞，进炸如雨！ "NOR,
HIB"$N随意一剑，$w"+HIB"光芒一闪而收，$n只觉那剑光迅疾逾电，迫在眉睫，唯有急速飞退！ "NOR,
});

string *feiyue_msg = ({
HIW"$N挺剑直刺，倏往倏来，$w化成一道长虹，招招不离$n的$l，穿梭如飞，奔行如电！",
HIC"$N随手一剑刺向$n，出招平平无奇，去势却是绝快，直如流光破空，星丸跳跃！",
HIM"$N跃身半空，回剑下击，$w幻出无数个剑花，银光闪烁，宛如天河飞泻，空谷山崩！",
HIB"$N手中$w连连刺出，剑光有如浮光掠影,惊鸿翩逝,又似星丸跳跃,稍纵即逝！",
HIY"$N手捏剑诀，$w如青龙跃舞，铿然长吟,一道匹练般的剑芒迅疾迸射，疾刺$n的$l！ ",
HIG"$N剑尖轻点，$w急射而出，幻出万千道剑影，将$n圈在其中，缭绕如虹，寒气大作！ ",
HIR"$N抱剑旋身，人剑合一，$w剑芒爆涨，纵横飞舞，进炸如雨！ ",
HIB"$N$w随意一剑，$w光芒一闪而收，$n只觉那剑光迅疾逾电，迫在眉睫，唯有急速飞退！ ",
});


int valid_enable(string usage)
{
                return (usage == "sword") || (usage == "parry") || (usage =="dodge") || (usage == "dagger") || (usage == "stick");
}

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
/*
        if(me->query("gender") != "女性" )
                return notify_fail("「越女剑」乃女子使用，你忙个啥劲。\n");
*/
        if ( me->query("max_neili") < 1000)
                return notify_fail("你的内力不够。\n");

        if ( me->query_skill("yuenu-jian",1) > 150 && me->query_skill("yuenu-jian", 1) < 220 )
                return notify_fail("越女剑法精微之处不能学习！\n"); 

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, j, level, damage;

        level = me->query_skill("yuenu-jian", 1);
        i = random(me->query_skill("sword"))+50;
        if( i<100 ) i = 100;
        j = random(40)-5;
        damage = (random(6)+1)*35;
        if( damage < 150 ) damage =150;

                if( level > 450 ) {
                        return ([
                        "action": msg[random(sizeof(msg))],
                        "damage": 320 + random(280),
                        "damage_type": "刺伤",
                        "dodge":  220+random(30),
                        "force":  250 + random(300),
                        "parry":  150 + random(150),

                        ]);
                }

                else return ([
                        "action": msg[random(sizeof(msg))],
                        "damage": 280 + random(180),
                        "damage_type": "刺伤",
                        "dodge":  120+random(30),
                        "force":  250 + random(300),
                        "parry":  50 + random(50),
                ]);
        }


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int practice_skill(object me)
{
         if ( me->query_skill("yuenu-jian", 1 ) < 300)
                return notify_fail("越女剑只能通过领悟来提高。\n"); 
 
         if ( me->query("jingli") < 50)
                 return notify_fail("你的体力不够练越女剑。\n");
         if ( me->query("neili") < 20)
                 return notify_fail("你的内力不够练习越女剑。\n");
        me->receive_damage("jingli", 40);
         me->add("neili", -15);
         return 1;
 }


string perform_action_file(string action)
{
        return __DIR__"yuenu-jian/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;
        int i;
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if( !objectp(weapon) ) return;

        i = me->query_skill("yuenu-jian", 1);

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"$N剑招穿梭如飞，奔行如电，根本无法闪躲避开！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("dgjj_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$n只觉$N剑光迅疾逾电，迫在眉睫，只得连连招架毫无还手之力！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("parry") == "yuenu-jian"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(HIM"$N身法灵巧之极，一转一侧，将$n招数尽数避开，手中"+weapon->name()+HIM"猛的一抖，戳在$n手腕之上！\n"NOR, 

me,victim);
                if( random(me->query("int")) > victim->query("int")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$N只觉腕上一阵剧痛，呛啷一声，"+weapon1->name()+HIR"脱手而出！\n"NOR, victim);
                        weapon1->unequip();
                     victim->apply_condition("broken_arm",5); 
                        weapon1->move(environment(victim));
                }
                else {
                        message_vision(HIC"$n心下大骇，连忙变招，堪堪避过！\n"NOR, me,victim);
                    me->start_perform(1,"「挑腕」");
                    victim->add_busy(1+random(2));
                       }
        }
     
}

void dgjj_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(CYN"$n终于缓过口气来，身法恢复了正常！\n"NOR,target);
        return;
    }
    if(wizardp(me) && me->query("env/dgjj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="yuenu-jian"
     ||me->query_skill_mapped("parry")!="yuenu-jian"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n终于缓过口气来，身法恢复了正常！\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("dgjj_must_be_hit",1,me,target,--i);
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        string msg;
        int p,j,skill, neili, neili1, exp, exp1;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("yuenu-jian", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");

        if( me->query("jiali") 
        && skill+50 > random(ob->query_skill("parry", 1)/3)
        && wp 
        && skill > 100
        && me->query_skill_mapped("parry") == "yuenu-jian"
        && living(ob)
        && !me->is_busy()){
                if(wp1){
                        msg = HIR"$N剑尖疾点$n持"+wp1->name()+HIR"之手腕！\n"NOR;
                        msg = replace_string(msg, "$w", wp1->name());
                        if(neili >= random(neili1+damage)){
                                if(random(me->query_dex(1)) > ob->query_str(1)/3 && skill > 120){
                                        msg += HIW"结果正好点在$n的手腕！$n只觉腕上一阵剧痛，招式顿时无法连贯！\n"NOR;
                                        ob->add_busy(2+random(2));
                                        j = -(damage);
                                }
                                else{
                                        ob->receive_damage("qi", damage/10, me);
                                        ob->receive_wound("qi", damage/10, me);
                                        p = ob->query("qi")*100/ob->query("max_qi");
                                        msg += COMBAT_D->damage_msg(damage/20, "伤害");
                                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                        j = -(damage/2+skill/2);
                                }
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += "$n攻势受阻，威力登减。\n";              
                                j = -(damage/2+skill/2);
                        }
                        else{
                                j = damage/2+random(damage/2);
                                if(j<damage/2) msg += "$n攻势受阻，威力登减。\n";
                                else msg += "$n攻势受阻，威力登减。\n";
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
                else{
                        msg = HIY"$N更不避让，"+wp->name()+HIY"刺出，后发先至，疾刺$n双目！\n"NOR;
                        if(neili >= neili1+random(neili1)+damage){
                                ob->receive_damage("qi", damage/10, me);
                                ob->receive_wound("qi", damage/10, me);
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += COMBAT_D->damage_msg(damage, "刺伤");
                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                j = -(damage*2+skill);
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += "$n攻势受阻，威力登减。\n";              
                                j = -(damage+skill);
                        }
                        else{
                                j = damage/2+random(damage/2); 
                                if(j<damage/2) msg += "$n攻势受阻，威力登减。\n";
                                else msg += "$n攻势受阻，威力登减。\n";
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
        }

   if ( random(me->query("kar")) >= 10 )
{
   message_vision(HIR"$N忽嫣然一笑，长袖连挥，身形如行云流水，对敌攻势竟是不闻不问！\n" NOR, me);
  return -damage;      }
}
