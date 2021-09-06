#include <ansi.h>

int exercising(object me);
int halt_exercise(object me);

int exert(object me, mixed arg)
{
	if(!arg)
		return notify_fail("��ʽ��exert shenyou <id> \n"); 

	if(objectp(arg))
		return notify_fail("��Ҫ�ҵ��˾���һ�ԣ��������Ρ���ʲô��\n"); 

	if(!stringp(arg))
		return notify_fail("��Ҫ�����Ρ�ʲô��\n"); 

	if( arg == me->query("id"))
		return notify_fail("�����Ρ��Լ����㲻���߻���ħ�˰ɣ�\n"); 

	if( (int)me->query_skill("longxiang-boruo",1) < 180 )
		return notify_fail("�������������������ȣ��޷����á����Ρ���\n"); 

	if ( environment(me)->query("no_death") || environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ʺ������Ρ�\n");

	if( (int)me->query_skill("huanxi-chan",1) < 180 )
		return notify_fail("������ڻ�ϲ�����������޷����á����Ρ���\n");    

	if( me->is_fighting() )
		return notify_fail("�����Ρ�ֻ���ڰ����Ļ�����ʹ�á�\n");

	if( (int)me->query("neili") < 2000 || (int)me->query("max_neili")<3000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("mz_shenyou") ) 
		return notify_fail("���Ѿ����˹��������ˡ�\n");

	if( me->query("jing") < me->query("eff_jing"))	
		return notify_fail("�㾫����������ܡ����Ρ���\n");  

	if( me->query("jingli") < 1000)
		return notify_fail("��Ŀǰ����˥�ߣ������޷������Ρ���\n");

	if( me->query_int(1) < 40)
		return notify_fail("ֻ�д��Ǵ��֮�˲���ͨ�������Ρ������������ǲ��е��ˡ�\n");
	  
	me->add("neili", -2000);

	message_vision(HIY"\n$N��ϥ��Ŀ�����������������ķ���������ܷ����������Ρ��󷨣�\n"+
		"���ܵ�ʯ�ɽ����������������Ϲ��ߣ��������졣����\n\n" NOR, me);

	me->set_temp("mz_shenyou", 1);
	me->set_temp("period", 1);
	me->set_temp("person", arg);
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object me)
{
	object npc, target;
	string arg;
	int period = (int)me->query_temp("period");
	 
	me->receive_damage("jing", 5+random(5));
	me->receive_damage("jingli", 5+random(5));

	if(!living(me)) return 0;
	if(me->query("jing") < 1 || me->query("jingli") < 1){
		me->delete_temp("mz_shenyou");
		me->delete_temp("period");
		me->delete_temp("person");
		me->delete_temp("shenyou_npc");
		me->unconcious();
		return 0;
	}
	if(!me->query_temp("person")){
		halt_exercise(me);
		return 0;
	}
	if(period < 0 && period > -6){
		me->set_temp("period", period-1);
		return 1;
	}
	if(period <= -6){
		write("\n�㻺��վ��������ֻ����ȫ�����ѣ�ʮ��ƣ����\n\n");
		tell_room(environment(me), me->name()+"��������һ�ڻ���������վ��������\n\n", ({ me }));
		me->set("jing", 1);
		me->set("jingli", 1);
		me->delete_temp("period");
		me->delete_temp("person");
		me->delete_temp("mz_shenyou");
		me->start_busy(2);
		return 0;
	}
	if(me->query("jing") <= 80 || me->query("jingli") <= 80){
		write(HIY"\n�����أ����˼���ֻ�ת������һ˿��΢����������������Ҳ��ʼ���˸о���\n\n"NOR);
		npc = me->query_temp("shenyou_npc");
		if(objectp(npc))
			npc->do_remove();
		me->delete_temp("shenyou_npc");
		me->add("potential", 1+random(5));
		me->set_temp("period", -1);
		return 1;
	}
	switch(period) {
		case 2:
			write("\n��ȫ����ɣ������������ڼ꣬����������\n\n");
			break;
		case 6:
			write("\n��һ�����������Լ�����־Խ��Խ���ѣ�������ҲԽ��Խ���ˡ�\n\n");
			break;
		case 9:
			write(HIY"\n�����أ��㷢���㿴�����Լ���ϥ����������������Ѿ��ֿ����Ƶġ�\n\n"NOR);
			break;
		case 12:
			write(HIC"\n�㷢���Լ�����־Խ��ԽԶ����˲ʱ���Ѿ�����˸�ɽ�󺣣��ε������֮�У�\n\n"NOR);
			me->improve_skill("force", 1);
			break;
		case 16:
			arg = me->query_temp("person");
			if ((target = LOGIN_D->find_body(arg)) && me->visible(target)){
				write(HIW"\n���˼�����ſ�ȥ��ֻһɲ�ǣ�������"+target->name()+HIW"����ߣ�\n\n"NOR);
				if (wizardp(target)) {
					tell_object(me, MAG"\n����Ȼ���֣����˾��Ǻ������֣�����һ��Ư���ڰ�յ���\n"+
							"���һ��ع�ͷ����������һ�ۣ���е����²����æ���˻�����\n\n"NOR);
					halt_exercise(me);
				}
				else {
					npc = new(__DIR__"shenyou_npc");
					npc->do_setup(me, target);
					me->set_temp("shenyou_npc", npc);
				}
			}
			else {
				write(HIW"\n���˼�����ſ�ȥ�������һ�����������Ҳ������ˣ�\n\n"NOR);
				halt_exercise(me);
			}
			break;
	}
	period++;
	me->set_temp("period", period);
	return 1; 
}

int halt_exercise(object me)
{
	object npc;
	if ( !me->query_temp("period"))
		return 1;
	me->delete_temp("mz_shenyou");
	me->delete_temp("period");
	me->delete_temp("person");
	me->receive_damage("jing", 200);
	me->receive_damage("jingli", 200);
	me->add("max_neili",-20-random(20));
	npc = me->query_temp("shenyou_npc");
	if(objectp(npc))
		npc->do_remove();
	write("����ͷһ���亹ֱ�£��ٲ��ܼ��������Ρ��󷨣�ֻ������վ��\n");
	tell_room(environment(me), me->name()+"ȫ��һ�󶶶���ͷ�Ϻ������£�����һ��վ��������\n", ({ me }));
	me->start_busy(1+random(5));
	return 1;
}

string exert_name(){ return HIY"����"NOR; }

int help(object me)
{
	write(HIY"\n���������֮�����Ρ���"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 2000 ���ϣ�
		������� 3000 ���ϣ�
		��ǰ���� 1000 ���ϣ�
		��ϲ���ȼ� 180 ���ϣ�
		����������ȼ� 180 ���ϣ�
		�������� 40 ���ϡ�

HELP
        );
        return 1;
}
