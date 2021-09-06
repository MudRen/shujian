inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("程瑶迦", ({"cheng yaojia", "cheng"}));
        set("gender", "女性");
        set("age", 24);
        set("class", "taoist");
        set("long",
                "她是清净散人孙不二的弟子。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("per", 26);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("level", 8);
        set("combat_exp", 160000);

        set_skill("force", 80);
        set_skill("xiantian-gong", 80);
        set_skill("sword", 80);
        set_skill("quanzhen-jianfa",70);
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);
        set_skill("parry", 80);
        set_skill("strike",80);
        set_skill("haotian-zhang", 70);
        set_skill("literate",60);
        set_skill("taoism",60);
	
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

        if (ob->query("gender")=="男性") {
                command("say 我不收男徒，你还是去拜我几位师兄为师吧。\n");
                return;
        }
       
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
        ob->set("shen",100000);
}
