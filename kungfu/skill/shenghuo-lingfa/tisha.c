// tisha.c ��ɳ
// Update By lsxk@hsbbs 2007/6/11 

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int j, f, flag;


	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target))
		return notify_fail("��ʥ���ѧ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if(me->query_skill("shenghuo-lingfa", 1) < 200 )
		return notify_fail("���ʥ�������̫ǳ������ʹ�á�\n");

   if(!me->query_skill("jiuyang-shengong", 1)||(int)me->query_skill("jiuyang-shengong",1)<200)
   if(me->query_skill("shenghuo-shengong", 1) < 200 )
           return notify_fail("��������ڹ�����̫ǳ������ʹ�á�\n");

   if(me->query_skill("dagger", 1) < 200 )
		return notify_fail("��Ļ���ذ������̫ǳ������ʹ�á�\n");

   if(me->query_skill("cuff", 1) < 200)
		return notify_fail("��Ļ���ȭ������̫ǳ������ʹ�á�\n");

   if(me->query_skill("qiankun-danuoyi", 1) < 200 )
		return notify_fail("���Ǭ����Ų�ƹ���̫ǳ������ʹ�á�\n");

   if(me->query("max_neili") < 3000 )
		return notify_fail("�������̫ǳ������ʹ�á�\n");

	if(me->query("neili") < 1000 )
		return notify_fail("�����������������ʹ�á�\n");

	if(me->query("jingli") < 1000)
		return notify_fail("��ľ�������������ʹ�á�\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if( me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

        if( me->query_skill_mapped("parry") != "shenghuo-lingfa" 
        && me->query_skill_mapped("parry") != "qiankun-danuoyi" )
                return notify_fail("����Ҫ�����м�Ϊʥ���������ʹ�ô˾�����\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "dagger"
	 || me->query_skill_prepared("cuff") != "shenghuo-lingfa"
	 || me->query_skill_mapped("dagger") != "shenghuo-lingfa"
    || me->query_skill_mapped("cuff") != "shenghuo-lingfa" 
    || (me->query_skill_mapped("force") != "shenghuo-shengong" && me->query_skill_mapped("force") != "jiuyang-shengong") )
		return notify_fail("�㲻��ʹ��������У�\n");

   if((int)me->query_temp("ling")
     && me->query_skill_prepared("force") != "jiuyang-shengong"
     && (int)me->query_skill("jiuyang-shengong",1)<200)
		return notify_fail("������ʹ�á���ħ���У���Ͼʹ�á���ɳ��������\n");

   if ( !me->query_skill("jiuyang-shengong", 1)||(!userp(me) && userp(target)))
		flag = 3;
	else
		flag = 4;


   f = ((int)me->query_skill("shenghuo-lingfa", 1) + (int)me->query_skill("jiuyang-shengong", 1))/2;
   j = f / (7-flag);
 
	message_vision(HIY"\n$NͻȻ���ȼ�ɨ��������´�Ƭɳʯ������һ��Ϊ����ǰ��л�������"+chinese_number(flag)+"�У�\n" NOR, me);

	me->set_temp("tisha", 4);
if( !userp(target) && me->query_skill("shenghuo-lingfa",1)<=251  ) target->add_busy(2);
if( !userp(target) && me->query_skill("qiankun-danuoyi",1)>=451  ) { target->add_busy(2);
                                                                      j=j*5/4;}

   if(userp(me))
   me->add_temp("apply/damage", j);
   me->add_temp("apply/attack", j);

	       weapon->unequip();
	       me->set_temp("type", 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	       me->delete_temp("type", 1);

	       weapon->wield();
 if (present(target,environment(me)) && me->is_fighting(target))
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	       weapon->unequip();
	       me->set_temp("type", 1);
 if (present(target,environment(me)) && me->is_fighting(target))
               COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	       weapon->wield();
	       me->delete_temp("type");

 if (present(target,environment(me)) && me->is_fighting(target) && flag >=4 )
	       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   if(userp(me))
   me->add_temp("apply/damage", -j);
   me->add_temp("apply/attack", -j);
   me->delete_temp("tisha");
 
if (present(target,environment(me)) && me->is_fighting(target) )
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   me->add("neili", -600);
   me->add("jingli", -300);
   me->start_perform(3+random(2), "��ɳ");
   me->start_busy(random(2));
	return 1;
}

string perform_name(){ return YEL"��ɳ"NOR; }

int help(object me)
{
	write(YEL"\nʥ���֮����ɳ����"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 1000 ���ϣ�
           ������� 3000 ���ϣ�
		��ǰ���� 1000 ���ϣ�
           ʥ����ȼ� 200 ���ϣ�
           Ǭ����Ų�Ƶȼ� 200 ���ϣ�
           ʥ���񹦵ȼ� 200 ���� ���� ���̾������ȼ� 200 ���ϣ�
           ������ȼ� 200 ���ϣ�
           ����ȭ���ȼ� 200 ���ϣ�
		�����Ϊʥ�����
		����ȭ��Ϊʥ�����
		�����м�Ϊʥ�����
		��ȭ��Ϊʥ�����
		���ֱֳ�����

HELP
        );
        return 1;
}
