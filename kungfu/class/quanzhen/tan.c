// tan.c 谭处端

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

string ask_me();

void create()
{
        set_name("谭处端", ({"tan chuduan", "tan"}));
        set("gender", "男性");
        set("age", 40);
        set("class", "taoist");
        set("nickname",HIY"长真子"NOR);
        set("long",
                "他就是全真次徒谭处端谭真人，他身材魁梧，浓眉大眼，嗓音\n"
                "洪亮，拜重阳真人为师前本是铁匠出身。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 34);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("title","全真七子之二");

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 100);
        set("level", 20);
        set("combat_exp", 1200000);

        set_skill("force", 150);
        set_skill("xiantian-gong", 160);
        set_skill("sword", 150);
        set_skill("quanzhen-jianfa",160);
        set_skill("dodge", 140);
        set_skill("jinyan-gong", 140);
        set_skill("parry", 150);
        set_skill("strike", 150);
        set_skill("haotian-zhang", 150);
        set_skill("literate",80);
        set_skill("taoism",100);
	      set_skill("cuff",150);
	      set_skill("tiangang-beidouzhen", 150);
	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教"   :  "我全真教是天下道家玄门正宗。\n",              
        ]) );
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}
/*
void attempt_apprentice(object ob)
{

        if ((int)ob->query_skill("xiantian-gong",1) < 80 )
        {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen") < 8000)
        {
                command("say 我看你还是多做一些侠义之事吧。\n");
                return;
        }
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}
*/
