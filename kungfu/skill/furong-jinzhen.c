// furong-jinzhen ܽ�ؽ���
// By lius 99/07

inherit SKILL;
#include <ansi.h>

string  *msg = ({
"ֻ��$N����һ�ӣ�һʽ���޿ײ��롹���ƹ�һ����û��$wֱ��$n�Ŀյ������˽�ȥ��",
"$NͻȻ״�Ƴտ��������裬�������ʱ��ʱ����һö$w����$n����ʤ��������һ��[�޷�����]��",
"$N���һ��������һ�ССһö$w�����ź�Х�������������ȴ������Ϣ����$n��$l����һ$w������һ��[ǰ����ӵ]��",
"$nͻ��$N˫�ֽ���ӳ�,���͹���,��ö$wٿ��ٿ��ٿǰٿ���ֱ��Ҫ������,ȴ��һ��[��С�޲�]��",
"$N΢һת��˫�����ӣ�ʹ��һ��[��������]��$w����������$n���š�",
"$N�������һʽ��ܽ�ػ���������ö$w��Ʒ���ͷɳ�������ܽ�ػ���,���컨������$n�������ҪѨ��"});

int valid_enable(string usage)
{
        return usage == "throwing" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
      int i, j, p;      
      i = random(me->query_skill("throwing"))+50;
      if(i<120) i = 120;
      j = random(me->query_skill("furong-jinzhen"))+40;
      if(j<120) j = 120;
      p = ((int)me->query_skill("force",1))/3 + me->query_con();
      if(p>100) p=100;
      if(me->query_temp("zhen/powerup") >= 1){
        me->add_temp("zhen/powerup", -1);               
        return ([
                "action":WHT"$NͻȻ����һ��,���Ծ������ȥ���ȼ������ڿ����������߳����ȣ��漴��������
�������ݰ����������������������ͻȻ��$N���Ϸ���������⣬�罵�����
��â���ɡ������������߿Х����$n������һƬ��ɫ����֮�С�\n"NOR,
                "damage":(i+j)/2+random((int)me->query_con())+60,
                "damage_type": "����",
                "dodge": random(10)+40,
                "force": random(120)+(i+j)/2+p,
		   "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
                ]);
}

	if(random(5) > 3 && me->query_skill("furong-jinzhen", 1) > 200 && random(me->query_dex()) > 26 ) 
              me->add_temp("zhen/powerup", 1);

      return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+1)*60,
                "damage_type":random(2)?"����":"����",
                "dodge":random(30),
                "force":random(150)+100,
                "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
                ]);

      
}

int practice_skill(object me)
{
       object weapon;
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("�������������ϰܽ�ؽ��롣\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}

int valid_learn(object me)
{
	mapping fam  = me->query("family");
	if (fam["family_name"] != "�䵱��" || fam["generation"] != 16 )
          return notify_fail("���๦������ͶԵ�������ǲ������״��ڵİɡ�\n");
	if ((int)me->query("max_neili") < 500)
          return notify_fail("�������������\n");
       if ((int)me->query_skill("yinyun-ziqi", 1) < 80)
          return notify_fail("�����������Ϊ̫ǳ���޷���ϰ�˼���\n");
          return 1;
}
string perform_action_file(string action)
{
       return __DIR__"furong-jinzhen/" + action;
}

