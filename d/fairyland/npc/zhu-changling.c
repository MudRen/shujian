// zhu-changling.c 

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Öì³¤Áä", ({"zhu changling", "zhu"}));
	set("title", HIR"ºìÃ·É½×¯×¯Ö÷"NOR);
	set("gender", "ÄĞĞÔ");
	set("age", 45);
        set("unique", 1);

	set_skill("unarmed", 60);
	set_skill("force", 50);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 70000);
	set("shen_type", -1);
	setup();
	add_money("silver", 50);
}

