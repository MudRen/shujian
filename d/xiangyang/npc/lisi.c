//shipotianc

inherit NPC;
#include <ansi.h>
int ask_taixuan();


void greeting(object me);

void create()
{
        set_name("李四", ({ "li si", "li", "si" }) );
        set("gender", "男性" );
        set("nickname",HIB"罚恶使者"NOR);
        set("age", 30);
        set("long",
"一个戴着面具的神秘男子。\n"
"脸上面具是一副凶恶的脸。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 25);
        set("shen_type", 1);
  set("no_get", 1);
  set("no_bark", 1);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hand", 200);
        set_skill("cuff",200); 
        
        set_skill("taixuan-gong",200);
        map_skill("force","taixuan-gong");
        map_skill("hand","taixuan-gong");
        map_skill("dodge","taixuan-gong");
        
        map_skill("parry","taixuan-gong");
    prepare_skill("hand", "taixuan-gong");
        set("combat_exp", 1000000);
        set("max_qi", 30000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("eff_jingli",3000);
        set("qi",30000);
        set("jing",3000);
        set("jingli",3000);
        set("neili", 5000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       (: exert_function, "taixuan" :),
       (: perform_action, "hand.po" :),
       (: perform_action, "hand.xuan" :),
     }));

 
        setup();
        
        carry_object("/clone/armor/cloth.c")->wear();
} 
