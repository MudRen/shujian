// shang_gp.c
// Created by Numa 19991022

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
  set_name("�Ϲ���", ({ "shangguan peng", "peng","shangguan"}));
  set("long", "ֻ�������ֳ��ţ�˫Ŀ������ã��������ơ�\n");
  set("title",HIY"�������  "HIR"�����ܹ�"NOR);
  set("gender", "����");
  set("age", 40);
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
  set("combat_exp", 1800000);
  set("shen", -5000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

	set_skill("cuff",200);
	set_skill("leg",200);
  set_skill("dodge",200);
	set_skill("ding-dodge", 200);
	set_skill("literate", 120);
	set_skill("force", 200);
	set_skill("tianmo-gong", 200);
	set_skill("parry", 200);
	set_skill("tianmo-zhang", 200);
	set_skill("tianmo-shou", 200);

  map_skill("dodge", "ding-dodge");
  map_skill("force", "tianmo-gong");
	map_skill("parry", "tianmo-zhang");
	map_skill("strike", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");
	create_family("�������",9,"����");

        setup();
        
	carry_object("/clone/misc/cloth")->wear();        
}
