// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "��Ȼ�������ƮƮ,���ƺ������ᵽ��һ�����صĵط���\n" NOR); 
                me->move("/u/dubei/sg");
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("player_bug", duration - 1);
        return 1;
}
