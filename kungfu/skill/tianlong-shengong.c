inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{       
        
        int i, l;             
        i = (int)me->query_skill("qiantian-yiyang", 1);       
        l = (int)me->query_skill("buddhism", 1);       

   if (!me->query("tls"))
        if ((i >= 10 && (int)me->query("shen") < i * 5) ||
            (i >= 50 && (int)me->query("shen") < i * 8) ||
            (i >= 100 && (int)me->query("shen") < i * 10))
        return notify_fail("���������������ɣ��������������������������\n");

        if (i > 10 && i < 150 && l < i - 10)
        return notify_fail("��ķ�ѧ��Ϊ����������ֹ������еĺ�ʤ֮���ˣ�\n");

        if (me->query_skill("force", 1) < 20)
                 return notify_fail("��Ļ����ڹ���򻹲������޷����Ǭ��һ������\n");

        if (i > 99 && (string)me->query("gender") != "����")
                 return notify_fail("�㲻�Ǵ���֮���޷������߲��Ǭ��һ������\n");

        if ( 
           me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("guiyuan-tunafa",1)
        || me->query_skill("xixing-dafa",1)
        )
        return notify_fail("Ǭ��һ�������ɺ�а���ڹ���Ϊһ�壿\n");

        return 1;
}


int practice_skill(object me)
{
            return notify_fail("Ǭ��һ����ֻ����ѧ(learn)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"qiantian-yiyang/" + func;
}
