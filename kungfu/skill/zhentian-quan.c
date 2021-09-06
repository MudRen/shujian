//����ȭ
//cool 981010
inherit SKILL;

mapping *action = ({
([
	"action" : "$N��һ��������΢��������һ����һ�С����°��졹��һȭֱͱ$n��$l",
	"lvl" : 0,
	"skill_name" : "���°���",
	"damage_type" : "����"
]),
([
	"action" : "$N��������һЦ����ȭ�������ϣ���ȭƽƽ������һ�С��������졹���������$n",
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N��$nһ����ȣ�ʹһ�С����羭�졹����ȭ�������漴��ȭ���ϣ�������������$n��$l",
	"lvl" : 30,
	"skill_name" : "���羭��",
	"damage_type" : "����"
]),
([
	"action" : "$N�ƺ�һ����˫ȭ���Ϸֿ���һ�ǡ��ٻ����졹��ȭ�����ߣ�����ͬʱ����$n��$l",
	"lvl" : 45,
	"skill_name" : "�ٻ�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ����һ�����졹��һ�����һȭ��մ����ȭ��ֱ��$n��$l",
	"lvl" : 60,
	"skill_name" : "һ������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ����Х��˫ȭ���������һ�С�ʯ���쾪����ȭ���ܲ�$n��ǰ������",
	"lvl" : 70,
	"skill_name" : "ʯ���쾪",
	"damage_type" : "����"
]),
([
	"action" : "$Nŭ��һ������շ���һʽ��������ѡ���˫ȭ�Ӹ����£����봷��$n",
	"lvl" : 80,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([
	"action" : "$N�����Ц������������۷��裬һ�С��޷����졹��ȭ����������������$n��ȥ",
	"lvl" : 90,
	"skill_name" : "�޷�����",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
 int valid_combine(string combo) { return combo=="chuanyun-tui"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ȭ��������֡�\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 25)
		return notify_fail("��ġ������޼�������򲻹����޷�ѧ������ȭ����\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���������ȭ����\n");
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
	if( me->query_skill("cuff", 1) >= 120 
	 && me->query_skill("zhentian-quan", 1) >= 120 
	 && me->query_skill("leg",1) >= 120
	 && me->query_skill("chuanyun-tui",1) >= 120
	 && me->query("neili") >= 500
	 && me->query_skill_mapped("leg") == "chuanyun-tui"
	 && me->query_skill_mapped("parry") != "zhentian-quan"
	 && !random(6)) {
		return ([
			"action": "$N������ʽͻȻ�ӿ죬һ�С�ȭ��˫������������$n����һȭ���漴˫�������߳�",
			"parry": random(15),
			"dodge": random(20)-5,
			"force": 350,
			"damage_type": "����"
		]);
	}
	level   = (int) me->query_skill("zhentian-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("zhentian-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ( me->query("neili") < 10)
		return notify_fail("�������������������ȭ����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhentian-quan/" + action;
}
