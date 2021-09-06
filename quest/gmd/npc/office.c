//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/quest/gmd/ruijin/sys/mirror_sys"
#define MIRROR_SYS1 "/quest/gmd/jumu/sys/mirror_sys"
#define MIRROR_SYS2 "/quest/gmd/hongshui/sys/mirror_sys"
#define MIRROR_SYS3 "/quest/gmd/liehuo/sys/mirror_sys"
#define MIRROR_SYS4 "/quest/gmd/houtu/sys/mirror_sys"


int ask_job();

void create()
{

set_name(HIG"空性大师"NOR, ({ "kongxing dashi", "kongxing" ,"dashi"}));
set("title",HIR"少林四大神僧"NOR);
         set("class", "bonze");
        set("gender", "男性");
        set("age", 60);
        set("long","空性是少林派四大神僧“见闻智性”之一，
精通少林龙爪手，平日多在寺中精研武功，下山极少。\n");
        set("age", 70);
        set("shen", 32000);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 12000);
        set("max_jing", 10000);
        set("eff_jingli", 9000);
        set("neili", 22000);
        set("max_neili", 22000);
        set("jiali", 150);
        set("combat_exp", 6400000);

        set_skill("force", 400);
        set_skill("yijin-jing", 400);
        set_skill("dodge", 400);
        set_skill("shaolin-shenfa", 400);
        set_skill("fumoquan-zhen", 200);
        set_skill("claw", 400);
        set_skill("parry", 400);
        set_skill("cuff", 400);
        set_skill("club", 400);
        set_skill("blade", 400);
        set_skill("ranmu-daofa", 400);
        set_skill("finger", 400);
        set_skill("strike", 400);
        set_skill("buddhism", 200);
        set_skill("riyue-bian", 400);
        set_skill("whip", 400);
        set_skill("yizhi-chan", 400);
        set_skill("literate", 250);
        set_skill("jingang-quan", 400);
        set_skill("hand", 400);
        set_skill("leg", 400);
        set_skill("ruying-suixingtui", 400);
        set_skill("banruo-zhang", 400);
        set_skill("qianye-shou", 400);
        set_skill("longzhua-gong", 400);
        set_skill("weituo-chu", 400);
        set_skill("zui-gun", 400);
        set_skill("club", 400);
        set_skill("nianhua-zhi",400);
        set_skill("xiuluo-dao",400);

        map_skill("blade","ranmu-daofa");
        map_skill("club","weituo-chu");
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "yizhi-chan");
        map_skill("cuff","jingang-quan");
        map_skill("leg","ruying-suixingtui");
        map_skill("hand","qianye-shou");
        map_skill("claw","longzhua-gong");
        map_skill("whip","riyue-bian");
        map_skill("strike","banruo-zhang");
        prepare_skill("finger", "yizhi-chan");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "jingang" :),
                (: perform_action, "finger.qiankun" :),
                (: perform_action, "finger.wofo" :),
        }));
 create_family("少林派", 36, "弟子");

	set("inquiry", ([ 
        	"围攻光明顶" : (: ask_job :),
            ])); 
 carry_object("/d/shaolin/obj/xuan-cloth")->wear();

        setup();
}


int ask_job()
{
	object me;
	object *team,memory;
object* ppl;
	int i,t,a,b,c,d,e;

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
{
                        command("say 怎么好象人不全啊？" + team[i]->query("name") + "怎么没来？\n");
return 1;
}

if (team[i]->query("shen")< 0) {
command("say 你队伍里" + team[i]->query("name") + "眼露邪光，不会是魔教的卧底吧？\n");
return 1;
}
if (team[i]->query("family/family_name")!=me->query("family/family_name"))
{
command("knock "+ me->query("id"));

tell_object(me,"你的同队队友不是一个门派的。\n");
return 1;
}
}
ppl = users();
t = sizeof(ppl);
a=0;
b=0;
c=0;
d=0;
e=0;

while(t--){
	if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/hongshui") )  a++;
			if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/ruijin") )  b++;
					if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/liehuo") )  c++;
							if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/jumu") )  d++;
									if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/houtu") )  e++;
		
		 }
if(a<1) {  team->set_temp("/quest/gmd/hongshui",1); 
tell_object(me,""+me->query("family/family_name")+"弟子听令，你等且由"HIW"洪水旗"NOR"进入，直捣光明顶，不得有误！\n");


if(MIRROR_SYS2->query_room_amount() >= 20)
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
	MIRROR_SYS2->mirror(team,me);
	return 1;

        team->move("quest/gmd/hongshui/hongshui");

}

	else if(b<1){ team->set_temp("/quest/gmd/ruijin",1);
tell_object(me,""+me->query("family/family_name")+"弟子听令，你等且由"HIY"锐金旗"NOR"进入，直捣光明顶，不得有误！\n");


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
	return 1;


        team->move("quest/gmd/ruijin/ruijin");


}

		else if(c<1) { team->set_temp("/quest/gmd/liehuo",1);
tell_object(me,""+me->query("family/family_name")+"弟子听令，你等且由"HIR"烈火旗"NOR"进入，直捣光明顶，不得有误！\n");


if(MIRROR_SYS3->query_room_amount() >= 20)
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
	MIRROR_SYS3->mirror(team,me);
	return 1;


        team->move("quest/gmd/liehuo/liehuo");


}

			else if(d<1) { team->set_temp("/quest/gmd/jumu",1);
tell_object(me,""+me->query("family/family_name")+"弟子听令，你等且由"HIG"巨木旗"NOR"进入，直捣光明顶，不得有误！\n");

if(MIRROR_SYS1->query_room_amount() >= 20)
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
	MIRROR_SYS1->mirror(team,me);
	return 1;


        team->move("quest/gmd/jumu/jumu");


}

				else if(e<1) { team->set_temp("/quest/gmd/houtu",1);
tell_object(me,""+me->query("family/family_name")+"弟子听令，你等且由"YEL"厚土旗"NOR"进入，直捣光明顶，不得有误！\n");

if(MIRROR_SYS4->query_room_amount() >= 20)
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
	MIRROR_SYS4->mirror(team,me);
	return 1;


        team->move("quest/gmd/houtu/houtu");


}
	else 		{
tell_object(me,"已经安排了足够的人手去攻克五行旗了，欢迎下次参与。\n");
return 1;
}

}
