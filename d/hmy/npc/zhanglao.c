// zhanglao.c
// Finish by action@SJ 2009.1.6
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("魔教长老", ({ "zhang lao", "zhanglao", "lao"}));
        set("long", "此人乃日月神教十大长老之一，武功深不可测。\n"+
		    "而他更痴迷于琴曲之道，琴艺可以称得上是当世第一人.\n");
        set("title",HIY"日月神教"NOR);
        set("gender", "男性");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 4000);
        set("eff_jingli", 4000);
        set("jiali", 90);
        set("combat_exp", 2000000);
        set("shen", -1000);
       
        set_skill("strike", 400);
        set_skill("hand", 400);
        set_skill("blade", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("force", 400);
        set_skill("literate", 160);

        set_skill("tianmo-dao",400);
        set_skill("tianmo-zhang",400);
        set_skill("tianmo-shou",200);
        set_skill("ding-dodge",400);
        set_skill("tianmo-gong",400);
        set_skill("tianmo-jue",200);

        map_skill("force", "tianmo-gong");
        map_skill("strike", "tianmo-zhang");
        map_skill("parry", "tianmo-gun");
        map_skill("hand", "tianmo-shou");
        map_skill("blade", "tianmo-dao");
        map_skill("dodge", "ding-dodge");
        map_skill("strike", "tianmo-zhang");
        prepare_skill("strike", "tianmo-zhang");
        create_family("日月神教", 8, "长老");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingshen" :),
                (: exert_function, "powerup" :),
        }));
	
        setup();
        
	carry_object(MISC_D("cloth"))->wear();  
	carry_object(BINGQI_D("blade"))->wield(); 
}
