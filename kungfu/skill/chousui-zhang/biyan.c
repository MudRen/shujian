#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
      object ob;
      string msg, *limbs;
      int i, neili, ap, dp, damage, p;
        
      i = (int)me->query_skill("chousui-zhang", 1);
      neili = (int)me->query("neili");   
        if( !target ) target = offensive_target(me);
    if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        || !living(target)
        || environment(me)!=environment(target) )
                return notify_fail("�����桹����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����桹��\n");        
        if(!objectp(ob = present("huo yan", environment(me))))
                return notify_fail("û�л����ô���������桹���й�����\n");
        if(me->query_temp("pfm_chousui"))
                return notify_fail("������������ѽ��й�����\n");
        if( i < 80 )
                return notify_fail("�㷢���Լ������޶��ƻ�������죬�޷�ʹ�á����桹���й�����\n");

        if( (int)me->query_skill("huagong-dafa",1) < 80 )
                return notify_fail("�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á����桹���й�����\n");

        if((int)me->query_skill("poison",1) < 60)
                return notify_fail("�㷢���Լ����ھ۶��������޷�ʹ�á����桹���й�����\n");         

        if (me->query_skill_prepared("strike") != "chousui-zhang"
        || me->query_skill_mapped("strike") != "chousui-zhang"
        || me->query_skill_mapped("parry") != "chousui-zhang")
                return notify_fail("������ó����Ʋ���ʹ�á����桹���й�����\n"); 
                                                                              
        if( me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("�㷢���Լ����õ��ڹ��޷����С����桹������\n");

        if( (int)me->query("max_neili") < 500) 
                return notify_fail("�㷢���Լ�����̫�����޷����������桹���й�����\n");

        if(neili < 300)
                return notify_fail("�㷢���Լ���������̫����ʹ���������桹���й�����\n");           
    
        if(target->query_condition("xx_poison") > 200)
                return notify_fail("�Է��Ѿ����������綾���㲻���ٽ��С����桹�����ˡ�\n");           

       message_vision(HIC"\n$N����ָ��"HIR"���"HIC"��Ĭ��������ע���Ż��棬���ư��أ������૵Ĳ�֪˵Щʲô������\n"NOR,me);
       me->start_busy(1+random(2));
          
        ap = me->query("combat_exp")/1000 * i * me->query_str();
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_dex();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -200);
        me->add("jingli", -25);

        msg = HIC"\nȻ��$NͻȻ˫����ǰƽƽ�Ƴ�������"RED"����"HIC"΢΢���������£��³�һ��"GRN"����"HIC"������$n��$l��\n"NOR;        
        if((userp(target) && random(ap+dp) > dp)||( !userp(target) && random(ap+dp)>dp/4))
{
        	damage = (i+me->query("jiali"))*8;
                if(neili > target->query("neili")) damage *= 2;

if(!userp(target) && me->query("max_pot")<=351) damage *=4;
                if( damage > target->query("qi") ) 
 { damage= target->query("qi")-1;
   target->start_busy(5);
  }
                        

          	target->receive_damage("qi", damage, me);
          	target->receive_wound("qi", random(damage), me);
          	target->apply_condition("xx_poison",  (me->query_skill("poison", 1)/2) + target->query_condition("xx_poison"));
		if (userp(me) && userp(target) && me->query_condition("killer") < 15)
			me->apply_condition("killer", 15);
          	p = (int)target->query("qi")*100/(int)target->query("max_qi");
          	msg += damage_msg(damage, "����");
          	msg += "( $n"+eff_status_msg(p)+" )\n";
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR); 
          	me->start_busy(1);
          	if(!target->is_busy())
          		target->start_busy(3);
          	}
        else{
          	me->start_busy(2);
          	msg += HIY"\n$pȫ�����һ��һ����������ֵرܿ����Ǽ��ٶ�����$w"HIY"��\n" NOR;
        }  
             
       limbs = target->query("limbs");
       msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       msg = replace_string(msg, "$w", GRN"����"NOR);
       message_vision(msg, me, target);
if( me->query_skill("chousui-zhang",1) <=450 )
       me->start_perform(4,"����");
       return 1;
}

string perform_name(){ return HIC"����"NOR; }
