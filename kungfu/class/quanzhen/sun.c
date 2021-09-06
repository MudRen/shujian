// sun.c 孙不二

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("孙不二", ({"sun buer", "sun"}));
        set("gender", "女性");
        set("age", 33);
        set("class", "taoist");
        set("nickname",CYN"清净散人"NOR);
        set("long",
                "她就是全真教二代弟子中唯一的女弟子孙不二孙真人。她本是\n"
                "马钰入道前的妻子，道袍上绣着一个骷髅头。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("title","全真七子之末");

        set("qi", 3700);
        set("max_qi", 3700);
        set("jing", 1800);
        set("max_jing", 1800);
        set("neili", 4100);
        set("max_neili", 4100);
        set("jiali", 100);

        set("combat_exp", 660000);

        set_skill("force", 280);
        set_skill("xiantian-gong", 220);
        set_skill("sword", 220);
        set_skill("quanzhen-jianfa",220);
        set_skill("dodge", 250);
        set_skill("jinyan-gong", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("haotian-zhang", 250);
        set_skill("literate",200);
        set_skill("taoism",200);
	      set_skill("tiangang-beidouzhen", 250);
	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

        if (ob->query("gender")=="男性") {
                command("say 我不收男徒，你还是去拜我几位师兄为师吧。\n");
                return;
        }
        if ((int)ob->query_skill("xiantian-gong",1) < 50 )
        {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen") < 6000)
        {
                command("say 我看你还是多做一些侠义之事吧。\n");
                return;
        }
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

