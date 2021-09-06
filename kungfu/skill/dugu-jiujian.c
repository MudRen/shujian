//KinGSo 2006年5月修改

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
        "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
        "$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
        "$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来。\n"
        "$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
        "$n突然使出青城派松风剑法的「鸿飞冥冥」，长剑对着$P一绞，企图突破$P的攻势。\n"
        "$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
        "只见$n不退反进，身如飘风，一式「天柱云气」动向无定，挡住了$P的\n进攻。\n",
        "$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招\n",
});
         
mapping *action = ({
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「" HIC "来鹤清"
                   "泉" NOR "」直刺$n的$l",
        "force" : 290,
        "dodge" : 30,
        "parry" : 40,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([      "action" : "$N奇诡地向$n挥出「" CYN "泉鸣芙蓉" NOR "」、「" MAG "鹤翔"
                   "紫盖" NOR "」、「" HIG "石廪书声" NOR "」、「" HIW "天柱"
                   "云气" NOR "」及「" HIY "雁回祝融" NOR "」衡\n山五神剑",
        "force" : 210,
        
        "dodge" : 35,
        "parry" : 35,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N剑随身转，续而刺出十九剑，竟然是华山「" HIW "玉女十九剑"
                   NOR "」，但奇的是这十九剑便如一招，手法之快，\n直是匪夷所"
                   "思",
        "force" : 240,
        
        "dodge" : 35,
        "parry" : 45,
        "damage": 175,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢"
                   "慢推去",
        "force" : 280,
        
        "dodge" : 55,
        "parry" : 65,
        "damage": 160,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千"
                   "里，尽括嵩山剑势击向$n",
        "force" : 340,
        
        "dodge" : 45,
        "parry" : 45,
        "damage": 210,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，"
                   "竟化「" HIY "泰山十八盘" NOR "」为一剑攻\n向$n",
        "force" : 250,
        
        "dodge" : 55,
        "parry" : 55,
        "damage": 210,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑招突变，使出衡山的「" HIB "一剑落九雁" NOR "」，削向$n"
                   "的$l，怎知剑到中途，突然转向，大出$n\n意料之外",
        "force" : 240,
        
        "dodge" : 45,
        "parry" : 35,
        "damage": 210,
        "damage_type" : "刺伤"
]),
([      "action" : "$N吐气开声，一招似是「" CYN "独劈华山" NOR "」，手中$w向下"
                   "斩落，直劈向$n的$l",
        "force" : 345,
        
        "dodge" : 55,
        "parry" : 45,
        "damage": 195,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的「" HIW "百变千幻云雾十"
                   "三式" NOR "」，剑式有如云卷雾涌，旁观\n者不由得目为之眩",
        "force" : 330,
        
        "dodge" : 65,
        "parry" : 55,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融「" HIR "达摩剑" NOR "」"
                   "为一式，闲舒地刺向$n",
        "force" : 330,
        
        "dodge" : 35,
        "parry" : 45,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使「" CYN "太极剑" NOR "」剑意，划出大大小小无"
                   "数个圆圈，无穷无尽源源不绝地缠向$n",
        "force" : 230,
        
        "dodge" : 85,
        "parry" : 55,
        "damage": 220,
        "damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「"
                   HIR "伏摩剑" NOR "」的剑意表露无遗",
        "force" : 330,
       
        "dodge" : 45,
        "parry" : 55,
        "damage": 180,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N突然虚步提腰，使出酷似武当「" HIG "蜻蜓点水" NOR
                   "」的一招",
        "force" : 180,
        
        "dodge" : 55,
        "parry" : 35,
        "damage": 210,
        "damage_type" : "刺伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是"
                   "「" HIR "伏魔剑" NOR "」的「" HIR "龙吞式" NOR "」",
        "force" : 270,
        
        "dodge" : 45,
        "parry" : 55,
        "damage": 170,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然运剑如狂，一手关外的「" HIY "乱披风剑法" NOR "」，"
                   "猛然向$n周身乱刺乱削",
        "force" : 330,
        
        "dodge" : 55,
        "parry" : 55,
        "damage": 180,
        "damage_type" : "刺伤"
]),
([      "action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法"
                   "的虚实",
        "force" : 310,
        
        "dodge" : 45,
        "parry" : 45,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([      "action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是"
                   "什么剑法",
        "force" : 330,
        
        "dodge" : 55,
        "parry" : 35,
        "damage": 175,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不"
                   "知如何是好",
        "force" : 360,
        
        "dodge" : 50,
        "parry" : 65,
        "damage": 210,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，"
                   "迫得$n不得不守",
        "force" : 310,
        
        "dodge" : 35,
        "parry" : 55,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([      "action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，"
                   "$n难以看清剑招来势",
        "force" : 334,
        
        "dodge" : 55,
        "parry" : 65,
        "damage": 180,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么"
                   "招式",
        "force" : 360,
       
        "dodge" : 45,
        "parry" : 55,
        "damage": 190,
        "damage_type" : "刺伤"
]),
([      "action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不"
                   "可思议",
        "force" : 360,
        
        "dodge" : 45,
        "parry" : 55,
        "damage": 188,
        "damage_type" : "刺伤"
]),
([      "action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向"
                   "$n的$l",
        "force" : 350,
        
        "dodge" : 65,
        "parry" : 65,
        "damage": 210,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，当真人所"
                   "难测",
        "force" : 310,
        
        "dodge" : 65,
        "parry" : 65,
        "damage": 210,
        "damage_type" : "刺伤"
])
});

mapping *action2 = ({
([      "action" : HIW "但见$N手中$w" HIW "破空长吟，平平一剑刺向$n，毫无招式可言"NOR,
        "force" : 400,
        
        "dodge" : 80,
        "parry" : 80,
        "damage": 300,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N揉身欺近，轻描淡写间随意刺出一剑，简单之极，无招无式"NOR,
        "force" : 450,
        
        "dodge" : 90,
        "parry" : 90,
        "damage": 360,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N身法飘逸，神态怡然，剑意藏于胸中，手中$w" HIW "随意挥洒而出，独孤"
                   "九剑已到了收发自如的境界"NOR,
        "force" : 500,
        
        "dodge" : 100,
        "parry" : 100,
        "damage": 380,
        "damage_type" : "刺伤"
]),
([
        "action" : HIW "$N将$w"HIW"随手一摆，但见$n自己向$w撞将上来，神剑之威，当真人所" 
                   "难测"NOR,
        "force" : 510,
        
        "dodge" : 95,
        "parry" : 95,
        "damage": 310,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么" 
                   "招式"NOR,
        "force" : 460,
       
        "dodge" : 95,
        "parry" : 95,
        "damage": 320,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不" 
                   "可思议"NOR,
        "force" : 460,
        
        "dodge" : 95,
        "parry" : 95,
        "damage": 328,
        "damage_type" : "刺伤"
]),
([      "action" : HIW "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向" 
                   "$n的$l"NOR,
        "force" : 450,
        
        "dodge" : 95,
        "parry" : 95,
        "damage": 310,
        "damage_type" : "刺伤"
]),

});
int valid_enable(string usage)
{
        return (usage == "sword") || (usage == "parry") ;
}

mapping query_action(object me, object weapon)
{
        if (me->query_skill("dugu-jiujian", 1) > 300 )
               return action2[random(sizeof(action2))];

        else   return action[random(sizeof(action))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;
        object m_weapon;

        if ((int) me->query_skill("dugu-jiujian", 1) < 120
           || ! (m_weapon = me->query_temp("weapon"))
           || ! living(me) || me->is_busy()
           || m_weapon->query("skill_type") != "sword")
                return;
         
	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return;

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return;




        ap = ob->query_skill("parry")+ mp; //+ mp;
      //  mp = random (me->query_skill("dugu-jiujian", 1));
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("dugu-jiujian", 1);
         
        // 无招
        if (me->query("quest/pass/dugu-jiujian/wuzhao"))

        {
             if (me->query_skill("sword") * 3 / 4 + random(me->query_skill("sword"))
                 > ob->query_skill("parry"))
             {
                        result = ([ "damage": -damage ]);

                        result += (["msg" : HBWHT HIB "$n" HIG "不理会$N" HIG "的攻势，"
                                    "随意挥出一剑，反攻向$N" HIG "。\n" NOR]);
            
                        ob->start_busy(1);
             }
             
             return result;
             
        }

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(9))
                {
                case 0:
                        result += (["msg" : HBWHT HIC "却见$n" HIC "踏前一步，剑式斜指$P" HIC
                                            "右臂，招式迅捷无比，使得$N" HIC "闪身而退"
                                            "。\n" NOR]);
                        break;

                case 1:
                        result += (["msg" : HBWHT HIC "可$n" HIC "以攻为守，以进为退，凝神运"
                                            "气向$N" HIC "猛攻快打地挥出方位大异的泰山"
                                            "「" NOR + YEL "快活三" NOR + HIC "」剑法。"
                                            "\n" NOR]);
                        break;

                case 2:
                        result += (["msg" : HBWHT HIC "$n" HIC "突然一剑点向$N" HIC "，虽一剑"
                                            "却暗藏无数后着，$N" HIC "顿时手足无措，攻"
                                            "势不由自主停了下来。\n" NOR]);
                        break;

                case 3:
                        result += (["msg" : HBWHT HIC "可是$n" HIC "不闪不避，举剑闪电般使出"
                                            "「" NOR + HIG "叠翠浮青" NOR + HIC "」反削"
                                            "$N" HIC "手腕，挡开了此招。\n" NOR]);
                        break;

                case 4:
                        result += (["msg" : HBWHT HIC "却见$n" HIC "突然使出青城派松风剑法「"
                                            NOR + CYN "鸿飞冥冥" NOR + HIC "」，长剑对"
                                            "着$N" HIC "一绞，顿时突破了攻势。\n" NOR]);
                        break;

                case 5:
                        result += (["msg" : HBWHT HIC "$n" HIC "挺剑而射，若一招「" NOR + HIW
                                            "白云出岫" NOR + HIC "」回刺$N" HIC "，顿"
                                            "时已将攻势化解。\n" NOR]);
                        break;

                case 6:
                        result += (["msg" : HBWHT HIB "只见$n" HIB "不退反进，身如飘风，一式" 
                                            "「" NOR + HIW "天柱云气" NOR + HIC "」动向"
                                            "无定，挡住了进攻。\n" NOR]);
                        break;

                case 7:
                        result += (["msg" : HBWHT HIC "但见$n" HIC "不退反进，使出恒山剑招「"
                                            NOR + HIY "绵里藏针" NOR + HIC "」，剑气四"
                                            "溢，架开了$N" HIC "这招。\n" NOR]);
                        break;

                default:
                        result += (["msg" : HBWHT HIC "$n" HIC "剑法突变，剑势伸缩不定，奔腾"
                                            "矫夭，逆使嵩山剑法的「" NOR + HIY "天外玉"
                                            "龙" NOR + HIC "」企图迫使$N" HIC "变招。\n"
                                            NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(3))
                {
                case 0:
                        result = HIY "$n" HIY "一抖手中的" + m_weapon->name() +
                                 HIY "，中攻直进一剑挺进，可是$N" HIY "反招更快"
                                 "，进袭$n" HIY "！\n" NOR;
                        break;

                case 1:
                        result = HIY "$n" HIY "手中" + m_weapon->name() + "轻挑"
                                 "，" HIY "正指向$N" HIY "攻势中的破绽，可是$N"
                                 HIY "身形一变，破绽立刻不成为破绽。\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "手中" + m_weapon->name() + HIY
                                 "续变换数种剑招，然而$N" HIY "理也不理，再次攻"
                                 "出，丝毫不受$n" HIY "的迷惑。\n"  NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon, weapon2;
        int i, ap, dpp, dpd, dpf;
        string type, msg;

        lvl = me->query_skill("dugu-jiujian", 1);

        if (me->query("neili") < 2000
           || me->query_skill_mapped("sword") != "dugu-jiujian"
           ||! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword"
           ||  !me->query("quest/pass/dugu-jiujian/wuzhao") )

                     return 0;

         
	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return 0;

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return 0;


        ap = me->query_skill("sword") + me->query_dex() + me->query_int()   ;
        dpp = victim->query_skill("parry");
        dpd = victim->query_skill("dodge");
        dpf = victim->query_skill("force");


        me->add("neili", -100);

        switch(random(5))
        {
           case 1:
              if (ap * 3 / 4 + random(ap) > dpp)
              {
                  me->add("neili", -220);
                  victim->receive_wound("qi", (damage_bonus - 30) / 2, me);
                  
                  return random(2) ? HIR "$N" HIR "一剑攻出，剑气横飞，" + weapon->name() + HIR
                                     "时若游龙穿空，时若惊鸿渡云，却不知这普通的"
                                     "一剑之中竟蕴藏着如此威力。\n" NOR:
                                     HIR "$N" HIR "手中" + weapon->name() + HIR "犹"
                                     "如生了眼睛一般，一剑随意挥出，竟直刺向$n" HIR 
                                     "小腹，看似平淡，但方位、力道却拿捏得恰倒好处。\n" NOR;
             }
             break;

           case 2:
              if (ap * 3 / 4 + random(ap) > dpp && me->query_dex() >= 50)
              {
                  me->add("neili", -220);
                  victim->receive_wound("qi", (damage_bonus - 30) / 2, me);
                  
                  return random(2) ? HBWHT HIR "$N" HIR "一剑攻出，剑气横飞，" + weapon->name() + HIR
                                     "时若游龙穿空，时若惊鸿渡云，却不知这普通的"
                                     "一剑之中竟蕴藏着如此威力。\n" NOR:
                                     HIR "$N" HIR "手中" + weapon->name() + HIR "犹"
                                     "如生了眼睛一般，一剑随意挥出，竟直刺向$n" HIR 
                                     "小腹，看似平淡，但方位、力道却拿捏得恰倒好处。\n" NOR;
             }
             break;

          case 3:
             message_vision(HIC "\n$N" HIC "随意挥洒手中的" + weapon->name() +
                            HIC "，招招从出其不意的方位直指$n" HIC "招式中的"
                            "破绽！\n" NOR, me, victim);

             if (! me->is_busy())
             {
                  weapon = me->query_temp("weapon");
                  weapon2 = victim->query_temp("weapon");
                  if (weapon2)type = weapon2->query("skill_type");


                  if (ap * 3 / 4 + random(ap) >= dpf && weapon2
                      && type != "pin")
                  {
                           msg = HIW "$n" HIW "觉得眼前眼花缭乱，手中"
                                 "的" + weapon2->name() + HIW "一时竟"
                                 "然拿捏不住，脱手而出！\n" NOR;
                           weapon2->move(environment(me));      
                           me->add("neili", -100);                 
                  } else
                  {
                           msg = HIY "$n" HIY "略得空隙喘息，一时间却"
                                 "也无力反击。\n" NOR;
                           me->add("neili", -40);
                  }
             }else 
             if (ap * 4 / 5 + random(ap) > dpd)
             {
                          msg = HBWHT HIY "$n" HIY "连忙抵挡，一时间不禁手忙脚乱，"
                                "无暇反击。\n" NOR;

                          me->start_busy(1);
                          victim->start_busy(1 + random(lvl / 100));
             }
             else
             {
                          msg = HIC "$N" HIC "随意挥洒着手中的" + weapon->name() +
                                HIC "刺向$n" HIC "，不过$n" HIC "防守的异常严密，$N"
                                HIC "一时竟然无法找到破绽。\n" NOR;
                          me->start_busy(1 + random(2));
                          victim->start_busy(1);
             }
             message_vision(msg, me, victim);
             break;
          
          case 4:
             if (ap * 4 / 5 + random(ap) > dpd && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian") &&
                 me->query_dex() >= 60)
             {
                weapon = me->query_temp("weapon");
                message_vision(HIY "\n$N" HIY "胸藏剑意，手中" + weapon->name() + HIY 
                             "随意挥洒而出，速度之快，方位之准，显是独孤九剑已达到"
                             "收发自如的境界。\n" NOR,
                             me, victim);

                me->add("neili", -320);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 3; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, random(4)?1:3);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
          
          default :
             if (ap * 4 / 5 + random(ap) > dpd && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian"))
             {
                weapon = me->query_temp("weapon");
message_vision(HBWHT HIB "\n$N" HIB "胸藏剑意，手中" + weapon->name() + HBWHT HIB
                             "随意挥洒而出，速度之快，方位之准，显是独孤九剑已达到"
                             "收发自如的境界。\n" NOR,
                             me, victim);

                me->add("neili", -320);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 3; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, random(4)?1:3);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
       }
}

int valid_learn(object me)
{
	mapping my_fam  = me->query("family");
	if(!my_fam || my_fam["master_name"] != "风清扬")
		return notify_fail("你不是风清扬的弟子，不能学习「独孤九剑」。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("dugu-jiujian",1) > 60
		 &&(int)me->query_skill("dugu-jiujian",1) < 300)
		return notify_fail("这套剑法我就教到这儿，以后就要靠你自己去领悟了。\n");
	return 1;
}

int query_effect_parry(object attacker, object me)
{
        object weapon;
        int lvl;

        if (! objectp(weapon = me->query_temp("weapon")) ||
           (string)weapon->query("skill_type") != "sword")
                return 0;

        lvl = me->query_skill("dugu-jiujian", 1);
        if (lvl < 90)  return 0;
        if (lvl < 100) return 50;
        if (lvl < 125) return 55;
        if (lvl < 150) return 60;
        if (lvl < 175) return 65;
        if (lvl < 200) return 70;
        if (lvl < 225) return 75;
        if (lvl < 250) return 80;
        if (lvl < 275) return 90;
        if (lvl < 325) return 100;
        if (lvl < 350) return 110;
        return 120;
}

int practice_skill(object me)
{
	if ( me->query_skill("dugu-jiujian", 1 ) < 300)
		return notify_fail("独孤九剑只能通过领悟来提高。\n");

	if ( me->query("jingli") < 50)
		return notify_fail("你的体力不够练独孤九剑。\n");
	if ( me->query("neili") < 50)
		return notify_fail("你的内力不够练习独孤九剑。\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{

        return __DIR__"dugu-jiujian/" + action;
}

void skill_improved(object me)
{
        int lvl, i;

        i = me->query("int") / 3;
        lvl = me->query_skill("dugu-jiujian", 1);

        if (lvl > 120
           && me->query("can_perform/dugu/qi") <= 100
           && ! me->query("quest/pass/dugu-jiujian/wuzhao"))
        {
                if (me->add("can_perform/dugu/qi", random(i)) < 100)
		{
                        tell_object(me, HIC "你对独孤九剑「" HIW "破气式"
                                        HIC "」有了新的领悟。\n" NOR);
                } else
		{
                        tell_object(me, HIC "你通晓了独孤九剑「" HIW "破"
                                        "气式" HIC "」的奥秘。\n" NOR);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
		}
        }

        if (lvl > 150
           && me->query("can_perform/dugu/po") <= 100
           && ! me->query("quest/pass/dugu-jiujian/wuzhao"))
        {
                if (me->add("can_perform/dugu/po", random(i)) < 100)
		{
                        tell_object(me, HIC "你对独孤九剑「" HIR "总诀式"
                                        HIC "」有了新的领悟。\n" NOR);
                } else
		{
                        tell_object(me, HIC "你通晓了独孤九剑「" HIR "总"
                                        "诀式" HIC "」的奥秘。\n" NOR);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
		}
        }
}

int difficult_level()
{
        object me = this_object();
       
        if ((int) me->query_skill("dugu-jiujian", 1) > 400 )

               return 1200;

        else   return 600;
}
