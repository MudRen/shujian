// yanshang.c ��������

inherit NPC;

void create()
{
        set_name("��������", ({ "dali yanshang", "yanshang", "trader" }));
	set("gender", "����");
        set("age", 32);
        set("long", "����һ��ר�Ž����������õ����������������̡�\n");
	
        set("combat_exp", 3000);
        set("shen_type", 1);

	set("attitude", "peaceful");
	
        set_skill("unarmed", 30);
	set_skill("dodge", 20);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}
