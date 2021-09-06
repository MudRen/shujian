// hanxiaoying.c 韩小莹
// Created by Zhuifeng@sjfy 08/8/2010

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("韩小莹",({"han xiaoying","han","xiaoying"}));
   set("gender","女性");
   set("long","江南七怪老七,\n");
   set("shen",80000);
   set("combat_exp",1200000);
   set("nickname",HIM"越女剑"NOR);
   set("title",WHT"江南七怪老七"NOR);
   
   set("age",18);
   set("pur",28);
   set("per",29);
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

   set_skill("dodge",180);
   set_skill("force",180);
   set_skill("parry",180);
   set_skill("sword",180);
   set_skill("yuenu-jian",200);
   set_skill("literate",120);
   set_skill("xiaoyaoyou",200);
   map_skill("dodge","xiaoyaoyou");
   map_skill("sword","yuenu-jian");

   setup();
   add_money("silver",70);
carry_object(__DIR__"obj/cloth")->wear();
carry_object("clone/weapon/sword")->wield();
}
