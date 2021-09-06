// sanhua-zhang.c -É¢»¨ÕÆ
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$NºÏÕÆ±§Çò£¬Ò»Ê½¡¸"HIG"´ºÉî·¼²Ý¾¡"NOR"¡¹£¬Ë«ÕÆ±ä»ÃÍÌÍÂ£¬»º»ºÍÆÏò$nµÄ$l",
	"lvl" : 0,
	"skill_name" : "´ºÉî·¼²Ý¾¡",
        "damage_type" : "ðöÉË"
]),
([
	"action" : "$NÎåÖ¸ÕÀ¿ª£¬Ò»Ê½¡¸"GRN"ÏÄÏÐ¶ÀÀ¼Ü°"NOR"¡¹£¬×óÓÒÕÆ´©²å·­·É£¬¼²Ïò$nµÄ$lÅÄÈ¥",
	"lvl" : 30,
	"skill_name" : "ÏÄÏÐ¶ÀÀ¼Ü°",
        "damage_type" : "ðöÉË"
]),
([
	"action" : "$NÊ¹Ò»Ê½¡¸"HIY"Çïº¨¾ÕËªÇå"NOR"¡¹£¬×óÕÆÐéÍÐ£¬ÓÒÕÆÕ§ÉìÕ§ºÏ£¬ÃÍµØ²åÍù$nµÄ$l",
	"lvl" : 60,
	"skill_name" : "Çïº¨¾ÕËªÇå",
        "damage_type" : "ðöÉË"
]),
([
	"action" : "$NË«ÕÆÑªºì£¬Ò»Ê½¡¸"HIW"¶¬ÎÔÌýÃ·Ò÷"NOR"¡¹£¬»Ã³ÉÂþÌìÃ·»¨¶ä¶ä£¬Óêµã°ãÏò$n»÷È¥",
	"lvl" : 90,
	"skill_name" : "¶¬ÎÔÌýÃ·Ò÷",
        "damage_type" : "ðöÉË"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if ((int)me->query_int(1) > 40)
		return combo=="nianhua-zhi"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("Á·É¢»¨ÕÆ±ØÐë¿ÕÊÖ¡£\n");
	if ((int)me->query_skill("yijin-jing", 1) < 60)
		return notify_fail("ÄãµÄÒ×½î¾­ÄÚ¹¦»ðºò²»¹»£¬ÎÞ·¨Ñ§É¢»¨ÕÆ¡£\n");
	if ((int)me->query_int(1) > 30) {
		return 1;
	}
	else {
		if ( me->query_skill("banruo-zhang", 1)
		 && me->query_skill("yizhi-chan", 1)
		 && me->query_skill("jingang-quan", 1)
		 && me->query_skill("nianhua-zhi", 1)
		 && me->query_skill("qianye-shou", 1)
		 && me->query_skill("ruying-suixingtui", 1)
		 && me->query_skill("longzhua-gong", 1))
			return notify_fail("ÄãµÄ¹¦Á¦²»¹»£¬ÎÞ·¨Í¬Ê±Ñ§Ï°Á½ÖÖÒÔÉÏµÄÉÏ³Ë¹¦·ò¡£\n");
	}
	if ((int)me->query("max_neili") < 600)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·É¢»¨ÕÆ¡£\n");
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
	int i, level, j;
	level   = (int) me->query_skill("sanhua-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("sanhua-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
	if ( me->query("neili") < 20)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·É¢»¨ÕÆ¡£\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sanhua-zhang/" + action;
}
