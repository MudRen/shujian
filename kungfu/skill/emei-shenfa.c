// Skill: Emei-ShenFa.c ��ü��
// Date : AHA 97/06/22

inherit SKILL;

string *dodge_msg = ({
  "ֻ��$nһ�С����ذδС����������ϱ�ֱ���������࣬�����$N��һ�С�\n",
  "$nһ�С�������֡�������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
  "$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
  "����$nһ�С����ն�����������Ʈ��������һ�ݣ����ѱܿ���\n",
  "$nһ�С�Ӱ�����ơ���������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
  "����$nʹ��������޳���������һ�ã�$N��һ�����˸��ա�\n",
  "ȴ��$n�㲻��أ�һ�С���ȥ���⡹�����Դܿ����ߣ����˿�ȥ��\n",
  "$nһ�С�������ҡ�������΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) 
  { return usage == "dodge"; }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 30 )
      return notify_fail("�������̫���ˣ���������ü����\n");
   me->receive_damage("qi", 20);
   return 1;
}
