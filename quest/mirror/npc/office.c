//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/quest/mirror/sys/mirror_sys"


int ask_job();

void create()
{

        set_name(HIG"袁崇焕"NOR, ({ "yuan chonghuan", "yuan" }));
set("title",HIR"蓟辽督师"NOR);

        set("gender", "男性");
        set("age", 40);
        set("long","袁崇焕，字元素，是一位忧国忧民的抗清将军，曾在山海关宁远镇一代抵御清军。\n");

	set("inquiry", ([ 
        	"抗清" : (: ask_job :),
            ])); 

        setup();
}


int ask_job()
{
	object me;
	object *team,memory;
	int i;
	me = this_player();

	if(!me->is_team_leader())
	{
		tell_object(me,"你不是领队。\n");
		return 1;
	}

       if  (me->query("fuben/kangqing/time") && time()-me->query("fuben/kangqing/time") < 21600 )
{
    tell_object(me,"进出副本每次需间隔21600秒。\n");
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



 if(team[i]->query("fuben/kangqing/time") && 
time()-team[i]->query("fuben/kangqing/time") <21600 )
   {
		tell_object(me,"你队伍中有人尚未达到冷却时间，请另找高明。\n");
		return 1;
	}
/*
if (!interactive(team[i]) || query_ip_number(team[i]) == query_ip_number(me)) {
command("say 同IP的不能进入副本，换个队友吧。");
			return 1;
		}

*/

}

	if(MIRROR_SYS->query_room_amount() >= 20)
	{
		tell_object(me,"镜像已经开启太多，欢迎下次参与。\n");
		return 1;
	}
	//删除旧的副本
	memory = me->query_temp("mirror/mirror_memory");
	if(objectp(memory))
	{
		memory->delete("user_id");
	}
	//创建新的副本
	MIRROR_SYS->mirror(team,me);
team->set("fuben/kangqing/time",time());
       	return 1;
       
team->move("quest/mirror/guangchang");


}
