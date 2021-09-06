// nanxiren.c 南希仁
// Created by Zhuifeng@sjfy 08/8/2010

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("南希仁",({"nan xiren","nan","xiren"}));
   set("gender","男性");
   set("long","江南七怪老四,\n");
   set("shen",80000);
   set("combat_exp",1200000);
   set("nickname",HIY"南山樵子"NOR);
   set("title",WHT"江南七怪老四"NOR);
   
   set("age",28);
   set("pur",30);
   set("kar",25);
   set("per",20);
   set("str",26);
	 set("int",20);
	 set("con",25);
	 set("dex",18);
	 set("max_qi", 3000);
	 set("max_jing", 2000);
	 set("eff_jingli", 2000);
	 set("neili", 2000);
	 set("max_neili", 2000);
	 set("jiali", 50);

   set_skill("dodge",210);
   set_skill("force",210);
   set_skill("parry",210);
   set_skill("blade",210);
   set_skill("strike",210);
   set_skill("nanshan-dao",220);
   set_skill("kaishan-zhang",210);
   set_skill("literate",90);
   set_skill("xiaoyaoyou",200);
   map_skill("dodge","xiaoyaoyou");
   map_skill("strike","kaishan-zhang");
   map_skill("blade","nanshan-dao");
   prepare_skill("strike","kaishan-zhang");

   setup();
   add_money("silver",70);
carry_object(__DIR__"obj/cloth")->wear();
carry_object("clone/weapon/blade")->wield();
}
