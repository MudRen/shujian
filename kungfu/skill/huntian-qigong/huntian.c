// huntian.c ������������
// Change Powerup to huntian by Looklove 2001.5.3

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIR"����"NOR; }

int exert(object me, object target)
{
	int skill;

	if( me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( me->query_skill("huntian-qigong", 1) < 100 )
		return notify_fail("��Ļ��������ȼ�������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query_temp("htqg/powerup") )
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force")/3;
	if( skill > 150 ) skill = 150;

	me->receive_damage("neili", -300);
	message_vision(HIR "$N΢һ�������𡸻��졹�񹦣�ȫ��ǽڷ���һ�󱬶�������졣\n" NOR, me);

	me->add_temp("apply/dodge", skill/2);
	me->set_temp("htqg/powerup", skill);
	me->delete_temp("htqg/shougong");

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "��������");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
	int amount;
	if(!me) return;
	if(me->query_temp("htqg/powerup")){
	if( count-- > 0 && !me->query_temp("htqg/shougong") ) {
			call_out("remove_effect", 1, me, count);
			return;
		}
	
		amount = me->query_temp("htqg/powerup");
		me->add_temp("apply/dodge", - amount/2);
		me->delete_temp("htqg/powerup");
		me->delete_temp("htqg/shougong");
		tell_object(me, HIR"��Ļ�������������ϣ��������ջص��\n"NOR);
	   return;
	   }
}

int help(object me)
{
        write(HIR"\n��������֮�����졹��"NOR"\n");
        write(@HELP
        ����Ϊ����������Ҫ����֮һ��ͨ���˹����Խ���������ӱ�������
        Ҫ��
        	���������ȼ���100 ���ϣ�
                ��ǰ����  500 ���ϡ�
HELP
        );
        return 1;
}