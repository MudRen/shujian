//��ɥ�굶����sanghun-dao.c

/*
ɥ�굶������ף�����ƫ�棬���˷���ʤ������ƫ�������ޱȣ�
���־������顣
��ͷ�ӵ���ִ˵������ش������
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "�����ɢ",
                "action":
CYN"$N����һ��ŭ������"+"$w"+CYN+"�����������$n�ĵ�ȫ������һ�С������ɢ��"+NOR,
                "dodge":                15,
		"parry":		-10,
                "damage":               30,
                 "lvl":0,
                "damage_type":  "����"
        ]),
        ([      "name":                 "Թ���޳�",
                "action":               
WHT"$N����һת�������ɫ��һ�С�Թ���޳���ʹ��������"+"$w"+WHT+"���񹴻���������$n�����ڵ���"+NOR,
                "dodge":                -15,
		"parry":		-20,
                "damage":               50,
                "lvl":12,
                "damage_type":  "����"
        ]),
       ([      "name":                 "��ҹ�׺�",
                "action":
HIM"$N�趯"+"$w"+HIM+"һ����Ц��һ�С���ҹ�׺���ʹ��, ��������ͻȻ��ʢ�����ŵ���׹����$n��$l"+NOR,
                "dodge":                10,
		"parry":		0,
                "damage":               60,
                 "lvl":25, 
                "damage_type":  "����"
        ]),
        ([      "name":                 "��Ұ�·�",
                "action":
YEL"$N��¶�������飬����"+"$w"+YEL+"ȴ����һ�ӣ�������ӳ֮�¸��Ե�������죬����Ұ�·ء�"+NOR,
                "dodge":                -10,
		"parry":		-10,
                "damage":               80,
                 "lvl":40,  
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
HIG"$N����һת������"+"$w"+HIG+"ͻȻ��ת�Ե����������������̲ҵ�֮�⣬\nһ�С��������硹����ɭɭ��������$n$l"+NOR,
                "dodge":                -5,
		"parry":		0,
                "damage":               90,
                 "lvl":55,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
BLU"$N�����﷢��һ�����У���ü���ţ�����"+"$w"+BLU+" �趯��糵��£��޼᲻�ݵ�ƬƬ������ס$n ȫ�����ǡ�����������"+NOR,
                "dodge":                5,
		"parry":		-20,
                "damage":               95,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("dulong-dafa") < 50 )
        return notify_fail("��Ķ�������Ϊ����������ѧϰɥ�굶����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ���������ɥ�굶����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
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
    level   = (int) me->query_skill("sanghun-dao",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("jingli") < 50)
   return notify_fail("�������������ɥ�굶����\n");
    me->receive_damage("jingli", 35);
    return 1;
}



void skill_improved(object me)
{
    if( -(int)me->query_skill("sanghun-dao", 1)  * 100 <me->query("shen")) {
                tell_object(me,
                  RED "\n��ͻȻ����ɱ���޷����ƣ�һ���Ļ�ֱ���Ժ�....\n\n" NOR);
          me->unconcious();
        }
      }

