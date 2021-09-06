//kungfu/skill/liuyang-zhang/baihong.c �׺�
// modified by action@SJ 2009/2/5
//updated By action@sjmud 2009/5/21
//modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
string perform_name(){ return HIR"�׺�"NOR; }

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int lv, a;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("���׺硹����ֻ����ս����ʹ�á�\n");
                
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á��׺硹���У�\n");   
                
        if( (int)me->query_skill("liuyang-zhang", 1) < 180 )
                return notify_fail("�����ɽ�����ƻ�������죬ʹ�������׺硹���С�\n");
                
        if (me->query_skill_prepared("strike") != "liuyang-zhang"
            || me->query_skill_mapped("strike") != "liuyang-zhang"
            || me->query_skill_mapped("parry") != "liuyang-zhang")
                return notify_fail("�������޷�ʹ�á��׺硹���й�����\n");  

        if( (int)me->query_skill("bahuang-gong", 1) < 180 )
        if( (int)me->query_skill("beiming-shengong", 1) < 180 )
                return notify_fail("����ڹ��ȼ���������ʹ�������׺硹���С�\n");
                
        if (me->query_skill_mapped("force") != "bahuang-gong")
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ڹ������޷�ʹ�á��׺硹���С�\n");               
		            
        if( me->query("max_neili") < 2500 )
                return notify_fail("����������̫����ʹ�������׺硹���С�\n"); 
                     
        if( (int)me->query("neili") < 1500 )
                return notify_fail("����������̫����ʹ�������׺硹���С�\n");
                
        if( (int)me->query("jingli") < 1000 )
                return notify_fail("�����ھ�������̫����ʹ�������׺硹���С�\n");
                
   message_vision(HBMAG+HIW "\n$N�����ĳ�������һ��������֮�����²��������Ź���������ɽ\n"
                HBMAG"�����Ʒ��е�"+ HIW +"���׺�������"+ NOR + WHT +HBMAG+"���˿�$N������ֱ���⣬�����˵ã�\n"NOR, me); 
                  
        lv = me->query_skill("liuyang-zhang",1) /2+me->query_skill("beiming-shengong",1) /2;
       
  me->set_temp("baihong",6);
        if (me->query("family/family_name") == "��ң��"||me->query("family/family_name") == "���չ�") {
        me->add_temp("apply/attack", lv / 3);
        me->add_temp("apply/damage", lv / 3);
        me->add_temp("apply/strike", lv / 5);
      };
        me->add_temp("apply/strike", lv / 5);
        me->add_temp("apply/attack", lv  /3);
        me->add_temp("apply/strength", lv / 10);

        for(a=0;a<6;a++)
        {
		     if(random(2)) me->set_temp("lyz/baihong",1);

		     if (me->query_temp("lyz/baihong"))
		   {
		         if(me->is_fighting(target))
		         	me->prepare_skill("strike", "liuyang-zhang");
		         	me->prepare_skill("hand", "none");
                         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (lv<351)?1:3); 
                } else {
                 if(me->is_fighting(target))
                 	me->prepare_skill("strike", "liuyang-zhang");
                 	me->prepare_skill("hand", "none");
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
           }
        me->delete_temp("lyz/baihong");
        }
		    me->delete_temp("baihong");
		    me->delete_temp("lyz/baihong");
        if (me->query("family/family_name") == "��ң��"||me->query("family/family_name") == "���չ�") {
        me->add_temp("apply/attack", -lv / 3);
        me->add_temp("apply/damage",- lv / 3);
        me->add_temp("apply/strike",- lv / 5);
      };
        me->add_temp("apply/attack", -lv / 3);
        me->add_temp("apply/strike",- lv / 5);
        me->add_temp("apply/strength", -lv / 10);

		    me->start_perform(2 + random(2), "���׺硹");
  
        return 1;
}


int help(object me)
{
        write(HIR"\n��ɽ������֮���׺硹��"NOR"\n");
        write(@HELP
        ��ɽ������֮���׺硹����Ϊ��ң�������Ӿ�ѧ��

        Ҫ��  ������� 2500 ���ϣ�      
                ��ǰ���� 1500  ���ϣ�  
                ��ɽ�����Ƶȼ� 180 ���ϣ�
                ��ڤ�񹦻�˻�����Ψ�Ҷ��𹦵ȼ� 180 ���ϣ�
                �����Ʒ�Ϊ��ɽ�����ƣ�
                ���Ʒ�Ϊ��ɽ�����ƣ�
                �����ޱ�����                               
HELP
        );
        return 1;
}


