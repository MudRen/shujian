// liumang.c ��Ʀ

inherit NPC;

void create()
{
	set_name("�����Ʀ", ({ "dali dipi", "dipi", "pi" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ֺ��еĵ�Ʀ��\n");
	
	set("combat_exp", 1500);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();	
}
