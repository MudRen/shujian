//pojian.c ����ʤ����;
//˭��������9j����questskills;
// poqi�˺��Ͼ�����̫���ˡ�;
//���Ƽ�������������quest��dodge����exert������Ч����
 
#include <ansi.h>
 
inherit F_SSERVER;
 
string perform_name() {return HIB"����ʤ����"NOR;}

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, p, force, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("dugu-jiujian",1)  ;
        

        if( !(me->is_fighting() ))
                return notify_fail("������ʤ���С�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return notify_fail("�������޷�ʹ�á�����ʤ���С���\n");

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return notify_fail("�������޷�ʹ�á�����ʤ���С���\n");

        if( skill < 350)
                return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʤ���С���\n");

        if( me->query("neili") < 2500 )
                return notify_fail("��������������޷����á�����ʤ���С���\n");
 
        msg = HIM"\n$N������������ڶ��¾Ž���������ʤ���С���Ҫּ�������á�һ��$n�ļ����������¾Ž���\n"+
                 "�����ְ��΢֮�������ӵ����쾡�¡����ƽ�ʽ����ֻһʽ�������������¸��Ÿ����з�Ҫ���\n"+
                  "�ղ����˵�����С���ȴ���������½���֮����Ϊ����������֮���ʵ�Ƿ�����˼��\n"NOR;
      if(!userp(me)) skill = skill / 2;
me->set_temp("pfmwz",1);
        me->add_temp("apply/attack", skill/6);
        me->add_temp("apply/damage", skill/4);
        me->add_temp("apply/sword",  skill/4);
        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force")/2;
        if( dp < 1 ) dp = 1;


       if( random(ap ) > dp ||  (!userp(target) && me->query("int")>40) ||  random( me->query("int",1)) > target->query("int",1)/2   ){
                if(userp(me))
                        me->add("neili",-(500+random(500)));
           msg += YEL"\n$n��$N���в�����ÿһ�仯���Ǵ���δ�������������������������С�\n"+
                     "�еĹ����������е��������࣬�е�С��Ѹ�ݣ��е����ͳ��ȡ�������$n������ξ��\n"+
                     "���������񣬵��ˡ����¾Ž�����΢�Ľ���֮�£�������ա�\n" NOR;

           p = (int)me->query_skill("force") + random(me->query_skill("force")*3);
   
           force = target->query_skill_mapped("force");
	switch(force) {
		case "huntian-qigong":
			if( intp(p = target->query_temp("htqg/powerup")) ){
				target->add_temp("apply/armor", - p*2);
				target->add_temp("apply/dodge", - p);
				target->delete_temp("htqg/powerup");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ�����������Ч����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "xixing-dafa":
			if( intp(p = target->query_temp("xxdf/xixing")) ){
				target->add_temp("apply/attack", - p);
				target->add_temp("apply/dexerity", - p/10);
				target->delete_temp("xxdf/xixing");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ����Ǵ󷨵�Ч����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}

		case "xiantian-gong":
			if( intp(p = target->query_temp("xtg/wuqi")) ){
				target->add_temp("apply/armor", - p/5);
				target->add_temp("apply/strike", - p/10);
				target->add_temp("apply/attack", - p*4 /10);
				target->delete_temp("xtg/wuqi");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ�������Ԫ��Ч����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "bahuang-gong":
			if( intp(p = target->query_temp("bhg/duzun")) ){
				target->add_temp("apply/armor", - p/5);
				target->add_temp("apply/hand", - p/10);
				target->add_temp("apply/attack", - p*5 /10);
				target->delete_temp("bhg/duzun");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ��˻Ĺ�Ψ�Ҷ���Ч����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}
	  case "xixing-dafa":
			if( intp(p = target->query_temp("xxdf/xixing")) ){

    target->add_temp("apply/attack", -p);
    target->add_temp("apply/dexerity",-p/10);
    target->add_temp("apply/parry", -p);
    target->delete_temp("xxdf/xixing");
   
		tell_object(target, HIR"��ĵ���ҪѨ���ˣ����Ǵ󷨵�Ч����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}
			
			
			
			
		case "beiming-shengong":
			if( intp(p = target->query_temp("bmsg/bm")) ){
				target->add_temp("apply/armor", - p/4);
              if (target->query("family/family_name") == "��ң��") {
				    target->add_temp("apply/attack", - p/6);
				    target->add_temp("apply/intelligence", - p/30);
			       target->add_temp("apply/dexerity", - p /20); 
		                                	}
				target->delete_temp("bmsg/bm");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ���ڤ������Ч����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "huashan-qigong":
			if( intp(p = target->query_temp("hsqg/yjs")) ){
				target->add_temp("apply/attack", - p/2);
				target->delete_temp("double_attack");
				target->delete_temp("hsqg/yjs");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ��������㣬Ԧ��ʽЧ����Ȼ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "zixia-gong":
			if( target->query_temp("zxg/zixia") ){
				target->delete_temp("double_attack");
				target->delete_temp("zxg/zixia");
				tell_object(target, HIR"��ĵ���ҪѨ���ˣ��������㣬��ϼ����Ч����ʧ�ˣ�\n"NOR);
				break;
			}

		case "yijin-jing":
			if( intp(p = target->query_temp("fanzhen")) ){
				target->add_temp("apply/armor", - p);
				target->add_temp("apply/parry", - p);
				target->add_temp("apply/attack", - p);
				target->delete_temp("fanzhen");
				target->delete_temp("no_skill_hit_ob");
				tell_object(target, HIR"��ĵ���ҪѨ����,����ղ������񹦡���ЧӦҲ��Ӧ����ʧ�ˣ�\n"NOR);
				break;
			}
		case "jiuyang-shengong":
			if( intp(p = target->query_temp("jiuyang/powerup")) ){
	                                        target->add_temp("apply/attack", - p);
	                                        target->add_temp("apply/dexerity", - p/10);
                                                      target->add_temp("apply/armor", - p/4);
                                                      target->delete_temp("fanzhen");  
	                                        target->delete_temp("jiuyang/powerup");
				tell_object(target, HIR"��ĵ���ҪѨ����,�������񹦡���ЧӦҲ��Ӧ����ʧ�ˣ�\n"NOR);
				break;
			}
		case "linji-zhuang":
			if( target->query_temp("ljz/riyue") ){
				target->delete_temp("ljz/riyue");
				tell_object(target, HIR"��ĵ���ҪѨ����,�����¡�ׯ�������֮������ɢ������֮�䣡\n"NOR);
				break;
			}
			if( intp(p = target->query_temp("ljz/yinyang")) ){
				target->add("max_qi", - p);
				target->receive_wound("qi", p, "��������ׯ���ƣ�������");
				target->delete_temp("ljz/yinyang");
				tell_object(target, HIR"��ĵ���ҪѨ����,��������ׯ������ЧӦҲ��ʧ�ˣ�\n"NOR);
				break;
			}
			if( intp(p = target->query_temp("ljz/fengyun")) ){
				target->add_temp("apply/dexerity", - p);        
				target->delete_temp("ljz/fengyun");
				tell_object(target, HIR"��ĵ���ҪѨ����,�����ơ�ׯЧ����ʧ���Ծ����ĳ�����һЩ��\n"NOR);
				break;
			}
			if( target->query_temp("ljz/wuwo")){
				target->delete_temp("ljz/wuwo");
				tell_object(target, HIR"��ĵ���ҪѨ����,�����ҡ��ķ����ƣ��ָֻ���ԭ�����㣡\n"NOR);
				break;
			}
		case "yinyun-ziqi":
			if( target->query_temp("tj/̫��") ){
				target->delete_temp("tj/̫��");
				tell_object(target, HIR"��ĵ���ҪѨ����,��æ֮�У�̫������������У�ЧӦҲ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "dulong-dafa":
			if( intp(p = target->query_temp("sld/wudi2") ) ){
				target->add_temp("apply/strength", -p/20);  
				target->add_temp("apply/attack", -p/3);
				target->delete_temp("double_attack");
				target->delete_temp("sld/wudi2");
				if(target->query("eff_qi") > target->query("max_qi")) 
					target->set("eff_qi", target->query("max_qi"));
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�����һ�ɣ���Ҳ֧�ֲ�ס�ˣ���\n"NOR);
				break;
			}
		           if( intp(p = target->query_temp("sld/wudi1")) ){
				target->add_temp("apply/strength", -p/20);
				target->add_temp("apply/attack", -p/4);
				target->delete_temp("sld/wudi");
				target->delete_temp("sld/wudi1");
				if(target->query("eff_qi") > target->query("max_qi")) 
					target->set("eff_qi",target->query("max_qi"));
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�����һ�ɣ�����������һ����ͻȻ������������\n"NOR);
				break;
			}
		case "hanbing-zhenqi":
			if ( intp(p = target->query_temp("hbzq/huti")) ){
				target->add_temp("apply/parry", -p);
				target->add_temp("apply/dodge", -p);
				target->delete_temp("hbzq/huti");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�����ĺ���ɢ�����������𵽱����������ˡ�\n"NOR);
				break;
			}
			if( target->query_temp("ss/focus")){
				target->delete_temp("ss/focus");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�����ĺ���������ɢȥ�ˡ�\n"NOR);
				break;
			}
			if( target->query_temp("ss/hb")){
				target->delete_temp("ss/hb");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ����ϵĺ���������ɢȥ�ˡ�\n"NOR);
				break;
			}
		case "huagong-dafa":
			if( intp(p = target->query_temp("hgdf/judu")) ){
				target->add_temp("apply/armor", -p);
				target->delete_temp("hgdf/judu");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�����һ�ɣ����۶���ȫ�����ˣ���\n"NOR);
				break;
			}
			else if( intp(p = target->query_temp("hgdf/huadu")) ){
				target->add_temp("apply/dodge", -p); 
				target->add_temp("apply/armor_vs_force", -p/2);           
				target->delete_temp("hgdf/huadu");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�����һ�ɣ��������۶���ȫ�����ˣ���\n"NOR);
				break;
			}
		case "yunu-xinjing":
			if( target->query_temp("gm/xinjing") ){
				p  = target->query_temp("gm/xinjing");
				target->add_temp("apply/intelligence", -p/10);
				target->add_temp("apply/dexerity", -p/10);
				if ( target->query_skill("yunu-xinjing", 1) > 200 ){
					target->add_temp("apply/attack", -p/5);
                                                                      target->add_temp("apply/damage", -p/8);
					if ( target->query("gender") == "Ů��") {
						target->add_temp("apply/dodge", -p/10);
						target->add_temp("apply/parry", -p/10);
						target->add_temp("apply/armor", -p/10);
					}
					if ( target->query("gender") == "����") {
						target->add_temp("apply/strike", -p/10);
						target->add_temp("apply/parry", -p/10);
						target->add_temp("apply/armor", -p/10);
					}
				}
				target->delete_temp("gm/xinjing");
				tell_object(target, HIR"��ĵ���ҪѨ����,���ľ����־�ЧӦҲ��ʧ�ˣ�\n"NOR);
				break;
			}
		case "shenyuan-gong":
			if ( intp(p = target->query_temp("shenyuan")) ){
				target->add_temp("apply/parry", -p/3);
				target->add_temp("apply/dexerity", -p/20);
				target->delete_temp("shenyuan");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�������ʽ�Ѿ������ˡ�\n"NOR);
				break;
			}
		case "xuantian-wuji":
			if ( intp(p = target->query_temp("kl/riyue")) ){
				target->add_temp("apply/parry", -p/2);
				target->add_temp("apply/armor", -p/2);
				target->delete_temp("kl/riyue");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ��޼������޷��𵽱��������ˡ�\n"NOR);
				break;
			}
			if ( intp( p = target->query_temp("kl/taxue")) ) {
				target->add_temp("apply/dodge", -p);
                                                        target->add_temp("apply/dexerity", -p);
				target->delete_temp("kl/taxue");
				tell_object(target, HIR"�����˽Ų������ظ���������\n"NOR);
				break;
			}
		case "longxiang-boruo":
			if ( intp(p = target->query_temp("xs/shield")) ) {
				target->add_temp("apply/dodge", -p);
				target->add_temp("apply/armor", -p*2);
				target->delete_temp("xs/shield");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ����Ϻ��һ�����ǽ�žž���켸����ɢȥ�˻���������\n" NOR);
				break;
			}
			if ( intp(p = target->query_temp("xs/longxiang")) ) {
				target->add_temp("apply/attack", -p);
				target->delete_temp("xs/longxiang");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ���������һ�����ָֻ��糣��\n" NOR);
				break;
			}
		case "qiantian-yiyang":
			if( intp(p = target->query_temp("dali_jing")) ){
				target->add_temp("apply/intelligence", -p);
				target->delete_temp("dali_jing");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ��޷�����Ǳ���ˡ�\n" NOR);
				break;
			}
		case "guiyuan-tunafa":
			if ( intp(p = target->query_temp("tz/focus")) ){
				target->add_temp("apply/attack", p);
				target->add_temp("apply/strength", p);
				target->delete_temp("tz/focus");
				tell_object(target, HIR"�㵤��ҪѨ���ˣ�������Щί�٣������漴�ָ���̬��\n"NOR);
				break;
			}
		case "kurong-changong":
			if( intp(p = target->query_temp("krcg_kurong")) ){
				target->delete_temp("krcg_kurong");
				target->add_temp("apply/armor", -p);
				target->add_temp("apply/parry", -p);
				tell_object(target, HIR"�㵤��ҪѨ���ˣ������١���������ɢ�ˣ�\n" NOR);
				break;
			}
			
		case "bihai-chaosheng":
			if( intp(p = target->query_temp("thd/maze")) ){
				target->delete_temp("thd/maze");
				target->add_temp("apply/dexerity", -p/10);
				target->add_temp("apply/parry", -p /2);
				target->add_temp("apply/dodge", -p /2);
			         if( me->query_temp("thd/mazed") ){ 
                                                        me->add_temp("apply/dexerity", p/10);
				me->add_temp("apply/damage", p/2);
				me->add_temp("apply/dodge", p /2);
				me->add_temp("apply/parry", p /2);
                                                        me->delete_temp("thd/mazed");
                                                         }
				tell_object(target, HIR"�㵤��ҪѨ���ˣ���Ͼ�˼��������󣬽���������¾ͱ���ɢ�ˣ�\n" NOR);
				break;
			}
           }
	         qi_wound = ap  +random(ap*2) ;
                 neili_wound =( qi_wound + random(qi_wound/2))* 5;
                
                if(neili_wound > target->query("neili"))
                   neili_wound = target->query("neili");

                if(qi_wound > target->query("qi"))
                   qi_wound = target->query("qi");
                if(random(2)== 1)
                target->apply_condition("no_perform", 2+ random(3));
                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound*2/3);
                target->add_busy(1);
target->set_temp("must_be_hit",1);
        message_vision(msg, me, target);

              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
   
     
	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

       
                me->start_perform(4,"����ʤ����");
       }

 else
              { 

         message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       
                me->start_perform(4,"����ʤ����");
         }


        me->add_temp("apply/attack", -skill/6);
        me->add_temp("apply/damage", -skill/4);
        me->add_temp("apply/sword",  -skill/4);
me->delete_temp("pfmwz");

target->delte_temp("must_be_hit");
        return 1;

}
int help(object me)
{
	write(HIC"\n���¾Ž�������ʤ���С���"NOR"\n");
	write(@HELP
 
���¾Ž�������ʤ���С�


����塣�����������������ڡ�������ʤ���С���Ҫּ�������á�
�ǡ����¾Ž����еġ��ƽ�ʽ����ֻһʽ�������������¸��Ÿ���
����Ҫ����ղ����˵�����С���ȴ���������½���֮����Ϊ��
�������ˡ����������������˵�ľ��֮�ϣ�һ��֮�����������з�
��֮������  �����۵��ֵ����������񣬵��ˡ����¾Ž�����΢
�Ľ���֮�£�������ա����������¾Ž����ǵ�ǿ��ǿ����������
�¾Ž��������ְ��΢֮�����������˾��콣������֮�⣬�м�
��һ��������ʹ���ߵ�����ʹ���ߴ����ǻ�Խ�ߣ�����Ҳ��Խ�ߡ�����     

	
 Ҫ��	��ǰ���� 2500 ���ϣ�
	���¾Ž��ȼ� 350 lv���ϣ�      
        �����������¾Ž���
        �����мܶ��¾Ž���
        
	      �ֱֳ�����
        ���ߵ����Զ�ս���ж����Ч���� 

HELP
	);
	return 1;
}
