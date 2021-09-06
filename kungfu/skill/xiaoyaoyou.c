// xiaoyaoyou.c
// rebuild by Lklv

inherit SKILL;

string *dodge_msg = ({
"$n����Ծ��һ�������ѵ�ˮ�����о����յض����$N��һ�С�\n",
"$n���һ�ݣ�ʹ��һ�С�ϸ���ɷ��ơ����պñܹ���$N�Ĺ�����\n",
"$nʩչ����ң������ʹ�����黳���ȡ���ǡ�ö����$N�Ĺ��ơ�\n",
"$nĬ����ң��Ҫ����ʹ����������ڤ������Ծ������$N�Ĺ��ơ�\n",
"$nһʽ��ŭ���ɡ��������������߸߰�����������$N�����\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge");
}

int valid_learn(object me)
{
	if ( me->query_skill("huntian-qigong", 1) < 10)
		return notify_fail("��Ļ��������ȼ�̫���ˡ�\n");
	if (me->query_skill("dodge", 1) < 10)
		return notify_fail("��Ļ����Ṧ���������޷�ѧϰ��ң�Ρ�\n");
	return 1;
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ���������ң�Ρ�\n");
	me->receive_damage("jingli", 25);
	return 1;
}
