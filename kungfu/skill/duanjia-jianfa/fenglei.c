//���� fenglei.c 

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return BLU"�����Ļ�"NOR;}

int perform(object me, object target)
{
        object weapon;
        int i,a;

        weapon = me->query_temp("weapon");
       
        if( !target ) target = offensive_target(me);
         if( !objectp(target)) return notify_fail("��Ҫ��˭������\n");

        if( !me->is_fighting() )
                return notify_fail("�������Ļ���ֻ����ս����ʹ�á�\n");
 
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "duanjia-jianfa")
                return notify_fail("�����޽�,����ôʹ�ó��������Ļ�����\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("�������������\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if( (int)me->query("jingli") < 300 )
                return notify_fail("��ľ���������\n");

        if( (int)me->query_str() < 24 )
                return notify_fail("��ı���������\n");

        if( (int)me->query_dex() < 24 )
                return notify_fail("�����������\n");

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) < 100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������������������\n");        
         
        if (me->query_skill_mapped("force") != "kurong-changong" )
          if(me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

        if( (int)me->query_skill("duanjia-jianfa",1) < 100 )
                return notify_fail("��Ķμҽ����������ң��޷�ʹ�á������Ļ���������\n");

        if( (int)me->query_skill("sword",1) < 100 )
                return notify_fail("��Ľ������費�����޷�ʹ����˸���ġ������Ļ���������\n");

        if( (int)me->query_skill("qingyan-zhang",1) < 100 ||
            me->query_skill_mapped("strike") != "qingyan-zhang")
                return notify_fail("������������ƻ������ң��޷�ʹ�á������Ļ���������\n");

        if( (int)me->query_skill("strike",1) < 100 )
                return notify_fail("����Ʒ����費�����޷�ʹ����˸���ġ������Ļ���������\n");

        if (me->query_skill_prepared("strike") != "qingyan-zhang"
          || me->query_skill_mapped("parry") != "qingyan-zhang")
                return notify_fail("�������޷�ʹ�á������Ļ������й�����\n");

        if( (int)me->query_skill("tianlong-xiang",1) < 100 )
                return notify_fail("����������������ң��޷�ʹ�á������Ļ���������\n");

        i = ((int)me->query_skill("duanjia-jianfa",1)+(int)me->query_skill("qingyan-zhang",1))/3;

if (i < 200) target->start_busy(1+random(2));

        message_vision(HIG"\n$N������ϣ�����"HIM"����������"HIG"������"HIW"�μҽ�"HIG"��ʩչһ���С�"HIR"�����Ļ�"HIG"����\n"NOR, me,target);
        me->add("neili",-(50+random(50))); 
        if (i > 200) i=200;
        me->add("jingli",-50); 
		me->set_temp("fenglei",4);
        for(a=0;a<4;a++)
        {
		     if(random(2)) me->set_temp("fl_sword",1);

		     if (me->query_temp("fl_sword"))
		   {
                         me->add_temp("apply/attack", i *2/2 );
                         me->add_temp("apply/strength", i /2 );
                         me->add_temp("apply/damage", i   );
                         me->add_temp("apply/sword", i /2  );
                         me->add_temp("apply/strike", i /2  );
		         if(me->is_fighting(target))
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3); 
                 me->add_temp("apply/sword", -i /2);
                 me->add_temp("apply/strike", -i /2);
                 me->add_temp("apply/strength", -i /2);
                 me->add_temp("apply/damage", -i );
                 me->add_temp("apply/attack", -i *2/2);
                } else {
		        weapon->unequip();
                         me->add_temp("apply/attack", i /2 );
                         me->add_temp("apply/strike", i /2 );
                         me->add_temp("apply/strength", i /2 );
                         me->add_temp("apply/damage", i  );
                 if(me->is_fighting(target))
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?1:3); 
                         me->add_temp("apply/damage", - i  );
                         me->add_temp("apply/strength", - i /2 );
                         me->add_temp("apply/strike", - i /2 );
                         me->add_temp("apply/attack", - i /2 );
                weapon->wield();
           }
     me->delete_temp("fl_sword");
        }
		me->delete_temp("fenglei");
		me->delete_temp("fl_sword");
        me->start_perform( 3 + random(2), "�������Ļ���");
if(target) target->start_busy(1);
        me->start_busy(2);
        return 1;
}
