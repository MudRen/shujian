//tianmo-shou.c ��ħ�ַ�
//By xjqx@SJ 2009/1/1

inherit SKILL; 

mapping *action = ({
([      "action":"$Nһ�С����귭�ơ�������ץ��$n�ĵ������$n�����Է���һ˲�䣬����ȴ��������$n��$l��",
        "lvl"   :0,
        "skill_name" :"���귭��",
        "damage_type":"����"
]),
([      "action":"$N˫��һ������������ƶ�����һ�С�������ӿ������һ�ɾ�������$n��$l��",
        "lvl"   :50,
        "skill_name" :"������ӿ",
        "damage_type":"����"
]),
([      "action":"����$Nһ��ŭ�����ָ߸߾���һʽ����ɽ��ˮ��������$n��$l��",
        "lvl"   :80,
        "skill_name" :"��ɽ��ˮ",
        "damage_type":"����"
]),
([      "action":"$N����΢б���漴���һ�������ֺ��ƺ�צʹ��������ãã��������$n��$l��",
        "lvl"   :130,
        "skill_name" :"����ãã",
        "damage_type":"����"
]),
([      "action":"$Nʹ������û�粨���˫�ֻ����쳣��׼$n��$lץȥ��",
        "lvl"   :160,
        "skill_name" :"��û�粨��",
        "damage_type":"ץ��"
]),
([      "action":"$N������$n$l���������һ�С�����׽Ӱ����������ͬһ��λץȥ��",
        "lvl"   :200,
        "skill_name" :"����׽Ӱ",
        "damage_type":"ץ��"
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }
int valid_combine(string combo) {
	if(this_player()->query_skill("tianmo-jue", 1) >= 120
	&& this_player()->query_skill("xixing-dafa",1) >= 200
	&& this_player()->query_con(1) > 45
	&& this_player()->query_int(1) > 45)
		return combo=="huanmo-longtianwu";
}

int valid_learn(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("����ħ�ַ�������֡�\n");

   if(!me->query_skill("xixing-dafa", 1)||(int)me->query_skill("tianmo-gong",1)<100)
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("��������ڹ�����̫ǳ������ѧ��ħ�ַ���\n");

     if ((int)me->query_skill("hand", 1) < 100)
         return notify_fail("��Ļ����ַ���򲻹���\n");

     if ((int)me->query("max_neili") < 350)
         return notify_fail("�������̫�ͣ��޷�ѧ��ħ�ַ���\n");

     if ((int)me->query_skill("hand", 1) < (int)me->query_skill("tianmo-shou", 1))
         return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷������������ħ�ַ���\n");

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
	level   = (int) me->query_skill("tianmo-shou",1);
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
         return notify_fail("����ħ�ַ�������֡�\n");

     if ((int)me->query("jingli") < 100)
            return notify_fail("���������������ħ�ַ���\n");

     if ((int)me->query("neili") < 90)
            return notify_fail("���������������ħ�ַ���\n");

     me->receive_damage("jingli", 85);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-shou/" + action;
}

