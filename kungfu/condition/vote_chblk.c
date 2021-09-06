// vote_unchblk.c
// snowman@SJ 11/12/2000

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 2) {
		tell_object(me, HIM "�ͷ�ʱ���ѵ������Ƶ�������ˣ�\n" NOR);
		me->clear_condition("vote_clear");
		me->delete("chblk_on");
        	me->delete("chblk_rumor");
        	me->delete("chblk_chat");
        	me->delete("chblk_party");
        	me->delete("chblk_group");
        	me->delete("chblk_sr");
        	me->delete("chblk_sj");
        	me->delete("chblk_irc");
		return 0;
	}

	me->apply_condition("vote_chblk", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "vote";
}
