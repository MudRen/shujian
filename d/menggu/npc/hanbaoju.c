// hanbaoju.c ������
// Created by Zhuifeng@sjfy 08/8/2010

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("������",({"han baoju","han","baoju"}));
   set("gender","����");
   set("long","�����߹�����,���һ�ֽ����޷�\n");
   set("shen",80000);
   set("combat_exp",1200000);
   set("nickname",HIB"������"NOR);
   set("title",WHT"�����߹�����"NOR);
   
   set("age",29);
   set("pur",28);
   set("kar",15);
   set("per",23);
   set("str",26);
	 set("int",20);
	 set("con",25);
	 set("dex",18);
	 set("max_qi", 3000);
	 set("max_jing", 2000);
	 set("eff_jingli", 2000);
	 set("neili", 2000);
	 set("max_neili", 2000);
	 set("jiali", 20);

   set_skill("dodge",210);
   set_skill("force",210);
   set_skill("parry",210);
   set_skill("whip",210);
   set_skill("jinlong-bianfa",220);
   set_skill("literate",50);
   set_skill("xiaoyaoyou",200);
   map_skill("dodge","xiaoyaoyou");
   map_skill("whip","jinlong-bianfa");

   setup();
   add_money("silver",70);
carry_object(__DIR__"obj/cloth")->wear();
carry_object("clone/weapon/changbian")->wield();
}
