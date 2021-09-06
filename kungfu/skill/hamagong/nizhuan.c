
// nizhuan.c ��ת����
// by snowman@SJ

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

string exert_name()
{
        return HIW"��ת����"NOR;
}

int exert(object me, object target)
{
        int skill,sk;

        if( !target )
                target = me;

        if(!(int)me->query_skill("hamagong", 1) )
                return 0;
        if( me->query("oyf/hamagong") < 2 )
                return notify_fail("���˸�󡹦ʹ������ת����������\n");
        if((int)me->query("neili") < 300  )
                return notify_fail("�������������\n");
        if((int)me->query("jingli") < 200  )
                return notify_fail("��ľ���������\n");
        if((int)me->query_temp("hmg_nizhuan") )
                return notify_fail("���Ѿ������˾�����\n");

       sk = me->query_skill("force",1)/2 + me->query_skill("hamagong", 1);
       sk /= 2;
       skill = me->query_skill("force",1)/4 + me->query_skill("hamagong", 1)/2;
       me->add("neili", -200);
       me->add("jingli", -20);


      message_vision(HIW "\n$N˫�ֳŵأ����з���һ���ܵͺ�����һ�ɹ��ھ�����ʹ$N˫����أ���ͷ������֮�ơ�\n" NOR, me);
      tell_object(me, HIW "�����ڸ�󡹦������ת�������йɾ޴������Ҫ��������һ����\n" NOR);

   me->start_call_out( (: call_other, this_object(), "remove_effect", me :), skill);

 if (me->query_skill("hamagong", 1) > 450)
        {
                me->add_temp("apply/parry", skill/4);
                me->add_temp("apply/dodge", skill/4);
        }

if(me->query("oyf/hamagong")==3 ) me->add_temp("apply/armor",skill);

        me->add_temp("apply/strength", skill/6);
        me->add_temp("apply/dexerity", skill/6);
        me->add_temp("apply/attack", skill/5);
 
      me->set_temp("hmg_nizhuan", skill);
        
        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me)
{
        int amount;
        if(!me) return;

        if( !intp(amount = me->query_temp("hmg_nizhuan")) )
                return;

        if (me->query_skill("hamagong", 1) > 450)
        {
                me->add_temp("apply/parry", -amount/4);
                me->add_temp("apply/dodge", -amount/4);
        }
        me->add_temp("apply/strength", - amount/6);
        me->add_temp("apply/dexerity", - amount/6);
        me->add_temp("apply/attack", - amount/5);

if(me->query("oyf/hamagong")==3 ) me->add_temp("apply/armor",-amount);

        me->delete_temp("hmg_nizhuan");
  tell_object(me, HIW "���󡹦���˹��ã����ǽ������壬ֻ����ֹ����ת��\n" NOR);      
}

int help(object me)
{
write(WHT"\n��󡹦����ת��������"NOR"\n");
write(@HELP
ŷ����Ķ��ž�����󡹦����������ѧ�еľ��������Դ������������ɷ�
���ֶ�����µ�һ�ĳƺź����󡹦������Ѱ���书�����ӹ������ס���
��ת����֮�������ǵ�������������ľ�����

      Ҫ������ 300 ���ϣ�
            �⿪��󡹦�������
            ����ʩչ��ת������
            �⿪��󡹦��������
            �����ͷ���ת��������������
HELP
);
return 1;

}
