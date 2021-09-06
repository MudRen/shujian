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

	if( !target ) target = offensive_target(me);

    if( !me->query("/quest/ѩɽ�ɺ�/�书/ronghe") )
		return notify_fail("����δ��֪�������ںϵİ��أ�\n");
		
	
		
        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
  		return notify_fail("�����ں�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

       if( me->query_skill_mapped("sword") != "miaojia-jianfa" || me->query_skill_mapped("blade") != "hujia-daofa")
		return notify_fail("�����ڻ�����ʹ�ú��ҵ�������ҽ������ںϼ��ɣ�\n");

     
	
      if(me->query_skill("miaojia-jianfa",1) <120)
		return notify_fail("�����ҽ�������������\n");

	if(me->query_skill("hujia-daofa",1) <120)
		return notify_fail("��ĺ��ҵ�������������\n");

	if( me->query_skill_mapped("force") != "lengquan-shengong" 
		)
		return notify_fail("�����õĲ�����Ȫ�񹦣�\n");

	

		
	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("������е�������ʹ�ã�\n");

     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
           if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   break;
		   }
     }

	if( !objectp(weapon2) )
		return notify_fail("������е�������ʹ�ã�\n");

	if( me->query("neili") <= 1000 )
		return notify_fail("�������������\n");
	if( me->query("jingli") <= 500 )
		return notify_fail("��ľ���������\n");
	if( me->query("jing") <= 120 )
		return notify_fail("��ľ�������\n");

	skill =  ( me->query_skill("sword",1) 
               + me->query_skill("miaojia-jianfa",1)
               + me->query_skill("hujia-daofa",1)
               + me->query_skill("blade",1)
               + me->query_skill("lengquan-shengong",1)) / 5; 

 skill = to_int(skill/250.0 * skill/2.0);


	message_vision(HIW"$N�����߶���Ȫ�񹦣�����ҽ����ͺ��ҵ����ں�ʹ�ã�����������������Ե�Ϊ�����Խ�ʹ������ʽ���������ٱ��\n" NOR, me);
 
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/damage", skill);
	me->add_temp("apply/sword",  skill/2);
	me->add_temp("apply/blade",  skill/2);

me->set_temp("pfmronghe",1);
       bei_skill = me->query_skill_mapped("sword");

if(skill>=351 && !userp(target)) {target->set_temp("must_be_hit",1);
                                    target->start_busy(2+random(2));
                                    }
if(skill>=451 && userp(target))  target->start_busy(2+random(2));

       me->map_skill("sword", "miaojia-jianfa");
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  

 if(me->is_fighting(target)) {
	weapon2->wield();
    me->map_skill("blade", "hujia-daofa");
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);   
	weapon2->unequip();
	weapon->wield();
                                   }

if(me->query_skill("lengquan-shengong",1) >= 350){

        if(me->is_fighting(target)) {
             me->map_skill("sword", "miaojia-jianfa");
	      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);  
	      weapon->unequip();
	      weapon2->wield();
                                   }
      if(me->is_fighting(target)) {
             me->map_skill("blade", "hujia-daofa");
	      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	      weapon2->unequip();
                                 }
}


if(me->query_skill("lengquan-shengong",1) >= 450){

             me->map_skill("sword", "miaojia-jianfa");
	      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);  
	      weapon->unequip();
	      weapon2->wield();
             me->map_skill("blade", "hujia-daofa");
	      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	      weapon2->unequip();
 
                                                  }


    me->map_skill("sword", bei_skill);
	weapon2->unequip();
	weapon->wield();

	me->add("jingli", -100);
	me->add("jing", -100);
	me->add("neili", -300);
	me->start_busy(1+random(2));
  if(target) {
target->start_busy(1+random(2));  
target->delete_temp("must_be_hit");
             }
	me->add_temp("apply/attack", -skill/2);
	me->add_temp("apply/damage", -skill);
	me->add_temp("apply/sword",  -skill/2);
	me->add_temp("apply/blade",  -skill/2);
me->delete_temp("pfmronghe",1);
    me->start_perform(2+random(2), "�������ںϡ�");
	return 1;
}
