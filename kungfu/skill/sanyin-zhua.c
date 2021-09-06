//  sanyin-zhua �������צ
// by dubei

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action": "$Nһʽ������̲�����������Σ����ֻ�צ�����μ��£�ͻȻ��$n�ı����Ѩץȥ",
	"lvl" : 0,
	"damage_type": "ץ��"
]),
([
	"action": "$N����һ�Σ�ʮָ���裬Ю��һ�ɴ�ָ��ð����������$n��$l������ȥ",
	"lvl" : 10,
	"weapon" : "ָ��",
	"damage_type": "����"
]),
([
	"action": "$Nһʽ���������������צָ�����ֱ�һ�ӣ����־Ϳ���$n���ʺ�Ҫ��",
	"lvl" : 20,
	"damage_type": "ץ��"
]),
([
	"action": "$N��Ʈ�����Ի�$n����������бб̽�������ݵ�ץ��$n��$l",
        "weapon" : "��צ",
	"lvl" : 40,
	"damage_type": "ץ��"
]),
([
	"action": "$Nһʽ������β����ʮָ����������ɭɭ���⣬����ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"lvl" : 60,
	"damage_type": "����"
]),
([
	"action": "$N������Ц������ɳ���ʮָ�������֣��������ޣ�������ץ��$n��$l",
	"lvl" : 80,
	"damage_type": "ץ��"
]),
([
	"action": "$N��Цһ���������з緢��һ�㣬˫�������趯����������צӰֱϮ$n��$l",
        "weapon" : "��צ",
	"lvl" : 100,
	"damage_type": "ץ��"
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level = (int)me->query_skill("sanyin-zhua",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":150+random(300),
				"dodge":random(30),
				"parry":random(30),
			]);
		}
	}
}

int valid_learn(object me)
{
	if( me->query_temp("weapon"))
		return notify_fail("�������б����������ϰ�������צ��\n");
	if ( me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("��Ļ����󷨵ȼ�������\n");
	if ( me->query("max_neili") < 100 )
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	int lvl = me->query_skill("sanyin-zhua", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������޷����������צ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int poison, i;

	poison = (me->query_skill("poison", 1) - victim->query_skill("poison", 1))/5;
	poison += me->query_skill("sanyin-zhua",1)/10;

	if ( userp(victim)) {
		poison /= 3;
		i = 160;
	}
	else
		i = 80;

	if(random(me->query_skill("huagong-dafa", 1)) > i
	&& me->query_skill("sanyin-zhua", 1) > 100
	&& me->query_skill("poison", 1) > 50
	&& me->query("env/������") != "����"
	&& random(me->query_skill("poison", 1)) > random(victim->query_skill("medicine", 1))
	&& victim->query_condition("xx_poison") < 200
	&& me->query("neili") > 200
	&& !victim->query("job_npc")) {
		if (me->query("env/������") == "ɢ��") {
			poison += random(poison/2);
			me->add("neili",-100-random(50));
			me->add("jingli",-20-random(30));
			message_vision(BLU"$N����һ�ߣ���צ��������ʢ��\n"NOR, me);
		}
		victim->add_condition("xx_poison", poison);
		message_vision(BLU"$Nһ��צ������һ�Σ������Ѿ����˶���\n"NOR, victim);
		if (victim->query_condition("xx_poison") > 180)
			message_vision(HBRED"$N���ڻ����������������Σ�գ�\n"NOR, victim);
		if (userp(me)
		 && userp(victim)
		 && !victim->query_temp("kill_other/"+me->query("id"))
		 && !me->query_temp("other_kill/"+victim->query("id"))
		 && !me->query_temp("revenge/"+victim->query("id"))
		 && !victim->query_condition("killer")
               && (!me->query_temp("special_die") || !victim->query_temp("special_die")))
			me->add_condition("killer", 5);
	}
}

string perform_action_file(string action)
{
	return __DIR__"sanyin-zhua/" + action;
}
