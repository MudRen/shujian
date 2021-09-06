// quanzhen-jianfa 全真剑法
// Modify By River 99.5.26
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$N剑影晃动，踏奇门，走偏锋，一式「分花拂柳」，$w径直刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "分花拂柳",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「横行漠北」直刺$n的$l",
	"lvl" : 10,
	"skill_name" : "横行漠北",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N拔步挺腰，一式「排山倒海」，手中$w沉滞无比，缓缓挥向$n的$l",
	"lvl" : 25,
	"skill_name" : "排山倒海",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N身子微侧，$w自左而右划出一个大弧，一式「顺水推舟」，平平地向$n的$l挥去",
	"lvl" : 30,
	"skill_name" : "顺水推舟",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N回身拧腰，右手虚抱成圆，一式「马蹴落花」，手中$w中宫直进，刺向$n的$l",
	"lvl" : 50,
	"skill_name" : "马蹴落花",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N一式「开天辟地」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
	"lvl" : 70,
	"skill_name" : "开天辟地",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N运气施出「雷电交加」，$w逼出一道丈许青芒，闪电般破空射向$n的$l",
	"lvl" : 90,
	"skill_name" : "雷电交加",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N双腿半屈半蹲，一式「人神共愤」，$w划出无数圆圈，狂风骤起，笼罩天地",
	"lvl" : 110,
	"skill_name" : "人神共愤",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry"); 
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if( ! me->query_skill("xiantian-gong"))
	if ((int)me->query_skill("yunu-xinjing", 1) < 20)
		return notify_fail("你的玉女心经火侯太浅。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{ 
	int i, j, level,xtg;
	level = me->query_skill("quanzhen-jianfa",1);
	xtg = me->query_skill("xiantian-gong", 1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("hebi") && random(2) || me->query_temp("hubo")) { 
				return ([  
                                        "action" :random(2)? HIB + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIB)+NOR
							   : MAG + replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG)+NOR,
					"force" : 200 + random(350),
					"dodge": random(30),
					"damage": 80 + random(140),
					"parry": random(30),
					"weapon" : random(2)?"剑气":"剑锋",
					"damage_type" : random(2)?"刺伤":"割伤",
				]);
			}
                        if( me->query_temp("sanqing")){

				return ([  
                                        "action":HIC+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
					"damage": 60 + random(80) + random((level+xtg)/4),
					"parry": random(15)+xtg/10,//原来是15
					"weapon" : random(2)?"剑气":"剑锋",
					"damage_type" : random(2)?"刺伤":"割伤",
				]);
			}
			if( me->query_temp("qzjf/lian")){
				return ([  
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
                                        "damage": 70 + random(50) + xtg/10,
					"parry": random(15)+xtg/10,//原来是15
					"weapon" : random(2)?"剑气":"剑锋",
					"damage_type" : random(2)?"刺伤":"割伤",
				]);
			}
						if( me->query_temp("qzjf/jianjue")){
				return ([  
					"action":HIC+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC), NOR, HIC)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
					"damage": 80 + random(100) + random((level+xtg)/5),
					"parry": random(15)+xtg/10,//原来是15
					"weapon" : random(2)?"剑气":"剑锋",
					"damage_type" : random(2)?"刺伤":"割伤",
				]);
			}
			return ([
				"action": action[j]["action"],
				"force" : 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 80 +random(80),
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练全真剑法。\n");
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力不够练全真剑法。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"quanzhen-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
//      增加全真剑诀，辅助攻击，概率很低
        object weapon; 
        int i;
        weapon = me->query_temp("weapon");
        i = me->query_skill("quanzhen-jianfa", 1);

        if( !userp(me) && random(2) ) return 0;
if(me->query_temp("jianjue")) return 0;
        if( !weapon || weapon->query("skill_type") != "sword" ) return 0;
        if( i < 350 ) return 0;
        if( !me->query("quest/qzjf/jianjue")) return 0;
        if( damage_bonus < 100 ) return 0;
        if( !living(victim) ) return 0;

        if( i >= 300 && !random(3)
         && random(me->query_con()) > victim->query_con()/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3 )
                         {
                if( me->query_skill_prepared("strike") == "haotian-zhang"
                 && me->query_skill_mapped("strike") == "haotian-zhang"
                 && me->query_skill_mapped("parry") == "quanzhen-jianfa"
                 && me->query_skill_mapped("force") == "xiantian-gong"
                 && me->query_skill_mapped("dodge") == "jinyan-gong"
                 && me->query_skill("haotian-zhang", 1) >= 200 && random(2) ) {
                        message_vision(HIW"$N默念全真剑诀，“"HBMAG+HIW"斗柄东指，天下皆春；斗柄南指，天下皆夏。"NOR+HIW"”右手猛的运剑回转，左手终南指法之「一阳指」随劲而起！"NOR, me);
                        weapon->unequip();
                        me->add_temp("apply/attack",  me->query_skill("quanzhen-jianfa", 1)/3);
                        COMBAT_D->do_attack(me, victim, 0, 3);
                        me->add_temp("apply/attack", -me->query_skill("quanzhen-jianfa", 1)/3);
                        weapon->wield();
                } else {
                        message_vision(HIW"$N默念全真剑诀，“"HBBLU+HIW"斗柄西指，天下皆秋；斗柄北指，天下皆冬。"NOR+HIW"”紧接着"+weapon->name()+HIW"猛的回转再次刺出！"NOR, me);
                        me->set_temp("jianjue", 1);
                        me->add_temp("apply/attack",  me->query_skill("quanzhen-jianfa", 1)/3);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("quanzhen-jianfa", 1)/3);
                        me->delete_temp("jianjue");
                }
        }
        else if( i >= 400 && random(2)
         && random(me->query("combat_exp")) > victim->query("combat_exp")/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3
         && random(me->query_con()) > victim->query_str()/3
         && !victim->query_temp("lost_attack") ) {
                message_vision(HIW"$N默念全真剑诀，“"HBRED+HIW"认星先从北斗来，由北往西再展开”。"NOR+HIW"”顿时剑气纵横，将$n攻个措手不及！\n"NOR, me, victim);
                victim->add_temp("lost_attack", 1+random(3));
                victim->apply_condition("no_perform", 1+random(2));
                return random(me->query_skill("sword"))/3;
        }
        return 0;
}

void check_fight(object me,object victim)
{
	if(!victim) return;
	if( ! me 
         || ! me->query_temp("hebi")){
		victim->delete_temp("lost_attack");
		return;
        }
	call_out("check_fight", 1, me, victim);
}
