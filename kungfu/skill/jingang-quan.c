// jingang-quan.c -����ȭ
 
inherit SKILL;
 
mapping *action = ({
([
	"action" :"$N��Ȼ΢Ц��һʽ������������˫�ֺ�ʮ��ǰ΢΢һ�ݣ�һ�ɰ������ƶ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" :"$N��ɫ������һʽ�����𴫷���������$n��������ֵ�������ǰһ�������ֳ�ȭֱ��$n�ĺ��ԡ�",
	"lvl" : 10,
	"skill_name" : "���𴫷�",
	"damage_type" : "����"
]),
([
	"action" :"$Nһ����Ц��һʽ����ڤ�ѻ꡹˫ȭ���ٽ������ʮ��ȭ��ȭ�����������������죬��$n��ס���ˣ�ƣ���м�",
	"lvl" : 30,
	"skill_name" : "��ڤ�ѻ�",
	"damage_type" : "����"
]),
([
	"action" :"$N���װ������У�һʽ��������������˫ȭһǰһ��Ю��һ����������$n",
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" :"$Nһʽ����ɢ��ħ������ü��Ŀ֮�䣬ͻȻ˫ȭֱ��ֱ�£������·��������ħһ�㹥��$n����ǰ���",
	"lvl" : 80,
	"skill_name" : "��ɢ��ħ",
	"damage_type" : "����"
]),
([
	"action" :"$Nһʽ�����෨�ࡹ����ȭ��Σ�����һ�䣬�ѻ�����ʮ����Ӱ���������$n��ȫ�����",
	"lvl" : 100,
	"skill_name" : "���෨��",
	"damage_type" : "����"
]),
([
	"action" :"$N����Ծ�𣬰���г��־޴���Ӱ��ͻȻһʽ���������ơ���ͷ�½��ϣ���ת�Ÿ���������˫ȭ����$n��̫��Ѩ",
	"lvl" : 120,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" :"$Nׯ����������������һ������ȫ���·�΢΢���𣬵ͺ�һ����һʽ�����ȼ��֡����������ȶ���������$n��ǰ��",
	"lvl" : 140,
	"skill_name" : "���ȼ���",
	"damage_type" : "����"
])
});
 
int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }
 
int valid_combine(string combo)
{
	object me;
	me = this_player();
 
	if ((int)me->query_int(1) > 40)
		return combo=="banruo-zhang";
}
 
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");

	if ((int)me->query_skill("yijin-jing", 1) < 60)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ����ȭ��\n");

	if ((int)me->query_int(1) > 30) {
		return 1;
	}
	else {
		if ( me->query_skill("banruo-zhang", 1)
		 && me->query_skill("yizhi-chan", 1)
		 && me->query_skill("longzhua-gong", 1)
		 && me->query_skill("nianhua-zhi", 1)
		 && me->query_skill("qianye-shou", 1)
		 && me->query_skill("ruying-suixingtui", 1)
		 && me->query_skill("sanhua-zhang", 1))
			return notify_fail("��Ĺ����������޷�ͬʱѧϰ�������ϵ��ϳ˹���\n");
	}
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
	level   = (int) me->query_skill("jingang-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}
 
int practice_skill(object me)
{
	int lvl = me->query_skill("jingang-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jingang-quan/" + action;
}
