// taxue-wuhen.c̤ѩ�޺� 
inherit SKILL;

string *dodge_msg = ({
"$nһʽ������ƽɳ�����������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ�ԡ�\n",
"$nһʽ���������𡹣������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
"$nһʽ���������ڡ���������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
"$nһʽ�����ɵ��ҡ���ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
"$nһʽ����ѩ��̲�����ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
"$nһʽ����˿���꡹��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
"$nһʽ��������ѩ�������в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
"$nһʽ������ǱԾ������Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
"$nһʽ��̤ѩ�޺ۡ������μ�����ת�����¾ͻ�������֮�⡣\n",
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me)
{
	if ( me->query_skill("xuantian-wuji", 1) < 10)
		return notify_fail("��������޼����ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ�������̤ѩ�޺ۡ�\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{       
return __DIR__"taxue-wuhen/" + action;
}
