// ��÷.��ѩ.ɢ����  action@SJ 2008/12/28

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int lv;

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("����÷.��ѩ.ɢ���㡿ֻ����ս����ʹ�á�\n");
                
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���÷.��ѩ.ɢ���㡿��\n");   
                
        if( (int)me->query_skill("zhemei-shou", 1) < 100 )
                return notify_fail("�����ɽ��÷�ֻ�������죬�޷�ʹ������÷.��ѩ.ɢ���㡿������\n");     
                
        if( (int)me->query_skill("hand", 1) < 100 )
                return notify_fail("��Ļ����ַ���������죬�޷�ʹ������÷.��ѩ.ɢ���㡿������\n");   
                
        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("����ڹ���Ϊ���㣬�޷�ʹ������÷.��ѩ.ɢ���㡿������\n");                                                         

        if (me->query_skill_mapped("force") != "bahuang-gong" )
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ʹ�õ��ڹ����ԣ��޷�ʹ������÷.��ѩ.ɢ���㡿��\n");  
                
        if ( me->query_skill_mapped("parry") != "zhemei-shou"
	            && me->query_skill_mapped("hand") != "zhemei-shou")
		            return notify_fail("�������޷�ʹ�á���÷.��ѩ.ɢ���㡿��\n");
		            
		    if (me->query_skill_prepared("hand") != "zhemei-shou"
	             || me->query_skill_mapped("hand") != "zhemei-shou")
	              return notify_fail("�������޷�ʹ�á���÷.��ѩ.ɢ���㡿��\n");

        if( (int)me->query_temp("tanmei") > 0 )
                return notify_fail(HIG"��ո��ù�����÷.��ѩ.ɢ���㡿����һ����ʹ�ðɡ�NOR\n"NOR);
                
        if( (int)me->query("max_neili", 1) < 1000 )
                return notify_fail("������������Ϊ���㣬�޷�ʹ������÷.��ѩ.ɢ���㡿��\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫�����޷�ʹ������÷.��ѩ.ɢ���㡿��\n");
                
        if( me->query("jingli") < 300 )
		            return notify_fail("�����ھ�������, �޷�ʹ������÷.��ѩ.ɢ���㡿! \n");
        lv = me->query_skill("zhemei-shou",1)/2+ me->query_skill("liuyang-zhang",1)/2;
        lv = lv *2 /3;
  if(!userp(me)) lv = lv / 6;

        if (me->query("family/family_name") != "��ң��"&& me->query("family/family_name") != "���չ�")
                 lv  =  lv / 6;

        me->add_temp("apply/attack", lv);
        me->add_temp("apply/damage", lv /2 );
        me->add_temp("apply/strength", lv /10 );
        me->add_temp("apply/hand", lv /2 );
        me->add_temp("apply/parry", lv /2 );
if( me->query_skill("zhemei-shou",1)>350 && !userp(target)) target->add_busy(1+random(2)); 

        me->set_temp("tanmei");
message_vision(MAG "$N΢΢һЦ��ʹ��"HIG"����÷.��ѩ.ɢ���㡿"MAG"������$n���ᵯ����������Ҫ��ȥ÷�������¶�飡       
\n"HIW"���� ÷��\n"NOR, me,target);

		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 

message_vision(HIG "$nͻȻ�ŵ�һ���������޵���ζ����Գ����֮��$N��˫������$p�ؿ�������                        
\n"HIW"���� ѩ��\n"NOR, me,target);

		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
message_vision(HIC "$N˫�ּ��ӣ�����ҡ�ڣ��ó�����"HIW"÷��"HIC"����ѩ�Ƶ���$n������                                    
\n"HIM"��ɢ���㡿\n"NOR, me,target); 


		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 

		    me->delete_temp("tanmei");

        me->add_temp("apply/attack", -lv);
        me->add_temp("apply/damage",- lv /2 );
        me->add_temp("apply/strength", -lv /10 );
        me->add_temp("apply/hand", -lv /2 );
        me->add_temp("apply/parry", -lv /2 );


		    me->start_perform(3 + random(2), "����÷.��ѩ.ɢ���㡿");
        return 1;
}

string perform_name(){ return HIG"��÷.��ѩ.ɢ����"NOR; }

int help(object me)
{
	write(YEL"\n��ɽ��÷��֮"HIG"����÷.��ѩ.ɢ���㡿��"NOR"\n");
	write(@HELP
	
	Ҫ��
	��ǰ���� 500 ���ϣ�
	������� 1000 ���ϣ�
	��ǰ���� 300���ϣ�
	��ɽ��÷�ֵȼ� 100 ���ϣ�
	�˻�����Ψ�Ҷ��𹦵ȼ� 100 ���ϣ�
	��ڤ�񹦵ȼ� 100 ���ϣ�
	�ڹ���Ч�ȼ� 100 ���ϣ�
HELP
	);
	return 1;
}
