#include <ansi.h>
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

void remove_effect(object me,int count);

string perform_name() {return HIY"������"NOR;}

int perform(object me, object target)
{                               
        int improve;
      
        if( !me->is_fighting() && (int)me->query_skill("tiyunzong",1)<350 )
                return notify_fail("������ֻ����ս����ʹ�á������ݡ���\n");
        if( (int)me->query_skill("tiyunzong",1) < 120 )
                return notify_fail("��������ݲ�����죬����ʹ�á������ݡ���\n");
        if( (int)me->query_skill("yinyun-ziqi",1) < 120 )
                return notify_fail("������������ȼ�����������ʹ�á������ݡ���\n");  
        if (me->query_skill_mapped("force") != "yinyun-ziqi")
                return notify_fail("����ڹ����ԣ�����ʹ�á������ݡ���\n");
        if( (int)me->query_dex() < 28 )
                return notify_fail("�����̫�ͣ�����ʹ�á������ݡ���\n");
      
        if( (int)me->query_skill("dodge",1) < 120 )
                return notify_fail("��Ļ����Ṧ̫����屿׾������ʹ�á������ݡ���\n");
      
        if( (int)me->query("neili") < 600 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó��������ݡ���\n");   
    
        if (me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("�����ڼ�����������ʹ�á������ݡ�������\n");                                                                                 
        if( me->query_temp("zong")   )
                return notify_fail("������ʹ�������ݵ���������������ݡ���\n");
       
        message_vision(HIY"$NͻȻ����һ������һ̧���͵İθ����ɣ����Ƹվ���˫�������߳���" +
        "�������������������������������£�\n" NOR, me);
      
        improve = (int)me->query_dex();
        me->start_perform(1,"�������ݡ�");
        me->add_temp("apply/dodge", improve);
 me->add_temp("apply/dexerity", improve);
        me->set_temp("zong",improve);  
        me->add("neili", -(350-(int)me->query_skill("tiyunzong",1)/10));            
        call_out("remove_effect", 1, me, improve);
        return 1;
}

void remove_effect(object me,int count)
{
        int improve;
        if( !me ) return;
        if( !intp(improve = me->query_temp("zong"))) return;
         if( count < 1){
          me->add_temp("apply/dodge", - improve);
 me->add_temp("apply/dexerity", -improve);
          me->delete_temp("zong");
          tell_object(me, HIY"��ɢȥ�������۵������������������������������У��������ġ�\n"NOR);
          tell_room(environment(me), HIY + me->name()+"ȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n"NOR,  ({ me })); 
          return;
        }
        call_out("remove_effect", 1 , me ,count -1);
}

int help(object me)
{
        write(WHT"\n�����ݡ��ݡ��־���"NOR"\n");
        write(@HELP
        �䵱�Ṧ��������ν�������֣������Ṧ�޳����ң��ٵ�֮ʱʹ�����ݡ���
        ����������������������Լ����Ṧ��Ч�ȼ�������ʤ������ѻ��ʡ�
        
        Ҫ��  �����ݵȼ� 120 ���ϣ�
                �������ȼ� 120 ���ϣ�
                �����Ṧ�ȼ� 120 ���ϣ�
                ���� 600 ���ϣ�
                ������ 28 ���ϡ�
HELP
        );
        return 1;
}
