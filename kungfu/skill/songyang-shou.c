// songyang-shou.c  ������
// Created by Numa 2000.1.5
// Modified by Numa 2000.1.25
// Modified by darken@SJ
// Modified by Looklove@SJ 2001.10.22

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ�Ƹߣ�һ�Ƶͣ��ڳ��ˡ������֡�������ʽ--���������ס�",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([
	"action" : "$N����һ�ᣬ����һ�б㼴������������һ�Ƴ��֣���ʱȫ������Ԩͣ���ţ���������",
	"damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "Ԩͣ����"
]),
([
	"action" : "$N���һ��������С���ˣ����漴˫������Ƴ���һ�����ҵ��Ʒ�����$n�������",
	"damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "����ӭ��"
]),
([
	"action" : "$N�����������裬˫�ƽ���һ��$n�����ţ�һ��$n��С��",
	"damage_type" : "����",
	"lvl" : 80,
	"skill_name" : "�ɰز���",
]),
([
	"action" : "$N̤ǰһ������$n��ڶ��У�˫�ֿ���硢Ѹ��磬��ͣ����$n�������ҪѨ",
	"lvl" : 100,
	"damage_type" : "����",
	"skill_name" : "��ڶ���"
]),
([
	"action" : "$N���������������б��Χ��$n�����ϳ��ƣ���Ѹ����$nȫ�����ҪѨ����¶����",
	"damage_type" : "����",
	"lvl" : 120,
	"skill_name" : "��������"
]),
([
	"action" : "$N������ǰ�������͵�һ�ܣ�������������ֻ��֣�˫����ֱ��$n������ѹȥ",
	"damage_type" : "����",
	"lvl" : 140,
	"skill_name" : "��Ԩ��̽"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧϰ�����ֱ�����֡�\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 20)
		return notify_fail("��ĺ���������򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������֡�\n");
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
	level = (int)me->query_skill("songyang-shou", 1);

	if (me->query_temp("yinyang") && random(level/10) > 12 && random(2)){
		switch(random(2)) {
			case(0) :
				return([
					"action": HIW "$Nٿ���۽�������ԶԶ����һ�ƣ���������$n�ؿڣ����ƺ������ˣ�$n��ʱһ������"NOR,
					"force" : 350+ random(150),
					"dodge" : random(35),
					"parry": random(35),
					"damage_type" : "����",
				]);
				break;
			case(1) :
				return([
					"action": HIW "$Nٿ���۽�������ԶԶ����һ�ƣ���������$n�ؿڣ����������ޱȣ�$n����ٸ�����"NOR,
					"force" : 350+random(150),
					"dodge" : random(35),
					"parry": random(35),
					"damage_type" : "����",
				]);
				break;
		}
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
                   if(me->query_temp("ss_lf") && (int)me->query_skill("songyang-shou",1)>=450){
                           return([
                           "action": HIW+action[j]["action"]+NOR,
                           "lvl": action[j]["lvl"],
                           "damage_type": action[j]["damage_type"],
                           "force": 400 +random(400),
                           "dodge": 30+random(30),
                           "parry": 20+ random(30),
                   ]);
               }
                   if(me->query_temp("ss_lf") && (int)me->query_skill("songyang-shou",1)>=350){
                   return ([
                           "action":HIY+ action[j]["action"]+NOR,
                           "lvl": action[j]["lvl"],
                           "damage_type": action[j]["damage_type"],
                           "force": 300 +random(300),
                           "dodge":20+random(30),
                           "parry":10+ random(30),
                   ]);
               }
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
	int focus, lvl, j;
	focus = me->query_temp("ss/focus");
	lvl= me->query_skill("songyang-shou", 1);
	j = (lvl - 100) / 5 + 1;

	if ( victim->query("job_npc")) return 0;

	if (me->query_temp("ss/hb") && !victim->is_busy()) {
		if ( !random(3))
			victim->add("neili",-me->query_skill("force"));
		if (victim->query("neili") < 0) victim->set("neili",0);
		msg = HIW"$n��$N��һ�ƻ��У���Ȼһ���£��ƺ�ȫ���ѪҺ��������һ�㣡\n"NOR;
		victim->add_condition("cold_poison", 3 + random(3));
		message_vision(msg, me, victim);
	}
	if ( j > 6 ) j = 6;

//         if ( me->query_temp("ss_lf") ) return 0;

	if ( random(me->query_con(1))>20
	&& lvl >= 100
	&& random(me->query_str(1))>20
	&& me->query_skill_prepared("hand") == "songyang-shou"
	&& me->query_skill_mapped("force") =="hanbing-zhenqi"
	&& me->query("neili") > 1000
	&& me->query("max_neili") > 1500
	&& me->query("jiali")
	&& random(2) ) {
		me->add("neili", -50);
		msg = HIB"$N���𺮱���������������һ���������ֵİ���������������$n��ȥ��\n"NOR;
		victim->add_condition("cold_poison", 3+ random(3));
		msg +=HIW"$nֻ����$N��һ�Ƽ����溮�ޱȵ���������ðٶˣ����������ע��ȫ��Ѩ��, ���ܶ�����\n"NOR;
		victim->add_busy(2+random(2));
		message_vision(msg, me, victim);
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("songyang-shou", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if (me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("������������������֡�\n");
	me->receive_damage("jingli", 30);
	me->receive_damage("neili", 10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"songyang-shou/" + action;
}
