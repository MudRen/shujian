// ginput
// by augx@sj 3/29/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( this_player()==this_player(1) || !arg ) return 0;
	input_to("input_yesno",me,arg);
	return 1;
}

void input_yesno(string arg,object me,string voter)
{
	if( !arg || (arg!="y" && arg!="n") ) {
		tell_object(me,"�����롰y����n����");
		input_to("input_yesno",me,voter);
		return;
	}
	GROUP_D->input_vote(me,voter,arg);
}
