#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("马钰", ({"ma yu", "ma"}));
        set("gender", "男性");
        set("age", 42);
        set("class", "taoist");
        set("nickname",MAG"丹阳子"NOR);
        set("long",
                "他就是王重阳的大弟子，全真七子之首，丹阳子马钰马真人。\n"
                "他慈眉善目，和蔼可亲，正笑着看着你。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 32);
        set("con", 31);
        set("dex", 30);
        set("title","全真七子之首");
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2200);
        set("max_jing", 2200);
        set("neili", 4700);
        set("max_neili", 4700);
        set("jiali", 100);
        set("level", 18);
        set("combat_exp", 1400000);

        set_skill("force", 180);
        set_skill("xiantian-gong", 180);
        set_skill("sword", 170);
        set_skill("quanzhen-jianfa",170);
        set_skill("dodge", 180);
        set_skill("jinyan-gong", 180);
        set_skill("parry", 180);
        set_skill("literate",100);
        set_skill("strike", 180);
        set_skill("haotian-zhang", 180);
        set_skill("taoism",150);
	      set_skill("medicine", 200);
        set_skill("tiangang-beidouzhen", 80);
	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("miji_count",1);
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
                command("say 玄门内丹修炼之术，男女有别，你还是去孙师妹那里看看吧。\n");
                return;
        }
        if ((int)ob->query_skill("xiantian-gong",1) < 100 )
        {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen") < 500000)
        {
                command("say 行侠仗义我辈学武人需铭记在心，这点你做的可不够啊！\n");
                return;
        }
        command("pat " + ob->query("id"));
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}
