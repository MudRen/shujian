// wudunru.cÎä¶ØÈå

inherit NPC;

 
void consider();

void create()
{
	set_name("Îä¶ØÈå", ({ "wu dunru","wu","dunru" }) );
	set("gender", "ÄĞĞÔ" );
	set("age", 28);
	set("long", "Éí²Ä½¡×³£¬Å¨Å¨µÄÃ¼Ã«£¬Ò»¸±¾«Éñ±¥ÂúµÄÑù×Ó¡£\n");
	set("attitude", "peaceful");
//      set("nickname", "");
        set("str", 30);
	set("con", 30);
	set("int", 20);
	set("dex", 30);
 

	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("shen", 5000);
	set("startroom","/d/xiangyang/outsroad1");

	 
	set("combat_exp", 500000);

	set_skill("force", 100); 
	set_skill("hand", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("huntian-qigong", 100);
	set_skill("literate", 100);
	set_skill("suohou-shou", 100); 
	set_skill("liuhe-daofa", 100);
	set_skill("xiaoyaoyou", 100);
        

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
        map_skill("blade","liuhe-daofa");
        map_skill("hand", "suohou-shou");
        map_skill("parry", "liuhe-daofa");
        prepare_skill("hand", "suohou-shou");

	create_family("Ø¤°ï", 19, "¹ÒÃûµÜ×Ó");

	set("chat_chance", 20);
	set("chat_msg", ({
		"Îä¶ØÈåËµµ½£º¡°´ò¹·°ôµÄ¾«ËèÌ«ÄÑÁìÎòÁË...°¥\n",
		"Îä¶ØÈåËµµ½£º¡°¹ùÜ½ÊÇÏ²»¶ÎÒÄØ£¬»¹ÊÇÏ²»¶....£¿\n",
                 (: random_move :)
	}) );

	setup();
        carry_object("/d/city/bqp_obj/blade")->wield();
        carry_object("/d/city/obj/cloth")->wear();
         
}
 

