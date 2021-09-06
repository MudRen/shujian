// ���｣��
// thd ����΢�� by Lane@SJ 2005.2.1

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ�����е�$w����ֱ��ǰ�ݳ��������Ҳ�������һ�С���������������ȡ�з棬ֱϮ$n��$l",
	"skill_name" : "��������",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰ����һ��������$w�������һ����һʽ��ɽ����������ָ$n���ʺ�",
	"skill_name" : "ɽ������",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��������񡹣�����$wƾ������˼��£������Ϻ����㣬ɲʱ��Ϯ$n��ȫ��Ҫ��",
	"skill_name" : "��������",
	"lvl" : 40,
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ�������¥̨����$wбָ���ϣ�����ֱ��ȴ��������������ش���$n��$l",
	"skill_name" : "���¥̨",
	"lvl" : 60,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�б�����������������࣬���в���������û���ˮ�������$nֻһ���䣬�Ѿ�����������",
	"skill_name" : "б������",
	"lvl" : 80,
	"damage_type" : "����"
]),
([
	"action" : "$N����$w��Σ�ٿȻ�����˼��£����϶��·�Ϯ$n�����漰���࣬����һ�С��������̡�",
	"skill_name" : "��������",
	"lvl" : 100,
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�㣬���κ󳷣���Ȼ��������ǰ����������翾��죬һ�С����������$w��ƮƮ��ֱ��$n",
	"skill_name" : "��������",
	"lvl" : 120,
	"damage_type" : "����"
]),
([
	"action" : "$NԾ�����࣬����$w���˸����ߣ�бб���£������ѵأ�һ�С������졹������$n��$l",
	"skill_name" : "������",
	"lvl" : 140,
	"damage_type" : "����"
]),
([
	"action" : "$N�ὣ�ʹ���ʹ����������������$w����������������죬��Ȼ��������㻮��$n���Ҷ�",
	"skill_name" : "��������",
	"lvl" : 160,
	"damage_type" : "����"
]),
([
	"action" : "$N����š��������˫ָ���˸�ָ�������ֻ�$w����ö��ϣ�һʽ����ʷ��������������ƥ��������$n��$l",
	"skill_name" : "��ʷ����",
	"lvl" : 180,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!(weapon = me->query_temp("weapon")))
		return notify_fail("����ʱ�޷������｣����\n");
	if ((string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ��޷������｣����\n");
	if ( me->query("max_neili") < 60)
		return notify_fail("�������������\n");
	if ( me->query_skill("bihai-chaosheng", 1) < 12)
		return notify_fail("��ı̺����������̫ǳ��\n");
	if (me->query_skill_mapped("force") != "bihai-chaosheng")
		return notify_fail("��ϰ���｣�������б̺���������ϡ�\n");
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

	level = (int) me->query_skill("yuxiao-jian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
                                "dodge" : 20+random(25),
                                "parry": 25 + random(15),
				"damage" : 100 + random(120),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("yuxiao-jian", 1);
	int i = sizeof(action);
	mapping learned = me->query_learned();

	if (!mapp(learned)) learned = ([]);
	if (!learned["yuxiao-jian"])
		while (i--) 
			if (lvl == action[i]["lvl"])
				return notify_fail("�㽫�Ѿ�ѧ���������ʽ��ϰ��һ�飬���������ȥ��ʦ��ѧ�µ���ʽ���޷���ý����ˡ�\n");;

	if ( me->query("jingli") < 50)
		return notify_fail("����������������｣����\n");
	if( me->query("neili") < 20)
		return notify_fail("����������������｣����\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yuxiao-jian/" + action;
}

void yuxiao(object me, object victim)
{
	string msg;

	if (!me || !victim || !me->is_fighting(victim))
		return;

	if ( !me->query_temp("weapon")) return;

	switch(random(3)){
		case 0 :
			msg = HIW"\n$Nʩչ�����Ž�·�����������ճ��棡$n�������ˣ�ȫ���мܣ��������У�"NOR;
			message_vision(msg, me, victim);
			me->set_temp("yuxiao_auto", 1);
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
			me->delete_temp("yuxiao_auto");
			victim->add_busy(random(2));
			break;
		case 1 :
			msg = HIW"\n$N���²������Ų�����һ���Ӵ̳��ü�����$n�����ֲ������һ�����飬��һ����ʵ��ֻ��ͣ�¹��ƣ������Ż���"NOR;
			message_vision(msg, me, victim);
			me->set_temp("yuxiao_auto", 1);
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
			me->delete_temp("yuxiao_auto");
			victim->add_busy(random(2));
			break;
		case 2 :
			msg = HIW"\n$N��۵糸������$n���ܣ�������������ֱ�����㲻��صķ���һ�㣡$n����$Nת��תȥ��Ū���ۻ����ң�ҡҡ��׹��"NOR;
			message_vision(msg, me, victim);
			me->set_temp("yuxiao_auto", 1);
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
			me->delete_temp("yuxiao_auto");
			victim->add_busy(random(2));
			break;
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int j, k;

	j = me->query_skill("yuxiao-jian", 1);
	k = me->query_skill("qimen-bagua",1);

	if( random(10) >= 5 
	&& random(j) > 120
	&& k > 150
	&& me->query_skill_mapped("parry") == "yuxiao-jian"
	&& me->query_temp("weapon")
	&& j/3 > random(victim->query_skill("dodge"))
	&& !me->query_temp("yuxiao_auto")
	&& !me->query_temp("yxj_qimen")
	&& !me->query_temp("thd/feiying")){
		call_out((: yuxiao :), 1, me, victim);
	}
}
