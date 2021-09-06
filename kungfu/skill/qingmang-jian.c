// qingmang-jian.c ������(��)��

inherit SKILL;

string *dodge_msg = ({
"�ƺ�$Nÿһ�ж�����$n������������$n���ǻ򷴴򡢻����ܣ�һһ��⿪ȥ��\n",
"ȴ��$nһ��ͷ����$N����������ȥ��������Ƹ���$n���ұۡ�\n",
"��֪$n����һ�ϣ��������ɵرܹ���$N�Ĺ�����\n",
"$n�������㣬����$N����һ�С�Ҷ�׷��ࡹ����Ϊ�ء�\n"
});

string  *msg = ({
"$Nˢˢˢ�������У�ʹ�����������š�������$w������������������һ�㣬��֪Ҫ����δ�",
"$N�������ˣ�����һ�У�$wֱ��$n���ţ��Ƶ�$n��æ��ͷ����",
"$N�������$nС����һɨ���뽫$n�赹������$wһ������ָס$n�ʺ�",
"$Nһ����Ц������$wӭ�濳�£�ֱ��$n$l",
"$Nһ�³嵽$n��ǰ��ͻȻ֮��γ�$w������$nͷ�Ͽ�����ȥ",
"$NͻȻһ�°�$w�ӻ�������ͻ���������ж����ǿ켫��$nȫ�����ܵ���ԣ",
"$N$wͦ����һ�С����߳���������$n������ȥ���Ƶ����Ǿ���",
"$N���������ã���$wȦת������$n$l",
"$Nһ�С��������š���$w�����ޱȵ���$n��$l"
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry" 
	|| usage == "dodge" || usage == "blade" 
	|| usage == "axe" || usage == "dagger"
	|| usage == "hook";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":	msg[random(sizeof(msg))],
                "damage":	60 + random(100),
		"damage_type":	random(2)?"����":"����",
		"dodge":	random(30),
		"force":	150+random(300),
		"parry":	random(30),
        ]);
}

string query_dodge_msg(object weapon)
{        
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	return notify_fail("NPC�书��������ҿ��š�\n");
}
