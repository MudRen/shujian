// ����Ǭ��  action@SJ 2008/12/28
//modified by zhuifeng@SJFY 2010/0717

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
string perform_name(){ return HIB"����Ǭ��"NOR; }

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int lv, i, hit;
         string weapon;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("������Ǭ����ֻ����ս����ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á�����Ǭ������\n");   
                
        if( (int)me->query_skill("liuyang-zhang", 1) < 100 )
                return notify_fail("�����ɽ�����ƻ�������죬ʹ����������Ǭ����������\n");
                
        if (me->query_skill_prepared("strike") != "liuyang-zhang"
            || me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("�������޷�ʹ�á�����Ǭ�������й�����\n");  

        if( (int)me->query_skill("bahuang-gong", 1) < 100 )
        if( (int)me->query_skill("beiming-shengong", 1) < 100 )
                return notify_fail("����ڹ��ȼ���������ʹ����������Ǭ����������\n");
                
        if (me->query_skill_mapped("force") != "bahuang-gong")
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("����ڹ������޷�ʹ�á�����Ǭ������\n");               
		            
        if( me->query("max_neili") < 1000 )
                return notify_fail("����������̫����ʹ����������Ǭ������\n"); 
                     
        if( (int)me->query("neili") < 800 )
                return notify_fail("����������̫����ʹ����������Ǭ������\n");
      
        
        lv = me->query_skill("liuyang-zhang",1);
        lv = lv /3;
        hit = (lv/50);
        if(hit > 6) hit = 6;
        if(hit <2) hit = 2;

       if(me->query("family/family_name") == "��ң��"||me->query("family/family_name") == "���չ�") 
    {
        if(!userp(target)) target->add_busy(random(2));

    }     
        me->add_temp("apply/attack", lv*4/5);
        me->add_temp("apply/damage", lv*3/5);
        me->add_temp("apply/parry", lv);
        
message_vision(HIB"\n$NͻȻ���һ����ʹ����ң�ɾ�ѧ������Ǭ����,����ǵ���$n��Ϯ��ȥ��\n"NOR, me,target);

        me->set_temp("lyz_times",hit);
        me->set_temp("lyz_effect",1);
        me->add_temp("lyz/jiutian", 3);
        me->set_temp("action_flag", member_array("strike", keys(me->query_skill_prepare())));

        for( i=0; i < hit; i++ )
        {
                me->add_temp("lyz/jiutian", 1);
                COMBAT_D->do_attack(me, target, weapon, (me->query_skill("liuyang-zhang",1)<351)?1:3);
        }

      
        me->add("neili", -hit*20+20);
        me->add("jing", -hit*5);
        me->start_perform(3,"������Ǭ����");
        me->delete_temp("lyz/jiutian");
        me->delete_temp("lyz_times");
        me->add_temp("apply/attack", -lv*4/5);
        me->add_temp("apply/damage", -lv*3/5);
        me->add_temp("apply/parry", -lv);
        return 1;
}

int help(object me)
{
	write(YEL"\n��ɽ������֮������Ǭ������"NOR"\n");
	write(@HELP

	Ҫ�󣺵�ǰ���� 1000 ���ϣ�
		������� 1000 ���ϣ�
		��ǰ���� 500���ϣ�
		��ɽ�����Ƶȼ� 100 ���ϣ�
                �˻�����Ψ�Ҷ��𹦵ȼ� 100 ���ϣ�
		�ڹ���Ч�ȼ� 100 ���ϣ�
HELP
	);
	return 1;
}
