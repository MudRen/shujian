#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("尹志平", ({"yin zhiping", "yin"}));
        set("gender", "男性");
        set("class", "taoist");
        set("nickname", HIM"清和真人"NOR);
        set("age", 24);
        set("long",
                "他是丘处机的得意大弟子尹志平，他粗眉大眼，长的有些英雄气\n"
                "概，在全真教第三代弟子中算得上年轻有为。身材不高，眉宇间\n"
		"似乎有一股忧郁之色。长的倒是长眉俊目，容貌秀雅，面白无须，\n"
		"可惜朱雀和玄武稍有不和。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);


        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 220000);

        set_skill("force", 110);
        set_skill("xiantian-gong", 110);
        set_skill("sword", 100);
        set_skill("quanzhen-jianfa", 100);
        set_skill("dodge", 90);
        set_skill("jinyan-gong", 90);
        set_skill("parry", 110);
        set_skill("strike", 100);
        set_skill("haotian-zhang", 100);
        set_skill("literate",60);
        set_skill("taoism",100);
        set_skill("tiangang-beidouzhen",60);
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教"   :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{     

        if (ob->query("gender")=="女性") {
                command("say 玄门内丹修炼之术，男女有别，我对坤丹修行一无所知，实在做不了你师父。\n");
                return;
        }

     command("say 好吧，我就收下你这个徒弟了。");
     command("recruit " + ob->query("id"));
     command("say 我全真教乃天下玄门正宗，门下弟子都当严谨操守，切不可误入歧途。");
}

