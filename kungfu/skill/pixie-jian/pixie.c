// pixie.c Ⱥа���� Created by action 2007/7/25

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIB"Ⱥа����"NOR;}

int perform(object me, object target)
{
        object weapon;
        int i,a,j;

        weapon = me->query_temp("weapon");
       
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�Ⱥа���ס�������\n");
 
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "pixie-jian")
                return notify_fail("�����޽�,����ôʹ�ó���Ⱥа���ס�������\n");

        if( (int)me->query_skill("pixie-jian", 1) < 250 )
                return notify_fail("��ı�а��������̫ǳ���޷�ʹ����а����֮��Ⱥа���ס�������\n");

        if( (int)me->query_skill("sword", 1) < 250 )
                return notify_fail("��Ļ�������̫��,�޷�ʹ����Ⱥа���ס�������\n");

        if( (int)me->query_skill("kuihua-shengong", 1) < 250)
                return notify_fail("��������ڹ�̫��,�޷�ʹ����Ⱥа���ס�������\n");

        if(me->query_skill_mapped("force") != "kuihua-shengong" )
            return notify_fail("��������ڹ����ԣ��޷�ʹ�á�Ⱥа���ס���\n");

        if( (int)me->query("max_neili") < 5000 )
               return notify_fail("���������Ϊ̫ǳ���޷�ʹ����Ⱥа���ס���\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("��������������޷�ʹ����Ⱥа���ס�����\n");

        if (   me->query_skill_mapped("sword") != "pixie-jian"
	          || me->query_skill_mapped("parry") != "pixie-jian"
	          || me->query_skill_mapped("dodge") != "pixie-jian")
                return notify_fail("�㲻ʹ�ñ�а����,���ʹ���ˡ�Ⱥа���ס���\n");                         
                     
message_vision(HIM"\n$N���е�"+weapon->query("name")+HIM"ͻȻһ�Σ��������ߣ�һ������������һƬ��Ӱ��һ�С�"+GRN+"Ⱥ"+
           "а����"+HIM+"��ֱ��$n��\n"NOR,me,target);  
        i = ((int)me->query_skill("pixie-jian",1)+(int)me->query_skill("kuihua-shengong",1))/2;
        	j = i /3;

	if ( i > 200 )
		j = to_int(i/200.0 * i/3.0);
        
        if ( me->query("quest/pixie/super") ) {
        	message_vision(HIW "\n������Ⱥָ��֮�������С�"+GRN+"Ⱥа����"+HIW+"��������ʹ��������������ʤ��ǰ���Ѵ������\n"NOR,me,target);
        	me->add_temp("apply/sword",j/2);
        	me->add_temp("apply/damage",j);
          }
    else if(me->query("quest/pixie/pass")) {
        	message_vision(HIW "\n$N���С�"+GRN+"Ⱥа����"+HIW+"���ѵÿ������侫Ҫ,��ʱʹ������,�����˽������!\n"NOR,me,target);
 target->set_temp("must_be_hit",1);
j= j*3/2;
                                            }
    me->add("jingli",-300); 
    me->add("neilili",-500); 
        me->add_temp("apply/attack", j*4/5);
	me->add_temp("apply/sword", j*2/5);
	me->add_temp("apply/damage", j/2);
		me->set_temp("pixie",4);
        for(a=0;a<4;a++)
        {
                 if(me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        }
		me->delete_temp("pixie");
		me->delete_temp("pxj/pixie");
        me->add_temp("apply/attack", -j*4/5);
        me->add_temp("apply/sword", -j*2/5);
        me->add_temp("apply/damage",-j/2);
        me->start_perform(4+ random(1), "��Ⱥа���ס�");
                if ( me->query("quest/pixie/super") ) {
        	me->add_temp("apply/sword",-j/2);
        	me->add_temp("apply/damage",-j);
          }
if(target) target->delete_temp("must_be_hit");
}


int help(object me)
{
   write(WHT"\n��а������"HIG"Ⱥа����"WHT"����"NOR"\n");
   write(@HELP
    ��������˸�����������а�����������ɡ����������ơ�����
    ��Ⱥа���ס����ǽ����������ܵĵ������,����ƽƽ�����޻���,
    �����������������������,����Ͽ�����,ʵ��һ��ɱ��!
    ָ�perform pixie

    Ҫ��  ���� 2000 ���ϣ�
            ������� 5000 ���ϣ� 
            ��а���� 250 ���ϣ�
            �������� 250 ���ϣ�
            ������ 250 ���ϡ�


HELP
   );
   return 1;
}
