#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create()
{
      
	set_name("�Ʋ���", ({ "huang boliu", "huang", "boliu"}));
	set("nickname", "������");        
        set("long", 
"��һ�����룬ֱ�����أ�����ȴ�����塣��\n");
        set("title",HIY"�������  "HIC"����������"NOR);
        set("gender", "����");
        
	set("age", 70);
	set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 2500);
        set("max_jing", 1500);
        set("eff_jingli", 1500);
        set("jiali", 50);
        set("combat_exp", 1200000);
     
        set_skill("parry",170);
        set_skill("dodge",170);
        set_skill("force",170);
        set_skill("strike",170);
        set_skill("literate", 100);      
        set_skill("ding-dodge",170);
        set_skill("tianmo-gong",170);
        set_skill("tiangang-zhang",170);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        map_skill("parry", "tiangang-zhang");
        map_skill("strike", "tiangang-zhang");
        prepare_skill("strike", "tiangang-zhang");
        
	      create_family("�������",9,"����");
        setup();
}
