#include <ansi.h>
inherit NPC;
string ask_baoming();
string* names = ({
"/d/hudong/xiangyang/defend",	"/d/hudong/xiangyang/attack",
});
void create()
{
        object ob;
        set_name("说书老者", ({ "shuoshu laozhe", "shuoshu", "laozhe"}));
        set("gender", "男性");
        set("unique", 1);
        set("age", 60);
        set("long", "他是一个说书老者，专门说些忠烈之事，极为精彩。\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 4000);
        set("qi", 4000);
        set("jing",1600);
        set("eff_jing", 1600);
        set("jingli", 2200);
        set("eff_jingli", 2200);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);

        set("combat_exp", 1500000);
        
               set("chat_chance", 3);
        set("chat_msg", ({
            "说书老者吟到：“黄金逐手快意尽，昨日破产今朝贫，丈夫何事空啸傲？不知烧却头上巾......”\n",
            "说书老者低声长吟：“天子重英豪，文章教尔曹，万般皆下品，唯有读书高......”\n", 
        }) );

        set("inquiry", ([
           "报名"  : (: ask_baoming :),
        ]));

        setup();
        if (clonep()) {
carry_object(ARMOR_D("changshan4"))->wear();
        add_money("gold",2);
   }
}

string ask_baoming()
{
object me = this_player();
int exp = me->query("combat_exp");
string objwhere;       
objwhere = names[random(sizeof(names))];


if( exp < 5000000 )
                return RANK_D->query_respect(me) + "纵有此心，奈何武功修为太差。\n";

        if( !wizardp(me) && me->query_condition("job_busy"))
                return "你的任务繁忙时间未过，等会再来吧。\n";

		   if(me->query_temp("quest/busy")) 
			    return "现在我这里没有给你的任务，你还是先处理好你其他事情再说吧。";

       if ( me->query_condition("killer"))
                 return "你现在是官府捉拿的要犯，还是先处理好你自己的事情吧!"; 
if(!this_object()->query("hd_start"))

return "襄阳大战还没有开始，等等吧!"; 


me->move(objwhere);
                return "去吧！\n";
}

