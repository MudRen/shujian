inherit NPC;
#include <ansi.h>
void create()
{
   set_name("��ľ��",({"tiemuzhen","dahan"}));
   set("gender","����");
   set("long","��ľ�����ɹŲ�ԭ�ĳɼ�˼����\n");
   set("nickname",HIY"��Į��ӥ  "HIG"��ԭ����"NOR);
   set("title",HIW"�ɼ�˼��"NOR);
   set("shen",25000);
   set("combat_exp",500000);
   set("age",45);
   set("pur",30);
   set("kar",30);
   set("per",25);
   set("neili",30000);
   set("max_neili",50000);

   set_skill("dodge",260);
   set_skill("force",260);
   set_skill("parry",260);
   set_skill("yingzhua-shou",300);
   set_skill("blade", 200);
   set_skill("arrow",120);
	 set_skill("spear", 400);
	 set_skill("medicine", 60);
	 set_skill("literate", 300);
	 set_skill("baibu-chuanyang",120);
	 set_skill("zhong-qiang", 400);
	 set_skill("war",300);
	 set_skill("political",280);
	 map_skill("spear", "zhong-qiang");
	 map_skill("arrow", "baibu-chuanyang");
	 map_skill("parry", "zhong-qiang");
	 map_skill("hand", "yingzhua-shou");
	 prepare_skill("hand", "yingzhua-shou");


	setup();
   
	add_money("gold",10);
}




