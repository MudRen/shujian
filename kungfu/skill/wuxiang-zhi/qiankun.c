// qiankun.c 
// tiantian@sj 2000.10.14 
// Modified by snowman@SJ 12/12/2000

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      string msg;
      int improve;

      if( !target ) target = offensive_target(me);
     
        if( !objectp(target))
          return notify_fail("��Ҫ��˭ʹ�á�����Ǭ������\n");

        if( me->query("family/family_name")!="������" )
                return notify_fail("�㲻�����ֵ��ӣ������ʹ�����־�����\n");
        if( me->query("shen")<0 || (userp(target) && target->query("combat_exp")>me->query("combat_exp")*3/2) || (userp(target)&& target->query("combat_exp")<me->query("combat_exp")*2/3 ))
        	
                return notify_fail("����������������ʹ�ôȱ�Ϊ���������书��\n");
                
        if(me->query_condition("killer")>200)
                return notify_fail("һ�ղ���������ɱ����ˡ�\n");
        if(environment(me)->query("no_fight"))
                return notify_fail("���ﲻ�ܹ������ˡ�\n");
        if(target->query("combat_exp")<100000)
                return notify_fail("��ô����ˣ��õ�����˷Ѿ�ô��\n");
                
     if( me->query("no_pk") && userp(target) && (!me->query_temp("xyjob") || !target->query_temp("xyjob")))
     return notify_fail("���Ѿ��˳���������������ʵʵ�İɡ�\n");

      if( target->query("no_pk") && userp(me) && (!me->query_temp("xyjob") || !target->query_temp("xyjob")))
     return notify_fail( target->name()+"�Ѿ��˳������ˣ������˴������˰ɣ�\n");
          
      if( objectp(me->query_temp("weapon")) )
          return notify_fail("��������ʹ�á�����Ǭ������\n");
      
      if( (int)me->query_skill("wuxiang-zhi",1) < 200 )
          return notify_fail("��������ָ������죬����ʹ�á�����Ǭ������\n");

      if( (int)me->query_skill("yijin-jing",1) < 200 )
          return notify_fail("����׽�ڹ��ȼ�����������ʹ�á�����Ǭ������\n");  
      
      if( (int)me->query("max_neili") < 3000 )
          return notify_fail("�������̫��������ʹ�á�����Ǭ������\n");
      
      if( (int)me->query("neili") < 3000 )
          return notify_fail("�������̫���ˣ��޷�ʹ�ó�������Ǭ������\n");   
                                                                                 
      if (me->query_skill_prepared("finger") != "wuxiang-zhi"
       || me->query_skill_mapped("finger") != "wuxiang-zhi")
          return notify_fail("�������޷�ʹ�á�����Ǭ�������й�����\n");                                                                                 
        if( me->query_temp("slpfm/jgqbrz") )
                return notify_fail("������ʹ�����־�����"+me->query_temp("slpfm/jgqbrz")+"����\n");
        if( me->query_temp("slpfm/rytqys") )
                return notify_fail("������ʹ�����־�����"+me->query_temp("slpfm/rytqys")+"����\n");
        if( me->query_temp("slpfm/lzgyzc") )
                return notify_fail("������ʹ�����־�����"+me->query_temp("slpfm/lzgyzc")+"����\n");

        if( target == me )
                return notify_fail("�Լ����Լ�����\n");

      if (target->is_corpse() || !target->is_character())
               return notify_fail("�ǲ��ǻ���Ү��\n");
        if(!living(target))
                return notify_fail("�Է��������ˣ����õ�����ô�Ѿ�ô��\n");

      if(  target->is_busy() ) 
                return notify_fail("�Է����Թ˲�Ͼ���ŵ������ɣ�\n");

      me->set_temp("slpfm/lzgyzc","����Ǭ��");
      me->set_temp("slpfm/jgqbrz","����Ǭ��");
      me->set_temp("slpfm/rytqys","����Ǭ��");

      me->start_perform(5, "����Ǭ��");
      tell_object(me, HIY"�����΢Ц����˫��£������֮�У�ָ���������а���������һ���������޵�΢������"
+target->name()+"Ϯȥ��\n" NOR);  
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), 6 );
        if( me->query("combat_exp") / 5 * 3 > random(target->query("combat_exp"))) {
        tell_object(me,"���"+target->query("name")+"����ָ����У���ʱ�������á�\n");
       tell_object(target,"��ֻ����һ���������޵�΢������Ϸ�����������䷢���Լ��Ѿ��޷�������\n");
            me->add("neili", -350);    
            target->start_busy(4 + random(me->query_skill("wuxiang-zhi",1))/40);
            target->apply_condition("no_exert",1+ random(me->query_skill("wuxiang-zhi",1))/100);
            target->apply_condition("no_fight",1+ random(me->query_skill("wuxiang-zhi",1))/100);
            target->apply_condition("no_perform",1+ random(me->query_skill("wuxiang-zhi",1))/100);
      } else {
        if( me->query_skill("wuxiang-zhi", 1)/3*2 > random(target->query_skill("dodge",1))){
                        msg = HIY"$nֻ����һ���������޵�΢������Ϸ�����ȴ�ֲ�֪��������ʲô���顣\n"NOR;
                        me->start_busy(1+random(2));
                } else {
                        msg = HIY"$nֻ����һ���������޵�΢������Ϸ�������ͷ��ȥ��ԭ����$N��ʵʩ���㡣\n"NOR;
                        me->start_busy(2+random(3));
                        me->kill_ob(target);
                        target->kill_ob(me);
                }
                message_vision(msg, me, target);  
me->add("neili", -200);
      }
      return 1;
}

void remove_effect(object me, int improve)
{
   me->delete_temp("slpfm/lzgyzc");
        me->delete_temp("slpfm/rytqys");
        me->delete_temp("slpfm/jgqbrz");
}

string perform_name(){ return HIY"����Ǭ��"NOR; }
