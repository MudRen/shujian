//    /kungfu/skill/tianchang-zhang.c �쳤�Ʒ�
// by action@SJ 2008/12/30

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ��"GRN"����ɽ������"NOR"��˫�ֻ��˸���Ȧ������$n��$l",
	  "skill_name" : "��ɽ����",
  	"lvl" : 5,
		"damage_type" : "����"
]),
([	"action" : "$Nʹһ��"MAG"����ϼ������"NOR"����������һ�ӣ�����$n��$l",
  	"skill_name" : "��ϼ����",
  	"lvl" : 15,
		"damage_type" : "����"
]),
([	"action" : "$N�����������⣬��������ʹһ��"CYN"���Ǻ�����"NOR"����$n��$l��ȥ",
  	"skill_name" : "�Ǻ�����",
  	"lvl" : 10,
		"damage_type" : "����"
]),
([	"action" : "$Nʹһ��"HIM"�������Ƶ���"NOR"���ֻ�$n���ؿں�$l",
  	"skill_name" : "�����Ƶ�",
	  "lvl" : 20,
		"damage_type" : "����"
]),
([	"action" : "$Nʹһ��"HIB"���������֡�"NOR"��������ͬʱ�������ڿ���ͻȻ�����Ʒ��򻥱�",
	  "skill_name" : "��������",
  	"lvl" : 30,
		"damage_type" : "����"
]),
([	"action" : "$N���ֲ�ס�ζ�������һ��"HIW"�����ղγ���"NOR"����$n��$l��ȥ",
	  "skill_name" : "���ղγ�",
  	"lvl" : 50,
		"damage_type" : "����"
]),
([	"action" : "$N���ֱ���Ϊ�ģ����������絶��һ��"HIY"�������ɳ��"NOR"������$n��$l",
	  "skill_name" : "�����ɳ",
	  "lvl" : 70,
		"damage_type" : "����"
]),
([	"action" : "$N����˺�벽������ʹһ��"HIC"��ˮ��һɫ��"NOR"�������$n",
	  "skill_name" : "ˮ��һɫ",
  	"lvl" : 80,
		"damage_type" : "����"
]),
([	"action" : "$Nһ��"CYN"���»����ա�"NOR"�������ȷ������������ƺ󷢶�����",
	  "skill_name" : "�»�����",
	  "lvl" : 90,
		"damage_type" : "����"
]),
([	"action" : "$N˫���������У�˫�����ɨ��$n��$l��ȴ��һ��"HIR"���϶��¡�"NOR"����̬����",
	  "skill_name" : "�϶���",
  	"lvl" : 100,
		"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���쳤�Ʒ���������֡�\n");
	if ( me->query_skill("baiyun-xinfa", 1) < 15)
		return notify_fail("��İ����ķ���򲻹����޷�ѧ��ת�쳤�Ʒ���\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����ת�쳤�Ʒ���\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int)me->query_skill("tianchang-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tianchang-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������쳤�Ʒ���\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianchang-zhang/" + action;
}
