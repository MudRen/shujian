//tianmo-gun.c ������ħ��
//By xjqx@SJ 2009/1/1

inherit SKILL; 

mapping *action = ({
([      "action":"$N�������ˣ�����$wӭ��һ����һ�С��ºڷ�ߡ�������$n��ͷ�������ҽ�������",
        "lvl"   :0,
        "skill_name" :"�ºڷ��",
        "damage_type":"����"
]),
([      "action":"$N�����ɫ������$w��һ�С���糤�š������������$n��$l����ɨȥ��",
        "lvl"   :20,
        "skill_name" :"��糤��",
        "damage_type":"����"
]),
([      "action":"$N����һת������$w����һ�ϣ������⽫��δ��֮�ʣ�һ�С����·ת������$n��ͷ���¡�",
        "lvl"   :50,
        "skill_name" :"���·ת",
        "damage_type":"����"
]),
([      "action":"$N����һת��һ�С��������⡹$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l��",
        "lvl"   :80,
        "skill_name" :"��������",
        "damage_type":"����"
]),
([      "action":"$N����ʱ���������죬$w�䴦������ϼǧ�ƣ�һʽ���������桹������������ȫȻ����$n���С�",
        "lvl"   :120,
        "skill_name" :"��������",
        "damage_type":"����"
]),
([      "action":"$n��Ȼ����$N����һ̧ͷֻ��$Nһʽ�����R�L��������������һ�㾶ֱɨ��$n$l��",
        "lvl"   :150,
        "skill_name" :"���R�L��",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }

int valid_learn(object me)
{
   if(!me->query_skill("xixing-dafa", 1)||(int)me->query_skill("tianmo-gong",1)<100)
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("��������ڹ�����̫ǳ������ѧ��ħ����\n");

     if ((int)me->query_skill("club", 1) < 100)
         return notify_fail("��Ļ���������򲻹���\n");

     if ((int)me->query("max_neili") < 350)
         return notify_fail("�������̫�ͣ��޷�ѧ������ħ����\n");

     if ((int)me->query_skill("club", 1) < (int)me->query_skill("tianmo-gun", 1))
         return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������������ħ����\n");

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

	level = (int) me->query_skill("tianmo-gun",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(120),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"damage" : 100 + random(120),
			]);
		}
	}
				if ( me->query_temp("tmg/luanwu")){
				return ([
					"action" : action[j]["action"],
					"damage": 150+random(180),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
							if ( me->query_temp("tmg/tian")){
				return ([
					"action" : action[j]["action"],
					"damage": 150+random(180),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(500),
				]);
			}
}

int practice_skill(object me)
{
     object weapon;

     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "club")
            return notify_fail("��ʹ�õ��������ԡ�\n");

     if ((int)me->query("jingli") < 70)
            return notify_fail("�������������������ħ����\n");

     if ((int)me->query("neili") < 80)
            return notify_fail("�������������������ħ����\n");

     me->receive_damage("jingli", 65);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-gun/" + action;
}

