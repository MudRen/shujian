// xueji.c

inherit NPC;

void create()
{
        set_name("Ñ©¼¦", ({"xue ji","ji"}));
        set("race", "Ò°ÊÞ");
        set("age", 2);
        set("long", "Ò»Ö»·Ê·Ê°×°×µÄÑ©¼¦¡£\n");

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "ºó×¦", "Î²°Í" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);

	set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
       message_vision("$N²Òº¿Ò»Éù£¬ÂýÂýµ¹ÏÂËÀÁË£¡\n", this_object());
       new_ob("../obj/xueji-rou")->move(environment());
       destruct(this_object());
}
