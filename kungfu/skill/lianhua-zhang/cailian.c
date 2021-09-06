// cailian.c ��������
// creat by Caiji@SJ
// Modified by Lklv 2001.10.21
// Modified by Lane@SJ 2005.7.19

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIM"����"NOR; }

string *color = ({ RED+"",GRN+"",YEL+"",BLU+"",MAG+"",CYN+"",
HIR+"",HIG+"",HIY+"",HIB+"",HIM+"",});

int perform(object me, object target)
{
	int tbusy, i, j;
	string msg;
	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 ||!target->is_character()
	 ||!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ֻ�ܿ���ʹ�á�\n");

	if( me->query_skill_prepared("strike") != "lianhua-zhang"
	 || me->query_skill_mapped("strike") != "lianhua-zhang"
	 || me->query_skill_mapped("parry") != "lianhua-zhang" )
		return notify_fail("������������Ʋ��ܳ����湦�� \n");

	if( me->query_skill("huntian-qigong",1) < 100 )
		return notify_fail("��Ļ�������������������ʹ�á�������!\n");

	if( me->query_skill("lianhua-zhang",1) < 100 )
		return notify_fail("�����������Ϊ������������ʹ��������������!\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query("max_neili") < 800 )
		return notify_fail("���������Ϊ��Ƿ���\n");

	if( me->query("neili") < 500 )
		return notify_fail("��������������, ����ʹ�á�������! \n");

	if( me->query("jingli") < 500 )
		return notify_fail("�����ھ�������, ����ʹ�á�������! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	if( me->query_temp("lhz/cailian") )
		return notify_fail("��������Ѫ��ӿ�����ڻ�����ʹ�á���������! \n");

	msg = HIM "\n����$N���º���һ��������һ�ǡ�ǧҶ����������ǰ��������$n��ǰ����������㱬��������\n"+
		"ɲ�Ǽ��â���䣬���糵�֣�����һ��ʢ���Ĳ�ɫ���������������⣬�յ����������۾���\n"NOR;

	me->start_perform(3, "����");
	me->set_temp("lhz/cailian",1);
	tbusy = (int)me->query_skill("lianhua-zhang",1) / 50 - random(3);
	if( tbusy < 3 ) tbusy = 3;
	if( tbusy > 5 ) tbusy = 5+random(2);

	i = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK) + me->query("combat_exp");
	j = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) + target->query("combat_exp");

	if( random(i + j) > j ) {
		if( tbusy > 3 ) msg += BLINK+"";
		target->start_busy(tbusy);
		if( !userp(target) ) target->add_busy(random(2));
		msg+=color[tbusy]+
		"              /\\/\\/\\/\\/\\/\\ \n"+
		"            </\\/\\/\\/\\/\\/\\/\\>\n"+
		"           </\\/\\/\\/\\/\\/\\/\\/\\>\n"+
		"           \\_<>_\\_\\<>/_/_<>_/\n"+
		"           / <> / /<>\\ \\ <> \\ \n"+NOR;
		msg += HIY"���$n��$N�Ĳ�ɫ������ס��˲���ʧȥ�˹���������! \n" NOR;
		me->add("neili",-200);
		me->add("jingli",-50);
		me->start_perform(tbusy-random(2), "����");
		message_vision(msg, me, target);
	}
	else {
		msg += HIM"$n�䱻�⾫���һ���������������������ʽ�·�ȴ˿�����ң���Ҳ��ǿ����������\n" NOR;
		if( me->is_fighting(target) && random(i) > j/2 ) {
			msg+=HIG"ֻ�Ǳ������Ʒ����ˣ�$N����һ����������ǰ�ƽ�������������˫�ơ�����\n" NOR;
			message_vision(msg, me, target);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?0:1);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
			me->start_busy(random(2));
			me->start_perform(3, "����");
		}
		else if( me->is_fighting(target) && random(i) > random(j)/2 ) {
			msg+=HIB"ֻ�Ǳ������Ʒ�ɨ�������̣�$n���Լ��ϰ����ػ�Ҳ������и��\n" NOR;
			message_vision(msg, me, target);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?0:1);
			me->start_busy(random(2));
			me->start_perform(2+random(2), "����");
		}
		else message_vision(msg, me, target);
		me->add("neili",-200);
		me->add("jingli",-50);
	}
	me->delete_temp("lhz/cailian");
	return 1;
}

int help(object me)
{
        write(HIM"\n�����ơ���������"NOR"\n");
        write(@HELP
        ����Ϊ�����ƾ���֮һ�������ﵽ�߿�������������������״���Ʒ档
        �����������Ʒ����Ի󣬹��ز������硣
        Ҫ��  ������� 800 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                �����Ƶȼ� 100 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                �����м�Ϊ�����ơ�
HELP
        );
        return 1;
}
