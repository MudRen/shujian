// Skill: Emei-JianFa.c ��ü����
// Date:  AHA 97/06/24

inherit SKILL;

mapping *action = ({
(["action" : "$N���ֽ������бָ������$w���˸�������һ�С���ʽ�ֽ𡹣�����"
             "$n��$l",
  "force" : 200,
  "dodge" : 25,
  "skill_name" : "��ʽ�ֽ�",
  "lvl" : 0,
  "damage" : 60,
  "damage_type" : "����"
]),
(["action" : "$N��ϥ΢�����ҽ���ǰ������΢����һ�С�˳ˮ���ۡ�������$n��$l",
  "force" : 220,
  "dodge" : 30,
  "skill_name" : "˳ˮ����",
  "lvl" : 9,
  "damage" : 70, 
  "damage_type" : "����"
]),
(["action" : "$N���ֽ�ָ����������䣬���ὣ��һ�С������Ὥ�������Ͷ��ϣ�"
             "$w����$n��$l",
  "force" : 240,
  "dodge" : 35,
  "skill_name" : "�����Ὥ",
  "lvl" : 19,
  "damage" : 80,
  "damage_type" : "����"
]),
(["action" : "$N��ǰ����һ����һ�С������������$w������ʮ��$w��ͻȻ�����"
             "�ش���$n��$l",
  "force" : 270,
  "dodge" : 25,
  "skill_name" : "�������",
  "lvl" : 29,
  "damage" : 90, 
  "damage_type" : "����"
]),
(["action" : "$N�������⣬һ�С�������ɽ����$w���϶��»��˸��뻡��������˸��"
             "ֱ��$n��$l",
  "force" : 300,
  "dodge" : 30,
  "skill_name" : "������ɽ",
  "lvl" : 39,
  "damage" : 100, 
  "damage_type" : "����"
]),
(["action" : "$N����һ�䣬ת��$n���������$w����Ҹ�´�����һ�С���б��᡹"
             "������$n��$l",
  "force" : 340,
  "dodge" : 40,
  "skill_name" : "��б���",
  "lvl" : 49,
  "damage": 120,
  "damage_type" : "����"
]),
(["action" : "$N�ҽŵŵ���������$w�ڿ������һ�佣����һ�С�ɳ�ݳ�������"
             "����$n��$l",
  "force" : 380,
  "dodge" : 50,
  "skill_name" : "ɳ�ݳ���",
  "lvl" : 59,
  "damage": 140,
  "damage_type" : "����"
]),
(["action" : "$N����$w�������ң��������������ξ��£�һ�С�����С�ȡ�������"
             "$n�ľŴ���Ѩ",
  "force" : 420,
  "dodge" : 60,
  "skill_name" : "����С��",
  "lvl" : 69,
  "damage": 160,
  "damage_type" : "����"
]),
(["action" : "$N������ע�뽣������$w�ó����콣Ӱ��һ�С�ǧ�徺�㡹������"
             "ɽ����֮�ƣ�����$n��$l",
  "force" : 460,
  "dodge" : 50,
  "skill_name" : "ǧ�徺��",
  "lvl" : 79,
  "damage" : 180,  
  "damage_type" : "����"
]),
(["action" : "$N˫���ս���ֻ����$w�����������·�����������֮����һ�С���"
             "��⡹������$n��$l",
  "force" : 600,
  "dodge" : 45,
  "skill_name" : "�𶥷��",
  "lvl" : 99,
  "damage" : 210, 
  "damage_type" : "����"
])
});

int valid_enable(string usage) 
  { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
  if ((int)me->query_skill("emei-jiuyang", 1) < 40)
     return notify_fail("��Ķ�ü���������̫ǳ���޷�������Ķ�ü������\n");
  if ((int)me->query("max_neili") < 300)
     return notify_fail("��ü��ѧ������Ϊ�������������̫���ˡ�\n");
  if ((int)me->query_skill("jinding-mianzhang", 1) < 50)
     return notify_fail("ѧϰ��ü������Ҫ��ʵ�Ļ�������\n"
                        "��Ľ����ƻ��̫ǳ���޷�������Ķ�ü������\n");
  if ((int)me->query("shen") < 4000)
     return notify_fail("�����������̫�ͣ����ܴ��ڶ�ü������\n");
  if ((int)me->query("combat_exp") < 15000)
     return notify_fail("���ʵս����̫��޷�������Ķ�ü������\n");
  return 1;
}

string query_skill_name(int level)
{
  int i = sizeof(action);

  while (i--)
    if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
  int i, level, max_neili;
  float factor;
  mapping act;

  level = (int) me->query_skill("emei-jianfa",1);

  for(i = sizeof(action); i > 0; i--)
     if(level > action[i-1]["lvl"]){
        act = action[NewRandom(i, 20, level/5)];
        max_neili = me->query("max_neili") - 400;
        if(max_neili > 100){ 
           factor = sqrt(sqrt(((float)max_neili)/100.0));
           act["force"] = (int)((float)act["force"]*factor);
           act["dodge"] = (int)((float)act["dodge"]*factor);
           act["damage"]= (int)((float)act["damage"]*factor);
        }
        return act;
     }
}

int practice_skill(object me)
{
  object weapon;

  if (!objectp(weapon = me->query_temp("weapon")) || 
       (string)weapon->query("skill_type") != "sword")
	  return notify_fail("��ʹ�õ��������ԡ�\n");
  if(me->query_skill("emei-jiuyang")*2 < me->query_skill("emei-jianfa")*3)
    return notify_fail("��Ķ�ü����������㣬�޷�����ü������\n");
  if((int)me->query("qi") < 100)
    return notify_fail("���������������ü������\n");
  if((int)me->query("neili") < 100)
    return notify_fail("����������㣬��������ü������\n");
  if((int)me->query("jingli") < 50)
    return notify_fail("��ľ���̫���ˣ�������ϰ��ü������\n");
  me->receive_damage("qi", 50);
  me->receive_damage("jingli", 30); 
  me->add("neili", -20);
  return 1;
}

string perform_action_file(string action)
{
  return __DIR__"emei-jianfa/" + action;
}
�
