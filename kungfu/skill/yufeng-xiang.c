// yufeng-xiang.c �����

inherit SKILL;

string *dodge_msg = ({
    "$nһ�������˫�ɡ�����������$N�Ĺ�������Ʈ�𣬴��ݶ����һ�С�\n",
    "$nʹ��һ�С���ﴩ�ơ����ż�һ�㣬���Ӱθ����࣬���$N���˸��ա�\n",
    "$n����һҡ���ó���������Ӱ��һ�С����񳯷�����$N�Ĺ��ơ�\n",
    "$nһ�С��ɷ����衹����Ծ���ڿ���һת��ٿ��������$N���\n",
    "$n��һҡ����һ�Σ�һ�С��Ʒ���ˡ�����������$N�Ĺ�����\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge" || usage == "move") ;
}

int valid_learn(object me) 
{ 
  if ( me->query("gender") != "Ů��")
               return notify_fail("����ô����ѧŮ�ӵ��书����\n");
   return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 35 )
            return notify_fail("�������̫���ˣ�����������衣\n");       
		me->receive_damage("jingli", 25);
        return 1;
}
