#include <ansi.h>
inherit SKILL;
mapping *action = ({
([
	"action" : HIW"$N�����転������аħ��˫צ���ץ�������������󷭴������ּ��죬�����ָץ��$n$l"NOR,
	"lvl" : 0,
	"damage_type" : "ץ��"
]),
([
	"action" : HIW"ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n$l������ȥ"NOR,
	"weapon" : "��ָ",
	"lvl" : 10,
	"damage_type" : "����"
]),
([
	"action" : HIW"$N�ֱ۹ؽڿ���һ�죬�ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���$n��$l"NOR,
	"weapon" : "��ָ",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : HIW"$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�â��ͻȻ�����צ����ָ�͵ز���"NOR,
	"weapon" : "��צ",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : HIW"$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l"NOR,
	"weapon" : "�����ָ",
	"lvl" : 40,
	"damage_type" : "����"
]),
([
	"action" : HIW "$N��צ��Σ���צ������һ��" HIR "��������ǡ�" HIW "ֱ����$n��$l" NOR,
	"lvl"   : 100,
	"skill_name" : "�������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : HIW "$N˫��������צ��צצ����$n��" HIR "������������" HIW "����$n��$lץ��" NOR,
	"lvl"   : 120,
	"skill_name" : "��������" ,
	"damage_type" : "ץ��"
]),
([
        "action" : HIW "$N����Χ��$nһת��ʹ��" HIR "�����޵�����" HIW "��$n��$l����ȫ������צӰ��" NOR,
	"lvl"   : 140,
	"skill_name" : "���޵���" ,
	"damage_type" : "ץ��"
]),
([
	"action" : HIW "$Nʹһ��" HIR "�������ơ�" HIW "��˫צ�ó�����צӰץ��$nȫ��" NOR,
	"lvl"   : 160,
	"skill_name" : "������" ,
	"damage_type" : "ץ��"
]),
([
	"action" : HIW "$N����������һ��" HIR "��Ψ�Ҷ���" HIW "˫צ������$n�������" NOR,
	"lvl"   : 180,
	"skill_name" : "Ψ�Ҷ���" ,
	"damage_type" : "ץ��"
]),
});

int valid_enable(string usage)
{ 
	return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
	if( (int)me->query_skill("jiuyin-shenzhua", 1 ) < 140 )
		return notify_fail("�����ڲ���ѧϰ������צ��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������צ������֡�\n");
	if ((int)me->query_skill("claw", 1) < 50)
		return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
	if ((int)me->query_skill("jiuyin-zhengong", 1) < 50)
		return notify_fail("��ľ����湦��򲻹����޷�ѧϰ��\n");
	if ((int)me->query_skill("jiuyin-baiguzhua", 1) > 1)
		return notify_fail("��ѧ�˾����׹�ץ���޷�ѧϰ������צ��\n");
	if ((int)me->query_skill("daode-jing", 1) < 50)
		return notify_fail("��ĵ�ѧ�ķ���򲻹����޷�ѧϰ��\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷���������צ��\n");
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
	level   = (int) me->query_skill("jiuyin-shenzhua",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"weapon":	action[j]["weapon"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	300 + random(350),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������������צ��\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20 );
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-shenzhua/" + action;
}



mixed hit_ob(object me, object victim, int damage)
{
  

        int lvl = me->query_skill("claw"),attack,lb;
        attack=lvl/100;
        if(attack>=4) attack=4;
          	attack=random(attack);
        if(attack<=1) attack=1;
        lb = random(10);
       
 if( !me->query_temp("9ysz/auto")  )
   	
   	{  

 		 if(  lb> 7 ||  me->query_temp("sz3j")==1 ) 
          {
                message_vision(HBBLU "����$n�����Ѿ�������δ��֮ʱ��$N���س�϶���������ֻ��ţ���ָ����$nͷ����" NOR,me,victim);
                victim->start_busy(random(4));
                         me->set_temp("9ysz/auto", 1);
                         me->add_temp("apply/damage",  me->query_skill("jiuyin-shenzhua", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
                        me->add_temp("apply/damage", -me->query_skill("jiuyin-shenzhua", 1)/6);
                        me->delete_temp("9ysz/auto");
                        victim->apply_condition("no_perform", 2+ random(2));

         }
 
   else if(  lb> 5 ||  me->query_temp("sz3j")==2 ) 
 {
        	message_vision(HBRED "$N��ת�˼������������һ�����ֱ۱��ǣ�ָצ��̽�����˸�������ĺ��⣬��׼$n������͵Ĳ�����ȥ��" NOR, me,victim);
        	victim->start_busy(random(2));
                   me->set_temp("9ysz/auto", 1);
                         me->add_temp("apply/damage",  me->query_skill("jiuyin-shenzhua", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
                        me->add_temp("apply/damage", -me->query_skill("jiuyin-shenzhua", 1)/6);
                        me->delete_temp("9ysz/auto");

        }

   else if( lb>3 || me->query_temp("sz3j")==3 )
{
        	message_vision(HBMAG "$N������ˣ�˫��ָ�׼������͵���$n�ĺ���ץȥ���ۿ�һ�����֮�±�Ҫš��$n�ĺ�����" NOR,me, victim);
                    	victim->start_busy(random(attack+1));
                      me->set_temp("9ysz/auto", 1);
                         me->add_temp("apply/damage",  me->query_skill("jiuyin-shenzhua", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
                        me->add_temp("apply/damage", -me->query_skill("jiuyin-shenzhua", 1)/6);
                        me->delete_temp("9ysz/auto");
 
}

}

}
