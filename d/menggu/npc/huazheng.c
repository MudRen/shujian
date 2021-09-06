inherit NPC;
#include <ansi.h>
void create()
{
   set_name("华筝公主",({"huazheng"}));
   set("gender","女性");
   set("long","铁木真的小女儿,郭靖的未婚妻子!\n");
   set("score",30000);
   set("combat_exp",60000);
   set("title",HIC"蒙古郡主"NOR);
   
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
   set_skill("arrow",100);
   set_skill("whip",100);
   set_skill("literate",120);
   set_skill("art",150);
   set_skill("music",120);

   setup();
   add_money("gold",1);
carry_object("clone/armor/yangao.c")->wear();
carry_object("clone/armor/flower_shoe2.c")->wear();
carry_object(__DIR__"obj/whip")->wield();
}
