// guifei ��������
// ����д�˹���---by daidai
/*
     ���������΢����������Ť�����㷴�ߣ������С����ȥ������������ܣ�
�����˳�Ʒ�������������§ס������ͷ�������־�����ס��ذ�ף������׼��
�������ģ�Ц���������ǵ�һ�У����������������������ס�ˡ���

*/
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name(){ return HIR"��������"NOR; }

int perform2(object me, object target);

int perform(object me, object target)
{
        object weapon;
        string msg,dodge_skill;
 int ap,dp,damage,effect;
 	 
        if(!target) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("������������ֻ����ս��ʱʹ�ã�\n");

        if(userp(me) && me->query("family/master_id")!="hong antong")
                return notify_fail("������������ֻ�а��˽���������ã�\n");

        if(!objectp(weapon=me->query_temp("weapon"))
        || weapon->query("skill_type") != "dagger")
             return notify_fail("������û��ذ�ף����ʹ�á�������������\n");
	
        if((int)(me->query("dex")+me->query_skill("dodge",1)/10) < 30 )
                return notify_fail("����������ʹ�á����������������»��˵��Լ���\n");

        if((int)me->query_skill("tenglong-bifa", 1) < 150 )
                return notify_fail("�������ذ������������������ʹ�á�������������\n");
	if((int)me->query_skill("shenlong-tuifa",1) < 150)
		return notify_fail("��������ȷ���������������ʹ�á�������������\n");
	
        if(me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("ֻ��ʹ������ذ��ʱ����ʹ�á�������������\n");

	if(me->query_skill_mapped("leg") != "shenlong-tuifa"
	|| me->query_skill_prepared("leg") != "shenlong-tuifa")
		return notify_fail("������û������׼�����޷�ʹ�á�������������\n");
		
        if( (int)me->query_skill("dulong-dafa", 1) < 150 )
                return notify_fail("��Ķ����󷨹������㣬�����á�������������\n");

        if((int)me->query("jingli", 1) < 400)
                return notify_fail("�����ھ������㣬����ʹ�á�������������\n");

        if((int)me->query("neili", 1) < 800)
                return notify_fail("�������������㣬����ʹ�á�������������\n");

        /* if(me->query("gender") == "����" )
                return notify_fail("����Ů����ô��ʹ�á������������أ�\n");
*/
 //ȡ��ʹ������  
     if( me->query_skill_mapped("force") != "dulong-dafa")
                return notify_fail("��������ʹ�õ��ڹ�ͬ�������໥�ִ�������ʹ�á�������������\n");

        
        message_vision( HIR"\n$N��$n��������֮����ƴ��ȫ��ʹ���շ��˲���֮����������������������"NOR,me,target);
   if(me->query("gender") == "����" )
   message_vision(MAG"\n$N����΢����ˮͰ��Ĵ����͵�һŤ�����㷴�ߣ���$nС����ȥ��\n"NOR,me,target);
  else    message_vision( MAG"\n$N����΢����������Ť�����㷴�ߣ���$nС����ȥ��\n"NOR,me,target);
  	me->receive_damage("neili",300);
  	me->receive_damage("jingli",150);


   ap = me->query_skill("tenglong-bifa",1)*me->query_dex();
   dp = target->query_skill("dodge",1)* target->query_dex();
  if( target->is_busy() ) dp= dp/2;
 if(random(ap)>dp/4)
 		{
 			effect = SKILL_D("dulong-dafa")->force_effect(target->query_skill_mapped("force"));
                        damage = (me->query_skill("force")+me->query("jiali"))*5;
 			damage *= (5-effect);
 		//	if(damage>3000)
 		//		damage = 2800+random(damage-2000)/5;
 			target->receive_damage("qi",damage,me);
 			target->receive_wound("qi",damage/3,me);
	msg = HIY"\n$n���ܲ�������$Nһ�����У���ɫ���̱�ĲҰף�\n"NOR;	
	msg += damage_msg(damage, "����");
       message_vision(msg,me,target);
	COMBAT_D->report_status(target);

if ( me->is_fighting(target)){
 message_vision( HIY"\n$N��˳�Ʒ���������������Ц��������������$n��ͷ�������ȥ��\n"NOR,me,target);
	perform2(me, target);}	}

else
 		{
                	dodge_skill = target->query_skill_mapped("dodge");
                	if( !dodge_skill ) dodge_skill = "dodge";
                	msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
 
if ( me->is_fighting(target))
     {          msg += HIY"\n$n�����ܹ���$N˳�Ʒ���������������Ц��������������$n��ͷ�������ȥ��\n"NOR;	 	 
 message_vision(msg,me,target);
 perform2(me, target);}  
     	}

 me->start_perform(4,"������������");
	return 1;
}


int perform2(object me, object target)
{
  object weapon; 

 int ap,dp,lvl;  
      if(!target) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return 0;
if((int)me->query("jingli", 1) < 200)
                return 0;
if((int)me->query("neili", 1) < 400)
                return 0;
weapon=me->query_temp("weapon");
 lvl = me->query_skill("tenglong-bifa",1);

ap = me->query_skill("tenglong-bifa",1)*me->query_dex();
dp = target->query_skill("dodge",1)* target->query_dex();
  if( target->is_busy() ) 
    dp= dp/2; 
if(random(ap)>dp/2)
{
      message_vision( MAG"$n��$N§סͷ����ֻ��������һ���������Ժ�֮��ȴû������$P���־�����ס��"+weapon->name()+MAG"��\n"NOR,me,target); 
 target->add_busy(2);  
        me->add_temp("apply/attack",lvl);
        me->add_temp("apply/damage",lvl/2);
        me->add_temp("apply/strength",lvl/8);
        me->set_temp("sld/pfm/guifei",1); 
      
COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
     


    if ( me->is_fighting(target) && me->query_skill("tenglong-bifa",1) > 300)  {
weapon->unequip();
   COMBAT_D->do_attack(me,target,0,3);
     weapon->wield();
 }    
    me->delete_temp("sld/pfm/guifei"); 

        me->add_temp("apply/damage",-lvl/2);
        me->add_temp("apply/attack",-lvl);
        me->add_temp("apply/strength",-lvl/8);
        me->add("neili",-250);
  	 me->add("jingli",-130);
 
} 

else {  
switch(random(2)){
                	case 2: message_vision( HIC"$n��Ȼ��ͷ������Ǳ�֮��ʹ������ʽ�Լ���ɬ��\n"NOR,me,target); 
                   target->add_temp("lost_attack", 2+random(2));	
                   target->apply_condition("no_perform",1);
                   break;
                	case 1: message_vision( HIC"$n��Ȼ��ͷ�����ȴҲ���´�������֮����æ���ң������·���\n"NOR,me,target);  
                  target->add_busy(random(2) + 1);
                   target->apply_condition("no_fight",1);

                   break;
                   default:  message_vision( HIC"$n��Ȼ��ͷ������Ǳ�֮��ʹ������ʽ�Լ���ɬ��\n"NOR,me,target); 
                  target->add_temp("lost_attack", 2+random(2)); 
                  target->add_busy(1);
                   break;
                } me->add("neili",-150);
  	me->add("jingli",-50);
 }
}
/*
 int help(object me)
 {   write(WHT"\n����ذ����"HIR"��������"WHT"����"NOR"\n");
    write(@HELP

     Ҫ�󣺵�ǰ���� 1500 ���ϣ�
           ��ǰ���� 800 ���ϣ�
           ����ذ���ȼ� 150 ���ϣ�
           �����󷨵ȼ� 150 ���ϣ�
           ������ 30 ���ϡ�
 HELP
    );
    return 1;
}

*/