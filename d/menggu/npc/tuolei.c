// tuolei.c 拖雷
// Created by Zhuifeng@sjfy 08/8/2010

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("拖雷",({"tuo lei"}));
   set("gender","男性");
   set("long","拖雷是成吉思汗幼子，坚忍果决。\n");
   set("shen",10000);
   set("combat_exp",80000);
   set("title",HIG"蒙古王子"NOR);
   
   set("age",12);
   set("pur",25);
   set("kar",30);
   set("per",28);
   set("str",20);
	 set("int",25);
	 set("con",20);
	 set("dex",30);
	 set("max_qi", 3000);
	 set("max_jing", 2000);
	 set("eff_jingli", 2000);
	 set("neili", 2000);
	 set("max_neili", 2000);
	 set("jiali", 0);

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("hand",100);
   set_skill("arrow",120);
   set_skill("baibu-chuanyang",120);
   set_skill("suohou-shou",120);
   set_skill("literate",260);
   set_skill("war",140);
   set_skill("political",120);
   map_skill("hand","suohou-shou");
   map_skill("arrow","baibu-chuanyang");

   setup();
   add_money("gold",2);
carry_object("clone/armor/jinduan.c")->wear();
}
