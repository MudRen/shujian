// anying.c

inherit SKILL;
 
string *dodge_msg = ({
"ֻ��$nһ�С�������硹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
"$nһ�С�������֡�������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
"$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n",
"����$nһ�С����ն�����������Ʈ��������һ�ݣ����ѱܿ���\n",
"$nһ�С�Ӱ�����ơ���������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
"����$nʹ��������޳���������һ�ã�$N��һ�����˸��ա�\n",
"ȴ��$n�㲻��أ�һ�С���ȥ���⡹������Ծ�����ߣ����˿�ȥ��\n",
"$nһ�С�������ҡ�������΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) 
{ 
	return usage == "dodge";
}

int valid_learn(object me)
{
	if ( me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("����ټ�ʮ��ׯ�ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ���������Ӱ���㡣\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"anying-fuxiang/" + action;
}

