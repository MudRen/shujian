// shuishangpiao.c 
// BY BOBO@SJ

inherit SKILL;

string *dodge_msg = ({
"$n���һ֧��ȫ�������һ�С����㵹�����������ܳ����࣬�����$N�Ĺ�����\n",
"$n�����Ȼ�����޹ǣ�����ҡ�ڣ�ʹ��һ�С����ƯƼ�����ܹ���$N�Ĺ�����\n",
"$nʹ�����ﻻ���ơ���������һ��ת����$N���Բ����������������$N���\n",
"$nһ�С���Ҷ��硹��������һƬ��Ҷһ��Ʈ�˳�ȥ������֮������Ѹ�ٵ��˼�����\n"
});

int valid_enable(string usage) 
{ 
	return usage == "dodge";
}

int valid_learn(object me)
{
	if ( me->query_skill("guiyuan-tunafa", 1) < 10)
		return notify_fail("��Ĺ�Ԫ���ɷ��ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ�������ˮ��Ư��\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shuishangpiao/" + action;
}
