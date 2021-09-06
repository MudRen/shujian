#include <ansi.h>
inherit NPC;
#include "boss.h"

void create()
{
        set_name("杨过", ({"yang guo", "guo", "yang", "zhengfang"}));
        
	set("title",HIW"古墓侠侣"NOR);
	set("nickname",HIY"神雕大侠"NOR);
	set("long", "他就是名满天下的杨过。虽断一臂但仍遮不去一脸的英雄豪气。\n");
	set("gender", "男性");
set("age", 30);
        set("attitude", "friendly");
        

        set("unique", 1);  //唯一性
     set("per", 36);
	set("str", 40);
	set("int", 35);
	set("con", 40);
	set("dex", 35);

        set("max_qi", 200000);
        set("max_jing", 20000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 200);
        set("eff_jingli",20000);
        set("combat_exp", 10000000);
        set("unique", 1);

        set_skill("sword",500);
        set_skill("dodge",500);
        set_skill("strike",500);
        set_skill("force", 500);
        set_skill("hand", 500);
        set_skill("cuff", 500);
        set_skill("parry", 500);
        set_skill("finger",140);
        set_skill("literate", 250);
        set_skill("xiantian-gong", 80);
        set_skill("hamagong",300);
        set_skill("medicine",120);
        set_skill("jingmai-xue", 80);
        set_skill("yunu-shenfa", 500);
        set_skill("xuantie-jianfa", 500);
        set_skill("anran-zhang", 380);
        set_skill("quanzhen-jianfa",360);
        set_skill("tianluo-diwang", 340);
        set_skill("yunu-xinjing",500);
        set_skill("jiuyin-zhengong",160);

        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-zhang");        
        map_skill("hand", "tianluo-diwang");
        map_skill("strike", "anran-zhang");        
        prepare_skill("strike","anran-zhang");
 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function, "xinjing" :),
		(: perform_action, "sword.haichao":),
		(: perform_action, "strike.xiaohun":),
		
  }));


	create_family("古墓派",3,"男主人");

	
	if (random(3))
		set("env/玄铁剑法", "汹涌");
        	
	set("inquiry", ([
		"古墓" : "那日华山与众英雄诀别后和龙儿隐居于此已有数年，不闻世事，能与\n"+
			"龙儿在此长伴一世，此身足矣！",
		"小龙女" : "龙儿乃我爱妻，你问她做甚？",
		

	]));

        
	

        set("max_cure",5);
        set_temp("互动任务/襄阳大战/阵营",1);

        set_temp("apply/damage",500);
        set_temp("apply/damage_force",500);
        set_temp("apply/armor",500);
        set_temp("apply/armor_force",500);
        set_temp("double_attack",1);
    

        
        setup();
carry_object(BINGQI_D("gangjian"))->wield();
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object("/d/gumu/obj/pao1")->wear();

}
