// bing.c Ãç±ø

inherit NPC;

void create()
{
	set_name("Ãç±ø", ({ "miao bing", "bing" }));
	set("age", 22);
	set("gender", "ÄĞĞÔ");
	set("long", "ÕâĞ©Ãç±ø·Ç³£Ğ×º·¡£\n");
	set("attitude", "peaceful");
 

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 30000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);

 
	setup();
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("junfu"))->wear();
}
