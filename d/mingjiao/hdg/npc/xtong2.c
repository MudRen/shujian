//xtong2.c Сͯ

inherit NPC;

void create()
{
	set_name("Сͯ", ({ "xiao tong", "xiao","tong"}) );
	set("gender", "����" );
	set("age", 16);
	set("long",
		"����һ������Сͯ�����������Ӷ���¯��ɿ�š�\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",random(50));
}
