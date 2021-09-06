// hunyuan-zhang.c ��ɽ��Ԫ�� 

inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$N�Ʒ缤����˫�ƴ��䣬���������޷���һ�С��ƶ����롹������$n��$l",
        "force" : 170,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" : "�ƶ�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫������һ�С����ɴ�䡹��һ�ƻ���$n���ţ���һ��ȴ����$nС��",
        "force" : 230,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 10,
        "skill_name" : "���ɴ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ������Ī�⣬һ�С���ɽ��ˮ����ǰ�����ң�˲Ϣ֮����$n������ʮ����",
        "force" : 300,
        "dodge" : 15,
        "parry" : 20,
        "lvl" : 20,
        "skill_name" : "��粻��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ����Х������һ�ƣ�һ�С�ɽ��·ת��������ת׾��ȴ��ȥ����죬��$n��$l�ͻ���ȥ��",
        "force" : 280,
        "dodge" : 20,
        "parry" : 25,
        "lvl" : 30,
        "skill_name" : "ɽ��·ת",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����˫�ƽ����������ޣ�Ʈ���һ�С��������á����Ʒ缱������$n��$l",
        "force" : 290,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 40,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ɽ�Ϻӡ�������һȭ���������ƽ���������ȭ��һ����˫������������$n��$l",
        "force" : 310,
        "dodge" : 5,
        "parry" : 3,
        "lvl" : 50,
        "skill_name" : "��ɽ�Ϻ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫���뻮������˫�����ƣ�һ�С�������ơ���һ����ɽ������������ֱ��$n����",
        "force" : 340,
        "dodge" : 10,
        "parry" : 3,
        "lvl" : 65,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�������ת��һ�С�����Ʈ�졹����Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 400,
        "dodge" : 5,
        "parry" : 0,
        "lvl" : 80,
        "skill_name" : "����Ʈ��",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ԫ�Ʊ�����֡�\n");
       if (me->query_skill_mapped("force") != "zixia-gong" && me->query_skill_mapped("force") !="huashan-qigong")
                return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧϰ��Ԫ�ơ�\n");
        if ((int)me->query_skill("zixia-gong", 1) < 20 && (int)me->query_skill("huashan-qigong", 1) < 20)
                return notify_fail("�����ϼ�񹦻�򲻹����޷�����Ԫ�ơ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����Ԫ�ơ�\n");
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
        int i,level,f_force;
        f_force=me->query_skill("force");
         if ((
         (me->query_temp("jianzhang")&&random(f_force)> 300)
         ||random(me->query_str()) >= 39)
          && me->query_skill("hunyuan-zhang",1)> 200 
          && me->query_skill("parry",1) > 200
          ) {
          	
                return ([
                "action": WHT "$N���һ�����������������������ƣ������Ʒ����,����ǧ�Ѹֵ���$nϮȥ��"NOR,
                "force": 500,
                "dodge": 10,
                "parry": 10,
                "damage_type": "����"]);
        }
        if ((
         (me->query_temp("jianzhang")&&random(f_force)> 200)
         ||random(me->query_str()) >= 35)
          && me->query_skill("hunyuan-zhang",1)> 150 
          && me->query_skill("parry",1) > 150
          ) {
                return ([
                "action": WHT "$N˫�ƻû�һƬ��Ӱ����$n�������ڣ�$n��ǰһ������ʱ��֪���롣"NOR,
                "force": 460,
                "dodge": 15,
                "parry": 5,
                "damage_type": "����"]);
        }
        if ((
         me->query_temp("jianzhang")
         ||random(me->query_str()) >= 30)
          && me->query_skill("hunyuan-zhang",1)> 100 
          && me->query_skill("parry",1) > 100
          ) {
                return ([
                "action": WHT "$N��ɫ���أ�˫����ƮƮ������$n��һ����ɽ�������ھ�����Ϣ����$n�ؿ�ײȥ��"NOR,
                "force": 420,
                "dodge": 5,
                "parry": 10,
                "damage_type": "����"]);
        }
        
       
        level   = (int) me->query_skill("hunyuan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������Ԫ�ơ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"hunyuan-zhang/" + action;
}
