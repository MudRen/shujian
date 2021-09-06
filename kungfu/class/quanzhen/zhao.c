// zhao.c 赵志敬
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("赵志敬", ({"zhao zhijing", "zhao"}));
        set("gender", "男性");
        set("age", 26);
        set("class", "taoist");
        set("long",
                "他就是全真教第三代弟子中的好手，王处一的大弟子赵志敬。 \n"
                "他相貌端正，但眉宇间似乎隐藏着一丝狡猾的神色。\n"
		"他是一个长须道人，看起来却有些煞气。\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);

        set_skill("force", 100);
        set_skill("xiantian-gong", 100);
        set_skill("sword", 100);
        set_skill("quanzhen-jianfa",100);
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);
        set_skill("parry", 100);
        set_skill("strike",100);
        set_skill("haotian-zhang", 100);
        set_skill("literate", 60);
        set_skill("taoism", 60);      
        set_skill("tiangang-beidouzhen", 40);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",          
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
}