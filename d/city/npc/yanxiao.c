// /d/city/npc/yanxiao.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "yan xiao", "yanxiao", "man" }));
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
        carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", random(10)+10);
}
