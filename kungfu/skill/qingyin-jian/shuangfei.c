// shuangfei.c ˫������Ӱ
// Created by snowman@SJ 18/03/2001

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

int is_pfm() { return 1;}

#define PFM_NAME 	"˫������Ӱ"
string perform_name(){ return HIM+PFM_NAME+NOR; }

int perform(object me, object target)
{     
      	if( (int)me->query_skill("qingyin-jian",1) < 120 )
           	return notify_fail("�����������������죬����ʹ��" + PFM_NAME + "��\n");
      
      	if( (int)me->query_skill("sword",1) < 120 )
           	return notify_fail("��Ļ��������ȼ�����������ʹ��" + PFM_NAME + "��\n");  
      
      	if( (int)me->query_skill("sancheng-gong", 1) < 120 )
           	return notify_fail("������˹����ȼ�����������ʹ��" + PFM_NAME + "��\n");

      	if (me->query_skill_mapped("force") != "sancheng-gong")
           	return notify_fail("����ʹ�õ��ڹ��������˹�����\n");

      	if( (int)me->query("max_neili") < 1000 )
           	return notify_fail("�������̫��������ʹ��" + PFM_NAME + "��\n");
      
      	if( (int)me->query("neili") < 500 )
           	return notify_fail("�������̫���ˣ��޷�ʹ�ó�" + PFM_NAME + "��\n"); 
        
        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
	object weapon;
	int modify, damage, ap, dp;
	string msg, *limbs, limb;
	
	if( !target ) target = offensive_target(me);
     
      	if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 500 || me->query("jingli") < 100 
        || environment(target) != environment(me) )
                return notify_fail("��Ŀǰ�޷�ʹ�á�" + PFM_NAME + "����\n");   
                	
	weapon = me->query_temp("weapon");
      	if (!weapon
       	|| weapon->query("skill_type") != "sword"
       	|| me->query_skill_mapped("sword") != "qingyin-jian" )
       		return notify_fail("�������޷�ʹ��" + PFM_NAME + "��\n");      
       		
       	modify = (int)me->query("emei_pfm/qingyin") + (int)me->query_temp("apply/qingyin");

	ap = me->query("combat_exp")/100000 * me->query_skill("qingyin-jian",1) * me->query_dex();
       	dp = target->query("combat_exp")/100000 * target->query_skill("parry",1) * target->query_dex();
       	if (ap < 1) ap = 1;
       	if (dp < 1) dp = 1;
       	if( modify > 1 )
		ap += ( ap / 10 * modify );
		
	if( wizardp(me) && me->query("env/debug") )
		write("AP: " + ap +"��DP: " + dp +"��Modify: " + modify +"\n");
		
	me->add("neili", -350); 
      	me->add("jingli", -50); 
	msg = HIW"\n$N��Хһ�����������߿���ȥ����������μ�ת�����е�" + weapon->name() + HIW"����������ھ�����������һ��һ��������â��\n";
	switch(modify){
		case 0:
		case 1: break;
		case 2..4: 
			msg += HIW"���ⷴ���£�ǡ����������ˮ��������ͷ׵�"HIG"�ʺ�"HIW"��һ��һ����ֱϮ$n��\n"; break;
		case 5..7: 
			msg += HIW"���â����ˮ����һ����������"HIC"ˮ��"HIW"�������ڿ��У�������ˮ�ɢ��$n��\n"; break;
		case 8..10: 
			msg += HIW"������ľ����˲ʱ�޷��Զ����ǹ�â�羪����ʯ�����������"HIB"����"HIW"����$n��ӿ�Ļ���\n"; break;
		default: msg += HIW"ɲ�Ǽ䣬�ǹ�â���ؽ����壬�������٣�����ɻ����񣬡�" + perform_name() + HIW"���Ѵ������\n"; break;
	}
	
      	message_vision(msg+NOR, me,target);
      	
      	me->add_temp("apply/attack", 50);
      	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      	me->add_temp("apply/attack", -50);
      	
      	me->start_busy(1);
      	target->start_busy(1);
      	me->start_perform(7, PFM_NAME);
      	if( random(ap + dp) > dp ){
      		msg = HIY"\n$n������������ʼ�հ��Ѳ�����˫�ɾ�����$p����һ�ᣬ�˹�ȫ��׼��Ӳ���ˣ�\n"NOR;
      		if (target->query("neili") <= 50){
			tell_object(target, "����Ȼ�����Լ�������Ȼ�ݽߺľ����޷��˾��࿹�ˣ�\n");
			msg += RED"���ֻ��$nһ���ҽУ����ʽ��˽���֮�У���ʱȫ��Ѫ���ɣ��ۼ��ǻ���ˣ���\n"NOR;
			target->receive_damage("qi", (int)target->query("qi")+1, me);
                	msg += "( $n"+eff_status_msg(1)+" )\n";   
			message_vision(msg, me, target);
			return 1;
		}
		else if( me->query("neili") * 3 < target->query("neili") ) {
			msg += HIR"����$p�ڹ������һ��֮�£�ֻ���˵����ˣ���\n"NOR;
			damage = (int)me->query_dex() * (modify + 1);
			target->receive_damage("qi", damage, me);
			msg += "( $n"+eff_status_msg((int)target->query("qi")*100/(int)target->query("max_qi"))+" )\n";   
			message_vision(msg, me, target);
     			return 1;
     		}
     		else {
     			limbs = target->query("limbs");
        		limb = limbs[random(sizeof(limbs))];
     			damage = me->query_skill("sword") + (weapon->query("weapon_prop/damage") * 2);
     			damage += modify * (me->query_dex() * 4 + me->query_str() + me->query("jiali") );
     			if( me->query("neili") > target->query("neili") * 2 )
     				damage *= 2;
     			else if( me->query("neili") > target->query("neili")/2*3 )
     				damage += random(damage);
     			else if( me->query("neili") > target->query("neili") )
     				damage += random(damage/2);
     					
     			if( wizardp(me) && me->query("env/debug") )
				write("Damage: " + damage +"\n");

     			target->receive_damage("qi", damage, me);
     			target->receive_wound("qi", damage/2 + random(damage/2), me);
        		msg += damage_msg(damage, "����") + 
        			"( $n"+eff_status_msg((int)target->query("qi")*100/(int)target->query("max_qi"))+" )\n"; 
        		msg = replace_string(msg, "$l", limb);
                   	msg = replace_string(msg, "$w", "˫�ɽ���"); 
                   	message_vision(msg, me, target);
                   	return 1;
                }
        }

        if( random(2) )
        	message_vision(YEL"\n$nע����$N��ÿһ��������ͻȻһ�µ����Ծ���ѳ���" + PFM_NAME + "�ķ�Χ��\n"NOR, me, target);
        else {
        	msg = target->query_skill_mapped("dodge");
	     	if( !msg ) msg = "dodge";
             	message_vision("\n"+SKILL_D(msg)->query_dodge_msg(target, 1), me, target);
        }

	if( random(2) && me->is_fighting(target) ){
		me->add_temp("apply/attack", 50);
      		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      		me->add_temp("apply/attack", -50);
	}

      	return 1;
}

int help(object me)
{
	write(HIG"\n\t����������" + perform_name() + HIG"����"NOR"\n");
	write(@HELP
			˫������Ӱ�����һţ��
			
	��������������֮һ������ڵ�����ô���֮��������˫����������
	���ϡ�������ڰ׶�ˮ��ţ��ʯ���Ƕ�üɽʮ��֮һ���侪����ʯ������
	�ɻ�����������ѩ��ˮ����һ����������ˮ�飬�����ڿ��У�������
	ˮ�����ӳ�䣬˫����������ˮ����ǡ����������ͷ׵Ĳʺ硣�˽�ʽ
	��Ҫ�����������������ƻõľ��磬����Խ�࣬����Խ��
	
	Ҫ��	
		���������ȼ� 120 ���ϣ�
		���������ȼ� 120 ���ϣ�
		���˹����ȼ� 120 ���ϣ�
		������� 1000 ���ϣ� 
		���� 500 ���ϡ�
HELP
	);
	return 1;
}

