// fanchang.c ��

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
#include <combat_msg.h>
#include <pktime.h>

int exert(object me, object target)
{
	object obj, weapon;
	int xf, sp, ap, curser;  
	string force;

	if( !target ) target = offensive_target(me);

	weapon = me->query_temp("weapon");  

	if( !weapon || weapon->query("skill_type") != "hammer" )
		return notify_fail("��δִ���������������󳪡�\n");

	if( weapon->query_amount() < 2 && weapon->query("id") != "fenghuo lun" && weapon->query("hammer_count") < 2 )
		return notify_fail("����Ҫ�������Ӳ��ܻ����󳪡�\n");
	
	if(!objectp(obj = me->query_temp("armor/cloth")) ||
	(
		!obj->id("shisan longxiang") && !obj->id("longxiang jiasha")
	))
		return notify_fail("��δ�������ۣ����������󳪡�\n");

	if( !objectp(target) || target == me)
		return notify_fail("����Ҫ����˭����\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if( target->query("race") != "����")
		return notify_fail(target->query("name") + "������������\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("xiangfu-lun",1) < 250 )
		return notify_fail("��Ľ���������������\n");

	if( (int)me->query_skill("huanxi-chan", 1) < 180 )
		return notify_fail("��������ķ�����������\n");

	if( (int)me->query_skill("longxiang-boruo", 1) < 250 )
		return notify_fail("����������������������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܳ���\n");

	if( target->query_temp("cursed", 1) )
		return notify_fail("�����ѱ�������\n");
	
        if ( me->query("no_pk") && userp(target) )
                return notify_fail("���Ѿ�����ϴ�֣����ǲ�Ҫ���뽭����Թ�ɡ�\n");

        if ( userp(me) && target->query("no_pk") )
                return notify_fail(target->name()+ "�Ѿ�����ϴ�֣������˴������˰ɡ�\n");

        if ( pktime_limit(me, target) )
                return 0;

        if( meisdummy(me,target) )
                return notify_fail("�����ף�һ������ȥ��\n");
               
	if( userp(me) && userp(target) ) {
                target->set_temp("other_kill/"+me->query("id"), 1);
                
                log_file("ANSUAN", 
                        sprintf("%-18s fanchan %-18s",
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                target->name(1)+"("+capitalize(getuid(target))+")"
                        ),
                        this_object(),
                );
        }
                                        
	me->start_exert(5, "��");
	me->add("neili", - 400 + me->query_skill("huanxi-chan", 1));
	me->receive_damage("jingli",  - 250 + me->query_skill("huanxi-chan", 1) );
	message_vision( BLU"$Nҡͷ���ԣ����������е�"NOR+weapon->query("name")+BLU"�����б��д�˷𾭣����������������䡣���������ٴ죬�����з����������ɡ�\n" NOR, me);
	tell_object(target,  "�����������ȹ�޻��������Դ���һ�����ң���ǰһ�ѹ�Ӱ��������Խ���е��־塣\n");

	xf = me->query_skill("xiangfu-lun", 1) + me->query_skill("longxiang-boruo", 1) + me->query_skill("huanxi-chan", 1);
	xf = xf + me->query("con")*10 + me->query("str")*10;
	ap = target->query_skill("parry") + target->query_skill("force");
	ap = ap + target->query("con")*15  + target->query("int")*10; 
	sp = xf * 2 + me->query("con")*15 + me->query("str")*10;
	sp += me->query("combat_exp")/5000 + me->query("neili")/10;
	ap += target->query("combat_exp")/5000 + target->query("neili")/10;
	
	message("wizard",sprintf(HIG"������Ϣ��lxbr'fanchang ���У�%d��������%d \n"NOR,sp,ap),
		environment(me)?filter_array(all_inventory(environment(me)),(:
		$1->query("env/combat")=="verbose"
		:)):0
	);
		
	if( random(sp) > ap*3/4 && !target->query("no_sing") ) {
		message_vision(HIR"$nֻ����$N���������������������ӿ������$n��ʱͷ���ۻ�����������������ʹ����������\n"NOR, me, target);
		target->remove_all_killer();
		target->start_busy(3 + random(2));
		me->set_temp("curser", 1);
		me->start_busy(1 + random(3));
		curser = me->query_skill("huanxi-chan", 1) + me->query_skill("force")/5;
		target->add_temp("apply/attack", -curser );
		target->set_temp("cursed", curser );
		target->add_temp("apply/strength", -me->query_con()/2);
		target->set_temp("cursed_str", me->query_con()/2);

		target->set("jiali", 0);
		target->apply_condition("no_enforce", (me->query_skill("huanxi-chan")/20)
			+ 1 + target->query_condition("huanxi-chan"));

		if( (int)target->query("combat_exp") > me->query("combat_exp")/2 && userp(target) ) {
			me->improve_skill("force", me->query("int")*10);
		}
		call_out("del_sung", 15 + me->query_skill("huanxi-chan", 1)/10, me, target);
		return 1;
	} else {
		if( !stringp(force = to_chinese(target->query_skill_mapped("force"))) ) force = "�ڹ�";
		message_vision(HIY"$nǱ��"+force+"���߶�������$N���������ֿ�����ʱ���ܵ�������ĸ�Ϊ���ӣ��������ܡ�\n"NOR, me, target);
		me->start_busy(3+random(3));
		target->start_busy(1);
		if( !target->is_killing(me) ) target->kill_ob(me);
		return 1;
	}
}

void del_sung(object me, object target)
{
	if( !target ) return;

	if( target->query_temp("cursed") ) {
		target->add_temp("apply/attack", target->query_temp("cursed"));
		target->delete_temp("cursed");		
	}
	if( target->query_temp("cursed_str") ) {
		target->add_temp("apply/strength", target->query_temp("cursed_str"));
		target->delete_temp("cursed_str");
	}
	
	if( target->query_leader() ) target->set_leader(0);
	message_vision(YEL"���ӵ����ɽ�����ʧ��$n�����ָ��˾��񣬲����ܵ�$N���Ի��ˡ�\n"NOR, me, target);
}

string exert_name(){ return HIB"��"NOR; }

int help(object me)
{
        write(HIB"\n���������֮���󳪡���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 5000 ���ϣ�
                ����������ȼ� 250 ���ϣ�
                ��ս����ֵȼ� 250 ���ϣ�
                ��ϲ���ȼ� 180 ���ϣ�
                ����װ����������Ϊ������
                �����������ġ�

HELP
        );
        return 1;
}
