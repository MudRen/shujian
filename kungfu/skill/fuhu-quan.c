// /lungfu/skill/fuhu-quan
// by dubei
// �޺�����ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "$N����˫ȭ��ʹ��һ�С��ඥ������ͷ����$n��$l  ",
        "skill_name" : "�ඥ",
        "force" : 80,
        "dodge" : 5,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ࡹ������һ�ͣ����ֻ���������һȭ����$n���ɲ�  ",
        "skill_name" : "���",
        "force" : 60,
        "dodge" : -5,
        "lvl" : 10,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С��ü������ȭ���$n��ǰ�أ�һ������ȭ��ɨ$n��̫��Ѩ  ",
        "skill_name" : "�ü",
        "force" : 80,
        "dodge" : 10,
        "lvl" : 20,
        "damage_type" : "����",
]),
([      "action" : "$N���ι��죬ʹһ�С�������˫ȭ���»���$n��$l  ",
        "skill_name" : "���",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����š���˫ȭ������������������ֱָ$n��$l  ",
        "skill_name" : "����",
        "force" : 120,
        "dodge" : -5,
        "lvl" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N΢΢һЦ��ʹ��һʽ����������˫ȭǰ�������ֱȡ$n������  ",
        "skill_name" : "����",
        "force" : 150,
        "dodge" : 10,
        "lvl" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ġ���ȫ��ת��˫ȭ��ɨ$n��$l  ",
        "skill_name" : "����",
        "force" : 270,
        "dodge" : 20,
        "lvl" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ��ʹ��һ�С���ʤ����һȭ�ͻ�$n�ʺ�  ",
        "skill_name" : "��ʤ",
        "force" : 260,
        "dodge" : 5,
        "lvl" : 100,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���޺�����ȭ������֡�\n");
	else if ((int)me->query("max_neili") < 50)
		return notify_fail("��������������޺�����ȭ��\n");
	if ((int)me->query_skill("longxiang-gong", 1) <= 20 )
                      return notify_fail("��Ҫ��һ�����������������򣬲������޺�����ȭ��\n");
 
          return 1;
}
 int valid_combine(string combo)
 {
         object me;
         me = this_player();
 
         if ((int)me->query_str() > 32)
                 return combo=="dashou-yin";
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
        int i, level;
	level   = (int) me->query_skill("fuhu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
            if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���޺�����ȭ������֡�\n");
         if ((int)me->query("jingli") < 30)
                 return notify_fail("�������̫���ˡ�\n");
         if ((int)me->query("neili") < 20)
                 return notify_fail("��������������޺�����ȭ��\n");
         me->receive_damage("jingli", 25);
         me->add("neili", -5);
         return 1;
}

