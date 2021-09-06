// xiang-ke.c �����

inherit NPC;

void create()
{
	int value;

	value = random(10);

	set_name("�����", ({ "jinxiang ke", "ke", "guest" }));
	set("gender", "����");
	set("age", 14 + value * 3 );
	set("combat_exp", 15000 + 2000 * value);
	set("shen_type", 0);

	set_temp("apply/armor", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 20);

	setup();
	add_money("silver", 1 + value);
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}
