// hanbing-mianzhang.c ��������

inherit SKILL;

mapping *action = ({
([
	"action" : "$N˫�Ƽ��ף�һʽ�����ֺ�˪�����ֱ�ͻȻ����һ����£�����$n��ȫ��",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "�纮��ͷ"
]),
([
	"action" : "$N˫�Ⱥϲ���������������һʽ���纮��ͷ��������ֱ�£�����$n��ͷ��",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "�纮��ͷ"
]),
([
	"action" : "$N���ƻ��أ�һʽ����¶Ϊ˪��������ֱ�߻���������$n����ǰ��Ѩ",
	"damage_type" : "����",
	"lvl" : 10,
	"skill_name" : "��¶Ϊ˪"
]),
([
	"action" : "$Nʹһʽ����÷�׷ɡ���˫�����಻�����ĳ����ƶ��ѩ�к�÷����$n",
	"damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "��÷�׷�"
]),
([
	"action" : "$N����һ��������ȭ�����󷢣�һʽ���캮�ض�����һ�ɺ�����������$n��$l",
	"damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "�캮�ض�"
]),
([
	"action" : "$Nʹһʽ������ѩ�ء���˫��ͻ�ı��ѩ�ף�һǰһ���͵�����$n��$l",
	"damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "����ѩ��"
]),
([
	"action" : "$N˫Ŀ΢�ţ�һʽ��ѩ���׷ɡ���˫�ƻ���ƬƬѩ��������$n��$l",
	"damage_type" : "����",
	"lvl" : 50,
	"skill_name" : "ѩ���׷�"
]),
([
	"action" : "$N���ϸ߸�Ծ��һʽ��������꡹���Ӹ����£������Ʊ���������$n��ȫ��",
	"damage_type" : "����",
	"lvl" : 70,
	"skill_name" : "�������"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if(!me->query_skill("jiuyang-shengong", 1))
	if ((int)me->query_skill("shenghuo-shengong", 1) < 20)
		return notify_fail("���ʥ���񹦻�򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����������ơ�\n");
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
	level = (int)me->query_skill("hanbing-mianzhang", 1);
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
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("hanbing-mianzhang", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query("neili")) > victim->query("neili")/3 
	 && random(me->query_skill("hanbing-mianzhang", 1)) >= 80
	 && !victim->query("job_npc")
	 && random(2) )
		victim->add_condition("hb_poison", random(6)+ 2);
}

string perform_action_file(string action)
{
	return __DIR__"hanbing-mianzhang/" + action;
}
