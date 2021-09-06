#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) {
	  if (this_player()->query("family/family_name")=="������" || this_player()->query("cw_mp/������")) return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
	int i, l;
	i = (int)me->query_skill("qiantian-yiyang", 1);
	l = (int)me->query_skill("buddhism", 1);

	if (!me->query("tls"))
	if ((i >= 10 && (int)me->query("shen") < i * 5)
	 || (i >= 50 && (int)me->query("shen") < i * 8)
	 || (i >= 100 && (int)me->query("shen") < i * 10))
		return notify_fail("���������������ɣ��������������������������\n");

	if ( me->query("tls") && i > 10 && i < 150 && l < i - 10)
		return notify_fail("��ķ�ѧ��Ϊ����������ֹ������еĺ�ʤ֮���ˣ�\n");

	if (me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ���򻹲������޷����Ǭ��һ������\n");

	if (i > 99 && (string)me->query("gender") != "����")
		return notify_fail("�㲻�Ǵ���֮���޷������߲��Ǭ��һ������\n");

	if ( me->query("menggu"))
		return notify_fail("Ǭ��һ�������ɺ�а�ɹ����Ϊһ�壿\n");

	if ( i > me->query_skill("force", 1) + 10 && i >= 200 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
	if((int)me->query_skill("qiantian-yiyang", 1) >= 200) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
			me->improve_skill("qiantian-yiyang", (int)me->query_int());
			me->add("neili", -100);
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ���������Ǭ��һ�����ˡ�\n");
	}
	else return notify_fail("�����ڵ�Ǭ��һ������Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"qiantian-yiyang/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIY + me->name()+"�����������̬����"NOR,
		"start_my_msg" : "����ϥ���£���Ŀ��ʲ������Ǭ��һ���񹦣�һ�ɴ���������ʼ��������ת��\n",
		"start_other_msg" : me->name()+"��ϥ���£���Ŀ��ʲ,��̬���꣬�����ƺ���һ�������֡�\n",
		"halt_msg" : "$N˫��һ�֣�ƽ̯���أ�Ѹ��������ֹͣ������������\n",
		"end_my_msg" : "������������������һ�����죬���������ڵ�������������۾���\n",
		"end_other_msg" : "ֻ��"+me->name()+"���������۾����������ֵĽ������ȥ��\n"
	]);
}

int ob_hit(object ob, object me, int damage)
{
	int i,neili,j;

	if( !me->query_temp("dali/jujing") ) return 0;

	if ( me->query_temp("weapon")) return 0;

	if ( me->query_skill_mapped("finger") != "yiyang-zhi"
	|| me->query_skill_prepared("finger") != "yiyang-zhi") return 0;

	if( me->is_busy() ) j = 2; else j = 1;

	if( damage > me->query("qi") ) {
		me->add_temp("dali/jujing1",damage*j);
		neili = 13000 - me->query_skill("force")*10;
		if( neili < me->query("neili") ) {
			me->add("neili",-neili);
			if( wizardp(me) && me->query("env/test") )
				tell_object(me,sprintf("dec: %d,%d\n",damage,neili));
			message_vision(CYN"$N��һ��ָ�ᾢ���յ�$nȫ���Ĺ�����\n"NOR, me, ob);
			return -damage;
		}
	}

	if( random(me->query("combat_exp")) < ob->query("combat_exp")/3 ) return 0;

	i = me->query_skill("force") / 10;
	i = MIN(i,70);
	i = i/3 + random(i);
	i = damage * i / 100;

	me->add_temp("dali/jujing1", i*j);
	if( wizardp(me) && me->query("env/test") )
		tell_object(me,sprintf("dec: %d(%d) \n",i,damage));
	message_vision(CYN"$N��һ��ָ�ᾢ���յ�$n���ֹ�����\n"NOR, me,ob);

	return -i;
}
