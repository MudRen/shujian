// huashan-shenfa.c ��ɽ��

inherit SKILL;

string *dodge_msg = ({
"$nһʽ���������᡹��ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ\n",
"$nһʽ��������ϼ����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
"$nһʽ���໲���������㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
"$nһʽ��ȴ����ɡ���һת��䣬����˷�Ʈ����������$n����Ӱ����$N������롣\n",
"$nһʽ�����ճ�������ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
"$nһʽ�������ա��������������������ݷ����У���$Nͷ����Ծ������\n",
"$nһʽ���������¡���˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
"$nһʽ���������Ρ������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
    if ( me->query_skill("zixia-gong", 1) < 10 && me->query_skill("huashan-qigong", 1) < 10)
		return notify_fail("�����ϼ���ȼ�̫���ˡ�\n");
	return 1;
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if (me->query("jingli") < 30 )
		return notify_fail("�����ڵľ���̫���ˣ�������ϰ��ɽ����\n");
	me->receive_damage("jingli", 25);
	return 1;
}
