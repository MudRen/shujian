// sixiang-zhang.c -������

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$N��$nңңһ�ϣ�һʽ��������̩����˫�ƴ󿪴��أ�����$n�Ľ�����",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "������̩"
]),
([
	"action" : "������$N�溬΢Ц��һʽ���������项��˫���Ʋ����ƣ�ͬʱ����$nȫ�������",
	"damage_type" : "����",
	"lvl" : 10,
	"skill_name" : "��������"
]),
([
	"action" : "$N�������һʽ��������ɳ����˫����£���У�����$n����磡",
        "damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "������ɳ"
]),
([
	"action" : "$Nһʽ���׶���������˫����Ѹ�ײ����ڶ�֮�ƣ�����$n������̫��Ѩ��",
        "damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "�׶�����"
]),
([
	"action" : "$Nʹһʽ��ժ�ǻ�����������������˫�����֣�һ������$n�ĺ��ȥ",
        "damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "ժ�ǻ���"
]),
([
	"action" : "$Nһʽ�����Ľ�ħ����˫�����÷��ã��ƶ��Ƕ��������缱����ʹ$n�������У�",
	"damage_type" : "����",
	"lvl" : 50,
	"skill_name" : "���Ľ�ħ"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ( me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧϰ�����ơ�\n");
	if ( me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
	int i, level, j;

	if ( me->query_skill("sixiang-zhang", 1) > 80
	 && me->query_skill("linji-zhuang", 1) > 80
	 && me->query_skill("strike", 1) > 80
	 && me->query("neili") > 500
	 && random(me->query_int(1)) > 25
	 && !random(3)
	 && environment(me)->query("outdoors")) {
		me->add("neili", -60);
		return ([
	                "action":HIY"��ʱ��,�����羲���ƺ�ƽ�̣������Լ��������$N����б���������γɲ�ɫ�⻷��\n"+
				"$N�����Լ�����Ӱ�����س�������ɫ�����ϡ�\n"+
				"$N����"+HIC+"���⻷���˶�����Ӱ�ڻ��С�"HIY"��ʹ����"+HIW"�����ƾ�ѧ"HIY"���𶥷�⡻"NOR,
			"weapon" : HIY"�𶥷��"NOR,
			"force": 500,
			"dodge": 15,
			"parry": 15,
			"damage_type": "����"
		]);
	}

        level   = (int) me->query_skill("sixiang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":150+random(300),
				"dodge":random(30),
				"parry":random(30),
			]);
		}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("sixiang-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if (me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if (me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
