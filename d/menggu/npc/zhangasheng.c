// zhangasheng.c
// Created by Zhuifeng@sjfy 08/9/2010

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("张阿生",({"zhang asheng","zhang","asheng"}));
   set("gender","男性");
   set("long","江南七怪老五\n");
   set("shen",80000);
   set("combat_exp",1200000);
   set("nickname",HIY"笑弥陀"NOR);
   set("title",WHT"江南七怪老五"NOR);
   
   set("age",28);
   set("pur",20);
   set("kar",18);
   set("per",26);
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
   set_skill("strike",300);
   set_skill("hand",220);
   set_skill("xiaoyaoyou",220);
   map_skill("dodge","xiaoyaoyou");

   setup();
   add_money("silver",70);
carry_object(__DIR__"obj/cloth")->wear();
}
