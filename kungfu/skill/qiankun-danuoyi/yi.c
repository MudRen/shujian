// yi.c Ǭ����Ų�ơ��ơ��־�
#include <ansi.h>
inherit F_SSERVER;
string perform_name(){ return HIB"���־�"NOR; }

int perform(object me, string target)
{
	object ob;

	if(!target)
		return notify_fail("����ѶԷ��ľ���Ų����˭��\n");

	if(!objectp(ob = present(target, environment(me))))
		return notify_fail("����û������Ų�Ƶ�Ŀ������ˡ�\n");

	if(!me->is_fighting())
		return notify_fail("��û�ڴ�ܣ���ʲô�ƣ�\n");

        if(!ob->is_character()) 
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if(!living(ob))
		return notify_fail(ob->name()+"�Ѿ��޷�ս���ˡ�\n"); 

	if(ob==me) return notify_fail("�㲻�ܹ����Լ���\n");               
	
	if(userp(ob) && !me->is_killing(ob))
		return notify_fail("���Ǹ��Է�������ޣ��㲻���ݺ���ҡ�\n");

	if(me->is_fighting(ob))
		return notify_fail("�������������ء�\n");

	if(me->query_skill("qiankun-danuoyi", 1) < 120 )
		return notify_fail("���Ǭ����Ų�ƻ�������죬����ʹ�á��ơ��־���\n");

	if (!me->query_skill("jiuyang-shengong", 1))
	if( me->query_skill("shenghuo-shengong", 1) < 120 )
		return notify_fail("���ʥ���񹦵ȼ�������\n");

	if(me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("��û��ʹ��Ǭ����Ų����Ϊ�н����޷�ʹ�á��ơ��־���\n"); 
	
	if((int)me->query("neili") < 800 )
		return notify_fail("�������������\n");
	
	if((int)me->query_skill("force") < 200 )
		return notify_fail("���ơ��־���Ҫ�����ڹ�����������������󻹲�����\n");

	me->add("neili", -50);
	tell_object(me, BLU"�㰵��Ǭ����Ų�ơ��ơ��־�����ͼҪ�ѶԷ���һ�е�����ת�Ƶ�"+ob->name()+"���ϣ�\n"NOR); 
	me->start_perform(2, "���־�");
	me->set_temp("qkdny/yi", ob);
	return 1;
}

int help(object me)
{
        write(HIB"\nǬ����Ų�ơ����־�����"NOR"\n");
        write(@HELP
        Ҫ��  ��ǰ���� 800 ���ϣ�
                Ǭ����Ų�Ƶȼ� 120 ���ϣ�
                ��Ч�ڹ� 200 ���ϣ�
                �����м�ΪǬ����Ų�ơ�
HELP
        );
        return 1;
}
