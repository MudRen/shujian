//xtong1.c Сͯ

inherit NPC;

void create()
{
	set_name("Сͯ", ({ "xiao tong", "xiao","tong"}) );
	set("gender", "����" );
	set("age", 15);
	set("long",
		"���Сͯ���������е�һ�������ϴ����˯��\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",random(50));
}
