// xiang.c 向问天
// Finish by action@SJ 2009.1.6
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("向问天", ({ "xiang wentian", "xiang", "wentian"}));
        set("long", "只见他容貌清瘦，身形高大，颏下疏疏朗朗一丛花白长须，垂在胸前，\n"+
		"背上负着一个包袱，再看他腰间时，却无弯刀。\n");
        set("title",HIY"日月神教 "HIW"光明左使"NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 4000);
        set("max_jing", 2200);
        set("eff_jingli", 2500);
        set("jiali", 100);
        set("combat_exp", 2000000);

        set_skill("strike", 220);
        set_skill("hand", 220);
        set_skill("club", 220);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("force", 220);
        set_skill("literate", 160);

        set_skill("tianmo-gun",220);
        set_skill("tianmo-zhang",220);
        set_skill("tianmo-shou",200);
        set_skill("ding-dodge",220);
        set_skill("tianmo-gong",220);
        set_skill("tianmo-jue",200);

        map_skill("force", "tianmo-gong");
        map_skill("parry", "tianmo-gun");
        map_skill("hand", "tianmo-shou");
        map_skill("club", "tianmo-gun");
        map_skill("dodge", "ding-dodge");
        map_skill("strike", "tianmo-zhang");
        prepare_skill("strike", "tianmo-zhang");
        
        set("chat_chance", 3);
        set("chat_msg", ({
		        "向问天拿起酒壶，灌了一大口，道：“好酒！”\n",
        }));
               create_family("日月神教", 8, "长老");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "club.luanwu" :),
                (: exert_function, "powerup" :),
        }));
        setup();

        carry_object(MISC_D("cloth"))->wear();  
        carry_object(BINGQI_D("club"))->wield();      
}

void attempt_apprentice(object ob)
{
     if(ob->query_skill("tianmo-gong",1) < 160 ||
      ob->query_skill("tianmo-zhang",1) < 160 ||
        ob->query_skill("tianmo-shou",1) < 160){
        command("say 你的武功还不够娴熟，再回去练练吧。");
        return;
        }
     command("say 好，我正想招兵买马救教主出来，看来你还不错嘛，就收下你了。");
     command("recruit " + ob->query("id"));
     ob->set("title",HIY"日月神教光明左使座下堂主"NOR);
}