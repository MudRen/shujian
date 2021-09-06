#include <ansi.h>
inherit NPC;
#include "boss.h"

void create()
{
       set_name("黄蓉", ({ "huang rong", "huang", "rong" }));
set("nickname", "丐帮前帮主");
	set("long",
"她长发披肩，全身白衣，头发上束了一条金带，灿然生光。虽年过三旬，一身装束犹如仙女一般。\n");
	set("gender", "女性");
		set("age", 33);
	set("attitude","peaceful");
	set("str", 30);
	set("int", 50);
	set("con", 35);
	set("dex", 40);
	set("per", 30);
	set("unique",1);
	set("max_qi", 200000);
        set("max_jing", 20000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 200);
        set("eff_jingli",20000);
        set("combat_exp", 10000000);
        set("unique", 1);

	set("tu", 1);
	set("shu", 1);
	set("shouhuan",1);

	set("jiali",50);
	set_skill("force", 500);
	set_skill("huntian-qigong", 500);
	set_skill("bihai-chaosheng", 500);
	set_skill("dodge", 500);
	set_skill("xiaoyaoyou", 500);
	set_skill("parry", 500);
	set_skill("strike", 500);
	set_skill("luoying-zhang", 500);
	set_skill("hand", 500);
	set_skill("lanhua-shou", 500);
	set_skill("finger", 500);
	set_skill("tanzhi-shentong", 500);
	set_skill("sword", 500);
	set_skill("yuxiao-jian", 500);
	set_skill("literate",500);
	set_skill("qimen-bagua", 500);
	set_skill("bangjue",500);
	set_skill("dagou-bang",500);
	set_skill("stick",500);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("parry", "dagou-bang");
	map_skill("sword", "yuxiao-jian");
	map_skill("stick", "dagou-bang");
	prepare_skill("hand", "lanhua-shou");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.ban" :),
		(: perform_action, "stick.yin" :),
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.chan" :),
		(: perform_action, "stick.wugou" :),
		(: exert_function, "huntian" :),
	}));



	


	
	
        	
	
        
	

        set("max_cure",5);
        set_temp("互动任务/襄阳大战/阵营",1);

        set_temp("apply/damage",500);
        set_temp("apply/damage_force",500);
        set_temp("apply/armor",500);
        set_temp("apply/armor_force",500);
        set_temp("double_attack",1);
    

        
        setup();
	carry_object("/d/city/obj/necklace.c")->wear();
	carry_object("d/thd/obj/white_cloth.c")->wear();
		carry_object("/d/city/obj/goldring.c")->wear();
	carry_object("/clone/weapon/zhubang")->wield();


}
