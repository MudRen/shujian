//fengyi.c �з����� Write By lsxk@hsbbs 2007/7/25
//����ԭ����������5�����ж�����grin lsxk
//�����Ҽ������̬��pfm..�޸��¡����� by spiderii@ty
inherit F_SSERVER;
#include <ansi.h>
#include <combat.h>
#include <combat_msg.h>

string perform_name() {return HIM"�з�����"NOR;}

string *xue_name = ({
"����Ѩ","���Ѩ","����Ѩ","����Ѩ","����Ѩ","�Ϲ�Ѩ","���Ѩ","�ٻ�Ѩ","̫��Ѩ","��ǿѨ","��̨Ѩ"
});

int perform(object me, object target)
{       
        object weapon = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);
 
     //   if(!objectp(target)|| !target->is_fighting(me) )
     //           return notify_fail("���з����ǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
// By Spiderii@ty lsxk��д�Ĳ�̫ȫ��,�Ҳ�����,��ǿ���ж�
        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
               return notify_fail("���з����ǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!weapon
         || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("�������޷�ʹ�á��з����ǡ��������ˡ�\n");

        if((int)me->query_skill("huashan-jianfa", 1) < 100
         ||(int)me->query_skill("sword", 1) < 100
         ||(int)me->query_str() < 25   
         ||(int)me->query_dex() < 25)  
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á��з����ǡ���\n");

        if((int)me->query_skill("huashan-qigong", 1) < 100 
			&&(int)me->query_skill("zixia-gong", 1) < 100)
                return notify_fail("��������ڹ���Ϊ�������޷������з����ǡ��ľ��衣\n");

        if(me->query_skill_mapped("force") != "huashan-qigong"
         &&me->query_skill_mapped("force") != "zixia-gong" )
            return notify_fail("��������ڹ����ԣ��޷�ʹ�á��з����ǡ���\n");

        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("�������̫�����޷�ʹ�ó����з����ǡ���\n");
        
        if( (int)me->query("neili") < 700 )
                return notify_fail("�������������\n");

	if( me->query_temp("hsjf/fengyi"))
                return notify_fail("������ʹ�á��з����ǡ���\n");

        me->start_perform(3, "���з����ǡ�");
        message_vision(HIM"\n$Nʹ�����з����ǡ������Ʒ����������ӯ�鶯������"+weapon->query("name")+HIM+"��˸������ֱ��$n!\n"NOR, me, target);
        message_vision(HIM"���С��з����ǡ����ǻ�ɽ�����ľ���������һ�м�����������������У��仯������ף�\n"NOR, me);
        me->set_temp("hsjf/fengyi/wait",1);
        call_out("fengyi1", 1, me , target, weapon);
        return 1;
}

int fengyi1(object me, object target, object weapon)
{
	string xue,msg;
	int t_exp,m_exp,t_dodge,m_skill,damage;

	if (!objectp(weapon)
        ||weapon->query("skill_type") != "sword"
        ||me->query_skill_mapped("sword") != "huashan-jianfa"
        ||me->is_busy()
	||(int)me->query("neili")< 700
	||(int)me->query("jingli")< 350){
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
            	return notify_fail(HIR"�������ʽ�޷����ᣬ����͸֧���ȣ��޷�����ʹ�á��з����ǡ���\n"NOR);
	}

   if(!objectp(target)||!living(target)||environment(target)!=environment(me)){
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return notify_fail(HIR"���������������֣�ȴ�����Ѿ�û�������Ҫ�ˣ�\n"NOR);
	}

	if (!me->is_fighting(target)){
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return 1;
	}

    t_exp = (int)target->query("combat_exp");
    m_exp = (int)me->query("combat_exp");
    t_dodge = (int)target->query_skill("dodge",1);
    m_skill = (int)me->query_skill("huashan-jianfa",1);
    damage = 0;
	
    xue = xue_name[random(sizeof(xue_name))];
    message_vision(HIY"\n$N��$n�������ƽ⣬��ʱһ�����У�����"+weapon->query("name")+HIY"�ڰ�;�о������ת�˻���"+
                  "���쳣��׼�ؼ���$n�ġ�"HIR+xue+HIY"��!\n"NOR, me, target);
    if ( random(m_exp) > t_exp/2
	|| random(m_skill) > t_dodge/2){
           damage = m_skill*(int)me->query("int")/3;
           if (damage > m_skill*6) damage = m_skill*6;
           if (wizardp(me) && me->query("env/fengyi")) write("damage is "+damage+"!\n");
		me->receive_damage("neili",300);
		me->receive_damage("jingli",150);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage*7/10,me);
        	msg = HIY"$n�����ϵõ�$N��������˱��У�����֮�£�ȫ��һ�𣬡�"HIR+xue+HIY"����Ȼ�����У���������!\n"NOR;
		msg += COMBAT_D->damage_msg(damage,"����");
           msg = replace_string( msg, "$l", "��"+HIR+xue+NOR"��" );
           msg = replace_string( msg, "$w", weapon->name());
		message_vision(msg,me,target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
		COMBAT_D->report_status(target, 1);
		me->set_temp("hsjf/fengyi/first","����");
           call_out("fengyi2", 1+random(3), me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
	}
	else{
		message_vision(HIG"ֻ��$N�����ٶ���죬��$n�����ٶȸ��죬ֻ��$n˫������һ�㣬ʮ�����ɵ����˿�ȥ��\n"NOR,me,target);
		me->set_temp("hsjf/fengyi/first","δ��");
		me->receive_damage("neili",200);
		me->receive_damage("jingli",100);
		call_out("fengyi2", 1, me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
	}

    return 1;
}

int fengyi2(object me, object target, object weapon, int t_exp, int m_exp, int t_dodge, int m_skill)
{
	string msg;
	int busy,damage;
	
	if (!objectp(weapon)
        ||weapon->query("skill_type") != "sword"
        ||me->query_skill_mapped("sword") != "huashan-jianfa"
        ||me->is_busy()
	||(int)me->query("neili")< 700
	||(int)me->query("jingli")< 350){
		if (userp(me))
	    me->delete_temp("hsjf/fengyi");
	    me->start_perform(3, "���з����ǡ�");
            return notify_fail(HIR"�������ʽ�޷����ᣬ����͸֧���ȣ��޷�����ʹ�á��з����ǡ���\n"NOR);
	}

   if(!objectp(target)||!living(target)||environment(target)!=environment(me)){
   	if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return notify_fail(HIR"���������������֣�ȴ�����Ѿ�û�������Ҫ�ˣ�\n"NOR);
	}
	
	if (!me->is_fighting(target)){
		if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return 1;
	}

	if(m_skill >= 120){
		if(me->query_temp("hsjf/fengyi/first")=="����"){
			message_vision(HIW"\n$Nһ�����У����б�ԴԴ���ϣ�ֻ��$N����"+weapon->query("name")+HIW"����һָ��"+
			"������ޱȵĴ���$n"HIR"����"HIW"����\n"NOR, me, target);
			    if ( random(m_skill) > t_dodge/3){
                                   busy = m_skill/120;
                                   if (busy > 2) busy = 1+random(2);
					target->add_busy(busy);
                                   if (wizardp(me)&&me->query("env/fengyi")) write("busy is "+busy+"!\n");
					me->receive_damage("neili",100);
					me->receive_damage("jingli",60);
					target->add("neili",-m_skill*5);
					msg = HIC"$N����ʹ��¯���࣬$n���ﻹ�мܵ�ס��ֱ��"HIR"����"HIC"һ�飬������ʧ���࣡\n"NOR;
					message_vision(msg,me,target);
					me->set_temp("hsjf/fengyi/second","����");
                                   call_out("fengyi3", 1+random(2), me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
			}
			else{
				message_vision(HIM"$nֻ�������׺��ޱȣ���æ�͵�һ�����Ǳ������˿�ȥ��\n"NOR,me,target);
				me->set_temp("hsjf/fengyi/second","δ��");
				me->receive_damage("neili",100);
				me->receive_damage("jingli",60);
				call_out("fengyi3", 1, me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
			}
		}
		else{
			message_vision(HIW"\n$N�϶�$n��Ȼ����һ���������˿�ȥ������ʩչ�Ṧ������"+weapon->query("name")+
			HIW"����$n��ͷ������ȥ��\n"NOR, me, target);
			    if ( random(m_skill) > t_dodge/3){
                                   damage = m_skill*(int)me->query("int")/3;
                                   if (damage > m_skill*8) damage = m_skill*8;
					damage = damage+random(damage/2);
                                   if (wizardp(me)&&me->query("env/fengyi")) write("damage is "+damage+"!\n");
					me->receive_damage("neili",300);
					me->receive_damage("jingli",150);
					target->receive_damage("qi",damage,me);
					target->receive_wound("qi",damage*7/10,me);
					msg = HIR"$n���ܲ������ѱ����ؿ��ˡ�\n"NOR;
					msg += COMBAT_D->damage_msg(damage,"����");
					message_vision(msg,me,target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
					COMBAT_D->report_status(target, 1);
					me->set_temp("hsjf/fengyi/second","����");
                                   call_out("fengyi3", 2+random(2), me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
				}
				else{
					message_vision(CYN"$n���һ���������ھ��������м�ס��������һ����\n"NOR,me,target);
					me->set_temp("hsjf/fengyi/second","δ��");
					me->receive_damage("neili",80);
					me->receive_damage("jingli",40);
					call_out("fengyi3", 1, me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
				}
		}
	}
	else{
		if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
            	return 1;
	}

	return 1;
}

int fengyi3(object me, object target, object weapon, int t_exp, int m_exp, int t_dodge, int m_skill)
{
	if (!objectp(weapon)
        ||weapon->query("skill_type") != "sword"
        ||me->query_skill_mapped("sword") != "huashan-jianfa"
        ||me->is_busy()
	||(int)me->query("neili")< 700
	||(int)me->query("jingli")< 350){
	    me->delete_temp("hsjf/fengyi");
	    me->start_perform(3, "���з����ǡ�");
            return notify_fail(HIR"�������ʽ�޷����ᣬ����͸֧���ȣ��޷�����ʹ�á��з����ǡ���\n"NOR);
	}

   if(!objectp(target)||!living(target)||environment(target)!=environment(me)){
   	if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return notify_fail(HIR"���������������֣�ȴ�����Ѿ�û�������Ҫ�ˣ�\n"NOR);
	}

	if (!me->is_fighting(target)){
		if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return 1;
	}

	if(m_skill<180){
		if (userp(me))
	    me->delete_temp("hsjf/fengyi");
	    me->start_perform(3, "���з����ǡ�");
            return 1;
	}

	if(!me->is_busy()){
		message_vision(HIB"\n$NĬ�����죬ȴ����������ֻ�����ৡ�������Х��˲��㹥������!\n"NOR, me, target);
		me->add("neili",-300);
		me->add("jingli",-150);
		me->add_temp("apply/attack",m_skill/20);
		if (me->query_temp("zxg/zixia")){
			message_vision(HIM"$N����������"+chinese_number(m_skill/30)+HIM"����ϼ�ھ�����������ʵ�˴���!\n"NOR, me);
			me->add_temp("apply/damage",m_skill/10);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
			me->add_temp("apply/damage",-m_skill/10);
		}
		else{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
		}
		me->add_temp("apply/attack",-m_skill/20);
	}
	else{
		message_vision(HIC"\n$N���뷢�У�ȴ�����Լ��������ƣ�ֻ�ó��з���!\n"NOR, me, target);
	}
	me->start_perform(3, "���з����ǡ�");
   call_out("fengyi4", 2+random(2), me, target, weapon, t_exp, m_exp, t_dodge, m_skill);

    return 1;
}

int fengyi4(object me, object target, object weapon, int t_exp, int m_exp, int t_dodge, int m_skill)
{
	string msg,xue;
	int damage;

	if (!objectp(weapon)
        ||weapon->query("skill_type") != "sword"
        ||me->query_skill_mapped("sword") != "huashan-jianfa"
        ||me->is_busy()
	||(int)me->query("neili")< 700
	||(int)me->query("jingli")< 350){
	    me->delete_temp("hsjf/fengyi");
	    me->start_perform(3, "���з����ǡ�");
            return notify_fail(HIR"�������ʽ�޷����ᣬ����͸֧���ȣ��޷�����ʹ�á��з����ǡ���\n"NOR);
	}

   if(!objectp(target)||!living(target)||environment(target)!=environment(me)){
   	if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return notify_fail(HIR"���������������֣�ȴ�����Ѿ�û�������Ҫ�ˣ�\n"NOR);
	}

	if (!me->is_fighting(target)){
		if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return 1;
	}

   if(m_skill<230||me->query("quest/hsjf/fengyi4")!="pass"){
   	if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
                return 1;
	}
	
	xue = xue_name[random(sizeof(xue_name))];
    message_vision(HIR"\n����$N�ٴ�Ծ������"+weapon->query("name")+HIR"ƽƽ�̳������к��޻��Σ�һ����������ֱ��"+
                     "$n�ġ�"+HIY+xue+HIR+"��!\n"NOR, me, target);
    if ( random(m_exp) > t_exp/2
	|| random(m_skill) > t_dodge*3/5){
            damage = m_skill*(int)me->query("int")/3;
            damage = damage*3/2 + random(damage/2);
       if (wizardp(me)&&me->query("env/fengyi")) write("damage is "+damage+"!\n");
	    me->receive_damage("neili",400);
	    me->receive_damage("jingli",200);
	    target->receive_damage("qi",damage,me);
	    target->receive_wound("qi",damage*7/10,me);
            msg = RED"$n���ѱ�$N�Ĺ����ŵ�ȫ��Ӳ���Ļ��а�㻹��֮����!\n"NOR;
	    msg += COMBAT_D->damage_msg(damage,"����");
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
       msg = replace_string( msg, "$l", "��"+HIY+xue+NOR"��" );
       msg = replace_string( msg, "$w", weapon->name());
	    message_vision(msg,me,target);
	    COMBAT_D->report_status(target, 1);
	    target->add_busy(3+random(3));
	    target->apply_condition("no_perform",1);
	    target->apply_condition("no_exert",1);
	    me->set_temp("hsjf/fengyi/forth","����");
	    me->start_perform(3, "���з����ǡ�");
	    call_out("fengyi5", 1, me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
	}
	else{
           message_vision(MAG"$n���������˾�����׵Ľ��У�һ�����⣬�㴦�����ƣ�\n"NOR,me,target);
		me->set_temp("hsjf/fengyi/first","δ��");
		me->receive_damage("neili",200);
		me->receive_damage("jingli",100);
		target->apply_condition("no_force",1);
		target->apply_condition("no_perform",2);
		target->apply_condition("no_exert",2);
		me->start_perform(3, "���з����ǡ�");
		call_out("fengyi5", 1, me, target, weapon, t_exp, m_exp, t_dodge, m_skill);
	}
	return 1;
}

int fengyi5(object me, object target, object weapon, int t_exp, int m_exp, int t_dodge, int m_skill)
{

	if (!objectp(weapon)
        ||weapon->query("skill_type") != "sword"
        ||me->query_skill_mapped("sword") != "huashan-jianfa"
        ||me->is_busy()
	||(int)me->query("neili")< 700
	||(int)me->query("jingli")< 350){
		if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
                return notify_fail(HIR"�������ʽ�޷����ᣬ����͸֧���ȣ��޷�����ʹ�á��з����ǡ���\n"NOR);
	}

   if(!objectp(target)||!living(target)||environment(target)!=environment(me)){
   	if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return notify_fail(HIR"���������������֣�ȴ�����Ѿ�û�������Ҫ�ˣ�\n"NOR);
	}

	if (!me->is_fighting(target)){
		if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
		return 1;
	}

   if(m_skill<300||me->query("quest/hsjf/fengyi5")!="pass"){
   	if (userp(me))
		me->delete_temp("hsjf/fengyi");
		me->start_perform(3, "���з����ǡ�");
                return 1;
	}

    message_vision(HIM"\n$N��ʤ׷��������"+weapon->query("name")+HIM"��ÿ���ޱȣ�$n�Ѿ�����������$N��������ֻ�����ܾ���������\n"+
		"$NͻȻ����һ����Х���ҽ�����һ����ǰ����Ծ����"+weapon->query("name")+HIM"���������󺮹�������չ�ᣡ\n"+
           "$N΢΢һЦ������"+weapon->query("name")+HIM"ȴ������ؼ��죬ɲ�Ǽ䣬����ৡ������������������ⱼ��$n��\n"NOR, me, target);
		me->add_temp("apply/attack",m_skill);
           if(me->query_temp("zxg/zixia")){
			message_vision(MAG"$N����������"+chinese_number(m_skill/30)+MAG"����ϼ�ھ������������ѷ�Ѱ��!\n"NOR, me);
			me->add_temp("apply/damage",m_skill/2);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
			me->add_temp("apply/damage",-m_skill/2);
		}
		else{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(3)?3:1);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(4)?3:1);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		}
	me->add_temp("apply/attack",-m_skill);
	me->add("neili",-400);
	me->add("jingli",-200);
  if (userp(me))
	me->delete_temp("hsjf/fengyi");
	me->start_perform(3, "���з����ǡ�");

	return 1;
}

int help(object me)
{
    write(WHT"\n��ɽ������"HIM"�з�����"WHT"����"NOR"\n");
    write(@HELP
    ���������˸�����������ɽ�����������ɡ����������ơ�����
    ���з����ǡ���Ϊ������ʽ����һ�й���ȴ��������У���ɽ������
    ��Ҫ���ϼ����²�֪���б仯������������ʵս��������õģ�����
    ���ؿ������ɾ�����һʽ����䣬һ��ǿ��һ�䣬��ɽ�����г���ʹ
    �ø��У�Ч�������ޱȣ�
    ָ�perform fengyi

    Ҫ�󣺻�ɽ���� ���� ��ϼ��100��
          ��ɽ����100����
          ��������100����
          ������25���ϣ�
          ����������25���ϣ�
          ��ǰ����700���ϣ�
          ��ǰ����350���ϣ�
          �������1200���ϣ�

    ˵����
          ��ɽ����120��ʱ���ڶ����У�
          ��ɽ����180��ʱ���������У�
          ��ɽ����230����ͨ�����Ժ������ĺ��У�
          ��ɽ����300����ͨ�����Ժ���������С�
          �������ϼ��ĳ���ؼ�һ��ʹ�ã�Ч�����ѣ�

HELP
	);
	return 1;
}
