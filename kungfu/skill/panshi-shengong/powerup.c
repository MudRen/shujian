// powerup.c

#include <ansi.h>
string exert_name(){ return HIY"����"NOR; }
int exert(object me)
{       

        int skill=me->query_skill("panshi-shengong");

        if ((int)me->query_skill("panshi-shengong", 1) < 160)
                return notify_fail("�����ʯ����Ϊ��������\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");
        
      if( me->query_temp("pssg/powerup")   )
                return notify_fail("���������þ�����\n");

        write(HIY"�͵�һ����Х������һ������ֱ�嶥�ţ�ë��ֱ������ʱ�����Ƶ��������ǰ��\n"NOR);

        me->add_temp("apply/attack", skill/2);
        me->set_temp("pssg/powerup", 1);  
        me->start_busy(random(2));
        me->add("neili", - 300);    
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill * 3/2 );
        return 1;
}
void remove_effect(object me, int skill)
{
       me->add_temp("apply/attack", -skill/2);
      me->delete_temp("pssg/powerup");
      tell_object(me, HIY"�����ʯ��������ϣ��������ջص��\n"NOR);
}

int help(object me)
{
	write(WHT"\n��ʯ��֮����������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ�������

	����Ҫ��
	        ����500
HELP
	);
	return 1;
}

