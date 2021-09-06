// dao-ke.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "dao ke","ke"}) );
	set("gender", "����");
	set("age", 20);
	set("long",
		"��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 25000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 45);
	set_skill("blade", 45);
	set_skill("parry", 40);
	set_skill("dodge", 40);

	setup();

        carry_object(BINGQI_D("gangdao"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 10);
}
