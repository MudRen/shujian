// Create By lsxk@hsbbs 2007/6/14
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name() {return HIG"��ȥ����"NOR;}

int perform(object me, object target)
{
        int lev,hits,i;
		string restore, *liumaiset;

        if( !target ) target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target)
         || !living(target) )
                return notify_fail("����ȥ������ֻ����ս����ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���ȥ��������\n");   

        if( (int)me->query_skill("liumai-shenjian", 1) < 30 )
                return notify_fail("�㻹��δ��ͨ�������񽣡�֮һ�������ʹ�ó��þ���?\n");

        if((int)me->query_skill("force") < 250 ) 
                return notify_fail("����ڹ���Ϊ��������ʹ��������ȥ������������\n");

        if( (int)me->query("jiali")< 100 )
                return notify_fail("��ʹ�ù��ٵ������˵У��޷�������ȥ���������������ֳ�����\n");

        if( me->query_temp("pf_rong"))
                return notify_fail("���������á��١��ִ󷨣�\n"); 

        if( me->query_temp("yyz/6mai/6mai"))
                return notify_fail("������ר�����á������񽣡����ֲ�������ʹ�á���ȥ��������\n"); 

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 250)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ��������ȥ��������\n"); 

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ�á���ȥ��������\n"); 
/*
        if (me->query_skill_mapped("force") != "kurong-changong" )
        if (me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
*/
        if( (int)me->query("max_neili") < 4500 )
                return notify_fail("����������̫����ʹ��������ȥ��������\n"); 

        if( (int)me->query("neili") < 2000) 
                return notify_fail("����������̫����ʹ��������ȥ��������\n");

        if( (int)me->query("jingli") < 1000)
                return notify_fail("�����ھ���̫�٣�ʹ��������ȥ��������\n");

	lev = (int)me->query_skill("yiyang-zhi", 1);
	hits= sizeof(keys(me->query("liumai-shenjian")));
	if (me->query("env/liumai"))
		restore = me->query("env/liumai");
	if (hits>6) hits=6;
	liumaiset = keys(me->query("liumai-shenjian"));

        message_vision(HIG"\n$Nʮָ������ʱ��ʱ������ʱ����"+
       HIR+chinese_number(hits)+HIG"�����ν��������������������书������֮����������"HIM"��ȥ����"HIG"����\n"NOR,me,target);
if(random(2) || !userp(target) )  target->start_busy(1);
        me->add_temp("apply/attack",lev/2);
        me->add_temp("apply/finger",lev/2);
        me->add_temp("apply/damage",lev/4);
        me->set_temp("yyz/6m",1);
		for (i=0;i<hits;i++)
		{
                    me->set("env/liumai",liumaiset[i]);
                    COMBAT_D->do_attack(me, target, 0, (lev>450||random(2))?3:1);
			me->add("neili", -80);
        }
		if (restore)
			me->set("env/liumai",restore);
        me->start_busy(1);
        me->add_temp("apply/attack",-lev/2);
        me->add_temp("apply/finger",-lev/2);
        me->add_temp("apply/damage",-lev/4);
        me->delete_temp("yyz/6m");
//        me->add("neili", -500);
        me->add("jingli", -300);
        me->start_perform((hits>4)?5:4,"����ȥ������");
        return 1;
}

int help(object me)
{
   write(WHT"\nһ��ָ֮��"HIG"��ȥ����"WHT"����"NOR"\n\n");
   write(@HELP

     Ҫ��: ������� 4500 ���ϣ�
           ��ǰ���� 2000 ���ϣ�
           ��ǰ���� 1000 ���ϣ�
           �����񽣵ȼ� 30 ���ϣ�
           �����ڹ��ȼ� 250 ���ϣ�
           �����ڹ��ȼ� 250 ���ϣ�
           ���� 100 ���ϣ�
           ����ָ��Ϊһ��ָ����һ��ָ��
           ���ܺ͡������񽣡�����һ��ʹ�á�

HELP
   );
   return 1;
}
