// piaoyi-shenfa.c Ʈ����

inherit SKILL;

string *dodge_msg = ({
"$n������Ȼ������󻬳����࣬��������������ס�Կ�Ѹ���ڵ��ַ���󳶶�һ�㡣\n",
"$n˫ϥ�����������䣬��Ȼ����������֮��Ӳ�ֹ�ֺͽ�ʬ���졣\n",
"����$n����̧�ţ�ͻȻ֮�䵹�����࣬һת����������֮�⡣\n",
"ֻ���ú���һ����$n���ӱ�ֱ������з���ֱ������ߣ��������һ�С�\n",
"$n��Ȼ���ΰ����ڿ��м�����������ת�ĸ�Ȧ�ӣ���ת���ߣ�һ��ת����������֮�⡣\n",
"$n����Ȧ�ӣ���ת�������������㣬�ڼ䲻�ݷ�֮�ʶ�������С�\n",
"$n���һ�����������ܣ����ʹ����������б�ɶ��ϣ���ʱ�Ķ������һ�С�\n",
"$n����һ�����̣���һ������һ������תһȦ����תһȦ�������˿�ȥ��\n"
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me)
{
	if( !me->query_skill("jiuyang-shengong", 1))
	if ( me->query_skill("shenghuo-shengong", 1) < 10)
		return notify_fail("���ʥ���񹦵ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg(object me)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ�������Ʈ������\n");
	me->receive_damage("jingli", 25);
	return 1;
}
