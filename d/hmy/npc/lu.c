#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()

{
	set_name("������", ({ "lu zhuweng", "lu", "zhuweng"}));
        set("long", 
"���������黭��һ�������������ڻ����书��ξͲ��ö�֪�ˡ�\n");
        set("gender", "����");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
       
	set("max_qi", 2000);
	set("qi", 2000);
  set("max_jing", 1300);
	set("jing", 1300);
  set("neili", 2000);
	set("max_neili", 2000);
	set("eff_jingli", 1400);
	set("jingli", 1400);
  set("jiali", 50);
  set("combat_exp", 400000);
  
  set_skill("dodge",140);
  set_skill("parry",140);
  set_skill("force",140);        
  set_skill("tianmo-gong",140);
  set_skill("ding-dodge",100);
  set_skill("literate", 150);
	set_skill("tianmo-zhang", 140);
	set_skill("strike", 140);

  map_skill("dodge", "ding-dodge");
  map_skill("force", "tianmo-gong");	
	map_skill("strike", "tianmo-zhang");
	map_skill("parry", "tianmo-zhang");
	prepare_skill("strike","tianmo-zhang");
	create_family("�������",9,"����");
	
   setup();
        
  carry_object(ARMOR_D("cloth"))->wear();
}
