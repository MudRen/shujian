//taiji-jian's perform tongshou(���ͬ��)
//looklove 2000-10-23 VS yuj ���ͬ��ʧ�ܣ���������

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
string msg;

  if(environment(me)->query("quest") || environment(me)->query("no_death"))           return notify_fail("��ѽ��С�����ﲻ��ʹ��Ŷ��\n"); 
if( !objectp(target) ) target = offensive_target(me);

if( !objectp(target)
 || !target->is_character()
 || !me->is_fighting(target) || !living(target)
 || !target->is_killing(me->query("id"))
 || environment(target)!=environment(me))
    return notify_fail("�������޷�ʹ�����ͬ�١�\n");

if (!objectp(weapon = me->query_temp("weapon")) 
|| (string)weapon->query("skill_type") != "sword")
return notify_fail("��ʹ�õ��������ԡ�\n");
      
       if((int)me->query_temp("special_die")) 
             return notify_fail("��ѽ��С�����ﲻ��ʹ��Ŷ��\n"); 

if((int)me->query_skill("taiji-jian", 1) < 200 )
    return notify_fail("���̫��������������������ʹ�����ͬ�پ��У�\n");

if((int)me->query_skill("yinyun-ziqi", 1) < 200 )
    return notify_fail("����������������ߣ�����ʹ�����ͬ�پ��У�\n");

if((int)me->query_skill("sword", 1) < 200 )
    return notify_fail("��Ľ���������죬ʹ����̫�����ľ��У�\n");

if (me->query_skill_mapped("sword") != "taiji-jian")
    return notify_fail("������Ƚ�̫���������ڽ���֮�в��С�\n");

if(me->query_skill_mapped("parry") != "taiji-jian")
    return notify_fail("������Ƚ�̫�����������м�֮�в��С�\n");

if((int)me->query("max_neili") < 2000 )
    return notify_fail("��������Ϊ���㣬ʹ�������ͬ�٣�\n");

if( (int)me->query("neili") < (int)me->query("max_neili")*2/3 )
    return notify_fail("�������������㣬ʹ�������ͬ�٣�\n");

if( (int)me->query("jingli") < me->query("eff_jingli")/2 )
    return notify_fail("�����ھ������㣬ʹ�������ͬ�٣�\n");

msg = HIW "\nֻ��$N����ƴ���򷨣�����"+weapon->name()+HIW"����һ�٣����˴���ֱ��$n��ȥ��\n"+
"$n����������һ������ӱ���ס$N��$N˳�����֮�ƣ��ؽ������Լ�С����ȥ��\n"+
HIR"\n��һ������׳�ң�����"BLINK+HIY"�����ͬ��"HIY"��\n"NOR;

message_vision(msg, me, target);

if (random(me->query("combat_exp")) > target->query("combat_exp")/4
 && random(me->query_dex(1)) > target->query_dex(1)/3 ){
msg = HIR"\n$N�������������һ�����Լ������崩͸��"+weapon->name()+HIR"�Ӻ󱳴���������$n��С����"+
"\n$n��ɫ��㵣�¶���������ŵı��飬��ǳ鶯�˼��£�������Ѫ���������ء�\n"NOR;
message_vision(msg, me, target);
target->set_temp("last_damage_from","��"+me->query("name")+"�����ͬ��ɱ");
me->set_temp("last_damage_from","��"+target->query("name")+"ͬ���ھ��ˡ�");
target->die();
me->die();
return 1;
}
msg = HIG"\n$n�ų�һ���亹����ǧ��һ��֮�ʻ�æ���֣��͵�һ��������ȥ��Զ��\n"NOR;
message_vision(msg, me, target);
me->set_temp("last_damage_from","�����ͬ���Ծ�");
me->die();
return 1;
}

string perform_name(){ return HIW"���ͬ��"NOR; }

int help(object me)
{
        write(HIW"\n̫������֮�����ͬ�١���"NOR"\n\n");
        write(@HELP
        ��������ͤΪ�����˼���ܽ��������̹�����ʹ����ƴ��������Զ
        ѷ������ֻ�������ͬ���ھ�����ʯ��ٵ��������ѱ����������֣�
        �����ֹ����������Լ�С���жԴ�������Է�Ҫ����

        Ҫ��  ��ǰ����������������� 2/3;
                ������� 2000 ���ϣ�
                ̫�������ȼ� 200 ���ϣ�
                �������ȼ� 200 ���ϣ�
                ���������ȼ� 200 ���ϣ�
                ��������Ϊ̫��������
                �����м�Ϊ̫��������
                �����ڹ�Ϊ��������

        ˵����  ��������ɱ����ң�ֻ�е����˶�����kill��ʱ�����ʹ�á�
                Ч��һ��ս��˫����ͬ���ھ���
                Ч������ս��ʧ�ܣ��Լ��������������˼�����á�

HELP
        );
        return 1;
}
