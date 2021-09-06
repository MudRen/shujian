// xinghe Modify By River@SJ 2001.12.13
inherit F_SSERVER;
#include <ansi.h>
#include <combat.h>

mapping valid_types = 
([
	"finger":	"ָ��",
	"hand":		"�ַ�",
	"cuff":		"ȭ��",
	"claw":		"צ��",
	"strike":	"�Ʒ�",
	"leg":		"�ȷ�",
]);

int perform(object me, object target)
{
	string *skill, basic1, msg, sk;
	int i;
	mapping smap, pmap;

	if( !target ) target = offensive_target(me);

        if( !objectp(target)
	 ||  !target->is_character()
	 ||  !me->is_fighting(target) )
		return notify_fail("���Ǻ�ǧ���衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ( me->query_skill("bihai-chaosheng", 1) < 250 )
		return notify_fail("��ı̺��������������޷�ʹ���Ǻ�ǧ���衣\n");

	if ( me->query_skill("suibo-zhuliu", 1) < 250 )
		return notify_fail("����沨������Ϊδ�����޷�ʹ���Ǻ�ǧ���衣\n");

	if ( me->query_skill("tanzhi-shentong", 1) < 250 )
		return notify_fail("��ĵ�ָ��ͨ��Ϊδ�����޷�ʹ���Ǻ�ǧ���衣\n");

	if ( me->query_skill_mapped("parry") != "tanzhi-shentong"
	 || me->query_skill_mapped("finger") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong")
	 	return notify_fail("�������޷�ʹ���Ǻ�ǧ���衣\n");

	if ( me->query_temp("weapon"))
		return notify_fail("�������޷�ʹ���Ǻ�ǧ���衣\n");

	if ( me->query_skill("finger",1) < 250 )
		return notify_fail("���ָ����Ϊ���㣬ʹ�����Ǻ�ǧ���衣\n");

	if( me->query("max_neili") < 3500 )
		return notify_fail("������̫�������ܳ��Ǻ�ǧ���衣\n");

	if( me->query("neili") < 1200 )
		return notify_fail("������̫�������ܳ��Ǻ�ǧ���衣\n");

	if( me->query("jingli") < 1000 )
		return notify_fail("�㾫��̫�������ܳ��Ǻ�ǧ���衣\n");

	if ( me->query_temp("thd/xinghe"))
		return notify_fail("������ʹ���Ǻ�ǧ���衣\n");

	sk = me->query("env/xinghe");

	if (!sk || sk == "tanzhi-shentong") 
		return notify_fail("�����ѡ��һ����������ϣ�\n");

	if (me->query_skill(sk,1) < 250)
		return notify_fail("�����ϼ��ɻ�û���졣\n");

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();

	skill = keys(valid_types);
	for (i=0; i<sizeof(skill); i++) {
		if( smap[skill[i]] == sk ) basic1 = skill[i];
	}
	if ( !basic1 )
		return notify_fail("���ּ�����δ������Ŀǰ����׼����\n");

	skill = keys(pmap);
	for (i=0; i<sizeof(skill); i++) {
		me->prepare_skill(skill[i]);
	}

	me->prepare_skill(basic1, sk);
	me->reset_action();

	me->start_perform(3, "�Ǻ�ǧ����");
	msg = HIW"\n$N��Хһ�������μӿ죬ʩչ���һ��������Ǻ�ǧ���衱������һ�䣬��ʱ���ʩչ��ָ��ͨ��\n"NOR;
	me->add("neili",-400);
	me->add_temp("apply/attack", 50);
	me->add("jingli", - 200);
	me->set_temp("thd/xinghe",1);
	message_vision(msg, me, target);
	call_out("check", 2, me, target, me->query_skill("tanzhi-shentong",1)/15);
	return 1;
}

string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
"ӿȪѨ","��׶Ѩ","�縮Ѩ",
}); 

void check(object me, object target, int count)
{
	int p, lvl, i, x=0;
	int ap, dp;
	string msg, *skill, dodge_skill, name, *limbs;
	mapping pmap;

	if ( !me ) return;

	lvl = me->query_skill("finger",1) * 3;
	lvl += me->query("jiali");
	pmap = me->query_skill_prepare();

	if (count > 0 && target && me->is_fighting(target)) {

		if (!sizeof(pmap)) msg = "unarmed";
		else msg = keys(pmap)[0];

		ap = COMBAT_D->skill_power(me, msg, SKILL_USAGE_ATTACK);
		dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
		dp -= random(dp/3*2);

		if ( target->is_busy()) dp -= dp/2;

		if ( random(ap + dp) > dp )
			x = 1;

		if ( me->query_temp("xinghe/"+target->query("id")) > 1+random(2)
		 && !userp(target)
		 && ap * 2 > dp )
			x = 1;

		limbs = target->query("limbs");
		name = xue_name[random(sizeof(xue_name))];
		message_vision(HIW"\n$N����ָ��ͨЮ������֮�У�����һ��ָ�磬ֱָ��$n�ġ�"+name+"����\n", me, target);
		message_vision(replace_string(SKILL_D("tanzhi-shentong")->query_action(me, 0)["action"],"$l", limbs[random(sizeof(limbs))]) + "��\n"NOR, me, target);

		if (wizardp(me))
			tell_object(me, sprintf("ap: %d, dp: %d��prepare: %s��damage��%d\n", ap, dp, msg, lvl));

		switch (x) {
			case 1:
				target->receive_damage("qi", lvl, me);
				target->receive_wound("qi", random(lvl), me);
				if (!random(5)) target->add_condition("no_force", 3);
				msg = COMBAT_D->damage_msg(lvl, "����");
				if (random(2) && target->query("qi") >=0 || target->query("eff_qi")+target->query_temp("apply/qi") < 0) {
					p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100
						/(target->query("max_qi")+target->query_temp("apply/qi"));
					msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
				}
				else {
					p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
					msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
				}
				msg = replace_string( msg, "$w", "��ָ����");
				msg = replace_string( msg, "$l", name);
				me->delete_temp("xinghe/"+target->query("id"));
				message_vision(msg,me,target);
				break;
			case 0:
				dodge_skill = target->query_skill_mapped("dodge");
				if( !dodge_skill ) dodge_skill = "dodge";
				me->add_temp("xinghe/"+target->query("id"), 1);
				msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
if(msg)                                  message_vision(msg, me, target);
				break;
			default: return notify_fail("����wiz�������ˣ���\n");
		}
		call_out("check", 3, me, target, count -3);
	}
	else {
		skill = keys(pmap);
		for (i=0; i<sizeof(skill); i++) {
			me->prepare_skill(skill[i]);
				}
		me->prepare_skill("finger", "tanzhi-shentong");
			me->reset_action();
		me->delete_temp("thd/xinghe");
		me->delete_temp("xinghe");
		me->add_temp("apply/attack", -50);
		me->start_perform(1, "�Ǻ�ǧ����");
		if (living(me) && ! me->is_ghost())
			message_vision(HIW"\n$N����һ�䣬��ת���˵�ָ��ͨ��\n"NOR, me);
                		me->delete_temp("thd/xinghe");
	}
}

string perform_name(){ return HIW"�Ǻ�ǧ����"NOR; }

int help(object me)
{
        write(HIW"\n��ָ��֮ͨ���Ǻ�ǧ���衹��"NOR"\n\n");
        write(@HELP
	Ҫ��	������� 3500 ���ϣ�
		��ǰ���� 1200 ���ϣ�
		��ǰ���� 1000 ���ϣ�
		�̺��������ȼ� 250 ���ϣ�
		�沨�����ȼ� 250 ���ϣ�
		��ָ��ͨ�ȼ� 250 ���ϣ�
		����ָ���ȼ� 250 ���ϣ�
		����ָ��Ϊ��ָ��ͨ��
		�����м�Ϊ��ָ��ͨ��
		�����ұ�ָ��Ϊ��ָ��ͨ��
	
	ʹ��˵����
		set xinghe <���������书>
		����set xinghe luoying-zhang

HELP
        );
        return 1;
}
