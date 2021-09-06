// kezhene.c 柯镇恶
// Created by Zhuifeng@sjfy 08/8/2010

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("柯镇恶",({"ke zhene","ke","zhene"}));
   set("gender","男性");
   set("long","蒙古王子\n");
   set("shen",90000);
   set("combat_exp",1800000);
   set("nickname",HIC"飞天蝙蝠"NOR);
   set("title",WHT"江南七怪之首"NOR);
   
   set("age",40);
   set("pur",30);
   set("kar",35);
   set("per",20);
   set("str",30);
	 set("int",25);
	 set("con",20);
	 set("dex",30);
	 set("max_qi", 6000);
	 set("max_jing", 4000);
	 set("eff_jingli", 4000);
	 set("neili", 4000);
	 set("max_neili", 4000);
	 set("jiali", 90);

   set_skill("dodge",240);
   set_skill("force",240);
   set_skill("parry",240);
   set_skill("strike",240);
   set_skill("staff",280);
   set_skill("fengmo-zhang",240);
   set_skill("literate",160);
   set_skill("feitianshu",240);
   map_skill("dodge","feitianshu");
   map_skill("staff","fengmo-zhang");

   setup();
   add_money("silver",80);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tiezhang")->wield();
}
