// tianlong-xiang.c ������
//COOL@SJ
inherit SKILL;

string *dodge_msg = ({
"$n˫�����ģ����Ӻ������죬�����������裬�˽����ƣ��紵����������ͻȻ���ϰ�գ�����һ�����ߣ�ԶԶ��Ʈ�˿�ȥ��\n",    
"$n��������һ�ǣ��ڿ�Ծ�����һ�󲽾Ϳ��$N���Ϸ������ȵ�����$N�ĺ��棬$N����ס���˸��ʣ���һ�С�����ɡ���\n",
"����$n���ڰ�գ�����һ����������������������˫���������£�ʹһ�С��������졹�����β�����׹������ԽƮԽ�ߡ�\n",
"$NͻȻһ�л�����$n����ܲ�����һ�ƻ���������$N�ľ����������������ԶԶ�Ķ��˿�ȥ��\n",
"$n˫���ַ��߳�������˳������������һʽ��������������������$N�Ĺ�����Χ��\n",
"$nһ�С������ĺ���������һ��һŤ�����ŵ���ƽƽ����,$N��ǰ��Ӱһ�Σ�ʧȥ��$n����Ӱ��\n",
"$n��Хһ����ʹһ�С��������������ڿն���һ���紵����$n˫������������裬������һ����ƣ�Խ��Խ�ߡ�\n",
"$nѸ�ٽ���������ӭ��һչ������̤�ն����ڷ���ƮƮȻȻ���У��������С��������¡���\n",
});

int valid_enable(string usage) 
{ 
	return usage == "dodge"; 
}

int valid_learn(object me)
{
	if (!me->query_skill("kurong-changong", 1))
	if ( me->query_skill("qiantian-yiyang", 1) < 10)
		return notify_fail("���Ǭ��һ�����ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ�������ϰ�����衣\n");
	me->receive_damage("jingli", 25);
	return 1;
}
