// ningxue-shenzhao.c ��Ѫ��צ
// creat by Lklv 2002.1.26 for tdh, quest skills

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
"$p˫��һ������$P�����ƾ�����ȥ��$N��������������һƬճ��֮���м�һ�㡣\n",
"$p�Ҽ�б����������ָƾ�ջ��˼���Ȧ�ӣ�������΢��������$Nǧ�������\n",
"$p�ۼ�$P����������ʹ��һ�С���ȸβ�����ҽ�ʵ������飬���𡰼����־���ճ��ճ�棬�����Ѵ�ס$P���󣬺ᾢ������$N����������ǰһ�壬�����������ʼվ����\n",
"����$p˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�ֻ����$P��ԭ�ؼ�ת�߰��¡�\n",
"$p��������˫�ֳ�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ��������ʱ���׵�$P����ײײ�������������㲻�ȡ�\n",
"$pʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$P�׿���\n",
"$p����Ϣ΢�ϣ�����һ�С�б���ơ�����$P��ƫ��\n",
"$p��һ����������������ת�����ƻӳ���һ��һӭ����$P�������������˻�ȥ��\n",
"$p˫��һ����ʹ��һ�С����֡���˫���ᵽ�˼������������飬��$P�ļ���������ȥ��\n",
"$p����˫��һ�ӭ��$P��ȥ���������ƽ���δ��֮�ʣ�ʩ������ȸβʽ�������¡��𼦶���ʽ��������صأ��������գ�ȫ��ת������һö���ݡ�\n",
"��������ʯ���һ˲֮�䣬$p����һ�������ǡ��׺����᡹��ǰ���У�$P�ľ�����ʱ��ա�\n",
});

string query_parry_msg(object weapon, object target)
{
        if ( objectp(target->query_temp("weapon")) )
                return SKILL_D("parry")->query_parry_msg(weapon);
        else
                return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([
	"action" : HIR"$N�����転������аħ��˫צ���ץ�������������󷭴������ּ��죬�����ָץ��$n$l"NOR,
	"force" : 200,
	"dodge" : -5,
	"lvl" : 0,
   	"damage_type" : "ץ��"
]),
([
	"action" : HIR"ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n$l������ȥ"NOR,
	"force" : 260,
	"weapon" : "��ָ",
	"dodge" : 10,
	"lvl" : 10,
	"damage_type" : "ץ��"
]),
([
	"action" : HIR"$N�ֱ۹ؽڿ���һ�죬�ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���"NOR,
	"force" : 300,
	"weapon" : "��ָ",
	"dodge" : 5,
   	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : HIR"$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�æ��ͻȻ�����צ����ָ�͵ز���"NOR,
	"force" : 360,
	"weapon" : "��צ",
	"dodge" : 5,
	"lvl" : 30,
   	"damage_type" : "����"
]),
([
	"action" : HIR"$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l"NOR,
	"force" : 380,
	"weapon" : "�����ָ",
	"dodge" : 5,
	"lvl" : 40,
	"damage_type" : "����"
]),
([
	"action" : HIR "$N��צ��Σ���צ������һ��" HIR "��������ǡ�" HIR "ֱ����$n��$l" NOR,
	"force" : 400,
	"dodge" : 10,
	"lvl"   : 100,
	"skill_name" : "�������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : HIR "$N˫��������צ��צצ����$n��" HIR "������������" HIR "����$n��$lץ��" NOR,
	"force" : 420,
	"dodge" : -10,
	"lvl"   : 120,
	"skill_name" : "��������" ,
	"damage_type" : "����"
]),
([
	"action" : HIR "$N����Χ$nһת��ʹ��" HIR "�����޵�����" HIR "��$n��$l����ȫ������צӰ��" NOR,
	"force" : 450,
	"dodge" : 15,
	"lvl"   : 140,
	"skill_name" : "���޵���" ,
	"damage_type" : "ץ��"
]),
([
	"action" : HIR "$Nʹһ��" HIR "�������ơ�" HIR "��˫צ�ó�����צӰץ��$nȫ��" NOR,
	"force" : 470,
	"dodge" : 10,
	"lvl"   : 160,
	"skill_name" : "������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : HIR "$N����������һ��" HIR "��Ψ�Ҷ���" HIR "˫צ������$n�������" NOR,
	"force" : 500,
	"dodge" : 20,
	"lvl"   : 200,
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
	if ( !me->query("chen_jn/pass") )
		return notify_fail("û�г½��ϵ�ָ�㣬���޷���ϰ��Ѫ��צ��\n");
	if ((int)me->query_skill("ningxue-shenzhao", 1 ) < 120 )
		return notify_fail("�����ڲ���ѧϰ��Ѫ��צ��\n");
	if ( objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")) )
		return notify_fail("������ֲ�����ϰ��Ѫ��צ��\n");
	if ((int)me->query_skill("claw", 1) < 31)
		return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷�����Ѫ��צ��\n");
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
	level = (int) me->query_skill("ningxue-shenzhao",1);

	for(i = sizeof(action); i > 0; i--)
	if (level >= action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = (int)me->query_skill("ningxue-shenzhao", 1 );

	if ( lvl < 150 )
		return notify_fail("�����ڲ�����ϰ��Ѫ��צ��\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("���������������Ѫ��צ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -(10 + random(lvl/10+1)));
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ningxue-shenzhao/" + action;
}

void skill_improved(object me)
{
	tell_object(me, "����������ͻȻ�о���������Ѫ��ӿ��\n");
	if ( me->query("neili") > (me->query_skill("ningxue-shenzhao", 1) / 10) ){
		me->add("neili", -(me->query_skill("ningxue-shenzhao", 1) / 10));
	}
}
