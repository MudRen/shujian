// yinyang.c   ��Ȫ��֮�������޳���
// Create By lsxk@hsbbs 2007/5/12
// By Spiderii@ty ����Ч��.��busy.��no_exert.no_perform.�����޵��ˡ�
#include <ansi.h>
string exert_name() {return HIY"�����޳�"NOR;}
int check(object me);
int exert(object me)
{


   if( (int)me->query_skill("lengquan-shengong", 1) < 200 )
           return notify_fail("�����Ȫ����Ϊ��������\n");

   if( (int)me->query_skill("force", 1) < 200 )
           return notify_fail("��Ļ����ڹ���Ϊ��������\n");

   if( (int)me->query_skill("medicine", 1) < 120 )
		return notify_fail("��ı�������ȼ�������\n");

   if( (int)me->query("max_neili") < 2000 )
           return notify_fail("���������Ϊ��������\n");

   if( (int)me->query("max_jingli") < 1600 )
           return notify_fail("��ľ�����Ϊ��������\n");

   if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");

   if( (int)me->query("jingli") < 400 ) 
		return notify_fail("��ľ���������\n");

   if( me->query_temp("lqsg/yy") )
           return notify_fail("������������Ȫ��֮�������޳���������\n");


   message_vision(HIY"��Ȫ�񹦵��������ǳ���ֻ��$N��������һ��������Ȫ�ھ��㲼��ȫ���򹥡�����ȫ������У�\n"NOR, me);
   me->set_temp("lqsg/yy", 1);  
   me->add("neili", - 400);
	check(me);
   me->start_exert(random(3),"�������޳���");
//         me->start_busy(random(2));
	return 1;
}

int check(object me)
{
   if( !me || !me->query_temp("lqsg/yy") ) return 0;

	if( me->is_ghost() || !living(me) )
           me->delete_temp("lqsg/yy");

   if( me->query("jingli") < 400 
   || me->query("neili") < 600
	|| me->query("qi") < 1		// ���� BUG������-1�����ָ�
	|| !me->is_fighting()
   || (userp(me) && me->query_skill_mapped("force") != "lengquan-shengong") ) {
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 1);
	}
	else {
           if( me->query("qi") < (int)me->query("max_qi") && !me->is_busy() && !random(6)) {
                   message_vision(HIM"$Nһ��ü���߶���Ȫ��Ϊ�Լ����ˣ���һ�Ṧ��$N����ȥ�����������һ�㣡\n"NOR,me);
                   me->add("neili", -80 );
			me->add("eff_qi", me->query_skill("medicine", 1));
                   me->add("eff_qi", (int)me->query_skill("lengquan-shengong", 1)/8);
			if( me->query("eff_qi") > me->query("max_qi") )
				me->set("eff_qi", me->query("max_qi"));
                        me->add("qi", me->query_skill("lengquan-shengong")*3/2);
                        if( me->query("qi") > me->query("eff_qi") )
				me->set("qi", me->query("eff_qi") );
		}
           else if( me->query("jing") < (int)me->query("max_jing") && !me->is_busy() && !random(6) ) {
                   message_vision(HIC"$Nһ��ü�����߶���Ȫ�������Լ�����ƣ�ͣ���һ�Ṧ��$N����ȥ���ݹ������������ȣ�\n"NOR,me);
                   me->add("neili", -80 );
                   me->add("eff_jing", (int)me->query_skill("lengquan-shengong", 1)/8);
                   if( me->query("eff_jing") > me->query("max_jing") )
                          me->set("eff_jing", me->query("max_jing"));
           }


        if((int)me->query_skill("lengquan-shengong",1) > 300 && !random(6)){
           if( me->query_condition("no_perform") ){
               message_vision(HIR"$N�����Լ��ѱ����У��������߶���Ȫ�񹦣��������Լ��ж��ָ�������\n"NOR,me);
               me->remove_condition("no_perform");
           }
        if( me->is_busy() && !random(6) ){
               message_vision(HIW"$N�ж�һ���ƣ�����Ǳ����Ȫ�ھ�������ʹ�Լ������վ���\n"NOR,me);
               me->start_busy(-1);
           }

           if( me->query_condition("no_exert") && !random(6)){
               message_vision(HIY"$N�����Լ��ѱ���������æ������Ȫ�񹦣��������Լ������ָ�������Ѩ����\n"NOR,me);
               me->remove_condition("no_exert");
           }

           if( me->query_condition("no_force") && !random(6)){
               message_vision(HIC"$N�����Լ�����Ϣ���ȣ���æ�߶���Ȫ�񹦣�������Ϣ��\n"NOR,me);
               me->remove_condition("no_force");
           }
        }

           call_out("check", 1, me); 
	}
	return 1;
}       

void remove_effect(object me)
{
        if( !me || !me->query_temp("lqsg/yy") ) return;
        me->start_exert(0);
        me->delete_temp("lqsg/yy");
        message_vision(HIY"$N�������޳��������ñϣ������غ�����һ��������\n"NOR, me);
}

int help(object me)
{
        write(WHT"\n��Ȫ�񹦡�"HIY"�����޳�"WHT"����"NOR"\n\n");
        write(@HELP
   ��Ȫ���˵����ڹ�һ��,�ǳ����ܵ�Ҳ!�ˡ������޳�������
   ������Ȫ�������ɫ����ս���У������л��������Լ�����
   ���ˣ�Ҳ�л������ƾ������ˣ������������ȫ������Ȫ��
   ����һ�����������������ս���е�����Ϣ���������ĸ�
   �ֲ���æ��״̬��

   Ҫ��  ��ǰ���� 600 ���ϣ�
           ��ǰ���� 400 ���ϣ�
           ������� 2000 ���ϣ�
           ����� 1600 ���ϣ�
           ��Ȫ�񹦵ȼ� 200 ���ϣ�
           �����ڹ��ȼ� 200 ���ϣ�
           ��������ȼ� 120 ���ϣ�
HELP
        );
        return 1;
}
