// jinshen-jianfa.c ���߽���
// by snowman@SJ 2000

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$N��ʽƽ�ߣ�һ�С�˫����Ҹ��������$w��������$n��$l",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N�������У��ڿ�������б�㣬����$wһʽ���������¡�ֱ��$n��$l",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ�������߰�β������ϥ΢�䣬$wб��,����Ļ���$n��$l",
	"lvl" : 50,
	"damage_type" : "����"
]),
([
	"action" : "$N����Խ��Խ����һ�С��������ڡ�������$w����һ�����⣬�ᴩ$n��$l",
	"lvl" : 60,
	"damage_type" : "����"
]),
([
	"action" : "$N����΢ת�������ڿգ�һ�С�����Ϸ�ߡ������е�$w���බ����Ϯ��$n��$l",
	"lvl" : 80,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���Ӱ���١��������Բ࣬����ֱ�죬������Σ���������ͻ��$w����$n��$l",
	"lvl" : 100,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�����ʹ�ý��߽����ܽ�һ����ϰ��Ľ��߽�����\n");

	if ( me->query("max_neili") < 1000)
		return notify_fail("�������������\n");
	if ( me->query_skill("sword", 1) < 100)
		return notify_fail("��Ļ�����̫ǳ��\n");
	if ( !me->query("jinshe/jianfa"))
		return notify_fail("���޷���ϰ���߽�����\n");

	return 1;
}

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("jinshe-jianfa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
            if ( me->query("quest/���߽���/pass")) {
        if (me->query_temp("jsj")) 
                    return ([
                     "action" : YEL+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"YEL)+NOR,
                         "force" : 350+random(250),
                         "dodge": 20+random(20),
                        "parry": 20+random(20),
                         "damage" : level/2 +random(level/2),
                     "damage_type" : "����",
                    ]);
                  else
                  return ([
                    "action" : CYN+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"CYN)+NOR,
                         "force" : 300+random(250),
                        "dodge": 10+random(20),
                        "parry": 10+random(20),
                        "damage" : level/3+random(level/6),
                     "damage_type" : "����",
                    ]); 
       }
			return ([
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"damage":	120 + random(140),
				"force":	200 + random(350),
				"dodge":	random(30)-10,
				"parry":	random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
		return notify_fail("����������������߽�����\n");
	if ( me->query("neili") < 20)
		return notify_fail("����������������߽�����\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinshe-jianfa/" + action;
}
