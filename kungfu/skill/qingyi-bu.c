// qingyi-bu.c �������²�
// Created by snowman@SJ 06/03/2001

inherit SKILL;
 
string *dodge_msg = ({
  	"ֻ��$n˫��һ�㣬���ӷ����ۼ��޷��ܿ��Ĺ�������Ȼ��$n���˿�ȥ��\n",
  	"$n����һŤ������$N��ʽ֮�����˹�ȥ������ǵ������õġ�����������\n",
  	"$n��һ��ƮȻ�ݳ��������ŵء�\n"
  	"����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
  	"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
  	"$N������ǰ��Ӱһ����$n�Կ�����׵����Ѿ�Ʈ�˿�ȥ��\n",
  	"ȴ��$n�㲻��أ�����Ծ�����ߣ����˿�ȥ��\n",
  	"$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) 
{ 
    	return usage == "dodge"; 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 30 )
            	return notify_fail("�������̫���ˣ��������������²���\n");
        me->receive_damage("jingli", 20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qingyi-bu/" + action;
}

