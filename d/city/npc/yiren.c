// yiren.c ����

inherit NPC;

void create()
{
        string gender;

        set_name("��������", ({ "yi ren", "yiren" }));
        gender = random(2)?"����":"Ů��";
	set("gender", gender);
        set("age", 23+random(10));
        set("long", "һ�����ϴ����Ľ������ˡ�\n");

	set("combat_exp", 7000);
        set("shen_type", 0);
	set("attitude", "peaceful");

	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 10);
}