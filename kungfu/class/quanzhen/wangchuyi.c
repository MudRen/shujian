#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("王处一", ({"wang chuyi", "wang"}));
        set("gender", "男性");
        set("age", 35);
        set("class", "taoist");
        set("nickname",RED"玉阳子"NOR);
        set("long",
                "他就是全真七子之五王处一王真人。他身材修长，服饰整洁，\n"
                "三绺黑须飘在胸前，神态潇洒。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 32);
        set("dex", 30);

        set("title","全真七子之五");

        set("qi", 4200);
        set("max_qi", 4200);
        set("jing", 2100);
        set("max_jing", 2100);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);

        set("combat_exp", 1200000);

        set_skill("force", 170);
        set_skill("xiantian-gong", 170);
        set_skill("sword", 160);
        set_skill("quanzhen-jianfa",160);
        set_skill("dodge", 150);
        set_skill("jinyan-gong", 150);
        set_skill("parry", 170);
        set_skill("strike", 170);
        set_skill("haotian-zhang", 170);
        set_skill("literate",100);
        set_skill("taoism",100);
	      set_skill("medicine", 180);
	      set_skill("cuff",150);
        set_skill("tiangang-beidouzhen",150);

	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

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
	    if ((int)ob->query_skill("xiantian-gong",1) < 100 )
        {
                command("say 你的本门内功心法火候不足，难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen") < 50000)
        {
                command("say 我看你还是多做一些侠义之事吧。\n");
                return;
        }
     command("say 好吧，我就收下你这个徒弟了。");
     command("recruit " + ob->query("id"));
}
*/


