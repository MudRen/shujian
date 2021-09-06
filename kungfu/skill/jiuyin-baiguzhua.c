// jiuyin-baiguzhua.c �����׹�צ

#include <ansi.h>
inherit SKILL;
mapping *action = ({
([
	"action" : BLU"$N�����転������аħ��˫צ���ץ�������������󷭴������ּ��죬�����ָץ��$n$l"NOR,
	"lvl" : 0,
   	"damage_type" : "ץ��"
]),
([
	"action" : BLU"ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n$l������ȥ"NOR,
	"weapon" : "��ָ",
	"lvl" : 10,
	"damage_type" : "����"
]),
([
	"action" : BLU"$N�ֱ۹ؽڿ���һ�죬�ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���"NOR,
	"weapon" : "��ָ",
   	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : BLU"$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�æ��ͻȻ�����צ����ָ�͵ز���"NOR,
	"weapon" : "��צ",
	"lvl" : 30,
   	"damage_type" : "����"
]),
([
	"action" : BLU"$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l"NOR,
	"weapon" : "�����ָ",
	"lvl" : 40,
	"damage_type" : "����"
]),
([
	"action" : BLU "$N��צ��Σ���צ������һ��" HIR "��������ǡ�" BLU "ֱ����$n��$l" NOR,
	"lvl"   : 100,
	"skill_name" : "�������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : BLU "$N˫��������צ��צצ����$n��" HIR "������������" BLU "����$n��$lץ��" NOR,
	"lvl"   : 120,
	"skill_name" : "��������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : BLU "$N����Χ$nһת��ʹ��" HIR "�����޵�����" BLU "��$n��$l����ȫ������צӰ��" NOR,
	"lvl"   : 140,
	"skill_name" : "���޵���" ,
	"damage_type" : "ץ��"
]),
([
	"action" : BLU "$Nʹһ��" HIR "�������ơ�" BLU "��˫צ�ó�����צӰץ��$nȫ��" NOR,
	"lvl"   : 160,
	"skill_name" : "������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : BLU "$N����������һ��" HIR "��Ψ�Ҷ���" BLU "˫צ������$n�������" NOR,
	"lvl"   : 180,
	"skill_name" : "Ψ�Ҷ���" ,
	"damage_type" : "ץ��"
]),
});

int valid_enable(string usage)
{
	return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
	if( !me->query("quest/jiuyin2/pass") && !me->query("quest/jiuyin1/pass"))
		return notify_fail("�㲻����ϰ�����׹�צ��\n");
        if( (int)me->query_skill("jiuyin-baiguzhua", 1 ) < 120 )
		return notify_fail("�����ڲ�����ϰ�����׹�צ��\n");
	if( (int)me->query_skill("jiuyin-shenzhua", 1 ) >= 1 )
		return notify_fail("�������ץ�ˣ�����ѧ�����׹�צ��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������׹�צ������֡�\n");
	if ((int)me->query_skill("claw", 1) < 41)
		return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷��������׹�צ��\n");
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
	level   = (int) me->query_skill("jiuyin-baiguzhua",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"weapon":	action[j]["weapon"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	250 + random(300),
				"dodge":	random(30)-10,
				"parry":	random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������׹�צ��\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-baiguzhua/" + action;
}

void skill_improved(object me)
{
	tell_object(me, "���������ź�Ȼ���ĵ�����һ��а�\n");
	me->add("shen", -(me->query_skill("jiuyin-baiguzhua", 1)*100));
}
