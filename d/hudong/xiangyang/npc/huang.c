#include <ansi.h>
inherit NPC;
#include "boss.h"

void create()
{
        set_name("黄药师", ({ "huang yaoshi", "huang", "yaoshi" }) );
	set("nickname", "桃花岛主");
	set("long",
		"他就是桃花岛的岛主，江湖上人人闻名变色的东邪黄药师。\n"
		"他身穿一件青色长袍，腰带上斜插着一只玉箫。\n"
		"他形相清癯，丰姿隽爽，萧疏轩举，湛然若神。\n");
	set("gender", "男性" );
	set("rank_info/rude", "黄老邪");
	set("age", 50);
	set("attitude", "peaceful");
	set("apprentice",1);
	set("str", 30);
	set("int", 50);
	set("con", 35);
	set("dex", 40);
	set("per", 30);
	


        set("unique", 1);  //唯一性
   

        set("max_qi", 200000);
        set("max_jing", 20000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 200);
        set("eff_jingli",20000);
        set("combat_exp", 10000000);
        set("unique", 1);

       set_skill("force", 500);
	set_skill("bihai-chaosheng", 500);
	set_skill("dodge", 500);
	set_skill("suibo-zhuliu", 500);
	set_skill("parry", 500);
	set_skill("strike", 500);
	set_skill("luoying-zhang", 500);
	set_skill("leg", 500);
	set_skill("xuanfeng-tui", 400);
	set_skill("hand", 500);
	set_skill("lanhua-shou", 500);
	set_skill("finger", 500);
	set_skill("taoism", 200);
	set_skill("throwing", 390);
	set_skill("qimen-baguazhen", 200);
	set_skill("tanzhi-shentong", 500);
	set_skill("sword", 500);
	set_skill("yuxiao-jian", 500);
	set_skill("literate", 300);
	set_skill("qimen-bagua", 200);
	
	map_skill("force", "bihai-chaosheng");
	map_skill("dodge", "suibo-zhuliu");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("throwing", "tanzhi-shentong");
	map_skill("leg", "xuanfeng-tui");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-tui");
	

 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function, "maze" :),
		(: perform_action, "sword.qimen":),
		(: perform_action, "leg.kuangfeng":),
		
  }));


	create_family("桃花岛", 1, "岛主");


	
	
        	
	
        
	

        set("max_cure",5);
        set_temp("互动任务/襄阳大战/阵营",1);

        set_temp("apply/damage",500);
        set_temp("apply/damage_force",500);
        set_temp("apply/armor",500);
        set_temp("apply/armor_force",500);
        set_temp("double_attack",1);
    

        
        setup();
if(clonep())
	{
		object ob = unew(ARMOR_D("rwj"));
		if(!ob) ob=new("/d/thd/obj/grn-cloth");
		ob->move(this_object());
		ob->wear();
	}
	
	if (clonep(this_object()))
	{
		object ob;
		if (ob = carry_object(BINGQI_D("sword/dongxiao")))
			ob->wield();
	}


}
