// yaoxiao ��������

inherit NPC;

void create()
{
        set_name("��������", ({ "dali yanxiao", "yanxiao" }));
	set("gender", "����");
        set("age", 35);
        set("long", "��װ�������ײ���ͷ��������������������λεĸֵ���\n");
	
        set("combat_exp", 13000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
        set_skill("dodge", 45);
        set_skill("blade", 45);
        set_skill("unarmed", 50);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
        carry_object("clone/weapon/blade")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}
