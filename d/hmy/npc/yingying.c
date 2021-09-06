// yingying.c
// Finish by action@SJ 2009.1.6
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        
        set_name("任盈盈", ({ "ren yingying","ren","yingying" }));
        set("long", "她容貌秀丽绝伦，不过十七八岁年纪，娇羞之态，娇美不可方物。\n");
        set("nickname", HIR"小魔女"NOR);
        set("title", HIY"日月神教  圣姑"NOR);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("age", 18);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("unique", 1);
        set("location", 1);
        set_temp("no_return", 1);

        set("max_qi", 1500);
        set("qi", 1500);
        set("jing", 1300);
        set("max_jing", 1300);
        set("neili", 2400);
        set("max_neili", 2400);
        set("eff_jingli", 1700);
        set("jingli", 1700);
        set("jiali", 50);
        set("combat_exp", 180000);
        set("shen", -1200);

        set_temp("apply/attack", 40);
        set_temp("apply/defence", 40);

        set_skill("tianmo-zhang",300);
        set_skill("tianmo-gun",300);
        set_skill("tianmo-dao",300);
        set_skill("strike", 300);
        set_skill("parry", 300);
        set_skill("dodge",300);
        set_skill("ding-dodge", 300);
        set_skill("tianmo-shou", 300);
        set_skill("force", 300);
        set_skill("blade",300);
        set_skill("club",300);
        set_skill("tianmo-gong", 300);
        set_skill("tianmo-jue", 200);
        set_skill("art", 160);

        map_skill("strike", "tianmo-zhang");
        map_skill("hand", "tianmo-shou");
        map_skill("club", "tianmo-gun");
        map_skill("blade", "tianmo-dao");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        map_skill("parry", "tianmo-zhang");
        prepare_skill("strike", "tianmo-zhang");
        set("inquiry", ([

        ]));

        create_family("日月神教", 8, "长老");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingshen" :),
                (: exert_function, "powerup" :),
        }));

        setup();

        carry_object("/clone/misc/cloth")->wear();     
        	carry_object(BINGQI_D("blade"))->wield();    
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
     ob->set("title",HIW"日月神教圣姑座下弟子"NOR);
}

