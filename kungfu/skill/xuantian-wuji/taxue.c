// �����޼�-̤ѩ�޺�
// ��̤��ѩ���޺�
// modify by cmkj 2003.8.19
// update���ӷ�Ծ��Ч��
#include <ansi.h>
void remove_effect(object me,int count);

string exert_name() {return HIY"̤ѩ"NOR;}

int exert(object me)
{                               
        int improve;
      
        if( !me->is_fighting() && (int)me->query_skill("xuantian-wuji",1)<350 )
                return notify_fail("������ֻ����ս����ʹ�á�̤ѩ����\n");

        if( (int)me->query_skill("xuantian-wuji",1) < 100 )
                return notify_fail("��������޼�����������죬����ʹ�á�̤ѩ����\n");

        if (me->query_skill_mapped("force") != "xuantian-wuji")
                return notify_fail("����ڹ����ԣ�����ʹ�á�̤ѩ����\n");
      
        if((int)me->query("max_neili")<1000)
                return notify_fail("���������Ϊ̫��������ɡ�\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if( me->query_temp("kl/taxue")   )
                return notify_fail("������ʹ�á�̤ѩ����\n");

        if( me->query_temp("kl/riyue")   )
                return notify_fail("������ʹ�á������޼�����\n");
      
        message_vision(CYN"$N˫���鰴���������Ծ������������������շ��У�" +
        "ƮȻ���ɣ�\n" NOR, me);
      
        improve = (int)me->query_dex();
    if( me->query_skill("xuantian-wuji",1)<=350 )    me->start_perform(1,"��̤ѩ��");
        me->add_temp("apply/dodge", improve);
        me->add_temp("apply/dexerity", improve);
        me->set_temp("kl/taxue",improve);  
        me->add("neili", -(350-(int)me->query_skill("xuantian-wuji",1)/10));            
        call_out("remove_effect", 1, me, improve);
        return 1;
}

void remove_effect(object me,int count)
{
         int improve;
         if( !me ) return;
         if( !intp(improve = me->query_temp("kl/taxue"))) return;
         if( count < 1){
          me->add_temp("apply/dodge", - improve);
          me->add_temp("apply/dexerity", -improve);
          me->delete_temp("kl/taxue");
          tell_object(me, HIY"��ɢȥ����ۼ��������������˽Ų������ظ���������\n"NOR);
          tell_room(environment(me), HIY + me->name()+"���ص��ɢȥ������Ĺ�����\n"NOR,  ({ me })); 
          return;
        }
        call_out("remove_effect", 1 , me ,count -1);
}

int help(object me)
{
        write(WHT"\n�����޼�����̤ѩ���־���"NOR"\n");
        write(@HELP
        �����޼�������Ϊ�����ɾ����ڹ��ķ����ˡ�̤ѩ�����ɺ������Ծ������������������֮�ƽ���֮ʱ��
        ���Բ������κ����壬��ƾ�����ڿ��д�һ��������������θߣ��������٣������������ϴ����ʮ�ɡ�
        ���ķ�һ��ʹ�����ɴ���������Ṧ������������æ��ʱ�ܼ�����������ܵ��˺���

        Ҫ��  ̤ѩ�޺۵ȼ� 120 ���ϣ�
                �����޼��ȼ� 100 ���ϣ�
                ������� 1000 ���ϣ�
                ��ǰ���� 600 ���ϣ�
                ������ �����޼� ͬʱʹ�á�
HELP
        );
        return 1;
}
