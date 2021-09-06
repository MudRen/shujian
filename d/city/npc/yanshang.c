// yanshang.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "yan shang", "yanshang", "shang ren", "trader"}));
	set("gender", "����");
	set("age", 32+random(20));
	set("long", "����һ�����������ε����̣�ÿ�ε�����һ��ȥ��������ϯ�μˡ�\n");

	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("dodge", 20);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 10);
}
