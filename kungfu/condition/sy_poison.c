// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_wound("jing", 20*(1+random(10)));
 	me->apply_condition("sy_poison", duration - 1);
	tell_object(me, HIG "һ������ӿ����ͷ���㲻��������Ż�����е�" HIR "����ӡ�ƶ�" HIG "�����ˣ�\n" NOR );
        message("vision", me->name() + "��ɫ���죬�������ǣ���֫�Ҳ�վ�����ȡ�\n",
            environment(me), me);
        if( duration < 1 ) return 0;
	return 1;
}
