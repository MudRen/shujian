
inherit NPC;

void create()
{
	set_name("ˮ��", ({ "shui bing", "shui", "bing" }));
	set("shen_type", 1);

	set("gender", "����");
	set("age", 20);
	set("long", "һ�����̴���ˮ����\n");
	set_skill("cuff", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 30);

	set("combat_exp", 16000+random(5000));
	set("attitude", "friendly");

	setup();
	add_money("silver", random(50));
	carry_object(ARMOR_D("armor"))->wear();
}
