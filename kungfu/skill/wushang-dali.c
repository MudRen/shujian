// wushang-dali.c ���ϴ����Ʒ�
// by iceland

inherit SKILL;

mapping *action = ({
([
	"action": "$N�߾�$w, ��ȫ��֮����һ�С���������������$n��ͷ�����������������ƾ��ˣ�",
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type": "����"
]),
([
	"action": "$Nʹ��һ�С���ɽʽ��,������ס$wͷ������������$w�м����ƣ�����һ��$wƽɨ��$n��$l",
	"lvl" : 30,
	"skill_name" : "��ɽʽ", 
	"damage_type": "����"
]),
([
	"action": "$N��ƽ��֮������$w�����������һ�㣬�ܲ�͸�磬һ�С���Ǭ������������$n��ѹ��ȥ��",
	"lvl" : 60,
	"skill_name" : "��Ǭ��", 
	"damage_type": "����"
]),
([
	"action": "$N���һ������������һ�С������ơ�,˫�ֱ�ס$wһ�ˣ����䷢��������������$n��û��һƬ����С�",
	"lvl" : 90,
	"skill_name" : "������", 
	"damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage == "staff" || usage == "parry";
}

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff")
		return notify_fail("����ϰ�����ϴ����Ʒ���ȴ�е�����̫���Ծ���\n");
	if ( me->query("max_neili") < 200)
		return notify_fail("�������̫��������ѧϰ���ϴ����Ʒ���\n");
	if ( me->query_str(1) < 25)
		return notify_fail("�������̫�ͣ����ʺ�ѧϰ���ϴ����Ʒ���\n");
	if (me->query_skill("longxiang-boruo", 1) < 35)
		return notify_fail("���������������̫ǳ��\n");    
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
	level   = (int) me->query_skill("wushang-dali",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"damage":40+random(60),
				"parry":random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("wushang-dali", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if( me->query("neili") < 10)
		return notify_fail("�������̫���ˣ�Ъ���������ɡ�\n");
	if ( me->query("jingli") < 30)
		return notify_fail("��̫���ˣ�Ъ���������ɡ�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
