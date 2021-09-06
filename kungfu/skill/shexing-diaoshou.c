// shexing-diaoshou ���ε���
//  by action@SJ 2008/12/30
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+RED+"���߳���"+NOR+"����������Σ���������ͻȻ����$n�ı����Ѩ",
    "lvl" : 0,
    "skill_name" : RED "���߳���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����һ�Σ�һʽ��"+YEL+"��ͷ��β"+NOR+"������������$n�ļ�ͷ����ȭ����$n���ؿ�",
    "lvl" : 24,
    "skill_name" : YEL "��ͷ��β" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+HIG+"��������"+NOR+"�������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
    "lvl" : 46,
    "skill_name" : HIG "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�������У�����ֱ����һʽ��"+HIY+"������Ӱ"+NOR+"������Ʈ��������$n������",
    "lvl" : 68,
    "skill_name" : HIY "������Ӱ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+HIB+"�������"+NOR+"������ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
    "skill_name" : BLK "�������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+GRN+"��������"+NOR+"����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
    "lvl" : 100,
    "skill_name" : GRN "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫�ֱ�ȭ��һʽ��"+YEL+"������ӿ"+NOR+"������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
    "force" : 380,
    "lvl" : 120,
    "skill_name" : YEL "������ӿ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+WHT+"��������"+NOR+"����ȭ���������֣��������ޣ�����������$n�ĵ���",
    "lvl" : 140,
    "skill_name" : WHT "��������" NOR,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ε��ֱ�����֡�\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫���ˣ����������ε��֡�\n");
	if ( me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦���̫ǳ������ѧ���ε��֡�\n");
	if ( me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ������ѧ���ε��֡�\n");
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
	level   = (int) me->query_skill("shexing-diaoshou",1);
if(me->query_temp("sxds/ds"))
		return ([
				"action": action[j]["action"],
				"damage_type": "����",
				"force": 600 +random(350),
				"dodge": random(30)-10,
				"parry": random(20)-10,
				"damage": 120 + random(140),
				"attack":150+random(150),
			]);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"parry":random(10),
			]);
		}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("shexing-diaoshou", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("����������������������ε��֡�\n");
	if ( me->query("neili") < 10)
		return notify_fail("����������������������ε��֡�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shexing-diaoshou/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("hand"),attack;
        attack=lvl/100;
        if(attack>4) attack=4;
				attack=random(attack);
				if(attack<=1) attack=1;
        
        if (random(7)>4|| random(me->query_str()/2)> victim->query_str()/2) {
                message_vision(WHT "$N�����������������ƣ���$n���󲿿�ȥ��$n˲�䱻$N��ס�������ܶ�����\n" NOR,me,victim);
                victim->start_busy(random(1));
        }
        else if (random(5)>3|| random(me->query_dex()/2)> victim->query_dex()/2) {
        	message_vision(MAG "$N������ϣ����������������һ�ܣ�$n��$N���������Ի󣬶�ʱ������������Ϊ���ء�\n" NOR, me,victim);
        	victim->start_busy(random(2));
        }
        else if (random(4)>2|| random(me->query_con()/2)> victim->query_con()/2) {
        	message_vision(HIY "�����ţ�$N���з�����˻˻����������˫�ְ�������ָ��������״���������ң���������缱�籩��㹥����"+
			   chinese_number(attack+1)+"�С�\n" NOR, victim);
        	victim->start_busy(random(2));
        }
}