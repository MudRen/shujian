// lao.c
#include <ansi.h>

inherit NPC;

void create()
{
      
	set_name("��ͷ��", ({ "lao touzi", "lao", "touzi",}));
	set("nickname", "�ƺ�����");        
  set("long", "������ļ�֮���֣�Զ������һ������㣬����ȴ��֮���飬�����������Ѹ�١�\n");
  set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen", 10000);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 40);
        
  set("max_qi", 2300);
  set("max_jing", 1400);
	set("eff_jingli", 1400);
  set("jiali", 50);
  set("combat_exp", 1000000);
  set("shen", -4000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

  set_skill("tianmo-jian",150);
	set_skill("sword", 150);
  set_skill("dodge",150);
	set_skill("ding-dodge", 150);
	set_skill("force", 150);
	set_skill("literate", 100);
	set_skill("tianmo-gong", 150);
	set_skill("tianmo-zhang", 150);
	set_skill("strike", 150);
	
	map_skill("parry", "tianmo-jian");
  map_skill("sword", "tianmo-jian");
  map_skill("dodge", "ding-dodge");
  map_skill("force", "tianmo-gong");
  map_skill("strike", "tianmo-zhang");
  prepare_skill("strike", "tianmo-zhang");

   setup();
 
	carry_object(BINGQI_D("panguanbi"))->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
