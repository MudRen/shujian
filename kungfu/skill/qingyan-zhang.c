// qingyan-zhang.c ����������
//cool@SJ,9905027

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action": "$N���Ʈ������ת��������һ�С��������ơ������������б����쬵�һ����������$n��$l",
	"skill_name" : "��������",
	"lvl": 0,
	"damage_type": "����"
]),
([
	"action": "$N����һʽ���������������������б��������һ��΢�縧��$n��$l������˿������",
	"skill_name" : "��������",
	"lvl": 20,
	"damage_type": "����"
]),
([
	"action": "$N΢΢һЦ�����ư���$n��$l�������ơ�����ˮ������֮�����������С��������ʡ�",
	"skill_name" : "��������",
	"lvl": 40,
	"damage_type": "����"
]),
([
	"action": "$Ņ��ͷ����Ŀ��ת˲����$n���ӣ�������ƮƮһת����Ʈ��ɢ���������������ĳ�",
	"skill_name" : "��Ʈ��ɢ",
	"lvl": 60,
	"damage_type": "����"
]),
([
	"action": "$N�������Ʈ����һʽ���������̡����������������ƣ���˿����ƹ�$N��������Ȼ��$n��$lϮȥ",
	"skill_name" : "��������",
	"lvl": 80,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }


string query_skill_name(int level)
{
        int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, b,level;
	string msg;
	level = (int) me->query_skill("qingyan-zhang",1);

	b = level/30;
	if ( b > 5 ) b=5;

	if(me->query_temp("fenglei")){
		switch(me->query_temp("fenglei")){
			case 4: msg = HIW"$N������ǰб����һ���������Ʒ绮����������������һ����$n����ǰɢ��"+chinese_number(b)+"����������Ϯ����Ҫ��" NOR;break;
			case 3: msg = HIW"$N����»����ؽ����ʣ���������һ������������һ�����������������������ֱ��$n��ǰҪ��" NOR;break;
			case 2: msg = HIW"$N���ڿ��У��Ʒ�ʹ��������ˮ�����ȣ���һ����һ�ư���������"+chinese_number(b)+"��������ɢ������$n��ȫ��" NOR; break;
			case 1: msg = HIW"$N����һ�ڣ���ʽ���ᣬ���������Ҷ������"+chinese_number(b)+"�£�����������֯��һ�����ε���������������$n"NOR;break;
			default: msg = HIW"$N����һ�ڣ���ʽ���ᣬ���������Ҷ������"+chinese_number(b)+"�£�����������֯��һ�����ε���������������$n" NOR; break;
		}
		me->add_temp("fenglei", -1);
		return ([
			"action":msg,
			"damage_type":"����",
			"dodge": random(20)- 5,
			"force": me->query("class") == "bonze"?180 +random(250):200 + random(300),
			"parry": random(15),
			"damage": me->query("class") == "bonze"?20 + random(20):40 +random(40),
			"skill_name" : "��������",
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			return ([
				"action":action[NewRandom(i, 20, level/5)]["action"],
				"damage_type": action[NewRandom(i, 20, level/5)]["damage_type"],
				"dodge": random(20)-10,
				"force": 100+random(250),
				"parry": random(10),
				"skill_name" : action[NewRandom(i, 20, level/5)]["skill_name"],
			]);
		}
	}
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ֲ�����ϰ���������ơ�\n");

	if (!me->query_skill("kurong-changong", 1))
	if ((int)me->query_skill("qiantian-yiyang", 1) < 10 )
		return notify_fail("���Ǭ��һ��������������\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("����������̫��, �����������������ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	int lvl = me->query_skill("qingyan-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 10)
		return notify_fail("������������������������ơ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qingyan-zhang/" + action;
}
