// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_jhg();
void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "这是一个二十五六岁的年轻人, 浓眉大眼,\n"+
	    "大大的鼻子扁平下塌, 容貌颇为丑陋. \n"+
	    "身穿一件华贵雅致的长袍, 倒使他更显几分精神.\n"+
	    "他就是天山童姥的救命恩人.\n");
	set("title", "灵鹫宫掌门人");
	set("gender", "男性");
	set("age", 26);
	set("nickname", HIR "梦郎" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 50);
	set("int", 55);
	set("con", 50);
	set("dex", 50);
	set("per", 1);

	set("qi", 15000);
	set("max_qi", 15000);
	set("jing", 12000);
	set("max_jing", 12000);
	set("neili", 38000);
	set("max_neili", 38000);
	set("jiali", 100);

	set("combat_exp", 5500000);
	set("score", 20000);
	set_skill("force", 450);
	set_skill("yangyanshu", 180);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("hand",350);
	set_skill("strike", 350);
	set_skill("finger", 200);
	set_skill("claw", 200);
	set_skill("cuff", 200);
	set_skill("leg", 200);
	set_skill("sword", 300);
	set_skill("hand",350);
	set_skill("medicine",200);
	set_skill("longzhua-gong",200);
	set_skill("yizhi-chan",200);
	set_skill("buddhism",200);
	set_skill("literate",50);
	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
	set_skill("yueying-wubu",350);
	set_skill("bahuang-gong", 400);
  set_skill("tianyu-qijian",300);
	map_skill("force", "bahuang-gong");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
	map_skill("sword", "tianyu-qijian");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	create_family("灵鹫宫",2, "弟子");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.shandian" :),
                (: perform_action, "strike.baihong" :),
               
        }));

	set("inquiry", ([

		"剑湖宫" : (: ask_jhg :),
			
	]));






        	setup();
	carry_object("/clone/armor/changpao1")->wear();
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
	 object me = this_player();
   if ((int)ob->query_skill("bahuang-gong", 1) < 100) 
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	   }  
   if ((string)ob->query("gender")=="女性")
   {
		message_vision("虚竹垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
			me->set("title",HIM "灵鹫宫灵鹫仙子" NOR);
       return;}
   else
      {
		message_vision("虚竹瞪着你看了半天,说道：“阁下不会是想来抢我的生意吧?”\n",ob);
       return;}
}


string ask_jhg()
{
	object ob = this_player();
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "灵鹫宫" )
		return RANK_D->query_respect(ob)+"，无崖子前辈是有叫我去剑湖宫找一位女子学功夫，只是我现在走不开。";
        if (ob->query_skill("bahuang-gong", 1) < 300 )
	return "这位"+ RANK_D->query_respect(ob) +"，无崖子前辈是有叫我去剑湖宫找一位女子学功夫，只是我现在走不开。";


if(  ob->query("marks/xiaoyao") || ob->query("quest/xiaoyao/pass") || ob->query_temp("marks/ljg/gotolqs"))
      return "这位"+ RANK_D->query_respect(ob) +"，我不是已经让你去剑湖宫打探情况了吗？";
	
       ob->set_temp("marks/ljg/gotolqs", 1);
	command("nod " + ob->query("id"));
	return "无崖子前辈是有叫我去剑湖宫找一位女子学功夫，那位女子似乎与我灵鹫宫渊源颇深，你有时间的话可以去碰碰运气？";       
}




