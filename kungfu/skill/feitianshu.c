// feitianshu.c ������
inherit SKILL;
string *dodge_msg = ({
"$n����һ�Σ�����һŤ��һ�С��������ܡ������ض���\n",
"$nһ�С����й��ȡ���$Nֻ����ǰһ����������$n����Ӱ��\n",
"$nһ�С�������졹������΢�Σ��о����յرܿ���$N��һ�С�\n",
});

string query_dodge_msg(object me)
{	
	return dodge_msg[random(sizeof(dodge_msg))];

}

int valid_enable(string usage)
{ 
	return usage == "dodge"; 
}

int valid_learn(object me)
{ 
	return 1; 
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 45 )
		return notify_fail("�������̫���ˣ���������������\n");	
	me->receive_damage("jingli", 35);	
	return 1;
}
