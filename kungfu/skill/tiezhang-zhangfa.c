// tiezhang-zhangfa �����Ʒ�
// BY BOBO@SJ 
// Update By lsxk@hsbbs 2007/5/15

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action": "$N����һ������һ�С��ƴ����¡��������Բ����������򣬵�ʱ��$n��������б������һ�ӣ�����$p$l",
	"lvl": 0,
	"damage_type": "����",
	"skill_name": "�ƴ�����"
]),
([
	"action": "$Nʹһ�С���ˮ���������ұ�ͻ��ץ��$n�����ƶ�Ȼ�����쳤���ұۣ��ɿ��һ��������ն��$n��$l",
	"lvl": 20,
	"damage_type": "����",
	"skill_name": "��ˮ����"
]),
([
	"action": "$NͻȻʹһʽ�����ƻ��衹��˫��������һ��һ����裬����һ����ת�����ˣ�����һ�ƣ�ѹ��$n",
	"lvl": 40,
	"damage_type": "����",
	"skill_name": "���ƻ���"
]),
([
	"action": "$Nһ�С�����Ǭ������һ���ĳ��Ժ��͵ز���������ұ��������¼���������Ĵ������ָ��Ȧ�͵�$n��$l",
	"lvl": 60,
	"damage_type": "����",
	"skill_name": "����Ǭ��"
]),
([
	"action": "$Nһ�С����ո��¡�������һ��һ�գ�һ����˿��������һ��֮�䣬һ�������ޱȵ������Ŷ�Ȼ����",
	"lvl": 80,
	"damage_type": "����",
	"skill_name": "���ո���"
]),
([
	"action": "$N���б���һʽ������Ϊ������˫�ƺ���г�����Ե�ŵݳ������غ�Х֮������������֮�����ɴ˶���",
	"lvl": 100,
	"damage_type": "����",
	"skill_name": "����Ϊ��"
]),
([
	"action": "$Nһ�С����޵����������ƴ�Ȧ����������СȦ�������������������һ��֮�£��޴���ھ�ѹ��$n��$l",
	"lvl": 120,
	"damage_type": "����",
	"skill_name": "���޵���"
]),
([
	"action": "$Nһ�С���ָ��ɽ������һ�����������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ��գ�˫����һ��ȥ���绢",
	"lvl": 140,
	"damage_type": "����",
	"skill_name": "��ָ��ɽ"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
	int i, level, j;
	string msg;

	level = me->query_skill("tiezhang-zhangfa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);      
			if ( me->query_temp("tz/heyi")) {
				switch(me->query_temp("tz/heyi")){
					case 3: msg = HIB"$NͻȻ����һ�Σ��۽�$n������һ�����������������������$p����ֱ�Ķ���"NOR; break;
					case 2: msg = HIR"������$N����һת������$n���ԣ�����˳���ĳ�����һ�п���ƽ�ͣ�ʵ���ں�����������ޱ�"NOR; break;
					case 1: msg = HIW"���$N��һ�����������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ��գ�˫����һ��ȥ���绢"NOR; break;
					default : msg = HIB"$NͻȻ����һ�Σ��۽�$n������һ�����������������������$p����ֱ�Ķ���"NOR; break;
				}
				me->add_temp("tz/heyi", -1);
				return ([
					"action": msg,
					"force": 250 + random(350),
					"parry": random(20)+10,
					"dodge": random(20)+10,
					"damage": 50 + random(100),
					"damage_type": "����"
				]);
			}
                   if (me->query_temp("tzzf")){
                     if (me->query_temp("tiezhang")){
                       me->add("neili", -500);
                           return ([
                                   "action" : BLU+action[j]["action"]+NOR,
                                   "force" : 400 + random(400),
                                   "damage": random(100)+80,
                                   "dodge": action[j]["dodge"]+random(20),
                                   "parry": random(20)+10,
                                   "lvl" : action[j]["lvl"],
                                   "damage_type" : action[j]["damage_type"],
                           ]);
                           }
                          else {
 				return ([
					"action" : WHT+action[j]["action"]+NOR,
 					"force" : 350 + random(350),
 					"damage": random(100)+50,
 					"dodge": action[j]["dodge"]+random(20),
 					"parry": random(20)+10,
					"lvl" : action[j]["lvl"],
 					"weapon" : "����",
					"damage_type" : "����",
				]);
                         }
                     }
			if( random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("tiezhang-zhangfa", 1)) > 100 
			 &&( me->query_skill("yingou-bifa") > 100 || me->query("max_pot",1) >450 )
			 && !random(3)
			 && me->query("neili") > 30 
       && me->query("quest/tzauto/over") == 1   
			 && !me->query_temp("tz/heyi")) {
				me->add("neili", -20);
				return ([
					"action": HIW"$N���������絶�����������縫��$n���мܲ�Ͼ������$N��ʽһ������ָ�繳��ȴ�������ʷ��е�һ�У�"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
           "damage": 160 +random(140),
					"damage_type": "����"
				]);
			}

                        if (random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("tiezhang-zhangfa", 1)) > 100 
			 && (me->query_skill("liuye-daofa") > 100 || me->query("max_pot",1) >450 )
			 && !random(3)
			 && me->query("neili") > 30 
       && me->query("quest/tzauto/over") == 1
			 && !me->query_temp("tz/heyi")) {
				me->add("neili", -20);
				return ([
					"action": HIR"$N��Ȼ�����絶����ʽһ�䣬�õ�ȴ����Ҷ�����е�����һ�ƵĹ���"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
                                        "damage": 120 +random(100),
					"damage_type": "����"
				]);
			}
                        if (random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("tiezhang-zhangfa", 1)) > 100 
                         && (me->query_skill("lietian-fu") > 100 || me->query("max_pot",1) >320)
			 && !random(3)
       && me->query("quest/tzauto/pass") == 1
			 && me->query("neili") > 30 
			 && !me->query_temp("tz/heyi")) {
				me->add("neili", -20);
				return ([
					"action": HIY"$N��Ȼ������Σ�����ȴ������������������һ�Ѵ󸫣�����һ����ͷ��$n���£�ȴ��һ�С����ն����"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
                                        "damage": 140 +random(100),
					"damage_type": "����"
				]);
			}

                   if (me->query_temp("tiezhang")) {
                           me->add("neili", -300);
                          return ([
                                   "action": CYN + action[j]["action"] + NOR,
                                   "lvl": action[j]["lvl"],
                                   "damage_type" : action[j]["damage_type"],
                                   "force":300+random(350),
                                   "dodge":random(30)-10,
                                   "parry":random(20),
                                   ]);
                               }
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":200+random(350),
				"dodge":random(30)-10,
				"parry":random(20),
			]);
		}
	}
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʒ�������֡�\n");
	if ((int)me->query_skill("force", 1) < 35)
		return notify_fail("����ڹ���򲻹����޷��������Ʒ���\n");
	if ((int)me->query("max_neili") < 40)
		return notify_fail("�������̫�����޷��������Ʒ�");
	return 1;
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tiezhang-zhangfa", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������Ʒ���\n");

	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiezhang-zhangfa/" + action;
}



mixed hit_ob(object me, object victim, int damage)
{
  

        int lvl,attack,lb;
        lvl= me->query_skill("tiezhang-zhangfa",1) +  me->query_skill("lietian-fu",1) +  me->query_skill("liuye-daofa",1) + me->query_skill("yingou-bifa",1);
        lvl = lvl/4;
        lb = random(10);
       
 if( !me->query_temp("tzrh/auto") && userp(me)&& me->query("quest/tzauto/over") )
   	
   	{  

 		 if(  lb> 7 &&  me->query_temp("tiezhang") ) 
          {
                message_vision(HBBLU "$N�似������Ƿ��켫֮���������似�������ģ�һ˫���ƻ����򿳻�㣬ʹ�ľ�Ȼȫ�ǳ����е���ʽ!" NOR,me,victim);
                victim->start_busy(random(2));
                         me->set_temp("tzrh/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lietian-fu", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lietian-fu", 1)/6);
                        me->delete_temp("tzrh/auto");
                        victim->apply_condition("no_perform", 2+ random(2));

         }
 
   else if(  lb> 5 &&  me->query_temp("tiezhang") ) 
 {
        	message_vision(HBRED "������������������$N���ұ��죬������׷�ʹ򣬲������ݣ�" NOR, me,victim);
        	victim->start_busy(random(2));
                   me->set_temp("tzrh/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("liuye-daofa", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("liuye-daofa", 1)/6);
                        me->delete_temp("tzrh/auto");

        }

   else if( lb>3 || me->query_temp("tiezhang") )
{
                message_vision(HBMAG "$N���һ����ƽ����ѧɲ�Ǽ��ڻ��ͨ�����������ĳ�һ�ơ�" NOR,me, victim);
                    	victim->start_busy(random(attack+1));
                      me->set_temp("tzrh/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("yingou-bifa", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("yingou-bifa", 1)/6);
                        me->delete_temp("tzrh/auto");
 
}

}

}
