// chou.c 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "chou songnian", "chou",}));
        set("nickname", "����ͷ��");        
        set("long", "��ͷ�ӳ������磬ͷ�ϴ���һ�����������ͭ�������ų�����\n");
        set("title",HIY"�������  "RED"��ȸ������"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 32);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 2700);
        set("max_jing", 1800);
	      set("eff_jingli", 1800);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", 5000);

        set_skill("dodge",180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("strike", 200);
        set_skill("literate", 130);
        set_skill("ding-dodge",190);
	      set_skill("tianmo-gong", 200);
	      set_skill("tianmo-zhang", 190);
     
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
	      map_skill("parry", "tianmo-zhang");
	      map_skill("strike", "tianmo-zhang");
	      prepare_skill("strike", "tianmo-zhang");
	      create_family("�������", 9, "����");
	
        setup();
        
	carry_object(MISC_D("cloth"))->wear();        
}
