// yuxue-dunxing.c ��ѩ����
// by iceland

inherit SKILL;

string *dodge_msg = ({
"$nһ�С�����С���˫��ƽ�죬����һ�����Ľ��󵹷���ȥ��\n",
"$n��״��ϥ�������ֳŵأ�ʹ��һ�С���Ǳ����˫��һ�㣬��һ���$NҸ�´��˹�ȥ��\n",
"$nƽ�ش���һ�����磬һ�С��귭����Ծ���ڿ��м��������$N���������������Ρ�\n",
"$nбб�ĵ��˼�����ͻȻ̽����$N����һ����ʹ��һ�С�ӥǧ����Ѿ���$Nͷ��Խ����\n",
"$nʹ��һ�С����Ρ���������ҡ�Ұڣ�Ʈ�����������º����·���$N������ȴ��֮���壬һһ��ա�\n",
"$n������Х��˫���ڵ���һ�ģ���������֮�£�һ�С���Ѳ���������\n",
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me)
{
	if ( me->query_skill("longxiang-boruo", 1) < 10 )
		return notify_fail("�������������ȼ���������\n");
	return 1;
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ�������ϰ��ѩ���Ρ�\n");
	me->receive_damage("jingli", 25);
	return 1;
}
