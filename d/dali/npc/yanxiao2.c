// yanxiao2.c ��������
inherit NPC;

void create()
{
        set_name("��������", ({ "yanxiao laozhe", "yanxiao", "oldman" }));
	set("gender", "����");
        set("age", 50);
        set("long", "��װ�������ײ���ͷ�����������������������\n");
	
        set("combat_exp", 24000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
        set_skill("dodge", 55);
        set_skill("staff", 60);
        set_skill("unarmed", 50);
        set_temp("apply/attack", 25);
	set_temp("apply/defense", 20);

	setup();
        carry_object("/clone/weapon/tiegun")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}
