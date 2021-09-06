#include <ansi.h>

inherit SKILL;

mapping *action = ({
([ "action": "$N����һ�ݣ�Ծ�ڰ�գ�һʽ���ʷ����ࡹ������$w�������£������鶯֮��������$n$l",
   "dodge": -5,
   "damage":30,
   "force": 100,
   "lvl" : 0,
   "skill_name" : "�ʷ�����",
   "damage_type":  "����"
]),
([ "action": "$N���绬��������$wһ����һʽ�����չ�᡹��Ѹ���ޱȵطִ��������࣬$n��ʱ����֧穣������ֽ�",
   "dodge": 5,
   "damage":50,
   "force": 150,
   "lvl" : 20,
   "skill_name" : "���չ��",
   "damage_type":  "����"
]),
([ "action": "$N������ע��$w�����ʹ��һʽ������Ϸ���$w��ز���裬ֱ�������ƿ�һ�����$n",
   "dodge": 10,
   "damage":80,
   "force": 200,
   "lvl" : 40,
   "skill_name" : "����Ϸ��",
   "damage_type":  "����"
]),
([ "action": "$Nһ����Х������$wһ�С����ɷ��衹�����������Ӱ����ǵص���$n�������Ƶ�����֮��",
   "dodge": -10,
   "damage":110,
   "force": 250,
   "lvl" : 60,
   "skill_name" : "���ɷ���",
   "damage_type":  "����"
]),
([ "action": "$N��¶΢Ц��ǰһ��������$w�������ʹ��һʽ��������项������ƽ������������˿������",
   "dodge": 1,
   "damage":130,
   "force": 300,
   "lvl" : 80,
   "skill_name" : "�������",
   "damage_type":  "����"
]),
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;
return notify_fail("�����ҼҴ��书,�������̵�! \n");

       if( (int)me->query("max_neili") < 100 )
               return notify_fail("����������㣬û�а취��ϰ�޷�, ����Щ���������ɡ�\n");

       if ((int)me->query_skill("force") < 40)
               return notify_fail("����ڹ����̫ǳ��\n");

       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("���������һ�����Ӳ������޷���\n");

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
       level   = (int) me->query_skill("qingxu-bian",1);
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
       if ((int)me->query_skill("force") < 100)
               return notify_fail("����ڹ����̫ǳ��\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("�����������������޷���\n");
       me->receive_damage("jingli", 15);
       return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weap,weap1;
        weap = victim->query_temp("weapon");
		weap1 = me->query_temp("weapon");

                if( (me->query_skill("qingxu-bian") > 60) && (me->query("neili") > 100)
                         && (victim->query_temp("weapon")) 
                         && random(10)>5)
                  {
						 message_vision(HIY "ֻ��$N���ٻ���" + weap1->name() + "��ת����������СȦ�ӣ�������֮����ס�Է���" + weap->name() +"��\n" NOR, me );	
				//		 message_vision(HIY "�������ϡ���һ����$N���е�" + weap->name()
                //               + "��"+weap1->name()+"����ס��\n" NOR, victim );
                         victim->start_busy(1);
						 if (random(me->query_str()) > victim->query_str()/2 )
                        {     	
				        message_vision(HIY "$N�����ֱ�����һק��" + weap->name()
                                + "ȴ�޷���"+weap1->name()+"�Ĳ������ѿ����鼱֮��ֻ�÷��������еı��С�\n" NOR, victim );
                        weap->move(environment(me));
						victim->reset_action();
						} else {
						message_vision(HIY "$N�����ɾ���" + weap->name()
                                + "˳�ŷ��������ת���£��⿪��"+weap1->name()+"�Ĳ��ơ�\n" NOR, victim );
                        victim->add("neili",-50);
						}
						me->add("neili", -50);
                 }
				       return 1;

      
}

string perform_action_file(string action)
{
               return __DIR__"qingxu-bian/" + action;
}

