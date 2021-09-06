// Skill: Emei-ChangQuan.c ��ü��ȭ
// Date : AHA 97/06/22

inherit SKILL;

mapping *action = ({
(["action" : "$N�������أ���ȭ���ƺ���ȭ��ӣ�ͬʱ����ǰ�����Ƴ���"
               "һ�С�����ʽ������$n���ؿ�",
  "force" : 80,
  "dodge" : 20,
  "skill_name" : "����ʽ",
  "damage_type" : "����"
]),
(["action" : "$N�����鶯��ʹ��һ�С�ǧ���ȡ����ҽŽż⹴�����$n��$l",
  "force" : 100,
  "dodge" : 15,
  "skill_name" : "ǧ����",
  "damage_type" : "����"
]),
(["action" : "$N������ȭ������������ȭǰ�壬һ�С����Ĵ�������$n���ؿ�",
  "force" : 110,
  "dodge" : 10,
  "skill_name" : "���Ĵ�",
  "damage_type" : "����"
]),
(["action" : "$N����һ�䣬˫ȭ�͵ش������϶���һ�С�����֡�����$n��$l",
  "force" : 120,
  "dodge" : 15,
  "skill_name" : "�����",
  "damage_type" : "����"
]),
(["action" : "$N�����³�����ס������ʹ����˳��ȭ������ȭ��ѹ����ȭ����$n��$l",
  "force" : 130,
  "dodge" : 20,
  "skill_name" : "˳��ȭ",
  "damage_type" : "����"
]),
(["action" : "$N��ϥ΢�����ҽŵ���һ�С����½š�������ͬʱ����$n��$l",
  "force" : 140,
  "dodge" : 25,
  "skill_name" : "���½�",
  "damage_type" : "����"
]),
(["action" : "$Nһ��������$n�Ĺ���������һ�С������ҡ���˫ȭ����·"
             "ͬʱ����$n��$l",
  "force" : 150,
  "dodge" : 15,
  "skill_name" : "������",
  "damage_type" : "����"
]),
(["action" : "$N����һ�䣬ת��$n�����һ�С������֡�����ȭ�û�$n��$l",
  "force" : 160,
  "dodge" : 25,
  "skill_name" : "������",
  "damage_type" : "����"
]),
(["action" : "$N��ŵŵ�����һ�С���ֳ᡹��˫ȭ���ƣ��ֱ����$n��$l",
  "force" : 140,
  "dodge" : 15,
  "skill_name" : "��ֳ�",
  "damage_type" : "����"
]),
(["action" : "$N��ס���Σ�������Σ�һ�С���ɽȭ������ȭ��ǰ�ͻ�$n��ͷ��",
  "force" : 170,
  "dodge" : 10,
  "skill_name" : "��ɽȭ",
  "damage_type" : "����"
]),
(["action" : "$N�͵������������$n�ҽ�֮ǰ��һ�С�����β������ȭ˦�����"
             "$n��$l",
  "force" : 160,
  "dodge" : 20,
  "skill_name" : "����β",
  "damage_type" : "����"
]),
(["action" : "$N��΢��������ȭ����һ�С�����ȭ����˫ȭ��磬����������"
             "����$n��$l",
  "force" : 180,
  "dodge" : 30,
  "skill_name" : "����ȭ",
  "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
  if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
     return notify_fail("����ü��ȭ������֡�\n");
  return 1;
}

string query_skill_name(int level)
{
  return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
  int max_neili;
  float factor;
 
  mapping act = action[random(sizeof(action))];
  max_neili = me->query("max_neili");
  if(max_neili <= 100) return act;
  factor = sqrt(sqrt((float)max_neili/100.0));
  act["force"] = (int)((float)act["force"]*factor);
  act["dodge"] = (int)((float)act["dodge"]*factor);
  return act;
}

int practice_skill(object me)
{
  int level;
  if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
     return notify_fail("����ü��ȭ������֡�\n");
                  
  if((int)me->query("qi") < 30)
     return notify_fail("�������̫���ˡ�\n");

  level = (int)me->query_skill("emei-changquan", 1)/10;
  if(level >= 3){
    if((int)me->query("neili") < 20)
       return notify_fail("���������������ü��ȭ��\n");
    me->add("neili", -8);
  }
  me->receive_damage("qi", 20);
  return 1;
}

string perform_action_file(string action)
{
  return __DIR__"emei-changquan/" + action;
}
�
