// halt.c
// LinuX@SJ 2004/03/02
#include <ansi.h>

int main(object me, string arg)
{
	object ob;

	if( arg && wizardp(me) ) {
		ob = present(arg, environment(me));
		if (!ob) ob = LOGIN_D->find_body(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("û��������\n");
		if (ob->is_busy()) {
			message_vision("\n$N����ʦ�����������$n��æ�ҡ�\n", me, ob);
			ob->interrupt_me();
			ob->start_busy(-1);
			ob->interrupt_me();
			return 1;
		}
		if( !ob->is_fighting() ) return notify_fail(ob->name()+"���ڲ�æ��\n");
		ob->remove_all_enemy();
		message_vision("\n$N����ʦ������ֹͣ��$n��ս����\n", me, ob);
		return 1;
	}
	if (!me->is_busy()) {
		if (me->is_fighting()) {
			if (me->is_nohalt()) 
				return notify_fail("������ʹ��"+me->query_perform()+"����ʱ�޷�ֹͣս����\n");
			if (strsrch(file_name(environment(me)), "/cmds/leitai/bwdh") >= 0 )
				return notify_fail("���Խ�ɽׯ�ڣ��޷�ֹͣս���ˡ�\n");
			me->remove_all_enemy();
			message_vision("\n$N�������һԾ������սȦ�����ˡ�\n", me); 
			return 1;
		}
		if (me->query_temp("on_baitan"))
		{
		message_vision(WHT "$N" WHT "����̯�����ĸ��ǣ��ѻ���һ���Ե�����"
                       "������վ��������\n" NOR, me);
        	me->delete_temp("on_baitan");
        	me->delete_temp("vendor_goods");
        	me->delete("disable_type");
        	return 1;
		}
		return notify_fail("�����ڲ�æ��\n");
	}

	notify_fail("�����ں�æ��ͣ��������\n");
	me->interrupt_me();
	if (me->is_busy()) return 0;
	return 1;
}
