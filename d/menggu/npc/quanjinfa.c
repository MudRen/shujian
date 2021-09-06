// quanjinfa.c
// Created by Zhuifeng@sjfy 08/9/2010

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("全金发",({"quan jinfa","quan","jinfa"}));
   set("gender","男性");
   set("long","江南七怪老六\n");
   set("shen",80000);
   set("combat_exp",1200000);
   set("nickname",HIG"闹市侠隐"NOR);
   set("title",WHT"江南七怪老六"NOR);
   
   set("age",20);
   set("pur",30);
   set("kar",20);
   set("per",25);
   set("str",30);
	 set("int",25);
	 set("con",20);
	 set("dex",30);
	 set("max_qi", 3000);
	 set("max_jing", 2000);
	 set("eff_jingli", 2000);
	 set("neili", 2000);
	 set("max_neili", 2000);
	 set("jiali", 20);

   set_skill("dodge",220);
   set_skill("force",220);
   set_skill("parry",220);
   set_skill("sword",200);
   set_skill("hand",240);
   set_skill("literate",40);
   set_skill("trade",200);
   set_skill("spear",280);
   set_skill("xiaoyaoyou",220);
   set_skill("huyan-qiang",280);
   map_skill("dodge","xiaoyaoyou");
   map_skill("spear","huyan-qiang");

   setup();
   add_money("silver",70);
carry_object(__DIR__"obj/cloth")->wear();
carry_object("clone/weapon/changqiang.c");
}
