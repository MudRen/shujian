// longfeng-xiang.c ����˫��

inherit SKILL;

string *msg = ({
"$nͻȻ�εض����ڿ���һ��һת���ɵ�$N���ʵ���䵱�����������ݡ���ͬ������֮�\n",
"$n�������ǣ�һ�С�����ʽ������Ծ�����ˣ�ԶԶƮ�˿�ȥ��\n",
"$n���˸������ͷ�������ƣ�ȴ��˫��Ӷ���������󻬳���\n",
"$nһ�������˫�ɡ�����������$N�Ĺ�������Ʈ�𣬴��ݶ����һ�С�\n",
"$nʹ��һ�С���ﴩ�ơ����ż�һ�㣬���Ӱθ����࣬���$N���˸��ա�\n",
"$n����һҡ���ó���������Ӱ��һ�С����񳯷�����$N�Ĺ��ơ�\n",
"$nһ�С��ɷ����衹����Ծ���ڿ���һת��ٿ��������$N���\n",
"$n��һҡ����һ�Σ�һ�С��Ʒ���ˡ�����������$N�Ĺ�����\n",
"ȴ��$n������˳��$N����ʽ�û����������š����չ�᡹һת�㵽��$N�����\n",
"$n��������һ�ǣ������������������ɸߣ��ƿ���$N����ʽ��\n",
"$n˫�����ģ�һʽ�����ɾ��졹Ծ�����ɸߣ�ԶԶƮ�˿�ȥ��\n",
"$n��������������һʽ��������������������$N�Ĺ�����Χ��\n",
"$nһ�С�����������������һ�䣬���ŵ���ƽƽ������\n"
});

int valid_enable(string usage) 
{ 
  return usage == "dodge" || usage == "parry"; 
}

int valid_learn(object me) { return 1; }
mapping query_action(object me,object weapon)
{
        return ([
            "action":msg[random(sizeof(msg))],
            "dodge":10+(random(me->query_dex())),
        ]);
}
string query_dodge_msg(object me)
{
  return msg[random(sizeof(msg))];
}
string query_parry_msg(object weapon)
{
  return msg[random(sizeof(msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("�������̫���ˣ�������ϰ����˫�衣\n");
        me->receive_damage("jingli", 35);
        return 1;
}