// daoqi.c  ���浶 [���浶��]
// coded by emnil@sj	4/29/2k

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

void clear_busy(object);

string perform_name(){ return HIR"���浶��"NOR; }

int perform(object me, object target)
{
	object ob;
	string msg;
	int lvl1,lvl2;
    
	if( !me->is_fighting() )
		return notify_fail("�����浶����ֻ����ս����ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ�á����浶������\n");
 
	if((int)me->query_skill("huoyan-dao",1) < 120)
		return notify_fail("��Ļ��浶��Ϊ������ Ŀǰ����ʹ�á������浶������! \n");

	if((int)me->query_skill("longxiang-boruo",1) < 120)
		return notify_fail("��������������Ϊ������ Ŀǰ����ʹ�á����浶����! \n");

	if( me->query_skill_mapped("strike") != "huoyan-dao")
		return notify_fail("�����ʹ�û��浶������ʹ�á����浶�����ľ�����\n");

	if( me->query_skill_mapped("force") != "longxiang-boruo")
		return notify_fail("��������ʹ�õ��ڹ�ͬ���������������ִ�������ʹ�������浶�����ľ�����\n");

	if( (int)me->query("max_neili") < 2500 )
		return notify_fail("���������Ϊ������\n");
	if((int)me->query("neili")<500)
		return notify_fail("�������������\n"); 
	if((int)me->query("jingli")<300)
		return notify_fail("��ľ���������\n"); 

	ob = me->select_opponent();

	switch((int)me->query_temp("hyd/pfm")) {
		case 0:
			lvl1 = me->query_skill("strike") + me->query_skill("force")/5;
			if( me->query_temp("xs/longxiang") &&  me->query_temp("apply/attack")>0 )
				lvl1 += me->query_temp("apply/attack");
			lvl2 = ob->query_skill("dodge");
			
			me->add("neili",-200);
			me->add("jingli",-100);
			msg = HIY"\n$N˫Ŀ�䶸Ȼ���һ�����漴��$n����ǰ������������������ĵ�������������ҽǣ���ȫ��֪���٣�\n"NOR;

			if( lvl1/2 > random(lvl2) ) {
           if(ob->query_temp("hyd/attack")==0) 
					ob->set_temp("hyd/attack" , me->query_skill("huoyan-dao",1)/4);
				else
					ob->add_temp("hyd/attack" , me->query_skill("huoyan-dao",1)/4);
                if(ob->query_temp("hyd/dodge")==0)
					ob->set_temp("hyd/dodge" , me->query_skill("huoyan-dao",1)/5);
				else
					ob->add_temp("hyd/dodge" , me->query_skill("huoyan-dao",1)/5);
            if(ob->query_temp("hyd/parry")==0)
					ob->set_temp("hyd/parry" , me->query_skill("huoyan-dao",1)/5);
				else
					ob->add_temp("hyd/parry" , me->query_skill("huoyan-dao",1)/5);
				ob->add_temp("apply/attack" , -me->query_skill("huoyan-dao",1)/4);
				ob->add_temp("apply/dodge" , -me->query_skill("huoyan-dao",1)/5);
				ob->add_temp("apply/parry" , -me->query_skill("huoyan-dao",1)/5);
			
				msg += HIR"$n��ȫ������$N�ĵ�·��ֻ�����н����Ż���\nȴ����ǰ�����Ҷ���$N�ĵ��������ˣ��������ض��������ǣ�ƣ�\n"NOR;
				me->set_temp("hyd/pfm",1);
				me->start_busy(1);
				ob->start_busy(1);
				me->start_perform(3,"���浶��");
				call_out("check_pfm",4,me,ob,me->query_skill("huoyan-dao",1)/25);
			}
			else {
				msg += HIC"ȷ����$n��ȫ����$N�������ĵ���������ͥ������$Nֻ�Ļ������С�\n"NOR;
				me->start_busy(2);
				me->start_perform(3,"���浶��");
			}
			break;
		case 1:
			msg = HIY"\n$Nȫ�����һ���죬�漴����$n�Ķ��ϣ����������ϣ����������ĵ�����ͼ��ȫ����$n����\n"NOR;
			lvl1 = me->query_skill("strike",1);
			if( me->query_temp("xs/longxiang") &&  me->query_temp("apply/attack")>0 )
				lvl1 += me->query_temp("apply/attack");
			lvl2 = ob->query_skill("parry",1);

			if( lvl1/2 > random(lvl2) ) {
				me->add("neili",-300);
				me->add("jingli",-100);
				
				me->set_temp("hyd/busy" , me->query_skill("huoyan-dao",1)/40);
				me->set_temp("hyd/pfm",2);
				me->start_perform(6,"���浶��");

				// �Դ˴���busy
				ob->set_temp("lost_attack",10);
				ob->apply_condition("no_perform", 4);
				ob->apply_condition("no_exert", 4);
				
				msg += HIR"$n�Ծɲ�������$N�ĵ�·�������$N��ȫ��ס�˹�����·�ߣ�ֻ�ܲ�ͣ��������Ծ�Զ��$N�Ĺ�������\n"NOR;
			}
			else {
				me->add("neili",-150);
				me->start_busy(2+random(2));
				me->start_perform(3,"���浶��");
				msg += HIC"$n���в��У���$N�����ĵ������������У����㵲ס��$N�Ĺ�����\n"NOR;
			}
			break;
		case 2:
			msg = HIR"\n$NͻȻ���һ����ƴ��ȫ��������Ծ�ڰ���е�$n����פ���ھ���һ��������\n"NOR;
			lvl1 = me->query("combat_exp");
			if( me->query_temp("xs/longxiang") )
				lvl1 = lvl1*12/10;
			lvl2 = ob->query("combat_exp");

			me->add("neili",-200);
			me->add("jingli",-100);

			if ( lvl1/2 > random(lvl2) ) {
				message_vision(msg, me , ob);
				msg = "";

				me->add_temp("apply/strength", me->query_skill("longxiang-boruo",1)/4);
				ob->set_temp("must_be_hit",1);
				COMBAT_D->do_attack(me, ob, 0, 1);
				ob->delete_temp("must_be_hit");
				me->add_temp("apply/strength", -me->query_skill("longxiang-boruo",1)/4);

				me->start_perform(4,"���浶��");
			}
			else {
				msg += HIC"$n���޿��ˣ�ֻ��ȫ���⵲��һ�У������Ȼ��ס����һ�У�ȴҲ������һ���亹��
��$Nȫ��������һ�и����˻�ȥ������$N��������\n$N��Ҳ�޷�ά�ַ���$n���ϣ����������ϣ������ĵ�����\n"NOR;
				me->start_busy(2);
				me->start_perform(4,"���浶��");
				me->delete_temp("hyd/busy");
				me->set_temp("hyd/pfm",1);
				clear_busy(ob);
		}
			break;
		default: break;
	}

	message_vision(msg, me , ob);

	return 1;
}

void check_pfm(object me,object target,int count)
{
	if( !objectp(me) || !objectp(target) || !me->is_fighting(target) || objectp(me->query_temp("weapon")) || count==0 ||
	  me->query_skill_mapped("strike")!="huoyan-dao" || me->query_skill_mapped("force")!="longxiang-boruo" ) {
		if(objectp(target)) {
			target->add_temp("apply/attack" , target->query_temp("hyd/attack"));
			target->add_temp("apply/dodge" , target->query_temp("hyd/dodge"));
			target->add_temp("apply/parry" , target->query_temp("hyd/parry"));
			target->delete_temp("hyd/attack");
			target->delete_temp("hyd/dodge");
			target->delete_temp("hyd/parry");
		}
		
		if(objectp(me))
		{
			me->delete_temp("hyd/pfm");
			me->delete_temp("hyd/busy");
		}
		if(objectp(target))
			clear_busy(target);

		if(me && target) 
			message_vision(HIC"\n$N�о�����һ�٣�ȴ���������Ĺ��࣬��Ҳ����ά�ַ�ס$n�ĵ�����\n"NOR, me , target);
		else 
			if (me) message_vision(HIC"\n$N�����ջ��������ĵ�����\n"NOR, me);

		return;
	}

	if( me->query_temp("hyd/pfm")==2 ) {
		if( me->query_temp("hyd/busy")==0 ) {
			me->delete_temp("hyd/busy");
			me->set_temp("hyd/pfm",1);
			clear_busy(target);
			message_vision(HIC"\n$n����������$N�ĵ�·�������������������˷�ס���ϣ����������ϣ������ĵ�����\n"NOR, me , target);
		}
		else {
			target->set_temp("lost_attack",10);
			target->apply_condition("no_perform", 4);
			target->apply_condition("no_exert", 4);

			me->add_temp("hyd/busy",-1);
			if( me->query_temp("hyd/busy")==1 )
				message_vision(HIC"\n$n��Ȼ��û�п���$N�ĵ��������������ƺ��Ѿ���������ࡣ\n"NOR, me , target);
		}
	}

	call_out("check_pfm",4,me,target,count-1);
}

void clear_busy(object ob)
{
	ob->delete_temp("lost_attack");
	ob->clear_condition("no_perform");
	ob->clear_condition("no_exert");
}
