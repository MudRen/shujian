// zhou.c

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("�ܹ�ͩ", ({ "zhou gutong", "zhou", "gutong"}));
        set("nickname", "ͩ��˫��");        
        set("long", 
"����һ��Ʒ�Ƶ����϶��㷢��һ����Ц��\n");
        set("title",HIY"�������  "RED"��ȸ�ö���"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 2500);
        set("max_jing", 1400);
	set("eff_jingli", 1700);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("shen", -1200);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-zhang",100);
	set_skill("strike", 100);
	set_skill("literate", 80);
        set_skill("dodge",100);
	set_skill("ding-dodge", 100);
	set_skill("force", 100);
	set_skill("tianmo-gong", 100);
	set_skill("parry", 100);

        map_skill("strike", "tianmo-zhang");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
	map_skill("parry", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");
	create_family("�������",9,"����");

	
        setup();

	carry_object(MISC_D("cloth"))->wear();        
}
