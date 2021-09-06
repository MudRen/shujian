// bao.c
#include <ansi.h>
inherit F_MASTER;

inherit NPC;

void create()
{
	set_name("鲍大楚", ({ "bao dachu", "bao", "dachu"}));
        set("long", "一个身材瘦削的老者，依相貌根本看不出他是身怀绝艺的高手。\n");
        set("title",HIY"日月神教  "RED"朱雀堂堂主"NOR);
        set("gender", "男性");
        
	set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 27);
        set("int", 27);
        set("con", 27);
        set("dex", 30);
        
        set("max_qi", 3000);
        set("max_jing", 2200);
	      set("eff_jingli", 2200);
	      set("max_neili", 4000);
        set("jiali", 50);
        set("combat_exp", 1700000);

        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("hand", 200);
        set_skill("literate", 130);
        set_skill("ding-dodge",190);
	      set_skill("tianmo-gong", 200);
	      set_skill("tianmo-shou", 190);
     
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
	      map_skill("parry", "tianmo-shou");
	      map_skill("hand", "tianmo-shou");
	      prepare_skill("hand", "tianmo-shou");
	      create_family("日月神教", 9, "弟子");

        setup();

	carry_object(MISC_D("cloth"))->wear();          
}