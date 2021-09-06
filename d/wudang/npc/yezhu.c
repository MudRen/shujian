// NPC : /d/wudang/npc/yezhu.c Ò°Öí

inherit NPC;
void create()
{
        set_name("Ò°Öí", ({ "ye zhu","zhu" }) );
        set("race", "Ò°ÊÞ");
        set("age", 6);
        set("con", 100);
        set("str", 100);
        set("long", "Ò»Ö»ÑÛ¾¦ÑªºìµÄÒ°Öí¡£\n");
        set("attitude", "aggressive");
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "ºó×¦", "Î²°Í" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 250000);
	 set_temp("apply/attack", 30);
	 set_temp("apply/defense", 50);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        setup();
}

void die()
{
	object ob;
	message_vision("$NÆà²ÒµÄº¿ÁË¼¸Éù£¬ËÀÁË¡£\n", this_object());
        ob = new(FOOD_D("yzhurou"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
