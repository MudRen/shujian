// /kungfu/skill/qingshen-fa
// by dubei
// ��������

inherit SKILL;

string *dodge_msg = ({
           "$nʹ��һ�С������ƿա������嶸ת��������Ʈȥ��\n",
           "$nʹ��һ�С������羵����˫����Ȼ���ϵ���Ծ�����֮�С�\n",
           "$nʹ��һ�С����ա�������һ�䣬����$N���\n",
            "$n���һ����ʹ��һ�С��󰲿ա�����$Nͷ��Խ����\n",
            "$nʹ��һ�С���ա���������Ʈȥ��˲��������$N��ǰ��\n",
             "$nʹ��һ�С���տա�����ʱ$N��Χ����$n����Ӱ��\n",
 });


 
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 50 )
                return notify_fail("�������̫���ˣ�����������������\n");
        me->receive_damage("jingli", 30);
        return 1;
}

string perform_action_file(string action)
{       
               return __DIR__"qingshen-fa/" + action;
}
