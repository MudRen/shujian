// Ұ��ȭ
// ���� ר��

inherit SKILL;
#include <ansi.h>
#include <combat.h>

mapping *action = ({
([     "action" : HIW"$Nͦ�������˫����ȭ��һǰһ��һ�С�"HIY"��������"HIW"������$n����������·!"NOR,
       "force" : 150,
        "dodge" : 5,
       "damage_type" : "����",
       "lvl" : 0,
]),
([     "action" : HIW"$N΢΢���˸�������ŵŵأ�������ת����ȭ�͵Ļ�����ֱ��$n����ǰ������һ�� ��"HIR"��ȭ"HIW"��!"NOR,
       "force" : 160,
        "dodge" : 5,
        "damage_type" : "����",
       "lvl" : 12,
]),
([     "action" : HIW"$N΢΢���˸������ҽŵŵأ�������ת����ȭ�͵Ļ�����ֱ��$n����ǰ������һ�� ��"HIC"�ҹ�ȭ"HIW"��!"NOR,
       "force" : 170,
        "dodge" : 5,
        "damage_type" : "����",
       "lvl" : 18,
]),
([     "action" : HIW"$N��ų����һ�ڣ��������գ���ȭ��$n��$l�͵Ļ���������һ�С�"MAG"б�Ϲ�ȭ"HIW" ��! "NOR,
       "force" : 185,
        "dodge" : 15,
        "damage_type" : "����",
       "lvl" : 24,
]),
([     "action" : HIW"$N��ȭ��������������������ı�ȭΪצ�����ֱ�ȥץ$n�ļ�ͷ,����һ�С�"YEL"����С����"HIW" ��!  "NOR,
       "force" : 185,
        "dodge" : 15,
        "damage_type" : "����",
       "lvl" : 30,
]),
([     "action" : HIW"$N�����Ƹ���Ȧ����ȭ��Σ��͵�������ȥ��ץס$n����������һŤ,��"HIB"�ֽ���"HIW" ��! "NOR,
       "force" : 185,
        "dodge" : 15,
        "damage_type" : "����",
       "lvl" : 50,
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("��Ұ��ȭ������֡�\n");
       if ((int)me->query_skill("force", 1) < 30)
               return notify_fail("��Ļ����ڹ��ȼ�������������ϰҰ��ȭ��\n");
       if ((int)me->query("max_neili") < 100)
               return notify_fail("�������̫�����޷���Ұ��ȭ��\n");

if ( me->query_skill("yeqiu-quan",1) > 251 )
		return notify_fail("�����и����񹦾�ѧ����ţë��Ұ��ȭ�������ּ��ܾͲ����ٷ�ʱ�˰ɡ�\n");

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
       level = (int)me->query_skill("yeqiu-quan", 1);
       for(i = sizeof(action); i > 0; i--)
               if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("��ľ���̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("�������������Ұ��ȭ��\n");
       me->receive_damage("jingli", 25);
       me->add("neili", -25);
       return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{

	int i;

	i = me->query("max_pot", 1);

   if(i<=320){
       if(random(i)>(int)victim->query_skill("parry",1)/2 
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIB"$n��$N�����������壬��һ�ͣ���ʱ�������У�\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("yqq_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i<=220){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIB"$nֻ��$Nȭ�����������ɵ�������η��ֻ�ó��з��أ�˿��û�н������ᣡ\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

	
     
}

void yqq_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n������ͨ����·������һ������\n"NOR,target);
        return;
    }

    if(me->query_skill_mapped("cuff")!="yeqiu-quan"
     ||me->query_skill_mapped("parry")!="yeqiu-quan"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n�������˿�������ʼ������\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("yqq_must_be_hit",1,me,target,--i);
}



string perform_action_file(string action)
{
	return __DIR__"yeqiu-quan/" + action;
}
