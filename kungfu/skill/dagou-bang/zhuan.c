// zhuan.c �򹷰���--ת�־�
// Creat by looklove@SJ 2001.4.10
// Modify by looklove 2001.5.2
// Modify by looklove 2001.5.4 ����ڿ�����
// Looklove modified at 2001.5.15

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HBYEL"ת�־�"NOR; }

string *zhuan_msg = ({
HIM"$n�޷���ʩ��ֻ����ǰ���ݣ�ȴ�Ǳܿ�һ������һ��������������\n"NOR,
HIY"�ۿ�$n�޷���ʩ��ֻ����ǰ���ݣ�ȴ�Ǳܿ�ǰ�������������\n"NOR,
HIC"����$n���¼Ӿ��������û�ת����$n��Ծ���죬$W"HIC"������������\n"NOR,
HIG"$n����$N�ɱ���Ծ����תȦ�ӡ�$N����$W"HIG"ȴһֱ��$n���Ļζ���\n"NOR,
HIB"$N��ɫ�����ؿ���$n�ɱ���Ծ����תȦ�ӡ�$Nվ�����ģ��ٰ�����$n���ġ�\n"NOR,
HIR"$n����$N�ϴ�������$N��ɫ������$W"HIR"ʼ�ղ���$n���ġ�\n"NOR,
HIW"$N��$W"HIW"�����ֽ������֣��������ֽ������֣�ʼ�ղ���$n���Ĵ�Ѩ��\n"NOR,
RED"$N����$W"RED"����ԲȦ��ֱ��$n���Ĵ�Ѩ��$nֻ�ü�����ǰ��Ծ��\n"NOR,
YEL"$n���а����п࣬ȴ�޼ƿ�ʩ������һ��Ҳ����ͣ�١�\n"NOR,
WHT"ֻ��$n�ܵ�Ȧ��ԽתԽ��$N���е�$W"WHT"ȴһֱ��$n���Ĵ�ת��\n"NOR,
BLU"$nȦ��ԽתԽ�󣬺����б���$N���е�$W"BLU"���ɲ�����$n�����к���\n"NOR,
MAG"$nһ����Ȼ����ͷ�󺹣����¿�˿������ͣ����һֱ����Ȧ�Ӷ�ܡ�\n"NOR,
CYN"һʱ��$n��ɫ��䣬��ͷ�󺹣�$W"CYN"���ϵ�����ʹ��$nӦ�Ӳ�Ͼ��\n"NOR,
});

int check_fight(object me);
int halt_fight(object me);

int perform(object me, object target)
{
	string msg;
	object tweapon, weapon;
	int lost, mexp, texp, mlvl, tlvl, x, y, b, n;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target))
		return notify_fail("��ת�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
	if( !weapon
	 || weapon->query("skill_type") != "stick"
	 || me->query_skill_mapped("stick") != "dagou-bang" 
	 || me->query_skill_mapped("parry") != "dagou-bang" )
		return notify_fail("�������޷�ʹ�á�ת�־�����\n");

	if( me->query_temp("dgb/zhuan") )
		return notify_fail("������ʹ�á�ת�־�����\n");

	if( me->query_temp("dgb/chan") )
		return notify_fail("������ʹ�á����־�����\n");

	if( target->is_busy() || target->query_temp("dgb/chan") )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	mexp=me->query("combat_exp");
	texp=target->query("combat_exp");

	mlvl = (int)me->query_skill("dagou-bang",1);
	tlvl = (int)target->query_skill("dodge", 1);

	x = me->query_int(1);
	y = target->query_int(1);
	b = me->query_skill("bangjue",1);

	tweapon = target->query_temp("weapon");

	if( mlvl < 180 )
		return notify_fail("��Ĵ򹷰�����������죬����ʹ�á�ת�־�����\n");
	if( b < 180 )
		return notify_fail("��Ĵ򹷰���������죬�޷�ʹ����ת�־�����\n");
	if( me->query_skill("huntian-qigong",1) < 180 )
		return notify_fail("��Ļ��������������㣬�޷�ʹ����ת�־�����\n");
	if( me->query("neili") < 800 )
		return notify_fail("������������ˡ�\n");
	if( me->query("jingli") <  800 )
		return notify_fail("��ľ���������֧����ʹ����ת�־�����\n");
	if( me->query("max_neili") < 2000 )
		return notify_fail("�����������֧����ʹ�á�ת�־�����\n");

	lost = b /50 + random(b/50)+x/5+mlvl/50;
	if( mlvl > tlvl ) lost += (mlvl-tlvl)/5;
	if( mlvl > 350 ) lost += (mlvl-300)/10;
	n = lost*5;
	if(lost > 15) lost = 15 + random(lost-15)/5;

	if( wizardp(me) )
        	write(sprintf(HIR"lost=%d n = %d\n"NOR,lost, n));

	x = mexp/1000 * (mlvl + x);
	y = texp/1000 * (tlvl + y);
	x += COMBAT_D->skill_power(me, "stick", SKILL_USAGE_ATTACK);
	y += COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);

	msg = HBYEL"$Nʹ���򹷰�����ת�־�����ֻ��"+weapon->name()+HBYEL"������һ�ű�Ӱ��\n"NOR;
	msg += HBYEL"�͵�$n���ġ�ǿ�䡹�����縮��������׵��������̨���������ࡹ����ҪѨ��\n"NOR;

	if(random(x+y) > y) {
		msg += HIM "$N�ĵ�����಻�ϣ�һ�㲻�У��ֵ�һѨ����Ӱֻ��$n�����Ѩ�ϻ�����ȥ��\n" NOR;
		me->set_temp("dgb/zhuan", lost);
		me->set_temp("dgb/zhuan_n", n);
		me->set_temp("dgb/zhuan_target",target);
		target->start_busy(2);
		me->add("neili", -600);
		if(wizardp(me))	write("starting busy2 now\n");
		me->start_busy((:check_fight:),(:halt_fight:));
	}
	else {
		msg += HIW "$n����һ������æ��"+weapon->name()+HIW"��һ������ס��$N�Ĺ��ơ�\n" NOR;
		me->start_busy(random(2));
		me->add("neili", -200);
	}
	me->start_perform(2, "ת�־�");
	message_vision(msg, me, target);
	return 1;
}


int remove_effect(object me)
{
        if(!me) return 0;

        me->delete_temp("dgb/zhuan");
        me->delete_temp("dgb/zhuan_n");
        me->delete_temp("dgb/zhuan_target");
        if(!living(me)) return 0;
        me->start_perform(2, "ת�־�");
        me->start_busy(random(2));
        return 0;
}

int check_fight(object me)
{
	object wp,target;
	string msg;
	int n, lost;
	n = me->query_temp("dgb/zhuan_n");
	lost = me->add_temp("dgb/zhuan",-1);
	if(wizardp(me))
		tell_object(me,sprintf("lost = %d  n = %d \n",lost,n ));
	if(!objectp(target = me->query_temp("dgb/zhuan_target")))
		lost = 0;
	message("wizard", "ת�־�ս����Ϣ���������� "+lost+", �غ���"+n+"��\n", environment(me), me);
	if(!objectp(wp = me->query_temp("weapon"))){
		msg = HIG"$N����������ʧ��ת�־�Ҳ��֮ͣ��������\n"NOR;
		me->delete_temp("dgb/zhuan");
		target->start_busy(1);
		message_vision(msg, me, target);
		message_vision(HBYEL"\n$N�ġ�ת�־���������ϣ����ص�������չ���\n"NOR, me);
		return remove_effect(me);
	}
	if(lost){
		if(!living(target))
			msg = HIW"$N��м�ؿ���$nһ�ۣ���ɫ�����ؽ�"+wp->name()+HIW"���˻�����\n"NOR;
		else if(!me->is_fighting(target) || !living(me))
			msg = HBYEL"$N������"+wp->name()+HBYEL"һ�գ��Ų�ͣ��������\n"NOR;
		else if( me->query_skill_mapped("stick") != "dagou-bang")
			msg = HBYEL"$N����һ�䣬ʹ����һ·��������\n"NOR;
		else if( me->query("jingli") <= 300 )
			msg = HBYEL"$N���н�����ԭ���Ǿ��������ˡ�\n"NOR;
		else if( random((int)me->query_int()) < target->query_int()/3 && lost<5)
			msg = HIW"$n�������𣬻�����"+wp->name()+HIW"��һ����$Nʼ�ϲ�������æ���С�\n"NOR;
		else if( target->is_ghost())
			msg = HBYEL"$N��"+wp->name()+HBYEL"���һ�ڣ��ջ�����ʽ��\n"NOR;
		if(stringp(msg)){
			message_vision(msg, me,target);
			return remove_effect(me);
		}
		msg = zhuan_msg[random(sizeof(zhuan_msg))];
		msg = replace_string(msg, "$W", wp->name());
		msg += "\n"NOR;
		if((int)target->query("jingli")< 0) target->set("jingli",-1);
		me->start_perform(1, "ת�־�");
		me->receive_damage("jingli",n/3,"�����ľ�");
		target->receive_damage("jingli", n, me);
		target->add_busy(1);
		message_vision(msg, me, target);
		return 1;
	}
	msg = HBBLU"$N��"+wp->name()+HBBLU"������б�Ϸ�һ������Ӱ�����ˡ�\n"NOR;
	message_vision(msg, me);
	return remove_effect(me);
}

int halt_fight(object me)
{
	if(!objectp(me))
		return 1;
        message_vision(HBYEL"\n$N�ġ�ת�־���������ϣ����ص�������չ���\n"NOR, me);
	if(!remove_effect(me))
		return 1;
}
int help(object me)
{
	write(HBYEL"\n�򹷰���ת�־�����"NOR"\n");
	write(@HELP
        ��ת�־������򹷰����ᡱ���顱���桱���ɡ����ص㷢�ӵ���
        �쾡�£���ר�����ֵĺ��ļ���ҪѨΪ����һ��ʩչ����������
        ��ʹ���ֲ�ͣ�������Ȱ���ת�������ܵ�򡣽�������Ӱ�Խ����
        ������ʹ�����п�ȴҲ�޼ƿ�ʩ�������ľ�������������ȥ��

	Ҫ��	������� 2000 ���ϣ�
		��ǰ���� 800 ���ϣ�
		��ǰ���� 800 ���ϣ�
		�򹷰��ȼ� 180 ���ϣ�
		���������ȼ� 180 ���ϣ�
		�򹷰����ȼ� 180 ���ϣ�
		�����м�Ϊ�򹷰���
HELP
	);
	return 1;
}
