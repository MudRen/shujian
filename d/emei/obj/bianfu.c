// animal: bianfu
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("òùòð", ({ "bian fu", "fu" }) );
        set("race", "Ò°ÊÞ");
        set("age", 20);
        set("long", "Ò»Ö»òùòðµ¹¹ÒÔÚÊ¯¶´±ÚÉÏ¡£\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "Í·²¿", "¾±²¿", "ºó±³", "¸¹²¿", "½Å×¦", "³á°ò" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 400);

        setup();
}
/*
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}

void die()
{
        object ob;
        message_vision("$N°¡~~µÄÒ»ÉùËºÁÐµÄ½ÐÉùËÀÁË¡£\n", this_object());
        destruct(this_object());
}
*/