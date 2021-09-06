//tianmo-jian.c 天魔剑法
//By xjqx@SJ 2009/1/3

inherit SKILL; 

mapping *action = ({
([      "action":"$N手中$w一抖，幻化出满天剑影，一招「日月辉煌」恰似满天风雪罩向$n。",
        "lvl"   :0,
        "skill_name" :"日月辉煌",
        "damage_type":"刺伤"
]),
([      "action":"$N悄然一笑，身形急旋，仿佛飞蝶戏花一般，绕着$n游走，手中$w使出一招「碧苔芳晖」接连向$n刺出五剑。",
        "lvl"   :30,
        "skill_name" :"碧苔芳晖",
        "damage_type":"刺伤"
]),
([      "action":"$N大步向前，姿势飘逸，如飞燕掠过长空，一招「海天一线」手中的$w电光一闪，刺向$n。",
        "lvl"   :80,
        "skill_name" :"海天一线",
        "damage_type":"刺伤"
]),
([      "action":"$N一挽手中$w，使出一招「凤舞九天」只见$N吐声发力，$w向$n点去，一股劲气夹着「啪、啪」的声音向$n卷去。",
        "lvl"   :110,
        "skill_name" :"凤舞九天",
        "damage_type":"刺伤"
]),
([      "action":"$N脚步游移不定，倒转手中$w，身行如燕直冲而起，一式「微雨燕双飞」自上而下直向$n扑来。",
        "lvl"   :150,
        "skill_name" :"微雨燕双飞",
        "damage_type":"刺伤"
]),
([      "action":"$N心底空明，剑随心意，身行傲然拔起，正是「空翠落庭阴」。$n为$N气势所逼，不住倒退。",
        "lvl"   :180,
        "skill_name" :"空翠落庭阴",
        "damage_type":"割伤"
]),
([      "action":"只见$N手中$w发出龙吟之声，阴阳相和，高声琨，正声缓，一招「壮气蒿莱」，剑锋直向$n左肩刺过去。",
        "lvl"   :210,
        "skill_name" :"壮气蒿莱",
        "damage_type":"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
     object weapon;

     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "sword")
         return notify_fail("你必须装备剑才能学习剑法。\n");

   if(!me->query_skill("xixing-dafa", 1))
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("你的特殊内功功力太浅，不能学天魔剑。\n");

     if ((int)me->query_skill("sword", 1) < 130)
         return notify_fail("你的基本剑法火候不够。\n");

     if ((int)me->query_skill("sword", 1) < (int)me->query_skill("tianmo-jian", 1))
         return notify_fail("你的基本剑法水平有限，无法领会更高深的天魔剑法。\n");

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
	int i, j, level;

	level = (int) me->query_skill("tianmo-jian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(100),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
     object weapon;
     int cost;

     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "sword")
         return notify_fail("你必须装备剑才能练天魔剑法。\n");

     if ((int)me->query("qi") < 160)
         return notify_fail("你的体力太低了。\n");

     cost = me->query_skill("tianmo-jian", 1) / 2 + 100;
     if ((int)me->query("neili") < cost)
         return notify_fail("你的内力不够练「天魔剑法」。\n");

     me->receive_damage("qi", 130);
     me->add("neili", -cost);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-jian/" + action;
}

