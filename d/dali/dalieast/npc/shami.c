// Modify By River 98/12
inherit NPC;

void create()
{
        set_name("Сɳ��", ({ "xiao shami", "xiao","shami" }));
	set("gender", "����");
	set("age", 19);
        set("long", "����һ��Сɳ�֡�\n");
	
	set("combat_exp", 1000);
        set("shen_type", 100);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}
