// zhaixingshu.c ժ����

inherit SKILL;

string *dodge_msg = ({
"$nһ�С�����ժ�ǡ��������ڿգ��ܹ���$N�Ĺ�����\n",
"$n����һԾ���ɹ�$N��ͷ���������$N�Ĺ��ƣ�����һ�С�ƮȻ��������\n",
"$nʹ��������ʳ�ա���һ��������ǡ�ö����$N�Ĺ�����\n",
"$nһ����Х��ʹ�����Ӷ�ʨ�𡹣���$N��ɫ����ʱԶԶ�����˿���\n",
"$nһ�С�������Ȼ�����ͺ�һ����ͻȻ������һ�ϣ��ܹ���$N�Ĺ��ơ�\n",
});

int valid_enable(string usage) 
{ 
	return usage == "dodge"; 
}

int valid_learn(object me)
{
	if ( me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("��Ļ����󷨵ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ�������ժ������\n");
	me->receive_damage("jingli", 25);
	return 1;
}
