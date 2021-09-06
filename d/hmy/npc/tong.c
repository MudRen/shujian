// Finish by Numa@SJ 2000.8

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("童百熊", ({ "tong baixiong", "tong", "baixiong"}));
        set("long", "一名须法俱白的老者，身材魁梧，双目炯炯有神，\n"+
        	"他掌管着日月教风雷堂，负责着教中所有对外的事务。\n");
        set("title",HIY"日月神教 "HIC"风雷堂主"NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 38);

        set("max_qi", 3500);
        set("max_jing", 2200);
        set("eff_jingli", 2200);
        set("jiali", 100);
        set("combat_exp", 1800000);
        set("shen", -1);

        set_skill("parry", 210);
        set_skill("dodge", 210);
        set_skill("force", 210);
        set_skill("blade", 210);
        set_skill("ding-dodge", 210);
        set_skill("tianmo-dao", 210);
        set_skill("tianmo-gong", 210);
        set_skill("strike", 210);
        set_skill("luoying-zhang", 210);
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        map_skill("blade", "tianmo-dao");
        map_skill("parry", "luoying-zhang");
        map_skill("strike", "luoying-zhang");
        prepare_skill("strike", "luoying-zhang");
        create_family("日月神教",8,"弟子");

        
        set("inquiry", ([
        ]));
        
        setup();
 
        carry_object(MISC_D("cloth"))->wear();
}





