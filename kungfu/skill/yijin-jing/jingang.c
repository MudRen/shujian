// snowman 04/01/99
// Modified by snowman@SJ 28/09/2000
// Modified by olives@SJ 5/2/2001
// for exert jingang �İٶ����ֵ�bug
// By Spiderii��ǿЧ�����Ͼ������NB��force
// By Server Fix ���� Exert bug
#include <ansi.h>
void remove_effect(object me,int count);

int exert(object me)
{    
      if ( !me->is_fighting())
                return notify_fail("��ֻ����ս����ʹ�á���ղ������񹦡���\n");

      if( (int)me->query_skill("yijin-jing", 1) < 199 )
                return notify_fail("����׽�ڹ���Ϊ�������޷�ʹ�á���ղ������񹦡���\n");

      if (me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("�����ڹ��С���ղ������񹦡���\n");

      if( (int)me->query_con() < 40 )
                return notify_fail("��ĸ���̫�ͣ������޷�ʹ�á���ղ������񹦡���\n");
 
      if( (int)me->query("neili") < 1000 )
                return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á���ղ������񹦡���\n");   
    
      if( (int)me->query("max_neili") < 3800 )
                return notify_fail("���������Ϊ��ô�����ʹ�á���ղ������񹦡���\n");   
                                                                                
      if( me->query_temp("fanzhen"))
                return notify_fail("���������á���ղ������񹦡���\n");
       
      message_vision(HIY"\n$NͻȻ����һ������Ŀ¶�ȹ⣬���΢Ц��������ת����ʹȫ�����±����������ǡ���ղ������񹦡���\n\n" NOR, me);
      me->start_busy(1);
      me->set_temp("fanzhen", me->query_skill("yijin-jing", 1)/2);
      me->set_temp("yjj/jg", me->query_skill("yijin-jing", 1)/2);
      me->set_temp("no_skill_hit_ob", 1);
      me->add_temp("apply/armor", me->query_skill("yijin-jing", 1)/2); 
      me->add_temp("apply/parry", me->query_skill("yijin-jing", 1)/2);
      me->add_temp("apply/attack", me->query_skill("yijin-jing", 1)/2);
      me->add("neili", -500);    
      call_out("remove_effect", 1, me, me->query_skill("yijin-jing", 1)/2+20);
      me->start_exert(2,"����ղ������񹦡�");
      return 1;
}

void remove_effect(object me,int count)
{
        if( !me) return;
                if(me->query_temp("yjj/jg")) {
        if( count < 1 ){
            me->delete_temp("fanzhen");
            me->delete_temp("no_skill_hit_ob");
            me->start_exert(2,"����ղ������񹦡�");
            me->add_temp("apply/parry", -me->query_skill("yijin-jing", 1)/2);
            me->add_temp("apply/attack",-me->query_skill("yijin-jing", 1)/2);
            me->add_temp("apply/armor", -me->query_skill("yijin-jing", 1)/2);
            message_vision(HIR"\n$N˫�ֺ�ʮ��ɢȥ��������ȫ�����µġ���ղ������񹦡���\n"NOR, me);    
            return;
        }
        else {
            call_out("remove_effect", 1, me,count -1);
            return;
        }
      }
}

int help(object me)
{
        write(HIY"\n�׽֮����ղ������񹦡���"NOR"\n");
        write(@HELP
        ��գ�����֮�⣬���ٽ�ǧ������ת�����������Բ��������Խ��֮�ᣬ��
        �����壻�Խ��֮�����������á���ղ�������Ϊ���ֵ�һ�����������
        �Ϊ����ʹ���塢���������ڣ�ѭ�򽥽�����֮�Ժ㣬���ܵ�����ħ��
        ����������
        
        Ҫ��  �׽�ȼ� 200 ���ϣ�
                ���� 40 ���ϣ�
                ������� 3800 ���ϣ�
                ���� 1000 ���ϡ�
HELP
        );
        return 1;
}
