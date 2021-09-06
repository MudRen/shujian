// chan.c ̫�������������־�
// Created and Modified by snowman@SJ 23/02/2001

#include <ansi.h>
inherit F_SSERVER;

string perform_name(){ return HIW"������ƾ�"NOR; }

int checking(object me, object target, object weapon);

string *number_msg = ({"һ","��","��","��","��","��","��","��","��","ʮ","ʮ��","ǧ��","����"});
string *sword_msg = ({"����","б��","����","�»�","����","ֱ��","����","ǰ��"});

string *chan_msg = ({
CYN"$N����Ԧ����$S����$R��"RED"ԲȦ"CYN"����ǧ���򻯣������޾���Ҫȥ������ס$n��\n" NOR,
CYN"$N����Ԧ�������಻�ϵ�$S����$R��"RED"ԲȦ"CYN"��ǰ�����У�Ҫ��$n����������\n" NOR,
CYN"$N���в��������ң�����Ԧ����$W"CYN"ÿ��һ�У����Ʒų�һ��"RED"ϸ˿"CYN"��Ҫȥ��ס$n��\n"NOR,
CYN"$N���ι�һ������Ԧ����$S����$R��"RED"ԲȦ"CYN"�������ཻ��Ҫ��$n�������У�\n" NOR,
CYN"$N����$W"CYN"�Ӷ�����̫������ɢ��������"RED"ϸ˿"CYN"��Ҫ��$n��������\n"NOR,
CYN"$N����Ԧ����$Sһʽ������$R��"RED"ԲȦ"CYN"�����°��ݣ�Ҫ��$n����������\n" NOR,
CYN"$N��һ��$W"CYN"����һ����"RED"ԲȦ"CYN"��ÿһ�о����Ի��δ̳����Ի����ջأ���ס$n��\n"NOR,
CYN"$N����Ԧ��������$S����$R��"RED"ԲȦ"CYN"�����Ҽ�ˣ�Ҫ��$n�������У�\n" NOR,
});

string *dodged = ({
HIY"����$n��Ȼ������$P����������עһ��ֱ��Ȧ�ģ�����$N��̫�����⣡\n\n" NOR,
HIY"$n΢��$N����ɬ�ͣ���æ���У��߾�ȫ��֮���й��������ӽ���Ȧ�г��˳�ȥ��\n\n"NOR,
HIY"$n΢��$N����ɬ�ͣ���æ���У��߾�ȫ��֮����Ծ���ˣ�Զ���˽�Ȧ��\n\n"NOR,
HIY"$n�������У����е�����$N�й�һ������������һԾ�����ӳ�Ȧ�⡣\n\n"NOR,
});

string *chaned = ({
HIW"���$n����������ɬ�ͣ�ż������һ�У������˵ò��㣬�㱻$W"HIW"������ת����Ȧ�ӡ�\n"NOR,
HIW"���̫������ɢ������ϸ˿Խ��Խ�࣬���ǻ�����һ����˿�ޣ���$n��������������\n"NOR,
HIW"������������ǻ�����һ����˿�ޣ���$n��������������\n"NOR,
HIW"$nԽ��Խ�Ǻ��£�һ���������̫�������������������\n"NOR,
});

int check_fight(object me, object target, object weapon);

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(!living(target))
		return notify_fail("���������ܶ����ˣ�\n");

	if(!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������ʹ�á������־���\n");

	if( me->query_temp("tjj/chan"))
		return notify_fail("������ʹ�á������־���\n");

	if( me->query_temp("tjj/lian"))
		return notify_fail("������ʹ������\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	if( (int)me->query_skill("taiji-jian", 1) < 100 )
		return notify_fail("���̫��������������죬����ʹ�á������־���\n");

	if( me->query("neili") <= 500 )
		return notify_fail("�������������\n");

	if( me->query("max_neili") <= 1000 )
		return notify_fail("���������Ϊ������\n");

	if( me->query_temp("combat_yield"))
		return notify_fail("�㲻����������ʹ�á������־���\n");

	if( me->query_skill_mapped("sword") != "taiji-jian")
		return notify_fail("�������޷�ʹ�á������־���\n");

	if(userp(me)){
		if (me->query_skill_mapped("parry") != "taiji-jian")
			return notify_fail("�������޷�ʹ�á������־���\n");       
		if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
			return notify_fail("����ڹ���Ϊ����������ʹ�á������־���\n");
		if( me->query_skill_mapped("force") != "yinyun-ziqi")
			return notify_fail("�����õ��ڹ���̫��������·��㣣�\n");
	}

	message_vision(CYN"\n$Nʹ��̫������"RED"������"CYN"�־���һ��"+weapon->name()+CYN"�ڻ���һ����ԲȦ��ÿһ�о����Ի��δ̳��������ջء�\n"+
				"���ڽ��ȣ����಻��������������һ�Ŵ���������$n�ս���\n\n"NOR, me, target);
	me->set_temp("tjj/chan", 1);
	checking(me, target, weapon);
	return 1;
}

int check_fight(object me, object target, object weapon)
{
        string msg;
        object wep;
	int i = 3;

        if (!me || !me->query_temp("tjj/chan")) return 1;

	me->start_perform(1, "��");
	me->delete_temp("tjj/chan");

	if ( !living(me)) return 1;

	if( me->query_skill("taiji-jian", 1) > 450 ) i = 2;
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){ 
                if(!wep) msg = HIY"$N����������ʧ��Բת��̫����ĻҲ��֮��ɢ��\n"NOR;
                else if(!target) 
                         msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��������ɢ����̫�����⣮\n"NOR;
                else  msg = HIY"$N����"+wep->name()+HIY"������̫�����⣬$n����ܲ��Ľ�ĻҲ��֮��ɢ��ѹ����Ȼ���ᣡ\n"NOR;
                me->start_busy(random(2));
                if(target->is_busy()) target->start_busy(1);
        } 
        else if(!target) 
                msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��������ɢ����̫�����⣮\n"NOR;
        
        else if(environment(me) != environment(target))
        	msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��������ɢ����̫�����⣮\n"NOR;

        else if(!living(target) || (!me->is_fighting(target) && !me->is_killing(target->query("id")))){
                if(target && !living(target)) msg = HIY"$N��м������$nһ�ۣ�������"+wep->name()+HIY"һ���ڣ�������ɢ���Ľ�Ļ��\n"NOR;
                else msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��������ɢ����̫�����⣮\n"NOR;
        }           

        else if(wep != weapon && target->is_busy() 
                && random(me->query_skill("taiji-jian", 1)) < (int)target->query_skill("dodge", 1)/2){
                msg = HIY"$N���󻻽������ƶ�ʱ�޷�Բת���⣬$n��ߵ�̫����Ļ���������ʹ$n���˴�Ϣ֮���ᣡ\n"NOR;
                if(target->is_busy()) target->start_busy(1);
                me->start_busy(random(2));
       	}
       	else if (userp(me) && (me->query_skill_mapped("sword") != "taiji-jian" || me->query_skill_mapped("parry") != "taiji-jian")){
                msg = HIY"$NͻȻ���У����ƽ�Ļ��ʹ����̫��������ȫ��ͬ����������\n"NOR;
                if(target->is_busy()) target->start_busy(1);
                me->start_busy(random(2));
       	}   
       	else if( me->query("neili") <= me->query_skill("taiji-jian", 1)/2 ){
                msg = HIY"$N���н���ɬ�ͣ�ż��һ���̳���Ȼ����������ԭ�������������ˣ�\n"NOR;
                me->start_busy(random(2));
                if(target->is_busy()) target->start_busy(1);
       	}           

       	else if(!target->is_busy() && !me->is_busy() && random(i)==1 && living(target)){ 
                checking(me, target, wep);
                return 1;
       	}
       	else {
       	        me->set_temp("tjj/chan", 1);
       	        call_out("check_fight", 1, me, target, wep);
       	        return 1;
       	}
       	message_vision(msg, me, target);  
       	return 1;
}       


int checking(object me, object target, object weapon)
{
       	string msg;
       	int ap, dp, cost;
       
       	cost = me->query_skill("taiji-jian", 1)/2;
       	ap = me->query("combat_exp")/10000 * me->query_skill("taiji-jian",1) * me->query_int(1);
       	dp = target->query("combat_exp")/10000 * target->query_skill("dodge",1) * target->query_int(1);
       	if (ap < 1) ap = 1;
       	if (dp < 1) dp = 1;
     	if( cost * 2 > 450 ) ap += random(ap/2);
       
       	msg = chan_msg[random(sizeof(chan_msg))];
       	msg = replace_string(msg, "$S", sword_msg[random(sizeof(sword_msg))]);
       	msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
       	msg = replace_string(msg, "$W", weapon->name());
                
       	me->add("neili", -350);
       	me->add("jingli", -100);
       	if( random(ap + dp) > dp ){          
                target->start_busy(3+random(cost/10));
                msg += chaned[random(sizeof(chaned))];
                msg = replace_string(msg, "$W", weapon->name());
                me->set_temp("tjj/chan", 1);
		me->start_perform(1, "��");
                call_out("check_fight", 1, me, target, weapon);
       	}
       	else{
                me->start_busy(2+random(2));
                msg += dodged[random(sizeof(dodged))];
                msg = replace_string(msg, "$W", weapon->name());
                me->delete_temp("tjj/chan");
       	}
       	message_vision(msg, me, target);
       	return 1;
}       

int help(object me)
{
	write(HIW"\n̫���������־�����"NOR"\n\n");
	write(@HELP
	̫������Բת���ϣ����಻�����ٵ���֮������Ԧ����ʹ���������־�ÿ��
	һ�У����Ʒų�һ��ϸ˿����ס���֣�ǧ���򻯣������޾���ʹ���޷�������
	���ҿ����Զ���������������ֱ�����ܶ��֡�
	
	Ҫ��	������� 1000 ���ϣ�      
		���� 500 ���ϣ� 
		̫�����ȼ� 100 ���ϣ�
		�������ȼ� 100 ���ϣ�
                ��������Ϊ̫��������
                �����м�Ϊ̫��������
                �����ڹ�Ϊ��������
		��δ���ƴ򲻻��֡�     

HELP
	);
	return 1;
}
