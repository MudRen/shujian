// caoyaoren.c ��ҩ��

inherit NPC;
void create()
{
	set_name("��ҩ��", ({ "caiyao ren",  "caiyaoren", "caiyao", "ren" }) );
	set("long", "һ����ҩ�ˡ�\n");
	set("gender","����");

	set("age", 20+random(22));
	set("str", 20);
	set("dex", 24);
	set("con", 20);
	set("int", (10+random(18)) );
	set("attitude", "peaceful");
	set("combat_exp", 25000+random(500));

	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 80);
	set_skill("force", 60);
	set_skill("literate", 100);

	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
	add_money("silver", 5+random(5));
}
