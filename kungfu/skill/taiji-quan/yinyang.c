// yinyang.c ̫��ȭ������������
// by snowman@SJ 26/02/2000
// Modified by snowman@SJ 24/05/2001

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

#define TAIJI                "/kungfu/skill/yinyun-ziqi/taiji"

int is_pfm() {return 1;}
string perform_name(){ return HIR"������"NOR; }

int perform(object me, object target)
{ 
	if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( userp(me) 
        &&( me->query_skill_mapped("parry") != "taiji-quan"
        && me->query_skill_mapped("parry") != "taiji-jian") )
                return notify_fail("������������������̫��ȭ��̫���������мܵ�����²���ʹ�á�\n");
        if( userp(me) && (me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill_prepared("cuff") != "taiji-quan") )
                return notify_fail("����ڹ���ȭ�����ԣ��������ܷ��ӳ����������������ơ�\n");  
        if( !me->query_temp("tj/̫��") && me->query_skill("taiji-quan", 1) < 300 )
                return notify_fail("̫���ߣ��޼�����������֮ĸҲ����û�����á�̫�������������ʹ�á�����������\n");
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("����������������ǿ��ʹ�á����������Ƿ��Ӳ������������ģ�\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
        
        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
        int damage = 1, ap, dp;
        string msg, force, str;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 300 || me->query("jingli") < 100 || me->query_temp("weapon"))
        	return 0;     
                
        if(intp(me->query_temp("tjq/"+target->query("id")) > 4))
		me->add_temp("tjq/"+target->query("id"), -4);
	else me->delete_temp("tjq/"+target->query("id"));
	
        str = (string)me->query("env/���Ͼ�"); 
        if(str != "�귭" && str != "����" && str != "����" && str != "����" && str != "����" && str != "����")
        	str = "��";
        	
        msg = GRN"\n$Nʹ��̫��ȭ��"RED"����������"GRN"�Ĺ���";
        
        if(me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill("yinyun-ziqi", 1) < 100){
        	msg += "��������������ס$n��\n"NOR;
        	str = "��";
        }        
        
        else msg += "����һ��ԲȦ����������������������$n˫�֣�\n"NOR;
        
       	if( TAIJI->check_force(target) == str || me->query_skill("taiji-quan", 1) > 350 )
        	damage = 3;
       
        me->start_perform(2, "����������");
        if(!stringp(force = to_chinese(target->query_skill_mapped("force"))))
        	force = "�ڹ�";
        	
        if(wizardp(me) && (string)me->query("env/combat")=="verbose")
		tell_object(me, "Str = "+str+"��Force = "+force+"��Damage = "+damage+"\n");

	ap = me->query("combat_exp", 1) * me->query_con(1);
	dp = target->query("combat_exp", 1) * target->query_con(1);

	if ( target->is_busy())
		dp -= dp/2;

	if( random(ap + dp ) > dp ){
		msg += HIY"$n�ۿ����ԣ��������Ƿ���һ����\n"NOR;
		me->start_perform(5, "����������");
		me->add_busy(2);
		target->add_busy(2);
		call_out("hurt", 2,  me, target, damage, str, force, target->query("jiali"));	
	}
	
        else{
		msg += HIY"����$p��Ȼ�������죬һ�����������ˡ����������ķ�Χ��\n"NOR;
		me->add("neili", -100);
		me->add("jingli", -50);
		me->start_busy(random(2));
	}

        message_vision(msg, me, target);
        return 1;
}

int hurt(object me, object target, int damage, string str, string force, int jiali)
{
        string msg;
	int i;
	
	if( !me || !living(me) || me->is_ghost() || !me->is_fighting()) return 0;
	
        if( !target || !target->is_character() || !me->is_fighting(target) || damage < 1
        || environment(target)!=environment(me))
                return 0;
        
        switch(str){
        	case "�귭": msg = GRN"\n$N���ִ���$n�����ϣ����ִ���$p�����ϣ�̫��ȭ��"HIW"��"+str+"����"GRN"ʹ����˳��һ��һ������$n˫�ֵ�"+force+"����һ��\n"NOR;break;
        	case "����": msg = GRN"\n$N˫�ֽ�$n������ץסһת��ʹ�������Ͼ����е�"HIW"��"+str+"����"GRN"����$n����"+force+"����˫��������\n"NOR;break;
        	case "����": msg = GRN"\n$N˫����$p����һ�ģ�$n���ϻر۵��������"+force+"һ�±�"HIW"��"+str+"����"GRN"��ס��˫��Ӳ��������һ��\n"NOR;break;
        	case "����": msg = GRN"\nֻ��$N˫�Ʒɷ���žž��������$n˫���ڲ࣬"HIW"��"+str+"����"GRN"����$n��"+force+"����$p˫�����ÿ���ֱ�죡\n"NOR;break;
        	case "����": msg = GRN"\n$N˫�Ʋ�����$nһ�´�����ֻ��ȫ��"+force+"��"HIW"��"+str+"����"GRN"�����֣�˫���޿����ܣ�����һ��\n"NOR;break;
        	case "����": msg = GRN"\n$N˫�����Ʒ��ɣ���Ȼһ�´�ס$n˫�֣�"HIW"��"+str+"����"GRN"�޼����������$n˫�۵�"+force+"����һ��\n"NOR;break;
        	default: msg = CYN"\n$N˫����ס$n˫�ƣ�������һ������һ��\n"NOR;break;
        }
        
        
        if (target->query("neili") <= 200){
        	message_vision(msg, me, target);
		tell_object(target, "�㷢���Լ�������Ȼ�ݽߺľ��������޷��࿹�ˣ�\n");
		target->receive_damage("qi", (int)target->query("qi")+1, me);
		msg = RED"���$N���ֲ��������Լ��ľ������ͷ��Ŀѣ��ҡҡ��׹��\n"NOR;
                msg += damage_msg(target->query("max_qi"), "����") + "( $N"+status_msg(5)+" )\n"; 
		message_vision(msg, target, target);
		me->start_busy(1);
		me->start_perform(2, "����������");
        	return 1;
	}
	
	
	else if(me->query("neili")*3 < target->query("neili")) {
		me->start_busy(1+random(2));
		me->start_perform(2, "����������");
		msg += HIR"����$p�����ۺ�$P˫�ֱ�����ȥ���ֱ���ľ�˰��죡��\n"NOR;  
		message_vision(msg, me, target); 
        	return 1;
	}
	
	message_vision(msg, me, target);
	if(wizardp(me) && (string)me->query("env/combat")=="verbose") 
		tell_object(me, "Damage ="+damage+"\n");
	
	target->set_temp("must_be_hit", 1);
	target->set("have_master", 1);
	i = target->query("jiali");
	target->set("jiali", jiali);
        COMBAT_D->do_attack(target, target, target->query_temp("weapon"), damage);
	target->receive_wound("jing", me->query_int(1)*2+ me->query_con(1)*2, me);
        if( random(2))
        	COMBAT_D->do_attack(target, target, target->query_temp("weapon"), 1);
	target->receive_wound("jing", me->query_int(1)*3+ me->query_con(1)*3, me);
        target->set("jiali", i);
        target->delete("have_master");
        target->set_temp("last_damage_from", me);
	target->delete_temp("must_be_hit", 1);

	me->start_perform(3, "����������");

        if( !me->is_killing(target->query("id"))
	&& !target->is_killing(me->query("id"))
	&& !me->query("have_master")   // added by snowman
	&& target->query("qi")*2 <= target->query("max_qi")) 
		COMBAT_D->end_fight(me, target);
		
        return 1;
}

int help(object me)
{
	write(WHT"\n̫��������������"NOR"\n");
	write(@HELP
	̫��ȭ������̫���ߣ��޼�����������֮ĸҲ��������ã���Ϊ����������
	����������������֮���������ں��������������������������ֿ죬�ǽ�
	������Ȼ֮��������ǧ��Ҳ���������ߣ��ز���֮���������ڵС�
	���жԸ�������֮����Ϊ��Ч��
	
	Ҫ��	���� 1000 ���ϣ�      
		���� 100 ���ϣ�      
		����̫��ȭ�������ޱ�����
HELP
	);
	return 1;
}
