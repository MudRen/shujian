//modify By Ziqing  Y2k
// Modified by snowman@SJ 05/12/2000

#include <ansi.h>

inherit F_SSERVER;

string exert_name() {return HIR"����"NOR;}

int exert(object me, object target)
{

        int hits;

        if( !target ) target = offensive_target(me);

	if( !objectp(target)
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
        	return notify_fail("�����Ĵ󷨡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
           
        if( (int)me->query_skill("dulong-dafa", 1) < 150 
        || (int)me->query_skill("shenlong-yaoli", 1) < 150 
        || (int)me->query_str() <=30 )
                return notify_fail("����Ϊ����������δ�����á����ġ���\n");

        if( me->query_skill("force", 1) < 150 )
                return notify_fail("����ڹ���Ϊ���δ����ʩչֻ���˼�����\n");
     
        if( me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ���������á����ġ���\n");
        if( me->query("eff_jingli") < 1500 )
                return notify_fail("��ľ�����Ϊ���������á����ġ���\n");
        if( me->query("neili") < 600 )
                return notify_fail("��������������������������á����ġ���\n");

        if( me->query("jingli") < 500 )
                return notify_fail("��ľ������ޣ����������á����ġ���\n");
        if( target->query_temp("shexin"))
                return notify_fail("�Է��Ѿ��������Ĵ���");
        
        message_vision(HIR"$n����$Pÿ��һ�䣬���о���һ�ݣ����������˵���Ϊϣ��Ź֣�ǰ��δ�У�\n\n" NOR, me , target);
        me->add("neili",-300);
        me->add("jingli",-100);
        me->start_exert(5, "�����ġ�");
        if( target->query_temp("hmg/nizhuan")){ 
           	message_vision("���$Pֻ��$n��ʽ�������Ĵ��޷��ɹ���\n", me, target);
           	return 1;
        }  
        if( target->query_temp("jiuyin/fast")){
           	message_vision("���$Pֻ��$n����Ʈ����������׽�����Ĵ��޷��ɹ���\n", me, target);
        	return 1;
        }
     	if( target->query_skill("buddhism", 1) > 200 && !target->is_killing(me->query("id")) ){
     		message_vision("���$n�𷨸�����Ĵ󷨸�����$pû�ã�\n", me, target);
        	return 1;
        }
        if( random(me->query_int()) > target->query_int()/2 ){
        	message_vision("���$n�ܵ�$P�����Ĵ󷨵�Ӱ�죬ԭ�ȵĶ�־��Ȼ��ʧ��\n", me , target);
       		target->remove_all_killer();
       		target->receive_damage("jing", me->query("int")*8, me);
       		target->receive_wound("jing", me->query("int")*3, me);
        	if( !target->is_busy() )
        		target->start_busy(3);    
        	hits = random(60)+(me->query("dex")-target->query("dex"))*5+(me->query("jingli")-target->query("jingli"))/20;
       		if (hits > 30) {
        		message_vision(HIR"$n�ܵ�$P���Ĵ󷨸�Ӧ��Խ��Խ�Ǻ��£�������ʱ�޷�����! \n", me , target);
         		target->apply_condition("sld_shexin", 3+random(3) );
         		target->apply_condition("no_perform", 3);
         		target->apply_condition("no_enforce", 3);
         		target->set("jiali", 0);
         		me->start_busy(1);
        	}
        }
        return 1;
}  

