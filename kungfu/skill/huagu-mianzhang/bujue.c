// bujue.c ���಻��

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name() {return HIC"���಻��"NOR;}

void attackob(object me,object target,int lvl,int hits,int);
void dohit(object,object);

int perform(object me, object target)
{
        string msg;
        int lvl,effect,i; 
        
        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("�����಻����ֻ����ս��ʱ�ã�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ����á����಻������\n"); 

        if( (lvl=(int)me->query_skill("huagu-mianzhang", 1)) < 100 )
                return notify_fail("��Ļ������ƻ���������������ʹ�ã�\n");

        if ( me->query_skill_prepared("strike") != "huagu-mianzhang"
        || me->query_skill_mapped("strike") != "huagu-mianzhang" 
        || me->query_skill_mapped("parry") != "huagu-mianzhang" )
                return notify_fail("��û�м����������ƣ�����ʹ�á����಻������\n");

          if(me->query_skill("dulong-dafa",1) < 100 )
                return notify_fail("��Ķ����󷨹������㣬���������಻����\n");

        if ( me->query_skill_mapped("force") != "dulong-dafa" )
                return notify_fail("��û�м��������󷨣�����ʹ�á����಻������\n");

        if((int)me->query("neili") < 800)
                return notify_fail("�������������㣬�����á����಻������\n"); 

        if((int)me->query("jingli") < 300)
                return notify_fail("�����ھ������㣬�����á����಻������\n"); 

        if((int)me->query("jiali") < 50)
                return notify_fail("�����̫���ˣ������á����಻������\n"); 

	if( target->query_temp("bujue_busy") )
	 	return notify_fail("�Է��Ѿ����ˡ����಻������\n"); 
	 	
i = 3;
        msg = HIY"\n$N��Ȼ��һ������˫��һ������$n������ĳ���\n"+ 
              HIC"�ƺ����ֲ��أ����䲨��״���������˻�ǰ�ˣ�һ�˸߹�һ�ˣ����಻����\n"NOR;
        message_vision(msg, me, target);
	effect = SKILL_D("dulong-dafa")->force_effect(target->query_skill_mapped("force"));
        if ( random(lvl) > target->query_skill("force")/4
        &&   random(me->query("combat_exp"))>target->query("combat_exp")/3) {
                me->start_perform(4,"�����಻����");
                me->set_temp("sld/pfm/bujue",1);
		target->add_temp("apply/defense",-lvl/5);
                target->apply_condition("no_perform", 4-effect);
                target->set_temp("bujue_busy", 1);
                me->add("jingli",-100);
                me->add("neili",-300);
                me->add_temp("apply/attack",lvl/5);
                if(i==3) me->add_temp("apply/strength",lvl/20);
                COMBAT_D->do_attack(me, target,0, i);
                if(i==3) me->add_temp("apply/strength",-lvl/20);
                COMBAT_D->do_attack(me, target,0, TYPE_RIPOSTE);
                me->add_temp("apply/attack",-lvl/5);
                if(wizardp(me)) write("�����غ���:"+(5-effect)*3 +"!\n");
                call_out("attackob", 2+random(2), me, target,lvl,(5-effect)*3,i);
        }
        else {
                message_vision(CYN"\n����$n���һ�������ۺ������������$N�������γɵ�������\n"+
                                  "���$Nֻ���ļ������������У����޷���ά�����ȵ����ơ�\n"NOR, me, target);
                me->add("neili",-500);
                me->add("jingli",-200);
                me->add_temp("apply/attack",lvl/5);
                target->add_temp("apply/dodge",-lvl/5);
                if (i==3) me->add_temp("apply/strength",lvl/20);
                COMBAT_D->do_attack(me, target,0, TYPE_RIPOSTE);
                   COMBAT_D->do_attack(me, target,0, i);
                if (lvl >= 150)
                {
                	if(random(me->query("combat_exp"))>target->query("combat_exp")/2)
				COMBAT_D->do_attack(me,target,0,TYPE_SUPER);
			else
                		COMBAT_D->do_attack(me, target,0, TYPE_RIPOSTE);
                }
                me->add_temp("apply/attack",-lvl/5);
                target->add_temp("apply/dodge",lvl/5);
                if (i==3) me->add_temp("apply/strength",-lvl/20);
                me->delete_temp("sld/pfm/bujue");
                me->start_busy(1+random(2));
                me->start_perform(2+random(2),"�����಻����");
        }
        return 1;       
}

void attackob(object me,object target,int lvl,int hits,int i)
{
	
   if( !target && me) {
      message_vision(HIC"\n$N����һ�٣���Ҳ֧�ֲ�ס�����ʱ�յ�������ֻ�ܻ����ջ����ƣ�\n"NOR, me);
      me->delete_temp("sld/pfm/bujue");
      me->start_perform(3,"�����಻����");
      return;
      }
	if( !me ){
if(target) {
                target->delete_temp("bujue_busy");
		target->add_temp("apply/defense",lvl/5);
		target->clear_condition("no_perform");
}
//           me->delete_temp("sld/pfm/bujue");
		return;
	}
        if (!hits 
        || !target
        || !living(target)
        || me->query_temp("weapon")
        || target->is_ghost() 
        || me->is_ghost()  
        || !me->is_fighting(target) 
        || me->query("neili") < 800 
        || me->query_skill_prepared("strike") != "huagu-mianzhang" ){
        	message_vision(HIC"\n$N����һ�٣���Ҳ֧�ֲ�ס�����ʱ�յ�������ֻ�ܻ����ջ����ƣ�\n"NOR, me);
                target->delete_temp("bujue_busy");
                target->clear_condition("no_perform");
              if( userp(me) ) 
                me->delete_temp("sld/pfm/bujue");
              if( userp(me) ) 
                me->start_perform(3,"�����಻����");
		return;
	}

        if(wizardp(me)) write("�����غ���:"+hits+"!\n");
        me->add_temp("apply/attack",lvl/5);
        COMBAT_D->do_attack(me, target,0, TYPE_RIPOSTE);
        if(i==3) me->add_temp("apply/strength",lvl/20);
        COMBAT_D->do_attack(me, target,0, i);
        if(i==3) me->add_temp("apply/strength",-lvl/20);
        me->add_temp("apply/attack",-lvl/5);
        me->start_perform(2,"�����಻����");
        call_out("attackob", 2, me,target, lvl, --hits,i);
}

int help(object me)
{
   write(WHT"\n�������ơ�"HIC"���಻��"WHT"����"NOR"\n");
   write(@HELP

    Ҫ�󣺵�ǰ���� 800 ���ϣ�
          ��ǰ���� 300 ���ϣ�
          �������Ƶȼ� 100 ���ϣ�
          �����󷨵ȼ� 100 ���ϣ�
          Ů��ʹ��Ч����������֮��ɣ�
          �˵м��� 50 ���ϡ�
HELP
   );
   return 1;
}
