// bibo-zhang.c
// Created by Numa 19990924,19991008

inherit SKILL;

// ���湥��
string* msg_f = ({
	"С��",
	"�ұ�",
	"���",
	"����",
	"�ؿ�",
	"С��",
	"ǰͥ",
});

// ���湥��
string* msg_b = ({
	"����",
	"����",
	"����",
});


mapping *action = ({
    ([  "action":       "$Nһ������˫�ƽ���������������ˮ��һɫ��Ʈ�Ʋ�������$n��"+ msg_f[random(sizeof(msg_f))],
        "dodge": 10,
        "parry": 5,
        "force": 120,
        "lvl": 0,
        "skill_name" : "ˮ��һɫ",
        "damage_type": "����"
        ]),
    ([  "action":       "$N��ǰ��̤һ����ͻʹһ�С�ˮ���Ľ���˫�ƾ�ֱ����$n��"+ msg_b[random(sizeof(msg_b))] +"��ȥ",
        "dodge": -10,
        "parry": -5,
        "force": 160,
        "lvl": 30,
        "skill_name" : "ˮ���Ľ�",
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һת�����ƻ��˸����������ԡ��̺����졹֮������$n��" + msg_f[random(sizeof(msg_f))] + "�����ȥ",
        "dodge":  20,
        "parry":  10,
        "force": 200,
        "lvl": 50,
        "skill_name" : "�̺�����",        
        "damage_type": "����"
        ]),
    ([  "action":       "$N���г��ȣ�˫����������һ�С�������ӿ���ͻ���$n��"+ msg_f[random(sizeof(msg_f))],
        "dodge": 20,
        "parry": 15,
        "force": 240,
        "lvl": 70,
        "skill_name" : "������ӿ",        
        "damage_type": "����"
        ]),
    ([  "action":       "$N��ǰ��̤һ�������Ʋ������������أ��������ᣬһ�С�ŭ���İ���Ϯ��$n��" + msg_f[random(sizeof(msg_f))],
        "dodge": 20,
        "parry": 15,
        "force": 300,
        "lvl": 90,
        "skill_name" : "ŭ���İ�",
        "damage_type": "����"
        ]),

});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���̲��Ʒ�������֡�\n");
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
        level = (int) me->query_skill("bibo-zhang",1);
        for (i = sizeof(action); i > 0; i--)
	        if (level > action[i-1]["lvl"])
        	        return action[NewRandom( i, 20, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 40)
                return notify_fail("�������̫���ˡ�\n");
        me->receive_damage("jingli", 20);
        return 1;
}