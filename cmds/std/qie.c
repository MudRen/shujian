// by snowman@SJ 18/02/2000
// YUJ 2001-10-29

#include <ansi.h>

inherit F_CLEAN_UP;
#define HEAD "/clone/misc/head"

int main(object me, string arg)
{
	object target, ob, weapon, murderer;

	if (!arg) return notify_fail("��Ҫնʲô��\n"); 
 
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ���ء�\n"); 

	if( !target = present(arg, environment(me)) ) {
		if( !target = present(arg, me) ) 
			return notify_fail("�Ҳ������������\n");
	}

	if( !target->is_corpse() ) 
		return notify_fail("������㣬�ǲ���ʬ�塣\n");
	if (target->query("race") != "����")
		return notify_fail("����ɣ���Զ����ʬ��Ҳ����Ȥ��\n");
	if (target->query("no_head"))
		return notify_fail("�Ǿ�ʬ���Ѿ�û���׼��ˡ�\n");
	if (!target->is_character())
		return notify_fail("�Ǿ�ʬ���Ѿ������ˡ�\n");
	murderer = target->query("kill_by");
	if (objectp(murderer) && murderer != me)
		return notify_fail("���б���ɱ���˸��ﰡ��\n"); 
	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����ü����������߲���������ʬ���ͷ����\n");

	if (weapon->query("flag") != 4)
		return notify_fail("��������������޷����У������������ʬ���ͷ����\n");

	message_vision("\n$N����"+weapon->name()+"����׼$n�Ĳ��ӱ��˱ȣ���ն����ȥ��\n", me, target);

	ob = new(HEAD);
	ob->set_name( target->query("victim_name")+"���׼�" , ({ "shouji", "head" }) );
	ob->set("long", "����һ��"+target->query("victim_name")+"���׼���\n");

	if (objectp(murderer)) {
//		target->set("kill_by", target->query("kill_by"));
		ob->set("kill_by", murderer);
		target->delete("kill_by");
	} else
		ob->set("kill_by", me);

	ob->set("victim_id", target->query("victim_id"));
	target->delete("victim_id");
	ob->set("victim_name", target->query("victim_name"));
	ob->set("victim_user", target->query("victim_user"));
	ob->move(me);
	message_vision("ֻ�����ǡ���һ����$N��$nն���������������С�\n", me, ob);
	message_vision(HIG"$N����һ�ţ���$nԶԶ�߿�,��֪���ɵ��ĸ�������ȥ�ˡ�\n"NOR, me, target);
       destruct(target);

	me->add_busy(1);
	return 1;
}      

int help(object me)
{
	write(@HELP
ָ���ʽ : qie <ʬ��>
 
���ָ����������ʬ���ͷ����������
 
HELP
	);
	return 1;
}
