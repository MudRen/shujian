//jinshe-zhangfa.c
// ����auto ���ܳɹ������ʹ�� by daidai
#include <ansi.h>

inherit SKILL;
#include <combat_msg.h>
#include <combat.h>

mapping *action = ({
([
	"action": "$Nʹһ�С����߳�������˫����ڣ��������߳���Ʈ�Ʋ�������$n$l",
        "lvl" : 0,
        "damage_type": "����"
]),
([
	"action": "$Nʹһ�С�������ˮ����˫��΢�������У�������������$n��$l",
        "lvl" : 20,
        "damage_type": "����"
]),
([
	"action": "$NͻȻ΢һ����һ�С�����ͦ����˫�ƻ���$n��$l",
        "lvl" : 40, 
        "damage_type": "����"
]),
([
	"action": "$Nٿ������$n��ǰ��һ�С����߹�����ֱ��$n��$l",
        "lvl" : 60,
        "damage_type": "����"
]),
([
	"action": "$N������$nһת��һ�С����߲�����$n$l��������",
        "lvl" : 70, 
        "damage_type": "����"
]),
([
	"action": "$N���ΰ����ڰ��һ�С�������ء������ͻ�$n��$l",
        "lvl" : 80, 
        "damage_type": "����"
]),
([
	"action": "$Nʹһ�С����߷��ڡ�����������˫�ƽ���ֱ��$n��$l",
        "lvl" : 90,
        "damage_type": "����"
]),
([
	"action": "$Nһ�����ʹ�����߿�ʺ硹���ó�������Ӱ�����Ʋ���$n��$l",
        "lvl" : 100,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");
	if ((int)me->query_skill("strike", 1) < 60)
		return notify_fail("��Ļ���������������ѧϰ���������ơ�\n");
	if( !me->query("jinshe/zhangfa"))
		return notify_fail("���޷���ϰ���������ơ�\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷������������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("jinshe-zhangfa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
    if ( me->query("quest/���߽���/pass") ){  
    if (me->query_temp("jsj"))  
                        return ([
                             "action":       YEL+action[j]["action"]+NOR,
                             "lvl":          action[j]["lvl"],
                            "damage_type":  action[j]["damage_type"],
                             "force":        350 + random(250),
                            "dodge":        10+random(30),
                           "parry":        10+random(30),
                    ]);
 else                         return ([ 
                               "action":       CYN+action[j]["action"]+NOR,
                              "lvl":          action[j]["lvl"],
                           "damage_type":  action[j]["damage_type"],
                             "force":        300 + random(200),
                            "dodge":        10+random(20),
                          "parry":        10+random(20),
                     ]);
                  }
else  
			return ([
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150 + random(300),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}
void lianji(object me, object victim)
{
     if (!me || !victim || !me->is_fighting(victim))
           return;

   if( me->query("quest/���߽���/pass")
    && me->query("neili") > 500 
   && !me->query_temp("weapon")
    && !me->is_busy()
   && !me->query_temp("jsj")){
            message_vision(HIW"\n����$Nٿ��ٿ�ˣ�����������˫����ڣ��������߳������Ʈ�ƣ�"NOR, me);
           me->set_temp("jsj", 1);
           me->add_temp("apply/strike", me->query_skill("jinshe-zhangfa", 1)/4);
          COMBAT_D->do_attack(me, victim, 0, random(3)?1:3);
           if (me->is_fighting(victim)) 
                COMBAT_D->do_attack(me, victim, 0, random(2)?1:3);
            me->add_temp("apply/strike", -me->query_skill("jinshe-zhangfa", 1)/4);
          me->delete_temp("jsj");
  }
  }

  mixed hit_ob(object me, object victim, int damage_bonus, int factor)
 {
           int ap, dp, pp, exp1, exp2;
      if(!me->query("quest/���߽���/pass"))            return 0;

      if(me->query("neili") < 600
      || me->query("max_neili") < 2500
      || me->query_skill("jinshe-zhangfa", 1) < 200 
      || me->query_temp("jsj")) 
                return 0; 
                ap = COMBAT_D->skill_power(me,"strike",SKILL_USAGE_ATTACK);
                dp = COMBAT_D->skill_power(victim,"dodge",SKILL_USAGE_DEFENSE);
                pp = COMBAT_D->skill_power(victim,"parry",SKILL_USAGE_DEFENSE);
                    exp1 = (int)me->query("combat_exp",1);
                    exp2 = (int)victim->query("combat_exp",1); 
        if(random(ap+dp)>dp/3 && random(ap+pp)>pp/3 && random(exp1) > exp2/3){
         if(random(2)) {
         message_vision(HIY"$N˫��΢�䣬˫�ƽ��������������а�����$p���߲�����\n"NOR, me, victim);
        if( !victim->is_busy() )    
           victim->start_busy(2 + random(2));
          }
          else           call_out((: lianji :), 1, me, victim);
 }
 }

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("��̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
