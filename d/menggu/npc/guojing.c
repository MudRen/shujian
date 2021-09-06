// guojing.c 郭靖
// Created by Zhuifeng@sjfy 08/8/2010

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("郭靖",({"guo jing","guo"}));
   set("gender","男性");
   set("long","郭靖出生在蒙古,随江南六怪学艺!\n");
   set("title",HIY"金刀驸马"NOR);
   set("shen",1000000);
   set("combat_exp",1000000);
   
   set("age",17);
   set("per",29);
   set("pur",30);
   set("kar",30);

   set("str",30);
	 set("int",20);
	 set("con",40);
	 set("dex",30);
	 set("max_qi", 4000);
	 set("max_jing", 4000);
	 set("eff_jingli", 4000);
	 set("neili", 8000);
	 set("max_neili", 4000);
	 set("jiali", 500);
   set_skill("dodge",200);
   set_skill("force",200);
   set_skill("parry",200);
   set_skill("staff",160);
   set_skill("jinyan-gong",160);
	 set_skill("spear", 200);
	 set_skill("zhong-qiang", 200);
   set_skill("whip",180);
   set_skill("sword",180);
   set_skill("blade",180);
   set_skill("strike",220);
   set_skill("arrow",200);
   set_skill("baibu-chuanyang",200);
   set_skill("xiantian-gong",220);
   set_skill("quanzhen-jianfa",220);
   set_skill("haotian-zhang",220);
   set_skill("literate",100);
   set_skill("war",80);
   set_skill("medicine",60);
   map_skill("force","xiantian-gong");
   map_skill("arrow","baibu-chuanyang");
   map_skill("dodge","jinyan-gong");
   map_skill("spear","zhong-qiang");
   map_skill("sword","quanzhen-jianfa");
   map_skill("strike","haotian-zhang");
   prepare_skill("strike","haotian-zhang");


   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/jindao")->wield();
}
