// duoming.c ��ҽ���֮����������������
// Write By lsxk@hsbbs 5/10/2007

#include <ansi.h>

inherit F_SSERVER;
string perform_name() {return HIY"����������"NOR;}
int perform(object me,object target)
{
	object weapon;
   int i=me->query_skill("miaojia-jianfa",1);
   int d=me->query_skill("force",1);
   int count;

	if( !target ) target = offensive_target(me);

        if( !objectp(target)|| !me->is_fighting(target) || !living(target)
	|| environment(target)!=environment(me))
           return notify_fail("�ˡ�������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if( (int)me->query_skill("miaojia-jianfa", 1) < 250 )
           return notify_fail("��Ľ�����δ���ɣ�����ʹ�á���������������\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword"
   || me->query_skill_mapped("sword") != "miaojia-jianfa")
           return notify_fail("������û�н����޷�ʹ�á���������������\n");

/*
   if(me->query_skill_mapped("parry") != "miaojia-jianfa")
           return notify_fail("����мܹ��򲻶ԣ��޷�ʹ�á���������������\n");
*/
   if((int)me->query("max_neili") < 3000 )
           return notify_fail("���������Ϊ����������ʹ�á���������������\n");
	if((int)me->query("neili") < 800 )
           return notify_fail("�������������㣬����ʹ�á���������������\n");
	if((int)me->query("jingli") < 500 )
           return notify_fail("�����ھ������㣬����ʹ�á���������������\n");
    if((int)me->query_temp("mjjf/lianhuan"))
           return notify_fail("������ʹ�á���������������\n");
   if((int)me->query_skill("sword", 1) < 250 )
           return notify_fail("��Ļ�������������죬�޷�ʹ�á���������������\n");

message_vision(HIY"\n$N"HIY"ʹ����ҽ���֮��"HIW"����������"HIY"��������$P����"+weapon->name()+HIY"һ���裬��������$n����"HIY"��\n"NOR, me,target);
   if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
    && me->query_temp("lqsg/lq")
    && me->query_skill_mapped("force") == "lengquan-shengong" ){
        me->set_temp("mjjf/lianhuan/lq",1);
        message_vision(HIW"$N������Ȫ���ھ��������е�"+weapon->name()+HIW"�ϣ���ʱ���ܵ����������˵Ľ�����\n"NOR, me,target);
     }

   me->set_temp("mjjf/lianhuan/color", 1);
   me->receive_damage("neili", 500);
   me->receive_damage("jingli", 500);
   me->add_temp("apply/attack", i/2);
   me->add_temp("apply/damage", d/5);
   me->add_temp("apply/dodge",i/2);

   for (count=0;count<(random(3)+1);count++)
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   me->add_temp("apply/damage", -d/5);
   me->delete_temp("mjjf/lianhuan/color");
   me->start_perform(4, "��������������");
   call_out("check_fight", 1, me, i, d);
	return 1;
}

void remove_effect2(object me, int i)
{
   if (me) me->add_temp("apply/dodge",-i/2);
}

void remove_effect(object me, int i, int d)
{
	if(!me) return;

   me->add_temp("apply/attack", -i/2);
	if (living(me))
           message_vision(HIG"\n$N"HIG"һ�ס�"HIW"����������"HIG"��ʹ�꣬���ص���������ڻָ�������\n"NOR, me);
   if (me->query_temp("mjjf/lianhuan/lq")){
           message_vision(HIW"$N��"HIB"��Ȫ"HIW"������ʹ�꣬����Ũ��Ľ���������ʧ�ˡ�\n"NOR, me);
           me->delete_temp("mjjf/lianhuan/lq");
   }
   me->delete_temp("mjjf/lianhuan");
   me->start_perform(2, "��������������");
	d = 1 + random(2);
	me->add_busy(d);
	call_out("remove_effect2", d+d, me, i);
}

void check_fight(object me, int j, int d)
{
	object weapon, target;
   int count;

	if (!me ) return;

	target = offensive_target(me);

   if(!living(me)
	|| !target
	|| !me->is_fighting(target)
	|| environment(target)!=environment(me)
   || !me->query_temp("mjjf/lianhuan")
	|| me->query("neili") < 200
	|| me->query("jingli") < 200)
		return remove_effect(me, j, d);

   if(me->query_skill_mapped("sword") != "miaojia-jianfa") {
           tell_object(me, HIR"����ʱ�Ļ���������������ʹ�á�������������������\n");
		remove_effect(me, j, d);
/*
   } else if(me->query_skill_mapped("parry") != "miaojia-jianfa"){
           tell_object(me, HIR"����ʱ�Ļ��мܣ���������ʹ�á�������������������\n");
		remove_effect(me, j, d);
*/
	} else if(!objectp(weapon = me->query_temp("weapon"))
		|| weapon->query("skill_type") != "sword"){
           tell_object(me, HIR"����ʱ�Ļ���������������ʹ�á�������������������\n");
		remove_effect(me, j, d);
	} else if (me->is_busy())
           call_out("check_fight", 1, me, j, d);
	else {
		me->receive_damage("neili", 50);
		me->receive_damage("jingli", 50);
           if (objectp(target) && me->is_fighting(target)){
                   me->set_temp("mjjf/lianhuan/color", 1);
                   me->add_temp("apply/damage", d/5);
                   for (count=0;count<(random(3)+1);count++)
                   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                   me->add_temp("apply/damage", -d/5);
                   me->delete_temp("mjjf/lianhuan/color");
           }
           call_out("check_fight", 1, me, j, d);
	}
}


int help(object me)
{
   write(WHT"\n��ҽ�����"HIW"����������"WHT"����"NOR"\n");
   write(@HELP
   ���С�����������������ҽ���֮���裬ʹ�ú�����ս����
   �Ӷ������������ʩ�Թ�������������ַ���ʤ����������ʹ
   ���߻����־�ѧ��Ȫ��֮����Ȫ�����������ศ��ɣ�Ч��
   ��Ȼ��

   Ҫ��  ���� 800 ���ϣ�
           ���� 500 ���ϣ� 
           ������� 3000 ���ϣ� 
           ��ҽ��� 250 ���ϣ�
           �������� 250 ���ϣ�

HELP
   );
   return 1;
}
