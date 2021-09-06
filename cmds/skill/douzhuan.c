// douzhuan.c ��ת����
// by tiantian@sj

#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int main(object me, string arg)
{
	object target1,target2;
	string str1,str2;

	if (!me) return 1;

	if (me->query("family/family_name")!="����Ľ��")
		return notify_fail("�㲻��Ľ�ݵ��ӣ�����ʹ�ù���Ľ�ݵľ�����\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (!me->is_fighting())
		return notify_fail("��ת����ֻ����ս����ʹ��!��\n");

	if (me->query_skill_mapped("parry")!="douzhuan-xingyi")
		return notify_fail("������ö�ת�������мܣ�����ʹ�ó�Ľ�ݾ�����\n");

	if (!arg || sscanf(arg,"%s to %s",str1,str2)!=2)
		return notify_fail("ָ���ʽ��douzhuan <id1> to <id2>��\n");

	if (!present(str1,environment(me)))
		return notify_fail("����û��"+str1+"����ˡ�\n");

	if (!present(str2,environment(me)))
		return notify_fail("����û��"+str2+"����ˡ�\n");

	target1=present(str1,environment(me));
	target2=present(str2,environment(me));

	if (target1==target2)
		return notify_fail("��ֻ�ܰѹ���ת�Ƹ������ߡ�\n");

	if (!me->is_fighting(target1) )
		return notify_fail("�㲢û���ڸ�"+str1+"��ս��\n");

	if (!target2->is_character() || target2->is_corpse() )
		return notify_fail("�ǲ��Ǹ����\n");

	if (wiz_level(target2)>wiz_level(me))
		return notify_fail("�㲻����ͼ������ʦ�������ߵ���ҡ�\n");

	if (me->query_temp("bishen_target"))
		return notify_fail("������ʹ���Ա�֮����ʩ����\n");

	if (me->query_temp("douzhuan_target")||me->query_temp("douzhuan_source"))
		return notify_fail("������ʹ�ö�ת���ơ�\n");

	if (userp(target2) && !me->is_killing(target2))
		return notify_fail("���Ǹ��Է�������ޣ��㲻�ܰ�����ҡ�\n");

	if ( target2->query("job_npc") || target2->query("no_quest"))
		return notify_fail("���޷��ѹ���ת�Ƹ�"+target2->name(1)+"��\n");

	if (target2->query("family/family_name")=="����Ľ��" || target2->query_skill("douzhuan-xingyi",1))
		return notify_fail("���Լ���ҲҪ����̫�����˰ɡ�\n");

	if (me->query("max_neili") < 2000)
		return notify_fail("��������������ߣ�\n");

	if (me->query("neili") < 1000)
		return notify_fail("�㵱ǰ������������\n");

	if (me->query_skill("douzhuan-xingyi",1)<140)
		return notify_fail("��Ķ�ת���Ʋ���������������ʹ�ö�ת���ơ�\n");

	tell_object( me, HIG"��Ǳ�˹���Ľ�ݶ�ת���ƾ�������Ҫ��"+target1->query("name")
		+"�Ĺ���ת�Ƶ�"+target2->query("name")+HIG"���ϡ�\n\n"NOR );
	if (random(me->query("combat_exp")) > target1->query("combat_exp")*2/3
	|| random(me->query("combat_exp")) > target2->query("cobmat_exp")/3){
		me->set_temp("douzhuan_source",target1);
		me->set_temp("douzhuan_target",target2);
		me->start_busy(1);
	}
	else {
		tell_object( me, HIY"���ǶԷ��ƺ���û���ܵ����Ӱ�졣\n"NOR );
		me->start_busy(1+random(2));
	}

	me->start_perform(6,"��ת����");
	me->add("neili",-300);
	call_out("check_fight",1,me,target1,target2,me->query_skill("douzhuan-xingyi",1)/10);

	return 1;
}

int check_fight(object me,object target1,object target2,int i)
{
	if(!me)
		return 0;
	if(!target1
		|| !target2
		|| !me->is_fighting()
		|| environment(me)!=environment(target1)
		|| environment(me)!=environment(target2)
		|| i==0
		|| me->query_skill_mapped("parry")!="douzhuan-xingyi"
	)
	{
		tell_object(me,HIG"�㻺���չ������������뵤�\n"NOR );
		me->delete_temp("douzhuan_source");
		me->delete_temp("douzhuan_target");
		return 0;
	}

//	me->start_perform(1,"��ת����");
	call_out("check_fight",1,me,target1,target2,i-1 );
	return 1;

}
