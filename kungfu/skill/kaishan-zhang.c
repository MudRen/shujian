//kaishan-zhang.c ��ɽ�Ʒ�
//By xjqx@SJ 2009/1/3

inherit SKILL; 

mapping *action =({
([      "action":"$N���һ�գ�����������б������ʹ��һ�С���ħ��������һ������$n��$l��",
        "lvl"   :0,
        "skill_name" :"��ħ����",
        "damage_type":"����"
]),
([      "action":"$Nһ�����������Ӽ��Σ�ʹ��һ�С�����Ӱ�����ó�������Ӱ������$nȫ��ĸ���ҪѨ��",
        "lvl"   :50,
        "skill_name" :"����Ӱ",
        "damage_type":"����"
]),
([      "action":"$N���һ�����ҿ�һ����˲������$n����ǰ��һ�С�ħ���ɲ����˫����������������$n��",
        "lvl"   :80,
        "skill_name" :"ħ���ɲ",
        "damage_type":"����"
]),
([      "action":"$Nʹһ�С�����·����������ǰ����˫�Ƹ����˸���Բ����������$n��$l��",
        "lvl"   :100,
        "skill_name" :"����·��",
        "damage_type":"����"
]),
([      "action":"$Nʹ��һ�С���ľ�������������������ƣ�ǣ��ȫ����$n�����˻���",
        "lvl"   :120,
        "skill_name" :"��ľ����",
        "damage_type":"����"
]),
([      "action":"$N����һ�ڣ���Ȼ�������ߣ�����˳��һ�С�ħӰ���ء���$n��$l��ȥ��",
        "lvl"   :150,
        "skill_name" :"ħӰ����",
        "damage_type":"����"
]),
([      "action":"$Nʹ��������ʵӦ�������������������ɺ���ϣ��γ�һ����������$n",
        "lvl"   :180,
        "skill_name" :"����ʵӦ",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("����ɽ�Ʒ�������֡�\n");


     if ((int)me->query_skill("strike", 1) < 80)
         return notify_fail("��Ļ����Ʒ���򲻹���\n");

     if ((int)me->query("max_neili") < 300)
         return notify_fail("�������̫�ͣ��޷�ѧ��ɽ�Ʒ���\n");

     if ((int)me->query_skill("strike", 1) < (int)me->query_skill("kaishan-zhang", 1))
         return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ŀ�ɽ�Ʒ���\n");

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
	level   = (int) me->query_skill("kaishan-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
				"damage" : 100 + random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("����ɽ�Ʒ�������֡�\n");

     if ((int)me->query("jingli") < 80)
            return notify_fail("���������������ɽ�Ʒ���\n");

     if ((int)me->query("neili") < 70)
            return notify_fail("���������������ɽ�Ʒ���\n");

     me->receive_damage("jingli", 65);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"kaishan-zhang/" + action;
}

