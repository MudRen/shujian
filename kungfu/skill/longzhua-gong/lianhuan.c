// lianhuan.c ��צ��������ʽ
// By Spiderii ��̬�޸ġ��������趨Ϊ�߹��������˺��������ǽ����������
/*
    ����ͻȻ����һ����������ϣ�˫�����������꣬������ʽ������׽Ӱʽ����������ʽ��������ɪʽ����������ʽ����������ʽ����������ʽ��������ȱʽ������ʽ�������������������޼������У���ʽ��Ϊ������׽Ӱ�����ٹ�ɪ���������顢������ȱ���������У����к󷢶�������
    ������ɮ���ʽ��������צ�����಻����������һ���еİ˸��仯һ�㣬����ޱȣ�
*/

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
string perform_name(){ return RED"������ʽ"NOR; }

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int lv, i, hit;
         string weapon, lzg_msg;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("��������ʽ��ֻ����ս����ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á�������ʽ����\n");   
        if( (int)me->query_skill("longzhua-gong", 1) < 100 )
                return notify_fail("�����צ����������죬ʹ������������ʽ��������\n");
        if (me->query_skill_prepared("claw") != "longzhua-gong"
        || me->query_skill_mapped("claw") != "longzhua-gong")
                return notify_fail("�������޷�ʹ�á�������ʽ�����й�����\n");  

	if( me->query_skill_mapped("force") != "yijin-jing" )
		return notify_fail("������ʹ�õ��ڹ�������ʹ�á�������ʽ����\n");
        if( (int)me->query_skill("yijin-jing", 1) < 100 )
                return notify_fail("����׽�ȼ���������ʹ������������ʽ��������\n");
        if (me->query("class") && me->query("class") != "bonze")
		            return notify_fail("������ڵ��ӣ�����ʹ�á�������ʽ����\n");
        if( me->query("max_neili") < 1000 )
                return notify_fail("����������̫����ʹ������������ʽ����\n");      
        if( (int)me->query("neili") < 800 )
                return notify_fail("����������̫����ʹ������������ʽ����\n");
      
        
        lv = me->query_skill("longzhua-gong",1)+ me->query_skill("yijin-jing",1)/3;
        hit = (lv/50);
        if(hit > 8) hit = 8;
        if(hit <2) hit = 2;
        
        me->add_temp("apply/attack", lv*2/5);
        me->add_temp("apply/damage", lv*3/5);
        me->add_temp("apply/parry", -lv);
        lzg_msg = RED"\n$NͻȻ����һ����������ϣ�˫������������: \n";

        if(hit >= 2)lzg_msg += "��������ʽ������׽Ӱʽ��";
        if(hit >= 4)lzg_msg += "��������ʽ��������ɪʽ��";
        if(hit >= 6)lzg_msg += "��������ʽ����������ʽ��";
        if(hit >= 8)lzg_msg += "��������ʽ��������ȱʽ��";
        
        lzg_msg += "��\n"+chinese_number(hit)+"ʽ����������������\n"NOR;

        message_vision(lzg_msg, me, target);
        me->set_temp("lzg_times",hit);
        me->set_temp("lzg_effect",1);
        me->add_temp("lzg/lianhuan", 3);
        me->set_temp("action_flag", member_array("claw", keys(me->query_skill_prepare())));
if(!userp(target)) target->add_busy(1+random(2));
        for( i=0; i < hit; i++ )
        {
                me->add_temp("lzg/lianhuan", 1);
                COMBAT_D->do_attack(me, target, weapon, random(2)?3:1);
        }


       message_vision(HIY"\n��"+chinese_number(hit)+"ʽ��������צ�����಻����������һ���е�"+chinese_number(hit)+"���仯һ�㣬����ޱȣ�\n"NOR, me);

        me->add("neili", -hit*20+20);
        me->add("jing", -hit*5);
        me->start_perform(3,"��������ʽ��");
        me->start_busy(1+random(2));
        me->delete_temp("lzg/lianhuan");
        me->delete_temp("lzg_times");
        me->add_temp("apply/attack", -lv*2/5);
        me->add_temp("apply/damage", -lv*3/5);
        me->add_temp("apply/parry", lv);
        return 1;
}


int help(object me)
{
        write(HIB"\n��צ��֮��������ʽ����"NOR"\n");
        write(@HELP
        ��צ��Ϊ������ʮ������֮һ��������ϰ��������ָ������Ҫ�������ֳ������֡�
        Ϊ��Ӳ���֮�������Ტ��֮�����������֮����������������ע������ָ�з�Ϊ
        ��ɡ��ˡ�������ʽ��һ��ʹ�������������꣬����ץ�������������������ޱȡ�
        ��ʽ����Υ�����ּ������������ɮϲ�������������ࡣ

        Ҫ��  ������� 1000 ���ϣ�      
                ��ǰ���� 800  ���ϣ�  
                ��צ���ȼ� 100 ���ϣ�
                �׽�ȼ� 100 ���ϣ�
                ����צ��Ϊ��צ����
                �����м�Ϊ��צ����
                �����ޱ�����
                ��צ��ÿ�����ȼ� 100 lv��
                ��׷��2 hit ������
                ��߿��� 8 hit ������
                
HELP
        );
        return 1;
}


