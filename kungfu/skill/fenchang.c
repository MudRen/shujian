// fanchang.c ��

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;


int exert(object me, object target)
{
	object obj, weapon;
	int xf, sp, ap;  

	if( !target ) target = offensive_target(me);

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "jingang chu")
		return notify_fail("��δִ���������������󳪡�\n");

	if ((!objectp(obj = present("shisan longxiang", me)) ) || (!obj->query("equipped") )) 
		return notify_fail("��δ�ŷ��ۣ����������󳪡�\n");
        
	if( !objectp(target) || target == me)
		return notify_fail("����Ҫ����˭����\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if( target->query("race") != "����")
		return notify_fail(target->query("name") + "������������\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("xiangfu-lun",1) < 300 )
		return notify_fail("��Ľ���������������\n");

	if( (int)me->query_skill("huanxi-chan", 1) < 200 )
		return notify_fail("��������ķ�����������\n");

	if( (int)me->query_skill("longxiang-boruo", 1) < 300 )
		return notify_fail("����������������������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܳ���\n");
        
	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1))
		return notify_fail("�����ѱ�������\n");

	if( (int)me->query_temp("curser") )
		return notify_fail("�㽵������һ���ˣ�\n");

	if ( me->query("no_pk") && userp(target))
		return notify_fail("���Ѿ��˳������ˡ�\n");

	if ( target->query("no_pk"))
		return notify_fail(target->name(1)+ "�Ѿ��˳������ˡ�\n");

	me->add("neili", - 350);
	me->receive_damage("jingli", 100);
	me->start_exert(3, "��");

	message_vision(HIB "$Nҡͷ���ԣ����б��д�˷𾭣����������������䡣���������ٴ죬�����з����������ɡ�\n" NOR, me);
	tell_object(target,  "�����������ȹ�޻��������Դ���һ�����ң���ǰһ�ѹ�Ӱ��������������������֫��������Ȼ��˯��\n");
                
	xf = (me->query_skill("xiangfu-lun", 1) + me->query_skill("huanxi-chan", 1));
	ap = target->query_skill("parry") + target->query_skill("force") + target->query("con")  + target->query("int") ; 
	sp = me->query_skill("force") + xf * 2;
	sp *= me->query("combat_exp")/1000;
	ap *= target->query("combat_exp")/1000;

	if( random(sp) > ap/2 && !target->query("job_npc")){
		tell_object(target, HIR "��ֻ������ǰ��һ����������Զȥ����Ļ�����Ҫ���ϣ������������ס�\n" NOR);
		message_vision("�㿴��" +target->query("name") +"ͻȻ��ʼ���۷�ֱ������������ǰ����\n", me);
		target->remove_all_killer();
		target->set_temp("cursed", 1);
		target->set_temp("block_msg/all", 1);
		me->set_temp("curser", 1);
		if((int)target->query("combat_exp") > me->query("combat_exp")/2 && userp(target)){
			me->improve_skill("force", me->query("int"));
		}
		call_out("del_sung", me->query_skill("huanxi-chan", 1)/5, me, target);
		return 1;
	}
	else {
		me->start_busy(random(7));
		if( !target->is_killing(me)) target->kill_ob(me);      
		return 1;
	}
}

void del_sung(object me, object target)
{
	if ( me && me->query_temp("curser") )
		me->delete_temp("curser");
	if (!target) return;
	if (target->query_temp("cursed", 1))
		target->set_temp("cursed", 0);
	if (target->query_temp("block_msg/all", 1))
		target->set_temp("block_msg/all", 0);
	if (target->query_leader() ) 
		target->set_leader(0);  
	message_vision("$N���������ѹ����������ֻص����Լ������ϡ�\n", target);
}

string exert_name(){ return HIB"��"NOR; }

int help(object me)
{
        write(HIB"\n���������֮���󳪡���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 5000 ���ϣ�
                ����������ȼ� 300 ���ϣ�
                ��ս����ֵȼ� 300 ���ϣ�
                ��ϲ���ȼ� 200 ���ϣ�
                ����װ����ս�ħ��Ϊ������
                ����ʮ���������ġ�

HELP
        );
        return 1;
}
