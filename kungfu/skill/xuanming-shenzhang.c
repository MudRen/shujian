inherit SKILL;

mapping *action = ({
([
	"action" : "$N����һ������˫�ƻ���������$n��$l",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N�����ĳ������ƺ�������ֱ����$n��$l",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : "$Nһת�����ַ��ƻ�������$n�����мܣ����Ʒɿ������$n��$l",
	"lvl" : 60,
	"damage_type" : "����"
]),
([
	"action" : "$N˫�������һ��һ�ƴ�������֮�����ϵ���$n��ȥ",
	"lvl" : 120,
	"damage_type" : "����"
]),
([
	"action" : "$N��Ϣ��ת��������һƬ������һ������$n��$l",
	"lvl" : 180,
	"damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	object me = this_player();
	if ( !userp(me) || me->query("menggu") || me->query("xmsz")){
		return usage=="strike" || usage=="parry";
	}
}

int valid_learn(object me)
{
	if (!me->query("menggu") && !me->query("xmsz"))
		return notify_fail("�����ڲ�����ϰ��ڤ���ơ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ڤ���Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 3000)
		return notify_fail("�������̫�����޷�������\n");
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
	level   = (int) me->query_skill("xuanming-shenzhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	300 + random(350),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	if (!me->query("menggu") && !me->query("xmsz"))
		return notify_fail("�����ڲ�����ϰ��ڤ���ơ�\n");
	if ((int)me->query("jingli") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("���������������ڤ���ơ�\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lvl;
	lvl = me->query_skill("xuanming-shenzhang")/5;
	if (!userp(me)) lvl /= 4;

	if ( victim->query("job_npc")) return 0;

	if (me->query("env/��ڤ����") == 1
	&& random(me->query("neili") + victim->query("neili")) > victim->query("neili")) {
		victim->add_condition("xuanmin_poison", lvl);
		if ( userp(me) && userp(victim)
		 && victim->query("combat_exp") < me->query("combat_exp") / 2
		 && !victim->query_temp("kill_other/"+me->query("id"))
		 && !me->query_temp("other_kill/"+victim->query("id"))
		 && ! me->query_temp("revenge/"+victim->query("id"))
		 && !victim->query_condition("killer") )
			me->add_condition("killer", 5);
	}
	if (me->query("env/��ڤ����") == 1
	&& random(me->query("neili") + victim->query("neili")) > me->query("neili")
	&& userp(victim)
	&& userp(me))
		me->add_condition("xuanmin_poison", lvl);
}

string perform_action_file(string action)
{
	return __DIR__"xuanming-shenzhang/" + action;
}
