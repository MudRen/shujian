// Skill: Emei-JiuYang.c ��ü������
// Date : AHA 97/06/22

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
  int level = (int)me->query_skill("emei-jiuyang", 1);
  int changquan = (int)me->query_skill("emei-changquan", 1);
  
  int t = 1, j;
  for (j = 1; j < level / 10; j++) t *= 2;

  if ( me->query("gender") == "����" )
     return notify_fail("��ü�����������Ǻ�Ȼ�������Թ����޸�����֮��
                         ����޵ã�\n");

  if ((int)me->query_skill("force", 1) < 10)
     return notify_fail("��Ļ����ڹ���򻹲�����\n");

  if ( changquan < 20 ) 
     return notify_fail("��Ķ�ü��ȭ��Ϊ̫�ͣ��޷������ü��������\n");  

  if (level > 10 && (int)me->query("shen") < t * 100) 
     return notify_fail("�����������̫���ˡ�\n");

  return 1;
}

int practice_skill(object me)
{
  return notify_fail("��ü������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
  return __DIR__"emei-jiuyang/" + func;
}

�