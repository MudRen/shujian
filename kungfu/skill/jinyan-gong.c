// jinyan-gong.c ���㹦
// Modified by action@SJ 2008/09/15


inherit SKILL;
 
string *dodge_msg = ({
"$n΢һ����������ǰһ�ݣ�һʽ�������Ϸɡ������赭д�ض��$N��һ����\n",
"$nһʽ����ȥ�޺ۡ����������ƮȻ���ˣ�$Nһ�����У�$n����������֮�⡣\n",
"$n�鲽ǰ�磬�Ų����Ƿ�λ������������⣬һ�С���ת���ơ���Ȼ�Ƶ�$N���\n",
"$n΢΢һЦ���㲻�������ڣ�һʽ������̫�项�����̰�ȽȽ���𣬻���$N��ࡣ\n",
"$n����ͻ�䣬ʹ����Ⱥ�ǲ��á���Χ��$N�Ĵ����߶�ʱ�û���������Ӱ��$NĿ���۴���֪����δ���\n",
"$n���������ݰ㼱����ת������һ�С���ճ�������$N�Ĺ���ͳͳ���⡣\n",
"$nһʽ����Ӱ���С�������ƮƮ������$N�����ƶ�������$N��֮��$n��ƮȻ������\n",
"$nʹ���������ݡ����嶷Ȼ����Խ��Խ�ߣ�����΢һת����������֮�⣬��$N�Ĺ��ƾ����������Σ�\n"
});
int valid_enable(string usage) 
{ 
	return usage == "dodge";
}

int valid_learn(object me)
{
	if ( me->query_skill("xiantian-gong", 1) < 10)
		return notify_fail("������칦�ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("�������̫���ˣ����������㹦��\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinyan-gong/" + action;
}