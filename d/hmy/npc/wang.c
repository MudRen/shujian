// wang.c
#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("����", ({ "wang cheng", "wang",}));
        set("long", "������İ��֣�������Ц����ʵΪ��ʮ�ֺݶ���\n");
        set("title",HIY"�������  "HIC"����������"NOR);        
        set("gender", "����");
        set("age", 50);
        set("attitude", "heroism");
        set("vendetta_mark", "authority");        
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 2800);
        set("max_jing", 1400);
        set("eff_jingli", 1500);
        set("jiali", 50);
        set("combat_exp", 1000000);

        set_skill("sword", 150); 
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("tianmo-gong", 150);
        set_skill("force", 150);
	set_skill("tianmo-jian", 150);
        set_skill("ding-dodge", 150);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "tianmo-gong");
	map_skill("parry", "tianmo-jian");
	map_skill("sword", "tianmo-jian");
	create_family("�������",9,"����");

        setup();

	carry_object(BINGQI_D("changjian"))->wield();
	carry_object(MISC_D("cloth"))->wear();
}

