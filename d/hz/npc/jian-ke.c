// jian-ke.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "jian ke","ke" }) );
	set("gender", "����");
	set("age", 45);
	set("long",
		"����λ�������ˣ��米�����������Ľ������Ʈ������ƺ������ա�\n");
	set("combat_exp", 21000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();

        carry_object(BINGQI_D("changjian"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 20);
}
