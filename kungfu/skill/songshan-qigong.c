// songshan-qigong.c ��ɽ����

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
       if ((int)me->query_skill("force", 1) < 10)
               return notify_fail("��Ļ����ڹ���򻹲�����\n");

       return 1;
}

int practice_skill(object me)
{
       if((int)me->query_skill("songshan-qigong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("songshan-qigong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ�����������ɽ�����ˡ�\n");       }
        else return notify_fail("�����ڵ���ɽ������Ϊֻ����ѧ(learn)�������������ȡ�\n");

}

string exert_function_file(string func)
{
       return __DIR__"songshan-qigong/" + func;
}
