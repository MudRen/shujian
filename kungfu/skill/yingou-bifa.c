//yingou-bifa.c �����ʷ�
// BY BOBO@SJ 
inherit SKILL;

string  *msg = ({
"������ӿ���죬$N��Хһ����$wֱ���������������ǽ���â����ʸӦ��������Ͼ�����粻���ɣ���һֱ���ǡ��桹�ֵ����һ��",
"$N˳��ʹ�����졹�ֵ�һ�࣬$w��$n��$lɨ��",
"$Nת��������$w�ͳ���ȴ�ǡ��¡��־���һֱ����$n���Ļ���",
"$Nһ�����ֲ������������ף�$w��������ƽƽ��ɨ������$n��̫��Ѩ�������ǡ������־��е�һ��",
"$N����$w�����Ͻ�б�����½ǣ�ɨ��$n�����ߡ���һ���ǡ������־���һƲ��",
"$N����ֱ���������е�$w���һ�㣬д�ɡ����������һ�ʣ�һ�����$n��������Ѩ",
"$N��������$n����һ����һ�������������ɵ��ڿ���һ����������Զ������һ�����ǡ��䡹�־��е�һ���꡹��\n����ν�������������Ѹ��ɣ���Σ�ƽڣ������ڻ�������ǧ��һ��֮�ʣ�תΣΪ��",
"$N����$w���ӣ�����ʹ��һ�ǡ������־������ƴ�ס$n��һ�ǹ��ƣ�$w��һƲ��$n$lһ�㣬���ӽ��ƴ���",
"$N�����㣬�������磬���������ٿ����ʹ���������־��е�һ��������$n��$l",
"$Nһ�С������־��е�һ��ֱ������$w�ڰ���м�������������$n��̫��Ѩ",
});

int valid_enable(string usage)
{
    	return usage == "brush" || usage == "parry";
}

mapping query_action(object me, object weapon)
{         
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+3)*40,
                "damage_type":random(2)?"����":"����",
                "dodge":random(20)-random(20),
                "force":random(200)+100,
        ]); 
}

int practice_skill(object me)
{    
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "brush")
                return notify_fail("��ʹ�õ��������ԡ�\n");
       	if ((int)me->query("jingli") < 50)
               return notify_fail("��������������йٱʷ���\n");         
       	if ((int)me->query("neili") < 30)
               return notify_fail("��������������йٱʷ���\n");
       	me->receive_damage("jingli", 35);
       	me->add("neili", -10);
       	return 1;
}

int valid_learn(object me)
{
       int skill = me->query_skill("yingou-bifa", 1);
       if ((int)me->query("max_neili") < 1500 )
               return notify_fail("�������������\n");
       if ((int)me->query_skill("guiyuan-tunafa", 1) < (skill-60))
               return notify_fail("��Ĺ�Ԫ���ɷ����̫ǳ��\n");
       if ((int)me->query_skill("literate", 1) < 150 )
               return notify_fail("��Ķ���д�ּ���̫�ͣ��޷�����鷨�����\n");      
       return 1;
}

string perform_action_file(string action)
{
      	return __DIR__"yingou-bifa/" + action;
}
