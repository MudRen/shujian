// xiansheng.c ��������
inherit NPC;

void create()
{
	set_name("��������", ({ "xian sheng", "teacher" , "xiansheng" }));
	set("long", "������Ľ�ݼ������Ľ���������\n");
	set("gender", "����");
	set("age", 65);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 120000);
	set("shen_type", 1);
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}
