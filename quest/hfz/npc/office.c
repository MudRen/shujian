//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/quest/hfz/sys/mirror_sys"

int ask_job();

void create()
{

        set_name("芹菜9毛", ({ "master nine", "master","nine" }));
        set("title", "二流子");

        set("gender", "男性");
        set("age", 35);
        set("long","他是一个长相猥琐、淫荡、下流、无耻的家伙。\n");

	set("inquiry", ([ 
        	"剿匪" : (: ask_job :),
            ])); 

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

int ask_job()
{
	object me;
	object *team,memory;
int i;
	int td;
td = time() / 86400;	
	me = this_player();
	if(!me->is_team_leader())
	{
		tell_object(me,"你不是领队。\n");
		return 1;
	}
	team = me->query_team();
	if(!pointerp(team) || sizeof(team) < 2)
	{
		tell_object(me,"你的人手不够。\n");
		return 1;
	}
for (i = 0;i < sizeof(team);i ++)
{
if (!team[i])
command("say 你的队伍出现了问题，请解散并重新组建。\n");

                                       if (!present(team[i]))
                        command("say 怎么好象人不全啊？" + team[i]->query("name") + "怎么没来？\n");

	if(MIRROR_SYS->query_room_amount() >= 20)
	{
		tell_object(me,"镜像已经开启太多，欢迎下次参与。\n");
		return 1;
	}

if (team[i]->query("hfz_ask/which_day2") != td)
{
                team[i]->delete("hfz_ask/times");

}
if (team[i]->query("hfz_ask/which_day2") == td &&
            team[i]->query("hfz_ask/times") >= 3) 
{
tell_object(me,"" + team[i]->query("name") + "今天已经达到进入副本次数极限了。\n");

                return 1;
}
             
team[i]->set("hfz_ask/which_day2", td);
              team[i]->add("hfz_ask/times", 1);



}


	//删除旧的副本
	memory = me->query_temp("mirror/mirror_memory");
	if(objectp(memory))
	{
		memory->delete("user_id");
	}
	//创建新的副本
	MIRROR_SYS->mirror(team,me);
	return 1;
        team->move("quest/hfz/damen");
}