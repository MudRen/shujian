//tulong.c ����
// By Spiderii@ty
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
 
string perform_name() {return HIC"����������"NOR;}

int perform(object me, object target)
{
        string weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
        
      if((int)me->query_skill("yitian-tulong",1) < 200 )
         return notify_fail("�������������������������ʹ������������\n");
      
      if((int)me->query_skill("literate",1) < 200 )
         return notify_fail("��Ķ���д�ֵȼ�������ʹ������������\n");  

      if((int)me->query_skill("sword",1) < 200 )
         return notify_fail("��Ļ�������������������\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("�����������ʹ����������\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("��ľ�������ʹ����������\n");

        if( me->query_temp("yttlg/tulong"))
                return notify_fail("������������������\n");

        if( !me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("�������޽�����ʹ������������\n");
              
        weapon = (me->query_temp("weapon"))->query("name");
              
       message_vision(HIY "\n$N������" + weapon + HIY"���ʣ��ڿ���д��������ÿһ�ְ������У���������仯��\n" +
        "�������п��ϣ����ݴ����Ʈѩ�裬���ش��绢���󲽣��������ۻ�ս������캨����\n" NOR, me, target);

skill = me->query_skill("yitian-tulong",1);

        me->set_temp("yttlg/tulong",1);
           me->add_temp("apply/attack", skill/3);
           me->add_temp("apply/damage", skill/3);
           me->add_temp("apply/parry",skill/10);        
           me->add_temp("apply/dodge", skill/10);
        
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
       me->add("neili", -(me->query_skill("force")));
       me->add("jingli", - 100);
       me->start_perform(4, "������");
       call_out("remove_effect", 1, me, target, weapon, skill/10);
       return 1;
}

int remove_effect(object me,object target,object weapon,int count)
{
        if(!me) return 0;
        if(!me->query_temp("yttlg/tulong")) return 0;
        if( !target 
         || ! me->is_fighting(target)
         || weapon != me->query_temp("weapon")
         || me->query_skill_mapped("sword") != "yitian-tulong"
         || count < 0){
           me->add_temp("apply/attack", -me->query_skill("yitian-tulong", 1)/3);
           me->add_temp("apply/damage", -me->query_skill("yitian-tulong", 1)/3);
           me->add_temp("apply/parry", -me->query_skill("yitian-tulong", 1)/10);        
           me->add_temp("apply/dodge",- me->query_skill("yitian-tulong", 1)/10);
           me->delete_temp("yttlg/tulong");
           if(living(me))
             message_vision(HIG "\n$N�Խ����ʣ���ʮ�ĸ���һ����һ��ķ�����չ������ʼ�գ�\n\n" NOR, me);
           return 0;
         }
         call_out("remove_effect", 1 ,me ,target, weapon, count -1);
}


int help(object me)
{
   write(HIG"\n��"HIW"����������"HIG"����"NOR"\n");
	write(@HELP
   
   ���������𣬱����������������£�Ī�Ҳ��ӡ����첻����˭�����档��
  
   �������ٵ�֮��,�����,��֮�����������ʮ�ĸ�����Ϊһ���书����
   ���䵱�Ŵ�ɽ��������
  
    ָ�perform sword(parry).yttl

    Ҫ�󣺻�������200��
          ����д��200��
          ����������200��
          ��ǰ����3000���ϣ���ǰ����1000���ϣ����г��н���������
                    

    ˵��������������������ȭ���ݱ������Ҫ����ߵ��鷨���裬
          ����֮�󣬲��жϼ�����
HELP
	);
	return 1;
}
