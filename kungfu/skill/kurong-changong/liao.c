//COOL@SJ
// By Spiderii@ty �Ӹ�����,��ֹǿ��Ϊ����yun liao.��ɶԷ�busy
#include <ansi.h>

string exert_name() {return HIY"��������"NOR;}

int exert(object me, object target)
{
        if( !objectp(target) )
                return notify_fail("��Ҫ��һ��ָΪ˭���ˣ�\n");

        if(!present(target,environment(me)) )
                return notify_fail("��Ҫ��һ��ָΪ˭���ˣ�\n");

        if (target->is_corpse() || !target->is_character())
                return notify_fail("�ǲ��ǻ���Ү��\n");

        if((int)me->query_skill("force") < 180 )
              return notify_fail("���Ǭ��һ����������죬�޷��������ˣ�\n");

        if((int)me->query_skill("yiyang-zhi",1) < 100 )
              return notify_fail("���һ��ָ�񹦲�����죬�޷��������ˣ�\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi"
         || me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("�������޷�ʹ��һ��ָ�������ˣ�\n");

        if( me->is_fighting()&&target != me)
                return notify_fail("ս�����޷���������ˣ�\n");

        if( target->is_fighting()&&target != me)
                return notify_fail("�Է�����ս�����޷��������ˣ�\n");
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("���������Ϊ������\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������\n");

        if((int)me->query_skill("medicine", 1) < 120 )
               return notify_fail("���������ҽ��֪ʶ��֪���٣���֪�������? \n");

        if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
                return notify_fail( target->name() + "��û�����ˣ�\n");
        // By Spiderii@ty �Ӹ�����
        if( target->query("env/no_lifeheal"))
                return notify_fail( target->name()+"�ܾ���������ˡ�\n");
        if (me->is_fighting() && (target==me))
        {
          message_vision(HIY"\n$N�ֱ۲������������ѵ�ˮ��һ����������Լ��ؿڵ�ʮ������Ѩ��������������͸�롣����\n\n"
                         HIM"ֻ��Ƭ��֮�䣬$N��ɫ�����˺���,���ƺö��ˡ�\n" NOR,me);
          me->add("neili",-((int)me->query_skill("force")/2));
          me->receive_curing("qi", 10+(int)me->query_skill("force") );
          me->add("qi", 10+(int)me->query_skill("force"));
          if( (int)me->query("qi") > (int)me->query("eff_qi") )
          me->set("qi", (int)target->query("eff_qi"));
          me->start_exert(2,"����");
        }
        else
        {
          if (target != me)
            message_vision(HIY"\n$N�������ʳָ��΢һ������������������, ʳָ���Ρ���������Ѩ���˵���������$n�ؿڵ����д�Ѩ�ϣ���������ԴԴ͸�롣����\n\n"
                           HIM"\n$Nͷ��ð��˿˿������$n�о�һ������ƽ�͵�����������ѭ������������һյ��ʱ�֣�$N�ŷſ���ָ��ֻ��Ƭ��֮�䣬$n˫��\n"
                           HIM"�����˺��Σ���ɫ������Ҳ�ö��ˡ�\n" NOR,me,target);
          else
           message_vision(HIY"\n$N�������£�΢һ������ʳָ���Ρ���������Ѩ���˵����ʳָһ�գ����ư����ؿ����д�Ѩ����������ԴԴ͸�롣����\n\n"
                          HIM"$Nͷ��ð��˿˿����������һյ��ʱ�֣��ŷſ���ָ,$N����ɫ������Ҳ�ö��ˡ�\n" NOR,me);
           if(target != me
           && userp(target)
           &&(int)target->query("eff_qi") < (int)target->query("max_qi")/5)
           {
             if(!random(4))
             	me->add("max_neili",-1);
             me->add("yyz_cure",1);
           }
           me->add("neili",-((int)me->query_skill("force")/3));
           target->receive_curing("qi", 10+(int)me->query_skill("force"));
           target->add("qi", 10+(int)me->query_skill("force"));
           if((int)target->query("qi")>(int)target->query("eff_qi"))
           	target->set("qi", (int)target->query("eff_qi"));
           if(target!=me)
           	me->start_busy(3);
           target->start_busy(3);
        }
        return 1;
}
