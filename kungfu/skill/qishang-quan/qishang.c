// qishang.c 
// Update By lsxk@hsbbs 2007/6/11

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void remove_effect(object target,int damage);

string *songs = ({"����֮��������","�����˷δݸγ�","���뾫ʧ����","������������Ƿ���"});
string *num_color = ({HIR,HIC,HIG,HIM,HIY,HIB,HBRED});

int perform(object me, object target)
{
	string msg, song;
   int p, damage, ap, dp, jiali, qi_wound;
	song = songs[random(sizeof(songs))];

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) || !living(target) )
		return notify_fail("�������ܾ���ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ�á������ܾ�����\n");

   if( (int)me->query_skill("qishang-quan",1) < 200 )
		return notify_fail("�������ȭ������죬����ʹ�á������ܾ�����\n");

   if(!me->query_skill("jiuyang-shengong", 1) || (int)me->query_skill("jiuyang-shengong",1)< 200 )
   if(userp(me) && (int)me->query_skill("shenghuo-shengong",1) < 200 )
           return notify_fail("��������ڹ��ȼ�����������ʹ�á������ܾ�����\n");

   if(userp(me) && me->query_skill_mapped("force") != "shenghuo-shengong" && me->query_skill_mapped("force") != "jiuyang-shengong" )
           return notify_fail("��û��ʥ���񹦻������̾������ڹ����޷�ʹ�á������ܾ������й�����\n");

   if( (int)me->query_con(1) < 38 )
		return notify_fail("������岻��ǿ׳������ʹ�á������ܾ�����\n");

   if( (int)me->query("max_neili") < 3000 )
		return notify_fail("�������̫��������ʹ�á������ܾ�����\n");

   if( (int)me->query("neili") < 1200 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó��������ܾ�����\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");
/*
	if( me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");
*/
   if( (int)me->query("jingli") < 800 )
		return notify_fail("��ľ���̫���ˣ��޷�ʹ�ó��������ܾ�����\n");

	if( me->query_skill_mapped("parry") != "qishang-quan"
	&& me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("����Ҫ�����м�Ϊ����ȭ������ʹ�á������ܾ������й�����\n");

	if (me->query_skill_prepared("cuff") != "qishang-quan"
	 || me->query_skill_mapped("cuff") != "qishang-quan")
           return notify_fail("�������޷�ʹ�á������ܾ������й�����\n");

   if((int)target->query_temp("qishang")>6)
           return notify_fail("�Է��Ѿ������߹ɡ������ھ������㲻�÷Ѿ��ˣ�\n");

	message_vision(HIR"\nͻȻ$N���侫�⣬����������Ƹ�Ǹ衢��ʫ��ʫ��ȭ������"+song+"�������һȭ����$n��\n"NOR,me, target);

   me->start_perform(2+random(4),"�������ܾ���");

	ap = COMBAT_D->skill_power(me, "cuff", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
   if(target->is_busy()) dp=dp/2;

   jiali = (int)me->query("jiali")/60;
   jiali = jiali+(int)target->query_temp("qishang");
   if(jiali<1) jiali = 1;

   if ( random(ap + dp ) > dp/2 ){
            qi_wound = ((int)me->query_skill("cuff",1)+(int)me->query_skill("qishang-quan",1)) * jiali;
           if(wizardp(me)) write("damage is :"+qi_wound+"!\n");
		target->receive_damage("qi", qi_wound, me);
		target->receive_wound("qi", qi_wound/2, me);
		target->add_busy(1);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+qi_wound+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+qi_wound+ WHT"���˺���\n"NOR);
		if((me->query("neili") + me->query_con(1)*(20+random(40))) < target->query("neili"))
			tell_object(me, HIR"��ֻ��"+target->name()+"����������ǿ���㰵����ȭ�ڵĸ������������Ͳ���ȥ��\n"NOR);
		else{
			damage = target->query_str(1)/2;
			damage += target->query_int(1)/2;
			damage += target->query_con(1)/2;
			damage += target->query_dex(1)/2;
                   damage /= 8;
                   tell_object(me, num_color[(int)target->query_temp("qishang")]+"�ڸ�һ����"+target->name(1)+"������ʱ����㰵����������������ȭ�ڵĵ�"+HIW+chinese_number(1+(int)target->query_temp("qishang"))+NOR+num_color[(int)target->query_temp("qishang")]+"���ھ����˹�ȥ��\n"NOR);
                   tell_object(target, HIW"��һ���ۣ�ֻ��"+me->name(1)+"��ȭ�Ѿ�����������ϣ�����һ��˵�����İ���˳�ƴ��˹�����\n"NOR);
			me->add("neili", -400);
			me->add("jingli", -50);
			me->start_perform(4, "�������ܾ���");
			target->set("qishang", damage);
                   if(!target->query_temp("qishang")){
			target->add_temp("apply/strength", -damage);
			target->add_temp("apply/dexerity", -damage);
			target->add_temp("apply/intelligence", -damage);
			target->add_temp("apply/constitution", -damage);
                   target->add_condition("qishang_poison", 9);
                   target->add_condition("no_perform", 6);
			target->start_call_out( (: call_other, __FILE__, "remove_effect", target ,damage :), me->query_skill("cuff", 1)/4);
                   }
                   target->add_temp("qishang", 1);
		}
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg = COMBAT_D->damage_msg(qi_wound, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg = COMBAT_D->damage_msg(qi_wound, "����");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
	}
	else {
		me->start_busy(1+random(2));
		me->add("neili", -150);
		me->add("jingli", -200);
		msg = "ֻ��$p����һת���Ѿ��Ƶ���$P��󡣶�$Nȴ������ղ��ܿ��ƣ�ͷ��ѣ�Σ�\n";
	}
	message_vision(msg, me, target);
	return 1;
}

void remove_effect(object target,int damage)
{
	if( ! target || !target->query_temp("qishang")) return;
	target->add_temp("apply/strength", damage);
	target->add_temp("apply/dexerity", damage);
	target->add_temp("apply/intelligence", damage);
	target->add_temp("apply/constitution", damage);
	target->clear_condition("no_perform");
	target->delete_temp("qishang");
	tell_object(target, HIW"\n���������Ǽ��ɰ����ڱ鲼���ȫ��֮�󣬿�ʼ����ɢȥ�ˡ�\n"NOR);
}

string perform_name(){ return HIR"�����ܾ�"NOR; }

int help(object me)
{
	write(HIR"\n����ȭ֮�������ܾ�����"NOR"\n\n");
	write(@HELP
   Ҫ��  ��ǰ���� 1200 ���ϣ�
           ������� 3000 ���ϣ�
           ��ǰ���� 800 ���ϣ�
           ����ȭ�ȼ� 200 ���ϣ�
           ʥ���񹦵ȼ� 200 ���� ���� ���̾������ȼ� 200 ���ϣ�
           ������� 38 ���ϣ�
		����ȭ��Ϊ����ȭ��
		�����м�Ϊ����ȭ��Ǭ����Ų�ƣ�
		��ȭ��Ϊ����ȭ��

HELP
	);
	return 1;
}
