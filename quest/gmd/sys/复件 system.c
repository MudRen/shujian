varargs void make_killer(object *player,object leader,int boss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
	object killer,memory,rand_map;
	mapping maps;
object *team;
team = this_player()->query_team();

		if(!player) return;
if(player[i]->is_team_leader())
		{
			leader = player[i];
			
		}

for (i = 0;i < sizeof(team);i ++)
{
if(team[i]->is_team_leader())
		{
			leader = team[i];
			
		}



if ( team->query_temp("/quest/gmd/hongshui"))
{
killer =new("quest/gmd/npc/tang");
killer->move(environment(present(leader)));
}
else if ( team->query_temp("/quest/gmd/liehuo"))
{
killer =new("quest/gmd/npc/xin");
killer->move(environment(present(leader)));
}
else if ( team->query_temp("/quest/gmd/houtu"))
{
killer =new("quest/gmd/npc/yan");
killer->move(environment(present(leader)));
}
else if ( team->query_temp("/quest/gmd/ruijin"))
{
killer =new("quest/gmd/npc/zhuang");
killer->move(environment(present(leader)));
}
else if ( team->query_temp("/quest/gmd/jumu"))
{
killer =new("quest/gmd/npc/wen");
killer->move(environment(present(leader)));
}
}
}
