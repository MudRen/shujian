// jia.c ������
// by pishou

inherit NPC;

void create()
{
    set_name("������", ({ "jia laolu", "jia" }));
	set("gender", "����");
    set("age", 35);
    set("long", "������ػ�ļ�������\n");
	
    set("combat_exp", 10000);
    set("shen_type", 1);
	set("attitude", "peaceful");
	
    set_skill("strike", 60);
	set_skill("dodge", 40);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
