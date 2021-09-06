// kuaihuo-strike.c 快活十三掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N左手一拳直攻，右手如开似闭，封住对方出手，底下暗出撩阴腿，正是"GRN"「痛快淋漓」"NOR"",
	"lvl"    : 0,
	"skill_name" : "痛快淋漓"
]),
([	"action" : "$N右手一掌封向$n面门，手掌暗颤，已是封住$n视线，左手直拳攻向$n胸口，正是一招"HIG"「敞开胸臆」"NOR"",
	"lvl"    : 20,
	"skill_name" : "敞开胸臆"
]),
([	"action" : "$N右手五直叉开，挥向$n面门，左手挥动，急点$n右身数处大穴，乃是"HIB"「六月挥扇」"NOR"",
	"lvl"    : 40,
	"skill_name" : "六月挥扇"
]),
([	"action": "$N使出"HIR"「腊月围炉」"NOR"，双臂向$n身体抱去，正中出腿疾踢$n$l",
	"lvl"    : 60,
	"skill_name" : "腊月围炉"
]),
([	"action" : "$N使出"MAG"「月下赏梅」"NOR"，左掌入弯月，斜斜向$n面门劈下，右手五指半曲，如梅枝斜出，指向$n",
	"lvl"    : 80,
	"skill_name" : "月下赏梅"
]),
([	"action" : "$N腰间使出铁板桥功夫，双手成提壶斟酒状，片刻间已指向$n嘴角，正是一招"HIW"「花间酌酒」"NOR"",
	"lvl"    : 100,
	"skill_name" : "花间酌酒"
]),
([	"action" : "$N右手五指直颤，急点$n数处大穴，左手成鹤形击出，乃是"HIM"「弄鹤闲琴」"NOR"",
	"lvl"    : 120,
	"skill_name" : "弄鹤闲琴"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练快活十三掌必须空手。\n");
        if ((int)me->query_skill("panshi-shengong", 1) < 20)
                return notify_fail("你的磐石神功火候不够，无法学快活十三掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练快活十三掌。\n");
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
        int i, level;
        level = (int)me->query_skill("kuaihuo-zhang", 1);

        if (me->query_temp("tsjf/shibapan") == 2){
            return([
                   "action": BLU "紧接着$N"BLU"右手一转一收，在$n"BLU"还没有反应过来时飞身欺前，腾出左手翻腕就是一式「快活十三掌」！"NOR,
                   "force" : 500,
                   "dodge" : 10,
                   "damage_type" : "瘀伤",
                   ]);
            }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{

        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练快活十三掌。\n");
        me->receive_damage("jingli", 30);
        me->receive_damage("neili", 5);
        if(me->query_skill("kuaihuo-zhang", 1) > 170)
                me->receive_damage("jingli", 10);
        if(me->query_skill("kuaihuo-zhang", 1) > 190)
                me->receive_damage("neili", 5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuaihuo-zhang/" + action;
}