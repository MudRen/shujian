inherit NPC;
void create()
{
        set_name("Сɳ��", ({ "xiao shami", "xiao","shami" }));
	set("gender", "����");
	set("age", 15);
        set("long", "����һλ���������Сɳ�֡�\n");	
	set("combat_exp", 1000);
        set("shen", 10);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
