#include <ansi.h>
inherit NPC;

void create()
{
        set_name("yeah", ({ "douzhuan npc", "npc"}));
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("str", 40);
        set("int", 40);
        set("con", 30);
        set("dex", 20);
         set("env/invisibility", 1);
        set("location", 1);
        set("no_quest", 1);
        set("max_qi", 50000);
        set("max_jing", 50000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 20);
        set("combat_exp", 1000);
        setup();
        carry_object("/d/gumu/obj/yfzhen");
}

void die()
{
        set("max_qi", 50000);
        set("eff_qi", 50000);
        set("qi", 50000);
	this_object()->remove_all_killer();
	this_object()->remove_all_enemy();
	call_out("delme",5);
}
void delme() {
        destruct(this_object());
}
void unconcious(){ die(); }
