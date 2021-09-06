// hebi.c ��Ů����ȫ�潣������һ���
//by sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill, skill1, skill2;
	
	object weapon,weapon2;
       object *inv;
       int i, count;
	string bei_skill;

	if( !target) target= offensive_target(me);

    if(me->query("gmhb") != "pass" && ! me->query("quest/hubo/pass") )
		return notify_fail("����δ�������һ�������������˫��������һ�����\n");

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
		return notify_fail("˫��������һ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	
	if( (int)me->query_temp("hubo") ) 
	{
		return notify_fail("��������˫��������һ�����\n");
	}

	if( (int)me->query_temp("hebi") ) 
	{
		return notify_fail("�������˺ϱڣ������ٽ���˫��������һ�����\n");
	}


       if( me->query_skill_mapped("sword") != "yunu-jianfa" && me->query_skill_mapped("sword") != "quanzhen-jianfa")
		return notify_fail("����ͨ����������Ů������ȫ�潣������˫��������һ�����\n");


	if(me->query_skill("quanzhen-jianfa",1) <120)
		return notify_fail("���ȫ�潣����������������˫��������һ�����\n");

	if(me->query_skill("yunu-jianfa",1) <120)
		return notify_fail("�����Ů������������������˫��������һ�����\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" &&
		me->query_skill_mapped("force") != "xiantian-gong"
		)
		return notify_fail("�����õĲ�����Ů�ľ������칦���޷�ʩչ˫��������һ�����\n");

	if( me->query_skill("yunu-xinjing", 1) < 120 &&
		me->query_skill("xiantian-gong", 1) < 120
		)
		return notify_fail("�����Ů�ľ������칦���δ�����޷�ʩչ˫��������һ�����\n");
	

	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("�������˫�����ܺ�����һ�����\n");

     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
           if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   break;
		   }
     }

	if( !objectp(weapon2) )
		return notify_fail("�������˫�����ܺ�����һ�����\n");

	if( me->query("neili") <= 400 )
		return notify_fail("�����������ʹ��˫��������һ�����\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ��˫��������һ�����\n");
	if( me->query("jing") <= 120 )
		return notify_fail("��ľ�����ʹ��˫��������һ�����\n");

	skill =  ( me->query_skill("sword",1) + me->query_skill("yunu-jianfa",1)
		+ me->query_skill("quanzhen-jianfa",1) +me->query_skill("yunu-xinjing",1) 
		+ me->query_skill("force")) / 10; 

if(me->query("gender")=="Ů��") skill = skill*3/2;

	message_vision(
	HIR "$NͻȻ�����ֳ����һ�ѽ���˫��ʹ�����ֽ�Ȼ��ͬ�Ľ������������һ���������\n"+HBBLU+HIM"ֻ��$N˫��һ������������Ů������ȫ�潣����ϵ������޷죬���ܻ��̣���������������ֽ���һ�㣬����������\n\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/2);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/sword",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->set_temp("hubo", 1);

	bei_skill = me->query_skill_mapped("sword");
if(me->query("max_pot")<=451 )
 target->start_busy(1+random(2));
 
 if(me->is_fighting(target)) {
    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	if(weapon) weapon->unequip();
	weapon2->wield();
                                       }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "quanzhen-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		if(weapon2) weapon2->unequip();
	   if(weapon)	weapon->wield();
                                    }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	if(weapon)	weapon->unequip();
	if(weapon2) 	weapon2->wield();
                                   }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "quanzhen-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	if(weapon2)	 weapon2->unequip();
	if(weapon)	weapon->wield();
                                 }
 if(me->is_fighting(target)) {
    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	if(weapon)	weapon->unequip();
	if(weapon2)	 weapon2->wield();
                              }
 if(me->is_fighting(target)) {
            me->map_skill("sword", "quanzhen-jianfa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                             }

       me->map_skill("sword", bei_skill);
	if(weapon2)	 weapon2->unequip();
   if(weapon)  weapon->wield();

	me->add("jingli", -100);
	me->add("jing", -100);
	me->add("neili", -300);
	me->start_busy(1+random(2));
     if(me->is_fighting(target))  target->start_busy(1+random(2));  

	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill/2);
	me->add_temp("apply/dodge",  -skill/2);
	me->add_temp("apply/sword",  -skill/2);
	me->add_temp("apply/parry",  -skill/2);
        me->delete_temp("hubo");
	if(weapon)
	message_vision(HIY "\n$N������һ���������ֽ�"+"$n" + HIY "��ؽ��ʣ��������У�\n\n" NOR, me,weapon);
   else 
   		message_vision(HIY "\n$N������һ�������������У�\n\n" NOR, me);
	return 1;
}
