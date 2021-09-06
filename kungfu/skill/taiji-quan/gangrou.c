// gangrou.c ̫��ȭ�����������
// by snowman@SJ 26/11/1999
// Modified by snowman@SJ 08/05/2001


inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

#define TAIJI	"/kungfu/skill/yinyun-ziqi/taiji"

int is_pfm() {return 1;}
string perform_name(){ return HIR"�����"NOR; }

int perform(object me, object target)
{ 
	if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( userp(me) 
        &&( me->query_skill_mapped("parry") != "taiji-quan"
        && me->query_skill_mapped("parry") != "taiji-jian") )
                return notify_fail("�����������������̫��ȭ��̫���������мܵ�����²���ʹ�á�\n");
        if( userp(me) && (me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill_prepared("cuff") != "taiji-quan") )
                return notify_fail("����ڹ���ȭ�����ԣ��������ܷ��ӳ���������������ơ�\n");  
        if( !me->query_temp("tj/̫��") && me->query_skill("taiji-quan", 1) < 300 )
                return notify_fail("̫��ȭ��Ҫ���������׼�����糵�֣���û�����á�̫�������������ʹ�á����������\n");
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("����������������ǿ��ʹ�á���������Ƿ��Ӳ������������ģ�\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
        
        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
        int damage = 1, j, ap, dp;
        string msg, str;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 1000 || me->query("jingli") < 200 || me->query_temp("weapon")){
        	write("��Ŀǰ�ò��ˡ����������\n");
		return 1;
        }                

	if( target->query_condition("neishang") ){
		write("�Է��Ѿ��������ˣ��㲻�����á���������ˡ�\n");
		return 1;
	}
	if(intp(me->query_temp("tjq/"+target->query("id")) > 4))
		me->add_temp("tjq/"+target->query("id"), -4);
	else me->delete_temp("tjq/"+target->query("id"));
	              
        str = (string)me->query("env/���Ͼ�"); 
        if(str != "�귭" && str != "����" && str != "����" && str != "����" && str != "����" && str != "����")
        	str = "��";
        	
        msg = HIB"\n$Nʹ��̫��ȭ��"RED"���������"HIB"�Ĺ���";
        
        if(me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill("yinyun-ziqi", 1) < 100){
        	msg += "����һ��������$n��\n"NOR;
        	str = "��";
        }        
        
	else msg += "����һ������$n���к�Ԫ����ȭ·������֮����֮���򣬱仯������\n"
		+"��Ī�ܲ⣬�������ģ�����̫�������\n"NOR;
        
        if( TAIJI->check_force(target) == str || me->query_skill("taiji-quan", 1) > 350 )
        	damage = 3;
       
        me->start_perform(2, "���������");

	me->add("neili", -100);
	me->add("jingli", -50);
	me->start_busy(1);
	if(!target->is_busy()) target->start_busy(1);

	ap = me->query("combat_exp")/ 100 * me->query_kar();
	dp = target->query("combat_exp")/100 * target->query_kar();

	if( random(ap + dp) > dp ){
		msg += HIY"$n�ۼ�$P�������ٺ�һЦ��̧�־ͷ�ס��$N��һ�ƣ�\n"NOR;
		me->add("neili", -100);
		me->add("jingli", -50);
		call_out("hurt", 0, me, target, damage);	
	}

	else if( random(ap) > dp/3 ){
		damage *= (me->query_skill("cuff") + me->query("jiali") + me->query_skill("wudang-jiuyang",1) ) * 2;

		target->receive_damage("qi", damage, me);
        	target->receive_wound("qi", damage/3, me);
        	j = (int)target->query("qi")*100/(int)target->query("max_qi");
        	msg += damage_msg(damage, "����")+"( $n"+eff_status_msg(j)+" )\n"; 
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
		me->add("neili", -150);
		me->add("jingli", -50);
	}
        else {
		msg += HIY"����$p�����ϵ�������һ�ˣ������ˡ����������\n"NOR;
	}
        message_vision(msg, me, target);
        return 1;
}

int hurt(object me,object target, int damage)
{
        string msg;

	if ( ! me) return 0;

        if( !target || !target->is_character() )
                return 0;
                
        msg = HIR"\nͻȻ$Nȫ��һ����Ϣ���ڣ�ԭ���Ǳ�������������ֵ��ᾢ�����ˣ�\n"NOR;
        if( target->query("neili") <= 50 || target->query("qi") <= 100 ){
		tell_object(target, "����Ȼ�����Լ�������Ȼ�ݽߺľ����޷��˾��࿹�ˣ�\n");
		msg += RED"���ֻ��$N�͵ؿ�����Ѫ���磬ȫ��������ѣ��ۼ��ǻ���ˣ���\n"NOR;
		target->receive_damage("qi", (int)target->query("qi")+1, me);
		target->set("eff_qi", 10);
                msg += "( $N"+eff_status_msg(1)+" )\n";   
	}
	
	else if( target->query_skill("force") > 450 ) 
		target->apply_condition("neishang", 7 * damage);
	else target->apply_condition("neishang", 13 * damage);
	message_vision(msg, target);
        return 1;
}

int help(object me)
{
	write(WHT"\n̫�������������"NOR"\n");
	write(@HELP
	ʹ̫��ȭ�������������Ϊ��Ҳ���������գ�ֱ���޺���������أ�������
	�������ɼ��壬������У���Ȼһ����������������ʯ���������ͣ�ӥ
	��ȼ�����ͬ��ˮ����ֹ���ɽ�����˵����ڣ����ƺ���������֮���֡�
	
	Ҫ��	���� 1000 ���ϣ�      
		���� 200 ���ϣ�      
		����̫��ȭ�������ޱ�����
HELP
	);
	return 1;
}
