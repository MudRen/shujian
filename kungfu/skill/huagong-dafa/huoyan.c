// huoyan.c ����
// By Spiderii xx��������
#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me)
{      
       object fire, ob;
       int skill;
       skill = me->query_skill("huagong-dafa");

	if( (int)me->query_skill("huagong-dafa", 1) < 100 )
		return notify_fail("��Ļ�������Ϊ�������޷��������棡\n");

	if (me->query_skill_mapped("force") != "huagong-dafa")
		return notify_fail("�����ڹ������Ч����\n");

       if(!objectp(fire = present("fire", me)))
               	return notify_fail("�㹦�����Ҳ����ƾ�յ��ɣ�\n");

       if( (int)me->query_skill("poison", 1) < 100 )
		return notify_fail("�����ڵĶ��ز������޷�ʹ�á���������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á���������\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ��ô�����ʹ�á���������\n");
       
       if(present("huo yan", environment(me)))
             	return notify_fail("�����Ѿ��л����ˣ���Ҫ��ʲô��\n");

	message_vision(HIR"$N�����³�һ�����̣��������������л���֮�ϣ�һ��һ�ף����һ��ȼ��һ�����ܻ��档\n" NOR, me);
	
       ob = unew("/d/xingxiu/obj/huoyan")->move(environment(me)); 
	return 1;
}
string exert_name(){ return HIR"��������"NOR; }
int help(object me)
{
        write(BLU"\n�����󷨡��������桹��"NOR"\n");
        write(@HELP
        �����ɵĹ�����Ҫ����<��>�����¹������������������ζ
        ���������������������쳣���������������޲�̸��ɫ�䡣
        ���������һʽ����ƾ����������������������л���֮�ϣ�ƾ
        �ռȿɾ������棬���в�����

        Ҫ��:   ������ 100 ����
                ����     100 ����
                ��ǰ���� 500 �㣻
                ������� 1000 �㣻
                �����л��ۡ�
        
HELP
        );
        return 1;
}

