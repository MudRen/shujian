// ci.c �����Ŀ

#include <ansi.h>
string perform_name(){ return RED"�����Ŀ"NOR; }

inherit F_SSERVER;

void back(object target);

int perform(object me, object target)
{
        int skill;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("pixie-jian", 1) < 120 )
                return notify_fail("��ı�а����������죬����ʹ�÷����Ŀ��\n");

    if( (int)me->query("neili", 1) < 800 )
       return notify_fail("�������������㣡\n");  
    if( (int)me->query("max_neili", 1) < 1500 )
       return notify_fail("��������Ϊ���㣡\n");  
        if( (int)me->query_dex() < 30  )
                return notify_fail("�����̫�ͣ�����ʹ�÷����Ŀ��\n");
       
        if (!weapon || !(weapon->id("needle"))
        || me->query_skill_mapped("sword") != "pixie-jian")
                return notify_fail("�������޷�ʹ�÷����Ŀ��\n");

        if( (int)target->query_temp("cimu") ) 
                return notify_fail("���Ѿ��������ˣ�\n");

        skill = (int)me->query_skill("pixie-jian", 1);                
        skill = skill/15;

        me->add("neili", -350);
        me->add("jingli", -200);

        message_vision(RED"$Nһ����Ц������һ�ź��ư��۽�$n������ϸ�����$n˫Ŀ��\n"NOR, me, target);
        message_vision(RED"$nһ����æ˫�ۻ�ת���뻤ס˫�ۣ�\n"NOR, me, target);;

  if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
     me->query_dex() > random((int)target->query_dex())) {
         if (target->query_skill_mapped("sword") != "dugu-jiujian" 
             || target->query_skill("dugu-jiujian", 1) < 99) {
                message_vision(HIR"\nֻ��$n�ҽ�һ����ֻ����˿ϸѪ��$n���������������Ѿ���$N����˫Ŀ�ˣ�\n"NOR, me, target);
                tell_object(target, HIY "��������Ȼ������˫�ۣ���ϸ�뻹�Ǵ����������Ƥ����������Ѿ�ģ�������ˣ�\n" NOR);
                target->set_temp("cimu", 1);
                target->add_temp("apply/attack", - 100);
                target->add_temp("apply/dodge", - 100);
                target->add_temp("apply/parry", 50);
                target->receive_damage("qi", 150);
                target->receive_wound("qi", 50);
                target->kill_ob(me);
                target->set_temp("block_msg/all",1);
                call_out("back", 3 + skill, target);
                }
         else { message_vision(HIR"\n$n�������ǣ����ֻ�ָΪ��Ҳ��$N����Ŀ���̣��������ܾ��˵Ĵ򷨡�\n"NOR, me, target);
                tell_object(target, HIR "�㵫�����ü��΢΢һʹ��֪���Լ���ü��Ϊ���廨�������У������ұܿ����۾�Ҫ����\n" NOR);
                target->receive_damage("qi", 100);
                target->receive_wound("qi", 40);
                target->kill_ob(me);
                me->start_busy(1+random(2));
               }
           }
  else {
                message_vision(HIY"$n��ͷ����һ������������㿪��$N��һ�С�\n"NOR, me, target);
                me->start_busy(3);
                target->kill_ob(me);
        }
      
        return 1;
}

void back(object target)
{
	if(!target) return;
        target->add_temp("apply/attack", 100);
        target->add_temp("apply/dodge", 100);
        target->add_temp("apply/parry", - 50);
        target->set_temp("block_msg/all", 0);
        if(living(target)) 
              tell_object(target, HIW "��������˫Ŀû�б��������ˣ����ֿ��Կ�����������\n" NOR);
        target->delete_temp("cimu");
}
