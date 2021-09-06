#include <ansi.h>
inherit F_SSERVER;

string perform_name() {return HIW"�ܾ�ʽ"NOR;}

int perform(object me, object target)
{
	string msg, *skill;
	object weapon;
	mapping skills;
	int i;


	if( !target ) target = offensive_target(me);

    if( !objectp(target)
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("���ܾ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_skill("dugu-jiujian",1) < 350 )
		return notify_fail("��Ķ��¾Ž����������\n");

	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return notify_fail("�������޷�ʹ�á��ܾ�ʽ����\n");

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return notify_fail("�������޷�ʹ�á��ܾ�ʽ����\n");


	if(target->query_temp("dgjj/zongjue") )
	       return notify_fail("�������Ѿ��������ʹ�á��ܾ�ʽ���ˡ�\n");

	if((int)me->query("jingli")<2500)
		return notify_fail("��ľ���������\n"); 
	
	msg = HIG"\n$N������ȫ�����������������У������·���\n"NOR;
	me->start_perform(2,"���ܾ�ʽ��");

	me->add("jingli",-800);

 if ( random(me->query_int()) >= target->query_int()*2/3 && (me->query("relife/gifts/total")+2) >= target->query("relife/gifts/total")   
|| (!userp(target)&& random(2) )
)
//ԭ��Ʋ���Ϊtarget->query_int(),��ʱ��ǿһ��
      {
	msg+= HIG"\n$nֻ���ô������ƣ��书������֮����ȫ�޷����ӳ�����\n"NOR;
	skills = target->query_skill_map();
	if (!skills) return notify_fail("����û�м������⼼�ܡ�\n");
	skill = keys(skills);
	i = sizeof(skill);
	while (i--)
	  target->map_skill(skill[i]);
	target->delete("jiali");

	target->set_temp("no_enable",1);
	target->set_temp("dgjj/zongjue",1);
	me->set("jiali",0);
	call_out("remove_effect",me->query_skill("dugu-jiujian",1)/10,me,target);
	} else
	msg+= HIG"\n$n���һ�������潣�ߣ���Ȼ$N��Ҳ�޷�������С�\n"NOR;
	message_vision(msg,me,target);
	return 1;
}

void remove_effect(object me, object target)
{
	if (me) me->delete_temp("dgjj/zongjue");
	if (target) target->delete_temp("no_enable");
	if (target) target->delete_temp("dgjj/zongjue");
}
