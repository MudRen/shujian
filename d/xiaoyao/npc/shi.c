//dadi.c 任务使
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;


void create()
{
        set_name("任务使", ({ "renwu shi", "shi", "renwu"}));
        set("title", HIC"逍遥派"NOR);
        set("gender", "男性" );
        set("age", 102);
        set("str", 50);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"一位的任务使。专门负责给本派弟子各种任务.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
       

         map_skill("hand","zhemei-shou");
      
}