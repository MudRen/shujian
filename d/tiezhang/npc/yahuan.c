// yahuan.c Ѿ��

inherit NPC;

void create()
{
	set_name("Ѿ��", ({ "ya huan", "ya", "yahuan" }));
	set("long", "һ��СѾ�ߣ��ߴ������ӡ�\n");
	set("gender", "Ů��");
	set("age", 17);
	set("per", 23);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	setup();
        carry_object(__DIR__"obj/heiyi")->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
