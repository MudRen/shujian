// ��ʬ����
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
       object co;

       if( !target ) target = offensive_target(me);

       if( !target || !me->is_fighting(target) )
            return notify_fail("����ʬ���񶾡�ֻ����ս���жԶ���ʹ�á�\n");

       if( objectp(me->query_temp("weapon")) )
            return notify_fail("�������ֲ���ʹ�á���ʬ���񶾡���\n");

       if( (int)me->query_skill("tianmo-zhang", 1) < 220 )
            return notify_fail("�����ħ�ƻ�������죬ʹ��������ʬ���񶾡�������\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing--dafa")
                return notify_fail("����ʹ�õ������ڹ����ԡ�\n"); 
                
                        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 220)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ��������ʬ���񶾡���\n");  

       if((int)me->query_skill("poison",1)<151)
            return notify_fail("�㶾�Ʋ����޷�ʹ����ʬ���񶾡�\n"); 
            co=present("corpse",me);       

       if (!co)
           return notify_fail("������û�и��õ�ʬ�壬���ʹ����ʬ����!\n");

       if (co->query("name")!="���õ���ʬ"
        && co->query("name")!="���õ�Ůʬ")
           return notify_fail("�����ϵ�ʬ��û�и��ã��޷�ʹ����ʬ���񶾡�\n");

       if (me->query_skill_prepared("strike") != "tianmo-zhang"
        || me->query_skill_mapped("strike") != "tianmo-zhang"
        || me->query_skill_mapped("parry") != "tianmo-zhang")
           return notify_fail("�������޷�ʹ�á���ʬ���񶾡���\n");                                                                                 

       if( (int)me->query("max_neili") < 1500) 
           return notify_fail("������̫����ʹ��������ʬ���񶾡���\n");      

       if( (int)me->query("neili") < 1000)
           return notify_fail("����������̫����ʹ��������ʬ���񶾡���\n");

       message_vision(HIB"\n$N�ӱ����ϳ�һ��ʬ�壬��$n��Ȼ������ʬ���Ѿ��������ظ��ã�����Ѭ�죡\n"NOR,me, target);
       call_out("destroying", 1, co);
       if (!target->is_killing(me))
          me->kill_ob(target);
       me->add("neili", - (250 + me->query_skill("force")));
       if( random(me->query("combat_exp")) > (int)target->query("combat_exp")* 3/5
        && me->query_str() > (int)target->query_str()/3*2){ 
         message_vision(HIB"\n$n���˹���������������޴룬�����޼���ֻ��ɢ���Ŷ����ʬ�壬�������Լ����ϡ�\n"NOR, me, target);
         me->add("max_neili", -50);
	if (userp(target))
		me->add_condition("killer", 90);
         target->set_temp("last_damage_from", "��ʬ��������");
         target->die();
         return 1;  
       }
       else if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3
         && me->query_str() > (int)target->query_str()/2){
          message_vision(HIB"\n$n���²��ã���æ����ֱ����ʬ����������ӹ���û�д��С�\n"NOR,me,target);
          tell_object(target,HIB"\n����Ȼ��ʱ�ܿ��˶�ʬ����һ���ȳ�����ǣ�����������ʬ�����ˡ�\n"NOR);
          me->add("max_neili", -70);
	if (userp(target))
		me->add_condition("killer", 15);
          target->apply_condition("sansi_poison", random(3));
          me->start_busy(5);
          target->add_busy(1);
          return 1;
      }
      message_vision(HIB"\n$n���г���һ����Х��˫�������������Ѷ�ʬ����������·��\n"NOR,me,target);
      tell_object(me,HIB"\n���ã���ʬ�������㣬����Ȼ�㿪��������Ҳ����������塣\n"NOR);
      me->set_temp("last_damage_from", "��ʬ��������");
      me->receive_damage("qi", 2500);
      me->receive_wound("qi", 2500);
      me->add("max_neili", -100);
      me->apply_condition("sansi_poison", random(3));
      me->start_perform(10,"��ʬ����");
      return 1;
}

void destroying(object obj)
{
        destruct(obj);
}
string perform_name(){ return HIB"��ʬ����"NOR; }