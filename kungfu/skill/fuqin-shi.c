// fuqin-shi.c ���Ҹ���ʽ
// Created by snowman@SJ 06/03/2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action": "$N���С���ɮ����粡�������һ�ӣ�$w��������ת����ס������һ���ӱ�������$n��ǰ",
       "dodge": 5,
       "parry": 10,
       "damage": 60,
       "force": 130,
       "lvl" : 0,
       "skill_name" : "��ɮ�����",
       "damage_type":  "����"
]),
([     "action": "$N˵���������⡸���¶�ü�塹����$wವ�һ�����Ͽշɴ�����������������һƬ��ž�������Һ���ת�£�ֱ��$n",
       "dodge": 10,
       "parry": 10,
       "damage": 70,
       "force": 180,
       "lvl" : 30,
       "skill_name" : "���¶�ü��",
       "damage_type":  "����"
]),
([     "action": "$N�����ֱۣ���$w��������͵�һ����������Ϊ��һ���֡�����$n��������ƹ�������������",
       "dodge": -10,
       "parry": 10,
       "damage": 80,
       "force":  230,
       "lvl" : 60,
       "skill_name" : "Ϊ��һ����",
       "damage_type":  "����"
]),
([     "action": "$N���а��ԣ����߱�����������ɡ���$w��$n��ǰ��ͣ��������Ȼ��׼���ᣬ�͵�һ�³��",
       "dodge": 10,
       "parry": 10,
       "damage": 90,
       "force": 270,
       "lvl" : 90,
       "skill_name" : "����������",
       "damage_type":  "����"
]),
([     "action": "$Nһ���ߺȡ�����ϴ��ˮ������$w���Ȼ��裬ֻ������ı�Ӱ������£������ˮ��ӿ��$n",
       "dodge": -5,
       "parry": 10,
       "damage": 110,
       "force": 300,
       "lvl" : 120,
       "skill_name" : "����ϴ��ˮ",
       "damage_type":  "����"
]),
([     "action": "$N������ע��$w�У������趯������һƬƬ����������������С�������˪�ӡ����ŵ�$n�ķ����ң�$wȴ�������",
       "dodge": 20,
       "parry": 10,
       "damage": 130,
       "force": 320,
       "lvl" : 150,
       "skill_name" : "������˪��",
       "damage_type":  "����"
]),
([     "action": "$N�����������ɽĺ�������Ʊ�ó����������������������������ɳ���ɿ����ҹ�������Ҷ�������޲����÷����ȥ",
       "dodge": 10,
       "parry": 10,
       "damage": 140,
       "force": 340,
       "lvl" : 180,
       "skill_name" : "������ɽĺ",
       "damage_type":  "����"
]),
([     "action": "$N�������С����ư����ء���$w�ڿ������������裬һ�¡����¡����¡������ϳ���$n���Ƶ�$p���Ϻ���",
       "dodge": 15,
       "parry": 10,
       "damage": 150,
       "force": 360,
       "lvl" : 200,
       "skill_name" : "���ư�����",
       "damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
                     
       	if( (int)me->query("max_neili") < 100 )
               return notify_fail("���������Ϊ���㣬û�а취�����Ҹ���ʽ��\n");

        if ((int)me->query_skill("sancheng-gong", 1) < 130)
               return notify_fail("������˹������̫ǳ��\n");
	if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        if ( me->query("class") != "bonze" && me->query_skill("sancheng-gong", 1) < 100 )
                return notify_fail("���Ҹ���ʽ�����׼��µ��ӡ�\n");
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
        level   = (int)me->query_skill("fuqin-shi", 1);
        
        if( me->query_temp("pfm/baishui") ){
        	me->delete_temp("pfm/baishui");
        	return ([
        		"action": HIW"������ͬ���է��ʱ������һ����ˮ������һ�ذ��ƣ�$N�����ڱޣ�" + weapon->name() + HIW"�����ֱ�£�����ˮ����ʽ������$n��"NOR,
       			"dodge": 30,
       			"damage": 160,
       			"force": 400,
       			"damage_type":  "����",
        	]);
        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

       	if ((int)me->query("jingli") < 40)
                return notify_fail("����������������Ҹ���ʽ��\n");
        me->receive_damage("jingli", 30);
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������Ҹ���ʽ��\n");
        me->receive_damage("neili", 5);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fuqin-shi/" + action;
}
