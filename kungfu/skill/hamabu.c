// hamabu.c ��󡲽

inherit SKILL;

string *dodge_msg = ({
       "ֻ��$n˫��һ��һ�ǣ�һ�±����ϸߣ������$N�Ĺ�����\n",
       "$n����ͻȻһ������ֻ���һ������������$N����ʽȫ�����ڿմ���\n",
      "$n˫��һ������~��~������������£�ԶԶ�ض��˿�ȥ��\n",
       "$n�嵽$N��ǰ��ҧ�����죬һ��Ҫƴ�������ӣ��ŵ�$N��æ�˿�������\n",
       "$n�ͺ�һ����˫����ǰһ�ƣ���������Ʈ�˿�ȥ��\n",
       "$n��������ļ��ƣ���������Ļҳ����Լ����ƶ����$N��һ�С�\n"
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("�������̫���ˣ���������󡲽��\n");
        me->receive_damage("jingli", 30);
        return 1;
}
