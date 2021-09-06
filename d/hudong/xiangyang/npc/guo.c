#include <ansi.h>
inherit NPC;
#include "boss.h"

void create()
{
        set_name("郭靖", ({"guo jing", "guo", "jing", "zhengfang"}));
        set("nickname", HIY"北侠"NOR);
        set("gender", "男性");
        set("age", 40);
        set("long", "他就是威振天下的大侠郭靖，第二次华山论剑后号称“北侠”。\n");
        set("attitude", "friendly");
        set("str", 50);
        set("int", 10);
        set("con", 50);
        set("dex", 25);

        set("unique", 1);  //唯一性
     
        set("max_qi", 200000);
        set("max_jing", 20000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 200);
        set("eff_jingli",20000);
        set("combat_exp", 10000000);

        set_skill("force", 500);
        set_skill("finger",500);
        set_skill("tanzhi-shentong",500);
        set_skill("yiyang-zhi",500);
        set_skill("claw",500);
        set_skill("jiuyin-baiguzhua",500);
        set_skill("huntian-qigong", 500);
        set_skill("strike", 500);
        set_skill("xianglong-zhang", 500);
        set_skill("dodge", 500);
        set_skill("jinyan-gong", 500);
        set_skill("parry", 500);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xianglong-zhang");
        map_skill("finger","tanzhi-shentong");
        map_skill("claw", "jiuyin-baiguzhua");
        prepare_skill("strike", "xianglong-zhang");

        set("inquiry", ([
       
        ]) );

        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("xlz/hang",1);
        set("max_cure",5);
        set_temp("互动任务/襄阳大战/阵营",1);

        set_temp("apply/damage",500);
        set_temp("apply/damage_force",500);
        set_temp("apply/armor",500);
        set_temp("apply/armor_force",500);
        set_temp("double_attack",1);
    

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: perform_action,  "strike.xiao" :),
                (: perform_action, "strike.paiyun" :),
                (: perform_action, "strike.kanglong" :),
        }));
        create_family("丐帮", 18, "帮主亲传弟子");
        setup();

        if (clonep()) carry_object("/d/thd/obj/grn-cloth.c")->wear();
}
