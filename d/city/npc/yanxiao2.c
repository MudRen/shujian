// /d/city/npc/yanxiao2.c ����

inherit NPC;

void create()
{
        set_name("��������", ({ "yan xiao", "yanxiao"}));
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
        carry_object(__DIR__"obj/tiegun")->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 20+random(10));
}
