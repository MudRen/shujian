//1999.2.26 by Snowman
// modify by athoi@sj 2004.06.11 for ��Ϊ��Ѫ��ʾ���� ���Ը�Ϊ�ָ���Ѫ������Ѫ
// modify by server ����set Ч����ѡ���Իָ�,recover jing ����������recover qi ��5 ��
// By Spiderii@ty ���������츳����Ч��
#include <ansi.h>

int exercising(object me);
int halt_exercise(object me);

int exert(object me)
{
	string force;
	mapping msg;
	
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");
	if (userp(me) && me->query_skill("medicine", 1) < 30)
		return notify_fail("��Ա���������о����������������ˡ�\n");   
	if(!(force = me->query_skill_mapped("force")))
		return notify_fail("�㻹û��ѡ����Ҫʹ�õ��ڹ���\n");
	if(me->query_skill("force") < 50)
		return notify_fail("����ڹ��ȼ���̫�ͣ������˹����ˡ�\n");
	if(me->query("env/heal") && me->query("env/heal") != "jing")
		return notify_fail("�㻹û��ѡ����Ҫ�ָ����趨��\n");
	if (me->query("max_neili") < 200)
		return notify_fail("���������Ϊ������\n");
	if (me->query("neili") < 50)
		return notify_fail("�������������\n");
	if (!me->query("env/heal") && me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("�㲢û�����ˣ�\n");
	if (me->query("env/heal") == "jing" && me->query("eff_jing") >= me->query("max_jing"))
		return notify_fail("�㲢û�����ˣ�\n");
	if (!me->query("env/heal") && me->query("eff_qi") < me->query("max_qi") / 4 || me->query("env/heal") == "jing"&& me->query("eff_jing") < me->query("max_jing") / 4)
		return notify_fail("���Ѿ����˹��أ����ܲ��������𵴣�\n");
	
      	msg = SKILL_D(force)->exercise_msg(me);
      	if (!msg || undefinedp(msg["heal_msg"]))
	   	message_vision(HIW"$N��ϥ���£���ʼ�˹����ˡ�\n"NOR,me);
      	else 
      		message_vision(msg["heal_msg"],me);
     
      	me->set_temp("pending/heal", 1);
      	me->set_temp("period", 1);
      	me->start_busy((: exercising :), (:halt_exercise:));
      	return 1;
}

int exercising(object me)
{
	int period = me->query_temp("period");
	int skill = (me->query_skill("jingmai-xue", 1) + me->query_skill("medicine", 1)) / 2;
	string force;
	mapping msg;
	
	if (!userp(me) && !skill) 
		skill = 100;
	if (!living(me) || !(force = me->query_skill_mapped("force")) || !skill) 
	{
		me->delete_temp("pending/heal");
		me->delete_temp("period");
		return 0;
	}

	msg = SKILL_D(force)->exercise_msg(me);
	skill = (skill+random(skill))/4;
	skill += me->query_skill(force)/10;
	skill += random(me->query_con()/4);
	
	if( !me->query("env/heal") && me->query("eff_qi") >= me->query("max_qi"))
	{
		tell_object(me, "���ã���о�ͨ���Լ�����Ϣ���У����ϵ������Ѿ�ȫ���ˡ�\n");
		if (!msg || undefinedp(msg["heal_finish_msg"]))
			message_vision(HIW"$N�˹���ϣ�վ������������ȥ��ɫ�����������ӡ�\n"NOR,me);
		else 
			message_vision(msg["heal_finish_msg"],me);
		me->delete_temp("pending/heal");
		me->delete_temp("period");
		return 0;
	}
		if( me->query("env/heal") == "jing"&& me->query("eff_jing") >= me->query("max_jing"))
	{
		tell_object(me, "���ã���о�ͨ���Լ�����Ϣ���У����ϵ������Ѿ�ȫ���ˡ�\n");
		if (!msg || undefinedp(msg["heal_finish_msg"]))
			message_vision(HIW"$N�˹���ϣ�վ������������ȥ��ɫ�����������ӡ�\n"NOR,me);
		else 
			message_vision(msg["heal_finish_msg"],me);
		me->delete_temp("pending/heal");
		me->delete_temp("period");
		return 0;
	}
	if( me->query("neili") < 50 )
	{
		tell_object(me, "�������˹����ˣ�ȴ�����Լ���ʣ�����������ˡ�\n");
		if(me->query("eff_qi") < me->query("max_qi") || me->query("eff_jing") < me->query("max_jing"))
			tell_object(me, HIY"�����һ����վ����������ϧ���ƻ�û����ȫ�ָ���\n"NOR);
		if (!msg || undefinedp(msg["heal_unfinish_msg"]))
			message_vision(HIY"$N�˹���ϣ�����վ����������ɫ������������ࡣ\n"NOR,me);
		else 
			message_vision(msg["heal_unfinish_msg"],me);
		me->delete_temp("pending/heal");
		me->delete_temp("period");
		return 0;
	}
                  
       //�츳��������ǡ�Ӱ��Ч����  by spiderii@ty
                   if((int)me->query("relife/recover/jsjg",1) > 0){
                       skill += (int)me->query("relife/recover/jsjg",1) * skill * 8 / 100;
                       tell_object(me,HIC"����Ϊת�����ޣ��������������ؿ�����������˻ָ�����Ѹ�ݷǳ���\n"NOR);
                       me->receive_curing("qi",skill);
                   }
        if (me->query("env/heal") == "jing" && me->receive_curing("jing", skill))
        me->receive_damage("neili", 50 * 5);//�ָ���ע��������Ϊ,�����������
        if (!me->query("env/heal") && me->receive_curing("qi", skill))
        me->receive_damage("neili", 50);

	switch(period) 
	{
		case 5:
		case 100:
		case 150:
			tell_object(me, "��˫�ֻ��գ����������ͣ�ش߶���Ϣ���ˡ�\n");
			break;
		case 10:
		case 40:
		case 80:
		case 110:
		case 160:
			message_vision("$N�����³�һ����Ѫ����ɫ����������һ�㡣\n",me);
			break;
		case 20:
		case 120:
		case 170:
			tell_object(me, "�㽫˫��������ԣ���Ϣ˳�ƻ�����ת��ͨ����ȫ��������\n");
			me->improve_skill("jingmai-xue", 1);
			break;
		case 30:
		case 130:
		case 180:
			tell_object(me, "������������ת��ת��Ż��������Ѫ����ȥ�˵��ؿڱ���֮����\n");
			me->improve_skill("force", 1);
			break;
		case 60:
		case 90:
		case 140:
		case 190:
			message_vision("$N������������Ϣ�˴���ʱ��������Ϊ֮һ��\n", me);
			break;
		case 50:
		case 70:
		case 200:
			tell_object(me, "�����������𲽹�ͨ����֫������ʼ���������ˡ�\n\n");
			me->improve_skill("medicine", 1);
			break;
	}
	me->add_temp("period", random(skill)+1);
	return 1; 
}

int halt_exercise(object me)
{
	string force;
	mapping msg;
	
	force = me->query_skill_mapped("force");
	if (force) 
		msg = SKILL_D(force)->exercise_msg(me);
	me->delete_temp("pending/heal");
	me->delete_temp("period");
	me->receive_damage("jing", 50);
	me->receive_damage("jingli", 50);
	tell_object(me, "����ͷһ������æ������Ϣ��Ӳ��������Ϣѹ����ȥ��\n");
	if (!msg || undefinedp(msg["heal_halt_msg"]))
		message_vision("$Nһ���³�һ����Ѫ������վ��������\n", me);
	else    
		message_vision(msg["heal_halt_msg"], me);    
	me->start_busy(1+random(5));
	return 1;
}
