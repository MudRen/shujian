// sanhua-zhang perform �ļ�ɢ��(�����ﶬ)
// by beyond
// rewrite by snowman@SJ 05/12/1999

#include <ansi.h>

inherit F_SSERVER;
#include <combat_msg.h>

int hehe(object me, object target, int i)
{
	string dodge_skill, msg;
	int damage = (random(me->query("int")/6)+1) * me->query_skill("sanhua-zhang",1 );
        if (damage>2000) damage=2000+random((damage-2000)/100);
        if(!target || ! me->is_fighting(target)) return 1;
	if (i >= 400 ) msg = HIW"\nͻȻ$N���һ������ʱ��$nϹ��һ�����飬֮��$N��ü��֮�䲼����һ�㱡˪��˫Ŀ����ĵ���$n������ɮ��һ��һ���������"MAG"����÷��"HIW"��$n����������\n"NOR;          
	else if( i >= 300) msg = HIY"\nͻȻ$N˫��Ī��ģ�$n��Ȼ������ǰ��Ӱ��ɽ��������ɽ����������������ɽ��ˮ������һ�ж�����$nԶȥ������һ�����˵�"GRN"����ա�"HIY"�����˱Ƕ���������\n"NOR;           
       	else if( i >= 200) msg = MAG"\nֻ��$N����ѽ��һ����������ǰ��ȥ��ͻȻһ���������֣��ƿ�֮���м���"WHT"��������"MAG"��$n����ǰ��ȥ��\n"NOR;             
      	else msg = GRN"\n$NͻȻ���΢Ц������΢�ţ�����ӿ��һ�ɾ��磬�к���һƬƬ���̵�"CYN"�����ݡ�"GRN"��ֱ��$n����շ�ȥ��\n"NOR;
        
         
    	if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                me->add("neili", -damage/3);
                me->add("jingli", -50);
                i = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(i)+" )\n";
		message_vision(msg, me, target);
		if( !me->is_killing(target->query("id"))
		&& !target->is_killing(me->query("id"))
		&& !me->query("have_master")   // added by snowman
		&& target->query("qi")*2 <= target->query("max_qi"))
			COMBAT_D->end_fight(me, target);
		return 1;
        } 
        else {       
                me->start_busy(2);
                me->add("neili", -100); 
                me->add("jingli", -25);
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                message_vision(msg, me, target);
                return 0;
        }    
}

int perform(object me, object target)
{
      	if( !target ) target = offensive_target(me);
     
      	if( !target || !me->is_fighting(target) )
      		return notify_fail("���ļ�ɢ����ֻ����ս���жԶ���ʹ�á�\n");
             
      	if(me->query_temp("weapon"))
      		return notify_fail("��������ʹ�á��ļ�ɢ������\n");
      
      	if( (int)me->query_skill("sanhua-zhang",1) < 100 )
      		return notify_fail("���ɢ���Ʋ�����죬����ʹ�á��ļ�ɢ������\n");
      
      	if( (int)me->query_skill("yijin-jing",1) < 100 )
      		return notify_fail("����׽�ڹ��ȼ�����������ʹ�á��ļ�ɢ������\n");  
      
      	if( (int)me->query_str() < 30 )
      		return notify_fail("��ı�������ǿ������ʹ�á��ļ�ɢ������\n");
      
      	if( (int)me->query("max_neili") < 800 )
      		return notify_fail("�������̫��������ʹ�á��ļ�ɢ������\n");
      
      	if( (int)me->query("neili") < 300 )
      		return notify_fail("�������̫���ˣ��޷�ʹ�ó����ļ�ɢ������\n");   
                                                                                 
        if( me->query_temp("fumo"))
                return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
     
      	if (me->query_skill_prepared("strike") != "sanhua-zhang"
          || me->query_skill_mapped("strike") != "sanhua-zhang")
      		return notify_fail("�������޷�ʹ�á��ļ�ɢ�������й�����\n");     
     
     	if (me->query_skill_mapped("force") != "yijin-jing")
      		return notify_fail("��Ŀǰ���ڹ��޷�ʹ�á��ļ�ɢ�������й�����\n");  
      		  
        me->start_perform(6, "���ļ�ɢ����");
          
    	if (!hehe(me, target, me->query_skill("sanhua-zhang", 1))){
        	if (random(me->query_int()) > target->query_int()/2) 
        		hehe(me, target, random(me->query_skill("sanhua-zhang", 1)*2));
        	else return 1;
        }
                
        else if (random(me->query_int()) > target->query_int()/2) 
        	hehe(me, target, random(me->query_skill("sanhua-zhang", 1)*2));
        return 1;
       
}
string perform_name(){ return HIW"�ļ�ɢ��"NOR; }