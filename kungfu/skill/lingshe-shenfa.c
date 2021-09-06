//Cracked by Roath
// lingshe-shenfa.c ������
// ywz Oct 28, 1996

inherit SKILL;

mapping *action = ({
([      "action" : "$n����ǰ�㣬��ǰ�������ߣ�һʽ�����߳�������ʱ�ܿ���$N���������ơ�\n",
        "dodge"  : 10
]),
([      "action" : "$n΢һ��ͷ�����������ӹ������ɵ�һʽ�����в��ߡ���������$N�Ĺ��ơ�\n",
        "dodge"  : 20
]),
([      "action" : "$nһʽ���������š���������Ȼ������������$N��ͷ����\n",
        "dodge"  : 30
]),
([      "action" : "$n��ͷ����һʽ�����߰�β������������һŤ����$N�Ĺ��ƻ������Ρ�\n",
        "dodge"  : 40
]),
([      "action" : "$nʹ����������ա����������Ҽ��ٻζ����ó�������Ӱ�����ݵ��ƽ�$N�Ĺ��ơ�\n",
        "dodge"  : 50
]),
([      "action" : "$nһ�С����߹鳲�����ڿն��������������䵽һ�ԡ�\n",
        "dodge"  : 60
]),
([      "action" : "$n��ЦƮ��ʹ����������Ƥ��������ͻȻһ������ƮƮ�ش�$N��Ҹ�´�����\n",
        "dodge"  : 70
]),
([      "action" : "$n����ͽȻһ�Σ�һ�С�Ⱥ�����衹����Ϊ������������$N��ת��ʹ���޴����֡�\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
	level   = (int) me->query_skill("lingshe-shenfa");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*

        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("��ľ���̫���ˣ���������������\n");
	me->receive_damage("jingli", 20);
        return 1;
}
