//yiyang-zhi's perform qianlong
//Ǳ������
//COOL@SJ,20000401

#include <ansi.h>
inherit F_SSERVER;
int qianlong_hit(object me, object victim, object weapon, int damage);
 
string perform_name() {return WHT"Ǳ������"NOR;}

int perform(object me, object target)
{       
        string msg;
        
        if( !target ) target = offensive_target(me);
 
        if( !objectp(target)
         || !target->is_character()
         || !present(target,environment(me)) )
                return notify_fail("��Ǳ�����á���\n");
        if( !living(target) )
        	return notify_fail("�Է��Ѿ��ι�ȥ�ˡ�\n");
 
 	if( me->query_temp("yyz_ql") ){ 
 		if( !me->is_fighting(target) )
 			return notify_fail("��ֻ�ܶ�ս���еĶ��ֳ���Ǳ�����á���\n"); 
 		write("��һ������׼���á�Ǳ�����á��ˡ�\n");
 		me->start_call_out( (: call_other, __FILE__, "main", me, target :), 2);
 		return 1;
 	}
 	
 	if( target->query_temp("yyz_ql/recive") )
 		return notify_fail("�����Ѿ����ܲ�����ġ�Ǳ�����á������ˡ�\n"); 
 		
        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target))
                return notify_fail("��Ǳ�����á�ֻ����ս����ʹ�á�\n");
        if( !living(target) )
        	return notify_fail("�Է��Ѿ��ι�ȥ�ˡ�\n");
        
        if( me->query_temp("weapon") )
                return notify_fail("ֻ�п��ֲ���ʩչ��Ǳ�����á���\n"); 

        if( (int)me->query_skill("yiyang-zhi", 1) < 160 ||
            (int)me->query_skill("finger", 1) < 160 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á�Ǳ�����á���\n");

        if(!me->query_skill("kurong-changong", 1))
           	if(me->query_skill("qiantian-yiyang", 1) < 160)
                	return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������Ǳ�����á���\n");        
         
        if (me->query_skill_mapped("force") != "kurong-changong" )
            	if (me->query_skill_mapped("force") != "qiantian-yiyang")
                	return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi" || 
            me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ����Ǳ�����á����й�����\n");                                                                                 
      
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ̫��������ʹ�á�Ǳ�����á���\n");

        if( (int)me->query("neili") < (int)me->query("max_neili")*3/2 )
                return notify_fail("�������������\n");
        
        if( (int)me->query("jingli") <= (int)me->query("max_jingli")*3/2 )
                return notify_fail("��ľ���������\n");
        
        
        if ((string)me->query("class")=="bonze")
         	msg = WHT "\n$N��Ȼ�ͻ���һ����"+target->name()+",����������ǧ����ħ������������˿�ش�����"NOR;    
	else 	msg = WHT "\n$N��Ȼ���һ����"+target->name()+",��������������������˫�������ˡ����졣"NOR; 
        tell_object(target, WHT"��ֻ��ü��ӡ�ü���һ��������Ҫ���Լ���˫ü˺��һ�㡣\n"NOR);
        msg += WHT "$n����һ����$N��һ���䣬$nɲ�Ǽ��������⣬���ڶ�ǰ,ȴ������������һ����$Nһָ������$n�����ġ�\n"NOR, me, target;
        
        message_vision(msg, me, target);
        
        if( target->query_skill("force") < me->query_skill("finger")/3 ){
        	tell_object(target, "����Ȼ�����Ƶ�ס����һָ����һ�����������Ʊ�Ѹ������ü�ģ���ֻ��ͷ�����ǣ���ǰһ�ڡ�������\n");
        	target->unconcious();
        	tell_object(me, "����һָ���У�����ԴԴ���ϵ����룬ȴ���ֶԷ������޷�������ľ���,��æ��ֹ����һʽ��\n");
        	me->set("neili",(int)(me->query("neili")/2));
        	me->set("jingli",(int)(me->query("jingli")/2));
        	me->apply_condition("no_exert", (int)(me->query_skill("finger")/40));   
        }

        if( target->query_skill("yiyang-zhi") )
        	target->set_temp("yyz_ql/lvl", me->query_skill("yiyang-zhi")/2 );
        else 
        	target->set_temp("yyz_ql/lvl", me->query_skill("yiyang-zhi")/4 );

	target->set_temp("yyz_ql/recive", 1);
	tell_object(target, "����Ȼ�����Ƶ�ס����һָ����һ�����������Ʊ�Ѹ������ü�ģ�����ȫ��������������о���һ�����������ڼ�����\n");
	me->set("neili",0);
        me->set("jingli",0);
       	tell_object(me, "����һָ���ľ������е�Ԫ����ֻ�����Լ�ƣ��֮���������˾���һ��ͻȻ���˵���ľһ�㡣\n");
        tell_object(target,me->name()+"������ƣ��֮���������˾���һ��ͻȻ�����˵���ľһ�㡣\n");
        me->apply_condition("no_exert", (int)(me->query_skill("finger")/35));
        target->start_call_out( (: call_other, __FILE__, "remove_qianlong", target :), 20+random(40) );
       	return 1;
}

void remove_qianlong(object ob)
{ 
	if( !ob ) return;
	if( !ob->query_temp("yyz_ql/recive") ) return;
	ob->delete_temp("yyz_ql");
	tell_object(ob, "�����ڵ��ǹ�����������ɢ�ˡ�\n");
}

int main(object me, object target)
{ 
        int i;
        mapping action;
	        
        if( !me ) return 0;
         
        if( me->is_ghost() || !living(me) ){    
        	me->delete_temp("yyz_ql");
                return 1;
        }
        if( !me->is_fighting() ) return 0;

	if( !target || !living(target) || environment(target) != environment(me) || !me->is_fighting(target) ){
		write("��ŷ��������Ѿ�û���ˡ�\n");
		return 1;
	}
	
        if( me->query_temp("weapon") ){
		write("��÷����������ܳ���Ǳ�����á�����\n");
		return 1;
	}
        
        if( ((int)me->query("eff_qi")* 100 / (int)me->query("max_qi")) > 40 ){
		write("��Ǳ�����á���ƴ���������������ؼ�ʱ���ðɡ�\n");
		return 1;
	}
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();
		action = me->query("action");
		if( !mapp(action) ) {
			CHANNEL_D->do_channel( this_object(), "err",
				sprintf("%O(%s): bad action = %O", me, me->query("id"), me->query("actions", 1)));
			write(HIR"���棺Combat action ������֪ͨ��ʦ -> Yiyangzhi PFM qianlong.\n");
			return 0;
		}
	}
	action += ([ "post_action": (: qianlong_hit :) ]);
	me->set("actions", action);
	me->delete_temp("yyz_ql");
        i = me->query_temp("yyz_ql/lvl");
        message_vision(RED "$N���˼��أ���æ�����ֵ���ͻȻ֮�䣬$Nü��Ѩһ����ȣ�����������ֱ�����������������Ӷ�������������Ѹ������һ��������ڴ�������Ϊһ���ڳ�������Ϊ����$N����һ�м���������;����Ϊָ��֨����һ����ָ���ƿն�����\n\n"NOR, me,target);     
	me->add_temp("apply/attack", i);
	me->add_temp("apply/damage", i/2 );
	COMBAT_D->do_attack(me, target, 0, 1);
	me->add_temp("apply/attack", -i);
	me->add_temp("apply/damage", -i/2 );
	return 1;                 

}

int qianlong_hit(object me, object victim, object weapon, int damage)
{    	
     	if(!victim ) return 0;
     	if( damage == -1 || damage == -2 ){
     		message_vision(WHT "\n\n$n����$N��Ȼʹ��һ��һ��ָ��������ף�ָ�籾����Ϊ��΢��һ�����Լ��Ļ������������Ϊ�񾢣���������һ����\n"+
                "���ƶ��룬$nһ��֮�£�ָ����ֱ��ü�ģ�$n���ֲ�������һ�����С�\n"NOR, me, victim);   
         	victim->apply_condition("no_exert", victim->query_condition("no_exert") + 5);
        }
	
        else {
                message_vision(WHT "\n$n����$N��Ȼʹ��һ��һ��ָ��������ף�ָ�籾����Ϊ��΢��һ�����Լ��Ļ������������Ϊ�񾢣���������һ�������ƶ��룬$nһ��֮�£�\n"
                +"ָ����ֱ��ü�ģ�$nӦ�����٣����Ƶ�������֮�������������£������Ʊ����ڶ�ǰ����ž����һ����ָ�������������ڡ�$n�������˾�ȫ����\n"
                +"����ָ�磬�����ּ���֧�ţ�����һ��ָ�磬�������أ��������ƿ�֮��һ�α�һ�θ��ң���Ȼ��һС�����ھ�͸��ü��ҪѨ��\n"NOR, me, victim);        
                victim->apply_condition("no_exert", victim->query_condition("no_exert") + 1);
                victim->apply_condition("no_perform", victim->query_condition("no_perform") + 1);
        }
        return 1; 
}
