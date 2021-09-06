// hao.c 郝大通
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("郝大通", ({"hao datong", "hao"}));
        set("gender", "男性");
        set("age", 34);
        set("class", "taoist");
        set("nickname",HIG"广宁子"NOR);
        set("long",
                "他就是全真七子中的郝大通郝真人。他身材微胖，象个富翁模\n"
                "样，身上穿的道袍双袖皆无。\n" );
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("title","全真七子之六");

        set("qi", 4200);
        set("max_qi", 4200);
        set("jing", 2100);
        set("max_jing", 2100);
        set("neili", 4400);
        set("max_neili", 4400);
        set("jiali", 100);
        set("level", 12);
        set("combat_exp", 680000);

        set_skill("force", 150);
        set_skill("xiantian-gong", 150);
        set_skill("sword", 130);
        set_skill("quanzhen-jianfa",130);
        set_skill("dodge", 110);
        set_skill("jinyan-gong", 120);
        set_skill("parry", 140);
        set_skill("literate",100);
        set_skill("strike", 150);
        set_skill("haotian-zhang", 150);
        set_skill("taoism",100);
        set_skill("tiangang-beidouzhen", 120);
	
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
/*
void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("xiantian-gong",1) < 50 )
        {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen") < 5000)
        {
                command("say 你这人行侠仗义的事情做得太少！\n");
                return;
        }
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}
*/