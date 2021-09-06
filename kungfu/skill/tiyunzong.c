// tiyunzong.c ������
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
"ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
"$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
"$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n",
"����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	if ( me->query_skill("yinyun-ziqi", 1) < 10)
		return notify_fail("����������ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ������������ݡ�\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{       
	return __DIR__"tiyunzong/" + action;
}
