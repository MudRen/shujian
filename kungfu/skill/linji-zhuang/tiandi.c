// Modified by Lane@SJ 2005/4/14

#include <ansi.h>
int exert(object me)
{
if( !me->is_fighting() )
return notify_fail("��������ô�У������������˰ɡ�\n");

if( (int)me->query_skill("linji-zhuang", 1) < 60 )
return notify_fail("����ڹ���Ϊ��������\n");

if( (int)me->query_skill("medicine", 1) < 60 )
return notify_fail("��ı���������Ϊ��������\n");

if( (int)me->query("neili") < 200 )
return notify_fail("�������������\n");

if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
return notify_fail("û���ˣ���ʲô�˰���\n");

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3/10 ) // ��Ϊ30%����
return notify_fail("���Ѿ����˹��أ����ܲ��������𵴣�\n");

if( me->query_temp("ljz/wuwo") )// �ĳ� ���ܺ� wuwo ͬʱʹ��
return notify_fail("�����������ټ�ʮ��ׯ�ġ����ҡ��־���\n");

message_vision(HIW"$N��������˿�������ɫ�����ö��ˡ�\n"NOR,me);
me->receive_curing("qi", (int)me->query_skill("force")/3);
me->add("neili", -100);
me->start_exert(1,"���");
me->start_busy(random(2));
return 1;
}
string exert_name(){ return HIW"����־�"NOR; }

int help(object me)
{
        write(HIW"\n�ټ�ʮ��ׯ������־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 200 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 60 ���ϣ�
                �������� 60 ���ϣ�
                ���ܺ͡����ҡ��־�ͬʱʹ�á�
HELP
        );
        return 1;
}
