// NPC: /d/huashan/npc/laodenuo.c
// Date: Look 99/03/25
// Lklv Modify at 2001.10.18
// By Spiderii@yt修改俸禄
inherit NPC;

#include <ansi.h>

string ask_me(object who);
//int ask_gold(object who);

void create()
{
        set_name("劳德诺", ({ "lao denuo", "lao", "denuo" }));
        set("nickname", "老好人");
        set("long",
"劳德诺身材矮胖，满面红光，成天笑眯眯的，他在\n"
"同门中排行第二，是华山派年轻一代中唯一带艺投师的。\n");
        set("gender", "男性");
        set("age", 54);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 24);
        set("per", 18);
        set("int", 25);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 30000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("eff_jingli", 1800);

        set("jiali", 50);
        set("combat_exp", 600000);
        set("score", 6000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("cuff", 100);
        set_skill("hand", 100);
        set_skill("songshan-jian", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("poyu-quan", 100);
        set_skill("hanbing-zhenqi", 100);
        set_skill("songyang-shou", 100);
        set_skill("zhengqi-jue", 100);
        set_skill("zixia-gong", 100);

        map_skill("hand", "songyang-shou");
        map_skill("dodge", "huashan-shenfa");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("cuff", "poyu-quan");

  
        set("inquiry", ([
              "紫霞秘籍"   : (: ask_me :),
                //"左掌门" : (: ask_gold :),
        ]) );

        create_family("华山派", 14, "弟子");

        setup();
        carry_object(BINGQI_D("sword/sword"))->wield();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_me(object who)
{
        int i;
        object *ob,book;

        if( (random(10) < 8) || is_fighting() )
                return "对不起，这件事，我不清楚，你还是问我师傅去吧！\n";
        set_temp("apply/attack",  500);
        set_temp("apply/defense", 500);
        set_temp("apply/damage",  500);
      
        
   
        set("neili", 60000);
        set("max_neili", 30000);
        set("eff_jingli", 8000);
        set("jingli",8000);
        set("jiali", 150);
        
        set("combat_exp",8000000);


        set_skill("force", 400);
        set_skill("songshan-qigong", 400);
        set_skill("dodge", 400);
        set_skill("zhongyuefeng", 400);
        set_skill("strike", 390);
        set_skill("songyang-zhang", 390);
        set_skill("parry", 390);
        set_skill("sword", 390);
        set_skill("songshan-jian", 395);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 450);
        map_skill("force", "hanbing-zhenqi");
        map_skill("dodge", "zhongyuefeng");
        map_skill("strike", "hanbing-shenzhang");
        map_skill("parry", "songshan-jian");
        map_skill("sword", "songshan-jian");

      prepare_skill("strike", "hanbing-shenzhang"); 



        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "strike.hanbing" :),
                (: exert_function, "juhan" :),
                (: random_move :),
        }));


        set("chat_chance", 70);
        set("chat_msg", ({
                (: random_move :)
        }) );

        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !userp(ob[i]) ) continue;
                if( ob[i]->query_temp("hs/askzixia",1) && ob[i]->query("quest/zixia/pass"))
                        {
                         ob[i]->delete_temp("hs/askzixia");
                        book = unew(__DIR__"obj/zixia");
                        if( clonep(book) ) {
                        book->move(this_object());
                        }
                  }
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
               
       message("vision",
                YEL "看来这件事你都知道了？臭贼，去死吧！\n"
                "劳德诺使开长剑，招数精奇，狠辣无比，一改整日笑咪咪的模样。\n" NOR,
                environment(), this_object() );
      
      
       return "我带艺投师，忍辱负重，你竟敢打我的主意，去死吧！\n";
                
        }
        
   
    
        return "对不起，这件事，我不清楚，你还是问我师傅去吧！\n";
}
