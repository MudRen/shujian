//daidai������2005-10-07

// yingshe-shengsibo ӥ��������



#include <ansi.h>

#include <combat.h>

inherit SKILL;

mapping *action = ({

([      "action" : "$N���ƻ��أ��ұ�΢�������Σ��������⼲�죬һʽ�����߳���������$n��$l",

        "force" : 140,

        "dodge" : 10,

        "damage_type" : "����",

        "lvl" : 0,

        "skill_name" : "���߳���"

]),



([      "action" : "$Nٿ������һ����ʹ������ӥ��צ������ۺ�ӣ�һת��˫��ʮָ��������ӥצ���Ͳ�$n��$l",

        "force" : 180,

        "dodge" : 10,

        "parry" : 10,

        "lvl" : 10,

        "damage_type" : "ץ��",

        "skill_name" : "��ӥ��צ"

]),



([      "action" : "$Nʹ�����������㡹��˫����$nץȥ��ͬʱ��������Ϣ��һ������$n��$l",

        "force" : 200,

        "dodge" : 10,

        "damage_type" : "����",

      "lvl" : 20,

        "skill_name" : "��������"

]),([      "action" : "$N�εض���һʽ����ӥϮ�á����Ӱ���з��˶��£�Ѹ�͵�ץ��$n��$l",

        "force" : 220,

        "dodge" : 10,

        "parry" : 10,

        "damage": 5,

        "lvl" : 30,

        "damage_type" : "ץ��"

,

        "skill_name" : "��ӥϮ��"

]),

([      "action" : "ֻ��$N�����ڵأ�����$n��ǰ̽�ӣ�ͻȻ����ʹ����������Ӱ������$n��ץ����",

        "force" : 240,

        "dodge" : 10,

        "damage_type" : "ץ��",

        "lvl" : 40,

        "skill_name" : "������Ӱ"

]),

([      "action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",

        "force" : 280,

        "dodge" : 0,

        "parry" : 0,

        "damage": 20,

        "lvl" : 50,

        "damage_type" : "ץ��"

,

        "skill_name" : "ӥ������"

]),

([      "action" : "$N˫�ֻ����лó������Ӱ��һ�С�������ӿ������������������ǵ�����$n",

        "force" : 300,

        "dodge" : 0,

        "damage_type" : "����",

        "lvl" : 60,

        "skill_name" : "������ӿ"

]),

([      "action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l",

        "force" : 320,

        "dodge" : 15,

        "parry" : 15,

        "damage": 15,

        "lvl" : 70,

        "damage_type" : "ץ��",

        "skill_name" : "��ӥչ��"

]),

([      "action" : "$N���䲻���ʹһʽ���������š�������ʳ����ָ΢�֣���������$n��$l��ͱ",

        "force" : 360,

        "dodge" : 0,

        "damage_type" : "����",

        "lvl" : 80,

        "skill_name" : "��������"

]),

([      "action" : "$N��������צ���棬һʽ��ӥ�����ա��������������ƿն�����Ѹ���ޱȵػ���$n",

        "force" : 380,

        "dodge" : 10,

        "parry" : 0,

        "damage": 15,

        "lvl" : 90,

        "damage_type" : "ץ��"

,

        "skill_name" : "ӥ������"

]),

([      "action" : "$N˫�������޹ǵ������ţ�ʹ�����������񡹲�ס$n���ұ۴Ӳ���˼�鴦Ĩ��$n��$l",

        "force" : 420,

        "dodge" : 5,

        "damage_type" : "����",

        "lvl" : 100,

           "skill_name" : "��������"

 ] ),

([      "action" : "$Nһʽ����ӥ��������˫�ִ���˻˻�ƿ�֮��������Ѹ�ٵؾ���$n����Ҫ������",

        "force" : 480,

        "dodge" : 20,

        "damage_type" : "����",

        "lvl" : 120,

        "skill_name" : "��ӥ����"

]),});

int valid_enable(string usage) { return usage=="claw" || usage=="hand" ||  usage=="parry"; }



int valid_combine(string combo) { return combo=="yingshe-shengsibo"; }



int valid_learn(object me)

{
	 mapping myfam = (mapping)me->query("family");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

                return notify_fail("��ӥ��������������֡�\n");

	if ( myfam["family_name"] !=  "��ɽ��")
		  return notify_fail("��ǻ�ɽ���ӣ����ʸ���ϰ���书��\n");

                     if ((int)me->query("max_neili") < 300)

                return notify_fail("�������̫�����޷���ӥ����������\n");

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

        int i, level,attack;

        object ob;

        

        ob = me->select_opponent();

        level = me->query_skill("yingshe-shengsibo", 1)+1;

    

            if( me->query_temp("huashan_shengsi")    &&living(ob)

&&me->query_skill_prepared("hand") == "yingshe-shengsibo"

&&me->query_skill_prepared("claw") == "yingshe-shengsibo"

&&!me->query_temp("huashan_yingshe")

&&me->query("neili")>800

)

    {    

        attack=level/100;

    if(attack>4) attack=4;

                            if(attack<=1) attack=1;

message_vision(HIY "\n������$N������ָ��£����ͷ֮�Σ��㡢�򡢴̡��������缱�籩��㹥����"+ chinese_number(attack+1)+"�С�\n" NOR, me);

                    for(i=0;i<attack;i++)

                    {

                        me->add("neili", -(50+random(50)));

                        

                        ob = me->select_opponent();

                        if(!living(ob))

                        {

                        break;

                        }

                        me->set_temp("huashan_yingshe",1);

                    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);  

                        me->delete_temp("huashan_yingshe");

me->delete_temp("huashan_shengsi");

                    }

        }





        

        for(i = sizeof(action); i > 0; i--)

                if(level > action[i-1]["lvl"])

                        return action[NewRandom(i, 20, level/5)];

}



int practice_skill(object me)

{

        if ((int)me->query("jingli") < 30)

                return notify_fail("��ľ���̫���ˡ�\n");

        if ((int)me->query("neili") < 20)

                return notify_fail("�������������ӥ����������\n");

        me->receive_damage("jingli", 25);

        me->add("neili", -5);

        return 1;

}

string perform_action_file(string action)

{

        return __DIR__"yingshe-shengsibo/" + action;

}