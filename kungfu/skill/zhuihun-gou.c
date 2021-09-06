// zhuihun-gou.c, ��ɽ׷�깳
// by snowman@SJ 30/09/1999

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
"$n�ٺ�һЦ������$w��ǰһ�ܣ���$NӲ�����ص��˿�ȥ�����⻹������$P��\n",
"ȴ��$n�������ܣ�ֻ������$w˳���ֱ�һ�ţ��㵲ס��$N��\n",
"$n����ͻ�䣬$w�������������������$N��û����ʱ������$p��������\n",
"����$n��$wӲ����ƹ��һ���ܿ����������ڵ�$N��\n",
});


string query_parry_msg(object weapon, object victim) 
{ 
	if ( victim->query_temp("weapon") && this_player()->query_temp("weapon"))
		return parry_msg[random(sizeof(parry_msg))];
		
	else	return SKILL_D("parry")->query_parry_msg();
}

mapping *action = ({
([  "action": "ɭɭ���˵��������$N���У�$w��������ζ�����գ�۵�˲Ϣ�䣬ҫĿ�ĵ������������������⣬Ѹ����ƥ�Ļ���$n",
    "dodge": 30,
    "force" : 130,
    "damage": 160,
    "skill_name" : "����׷��",
    "lvl" : 0,
    "damage_type": "����"
]),
([  "action": "����$N����$w������һƬ�̶������ƵĽ���ײ������������������������ϵĳ�������ɢ���䣬һ���ڹ�����$nֱ�Ӷ���",
    "dodge": 30,
    "force" : 200,
    "damage": 180,
    "skill_name" : "ɷ��׷��",
    "lvl" : 20,
    "damage_type": "����"
]),
([  "action": "$N�ٴγ��ϣ�$wΧ��$n�������������䣬ǧ�ٹ�Ӱ�������л�ӳ��һ��������ѣĿ��ͼ������ͼ�������ˣ�����һƬ������ѩ������",
    "dodge": 40,
    "force" : 330,
    "damage": 250,
    "skill_name" : "����׷��",
    "lvl" : 40,
    "damage_type": "����"
]),
([  "action": "$N���������������������ɷ�Բ������һ������ķ籩���⻪��Ȼ�У���������������ɫ�����������������$w����һ����ֱ��$n",
    "dodge": 30,
    "force" : 200,
    "damage": 280,
    "skill_name" : "��ɳ׷��",
    "lvl" : 60,
    "damage_type": "����"
]),
([  "action": "$N��ɫ����������ɲ�Ǽ��ֳ������߸��Ƕ�����$w�Ķ�ʮһ���ó���Ƭ���⣬���һ������������٣�˲���Ѿ�����$n��ǰ",
    "dodge": 20,
    "force" : 270,
    "damage": 310,
    "skill_name" : "���׷��",
    "lvl" : 100,
    "damage_type": "����"
]),
([  "action": "$N����$w��ͻȻ����һ��ǿ�ҵĺ��⣬���ˡ���һ�������һ���뻡���������ֱ�������ƻã������ı����Ȼбƫ������$n����",
    "dodge": 30,
    "force" : 300,
    "damage": 330,
    "skill_name" : "����׷��",
    "lvl" : 140,
    "damage_type": "����"
]),
([  "action": "$N�Ĺ�ʽ�������ң�$w���������·��������������ҡ�������������죬���$n������������֮���������ˣ��Ǳ�����",
    "dodge": 10,
    "force" : 300,
    "damage": 300,
    "skill_name" : "Ѹ��׷��",
    "lvl" : 180,
    "damage_type": "����"
]),
([  "action": "$N����$w�������������纣Хɽ�������컽�أ���������������һ�������Ű��������Х��������������ϸ�ܵĹ�Ӱ����$nȫ������",
    "dodge": 30,
    "force" : 320,
    "damage": 360,
    "skill_name" : "����׷��",
    "lvl" : 0,
    "damage_type": "����"
]),
});

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 2000)
        return notify_fail("��ɽ׷�깳��Ҫ���ߵ�������Ϊ�������ã��㻹���ȼ��о������������ɡ�\n");

    if ((int)me->query("max_jingli") < 1000)
        return notify_fail("��ɽ׷�깳��Ҫ���ߵľ�����Ϊ�������ã��㻹���ȼ��о������������ɡ�\n");

    if (me->query_skill("huagong-dafa", 1) < 100)
               return notify_fail("��Ļ����󷨻��̫ǳ����ϰ������ɽ׷�깳��\n");
               
        return 1;
}

int practice_skill(object me)
{
        object weapon;
       
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hook")
        	return notify_fail("�����ϵ�����������������ɽ׷�깳��\n");
        if ((int)me->query("jingli") < 60)
        	return notify_fail("����Ъ���������ɡ�\n");
        if ((int)me->query("neili") < 20)
        	return notify_fail("���Ⱦۼ������������ɡ�\n");
        me->receive_damage("jingli", 50);  
        me->receive_damage("neili", 10);      
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        
        level=(int)me->query_skill("zhuihun-gou",1);
        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"zhuihun-gou/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
  

        int lvl,attack,lb;
     	  object weapon;

        lvl= me->query_skill("zhuihun-gou",1) +  me->query_skill("huagong-dafa",1) +  me->query_skill("hook",1) + me->query_skill("choushui-zhang",1);
        lvl = lvl* 5/4;
        lb = random(10);

         weapon = me->query_temp("weapon");

 if(!weapon) return;
 	
 if (me->query_skill_prepared("strike") != "chousui-zhang" ) return;




  if( lb> 5 || (lb>=3&&me->query_temp("zhuihun/lpf")))
   {
   	          
         message_vision(HIB "$N�����е�"+HIW+weapon->query("name")+HIB"һ�գ����־���һ�г����ƣ��Ʒ��ȳ�����Ȼ�Ǻ��о綾��" NOR,me, victim);
                         me->add_temp("apply/attack", lvl/5);
                         me->add_temp("apply/strength", lvl/5);
                         me->add_temp("apply/damage", lvl/5);
       weapon->unequip(); 
                        if (me->is_fighting(victim))
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),3); 
       weapon->wield();
                       me->add_temp("apply/attack", -lvl/5);
                                                               me->add_temp("apply/strength", -lvl/5);
                       me->add_temp("apply/damage", -lvl/5);
 
     }

}


  
