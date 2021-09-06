#include <ansi.h>
//inherit FORCE;
inherit SKILL;

string *dodge_msg = ({
    "$n�����ĳ������絽������$N��һ�ߡ�\n",
    "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
    "$n������ţ���Ծ��������������ʮ�����⡣\n",
    "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});

string *parry_msg = ({
    "$nĬ��̫���ھ�����$N�Ĺ��ƾ������⡣\n",
    "$nһ����Ц����$N�Ĺ����������⡣\n",
    
    "$Nֻ��$n�����Ӳ���������ͭǽ������һ�㡣\n",
});

mapping *actionw = ({
([      "action" : "$Nһ��[ �Կ��Ϻ�ӧ���⹳˪ѩ�� ]ֱ����$n��",
        "force" : 510,
        "attack": 180,
        "dodge" : 85,
        "parry" : 175,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$Nһ��[ �Կ��Ϻ�ӧ���⹳˪ѩ�� ]ֱ����$n��",
        "force" : 510,
        "attack": 108,
        "dodge" : 72,
        "parry" : 115,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$Nһ��[ �Կ��Ϻ�ӧ���⹳˪ѩ�� ]ֱ����$n��",
        "force" : 532,
        "attack": 125,
        "dodge" : 60,
        "parry" : 102,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N��һ��[ �����հ����������� ]��$nײȥ��",
        "force" : 565,
        "attack": 110,
        "dodge" : 75,
        "parry" : 105,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N�߽У�[ ʮ��ɱһ�ˣ�ǧ�ﲻ���� ]����$n��",
        "force" : 550,
        "attack": 108,
        "dodge" : 70,
        "parry" : 120,
        "damage": 420,
        "damage_type": "����"
]),
});

mapping *action = ({
([      "action":"$N��ʽһ�䣬[ ���˷���ȥ����������� ]$nֻ�÷����ֵ���",
        "force" : 540,
        "attack": 50,
        "dodge" : 50,
        "parry" : 120,
        "damage": 355,
        "damage_type":  "����"
]),
([      "action":"$N�����Ц[ �й����������ѽ�ϥǰ�� ]��ȭ��$n��ȥ��",   
        "force" : 560,
        "attack": 60,
        "dodge" : 60,
        "parry" : 90,
        "damage": 330,
        "damage_type":  "����"
]),
([      "action":"$N��ʹ��һ��[ ������캥������Ȱ���� ]ֱ����$n��",
        "force" : 570,
        "attack": 75,
        "dodge" : 75,
        "parry" : 135,
        "damage": 360,
        "damage_type":  "����"
]),
([      "action":"$N��ȭΪ�ƣ�����һ��[ ������Ȼŵ��������Ϊ�� ]��",
        "force" : 580,
        "attack": 80,
        "dodge" : 80,
        "parry" : 75,
        "damage": 395,
        "damage_type":  "����"
]),
([      "action":"$Nȭ���ٱ䣬[ �ۻ����Ⱥ����������� ]$n�ò��Ǳ���",
        "force" : 580,
        "attack": 95,
        "dodge" : 90,
        "parry" : 125,
        "damage": 360,
        "damage_type":  "����"
]),
([      "action":"$N��̾һ����[ ˭������£�����̫���� ]$n�������ˡ�",
        "force" : 580,
        "attack": 100,
        "dodge" : 100,
        "parry" : 145,
        "damage": 480,
        "damage_type":  "����"
]),
});
int valid_enable(string usage)
{
return usage == "cuff" || usage == "dodge" ||usage == "parry" || usage == "force" || usage == "strike";
}



string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_learn(object me)
{


if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
return notify_fail("��̫����������֡�\n");
if ((int)me->query("max_neili") < 100)
return notify_fail("�������̫�����޷�������\n");
return 1;
}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/" + func;
}
string perform_action_file(string action)
{
        return __DIR__"taixuan-gong/" + action;
}

string query_parry_msg(object weapon, object me)
{
        if (me->query_skill_mapped("parry") == "taixuan-gong")
                return parry_msg[random(sizeof(parry_msg))];
}
        

mapping query_action(object me, object weapon)
{
        int i, j, level;
                string msg;
level = me->query_skill("taixuan-gong",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                                                if ( me->query_temp("txg/xuan")){
                                return ([
                                        "action":HIW+replace_string(replace_string(replace_string(action[j]["actionw"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
                                        "damage": 60+random(120),
                                        "damage_type": "����",
                                        "dodge": random(35),
                                        "parry": random(35),
                                        "force": 200+random(300),
                                ]);
                        }
                        if(me->query_temp("txg/xuan")){
                switch(me->query_temp("taixuan")){                                              
 case 5: msg = HIW"\n$N��ʽһ�䡸"HIR"�����հ����������� "NOR+HIC"��$nֻ�÷����ֵ�"NOR;break;
 case 4: msg = HIG"\n$Nһ�С�"HIR"�Կ��Ϻ�ӧ���⹳˪ѩ��"NOR+HIC"��ֱ����$n"NOR;break;
 case 3: msg = HIC"\n$N��ȭΪ�ƣ�����һ�С�"HIR"������Ȼŵ��������Ϊ�� "NOR+HIC"��"NOR;break;
 case 2: msg = HIM"\n$Nȭ���ٱ䣬��"HIR" �ۻ����Ⱥ����������� "NOR+HIC"��$n�ò��Ǳ�"NOR; break;
 case 1: msg = HIC"\n$N�߽У���"HIR" ʮ��ɱһ�ˣ�ǧ�ﲻ���� "NOR+HIC"������$n"NOR; break;
default: msg = HIY"\n$N��̾һ����"HIR"˭������£�����̫���� "NOR+HIC"��$n��������"NOR;break;
                }
                me->add_temp("taixuan", -1);
                return ([
                        "action":msg,
                                        "damage": 80+random(80),
                                        "damage_type": "����",
                                        "dodge": random(35),
                                        "parry": random(60),
                                        "force": 200+random(300),
                                ]);
                        }
                        return ([
                                "action" : action[j]["action"],
                                "force" : 200 + random(350),
                                "dodge" : random(25)-5,
                                "parry": 50+random(60),
                                "damage" : 80 + random(80),
                                "damage_type" : action[j]["damage_type"],
                                "lvl": action[j]["lvl"],
                        ]);
                }
        }
if (random(me->query_skill("taixuan-gong",1)) > 300 && me->query("neili") > 100)
        {
                me->add("neili", -50);
                return ([
        "action": HIR "$N������ͻȻһƬãȻ��ֻ���þ�������������������ڴ�����ȥ���ѹ��ǳ���
���²������룬˳����������һ��ȭ����ߣ����ܶ�ʱ������쩣��ò����֣�"NOR,
        "damage": 1000,
        "dodge" : 100,
        "force" : 400,
        "damage_type": "����"]);
        }
        return action[random(sizeof(action))];


        
}
int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("�������������̫������\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}


