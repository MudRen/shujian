// haotian-zhang �����
// Modified by action@SJ 2008/09/15

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$Nʹһ��"+(order[random(13)])+"��������ˮ��"NOR"��˫�ֻ��˸���Ȧ������$n��$l",
        "skill_name" : "������ˮ",
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"���������¡�"NOR"����������һ�ӣ�����$n��$l",
        "skill_name" : "��������",
        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬��������ʹһ��"+(order[random(13)])+"�������沨��"NOR"����$n��$l��ȥ",
        "skill_name" : "�����沨",
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"��������ת��"NOR"���ֻ�$n���ؿں�$l",
        "skill_name" : "������ת",
        "lvl" : 15,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"�����ջ��֡�"NOR"��������ͬʱ�������ڿ���ͻȻ�����Ʒ��򻥱�",
        "skill_name" : "���ջ���",
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N���ֲ�ס�ζ�������һ��"+(order[random(13)])+"��������˪��"NOR"����$n��$l��ȥ",
        "skill_name" : "������˪",
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$N���ֱ���Ϊ�ģ����������絶��һ��"+(order[random(13)])+"��͡�ϰ�ɳ��"NOR"������$n��$l",
        "skill_name" : "͡�ϰ�ɳ",
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N����˺�벽������ʹһ��"+(order[random(13)])+"������һɫ��"NOR"�������$n",
        "skill_name" : "����һɫ",
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"������¡�"NOR"�������ȷ������������ƺ󷢶�����",
        "skill_name" : "�����",
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N˫���������У�˫�����ɨ��$n��$l��ȴ��һ��"+(order[random(13)])+"��������ˮ��"NOR"����̬����",
        "skill_name" : "������ˮ",
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N�����鰴�����ֻ�������ʹһ��"+(order[random(13)])+"���������ơ�"NOR"����$n��$l��ȥ",
        "skill_name" : "��������",
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֱ�����ȭ����ǰ��󻮻���һ��"+(order[random(13)])+"��������ϡ�"NOR"����$n��$l",
        "skill_name" : "�������",
        "lvl" : 55,
        "damage_type" : "����"
]),
([      "action" : "$N�����黮�����ֱ���Ϊ��һ��"+(order[random(13)])+"��¥����ء�"NOR"����$n��$l",
        "skill_name" : "¥�����",
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$Nʩ��"+(order[random(13)])+"�������С�"NOR"����������ӳ�������ͬʱ����$n",
        "skill_name" : "������",
        "lvl" : 65,
        "damage_type" : "����"
]),
([      "action" : "$N�ɱ۴��֣�����ǰ����������ʹһ��"+(order[random(13)])+"�����㳤�ɡ�"NOR"������$n��$l",
        "skill_name" : "���㳤��",
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N����͵أ�����ʹһ��"+(order[random(13)])+"������ǱԾ��"NOR"�����¶�����$n��$l��ȥ",
        "skill_name" : "����ǱԾ",
        "lvl" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ��"+(order[random(13)])+"���»����ա�"NOR"",
        "skill_name" : "�»�����",
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N���Ʋ�ס����ɨ������һʽ"+(order[random(13)])+"����̶�仨��"NOR"��������ת����$n��ȥ",
        "skill_name" : "��̶�仨",
        "lvl" : 85,
        "damage_type" : "����"
]),
([      "action" : "$N���־���ǰ��������ǰƲ����ʹһ��"+(order[random(13)])+"����ˮ������"NOR"����$n��$l��ȥ",
        "skill_name" : "��ˮ����",
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"��б�³�����"NOR"����������������Ȧ�����ƴ�Ȧ�д�������$n",
        "skill_name" : "б�³���",
        "lvl" : 95,
        "damage_type" : "����"
]),
([      "action" : "$N�������ϻ�������������ʹһ��"+(order[random(13)])+"����ʯ���桹"NOR"�����Ʋ�ס�ζ�������$nͷ������֮��",
        "skill_name" : "��ʯ����",
        "lvl" : 100,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������Ʊ�����֡�\n");
        if ((int)me->query_skill("xiantian-gong", 1) < 10)
                return notify_fail("�������������򲻹����޷�ѧ����ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{ 
	int i, j, level,xtg;
	level = me->query_skill("haotian-zhang",1);
	xtg = me->query_skill("xiantian-gong", 1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("htz/ju") && random(2)) { 
				return ([  
					"action" :random(2)? HIW+action[j]["action"]+NOR :HIY+action[j]["action"]+NOR,
					"force" : 200 + random(350),
					"dodge": random(30),
					"damage": 80 + random(140),
					"parry": random(30),
					"weapon" : random(2)?"����":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			if( me->query_temp("htz/lianhuan")){
				return ([  
					"action":HIW+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIW), NOR, HIW)+NOR,
					"lvl" : action[j]["lvl"],
					"force" : 120 + random(250) + xtg/10,
					"dodge": random(20)- 5 +xtg/15,
					"damage":40 + random(60) + random((level+xtg)/4),
					"parry": random(15)+xtg/10,//ԭ����15
					"weapon" : random(2)?"�Ʒ�":"����",
					"damage_type" : random(2)?"����":"����",
				]);
			}
			return ([
				"action": action[j]["action"],
				"force" : 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 100 +random(120),
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
			]);
		}
	}
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ơ�\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"haotian-zhang/" + action;
}
