// sang.c
#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("ɣ����", ({ "sang sanniang", "sang", "sanniang"}));
	set("long", 
"һ����ò��������긾�ˣ���ɱ�������ĺ���������������\n");
	set("title",HIY"�������  "HIW"�׻�������"NOR);
  set("gender", "Ů��");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
                
  set("max_qi", 3000);
  set("max_jing", 2200);
	set("eff_jingli", 2200);
  set("jiali", 50);
  set("combat_exp", 1700000);
  set("shen", -5500);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

  set_skill("tianmo-zhang",200);
	set_skill("strike", 200);
	set_skill("literate", 100);
  set_skill("dodge",200);
	set_skill("ding-dodge", 200);
	set_skill("force", 200);
	set_skill("tianmo-gong", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("cihang-bian", 200);

  map_skill("strike", "tianmo-zhang");
  map_skill("dodge", "ding-dodge");
  map_skill("force", "tianmo-gong");
	map_skill("parry", "tianmo-zhang");
	map_skill("whip", "cihang-bian");
	prepare_skill("strike", "tianmo-zhang");
	create_family("�������",8,"����");
	
        setup();
        
  carry_object(BINGQI_D("changbian"))->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
