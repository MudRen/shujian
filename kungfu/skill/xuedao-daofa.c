// /kungfu/skill/xue-dao.c
// by dubei
// xue-dao.c Ѫ��

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С�ĥ��˱Ѫ������$w���������$n�߽��ˣ�ͻȻ������ץס������˳��һ�ӣ�����$p$l",
        "skill_name" : "ĥ��˱Ѫ",
        "force" : 100,
        "dodge" : -5,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N�ٺ�һЦ��һʽ����ֽ��������һ��������ȥ��$nֻ����ǰ���������$l��΢΢һ��",
        "skill_name" : "��ֽ����",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 20,
        "damage" : 75,
        "damage_type" : "����",
]),
([      "action" : "$N��$w�ڿڣ�������$n���Դ�����ȥ����������ִӿ��г����������Ѫ��ãã��һ��֮�£�����ֱ��$p$l",
        "skill_name" : "Ѫ��ãã",
        "force" : 180,
        "dodge" : 10,
        "lvl" : 30,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$N�ٺ���Ц���У�һ�С�Ѫϴ��ӡ���ͻ����$w��Ӱ������ӭͷ��ת������һ�����һ��������������ͷ����$n$l",
        "skill_name" : "Ѫϴ���",
        "force" : 220,
        "dodge" : 5,
        "lvl" : 50,
        "damage" : 90,
        "damage_type" : "����",
]),
([      "action" : "$N������ǰһ̽��һ�С�Ѫ����硹��$w���������б���һ��������һ�㣬Ѹ�����׵���$n�������ж������漴�յ����ʣ�������Ц",
        "skill_name" : "Ѫ�����",
        "force" : 250,
        "dodge" : -5,
        "lvl" : 70,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ������Ȼ������������$w�������ã�һʽ��Ѫ�����ۡ�������ƬƬ����ն��$n��$l",
        "skill_name" : "Ѫ������",
        "force" : 280,
        "dodge" : 10,
        "lvl" : 90,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$N��͸���⣬����̹Ǻ��磬һ�С�Ѫ��̹ǡ���ǰֱ�����£�һ����������������$n��$l",
        "skill_name" : "Ѫ��̹�",
        "force" : 300,
        "dodge" : 5,
        "lvl" : 100,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$Nһʽ��Ѫ���������һ��$wԽʹԽ�죬һ���ź�Ӱ������ȫ����$n��������������ֻ�����أ���������������",
        "skill_name" : "Ѫ�����",
        "force" : 320,
        "dodge" : 10,
        "lvl" : 120,
        "damage" : 120,
        "damage_type" : "����",
]),
});

string *parry_msg = ({
"$n����һ�̣�$w��һ�����ߣ�ֱ��$N������.",
"$n������һ�������е�$w˳�ƻ��£�����$N�յ���ָ��\n",
"$n����һ�䣬�����е�$w����һ��,��$N�Ĺ�����ƫ��ȥ.",
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������������ϰѪ����\n");
	if ((int)me->query_skill("longxiang-gong", 1) < 100)
		return notify_fail("��Ҫ�е��������������������,��������Ѫ��������\n");
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
        int i, level;
	level   = (int) me->query_skill("xuedao-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	
	if ((int)me->query("jingli") < 60)
		return notify_fail("��ľ���������Ѫ��������\n");
	me->receive_damage("jingli", 50);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xuedao-daofa/" + action;
}
