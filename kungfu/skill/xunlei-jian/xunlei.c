//xunlei.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
string perform_name(){ return HIY"Ѹ�׾�"NOR; } 
int perform(object me, object target)
{
        object weapon;
				
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
	   		  return notify_fail("��Ѹ�׾���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("xunlei_yushi"))
	  		   return notify_fail("�㽣��δ����������ʩչ��Ѹ�׾�����\n");

        if((string)me->query_skill_mapped("sword") != "xunlei-jian" && userp(me))
           return notify_fail("�������޷�ʹ�á�Ѹ�׾�����\n");
                   
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
	  		   return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("neili") < 800 )
	   		 	 return notify_fail("�������������\n");
				
				if( (int)me->query("max_neili") < 1500 )
	   		 	 return notify_fail("���������Ϊ������\n");
	   		 	 
        if((int)me->query_skill("xuantian-wuji",1) < 140 )
           return notify_fail("��������޼������������ʹ������Ѹ�׾�����\n");
           
        if( me->query_skill("xunlei-jian", 1) < 140 )
	    		 return notify_fail("���Ѹ��ʮ����δ�����磬�޷�ʹ�á�Ѹ�׾�����\n");

if(me->query_skill("xunlei-jian",1) <450)
      me->start_perform(5,"Ѹ�׾�");
        message_vision(HIR "\n$N����"+weapon->query("name")+HIR"����ָ���Լ��ؿڣ�����бб���⣬����֮�������ƻؽ�����һ�㣡\n\n"	 NOR, me,target);
me->delete_temp("xunlei");
        me->set_temp("xunlei",4);
        me->add("neili", -50);
        me->set_temp("xunlei_yushi",1);
        call_out("checking", 1, me, target);
        return 1;
}


void checking(object me, object target)
{

 	object weapon;
 	int i,k;
 	
 	if( !me )  return;
 		
 	if( !target ) target = offensive_target(me);
       
  if( !target || !(target->is_character()) || !(me->is_fighting(target)) ) {
			call_out("xunlei_end", 1, me);
		return; 
  }
  
  weapon = me->query_temp("weapon");

  if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword") {
		tell_object(me, "\n�������޽�������ֹͣ��Ѹ�׾��ļ��ơ�\n" NOR);
			call_out("xunlei_end", 1, me);
		return;
	}
	else if ( weapon->query("weapon_prop") == 0 ) {
		tell_object(me, "\n���"+weapon->name()+"�ѻ٣��޷�������Ѹ�׾����Ĺ��ƣ�\n\n" NOR);
		call_out("xunlei_end", 1, me);

		return;
	}
	else if ( (int)me->query("neili") < 400  ) {
		message_vision(HIR"$N���ھ�������������ò�ֹͣ��Ѹ�׾����Ĺ��ƣ�\n" NOR, me,target);
        	call_out("xunlei_end", 1, me);
		return;
	}
	else if ( me->query_skill_mapped("sword") != "xunlei-jian" ) {
		tell_object(me, HIR "\n��ת��ʩչ�����������޷����ԡ�Ѹ�׾������У�\n\n" NOR);
        	call_out("xunlei_end", 1, me);
		return;
	}
	else if ( me->is_busy() ) {
		tell_object(me, HIR "\n�����ڶ����������޷�����ά�֡�Ѹ�׾������ƣ�\n\n" NOR);
		call_out("xunlei_end", 1, me);
		return;
	}
	else if (!me->is_fighting()) {
		tell_object(me,  "\n������û�к��˹��У������ջ��ˡ�Ѹ�׾����Ĺ��ơ�\n" NOR);
		call_out("xunlei_end", 1, me);
		return;
	}
	if( environment(target) != environment(me) ) {
		tell_object(me, "����Է��Ѿ������������ֹͣ�ˡ�Ѹ�׾����Ĺ��ơ�\n");
		call_out("xunlei_end", 1, me);
		return;
	}
	else{

        if ( me->query_temp("xunlei") ==4 )message_vision(HIY"\n$N�����ǰ��"+weapon->name()+HIY"��Ȼ���䵯��������ֱ��$n������֮������Ϊ�κν�����������\n" NOR, me,target);
        if ( me->query_temp("xunlei") ==3 )message_vision(HIW"\n$N��ָ��"+weapon->name()+HIW"��һ�����������ˣ�����������"+weapon->name()+HIW"�������������������޷���\n" NOR, me,target);
        if ( me->query_temp("xunlei") ==2 )message_vision(HIG"\n$N��Ȼ����һ����"+weapon->name()+HIG"�Ϻ����������ȵ�����"+target->name()+HIG"����С���ˣ���\n" NOR, me,target);
        if ( me->query_temp("xunlei") ==1 )message_vision(HIR"\nֻ��$N���ֻӽ���"+weapon->name()+HIR"������ǰ�����ң�˲Ϣ֮���ѹ���������һʮ���У�\n" NOR, me,target);
				me->add("neili", -100);
				
        i=me->query_skill("xunlei-jian",1);
if(!userp(me)) i = i /2;
        me->add_temp("apply/attack", i/2);
        me->add_temp("apply/damage", i/3);
        me->add_temp("apply/sword",  i/3);

        
        for(k = 0; k < 3; k++) {
                if (me->is_fighting(target))
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        }
        if (me->is_fighting(target))
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
        
        me->add_temp("apply/attack", -i/2);
        me->add_temp("apply/damage", -i/3);
        me->add_temp("apply/sword",  -i/3);


        if ( me->query_temp("xunlei") ==1 ) {
						message_vision(HIY "\n$N˳��Ȧת����"+weapon->name()+HIY"��һʮ����Ѹ�׽���Ȼ����ʹ����\n" NOR, me, target);      	
        		call_out("xunlei_end", 6, me);        		
					}
				else {
	  				me->set_temp("xunlei", me->query_temp("xunlei")-1);
	   				call_out("checking", 4, me, target);
	  		 }  
      }


}  

void xunlei_end(object me)
{
    int i;
    if (me) {
        tell_object(me, HIW "\n�㰵�Ե�Ϣ������ƽ����ӿ��������\n\n" NOR);
        i = (4 - me->query_temp("xunlei")) / 2;
        if (i<0) i = 0;
        me->start_busy(i+random(2));
        me->delete_temp("xunlei");
        me->delete_temp("xunlei_yushi");				
		}		
}

int help(object me)
{
        write(HIY"\n��Ѹ�׾�����"NOR"\n");
        write(@HELP
        Ѹ��ʮ��������졢����ƣ����������ٶ�,�ų��Ĵ�ֻ����Ӱ������
        Ӱ���⡸Ѹ�׾������ǽ�Ѹ��ʮ�����졢�ݳ�ַ��ӵĽ�����

        Ҫ��  ������� 1500 ���ϣ�
                ��ǰ���� 800 ���ϣ�
                Ѹ��ʮ�����ȼ� 140 ���ϣ�
                �����޼����ȼ� 140 ���ϣ�
                
HELP
        );
        return 1;
}


