// jinsq.c ½ğË¿È¸

inherit NPC;
void create()
{
        set_name("½ğË¿È¸", ({ "jinsi que", "bird" }) );
        set("race", "Ò°ÊŞ");
        set("age", 1);
        set("long", "Ò»Ö»ÃÀÀöµÄ½ğË¿È¸£¬ß´ß´ÔûÔûµÄ½Ğ×Å£¬¸èÉùÔÃ¶ú¶¯Ìı¡£\n");
        set("attitude", "friendly");
        set("max_qi", 100);
        set("max_jing", 100);
        set("eff_jingli", 100);
        set("limbs", ({ "×ì", "³á°ò", "×¦×Ó" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);
        set("chat_chance", 3);
        set("chat_msg", ({ (: random_move :),}) );
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5);
        set("senlin", 1);
        setup();
}

