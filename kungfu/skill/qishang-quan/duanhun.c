// �ϻ����
// by Looklove@SJ
// Update By lsxk@hsbbs 2007/6/11

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
   int i, j, p, flag;
   i = (int)me->query_skill("qishang-quan", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target)!=environment(me))
		return notify_fail("���ϻ���ǡ�ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʹ�á��ϻ���ǡ���\n");

   if( (int)me->query_skill("qishang-quan", 1) < 250 )
		return notify_fail("�������ȭ��������죬ʹ�������ϻ���ǡ�������\n");

   if(!me->query_skill("jiuyang-shengong", 1) || (int)me->query_skill("jiuyang-shengong",1)<250)
   if( (int)me->query_skill("shenghuo-shengong", 1) < 250 )
           return notify_fail("���ʥ����ȼ���������ʹ�������ϻ���ǡ�������\n");

   if( (int)me->query_skill("force",1) < 250 )
		return notify_fail("����ڹ��ȼ�����������ʹ�á��ϻ���ǡ���\n");

   if( me->query_str(1) < 45 )
		return notify_fail("�������������ǿ����ʹ�������ϻ���ǡ�����\n");

	if( me->query_skill_prepared("cuff") != "qishang-quan"
	 || me->query_skill_mapped("cuff") != "qishang-quan")
		return notify_fail("�������޷�ʹ�á��ϻ���ǡ���\n");

   if( me->query_skill_mapped("force") != "jiuyang-shengong"
    && me->query_skill_mapped("force") != "shenghuo-shengong")
           return notify_fail("��������ڹ����ԣ��޷�ʹ�á��ϻ���ǡ���\n");

	if( me->query_skill_mapped("parry") != "qishang-quan"
	&& me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("����Ҫ�����м�Ϊ����ȭ������ʹ�á��ϻ���ǡ���\n");

   if (target->query_temp("qishang") && (int)me->query_skill("qishang-quan",1)<350)
		return notify_fail("�Է��Ѿ���������ȭ�����ˡ�\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if ( me->query_temp("qsq/duanhun"))
		return notify_fail("������ʹ�á��ϻ���ǡ���\n");

   if( (int)me->query("max_neili") < 4000)
		return notify_fail("�������̫����ʹ�������ϻ���ǡ���\n");

   if( (int)me->query("neili") < 1500 )
		return notify_fail("����������̫����ʹ�������ϻ���ǡ���\n");

   if( (int)me->query("jingli") < 2000 )
           return notify_fail("������̫���ˣ�ʹ�������ϻ���ǡ���\n");

	message_vision(HIR"\n$N�����������˶ϻ���Ǹ����������ȭ�ⷢ�ӵ����쾡�£����һ��ȫ���������\n"NOR,me);

   if( me->query_skill_mapped("force") == "jiuyang-shengong" && userp(me))
       flag=1;
   else flag = 0;

	p = me->query_skill("qishang-quan", 1) / 50;
	if ( p > 5 ) p = 5;

	if (!me->query_skill("jiuyang-shengong", 1))
		if ( p > 4 ) p = 4;

   i = i/5*3 + (int)me->query_skill("jiuyang-shengong", 1)/5*2;   

   j = i/(7-p);                //��9yang��1/2,������1/3

	if ( i > 300 && p>4 )
		j = to_int( i/3.0 * i/ 300.0);  // 9yang 300��С��

if(random(2)&&userp(me)) target->start_busy(2);

   me->add_temp("apply/cuff", j);
   me->add_temp("apply/attack", j );
   me->add_temp("apply/parry", j);
	
   if( userp(me) ) {
   me->add_temp("apply/strength",j/5);
   me->add_temp("apply/damage", j);

   }

if(me->query_skill("jiuyang-shengong",1)>300)

	me->set_temp("qsq/duanhun",p);

   COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
           COMBAT_D->do_attack(me, target, 0, (flag==1)?3:1);

	if ( me->is_fighting(target) && p > 3)
           COMBAT_D->do_attack(me, target, 0, (flag==1)?3:1);

	if ( me->is_fighting(target) && p > 4)
           COMBAT_D->do_attack(me, target, 0, (flag==1)?3:1);

   me->add_temp("apply/cuff", -j);
   me->add_temp("apply/attack",-j );
   me->add_temp("apply/parry", -j);
	
   if( userp(me) ) {
   me->add_temp("apply/strength",-j/5);
   me->add_temp("apply/damage",-j);
     }
	me->delete_temp("qsq/duanhun");
   me->add("jingli", -100*p);
   me->add("neili", -200*p);
   me->start_busy(random(2));
   me->start_perform(4+ random(1),"���ϻ���ǡ�");
	return 1;
}

string perform_name(){ return HIR"�ϻ����"NOR; }

int help(object me)
{
	write(HIR"\n����ȭ֮���ϻ���ǡ���"NOR"\n\n");
	write(@HELP
           ������� 4000 ���ϣ�
           ������� 3000 ���ϣ�
           ��ǰ���� 2000 ���ϣ�
           ����ȭ�ȼ� 250 ���ϣ�
           ʥ���񹦵ȼ� 250 ���� ���� ���̾������ȼ� 250 ���ϣ�
           �����ڹ��ȼ� 250 ���ϣ�
           �������� 45 ���ϣ�
		����ȭ��Ϊ����ȭ��
		�����м�Ϊ����ȭ��Ǭ����Ų�ƣ�
		��ȭ��Ϊ����ȭ�ҿ��֡�

HELP
	);
	return 1;
}
