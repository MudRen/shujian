// by darken@SJ
// Modify By River@SJ 2001.6.18

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
string perform_name(){ return HIW"һ��������"NOR; }
int perform(object me, object target)
{
        int skill = me->query_skill("quanzhen-jianfa", 1);
        object weapon = me->query_temp("weapon");  
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
         || !me->is_fighting(target) 
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("һ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_skill("force", 1) < 100 )
                return notify_fail("����ڹ����δ�����޷�ʩչһ�������壡\n");

        if( me->query_skill("dodge") < 150 )
                return notify_fail("һ�����������Ṧ��ϣ�����ʩչ��\n");

        if( me->query_skill("sword") < 150 )
                return notify_fail("�㽣�����δ�㣬�޷�ʹ��һ�������壡\n");

        if( me->query("neili") < 500 )
                return notify_fail("�����������ʹ��һ�������壡\n");

        if( me->query("jingli") < 150 )
                return notify_fail("��ľ�������ʹ��һ�������壡\n");
     
       if( me->query_temp("sanqing") )
                return notify_fail("������ʹ��һ���������أ�\n");

        if((int)me->query_temp("hebi"))
               return notify_fail("������ʩչ˫���ϱڣ��޷�ʹ�á�һ�������塹������\n"); 

        if(!me->query_skill("xiantian-gong"))
          if(me->query_skill("yunu-xinjing", 1) < 100)
                return notify_fail("����ڹ���򲻹����޷�ʹ��һ�������塣\n");

        if (!weapon 
         || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("�������޽�����ʹ��һ�������壿��\n");

        msg = HIW"\n$Nһ����Х��ʹ��ȫ�潣���е�һ�������壬����ֳ����㣬����$n��\n" NOR;
        message_vision(msg , me, target);
        me->add_temp("apply/attack", me->query_skill("xiantian-gong") /3 );
        me->add_temp("apply/damage", me->query_skill("xiantian-gong")/4 );
        me->add("neili", -300);
        me->add("jingli", -100);
        me->set_temp("sanqing", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?3:1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?3:1);
  
  if(me->query_skill("quanzhen-jianfa",1)<=450 ) 
  	    me->start_perform(3,"һ��������");
  
        call_out("check_fight", 2, me, target, weapon, skill/20);
        return 1;
}

void check_fight(object me,object target,object weapon,int count)
{
        if(!me) return;
	     if(!target
	       || !me->is_fighting(target)
         || !weapon
         || me->query_skill_mapped("sword") != "quanzhen-jianfa"
         || count < 3 ){
                message_vision(HIW"\n�⼸��һ���ǳɣ��������������Ƴ��ȣ�ȡ��������壬����ȫ�潣���еľ������ڡ�\n\n"NOR, me);
                me->delete_temp("sanqing");
                me->add_temp("apply/attack", -me->query_skill("xiantian-gong")/3);
                me->add_temp("apply/damage", -me->query_skill("xiantian-gong")/4);
                return;
         }
         else {
           me->set_temp("sanqing", 1);
           if (me->query_skill("xiantian-gong", 1) > 551) {
             if (me->is_fighting(target))
             	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
             if (me->is_fighting(target) && random(2))
             	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
           }
           if (me->is_fighting(target))
           	           	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
           if (me->is_fighting(target))
           	           COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
         }
         call_out("check_fight", 2, me, target, weapon, count - 3);  

}
