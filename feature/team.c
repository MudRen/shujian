// team.c
// 2001-05-06 ����׷ɱ������һ���� follow delay -YUJ@SJ
// Modified by Ciwei@SJ fix a big bug 2004 5 2
#include <command.h>
#include <dbase.h>
#include <origin.h>

nosave object leader, *team;

int set_leader(object ob)
{
	if (ob==this_object())
		error("set_leader: Cannot set this_object() as leader.\n");
	leader = ob;
}

object query_leader() { return leader; }

private void follow_path(object ob, string dir)
{
	if (!ob
	|| environment(ob) == environment()
	|| query_temp("pending/follow") != ob)
		return;
	GO_CMD->main(this_object(), dir);
}

void follow_me(object ob, string dir)
{
	object me = this_object();

	if( !living(me) || ob==me ) return 0;

	if( ob==leader || (query("pursuer") && me->is_killing(ob->query("id")))) {
		set_temp("pending/follow", ob);
		if (random(2) && userp(me) && !wizardp(me) && userp(ob)
		&& ob->query_leader() != me && !me->is_killing(ob->query("id"))) {
			remove_call_out("follow_path");
			call_out("follow_path", 1, ob, dir);
		} else follow_path(ob, dir);
	}
}

int add_team_member(object ob)
{
	if( ob==this_object() ) return 0;

	if( arrayp(team) ) {
		if( member_array(ob, team)==-1 ) {
			team -= ({ 0 });
			team += ({ ob });
			for(int i=sizeof(team)-1; i>=0; i--)
				team[i]->set_team(team);
		} else
			return 0;
	} else {
		team = ({ this_object(), ob });
		ob->set_team(team);
	}
	return 1;
}

int is_team_leader()
{
	return arrayp(team) && team[0]==this_object();
}

int set_team(object *t)
{
	team = t;
}

varargs int dismiss_team(object ob)
{
	int i;

	if( !arrayp(team) ) return 0;
	
	if( !ob ) {
		if( team[0]==this_object() ) {
			team -= ({ 0 });
			for(i=1; i<sizeof(team); i++)
				team[i]->set_team(0);
		} else {
			team -= ({ 0 });			
			for(i=0; i<sizeof(team); i++)
			{
				if(team[i]==this_object()) continue;//add by Ciwei@SJ
				team[i]->dismiss_team( this_object() );
			}
		}
		team = 0;
	} else team -= ({ ob });
	return 1;
}

object *query_team()
{
	return team;
}

