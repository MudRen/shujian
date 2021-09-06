#include <ansi.h>;
inherit NPC;
void create()
{
   set_name("哲别",({"zhe bie","zhe","bie"}));
   set("gender","男性");
   set("long","铁木真手下猛将之一,是郭靖的箭术师傅!\n");
   set("shen",200000);
   set("combat_exp",2000000);
   set("title",HIR"神箭手"NOR);
   
   set("age",35);
   set("neili",9000);
   set("max_neili",6000);
   set("pur",22);
   set("per",15);
   set("kar",30);

   set_skill("dodge",200);
   set_skill("force",200);
   set_skill("parry",200);
   set_skill("arrow",300);
	 set_skill("spear", 200);
	 set_skill("medicine", 122);
	 set_skill("literate", 260);
	 set_skill("baibu-chuanyang",300);
	 set_skill("zhong-qiang", 200);
	 set_skill("war",100);
	 map_skill("spear", "zhong-qiang");
	 map_skill("arrow", "baibu-chuanyang");
	 map_skill("parry", "baibu-chuanyang");


   setup();
   add_money("silver",20);
  carry_object(__DIR__"obj/zhanpao")->wear();
  carry_object(__DIR__"obj/tieqiang")->wield();
}
