// duanjia-quan.c �μ�ȭ��
// update by cool@SJ,990605

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ�����׳�н��������һ̽�����ִ�����ȭ�״���������$n��ȥ",
          "skill_name" : "���׳�н",
        "damage_type" : "����"
]),
([      "action" : "$N��Ц����һʽ������չ�᡹������Ӳ���������أ����ֶ���$n$l�������",
          "skill_name" : "����չ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����಻������ȭ�Ƴ�����ȭ������������ȭһ���أ��ּ�����ȭ������֮��",
         "skill_name" : "���಻��",
        "damage_type" : "����"
]),
([      "action" : "$N�����ÿ���һʽ�����ҷ�Դ�����������϶���б�ӣ�����һ��������$n����",
          "skill_name" : "���ҷ�Դ",
        "damage_type" : "����"
]), 
([      "action" : "$Nһ��������һʽ����ˮ���ۡ�������$n���˹�������������һȭ������$n��$l",
          "skill_name" : "��ˮ����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���μ�ȭ��������֡�\n");
          if ((int)me->query_skill("qiantian-yiyang", 1) < 20)
                return notify_fail("���Ǭ��һ������򲻹����޷�ѧ���μ�ȭ����\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����μ�ȭ����\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                   return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level,a;
        level   = (int) me->query_skill("duanjia-quan",1);
        if (level>100) a=100;
		      else a=level;
     if (( (int)me->query_skill("cuff") >= 120 ) 
      && ( (int)me->query("neili") >= 500 )
      && (me->query_skill_prepared("cuff") == "duanjia-quan")
      && random(10)>7 ) {
                return ([
                "action": "$N��ȭһ�Σ��漴��ȭ������������˫ȭ��������ǰ������������ʮ�������磬�ۻ�����֮����",
                "parry":(int)me->query_skill("parry")/8,
                "dodge":(int)me->query_skill("dodge")/6,
                "force":level*2,
                "damage_type": "����"
  ]);
        }
        for(i = sizeof(action); i > 0; i--) {
        return ([
                "action":action[NewRandom(i, 20, level/5)]["action"],
                "damage_type": action[NewRandom(i, 20, level/5)]["damage_type"],
                "dodge": random(20)-random(20),
                "force": 100+a+random(170),
                "parry": 10+random(20),
                "skill_name" : action[NewRandom(i, 20, level/5)]["skill_name"],
                ]);
       }
}
int practice_skill(object me)
{
        int lvl = me->query_skill("duanjia-quan", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������μ�ȭ����\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

