inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
 "$n���Ų�æ��һʽ��"+HIR+"��ˮ����"+NOR+"��������ٿ����һ��ƽ������,���������$N�Ĺ��ơ�\n",
"$n��������Ȱ�һ�Σ�ɲ�Ǽ���Զȥ����֮�⣬$N��ʱ���˸��ա�\n",
"$n���к��ļӿ죬��һ�����̰�����$N�ɿ���ת������$Nһ��ͷ���ۻ���\n��æ����������\n",
"ֻ��$n�������һ����һ�С�"+RED+"����º�Ӱ"+NOR+"�����󵴶�������һ�ԡ�\n" ,
"$n�����һЦ�����к��ı�����ʲ��壬$N��������ʽ��Ȼ͸�������ԭ������һ�߻�Ӱ��\n",
"$n�����ж�ʱ�������һ����������$N����ʽ���Ұڶ�����ʹ��$N������ա�\n",
});
int practice_level(){   return 150;  }
int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me)
{
if (me->query_skill("dodge", 1) <=me->query_skill("wudu-yanluobu", 1))
return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
 return 1;
}
string query_dodge_msg(string limb,object me)
{
//:me->add_temp("apply/dodge",me->query_skill("wudu-yanluobu",1)/3);
return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
if( (int)me->query("qi") < 40 )
return notify_fail("�������̫���ˣ��������嶾���ܲ���\n");
me->receive_damage("qi", 20);
return 1;
}
int valid_effect(object me, object weapon, string action_name, int skill)
{
message_vision("�������̫���ˣ��������嶾���ܲ���\n",me);
}
string perform_action_file(string action)
{
return __DIR__"wudu-yanluobu/" + action;
}
