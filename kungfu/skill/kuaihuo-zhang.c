// kuaihuo-strike.c ���ʮ����
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N����һȭֱ���������翪�Ʊգ���ס�Է����֣����°��������ȣ�����"GRN"��ʹ�����졹"NOR"",
	"lvl"    : 0,
	"skill_name" : "ʹ������"
]),
([	"action" : "$N����һ�Ʒ���$n���ţ����ư��������Ƿ�ס$n���ߣ�����ֱȭ����$n�ؿڣ�����һ��"HIG"���������ܡ�"NOR"",
	"lvl"    : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N������ֱ�濪������$n���ţ����ֻӶ�������$n����������Ѩ������"HIB"�����»��ȡ�"NOR"",
	"lvl"    : 40,
	"skill_name" : "���»���"
]),
([	"action": "$Nʹ��"HIR"������Χ¯��"NOR"��˫����$n���屧ȥ�����г��ȼ���$n$l",
	"lvl"    : 60,
	"skill_name" : "����Χ¯"
]),
([	"action" : "$Nʹ��"MAG"��������÷��"NOR"�����������£�бб��$n�������£�������ָ��������÷֦б����ָ��$n",
	"lvl"    : 80,
	"skill_name" : "������÷"
]),
([	"action" : "$N����ʹ�������Ź���˫�ֳ�������״��Ƭ�̼���ָ��$n��ǣ�����һ��"HIW"�������þơ�"NOR"",
	"lvl"    : 100,
	"skill_name" : "�����þ�"
]),
([	"action" : "$N������ֱָ��������$n������Ѩ�����ֳɺ��λ���������"HIM"��Ū�����١�"NOR"",
	"lvl"    : 120,
	"skill_name" : "Ū������"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ʮ���Ʊ�����֡�\n");
        if ((int)me->query_skill("panshi-shengong", 1) < 20)
                return notify_fail("�����ʯ�񹦻�򲻹����޷�ѧ���ʮ���ơ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷������ʮ���ơ�\n");
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
        level = (int)me->query_skill("kuaihuo-zhang", 1);

        if (me->query_temp("tsjf/shibapan") == 2){
            return([
                   "action": BLU "������$N"BLU"����һתһ�գ���$n"BLU"��û�з�Ӧ����ʱ������ǰ���ڳ����ַ������һʽ�����ʮ���ơ���"NOR,
                   "force" : 500,
                   "dodge" : 10,
                   "damage_type" : "����",
                   ]);
            }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{

        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������ʮ���ơ�\n");
        me->receive_damage("jingli", 30);
        me->receive_damage("neili", 5);
        if(me->query_skill("kuaihuo-zhang", 1) > 170)
                me->receive_damage("jingli", 10);
        if(me->query_skill("kuaihuo-zhang", 1) > 190)
                me->receive_damage("neili", 5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuaihuo-zhang/" + action;
}