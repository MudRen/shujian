// yangguo.c 杨过

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#include "xykm_job.h"
string ask_job();

void create()
{
	set_name("杨过",({"yang guo","yang"}));
	set("title",HIW"古墓侠侣"NOR);
	set("nickname",HIY"神雕大侠"NOR);
	set("long", "他就是名满天下的杨过。虽断一臂但仍遮不去一脸的英雄豪气。\n");
	set("gender", "男性");
	set("age", 39);
	set("attitude", "friendly");
	set("gender", "男性");
	set("shen", 10000);
	set("per", 36);
	set("str", 40);
	set("int", 35);
	set("con", 40);
	set("dex", 35);

        set("max_qi", 10500);
        set("max_jing", 7000);
        set("neili", 18500);
        set("eff_jingli", 7500);
        set("max_neili", 18500);
        set("jiali", 150);
        set("combat_exp", 4800000);
        set("unique", 1);

        set_skill("sword",350);
        set_skill("dodge",350);
        set_skill("strike",350);
        set_skill("force", 350);
        set_skill("hand", 350);
        set_skill("cuff", 350);
        set_skill("parry", 350);
        set_skill("finger",140);
        set_skill("literate", 250);
        set_skill("xiantian-gong", 80);
        set_skill("hamagong",300);
        set_skill("medicine",120);
        set_skill("jingmai-xue", 80);
        set_skill("yunu-shenfa", 350);
        set_skill("xuantie-jianfa", 370);
        set_skill("anran-zhang", 380);
        set_skill("quanzhen-jianfa",360);
        set_skill("tianluo-diwang", 340);
        set_skill("yunu-xinjing",350);
        set_skill("jiuyin-zhengong",160);

        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-zhang");        
        map_skill("hand", "tianluo-diwang");
        map_skill("strike", "anran-zhang");        
        prepare_skill("strike","anran-zhang");


	create_family("古墓派",3,"男主人");

	set_temp("apply/damage", 70);
	set_temp("apply/dodge", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 70);

	if (random(3))
		set("env/玄铁剑法", "汹涌");
        	setup();
	set("inquiry", ([
		"古墓" : "那日华山与众英雄诀别后和龙儿隐居于此已有数年，不闻世事，能与\n"+
			"龙儿在此长伴一世，此身足矣！",
		"小龙女" : "龙儿乃我爱妻，你问她做甚？",
		"襄阳任务" : (: ask_job :),
                "job" : (: ask_job :),

	]));

        setup();
	carry_object(BINGQI_D("sword/gangjian"));
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object("/d/gumu/obj/pao1")->wear();
}

string ask_job()
{
        object me = this_player();
        int exp = me->query("combat_exp");

        if( (int)me->query("shen") < 0 )
                return "你尽做坏事，我如何放心把襄阳城安危托付给你。\n";

        if( exp < 5000000 )
                return RANK_D->query_respect(me) + "纵有此心，奈何武功修为太差。\n";

        if( !wizardp(me) && me->query_condition("job_busy"))
                return "我这里现在没有什么任务，你等会再来吧。\n";

		   if(me->query_temp("quest/busy")) //added by tangfeng 与quest冲突
			    return "现在我这里没有给你的任务，你还是先处理好你其他事情再说吧。";

       if ( me->query_condition("killer"))
                 return "你现在是官府捉拿的要犯，还是先处理好你自己的事情吧!"; 
        if( me->query("menggu") )
                return "哼，你这汉奸，还想要任务？\n";

        if( exp >5000000 ){
                return xykm_job();
        }
        return "我这里没有什么可以给你做的任务了。\n";
}

void unconcious()
 {
         remove_all_killer();
         remove_all_enemy();
         say("杨过大叫一声: 有救命丸，咱啥都不怕，哈哈！。\n");
         reincarnate();
         set("eff_qi", query("max_qi"));
         set("qi", query("max_qi"));
         set("eff_jing", query("max_jing"));
         set("jing", query("max_jing"));
         set("jingli", query("eff_jingli"));
         clear_conditions_by_type("poison");
 }
 
 void die()
 {
         unconcious();
 }